#pragma once

#include <vector>

#include "xstate.h"

xs::StateMachine sukurtiPinoMasina(std::string id);

struct Dezute {
	int pinas;
	bool arBaige;
	xs::Interpreter *interpreteris;

	static std::vector<Dezute> sukurtiDezutesIsPinu(int pinai[], const int &pinuMasyvoDydis);

	~Dezute() {
		delete this->interpreteris;
	}
};

void arSensoriaiJunginejasi();
