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
	return digitalRead(START_MODULE) == HIGH ? false : true;
	// return digitalRead(START_MODULE) == LOW ? true : false;
}

void motor(int a, int b)
{
	a = constrain(a, -255, 255);
	b = constrain(b, -255, 255);
	// a-=10;//buvo80 pries tempima i viena puse

	if (arStabdytiMotorus())
	{
		a = 0;
		b = 0;
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

/** NEVEIKIA */
// void motor(int a, int b)
// {
// 	a = constrain(a, -255, 255);
// 	b = constrain(b, -255, 255);

// 	if (arStabdytiMotorus) {
// 		a = 0;
// 		b = 0;
// 	}

// 	// if (arVidurysKaNorsMato()) // #BAD
// 	// {
// 	// 	// motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
// 	// 	a = greitisVaziavimoPirmyn;
// 	// 	b = greitisVaziavimoPirmyn;
// 	// }

// 	if (a <= -1) //&& a > -255
// 	{
// 		digitalWrite(DIR1, 1);
// 		analogWrite(PWM1, (255 - abs(a)));
// 	}
// 	else if (a >= 1)
// 	{
// 		digitalWrite(DIR1, 0);
// 		analogWrite(PWM1, a);
// 	}
// 	else if (a == 0)
// 	{
// 		digitalWrite(DIR1, 0);
// 		analogWrite(PWM1, 0);
// 	}

// 	if (b >= 1) //&& b > -255
// 	{
// 		// b = map(abs(b), 0,255,255,0);
// 		digitalWrite(DIR2, 0);
// 		analogWrite(PWM2, b); // 255 -
// 	}
// 	else if (b <= -1) //&& b < 255
// 	{
// 		digitalWrite(DIR2, 1);
// 		analogWrite(PWM2, (255 - abs(b)));
// 	}
// 	else if (b == 0)
// 	{
// 		digitalWrite(DIR2, 0);
// 		analogWrite(PWM2, 0);
// 	}
// }

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

/** naudoja while ciklą, kad motorai vykdytų dalykus X laiko */
void motoraiSuLaiku(int kairioMotoroGreitis, int desinioMotoroGreitis, unsigned long kiekMsLaukti)
{
	if (arVidurysKaNorsMato())
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
		kiekMsLaukti = -1;
		return; // nežinau, ar veikia returnas (ar nutraukia ciklą)
	}

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

			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			kiekMsLaukti = -1;
			return; // nežinau, ar veikia returnas (ar nutraukia ciklą)
		}
		// pause programm (not good). Much like using a delay.
	}
	motor(0, 0);
}

void motoraiSuLaikuNereguojantysIPrieki(int kairioMotoroGreitis, int desinioMotoroGreitis, unsigned long kiekMsLaukti)
{
	time = millis();
	motor(kairioMotoroGreitis, desinioMotoroGreitis);
	while (millis() - time < kiekMsLaukti)
	{
	}
	motor(0, 0);
}
