#include <Arduino.h>
#include "linija.h"
#include "inicializuoti.h"
#include "motoras.h"

/**
 * WARNING
 * Not fully working yet (needs more testing)
 */
void linijosTikrinimas()
{
	if (myLINE == 0b0011)
	{
		motoraiSuLaiku(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE, TIME_FOR_GO_BACK_1);
		motoraiSuLaiku(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2, TIME_FOR_GO_BACK_1);
	}

	else if (myLINE == 0b1100)
	{
		motoraiSuLaiku(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE, TIME_FOR_GO_BACK);
		motoraiSuLaiku(SPEED_GO_BACK_LINE_TURN, -SPEED_GO_BACK_LINE_TURN2, TIME_FOR_GO_BACK_1);
	}
	else if (myLINE == 0b1111)
	{
		motoraiSuLaiku(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE, TIME_FOR_GO_BACK);
		motoraiSuLaiku(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2, TIME_FOR_GO_BACK); // nereik TIME_FOR_GO_BACK_1?
	}
}

void originaliLinijaBeDefaultCase()
{
	/**
	 * atnaujins `myLINE` etc.
	*/
	atnaujintiJutikliuDuomenis();

	// Serial.print("myLINE = ");
	// Serial.print(myLINE);
	// Serial.print("\n");
	// Serial.flush();

	//Back = false;
	//Linija
	switch (myLINE)
	{
	case 0b0011: //Right
		time = millis();
		// Serial.print("myLINE 3 - linija");
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
			//Jutikliu_duom_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK_1)
		{
			motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
			//Jutikliu_duom_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		break;
	case 0b1100: //Left
		time = millis();
		// Serial.print("myLINE 12 - linija");
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
			//Jutikliu_duom_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK_1)
		{
			motor(SPEED_GO_BACK_LINE_TURN, -SPEED_GO_BACK_LINE_TURN2);
			//Jutikliu_duom_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		break;
	case 0b1111: //Both
		// Serial.print("myLINE 15 - linija");
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
			//Jutikliu_duom_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		time = millis();
		while (millis() - time <= TIME_FOR_GO_BACK)
		{
			motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
			//Jutikliu_duom_back();
			if (myLINEBACK != 0b00)
			{
				break;
			}
		}
		break;
		// case 0:
		//   motor(SPEED_NORMAL, SPEED_NORMAL);
		//   break;
	}
}
