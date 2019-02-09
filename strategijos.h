#pragma once

typedef enum : long unsigned int
{
	stratPirma = 0xFF906F,									// TODO - reikia užvadinti
	stratAntra = 0xFFB847,									//
	stratTrecia = 0xFFF807,									//
	stratZigzagasDesinenMazas = 0xFF9867,		// stratZigzagasDesinenMazas
	stratZigzagasKairenMazas = 0xFFD827,		// stratZigzagasKairenMazas
	stratZigzagasDesinenDidelis = 0xFF8877, // stratZigzagasDesinenDidelis
	stratZigzagasKairenDidelis = 0xFFE817,	// stratZigzagasKairenDidelis
	stratAstunta = 0xFF48B7,
	stratDevinta = 0xFF9A65,
	stratPatvirtinimas = 0xFFE01F // TODO anksčiau `enter`
} StrategijosPagalHex;

unsigned int laikas;
StrategijosPagalHex pradineStrategija, pagrindineStrategija;

void vykdytiStrategija(StrategijosPagalHex strategijosKodas);
