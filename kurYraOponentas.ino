/*
 * kurYraOponentas.ino
 * 
 * kuo oponentas arčiau mūsų vidurio, tuo balas ARTESNIS NULIUI
 * balas >= -255 && balas <= 255
 * 
 * Copyright (c) 2019 Kipras Melnikovas
*/

#include "kurYraOponentas.h"
#include "inicializuoti.h" // maximalusBalas

// double mappinti(double skaicius, double minReiksme, double maxReiksme)
// {
// 	return ((maxReiksme - minReiksme) * (skaicius - minReiksme) / (maxReiksme - minReiksme) + minReiksme);
// }

double oponentoPozicijosBalas()
{
	double baluSuma = 0;
	const double kiekPinu = sizeof(visiPinaiIrJuTeikiamiBalai) / sizeof(visiPinaiIrJuTeikiamiBalai[0][0]);
	// #TODO #WARN #CHECK ar reikia dalinti iš 1D, ar iš 2D masyvo `sizeof`o (reiktų iš `const double`)

	for (int i = 0; i < kiekPinu; ++i)
	{
		if (digitalRead(visiPinaiIrJuTeikiamiBalai[i][0]) == 0) // jeigu matome
		{
			baluSuma += visiPinaiIrJuTeikiamiBalai[i][1];
		}
	}

	return baluSuma;
}

/**
 * return'ina skaičių (nuo -1 iki +1);
 * -1 = 100% kairėje,
 * +1 = 100% dešinėje; 
*/
double kurYraOponentas() // nuo -1 iki +1
{
	return oponentoPozicijosBalas() / maximalusBalas;
}

/** 
 * return'ina procentus (nuo -100 iki +100);
 * -100 = 100% kairėje,
 * +100 = 100% dešinėje;
*/
double kurYraOponentasProcentaliai() // nuo -100 iki +100
{
	return oponentoPozicijosBalas() * 100 / maximalusBalas;
}
