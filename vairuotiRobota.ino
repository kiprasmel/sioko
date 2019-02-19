#include "vairuotiRobota.h"
#include "kurYraOponentas.h"
#include "motoras.h"
#include "inicializuoti.h"
#include "pagalbines_funkcijos.h"
#include "linija.h"
#include <math.h>

void vairuotiRobota()
{
	double oponentoPozicija = 0;
	double kiekMsReikesSuktis = 0;

	if (digitalRead(START_MODULE) == LOW)
	{
		motor(0, 0);
		return;
	}

	atnaujintiJutikliuDuomenis();

	originaliLinijaBeDefaultCase();

	if (arVidurysKaNorsMato())
	{
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
		return;
	}

	oponentoPozicija = kurYraOponentas(); // nuo -1 iki +1

	/** 
	 * skaičiuojam numamant, jog didžiausias kampas, kokį mato sensorius,
	 * palyginus su roboto priekiu, yra 90 laipsnių (360 / 4)
	 * #TODO #CLEANUP
	* #sukimosiSkaiciavimas
	*/
	kiekMsReikesSuktis = fabs(perKiekMsApsisukam360Sukdamiesi255 / 4 * oponentoPozicija);
	// Serial.print(perKiekMsApsisukam360Sukdamiesi255);

	// Serial.print("\nKiek ms reikės suktis ");
	// Serial.print(kiekMsReikesSuktis);
	// Serial.print(" oponento pozicija ");
	// Serial.print(oponentoPozicija);

	Serial.print("\nOponento pozicija: ");
	Serial.print(oponentoPozicija);

	// // #TESTING
	// if (kiekMsReikesSuktis != 0)
	// {
	// 	digitalWrite(13, HIGH);
	// }
	// else
	// {
	// 	digitalWrite(13, LOW);
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
