/*
 * inicializuoti.ino
 * 
 * inicializavimo failas
 * 
 * Copyright (c) 2019 Kipras Melnikovas
 * 
*/

#include "inicializuoti.h"
#include <assert.h>

void inicializuoti()
{
	suskaiciuotiBalusVisiemsPinams();
}

double apskaiciuotiNaujaBala(double skaicius, int iteratorius)
{
	assert(skaicius >= 0 && iteratorius >= 0);

	// pradedam skaičiuoti nuo paskutinio elemento - 1, o paskui, didėjant
	// iteratoriui, skaičius vis mažėja
	const double balas = skaicius * (poKiekPinuKiekvienojePuseje - 1 - iteratorius);

	// patvirtinti, jog atitinka (patikrinom ankščiau)
	// assert(balas >= -255 && balas <= 255);

	// switch'e nenaudojam `break`, nes `return` taip ar taip viską nutraukia ir grąžina reikšmę.
	switch (iteratorius)
	{
	case minusinisIndeksas:
		return balas * -1;
	case neutralusIndeksas:
		return 0;
	case pliusinisIndeksas:
		return balas;
	default:
		Serial.println("Klaida! iteratorius buvo didesnis, negu yra indeksų\nir todėl neįmanoma apskaičiuoti naujos didinimo reikšmės,\njog galėtume nustatyti, kur yra oponentas!");
	};
}

void suskaiciuotiBalusVisiemsPinams()
{
	for (int i = 0; i < kiekPinuPusiu; ++i)
	{
		for (int j = 0; j < poKiekPinuKiekvienojePuseje; ++j)
		{
			visiPinaiIrJuTeikiamiBalai[i][j] = apskaiciuotiNaujaBala(didinimoSkaicius, i);
		}
	}
}
