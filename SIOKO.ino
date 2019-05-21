/*
 * SIOKO.ino
 * 
 * Pagrindinis programos failas.
 * 
 * Copyright (c) 2019 Kipras Melnikovas, Vismantas Masiokas, Neilas Antanavičius
 * 
*/

/**
 * Kas yra etr? (Naudojamas pulteliuNustatytiStrategijas, galbūt geriau jį ten deklaruoti?) 
 * > Perkėliau į pulteliuNustatytiStrategijas failą
 * 
 * Iš kur gauti IRremote.h biblioteką? kurią čia naudojat?
 * 
 * 
 * Search'inimo keywords'ai: [TODO, CHECK, WARN, BROKEN]
 */

#include "inicializuoti.h"
#include "strategijos.h"
#include "IRremote/IRremote.h"
#include "irremote_pultelis.h"
#include "pagalbines_funkcijos.h"
#include "vairuotiRobota.h"
#include "ivairusTestai.h"
#include "strategijos.h"

// const byte START_MODULE = 29;

void setup()
{
	Serial.begin(115200);

	inicializuoti();

	const byte outputPins[] = {
			LEDas,
			PWM1,
			PWM2,
			DIR1,
			DIR2,
	};

	const byte inputPins[] = {LeftLine1, LeftLine2, RightLine1, RightLine2, Right1, Right2, Right3, Rightback,
														Left1, Left2, Left3, Leftback, Middle1, Middle2, Middle3, START_MODULE};

	for (const byte &pin : outputPins)
	{
		pinMode(pin, OUTPUT);
	}

	for (const byte &pin : inputPins)
	{
		pinMode(pin, INPUT);
	}
	// #NOTE - `analogWriteFrequency` susijęs su motor `analogWrite`.

	analogWriteFrequency(PWM2, 15000.0f); /** #BROKEN #CHECK ką daro šitas? Neveikia man, meta errorus, gal neturiu bibliotekos kažkokios */
	analogWriteFrequency(PWM1, 15000.0f);

	// // motor(255, 255);

	irrecv.enableIRIn(); /** CHECK ką šitas daro? */

	/**
	 * #TEMP #DEV - išjungiam strategijų pultelį 
	 */

	// pulteliuNustatytiStrategijas();
	MAIN_STRATEGY_STATE = 1;
	START_STRATEGY_STATE = 1;

	// Serial.print(digitalRead(arStabdytiMotorus() == false));

	/** 
	 * laukti, iki kol `START_MODULE` == `HIGH`
	 */
	while (true)
	{
		if (arStabdytiMotorus() == false)
		{
			break;
		}
	}

	// while (true)
	// {
	// 	if (digitalRead(START_MODULE) == HIGH)
	// 	{
	// 		break;
	// 	}

	// 	atnaujintiJutikliuDuomenis();
	// }

	// vykdytiStrategija(pradineStrategija);

	// pirmaStrategija();
	// hardCodedVarikliuTestai();
}

void loop()
{
	// vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai();
	vairuotiRobotaSuApskaiciavimais();

	// hardCodedVarikliuTestai();

	// if (!printinom)
	// {
	// 	Serial.print("\nvisi pinai ir jų teikiami balai");
	// 	// Serial.print(visiPinaiIrJuTeikiamiBalai);
	// 	for (int i = 0; i < sizeof(visiPinaiIrJuTeikiamiBalai) / sizeof(double); i++)
	// 	{
	// 		Serial.print(i);
	// 		Serial.print(visiPinaiIrJuTeikiamiBalai[i][0]);
	// 		Serial.print(visiPinaiIrJuTeikiamiBalai[i][1]);
	// 	}

	// 	printinom = true;
	// }

	// sukimosiTestaiSuEnter();

	// motoraiSuLaiku(10, -10, 1000);

	// motoraiSuLaiku(-10, 10, 1000);

	// sukimosiTestaiSuEnter();

	// Serial.print("mySIDES, myFRONT, myLINE = ");
	// Serial.print(mySIDES);
	// Serial.print(myFRONT);
	// Serial.print(myLINE);
}

// void loop()
// {
// 	motor(100, -100);
// 	delay(1000);

// 	motor(0, 0);
// 	delay(2000);

// 	motor(-100, 100);
// 	delay(1000);

// 	motor(0, 0);
// 	delay(2000);
// }

// bool printinom = false;

/** <= --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- * --- => **/

/** 
 * Toliau eina legacy dalykai, kuriuos sukūriau ne aš, bet kurie dar
 * pilnai nepertvarkyti ir kol kas reikalingi naudojimui.
 *
 * Rekomenduojama jų nenaudoti, taip pat, jeigu įmanoma - perrašyti
 * esantį kodą su jais į naują kodą su atnaujintais kintamaisiais etc. 
*/

void loop_mano_old()
{
	/** Susivedam jutiklių duomenis ir apsisaugom nuo linijos kirtimo */
	atnaujintiJutikliuDuomenis();
	Line(); // #TODO perdaryt Linijos tikrinimą ir atsitraukimą (gali būt, kad neišvengsim while / delay)

	/** myFRONT turi 5 skirtingas pozicijas bitams. 2^5 = 32 skirtingi galimi variantai */

	/** tarkim, kad visada norim atsisukti tiesiai į priešininką ir tada pulti tiesiai į jį. */

	if (myFRONT == 0b01110 || myFRONT == 0b01100 || myFRONT == 0b00110 || myFRONT == 0b00100)
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn); // CHARGE!
	}

	/** kol tiesiai nematom oponento */

	// while (myFRONT != 0b01110 && myFRONT != 0b01100 && myFRONT != 0b00110 && myFRONT != 0b00100)
	// {
	// 	if (myFRONT == 0b00000)
	// 	{
	// 		// do stuff with sides
	// 	}

	// 	switch (myFRONT)
	// 	{
	// 	case 0b10000: // labai kairėje
	// 		motor();
	// 		break;
	// 	case 0b11000:
	// 	case 0b01000:
	// 	}
	// }
}

// void loop_old()
// {
// 	/** Susivedam jutiklių duomenis ir apsisaugom nuo linijos kirtimo */
// 	atnaujintiJutikliuDuomenis();
// 	Line();

// 	/** kažką darom lol. reikia rewrittint. */
// 	switch (pagrindineStrategija)
// 	{
// 	case stratPirmaNEC1:
// 		switch (myFRONT)
// 		{
// 		case 0b10000:
// 		case 0b11000:
// 			SpinLeft(SPEED_TURN, 0.1);
// 			break;
// 		case 0b00001:
// 		case 0b00011:
// 			SpinRight(SPEED_TURN, 0.1);
// 			break;
// 		case 0b00000:
// 			atnaujintiJutikliuDuomenis();
// 			Line();
// 			switch (mySIDES)
// 			{
// 			case 0b000000:
// 				atnaujintiJutikliuDuomenis();
// 				Line();
// 				break;
// 			case 0b001000:
// 			case 0b111000:
// 			case 0b101000:
// 			case 0b011000:
// 				SpinLeft(SPEED_TURN, 10);
// 				break;
// 			case 0b000100:
// 			case 0b000110:
// 			case 0b000111:
// 			case 0b000101:
// 				SpinRight(SPEED_TURN, 10);
// 				break;
// 			case 0b010000:
// 				SpinLeft(SPEED_TURN, 5);
// 				break;
// 			case 0b000010:
// 				SpinRight(SPEED_TURN, 5);
// 				break;
// 			case 0b110000:
// 			case 0b100000:
// 				SpinLeft(SPEED_TURN, 40);
// 				break;
// 			case 0b000011:
// 			case 0b000001:
// 				SpinRight(SPEED_TURN, 40);
// 				break;
// 			}
// 			break;
// 		default:
// 			time = millis();
// 			while (millis() - time <= 100 && digitalRead(Middle1) == 0 && digitalRead(Middle2) == 0 && digitalRead(Middle3) == 0 && millis() - time >= 40)
// 			{
// 				motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
// 			}
// 			break;
// 		}
// 		break;

// 	case startAntraNEC2:
// 		switch (myFRONT)
// 		{
// 		case 0b10000:
// 		case 0b11000:
// 			SpinLeft(SPEED_TURN, 0.1);
// 			break;
// 		case 0b00001:
// 		case 0b00011:
// 			SpinRight(SPEED_TURN, 0.1);
// 			break;
// 		case 0b00000:
// 			atnaujintiJutikliuDuomenis();
// 			Line();
// 		default:
// 			time = millis();
// 			while (millis() - time <= 100 && digitalRead(Middle1) == 0 && digitalRead(Middle2) == 0 && digitalRead(Middle3) == 0 && millis() - time >= 40)
// 			{
// 				motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
// 			}
// 			break;
// 		}
// 		break;

// 	case stratTreciaNEC3:
// 		atnaujintiJutikliuDuomenis();
// 		Line();
// 		break;

// 		/**
// 	 * TODO CHECK - o kodėl tiek mažai strategijų?
// 	 * Ir apskritai kažkaip nekaip padaryta, nes nustatant ir pradinę, ir pagrindinę, naudojamos tos pačios
// 	 */

// 		/** #WARN #DANGER delayinam (stabdom programą 2 sekundėm (tik
// 	 * važiuojam, bet pinai neskenuojami ir nekeičiami!) uh oh bad!)
// 	 * https://www.arduino.cc/reference/en/language/functions/time/delay/
// 	 */

// 	case stratDevintaNEC9:
// 		motor(100, 100);
// 		delay(2000);
// 		motor(-100, -100);
// 		delay(2000);
// 		break;
// 	}
// }

void Line()
{
	//Back = false;
	//Linija
	switch (myLINE)
	{
	case 0b0011: //Right
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
			//atnaujintiJutikliuDuomenis_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK_1)
		{
			motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
			//atnaujintiJutikliuDuomenis_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		break;
	case 0b1100: //Left
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
			//atnaujintiJutikliuDuomenis_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK_1)
		{
			motor(SPEED_GO_BACK_LINE_TURN, -SPEED_GO_BACK_LINE_TURN2);
			//atnaujintiJutikliuDuomenis_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		break;
	case 0b1111: //Both
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
			//atnaujintiJutikliuDuomenis_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
			//atnaujintiJutikliuDuomenis_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		break;
		// case 0:
		// 	motor(SPEED_NORMAL, SPEED_NORMAL);
		// 	break;
	}
}

void SpinRight(int a, int t)
{
	time = millis();
	while (millis() - time <= t && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(a, -a);
	}
}

void SpinLeft(int a, int t)
{
	time = millis();
	while (millis() - time <= t && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(-a, a);
	}
}
