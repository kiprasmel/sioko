/**
 * Susivedam jutiklių duomenis ir apsisaugom nuo linijos kirtimo, o
 * tada vairuojam robotą :D
 * 
 * #TODO Taip pat reikia pertvarkyti `Line` funkciją - linijos tikrinimą ir atsitraukimą.
 * (gali būt, kad neišvengsim while / delay) 
*/

#include "vairuotiRobota.h"
#include "kurYraOponentas.h"
#include "motoras.h"
#include "inicializuoti.h"
#include "pagalbines_funkcijos.h"
#include "linija.h"
#include <math.h>

// for testing:
// #include "ivairusTestai.h"

void vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai()
{
	atnaujintiJutikliuDuomenis(); // #TODO #CHECK galima mėginti atkomentuot senąjį pin'ų surašymą

	// pinuSensoriuTestas(); // serial print'ai

	originaliLinijaBeDefaultCase();

	// Serial.print(myLINE + "\r\n");
	// Serial.println(myLINE + " linija");

	// // TESTING ONLY
	// if (arVidurysKaNorsMato() || arKaireKaNorsMato() || arDesineKaNorsMato())  {
	// 	motor(0, 0);
	// 	return;
	// }

	if (arVidurysKaNorsMato())
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn); // +max forward; +max forward
		return;
	}

	else if (arKaireKaNorsMato() || arDesineKaNorsMato())
	{

		/** dafuq? Abu šonai mato:D Tiesiog varom pirmyn */
		if (arKaireKaNorsMato() && arDesineKaNorsMato())
		{
			motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn); // +max forward; +max forward
			return;
		}

		else if (arKaireKaNorsMato())
		{
			motor(-greitisSukimosi, +greitisSukimosi); // -max rotate; +max rotate
			return;
		}
		else if (arDesineKaNorsMato())
		{
			motor(+greitisSukimosi, -greitisSukimosi); // -max rotate; +max rotate
			return;
		}
	}

	// nemato niekas
	else
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
		Serial.print("Niekas");
		return;
	}

	//// Ar KAIRĖ ką nors mato?  min => max reikšmingumas
	//// gali reikėt išimt Left1
	//// else if (digitalRead(Left1) || digitalRead(Left2) || digitalRead(Left3))
	//else if (arKaireKaNorsMato())
	//{
	//motor(-greitisSukimosi, +greitisSukimosi); // -max rotate; +max rotate
	//return;
	//}
	//// Ar DEŠINĖ ką nors mato? min => max reikšmingumas
	//// gali reikėt išimt Right1
	//else if (arDesineKaNorsMato())
	//{
	//motor(+greitisSukimosi, -greitisSukimosi); // +max rotate; -max rotate
	//return;
	//}
}

void vairuotiRobotaSuApskaiciavimais()
{
	atnaujintiJutikliuDuomenis();

	originaliLinijaBeDefaultCase();

	if (arVidurysKaNorsMato())
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
		return;
	}

	double oponentoPozicija = 0;
	double kiekMsReikesSuktis = 0;

	oponentoPozicija = kurYraOponentas(); // nuo -1 iki +1

	/** 
	 * skaičiuojam numamant, jog didžiausias kampas, kokį mato sensorius,
	 * palyginus su roboto priekiu, yra 90 laipsnių (360 / 4)
	 * #TODO #CLEANUP
	* #sukimosiSkaiciavimas
	*/
	kiekMsReikesSuktis = fabs(perKiekMsApsisukam90Sukdamiesi255 * oponentoPozicija); // nuo 0 iki 90 laipsnių
	// Serial.print(perKiekMsApsisukam360Sukdamiesi255);

	// Serial.print("\nKiek ms reikės suktis ");
	// Serial.print(kiekMsReikesSuktis);
	// Serial.print(" oponento pozicija ");
	// Serial.print(oponentoPozicija);

	Serial.print("\r\n\r\nOponento pozicija");
	Serial.print(oponentoPozicija);
	Serial.print("\r\n kiek reikės suktis == ");
	Serial.print(kiekMsReikesSuktis);

	// // #TESTING
	// if (kiekMsReikesSuktis != 0)
	// {
	// 	digitalWrite(LEDas, HIGH);
	// }
	// else
	// {
	// 	digitalWrite(LEDas, LOW);
	// }

	// if (abs(oponentoPozicija) < didinimoSkaicius)
	if (oponentoPozicija == 0) // priekis
	{
		//nenaudos while ciklo, tad `loop`as vyks nesustodamas, kol oponentoPozicija pasikeis iš 0
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
	}
	else if (oponentoPozicija < 0) // kairė
	{
		motoraiSuLaiku(-greitisSukimosi, greitisSukimosi, kiekMsReikesSuktis); // naudos while ciklą
	}
	else if (oponentoPozicija > 0) // dešinė
	{
		motoraiSuLaiku(greitisSukimosi, -greitisSukimosi, kiekMsReikesSuktis); // naudos while ciklą
	}
}
