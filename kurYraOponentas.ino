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
#include "pagalbines_funkcijos.h"

// double mappinti(double skaicius, double minReiksme, double maxReiksme)
// {
// 	return ((maxReiksme - minReiksme) * (skaicius - minReiksme) / (maxReiksme - minReiksme) + minReiksme);
// }

double oponentoPozicijosBalas()
{
	double baluSuma = 0;
	// #TODO pertvarkyt kiekPinu
	// const double kiekPinu = sizeof(visiPinaiIrJuTeikiamiBalai) / sizeof(visiPinaiIrJuTeikiamiBalai[0][0]);
	// const double kiekPinu = 9;
	// #TODO #WARN #CHECK ar reikia dalinti iš 1D, ar iš 2D masyvo `sizeof`o (reiktų iš `const double`)

	const int kiekPinu = 9;
	// const double tempPinaiIrBalai[][2] = {
	// 		{Left1, -42.5},
	// 		{Left2, -85},
	// 		{Left3, -127.5},
	// 		{Middle1, 0},
	// 		{Middle2, 0},
	// 		{Middle3, 0},
	// 		{Right1, 42.5},
	// 		{Right2, 85},
	// 		{Right3, 127.5}
	//};

	const int tempPinaiIrBalai[][2] = {
			{Left1, 0},		// 0 // -15
			{Left2, -30}, ////// 64
			{Left3, -40}, ////// 100
			{Middle1, 0},
			{Middle2, 0},
			{Middle3, 0},
			{Right1, 0},	 // 0 // 15
			{Right2, 30},	////// 64
			{Right3, 40}}; ////// 100

	// least important
	// middle
	// most important

	// Left3 -> mažiausias (apie 30 laipsnių) aukščiausiai
	// Left1 -> vidurinis (aukščiau už 2)
	// Left2 -> 90 laipsniu pats žemiausias

	// Right3 -> aukščiausias (apie 30)
	// Right1 -> vidurinis
	// Right2 -> zemiausias (90 laipsniu desine)

	// Middle1 -> left most (kairiausias)
	// Middle2 -> middle middle
	// Middle3 -> right most

	// const byte temp = Middle3;
	// if (digitalRead(temp) == 0)
	// {
	// 	digitalWrite(13, HIGH);
	// }
	// else
	// {
	// 	digitalWrite(13, LOW);
	// }

	// Serial.print("\nMiddle3 = ");
	// Serial.print(digitalRead(temp));
	// Serial.print("  ; digitalRead(Left1) = ");
	// Serial.print(digitalRead(Left1));

	// iškart grąžinam 0;
	if (arVidurysKaNorsMato())
	{
		return 0;
	}

	for (int i = 0; i < kiekPinu; ++i)
	{
		if (digitalRead(tempPinaiIrBalai[i][0]) == 0) // jeigu matome
		{
			baluSuma += tempPinaiIrBalai[i][1];
		}
	}

	// for (int i = 0; i < kiekPinu; ++i)
	// {
	// 	if (digitalRead(visiPinaiIrJuTeikiamiBalai[i][0]) == 0) // jeigu matome
	// 	{
	// 		baluSuma += visiPinaiIrJuTeikiamiBalai[i][1];
	// 	}
	// }

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
