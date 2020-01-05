#include <vector>
#include <string>

#include "Arduino.h"
#include "xstate.h"

#include "arSensoriaiJunginejasi.h"
#include "config.h"
#include "pagalbines_funkcijos.h"

xs::StateMachine sukurtiPinoMasina(std::string id) {
	xs::StateMachine masina = {
		.id = id,
		.initial =  "nemato",
		.states = {
			{"nemato", { .on = { {"MATO", "mato"} } }},
			{"mato", { .on = { {"NEMATO", "vel_nemato"} } }},
			{"vel_nemato", { .on = {} } },
		}
	};

	return masina;
}

std::vector<Dezute> Dezute::sukurtiDezutesIsPinu(int pinai[], const int &pinuMasyvoDydis) {
	std::vector<Dezute> dezutes(pinuMasyvoDydis);

	for (int i = 0; i < pinuMasyvoDydis; ++i) {
		const int &pinas = pinai[i];

		xs::StateMachine masina = sukurtiPinoMasina("pinas" + pinas);
		xs::Interpreter *interpreteris = xs::interpret(masina);

		Dezute paruostaDezute = {
			.pinas = pinas,
			.arBaige = false,
			interpreteris = interpreteris
		};

		dezutes[i] = paruostaDezute;
	}

	return dezutes;
}

void arSensoriaiJunginejasi() {
	Serial.print("\narSensoriaiJunginejasi:\n");

	std::vector<Dezute> dezutes = Dezute::sukurtiDezutesIsPinu(visiPinai, visiPinaiDydis);

	size_t kiekBaige = 0;

	while (kiekBaige < dezutes.size()) {
		for (Dezute &dezute : dezutes) {
			/** atnaujinam state'ą / būseną */
			dezute.interpreteris->send(arMato(dezute.pinas) ? "MATO" : "NEMATO");

			if (dezute.interpreteris->state->value != "vel_nebemato") {
				/** dar nebaigė */
				continue;
			}

			/** baigė, tik nežinia, kelintą kartą */
			if (dezute.arBaige == true) {
				/** jau atnaujinom `kiekBaige` */
				continue;
			}

			/** baigė pirmą kartą! */
			dezute.arBaige = true;
			++kiekBaige;

			Serial.print("\nBaige dar vienas pinas - ");
			Serial.print(dezute.pinas);
			Serial.print(" ; kiekBaige = ");
			Serial.print(kiekBaige);
		}
	}
}
