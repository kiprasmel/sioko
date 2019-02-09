#include "pagalbines_funkcijos.h"

const int sonuPinai[] = {Right1, Right2, Left1, Left2};

bool arVidurysKaNorsMato()
{
	return (digitalRead(Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle3) == 0);
}

int kiekMatoKazkuriPuse(const int pinaiSkenavimui[])
{
	int suma = 0;
	int kiekPinu = (sizeof(pinaiSkenavimui) / sizeof(pinaiSkenavimui[0]));
	for (int i = 0; i < kiekPinu; ++i)
	{
		if (digitalRead(pinaiSkenavimui[i]) == 0) // jeigu matome
		{
			++suma;
		}
	}
	return suma;
}

void atnaujintiBitusXPusesPagalPinus(byte &kazkuriPuse, const int pinaiSkenavimui[])
{
	int kiekPinu = (sizeof(pinaiSkenavimui) / sizeof(pinaiSkenavimui[0]));

	// for (int i = 0; i < kiekPinu; ++i)
	// {
	// 	bitClear(kazkuriPuse, i);
	// }

	for (int i = 0; i < kiekPinu; ++i)
	{
		if (digitalRead(pinaiSkenavimui[i]) == 0) // jeigu matome
		{
			bitSet(kazkuriPuse, i); // 1
		}
		else // nematome
		{
			bitClear(kazkuriPuse, i); // 0
		}
	}
	// return kazkuriPuse;
}

void jutikliuDuomenys()
{
	atnaujintiBitusXPusesPagalPinus(myFRONT, priekioPinai);
	// myFRONT = atnaujintiBitusXPusesPagalPinus(myFRONT, priekioPinai);
	// mySIDES = ;

	// TODO FIX labai keistai čia nustatinėja. Kaip pertvarkyt normaliai?
	//Linija
	if (digitalRead(LeftLine1) == 1)
		bitSet(myLINE, 3);
	if (digitalRead(LeftLine2) == 1)
		bitSet(myLINE, 2);
	if (digitalRead(RightLine1) == 1)
		bitSet(myLINE, 0);
	if (digitalRead(RightLine2) == 1)
		bitSet(myLINE, 1);
}

/** 
 * TODO išsikelt kintamuosiuos masyvus (Pinų) į globalų scopą /
 * namespace'ą, kad nereiktų initialisint atskirai kiekvieną kart, kai
 * realiai jie tiesiog yra nuorodos (refs) į jau turimus globalius
 * kintamuosius
*/
// int Jutikliu_Duom()
// nuskenuot jutiklius, susivest info į myLINE, myFRONT, mySIDES kintamuosius booleanais
void jutikliuDuomenys_old()
{
	// TODO CHECK kodėl nuo 0 iki 9 (10 kartų)? Tipo turi myLINE, myFRONT ir mySIDES po 10 bitų?
	for (int i = 0; i <= 9; i++)
	{
		bitClear(myLINE, i);
		bitClear(myFRONT, i);
		bitClear(mySIDES, i);
	}

	// TODO CHECK kiek yra šonuose pinų? Ir ar reikia pradėt read'int ir settint nuo 1, ar nuo 0?
	// const int sonuPinai[] = {Right1, Right2, Left1, Left2};

	for (int i = 1; i <= sizeof(sonuPinai) / sizeof(const int); ++i)
	{
		if (digitalRead(sonuPinai[i]) == 0)
		{
			bitSet(mySIDES, i);
		}
	}

	// //if (digitalRead(Rightback) == 0)  bitSet(mySIDES, 0);
	// if (digitalRead(Right1) == 0)
	// 	bitSet(mySIDES, 1);
	// if (digitalRead(Right2) == 0)
	// 	bitSet(mySIDES, 2);
	// if (digitalRead(Left2) == 0)
	// 	bitSet(mySIDES, 3);
	// if (digitalRead(Left1) == 0)
	// 	bitSet(mySIDES, 4);
	// //if (digitalRead(Leftback) == 0)   bitSet(mySIDES, 5);

	// TODO CHECK kodėl sonuPinus pradedam nustatynėt nuo 1, o priekio nuo
	// 0? myFRONT atrodys 0bxxxxx kur x = 0 arba 1; bitSet visada nustato
	// 1; pradeda nustatinėt nuo mažiausiai reikšmingo (dešiniausio bito)
	// iki kairiausio.
	// const int priekioPinai[] = {Right3, Middle1, Middle2, Middle3, Left3};

	for (int i = 0; i < sizeof(priekioPinai) / sizeof(priekioPinai[0]); ++i)
	{
		if (digitalRead(priekioPinai[i]) == 0) // jeigu matome
		{
			bitSet(myFRONT, i); // myFRONT[i] = 1; (tik myFRONT yra bitų kintamasis)
		}
	}
	// if (digitalRead(Right3) == 0)
	// 	bitSet(myFRONT, 0);
	// if (digitalRead(Middle1) == 0)
	// 	bitSet(myFRONT, 1);
	// if (digitalRead(Middle2) == 0)
	// 	bitSet(myFRONT, 2);
	// if (digitalRead(Middle3) == 0)
	// 	bitSet(myFRONT, 3);
	// if (digitalRead(Left3) == 0)
	// 	bitSet(myFRONT, 4);

	/*if (digitalRead(Right1) == 0) bitSet(myFRONT, 6);
    if (digitalRead(Right2) == 0) bitSet(myFRONT, 5);*/
	/*if (digitalRead(Right3) == 0) bitSet(myFRONT, 4);
    if (digitalRead(Middle2) == 0) bitSet(myFRONT, 3);
    if (digitalRead(Left3) == 0) bitSet(myFRONT, 2);*/
	/*if (digitalRead(Left2) == 0) bitSet(myFRONT, 1);
    if (digitalRead(Right1) == 0) bitSet(myFRONT, 0);*/

	// TODO FIX labai keistai čia nustatinėja. Kaip pertvarkyt normaliai?
	//Linija
	if (digitalRead(LeftLine1) == 1)
		bitSet(myLINE, 3);
	if (digitalRead(LeftLine2) == 1)
		bitSet(myLINE, 2);
	if (digitalRead(RightLine1) == 1)
		bitSet(myLINE, 0);
	if (digitalRead(RightLine2) == 1)
		bitSet(myLINE, 1);
}
