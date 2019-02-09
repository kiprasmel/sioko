#include "motoras.h"

/** jeigu motoroGreitis < 0, kryptis atgal (1), o jeigu >= 0, tai kryptis pirmyn (0). Returnina `int`! */
int kokiaKryptis(int motoroGreitis)
{
	return motoroGreitis < 0 ? VaziavimoKryptys::kryptisAtgal : VaziavimoKryptys::kryptisPirmyn;
	// return motoroGreitis < 0 ? 1 : 0;
}

void motor(int kairioMotoroGreitis, int desinioMotoroGreitis)
{
	// `constrain`: jei a > 255 arba < -255, tai returnins minimalią / maximalią reikšme (255 arba -255)
	kairioMotoroGreitis = constrain(kairioMotoroGreitis, -255, 255);
	desinioMotoroGreitis = constrain(desinioMotoroGreitis, -255, 255);

	// Jeigu žema įtampa, sustabdom motorus.
	if (digitalRead(START_MODULE) == LOW)
	{
		kairioMotoroGreitis = 0;
		desinioMotoroGreitis = 0;
	}

	analogWrite(PWM1, kairioMotoroGreitis); // greitis
	digitalWrite(DIR1, kokiaKryptis(kairioMotoroGreitis));

	analogWrite(PWM2, desinioMotoroGreitis); // greitis
	digitalWrite(DIR2, kokiaKryptis(desinioMotoroGreitis));
}

/** naudoja while ciklą, kad motorai vykdytų dalykus X laiko */
void motoraiSuLaiku(int kairioMotoroGreitis, int desinioMotoroGreitis, unsigned long kiekMsLaukti)
{
	time = millis();
	motor(kairioMotoroGreitis, desinioMotoroGreitis);
	while (millis() - time <= kiekMsLaukti)
	{
		// pause programm (not good). Much like using a delay.
	}
}
