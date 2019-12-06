#include <Arduino.h>
#include "ivairusTestai.h"
#include "irremote_pultelis.h" // tik testavimo strategijoms
#include "inicializuoti.h"		 // tik testavimo strategijoms
#include "motoras.h"
#include "pagalbines_funkcijos.h"
#include "strategijos.h"

void hardCodedVarikliuTestai()
{
	const int msTimeStamps[] = {
			150,
			140,
			130};

	int masyvoDydis = gautiMasyvoDydi(msTimeStamps);

	motor(0, 0);
	for (int i = 0; i < masyvoDydis; ++i)
	{
		lauktiEnterPaspaudimo();

		// #WARN - prieš tai testavimui naudojom ne šitą, o delay!!

		motoraiSuLaikuNereguojantysIPrieki(-greitisSukimosi, greitisSukimosi, msTimeStamps[i]);
		// motor(255, -255); // right
		// delay(msTimeStamps[i]);
		// motor(0, 0);

		delay(200); // kad nepasispaustų knopkė kelis kartus

		// delay(4000);

		// motor(-255, 255); // left
		// delay(msTimeStamps[i]);
		// motor(0, 0);
		// delay(1500);
	}

	// delay(2000);

	// for (int i = 0; i < masyvoDydis; ++i)
	// {
	// 	motor(-255, 255); // left
	// 	delay(msTimeStamps[i]);
	// 	motor(0, 0);
	// 	delay(2000);

	// 	motor(255, -255); // right
	// 	delay(msTimeStamps[i]);
	// 	motor(0, 0);
	// 	delay(2000);
	// }
}

void sukimosiTestaiSuEnter()
{
	const double sukimosiLaikai[] = {
			perKiekMsApsisukam360Sukdamiesi255,			// 360
			perKiekMsApsisukam360Sukdamiesi255 / 2, // 180
			perKiekMsApsisukam360Sukdamiesi255 / 4, // 90
																							// perKiekMsApsisukam360Sukdamiesi255 / 8, // 45
																							// perKiekMsApsisukam360Sukdamiesi255 / 12 // 30
	};

	const int masyvoDydis = sizeof(sukimosiLaikai) / sizeof(sukimosiLaikai[0]);

	motor(0, 0);
	for (int i = 0; i < masyvoDydis; i++)
	{
		// lauktiEnterPaspaudimo();
		motoraiSuLaikuNereguojantysIPrieki(-greitisSukimosi, greitisSukimosi, sukimosiLaikai[i]);
		motor(0, 0);
		delay(4000);
	}
}

void interaktyvusSukimosiTestaiNesibaigiantys()
{
	motor(0, 0);

	double lokalusPerKiekMs360 = perKiekMsApsisukam360Sukdamiesi255;
	StrategijosPagalHex gautasKodas;

	while (true) // visą laiką
	{
		while (true) // kol paspaudžiam enter (galim iki tol didinti / mažinti `lokalusPerKiekMs360`)
		{
			gautasKodas = lauktiMygtukoPaspaudimoIrGautiMygtukoKoda();

			if (gautasKodas == StrategijosPagalHex::stratPatvirtinimasNECEnter) // enter
			{
				break;
			}
			else if (gautasKodas == StrategijosPagalHex::stratPirmaNEC1) // 1
			{
				lokalusPerKiekMs360 += 5;
			}
			else if (gautasKodas == StrategijosPagalHex::stratTreciaNEC3) // 3
			{
				lokalusPerKiekMs360 -= 5;
			}
		}

		// kai baigia, patys skambina motor(0, 0)
		motoraiSuLaikuNereguojantysIPrieki(-greitisSukimosi, greitisSukimosi, lokalusPerKiekMs360); // left
	}
}

// void pinuSensoriuTestas()
// {
// 	/** (((int))) */
// 	// const int pinaiIrJuPavadinimai[][2] = {
// 	// 	[Left1, "left1"],
// 	// 	[Left2, "left2"],
// 	// 	[Left3, "left3"],
// 	// 	[Right1, "right1"],
// 	// 	[Right2, "right2"],
// 	// 	[Right3, "right3"],
// 	// 	[Middle1, "middle1"],
// 	// 	[Middle2, "middle2"],
// 	// 	[Middle3, "middle3"]
// 	// };

// 	const byte pinai[] = {Left1, Left2, Left3, Right1, Right2, Right3, Middle1, Middle2, Middle3};

// 	/**
// 	 * the number inside the second `[]` must be entered.
// 	 *
// 	 * It shall represent the number of characters
// 	 * that the longest string has
// 	 *
// 	 * (arduino just doesn't have strings - move to c++ already)
// 	 */
// 	const char pavadinimai[][9] = {"\nleft1", "\nleft2", "\nleft3",
// 																 "\nright1", "\nright2", "\nright3",
// 																 "\nmiddle1", "\nmiddle2", "\nmiddle3"};

// 	for (int i = 0; i < 9; i++)
// 	{
// 		if (digitalRead(pinai[i]) == 0)
// 		{
// 			Serial.print(pavadinimai[i]);
// 		}
// 	}
// }

void testuotiKiekLaikoSukames(unsigned long laikasMs) {
	motor(255, -255);
	delay(laikasMs);
	/**
	 * 50 per mažai stipriai
	 * 60 šiek tiek per daug
	 *
	 * 56 good 90 deg 255 speed
	 *
	 * ---
	 *
	 * 32 bandėm kažkam
	 *
	 */

	motor(0, 0);

	delay(3000);
}

void ijungtiLedaJeiBetKurisPinasMato() {
	arBetKuriPuseKaNorsMato() ? ledasON() : ledasOFF();
}
