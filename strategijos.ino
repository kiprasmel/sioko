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
#include "strategijos.h"
#include "motoras.h"
// enum StrategijosPagalHex
// {
// 	stratPirma = 0xFF906F,									// TODO - reikia užvadinti
// 	stratAntra = 0xFFB847,									//
// 	stratTrecia = 0xFFF807,									//
// 	stratZigzagasDesinenMazas = 0xFF9867,		// stratZigzagasDesinenMazas
// 	stratZigzagasKairenMazas = 0xFFD827,		// stratZigzagasKairenMazas
// 	stratZigzagasDesinenDidelis = 0xFF8877, // stratZigzagasDesinenDidelis
// 	stratZigzagasKairenDidelis = 0xFFE817,	// stratZigzagasKairenDidelis
// 	stratAstunta = 0xFF48B7,
// 	stratDevinta = 0xFF9A65,
// 	stratPatvirtinimas = 0xFFE01F // TODO anksčiau `enter`
// };

void vykdytiStrategija(StrategijosPagalHex strategijosKodas)
{
	switch (strategijosKodas)
	{
	case stratPirma:
		pirmaStrategija();
		break;
	case stratAntra:
		antraStrategija();
		break;
	case stratTrecia:
		treciaStrategija();
		break;
	case stratZigzagasDesinenMazas:
		zigzagasDesinenMazas();
		break;
	case stratZigzagasKairenMazas:
		zigzagasKairenMazas();
		break;
	case stratZigzagasDesinenDidelis:
		zigzagasDesinenDidelis();
		break;
	case stratZigzagasKairenDidelis:
		zigzagasKairenDidelis();
		break;
	}
}

// const int SPEED_NORMAL = 200;
// TODO - pervardinti strategijų pavadinimus
void pirmaStrategija()
{
	motor(SPEED_NORMAL, SPEED_NORMAL);
}

void antraStrategija()
{
	motor(255, 255);
	delay(200);
}

void treciaStrategija()
{
	motor(255, 255);
	delay(325);
}

void zigzagasKairenMazas()
{
	Serial.println("#TODO - dar nepadaryta");
}

void zigzagasDesinenDidelis()
{
	Serial.println("#TODO - dar nepadaryta");
}

void zigzagasKairenDidelis()
{
	Serial.println("#TODO - dar nepadaryta");
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

void zigzagasDesinenMazas()
{
	Serial.println("#TODO - dar nepadaryta (dabar tobulinu)");

	bool matome = false;
	unsigned int laikas = millis();

	// #TODO #STRATS
	const int directions[6][2] = {
			{-200, 200},
			{0, 0},
			{255, 255},
			{200, -200},
			{0, 0},
			{255, 255}};

	// CHECK 20 ms tikrina, right? Bet kiek kartų įvyksta tikrinimas
	// Nes kiek kartų patikrina, kol praeina 20 ms?
	while (millis() - laikas <= 20 && !arVidurysKaNorsMato())
	//  (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(-200, 200);
		jutikliuDuomenys();

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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255); // #go
			jutikliuDuomenys();
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
		jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
    motor(255, 255);
    delay(135);
    motor(200, -200);
    delay(45);
    motor(0, 0);
    delay(5);
    motor(255, 255);
    delay(135);*/
}

void zigzag_kaire_M()
{
	bool see = false;
	time = millis();
	while (millis() - time <= 20 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(200, -200);
		jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
    motor(255, 255);
    delay(50);
    motor(-200, 200);
    delay(20);
    motor(255, 255);
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
		jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
    motor(255, 255);
    delay(100);
    motor(200, -200);
    delay(40);
    motor(255, 255);
    delay(150);*/
}
void zigzag_kaire_D()
{
	bool see = false;
	time = millis();
	while (millis() - time <= 20 && (digitalRead(Middle1) == 1 || digitalRead(Middle2) == 1 || digitalRead(Middle3) == 1))
	{
		motor(200, -200);
		jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			jutikliuDuomenys();
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
			motor(255, 255);
			jutikliuDuomenys();
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
    motor(255, 255);
    delay(100);
    motor(-200, 200);
    delay(40);
    motor(255, 255);
    delay(150);*/
}
//------------------------------------------------------------------------------
