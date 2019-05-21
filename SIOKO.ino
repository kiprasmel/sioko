/**
 * SIOKO.ino
 * 
 * Pagrindinis programos failas.
 * 
 * Copyright (c) 2019 Kipras Melnikovas, Vismantas Masiokas, Neilas Antanavičius
 * 
*/

/**
 * Kas yra etr? (Naudojamas pulteliuNustatytiStrategijas, galbūt geriau jį ten deklaruoti?) 
 * > Perkėliau į pulteliuNustatytiStrategijas failą
 * 
 * Iš kur gauti IRremote.h biblioteką? kurią čia naudojat?
 * 
 * 
 * Search'inimo keywords'ai: [TODO, CHECK, WARN, BROKEN]
 */

#include "inicializuoti.h"
#include "strategijos.h"
#include "IRremote/IRremote.h"
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

	analogWriteFrequency(PWM2, 15000.0f); /** #BROKEN #CHECK ką daro šitas? Neveikia man, meta errorus, gal neturiu bibliotekos kažkokios */
	analogWriteFrequency(PWM1, 15000.0f);

	// // motor(255, 255);

	irrecv.enableIRIn(); /** CHECK ką šitas daro? */

	/**
	 * #TEMP #DEV - išjungiam strategijų pultelį 
	 */
	// pulteliuNustatytiStrategijas();
	MAIN_STRATEGY_STATE = 1;
	START_STRATEGY_STATE = 1;

	lauktiKolPaleisimRobota();

	// vykdytiStrategija(pradineStrategija);

	// pirmaStrategija();
	// hardCodedVarikliuTestai();
}

void loop()
{
	// vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai();
	vairuotiRobotaSuApskaiciavimais();
}
