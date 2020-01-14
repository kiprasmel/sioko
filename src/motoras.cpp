#include <Arduino.h>
#include "motoras.h"
#include "inicializuoti.h"
#include "pagalbines_funkcijos.h"

/** jeigu motoroGreitis < 0, kryptis atgal (1), o jeigu >= 0, tai kryptis pirmyn (0). Returnina `int`! */
int kokiaKryptis(int motoroGreitis)
{
	return motoroGreitis < 0 ? VaziavimoKryptys::kryptisAtgal : VaziavimoKryptys::kryptisPirmyn;
	// return motoroGreitis < 0 ? 1 : 0;
}

bool arStabdytiMotorus()
{
	const int startModulis = digitalRead(START_MODULE);
	const bool arStabdyti = startModulis == HIGH ? false : true;

	// Serial.print("\nSTART_MODULE ");
	// Serial.print(START_MODULE);
	// Serial.print("\nstartModulis ");
	// Serial.print(startModulis);
	// Serial.print("\narStabdyti ");
	// Serial.print(arStabdyti);

	return arStabdyti;
	// return digitalRead(START_MODULE) == LOW ? true : false;
}

/**
 * laukti, iki kol `START_MODULE` == `HIGH`
 *
 * BAD, nes ir motoras tą patį daro
 *
 */
void lauktiKolPaleisimRobota()
{
	while (arStabdytiMotorus())
	{
	}
}

void motor(int a, int b)
{
	a = constrain(a, -255, 255);
	b = constrain(b, -255, 255);
	// a-=10;//buvo80 pries tempima i viena puse

	// /** lekiam pirmyn, jeigu priekis mato */
	// if (arVidurysKaNorsMato()) {
	// 	a = 255;
	// 	b = 255;
	// }

	if (arStabdytiMotorus())
	{
		a = 0;
		b = 0;
	}

	if (a == b && a == greitisVaziavimoPirmyn) {
		/** važiuojam pirmyn */
		ledasON();
	} else {
		ledasOFF();
	}

	if (a <= -1) //&& a > -255
	{
		digitalWrite(DIR1, 1);
		analogWrite(PWM1, (255 - abs(a)));
	}
	else if (a >= 1)
	{
		digitalWrite(DIR1, 0);
		analogWrite(PWM1, a);
	}
	else if (a == 0)
	{
		digitalWrite(DIR1, 0);
		analogWrite(PWM1, 0);
	}

	if (b >= 1) //&& b > -255
	{
		// b = map(abs(b), 0,255,255,0);
		digitalWrite(DIR2, 0);
		analogWrite(PWM2, b); // 255 -
	}
	else if (b <= -1) //&& b < 255
	{
		digitalWrite(DIR2, 1);
		analogWrite(PWM2, (255 - abs(b)));
	}
	else if (b == 0)
	{
		digitalWrite(DIR2, 0);
		analogWrite(PWM2, 0);
	}
}


// void motor(int kairioMotoroGreitis, int desinioMotoroGreitis)
// {
// 	// `constrain`: jei a > 255 arba < -255, tai returnins minimalią / maximalią reikšme (255 arba -255)
// 	kairioMotoroGreitis = constrain(kairioMotoroGreitis, -255, 255);
// 	desinioMotoroGreitis = constrain(desinioMotoroGreitis, -255, 255);

// 	// Jeigu žema įtampa, sustabdom motorus.
// 	if (digitalRead(START_MODULE) == LOW)
// 	{
// 		kairioMotoroGreitis = 0;
// 		desinioMotoroGreitis = 0;
// 	}

// 	if (kairioMotoroGreitis <= -1)
// 	{
// 		kairioMotoroGreitis = 255 - abs(kairioMotoroGreitis);
// 	}
// 	if (desinioMotoroGreitis <= -1)
// 	{
// 		desinioMotoroGreitis = 255 - abs(desinioMotoroGreitis);
// 	}

// 	Serial.print("\nKairio gretis, desinio gretis = ");
// 	Serial.print(kairioMotoroGreitis);
// 	Serial.print(" ");
// 	Serial.print(desinioMotoroGreitis);

// 	analogWrite(PWM1, kairioMotoroGreitis); // greitis
// 	digitalWrite(DIR1, kokiaKryptis(kairioMotoroGreitis));

// 	analogWrite(PWM2, desinioMotoroGreitis); // greitis
// 	digitalWrite(DIR2, kokiaKryptis(desinioMotoroGreitis));
// }

void motoraiKolPriekisPamato(int kairioMotoroGreitis, int desinioMotoroGreitis) {
	motor(kairioMotoroGreitis, desinioMotoroGreitis);

	while (true) {
		motor(kairioMotoroGreitis, desinioMotoroGreitis);

		if (arVidurysKaNorsMato()) {
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);

			// motor(0, 0);
			digitalWrite(LEDas, HIGH);
			// while (true) {};

			delay(50);

			digitalWrite(LEDas, LOW);

			return;
		}
	}

	return;
}

/**
 * TODO - šito bent kol kas nenaudojam,
 * nes vėlgi - stateChart'ai,
 *
 * o ir apskritai čia gana keblu nuspręsti,
 * kada yra laikas nutraukti etc
 * ir atsiranda daugybė kitų bug'ų,
 * kur neaišku, ar hardware'as, ar software'as kaltas.
 *
 * So no honey for this bad boy rn.
 *
 * naudoja while ciklą, kad motorai vykdytų dalykus X laiko
 * (senoji versija iš `v1.1.0` (9962c68))
 */
void motoraiSuLaiku(int kairioMotoroGreitis, int desinioMotoroGreitis, unsigned long kiekMsLaukti)
{
	// if (arVidurysKaNorsMato())
	// {
	// 	motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
	// 	kiekMsLaukti = -1;
	// 	return; // nežinau, ar veikia returnas (ar nutraukia ciklą)
	// }

	time = millis();
	// unsigned long laikasDepth2;

	motor(kairioMotoroGreitis, desinioMotoroGreitis);

	while (millis() - time < kiekMsLaukti)
	{
		/**
		 * tikrinam jutiklių duomenis, jog jeigu priekis ką nors mato - iškart varytume į priekį.
		 */
		atnaujintiJutikliuDuomenis(); // #NEW! Gali būt, kad sutvarkys.
		// Line();							// gali būt bėdų dėl prastos funkcijos #TODO ATKOMENTUOT

		if (arVidurysKaNorsMato())
		{
			// motor(-kairioMotoroGreitis, -desinioMotoroGreitis);

			// motor(0, 0);
			// delay(2500);

			// laikasDepth2 = millis();
			// while (millis() - laikasDepth2 < 2500)
			// {
			// 	atnaujintiJutikliuDuomenis();
			// 	// delay(2500);
			// 	// Line();
			// 	arVidurysKaNorsMato(); // tiesiog atnaujins ledą
			// }

			// motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			// kiekMsLaukti = -1;

			// ledasON();
			// while (1) {};

			// return; // nežinau, ar veikia returnas (ar nutraukia ciklą)
		}
		// pause programm (not good). Much like using a delay.
	}

	/** questionable */
	motor(0, 0);
}

// void motoraiSuLaiku(int kairioMotoroGreitis, int desinioMotoroGreitis, unsigned long kiekMsLaukti)
// {
// 	unsigned long pradinisLaikas = millis();

// 	while (millis() - pradinisLaikas <= kiekMsLaukti && !arVidurysKaNorsMato())
// 	{
// 		motor(kairioMotoroGreitis, desinioMotoroGreitis);
// 	}

// 	return;
// }

void motoraiSuLaikuNereguojantysIPrieki(int kairioMotoroGreitis, int desinioMotoroGreitis, unsigned long kiekMsLaukti)
{
	time = millis();
	motor(kairioMotoroGreitis, desinioMotoroGreitis);
	while (millis() - time < kiekMsLaukti)
	{
	}
	motor(0, 0);
}

/**
 * DĖMESIO
 *
 * Atsargiai su `delay` - jie užlaikys visą programą,
 * ne tik LED'ą - motoras važiuos į priekį ilgiau
 * nepaisant kitų sąlygų, nes nieks nesikeis (duh)
 *
 * NOTE
 * Šitas neužlockins važiavimui pirmyn - jis tik pasiūs!
 *
 */
bool siunciamPirmynJeiguPriekisMato(bool arRodytLEDa) {
	if (arVidurysKaNorsMato())
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);

		// if (arRodytLEDa) {
		// 	digitalWrite(LEDas, HIGH);
		// 	delay(10);
		// }

		return true;

	} else {
		// if (arRodytLEDa) {
		// 	digitalWrite(LEDas, LOW);
		// 	delay(10);
		// }

		return false;
	}
}

void siunciamIrUzlokinamPirmynKolPriekisMato(bool arRodytLEDa) {
	while (arVidurysKaNorsMato()) {

		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);

		if (arRodytLEDa) {
			digitalWrite(LEDas, HIGH);
			delay(10);
		}
	}

	digitalWrite(LEDas, LOW);
	delay(10);

	return;
}
