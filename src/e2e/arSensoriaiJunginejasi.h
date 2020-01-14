#pragma once

#include <vector>
// #include "functional"

#include "xstate.h"

xs::StateMachine sukurtiPinoMasina(std::string id);

struct Dezute {
	int pinas;
	bool arBaige;
	xs::Interpreter interpreteris;
	// std::function<bool(int pinas)> arMatoTikrinimoFunkcija = [](int pinas) -> bool {};

	static std::vector<Dezute*> sukurtiDezutesIsPinu(int pinai[], const int &pinuMasyvoDydis);
	// static std::vector<Dezute*> Dezute::sukurtiDezutesIsPinu(int pinai[], const int &pinuMasyvoDydis, std::function<bool(int pinas)> arMatoTikrinimoFunkcija);

	~Dezute() {
	}
};

void arSensoriaiJunginejasi();
