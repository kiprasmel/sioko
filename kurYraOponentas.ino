/*
 * kurYraOponentas.ino
 * 
 * kuo oponentas arčiau mūsų vidurio, tuo balas ARTESNIS NULIUI
 * balas >= -255 && balas <= 255
 * 
 * Copyright (c) 2019 Kipras Melnikovas
*/

#include "kurYraOponentas.h"
#include "inicializuoti.h" // tolimiausioPinoLaipsnis
#include "pagalbines_funkcijos.h"

// double mappinti(double skaicius, double minReiksme, double maxReiksme)
// {
// 	return ((maxReiksme - minReiksme) * (skaicius - minReiksme) / (maxReiksme - minReiksme) + minReiksme);
// }

double oponentoPozicijosBalasVidutinis()
{
	int kiekPinuMato = 0;

	double baluSuma = 0;

	for (int i = 0; i < kiekYraPinu; ++i)
	{
		if (digitalRead(pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[i][0]) == 0) // jeigu matome
		{
			baluSuma += pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[i][1];
			++kiekPinuMato;
		}
	}

	/** vidurkis */
	baluSuma /= kiekPinuMato;

	return baluSuma;
}

double oponentoPozicijosBalasMediana()
{
	int kiekPinuMato = 0;

	double baluSuma = 0;
	int matanciuPinuReiksmes[kiekYraPinu];

	/**
	 * Pirma susirašom matančių pin'ų reikšmes,
	 * o tada apskaičiuojam medianą.
	*/

	for (int i = 0; i < kiekYraPinu; ++i)
	{
		if (digitalRead(pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[i][0]) == 0) // jeigu matome
		{
			/**
 			  * [kiekPinuMato] - kiek kol kas šiame cikle mato pin'ų.
			  * 
			  * Tai reiškia, jog jei tik pradėjom tikrinti,
			  * gali būti, jog atsiras ir daugiau matančių.
			  * 
			  * Čia realiai naudojama kaip std::vector'o push_back() metodas,
			  * tik patiems atnaujinant indeksą (kiekPinuMato)
			 */
			matanciuPinuReiksmes[kiekPinuMato] = pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[i][1];
			++kiekPinuMato;
		}
	}

	if (kiekPinuMato == 0)
	{
		baluSuma = 0;
	}

	// 0 1 2 3
	// (1 + 2) / 2  =  3 / 2  =  1.5
	else if (kiekPinuMato % 2 == 0)
	{
		baluSuma = (matanciuPinuReiksmes[kiekPinuMato / 2 - 1] + matanciuPinuReiksmes[kiekPinuMato / 2]) / 2;
	}

	// 0 1 2
	// = 1
	else
	{
		baluSuma = matanciuPinuReiksmes[kiekPinuMato / 2];
	}

	Serial.print("\n\rKiekPinuMato = ");
	Serial.print(kiekPinuMato);
	Serial.print("\n\rMediana = ");
	Serial.print(baluSuma);

	return baluSuma;
}

/**
 * return'ina skaičių (nuo -1 iki +1);
 * -1 = 100% kairėje,
 * +1 = 100% dešinėje; 
*/
double kurYraOponentas() // nuo -1 iki +1
{
	return oponentoPozicijosBalasMediana() / tolimiausioPinoLaipsnis;
}

/** 
 * return'ina procentus (nuo -100 iki +100);
 * -100 = 100% kairėje,
 * +100 = 100% dešinėje;
*/
double kurYraOponentasProcentaliai() // nuo -100 iki +100
{
	return kurYraOponentas() * 100;
}
