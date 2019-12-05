/**
 * Susivedam jutiklių duomenis ir apsisaugom nuo linijos kirtimo, o
 * tada vairuojam robotą :D
 *
 * #TODO Taip pat reikia pertvarkyti `Line` funkciją - linijos tikrinimą ir atsitraukimą.
 * (gali būt, kad neišvengsim while / delay)
*/

#include <Arduino.h>
#include "vairuotiRobota.h"
#include "kurYraOponentas.h"
#include "motoras.h"
#include "inicializuoti.h"
#include "pagalbines_funkcijos.h"
#include "linija.h"
#include <math.h>

// for testing:
// #include "ivairusTestai.h"

void pirmynSuDelay() {
	motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
	// digitalWrite(LEDas, HIGH);

	delay(50);

	// digitalWrite(LEDas, LOW);
	return;
}

void vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai()
{
	atnaujintiJutikliuDuomenis(); // #TODO #CHECK galima mėginti atkomentuot senąjį pin'ų surašymą

	originaliLinijaBeDefaultCase();

	if (arVidurysKaNorsMato())
	{
		// motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn); // +max forward; +max forward
		pirmynSuDelay();
		return;
	}

	else if (arKaireKaNorsMato() || arDesineKaNorsMato())
	{

		/** dafuq? Abu šonai mato:D Tiesiog varom pirmyn */
		if (arKaireKaNorsMato() && arDesineKaNorsMato())
		{
			// motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn); // +max forward; +max forward
			pirmynSuDelay();
			return;
		}

		else if (arKaireKaNorsMato())
		{
			// motor(-greitisSukimosi, +greitisSukimosi); // -max rotate; +max rotate
			motoraiKolPriekisPamato(-greitisSukimosi, +greitisSukimosi);
			return;
		}
		else if (arDesineKaNorsMato())
		{
			// motor(+greitisSukimosi, -greitisSukimosi); // -max rotate; +max rotate
			motoraiKolPriekisPamato(+greitisSukimosi, -greitisSukimosi); // -max rotate; +max rotate
			return;
		}
	}

	// nemato niekas
	else
	{
		// motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
		pirmynSuDelay();
		// Serial.print("Niekas");
		return;
	}
}

void vairuotiRobotaSuApskaiciavimais()
{
	atnaujintiJutikliuDuomenis();

	originaliLinijaBeDefaultCase();

	/**
	 * #EXPERIMENTAL
	 * Išjungiam, kad visas flow būtų toks pat bet kokiu atveju,
	 * turint omeny, jeigu norėtume daryti ką nors skirtingo,
	 * nepriklausomai nuo to, ar vidurys mato.
	 */
	bool arRodytLEDa = true; /** testing */

	// if (arVidurysKaNorsMato()) {
	// 	motor(0, 0);
	// 	while (true) {}
	// }

	if (siunciamPirmynJeiguPriekisMato(arRodytLEDa)) {
		/**
		 * jeigu siunčiam pirmyn, nes priekis mato,
		 * tai nutraukiam tolesnius skaičiavimus
		 */
		return;
	}

	// siunciamIrUzlokinamPirmynKolPriekisMato(arRodytLEDa);

	/** BEGIN calculations */

	double oponentoPozicija = kurYraOponentas(); // nuo -1 iki +1

	/**
	 * nuo `0` iki `tolimiausioPinoLaipsnis` laipsnių
	 *
	 * skaičiuojam numamant, jog didžiausias kampas, kokį mato sensorius,
	 * #sukimosiSkaiciavimas
	*/
	double kiekMsReikesSuktisNotAbs = (double) perKiekMsApsisukam90Sukdamiesi255 * oponentoPozicija;
	double kiekMsReikesSuktisFabs = fabs(kiekMsReikesSuktisNotAbs);
	unsigned long kiekMsReikesSuktis = (unsigned long) kiekMsReikesSuktisFabs;

	// Serial.print("\nOponento pozicija ");
	// Serial.print(oponentoPozicija);
	// Serial.print("\nkiek reikės suktis == ");
	// Serial.print(kiekMsReikesSuktis);

	// // #TESTING
	// if (oponentoPozicija != 0)
	// {
	// 	digitalWrite(LEDas, HIGH);
	// 	delay(10);
	// }
	// else
	// {
	// 	digitalWrite(LEDas, LOW);
	// }

	if (oponentoPozicija == 0) // priekis
	{
		/** nenaudos while ciklo, tad `loop`as vyks nesustodamas, kol oponentoPozicija pasikeis iš 0 */
		motor(greitisVaziavimoPirmyn, greitisVaziavimoPirmyn);
	}
	else if (oponentoPozicija < 0) // kairė
	{
		motoraiSuLaiku(-greitisSukimosi, +greitisSukimosi, kiekMsReikesSuktis); // naudos while ciklą
		// while (true) {
		// 	digitalWrite(LEDas, HIGH);
		// 	delay(50);

		// 	digitalWrite(LEDas, LOW);
		// 	delay(50);
		// };
	}
	else if (oponentoPozicija > 0) // dešinė
	{
		motoraiSuLaiku(+greitisSukimosi, -greitisSukimosi, kiekMsReikesSuktis); // naudos while ciklą
		// while (true) {
		// 	digitalWrite(LEDas, HIGH);
		// 	delay(50);

		// 	digitalWrite(LEDas, LOW);
		// 	delay(50);
		// };
	}

	return;
}
