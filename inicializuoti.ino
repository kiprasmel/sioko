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

	paruostiGeneralConfiga();
}

void sukurtiBendraPinuMasyva() {
	int bendrasIndex = 0;

	/** perkopijuojam: */

	/** dešinę */
	for (int i = 0; i < ziurintysIDesinePinaiDydis; i++) {
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][0] = ziurintysIDesineSensoriai[i][0];
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][1] = ziurintysIDesineSensoriai[i][1];

		visiPinai[bendrasIndex] = ziurintysIDesineSensoriai[i][0];

		bendrasIndex++;
	}

	/** vidurį */
	for (int i = 0; i < ziurintysIViduriPinaiDydis; i++) {
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][0] = ziurintysIViduriSensoriai[i][0];
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][1] = ziurintysIViduriSensoriai[i][1];

		visiPinai[bendrasIndex] = ziurintysIViduriSensoriai[i][0];

		bendrasIndex++;
	}

	/** kairę */
	for (int i = 0; i < ziurintysIKairePinaiDydis; i++) {
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][0] = ziurintysIKaireSensoriai[i][0];
		pinaiIrJuPasisukimoLaipsniaiKaireMinusaiDesinePliusai[bendrasIndex][1] = ziurintysIKaireSensoriai[i][1];

		visiPinai[bendrasIndex] = ziurintysIKaireSensoriai[i][0];

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

	suteiktiPinModeMasyvui(outputPins, gautiMasyvoDydi(outputPins), OUTPUT);

	const int randomInputPins[] = {START_MODULE, Rightback, Leftback};

	suteiktiPinModeMasyvui(randomInputPins, gautiMasyvoDydi(randomInputPins), INPUT);

	suteiktiPinModeMasyvui(ziurintysIKairePinai, ziurintysIKairePinaiDydis, INPUT);
	suteiktiPinModeMasyvui(ziurintysIViduriPinai, ziurintysIViduriPinaiDydis, INPUT);
	suteiktiPinModeMasyvui(ziurintysIDesinePinai,  ziurintysIDesinePinaiDydis, INPUT);

	suteiktiPinModeMasyvui(linijuSensoriai,  gautiMasyvoDydi(linijuSensoriai), INPUT);
}

void suteiktiPinModeMasyvui(const int pinuMasyvas[], int masyvoDydis, int pinModas) {
	for (int i = 0; i < masyvoDydis; i++) {
		const int pin = pinuMasyvas[i];
		pinMode(pin, pinModas);
	}
}

void paruostiGeneralConfiga() {
	/**
	 * CONFIG
	 * Nustato variklių dažnį.
	 * Jeigu šitų nėra, tai varikliai nevažiuoja.
	 *
	 * ką daro `analogWriteFrequency`?
	 *
	 * Man neveikia per `vscode`, meta errorus -
	 * tikriausiai trūksta kažkokios bibliotekos.
	 *
	 * `Upload`inant su arduino IDE veikia.
	*/
	analogWriteFrequency(PWM2, 15000.0f); /** #BROKEN #CHECK */
	analogWriteFrequency(PWM1, 15000.0f);

	/** enable receiving I suppose?:D */
	irrecv.enableIRIn();
	// irrecv.blink13(true); /** signalizuotų, kai gaunam signalą */

	/**
	 * CONFIG
	 * įjungti/išjungti strategijų nustatymą pulteliu
	 */
	// pulteliuNustatytiStrategijas();

	MAIN_STRATEGY_STATE = 1;
	START_STRATEGY_STATE = 1;

	/**
	 * CONFIG
	 * #TEMP #DEV - nevykdom pradinės strategijos (įjungti production'ui!)
	 */
	// vykdytiStrategija(pradineStrategija);
}
