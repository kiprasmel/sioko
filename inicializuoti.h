/*
 * inicializuoti.h
 *
 * inicializavimo header failas su visais globaliais kintamaisiais ir
 * funkcijomis, kurių reikia inicializacijai ir visam programos
 * veikimui.
 *
 * Copyright (c) 2019 Kipras Melnikovas
 *
*/

#pragma once

void inicializuoti();

const double greitisVaziavimoPirmyn = 255;
const double greitisSukimosi = 255;							 // #EDITME
double perKiekMsApsisukam360Sukdamiesi255 = 157; //50; //157;

// const double perKiekMsApsisukam360Sukdamiesi255 = greitisSukimosi * 157 / 255;

// 255 greitis - 157 sec
// 1 greitis = x sec
// x = 1 * 157 / 255
// x = 0.61
// * greitisSukimosi

// greitis 100; sukimasis 100
// greitis 50; sukimasis 200

// laikas = kelias / greicio
/*
	1 laipsnio apsisukimas = 157 / 360 ~ 0.43
	90 laipsniu = 38.7



	157 = kelias / 255
	x = kelias / 100
	

*/

// greitis = kelias / laikas

// testavimui
// const double perKiekMsApsisukam360Sukdamiesi255 = 4003; //#TODO
// const double greitisSukimosi = 10;													 // #EDITME

// TODO FAST perdaryt šituos. Galbūt reiktų iškart dėt, kas yra priekyje, kas kairėj, kas dešinėj etc.
//puolimo sensoriai

const byte Right1 = 21; // Dešinysis aukščiausias (nesvarbiausias)
const byte Right2 = 23; // Dešinysis vidurinis
const byte Right3 = 22; // Pats pats dešinysis (90 laipsnių) svarbiausias

const byte Middle1 = 20; // kairiausias
const byte Middle2 = 19; // vidurinysis
const byte Middle3 = 33; // desiniausias

const byte Left1 = 18; // Kairysis aukščiausias (nesvarbiausias)
const byte Left2 = 16; // Kairysis vidurinis
const byte Left3 = 17; // Pats pats kairysis (90 laipsnių) svarbiausias

// const byte Right1 = 23;
// const byte Right2 = 22;
// const byte Right3 = 21;
// const byte Middle1 = 20;
// const byte Middle2 = 19;
// const byte Middle3 = 33;
// const byte Left3 = 18;
// const byte Left2 = 17;
// const byte Left1 = 16;

const byte Rightback = 15;
const byte Leftback = 34;

/**
 * visų pusių pinai, suskirstyti pusėmis.
 * išvardinti nuo mažiausiai reikšmingo iki reikšmingiausio
 * (kuo labiau toje pusėje, tuo reikšmingesnis)
*/
const int kairesPinai[] = {Left1, Left2, Left3};
const int priekioPinai[] = {Middle1, Middle2, Middle3};
const int desinesPinai[] = {Right1, Right2, Right3};

/**
 * skaičiuojant, kur yra oponentas kuo kairiau, tuo daugiau -, kuo
 * dešiniau, tuo daugiau + Turi būti vienodai pinų kairėje ir dešinėje
 *
 * kadangi funkcija turi grąžinti skaičių nuo -255 iki 255, reikia
 * apskaičiuoti, po kiek didinti kiekvieno pino balus, kad galutinė max
 * suma vienos pusės būtų nuo -255 iki +255;
 * formulė:
 * (double) maximalusBalas / ((poKiekPinuKiekvienojePuseje * (poKiekPinuKiekvienojePuseje + 1)) / 2);
 * 
 * skaitykite => https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
 * 
 * šiuo metu, poKiekPinuKiekvienojePuseje = 3; maximalusBalas = 255;
 * 255 / ((3 * (3 + 1) / 2) = 255 / (3 * 4 / 2) = 255 / 6 = 42.5;
 * 
 * pradedant nuo mažiausiai reikšmingo pino ir prie 0 pridedant gautą reikšmę;
 * sekančiam - labiau reikšmingesniam, pridedam tiek pat, iki kol pridedam visiems,
 * o galutinė suma = 255
 * 
 * ---
 * 
 * arba, galima naudoti bet kokias reikšmes, tarkim, didinant / mažinant kas 64,
 * o paskui gautą balų skaičių mappinant nuo -255 iki +255
*/

/**
 * Konfiguracija. Pakeitus pinų sudėtį reikia PATIEMS pertvarkyti!
*/
const int kiekPinuPusiu = 3;
const int poKiekPinuKiekvienojePuseje = 3;

const int minusinisIndeksas = 0, // kelinti sudėlioti KAIRIEJI pinai
		neutralusIndeksas = 1,			 // kelinti sudėlioti VIDURINIAI pinai
		pliusinisIndeksas = 2;			 // kelinti sudėlioti DEŠINIEJI pinai

double maximalusBalas = 255;
// const double maximalusBalas = 100;
const double didinimoSkaicius = maximalusBalas / ((poKiekPinuKiekvienojePuseje * (poKiekPinuKiekvienojePuseje + 1)) / 2);

// maximalusBalas = didinimoSkaicius * poKiekPinuKiekvienojePuseje;

/**
 * patvirtinti, jog atitinka min/max sąlygą 
*/
//assert(didinimoSkaicius * poKiekPinuKiekvienojePuseje >= -maximalusBalas && didinimoSkaicius * poKiekPinuKiekvienojePuseje <= maximalusBalas);

/**
 * #TODO optimizuoti `apskaiciuotiNaujaBala`
*/
// double didinimoReiksmes[poKiekPinuKiekvienojePuseje];
// didinimoReiksmes[poKiekPinuKiekvienojePuseje - 1] = didinimoSkaicius;
// for (int i = poKiekPinuKiekvienojePuseje - 2; i > 0; --i)
// {
// 	didinimoReiksmes[i] = didinimoReiksmes[i + 1] + didinimoSkaicius;
// }
double apskaiciuotiNaujaBala(double skaicius, int iteratorius);

const int visiPinai[kiekPinuPusiu][poKiekPinuKiekvienojePuseje] = {
		{Left1, Left2, Left3},
		{Middle1, Middle2, Middle3},
		{Right1, Right2, Right3}};

double visiPinaiIrJuTeikiamiBalai[kiekPinuPusiu * poKiekPinuKiekvienojePuseje][2];

void suskaiciuotiBalusVisiemsPinams();

/** <= --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- => **/

/** 
 * Toliau eina legacy dalykai, kuriuos sukūriau ne aš, bet kurie dar
 * pilnai nepertvarkyti ir kol kas reikalingi naudojimui.
 *
 * Rekomenduojama jų nenaudoti, taip pat, jeigu įmanoma - perrašyti
 * esantį kodą su jais į naują kodą su atnaujintais kintamaisiais etc. 
*/

// protokolas (atrodo, jog nereikalingas)
#define MY_PROTOCOL NEC

//Pultelio hex kodai ir nustatymai
#define Number1 0xFF906F
#define Number2 0xFFB847
#define Number3 0xFFF807
#define Number4 0xFF9867
#define Number5 0xFFD827
#define Number6 0xFF8877
#define Number7 0xFFE817
#define Number8 0xFF48B7
#define Number9 0xFF9A65
#define Enter 0xFFE01F

// pagalbiniai pavadinimai bitais (nuo 0 iki 255);
byte myLINE = B0000;
byte myLINEBACK = B00;
byte mySIDES = B000000; //8
byte myFRONT = B000000;
byte myMOUSE = B00; //8

// TODO CHECK - kuris yra kairinis, o kuris - dešininis? ir kuris pirmyn, o kuris atgal?
const byte PWM1 = 7;	// kairysis motoras
const byte PWM2 = 9;	// dešinysis motoras
const byte DIR1 = 6;	// ?
const byte DIR2 = 10; // ?

//Linijos sensoriai
const byte LeftLine1 = 35; //rau
const byte LeftLine2 = 36; //g

const byte RightLine1 = 37; //ru
const byte RightLine2 = 38; //z

int k = 0;
int b = 0;

//nep right
//33
//34
//nep left
//15
//14
const byte START_MODULE = 29;

//Varikliu greiciai
const byte SPEED_NORMAL = 200;
const byte SPEED_TURN = 150;
const byte SPEED_TURN2 = 150;
const byte SPEED_GO_BACK_LINE = 255;
const byte SPEED_GO_BACK_LINE_TURN = 200;
const byte SPEED_GO_BACK_LINE_TURN2 = 200;

//atsitraukimo ir pasisukimo atsitraukiant laikai priekiniu linijos
const unsigned short TIME_FOR_GO_BACK = 70;		//60
const unsigned short TIME_FOR_GO_BACK_1 = 70; //105

byte START_STRATEGY_STATE = 0;
byte MAIN_STRATEGY_STATE = 0;

// millis
unsigned long time;

bool Front = false;

byte check;
