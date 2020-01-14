#include <vector>
#include <string>
// #include <functional>

#include "Arduino.h"
#include "xstate.h"

#include "arSensoriaiJunginejasi.h"
#include "config.h"
#include "pagalbines_funkcijos.h"

xs::StateMachine sukurtiPinoMasina(std::string id) {
	// xs::StateMachine masina = {
	// 	.id = id,
	// 	.state = { .value = "nemato" },
	// 	.states = {
	// 		{"nemato", { .on = { {"MATO", "mato"} } }},
	// 		{"mato", { .on = { {"NEMATO", "vel_nemato"} } }},
	// 		{"vel_nemato", { .on = {} } },
	// 	}
	// };

	struct xs::StateMachine masina = {
		id: id,
		state: { value: "nemato" },
		on: {},
		states: {
			{"nemato", { id: "", state: { value: "" }, on: { {"MATO",   "mato"} },       states: {} }},
			{"mato",   { id: "", state: { value: "" }, on: { {"NEMATO", "vel_nemato"} }, states: {} }},
			{"vel_nemato", { id: "", state: { value: "" }, on: { },                          states: {} }},
			// {"mato", { on: { {"NEMATO", "vel_nemato"} } }},
			// {"vel_nemato", { on: {} } },
		}
	};

	return masina;
}

std::vector<Dezute*> Dezute::sukurtiDezutesIsPinu(int pinai[], const int &pinuMasyvoDydis) {
// std::vector<Dezute*> Dezute::sukurtiDezutesIsPinu(int pinai[], const int &pinuMasyvoDydis, std::function<bool(int pinas)> arMatoTikrinimoFunkcija) {
	std::vector<Dezute*> dezutes(pinuMasyvoDydis);

	for (int i = 0; i < pinuMasyvoDydis; ++i) {
		const int &pinas = pinai[i];

		xs::StateMachine masina = sukurtiPinoMasina("pinas" + pinas);
		// Serial.print("\nSukurti pino masina");

		xs::Interpreter interpreteris = xs::interpret(masina)
			/** TODO šitų nebeturėtų reikėt */
			// .onStart([]() {})
			// .onTransition([]() {})
			// .onStop([]() {})
		;

		// Serial.print("\ninterpret");

		interpreteris.start();
		// Serial.print("\nstart");

		Dezute* paruostaDezute = new Dezute({
			.pinas = pinas,
			.arBaige = false,
			.interpreteris = interpreteris
			// ,
			// .arMatoTikrinimoFunkcija = arMatoTikrinimoFunkcija
		});

		dezutes[i] = paruostaDezute;
		// Serial.flush();
	}

	return dezutes;
}

void arSensoriaiJunginejasi() {
	Serial.print("\narSensoriaiJunginejasi:\n");
	ledasOFF();

	// std::vector<Dezute*> dezutes = Dezute::sukurtiDezutesIsPinu(visiPinai, visiPinaiDydis);
	std::vector<Dezute*> dezutes = Dezute::sukurtiDezutesIsPinu(linijuSensoriai, linijuSensoriaiDydis);

	// std::vector<Dezute*> dezutes = Dezute::sukurtiDezutesIsPinu(visiPinai, visiPinaiDydis, [](int pinas) { return arMato(pinas); });
	// std::vector<Dezute*> linijuDezutes = Dezute::sukurtiDezutesIsPinu(linijuSensoriai, linijuSensoriaiDydis, [](int pinas) { return arMatoLinija(pinas); });

	// dezutes.insert(dezutes.end(), linijuDezutes.begin(), linijuDezutes.end());

	size_t kiekBaige = 0;

	while (kiekBaige < dezutes.size()) {
		// Serial.print("\nwhile");
		for (Dezute *dezute : dezutes) {
			// Serial.print("\nfor");
			/** atnaujinam state'ą / būseną */

			// bool arPinasMato = dezute->arMatoTikrinimoFunkcija(dezute->pinas);
			bool arPinasMato = arMatoLinija(dezute->pinas);

			// Serial.print("\narPinasMato = ");
			// Serial.print(arPinasMato);

			std::string eventas = arPinasMato ? "MATO" : "NEMATO";
			// Serial.print("\neventas = ");
			// Serial.print(eventas.c_str());

			dezute->interpreteris.send(eventas);
			// Serial.print("\nsend");
			Serial.print("\n");
			Serial.print(dezute->interpreteris.stateMachine.state.value.c_str());
			Serial.print(" ");
			Serial.print(kiekBaige);

			if (dezute->interpreteris.stateMachine.state.value != "vel_nemato") {
				/** dar nebaigė */
				continue;
			}

			/** baigė, tik nežinia, kelintą kartą */
			if (dezute->arBaige == true) {
				/** jau atnaujinom `kiekBaige` */
				continue;
			}

			/** baigė pirmą kartą! */
			dezute->arBaige = true;
			++kiekBaige;

			Serial.print("\nBaige dar vienas pinas - ");
			Serial.print(dezute->pinas);
			Serial.print(" ; kiekBaige = ");
			Serial.print(kiekBaige);
			Serial.flush();
		}
		Serial.flush();
	}

	Serial.print("\ndone arSensoriaiJunginejasi\n");
	ledasON();

	while (1) {};
}
