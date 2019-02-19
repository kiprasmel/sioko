#include "ivairusTestai.h"
#include "irremote_pultelis.h" // tik testavimo strategijoms
#include "inicializuoti.h"		 // tik testavimo strategijoms

void hardCodedVarikliuTestai()
{
	const int msTimeStamps[] = {
			150,
			140,
			130};

	int masyvoDydis = sizeof(msTimeStamps) / sizeof(msTimeStamps[0]);

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