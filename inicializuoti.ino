/*
 * inicializuoti.ino
 *
 * inicializavimo failas
 *
 * Naudojamas pagrindiniame projekto faile (sioko.ino)
 * ir suteikia globalius kintamuosius visiems failams.
 *
 * Copyright (c) 2019 Kipras Melnikovas
 *
*/

#include "inicializuoti.h"
#include <assert.h>

void inicializuoti() {
	sukurtiBendraPinuMasyva();

	suteiktiPinModusViskam();
}

void sukurtiBendraPinuMasyva() {
	int bendrasIndex = 0;

	/** perkopijuojam: */

	/** dešinę */
	for (int i = 0; i < ziurintysIDesinePinaiDydis; i++) {
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][0] = ziurintysIDesineSensoriai[i][0];
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][1] = ziurintysIDesineSensoriai[i][1];

		bendrasIndex++;
	}

	/** vidurį */
	for (int i = 0; i < ziurintysIViduriPinaiDydis; i++) {
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][0] = ziurintysIViduriSensoriai[i][0];
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][1] = ziurintysIViduriSensoriai[i][1];

		bendrasIndex++;
}

	/** kairę */
	for (int i = 0; i < ziurintysIKairePinaiDydis; i++) {
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][0] = ziurintysIKaireSensoriai[i][0];
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][1] = ziurintysIKaireSensoriai[i][1];

		bendrasIndex++;
	}
}


void suteiktiPinModusViskam() {
	const int outputPins[] = {
			LEDas,
			PWM1,
			PWM2,
			DIR1,
			DIR2,
	};

	const int outputPinsDydis = sizeof(outputPins) / sizeof(outputPins[0]);

	suteiktiPinModeMasyvui(outputPins, outputPinsDydis, OUTPUT);

	const int inputPins[] = {START_MODULE, Rightback, Leftback};

	const int inputPinsDydis = sizeof(inputPins) / sizeof(inputPins[0]);

	suteiktiPinModeMasyvui(inputPins, inputPinsDydis, INPUT);

	suteiktiPinModeMasyvui(ziurintysIKairePinai, ziurintysIKairePinaiDydis, INPUT);
	suteiktiPinModeMasyvui(ziurintysIViduriPinai, ziurintysIViduriPinaiDydis, INPUT);
	suteiktiPinModeMasyvui(ziurintysIDesinePinai,  ziurintysIDesinePinaiDydis, INPUT);
}
