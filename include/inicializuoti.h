#pragma once

/*
 * inicializuoti.h
 *
 * inicializavimo header failas su visais globaliais kintamaisiais ir
 * funkcijomis, kurių reikia inicializacijai ir visam programos
 * veikimui.
 *
 * Naudojamas pagrindiniame projekto faile (sioko.ino)
 * ir suteikia globalius kintamuosius visiems failams.
 *
 * Copyright (c) 2019 Kipras Melnikovas
 *
*/

/**
 * DĖMESIO
 *
 * Šitas VEIKIA masyvams, kurie yra `stack`e,
 * bet ne `heap`e!
 *
 * Šitas NEVEIKIA, jeigu masyvas buvo paduotas kaip funkcijos parametras,
 * nes jis tampa `pointer`iu ir nebeišeina patikrinti jo dydžio!
 *
 * Skaityti daugiau:
 *
 * https://stackoverflow.com/a/10349610
 * https://stackoverflow.com/a/37539
 *
 */
#define gautiMasyvoDydi(x) (sizeof(x) / sizeof((x)[0]))

void inicializuoti();

void sukurtiBendraPinuMasyva();
void suteiktiPinModusViskam();
void suteiktiPinModeMasyvui(const int pinuMasyvas[], int masyvoDydis, int pinModas);
void paruostiGeneralConfiga();

/**
 * didžiausio laipsnio modulio (paversto į teigiamo sk.) greitis
 * iš `pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai`
*/
const double tolimiausioPinoLaipsnis = 90;

const double greitisVaziavimoPirmyn = 255;
const double greitisSukimosi = 255;										 // #EDITME
const double perKiekMsApsisukam360Sukdamiesi255 = 157; //50; //157;
const double perKiekMsApsisukam90Sukdamiesi255 = 56; // 56; 64;

/**
 * TODO - implementuot šituos
 */
// const double sukimosiLaikasMs1Laipsnio = perKiekMsApsisukam90Sukdamiesi255 / 255 * greitisSukimosi / 90;
// const double sukimosiLaikasMsTolimiausiuLaipsniu = sukimosiLaikasMs1Laipsnio * tolimiausioPinoLaipsnis;

/** --- */

/**
 * new layout of pins etc
 *
 * Esmė sudelioti pagal tai, kur pinai **ŽIŪRI**
 *
 * Note - strategijos bus broken
 *
*/

const byte LEDas = 13;




/** palieku čia - reikia strategijoms -- TODO perdaryt, nes nereikšmingi */
const int Middle1 = 16; /** lazeris ilgas, padėtas pačiame viduryje */
const int Middle2 = 21; /** ne lazeris, žiūri į vidurinį (irgi pačiame viduryje) */
const int Middle3 = 15; /** lazeris trumpas, padėtas pačiame viduryje */

const byte Rightback = 15;
const byte Leftback = 34;

/**
 * Toliau aprašomi sensoriai:
 *
 * { pinas, kiekLaipsniuPasisukes }
 *
 */

/** ŽIŪRI į dešinę */
const int ziurintysIDesineSensoriai[][2] = {
		{17, 45}, /** lazeris trumpas */
		// {18, 45}, /** lazeris ilgas */
		{22, 45},
		{19, 90}
};

const int ziurintysIDesineSensoriaiDydis = gautiMasyvoDydi(ziurintysIDesineSensoriai);

const int ziurintysIDesinePinai[ziurintysIDesineSensoriaiDydis] = {
	ziurintysIDesineSensoriai[0][0],
	ziurintysIDesineSensoriai[1][0],
	ziurintysIDesineSensoriai[2][0],
	// ziurintysIDesineSensoriai[3][0]
};

const int ziurintysIDesinePinaiDydis = gautiMasyvoDydi(ziurintysIDesinePinai);

/** ŽIŪRI į vidurį */
const int ziurintysIViduriSensoriai[][2] = {
		// {Middle1, 0}, /** lazeris ilgas */
		// {Middle2, 0}, /** buvo vienas priekinis, dabar yra 2 iš šonų priekyje */
		{Middle3, 0},  /** lazeris trumpas */
		{34, 0}, /** iš šono į priekį */
		{21, 0} /** iš šono į priekį */
};

const int ziurintysIViduriSensoriaiDydis = gautiMasyvoDydi(ziurintysIViduriSensoriai);

const int ziurintysIViduriPinai[ziurintysIViduriSensoriaiDydis] = {
	ziurintysIViduriSensoriai[0][0],
	ziurintysIViduriSensoriai[1][0],
	ziurintysIViduriSensoriai[2][0],
	// ziurintysIViduriSensoriai[3][0]
};

const int ziurintysIViduriPinaiDydis = gautiMasyvoDydi(ziurintysIViduriPinai);

/** ŽIŪRI į kairę */
const int ziurintysIKaireSensoriai[][2] = {
		{23, -90},
		{20, -45},
		// {14, -45}, /** lazeris ilgas */
		{39, -45}  /** lazeris trumpas */
};

const int ziurintysIKaireSensoriaiDydis = gautiMasyvoDydi(ziurintysIKaireSensoriai);

const int ziurintysIKairePinai[ziurintysIKaireSensoriaiDydis] = {
	ziurintysIKaireSensoriai[0][0],
	ziurintysIKaireSensoriai[1][0],
	ziurintysIKaireSensoriai[2][0],
	// ziurintysIKaireSensoriai[3][0]
};

const int ziurintysIKairePinaiDydis = gautiMasyvoDydi(ziurintysIKairePinai);

/**
 * Nesirūpinam linijom.
 * čia tik tie sensoriai, kurie aktualūs skaičiuojant pasisukimus / puolimus.
 */
const int kiekYraSensoriuPinu = ziurintysIDesinePinaiDydis + ziurintysIKairePinaiDydis + ziurintysIViduriPinaiDydis;

/**
 * dinamiškai sukuriamas `inicializuoti()` funkcijoje
 * iš kitų turimų duomenų
 */
int pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[kiekYraSensoriuPinu][2];
int visiPinai[kiekYraSensoriuPinu];

/** ŽIŪRI į linijas (bet jau nebesvarbūs skaičiavimams) */
const int linijuSensoriai[] = {
	35, /** LeftLine1 */
	36, /** LeftLine2 */
	37, /** RightLine1 */
	38 /** RightLine2 */
};

/** --- */

/**
 * TODO perrašyt šituos docs'us pagal naujausią softo versiją.
 *
 * skaičiuojant, kur yra oponentas kuo kairiau, tuo daugiau -, kuo
 * dešiniau, tuo daugiau + Turi būti vienodai pinų kairėje ir dešinėje
 *
 * kadangi funkcija turi grąžinti skaičių nuo -255 iki 255, reikia
 * apskaičiuoti, po kiek didinti kiekvieno pino balus, kad galutinė max
 * suma vienos pusės būtų nuo -255 iki +255;
 * formulė:
 * (double) tolimiausioPinoLaipsnis / ((poKiekPinuKiekvienojePuseje * (poKiekPinuKiekvienojePuseje + 1)) / 2);
 *
 * skaitykite => https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
 *
 * šiuo metu, poKiekPinuKiekvienojePuseje = 3; tolimiausioPinoLaipsnis = 255;
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

/** --- */

/**
 * Konfiguracija. Pakeitus pinų sudėtį reikia PATIEMS pertvarkyti!
*/
// // const int poKiekPinuKiekvienojePuseje = 3;

// // const int minusinisIndeksas = 0, // kelinti sudėlioti KAIRIEJI pinai
// // 		neutralusIndeksas = 1,			 // kelinti sudėlioti VIDURINIAI pinai
// // 		pliusinisIndeksas = 2;			 // kelinti sudėlioti DEŠINIEJI pinai

/**
 * Išmatuoti pasisukimo laipsniai, lyginant nuo priekio.
 *
 */
// const int pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[][2] = {
// 		{Left3, -90},
// 		{Left2, -50},
// 		{Left1, -15},
// 		{Middle1, 0},
// 		{Middle2, 0},
// 		{Middle3, 0},
// 		{Right1, 15},
// 		{Right2, 50},
// 		{Right3, 90}};

// const int kiekYraSensoriuPinu = sizeof(pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai); / sizeof(pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[0]);

/** <= --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- => **/

/**
 * TODO - atsirinkti, ko reikia, o kitką išmest
 *
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
// const byte LeftLine1 = 35; //rau
// const byte LeftLine2 = 36; //g

// const byte RightLine1 = 37; //ru
// const byte RightLine2 = 38; //z

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
