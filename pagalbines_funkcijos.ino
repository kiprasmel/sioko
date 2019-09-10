#include "pagalbines_funkcijos.h"
#include "inicializuoti.h"

/**
 * NOTE:
 * Tikrinant su `digitalRead`, mato tada, kai `== 0`, o ne `1`!
 */

bool arVidurysKaNorsMato()
{
	const int kiekMato = kiekMatoKazkuriPuse(ziurintysIViduriPinai, ziurintysIViduriPinaiDydis);

	if (
		kiekMato > 0
			// digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0
			//|| digitalRead(Left1) == 0 || digitalRead(Right1) == 0
			// makes checking loose (also includes the near left & right sensors)
	)
	{
		// Serial.print("\nVidurys");

		// digitalWrite(LEDas, HIGH);
		return true;
	}
	else
	{
		// digitalWrite(LEDas, LOW);
		return false;
	}
}

bool arKaireKaNorsMato()
{
	const int kiekMato = kiekMatoKazkuriPuse(ziurintysIKairePinai, ziurintysIKairePinaiDydis);

	if (kiekMato > 0) {
		// Serial.print("\nKaire");

		// digitalWrite(LEDas, HIGH);
		return true;
	} else {
		// digitalWrite(LEDas, LOW);
		return false;
	}

// 	if (digitalRead(Left1) == 0 || digitalRead(Left2) == 0 || digitalRead(Left3) == 0)
// 	{
// 		Serial.print("\nKaire");

// 		digitalWrite(LEDas, HIGH);
// 		return true;
// 	}
// 	else
// 	{
// 		digitalWrite(LEDas, LOW);
// 		return false;
// 	}
}

bool arDesineKaNorsMato()
{
	const int kiekMato = kiekMatoKazkuriPuse(ziurintysIDesinePinai, ziurintysIDesinePinaiDydis);

	// byte pinas;
	// bool bentVienasMato = false;

	// for (int i = 0; i < ziurintysIDesinePinaiDydis; i++) {
	// 	pinas = ziurintysIKairePinai[i];

	// 	if (digitalRead(pinas)) {
	// 		bentVienasMato = true;
	// 	}
	// }

	// if (bentVienasMato)
	if (kiekMato > 0) {
	// Serial.print("\nDesine");

		// digitalWrite(LEDas, HIGH);
		return true;
	} else {
		// digitalWrite(LEDas, LOW);
		return false;
	}
}

int kiekMatoKazkuriPuse(const int pinaiSkenavimui[], const int masyvoDydis)
{
	int suma = 0;

	for (int i = 0; i < masyvoDydis; ++i)
	{
		if (digitalRead(pinaiSkenavimui[i]) == 0) // jeigu matome
		{
			++suma;
		}
	}
	return suma;
}

void atnaujintiBitusXPusesPagalPinus(byte &kazkuriPuse, const int pinaiSkenavimui[], int masyvoDydis)
{
	/** pirma išvalyti; tas 10 keistas */
	for (int i = 0; i < 10; ++i)
	{
		bitClear(kazkuriPuse, i);
	}

	for (int i = 0; i < masyvoDydis; ++i)
	{
		if (digitalRead(pinaiSkenavimui[i]) == 0) // jeigu matome
		{
			bitSet(kazkuriPuse, i); // 1
		}
		// // else // nematome
		// // {
		// // 	bitClear(kazkuriPuse, i); // 0
		// // }
	}
	// // return kazkuriPuse;
}

void atnaujintiJutikliuDuomenis() {
	atnaujintiBitusXPusesPagalPinus(myLINE, linijuSensoriai, gautiMasyvoDydi(linijuSensoriai));
	// // atnaujintiBitusXPusesPagalPinus(MYFRONT, ziurintysIKaireSensoriai);
	// // atnaujintiBitusXPusesPagalPinus(, ziurintysIKaireSensoriai);
}

/**
 * TODO wtf - ar čia iš viso kur nors naudojama?
 * Niekur nematau `myFRONT` / `mySIDES` kintamųjų
 * Matau tik `myLINE`
 */
// void atnaujintiJutikliuDuomenis_OLD()
// {
// 	for (int i = 0; i <= 9; i++)
// 	{ //9
// 		bitClear(myLINE, i);
// 		bitClear(myFRONT, i);
// 		bitClear(mySIDES, i);
// 	}
// 	//Sonai

// 	//if (digitalRead(Rightback) == 0)  bitSet(mySIDES, 0);
// 	if (digitalRead(Right1) == 0)
// 		bitSet(mySIDES, 1);
// 	if (digitalRead(Right2) == 0)
// 		bitSet(mySIDES, 2);
// 	if (digitalRead(Left2) == 0)
// 		bitSet(mySIDES, 3);
// 	if (digitalRead(Left1) == 0)
// 		bitSet(mySIDES, 4);
// 	//if (digitalRead(Leftback) == 0)   bitSet(mySIDES, 5);

// 	//Priekis
// 	if (digitalRead(Right3) == 0)
// 		bitSet(myFRONT, 0);
// 	if (digitalRead(Middle1) == 0)
// 		bitSet(myFRONT, 1);
// 	if (digitalRead(Middle2) == 0)
// 		bitSet(myFRONT, 2);
// 	if (digitalRead(Middle3) == 0)
// 		bitSet(myFRONT, 3);
// 	if (digitalRead(Left3) == 0)
// 		bitSet(myFRONT, 4);

// 	/*if (digitalRead(Right1) == 0) bitSet(myFRONT, 6);
//     if (digitalRead(Right2) == 0) bitSet(myFRONT, 5);*/
// 	/*if (digitalRead(Right3) == 0) bitSet(myFRONT, 4);
//     if (digitalRead(Middle2) == 0) bitSet(myFRONT, 3);
//     if (digitalRead(Left3) == 0) bitSet(myFRONT, 2);*/
// 	/*if (digitalRead(Left2) == 0) bitSet(myFRONT, 1);
//     if (digitalRead(Right1) == 0) bitSet(myFRONT, 0);*/

// 	//Linija
// 	if (digitalRead(LeftLine1) == 1)
// 		bitSet(myLINE, 3);
// 	if (digitalRead(LeftLine2) == 1)
// 		bitSet(myLINE, 2);
// 	if (digitalRead(RightLine1) == 1)
// 		bitSet(myLINE, 0);
// 	if (digitalRead(RightLine2) == 1)
// 		bitSet(myLINE, 1);
// }
