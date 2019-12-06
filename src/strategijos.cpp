/**
 * TODO CHECK FIX
 *
 * 1. Pervadinti funkciją
 *
 * 2. Sumažinti ją iki minimumo (daug nereikalingų dalykų čia)
 *
 * 3. Apvalyt /(START|MAIN)_STRATEGY_STATE/ setinimą visoje programoje,
 *    kad būtų paprasčiau, nes tikrai galima
 *
 * 4. Sutvarkyt while() tikrinimus. Pirmiausia, millis() return'ina
 *    `unsigned long`, ir todėl negalima atlikti loginių operacijų
 *    lyginant su kitokiais duomenų tipais (net `int` ar net `long`).
 *    Pertvarkyt šitą. Source:
 *    https://www.arduino.cc/reference/en/language/functions/time/millis/
 * 			P.S. Buvo `unsigned int time`, tai viskas ok.
 *
 * 5. Nedėt į `case` blokus logikos, o juose iškviest funkciją.
 * 		a) Todėl sukurti funkcijas kiekvienam manevrui
 */

// TODO - pervadinti pagal strategijų pavadinimus
#include <Arduino.h>
#include "strategijos.h"
#include "pagalbines_funkcijos.h"
#include "strategijos.h"
#include "motoras.h"
#include "inicializuoti.h"

size_t laikas = 0;
StrategijosPagalHex pradineStrategija = nezinoma;
StrategijosPagalHex pagrindineStrategija = nezinoma;

extern StrategijosPagalHex pradineStrategija, pagrindineStrategija;

void vykdytiStrategija(StrategijosPagalHex strategijosKodas)
{
	switch (strategijosKodas)
	{
	case stratPirmaNEC1:
		pirmaStrategija();
		break;
	case stratAntraNEC2:
		antraStrategija();
		break;
	case stratTreciaNEC3:
		treciaStrategija();
		break;
	case stratZigzagasDesinenMazasNEC4:
		zigzagasDesinenMazas();
		break;
	case stratZigzagasKairenMazasNEC5:
		zigzagasKairenMazas();
		break;
	case stratZigzagasDesinenDidelisNEC6:
		zigzagasDesinenDidelis();
		break;
	case stratZigzagasKairenDidelisNEC7:
		zigzagasKairenDidelis();
		break;
	case stratPatvirtinimasNECEnter:
		/** do nothing (TODO reikia išimti) */
		break;
	case nezinoma:
		break;
	}
}

// const int SPEED_NORMAL = 200;
// TODO - pervardinti strategijų pavadinimus
// TODO FRESH persikelt į `hardCodedVarikliuTestai`
void pirmaStrategija()
{
	motor(SPEED_NORMAL, SPEED_NORMAL);
}

void antraStrategija()
{
	motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
	delay(200);
}

void treciaStrategija()
{
	motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
	delay(325);
}

void zigzagasKairenMazas()
{
	Serial.println("#TODO - dar nepadaryta");
	zigzag_kaire_M();
}

void zigzagasDesinenMazas()
{
	Serial.println("#TODO - dar nepadaryta");
	zigzag_desine_M();
}

void zigzagasKairenDidelis()
{
	Serial.println("#TODO - dar nepadaryta");
	zigzag_kaire_D();
}

void zigzagasDesinenDidelis()
{
	Serial.println("#TODO - dar nepadaryta");
	zigzag_desine_D();
}

/**
 * zigzagasDesinenMazas
 *
 * į dešinę
 * vietoje
 * max į priekį
 * stipriai į dešinę
 * vietoje
 * max į priekį
 */

void zigzagasDesinenMazas_unfinished()
{
	Serial.println("#TODO - dar nepadaryta (dabar tobulinu)");

	bool matome = false;
	unsigned int laikas = millis();

	// #TODO #STRATS
	// const int directions[6][2] = {
	// 		{-200, 200},
	// 		{0, 0},
	// 		{255, 255},
	// 		{200, -200},
	// 		{0, 0},
	// 		{255, 255}};

	// CHECK 20 ms tikrina, right? Bet kiek kartų įvyksta tikrinimas
	// Nes kiek kartų patikrina, kol praeina 20 ms?
	while (millis() - laikas <= 20 && !arVidurysKaNorsMato())
	//  (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(-200, 200);
		atnaujintiJutikliuDuomenis();

		if (myLINE != 0b0000 || arVidurysKaNorsMato())
		{
			matome = true;
			break;
		}
	}

	if (matome != true)
	{
		laikas = millis();
		while (millis() - laikas <= 5 &&
					 (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				matome = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				matome = true;
				break;
			}
		}
	}

	if (matome != true)
	{
		laikas = millis();
		while (millis() - laikas <= 120 &&
					 (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				matome = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				matome = true;
				break;
			}
		}
	}

	if (matome != true)
	{
		laikas = millis();
		while (millis() - laikas <= 45 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(200, -200);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				matome = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				matome = true;
				break;
			}
		}
	}

	if (matome != true)
	{
		laikas = millis();
		while (millis() - laikas <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				matome = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				matome = true;
				break;
			}
		}
	}

	if (matome != true)
	{
		laikas = millis();
		while (millis() - laikas <= 120 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn); // #go
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				matome = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				matome = true;
				break;
			}
		}
	}
}

void zigzag_desine_M()
{
	bool see = false;
	time = millis();

	while (millis() - time <= 20 &&
				 (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(-200, 200);
		atnaujintiJutikliuDuomenis();
		if (myLINE != 0b0000)
		{
			see = true;
			break;
		}
		if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
		{
			see = true;
			break;
		}
	}

	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 &&
					 (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}

	if (see != true)
	{
		time = millis();
		while (millis() - time <= 120 &&
					 (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}

	if (see != true)
	{
		time = millis();
		while (millis() - time <= 45 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(200, -200);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}

	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}

	if (see != true)
	{
		time = millis();
		while (millis() - time <= 120 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	/*motor(-200, 200);
    delay(20);
    motor(0, 0);
    delay(5);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(135);
    motor(200, -200);
    delay(45);
    motor(0, 0);
    delay(5);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(135);*/
}

void zigzag_kaire_M()
{
	bool see = false;
	time = millis();
	while (millis() - time <= 20 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(200, -200);
		atnaujintiJutikliuDuomenis();
		if (myLINE != 0b0000)
		{
			see = true;
			break;
		}
		if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
		{
			see = true;
			break;
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 120 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 45 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(-200, 200);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 120 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}

	/*motor(200, -200);
    delay(15);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(50);
    motor(-200, 200);
    delay(20);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(150);*/
}
//------------------------------------------------------------------------------
void zigzag_desine_D()
{
	bool see = false;
	time = millis();
	while (millis() - time <= 20 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(-200, 200);
		atnaujintiJutikliuDuomenis();
		if (myLINE != 0b0000)
		{
			see = true;
			break;
		}
		if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
		{
			see = true;
			break;
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 140 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 45 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(200, -200);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 140 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	/*motor(-200, 200);
    delay(40);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(100);
    motor(200, -200);
    delay(40);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(150);*/
}
void zigzag_kaire_D()
{
	bool see = false;
	time = millis();
	while (millis() - time <= 20 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(200, -200);
		atnaujintiJutikliuDuomenis();
		if (myLINE != 0b0000)
		{
			see = true;
			break;
		}
		if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
		{
			see = true;
			break;
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 140 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 45 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(-200, 200);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 5 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(0, 0);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	if (see != true)
	{
		time = millis();
		while (millis() - time <= 140 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
			atnaujintiJutikliuDuomenis();
			if (myLINE != 0b0000)
			{
				see = true;
				break;
			}
			if (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0)
			{
				see = true;
				break;
			}
		}
	}
	/*motor(200, -200);
    delay(40);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(100);
    motor(-200, 200);
    delay(40);
    motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
    delay(150);*/
}
//------------------------------------------------------------------------------
