#include "config.h"
#include "pagalbines_funkcijos.h"

/**
 * didžiausio laipsnio modulio (paversto į teigiamo sk.) greitis
 * iš `pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai`
*/
const double tolimiausioPinoLaipsnis = 90;

const double greitisVaziavimoPirmyn = 255;
const double greitisSukimosi = 255;
const double perKiekMsApsisukam360Sukdamiesi255 = 157; //50; //157;
const double perKiekMsApsisukam90Sukdamiesi255 = 56; // 56; 64;

/**
 * Esmė pinus sudelioti pagal tai, kur jie **ŽIŪRI**
*/

const byte LEDas = 39;

const byte Rightback = 15;
const byte Leftback = 34;

/**
 * Toliau aprašomi sensoriai:
 *
 * { pinas, kiekLaipsniuPasisukes }
 *
 */

/** ŽIŪRI į dešinę */
/** TODO susidėt pinų pasisukimo laipsnius */
const int ziurintysIDesineSensoriai[][2] = {
		// {17, 45}, /** lazeris trumpas */
		// // {18, 45}, /** lazeris ilgas */
		// {22, 45},
		// {19, 90}
		{22, 90},
		{20, 45},
		{21, 15}
};

const int ziurintysIDesineSensoriaiDydis = gautiMasyvoDydi(ziurintysIDesineSensoriai);

const int ziurintysIDesinePinai[ziurintysIDesineSensoriaiDydis] = {
	ziurintysIDesineSensoriai[0][0],
	ziurintysIDesineSensoriai[1][0],
	ziurintysIDesineSensoriai[2][0],
	// ziurintysIDesineSensoriai[3][0]
};

const int ziurintysIDesinePinaiDydis = gautiMasyvoDydi(ziurintysIDesinePinai);

/** palieku čia - reikia strategijoms -- TODO perdaryt, nes nereikšmingi */
const int Middle1 = 17; /** lazeris ilgas, padėtas pačiame viduryje */
const int Middle2 = 23; /** ne lazeris, žiūri į vidurinį (irgi pačiame viduryje) */
const int Middle3 = 23; /** lazeris trumpas, padėtas pačiame viduryje */

/** ŽIŪRI į vidurį */
const int ziurintysIViduriSensoriai[][2] = {
		{17, 0}, /** left */
		{23, 0} /** right */
};

const int ziurintysIViduriSensoriaiDydis = gautiMasyvoDydi(ziurintysIViduriSensoriai);

const int ziurintysIViduriPinai[ziurintysIViduriSensoriaiDydis] = {
	ziurintysIViduriSensoriai[0][0],
	ziurintysIViduriSensoriai[1][0],
	// ziurintysIViduriSensoriai[2][0],
	// ziurintysIViduriSensoriai[3][0]
};

const int ziurintysIViduriPinaiDydis = gautiMasyvoDydi(ziurintysIViduriPinai);

/** ŽIŪRI į kairę */
const int ziurintysIKaireSensoriai[][2] = {
		{16, -90},
		{19, -15},
		{18, -45}
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
const int visiPinaiDydis = kiekYraSensoriuPinu;


/**
 * dinamiškai sukuriamas `inicializuoti()` funkcijoje
 * iš kitų turimų duomenų
 */
int pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[kiekYraSensoriuPinu][2];
int visiPinai[kiekYraSensoriuPinu];

/** ŽIŪRI į linijas (bet jau nebesvarbūs skaičiavimams) */
const int linijuSensoriai[] = {
	34, /** LeftLine1 */
	33, /** LeftLine2 */
	31, /** RightLine1 */
	32 /** RightLine2 */
};

const size_t linijuSensoriaiDydis = gautiMasyvoDydi(linijuSensoriai);

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
