/*
 * kurYraOponentas.ino
 *
 * kuo oponentas arčiau mūsų vidurio, tuo balas ARTESNIS NULIUI
 * balas >= -255 && balas <= 255
 *
 * Copyright (c) 2019 Kipras Melnikovas
*/

#include <Arduino.h>
#include "kurYraOponentas.h"
#include "inicializuoti.h" // tolimiausioPinoLaipsnis
#include "pagalbines_funkcijos.h"

// double mappinti(double skaicius, double minReiksme, double maxReiksme)
// {
// 	return ((maxReiksme - minReiksme) * (skaicius - minReiksme) / (maxReiksme - minReiksme) + minReiksme);
// }

double oponentoPozicijosBalasVidutinis()
{
	size_t kiekPinuMato = 0;

	double baluSuma = 0;

	for (int i = 0; i < kiekYraSensoriuPinu; ++i)
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
	size_t kiekPinuMato = 0;

	int matanciuPinuLaipsniai[kiekYraSensoriuPinu];

	/**
	 * Pirma susirašom matančių pin'ų reikšmes,
	 * o tada apskaičiuojam medianą.
	*/

	// Serial.print("\n\nPinai: ");

	for (int i = 0; i < kiekYraSensoriuPinu; ++i)
	{
		// Serial.print("\n");
		// Serial.print(i);

		if (digitalRead(pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[i][0]) == 0) // jeigu matome
		{
			// Serial.print(" +");

			/**
 			  * [kiekPinuMato] - kiek kol kas šiame cikle mato pin'ų.
			  *
			  * Tai reiškia, jog jei tik pradėjom tikrinti,
			  * gali būti, jog atsiras ir daugiau matančių.
			  *
			  * Čia realiai naudojama kaip std::vector'o push_back() metodas,
			  * tik patiems atnaujinant indeksą (kiekPinuMato)
			 */
			matanciuPinuLaipsniai[kiekPinuMato] = pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[i][1];
			++kiekPinuMato;
		} else {
			// Serial.print(" -");
		}
	}

	double baluSuma = 0;

	if (kiekPinuMato == 0)
	{
		baluSuma = 0;
	}

	/**
	 * pvz
	 *
	 * matantys = { 10, 20, 30, 40 };
	 *
	 * (20 + 30) / 2 = 25;
	 *
	 */
	else if (kiekPinuMato % 2 == 0)
	{
		const int kairesnioIndeksas = (kiekPinuMato / 2) - 1;
		const int desinesnioIndeksas = (kiekPinuMato / 2);

		const int kairesnisLaipsnis =  matanciuPinuLaipsniai[kairesnioIndeksas];
		const int desinesnisLaipsnis = matanciuPinuLaipsniai[desinesnioIndeksas];

		baluSuma = (kairesnisLaipsnis + desinesnisLaipsnis) / 2;
	}

	/**
	 * pvz
	 *
	 * matantys = { 10, 30, 50 };
	 *
	 * = 30;
	 *
	 */
	else
	{
		baluSuma = matanciuPinuLaipsniai[kiekPinuMato / 2];
	}

	Serial.print("\nKiekPinuMato = ");
	Serial.print(kiekPinuMato);

	Serial.print("\nMatanciu pinu laipsniai == ");

	for (size_t i = 0; i < kiekPinuMato; ++i) {
		Serial.print(matanciuPinuLaipsniai[i]);
		Serial.print(" ");
	}

	Serial.print("\nMediana = ");
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
