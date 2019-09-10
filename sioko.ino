/**
 * SIOKO.ino
 *
 * Pagrindinis programos failas.
 * Search'inimo keywords'ai: [TODO, CHECK, WARN, BROKEN, DEV]
 *
 * Copyright (c) 2019 Kipras Melnikovas, Vismantas Masiokas, Neilas Antanavičius
 *
*/

#include "inicializuoti.h"
#include "strategijos.h"
#include "irremote_pultelis.h"
#include "pagalbines_funkcijos.h"
#include "vairuotiRobota.h"
#include "ivairusTestai.h"
#include "strategijos.h"

void setup()
{
	Serial.begin(115200);

	inicializuoti();

	const byte outputPins[] = {
			LEDas,
			PWM1,
			PWM2,
			DIR1,
			DIR2,
	};

	const byte inputPins[] = {LeftLine1, LeftLine2, RightLine1, RightLine2, Right1, Right2, Right3, Rightback,
														Left1, Left2, Left3, Leftback, Middle1, Middle2, Middle3, START_MODULE};

	for (const byte &pin : outputPins)
	{
		pinMode(pin, OUTPUT);
	}

	for (const byte &pin : inputPins)
	{
		pinMode(pin, INPUT);
	}

	/**
	 * ką daro `analogWriteFrequency`?
	 *
	 * Man neveikia per `vscode`, meta errorus -
	 * tikriausiai trūksta kažkokios bibliotekos.
	 *
	 * `Upload`inant su arduino IDE veikia.
	*/
	// analogWriteFrequency(PWM2, 15000.0f); /** #BROKEN #CHECK */
	// analogWriteFrequency(PWM1, 15000.0f);

	/** enable receiving I suppose?:D */
	irrecv.enableIRIn();
	// irrecv.blink13(true); /** signalizuotų, kai gaunam signalą */

	/**
	 * #TEMP #DEV - išjungiam strategijų pultelį  (įjungti production'ui!)
	 */
	// pulteliuNustatytiStrategijas();
	MAIN_STRATEGY_STATE = 1;
	START_STRATEGY_STATE = 1;

	lauktiKolPaleisimRobota();

	/**
	 * #TEMP #DEV - nevykdom pradinės strategijos (įjungti production'ui!)
	 */
	// vykdytiStrategija(pradineStrategija);
}

void loop()
{
	// vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai();
	vairuotiRobotaSuApskaiciavimais();
}
