/**
 * SIOKO.ino
 *
 * Pagrindinis programos failas.
 * Search'inimo keywords'ai: [TODO, CHECK, WARN, BROKEN, DEV]
 *
 * Copyright (c) 2019 Kipras Melnikovas, Vismantas Masiokas, Neilas Antanavičius
 *
*/

#include <Arduino.h>
#include "inicializuoti.h"
#include "strategijos.h"
#include "irremote_pultelis.h"
#include "pagalbines_funkcijos.h"
#include "vairuotiRobota.h"
#include "ivairusTestai.h"
#include "strategijos.h"

void setup()
{
	Serial.begin(9600);

	/**
	 * TEST ONLY - laukti, kol įsijungs serial'as (TEST ONLY)
	 * see https://www.arduino.cc/reference/en/language/functions/communication/serial/ifserial/
	*/
	// while (!Serial) { /** wait */ }

	inicializuoti();
}

void loop()
{
	// Serial.println();

	// vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai();

	/**
	 * TEST ONLY - laukti, kol visi duomenys iš serial'o bus išsiųsti, ir tik tada tęsti.
	 *
	 * https://www.arduino.cc/reference/en/language/functions/communication/serial/flush/
	 */
	// Serial.flush();
}
