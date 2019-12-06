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
	Serial.begin(115200);

	inicializuoti();
}

void loop()
{
	// vairuotiRobotaBeSkaiciavimuIrUzlaikymuPrimityviai();
	vairuotiRobotaSuApskaiciavimais();
}
