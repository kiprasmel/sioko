#pragma once

// typedef enum : long unsigned int
// {
// 	stratPirmaNEC1 = 0xFF906F,									// TODO - reikia užvadinti
// 	stratAntraNEC2 = 0xFFB847,									//
// 	stratTreciaNEC3 = 0xFFF807,									//
// 	stratZigzagasDesinenMazasNEC4 = 0xFF9867,		// stratZigzagasDesinenMazasNEC4
// 	stratZigzagasKairenMazasNEC5 = 0xFFD827,		// stratZigzagasKairenMazasNEC5
// 	stratZigzagasDesinenDidelisNEC6 = 0xFF8877, // stratZigzagasDesinenDidelisNEC6
// 	stratZigzagasKairenDidelisNEC7 = 0xFFE817,	// stratZigzagasKairenDidelisNEC7
// 	stratAstuntaNEC8 = 0xFF48B7,
// 	stratDevintaNEC9 = 0xFF9A65,
// 	stratPatvirtinimasNECEnter = 0xFFE01F // TODO anksčiau `enter`
// } StrategijosPagalHex;

enum StrategijosPagalHex : long unsigned int
{
	nezinoma = 0,
	stratPirmaNEC1 = 0xFF906F,									// TODO - reikia užvadinti
	stratAntraNEC2 = 0xFFB847,									//
	stratTreciaNEC3 = 0xFFF807,									//
	stratZigzagasDesinenMazasNEC4 = 0xFF9867,		// stratZigzagasDesinenMazasNEC4
	stratZigzagasKairenMazasNEC5 = 0xFFD827,		// stratZigzagasKairenMazasNEC5
	stratZigzagasDesinenDidelisNEC6 = 0xFF8877, // stratZigzagasDesinenDidelisNEC6
	stratZigzagasKairenDidelisNEC7 = 0xFFE817,	// stratZigzagasKairenDidelisNEC7
	// stratAstuntaNEC8 = 0xFF48B7,
	// stratDevintaNEC9 = 0xFF9A65,
	stratPatvirtinimasNECEnter = 0xFFE01F // TODO anksčiau `enter`
};

extern size_t laikas;
extern StrategijosPagalHex pradineStrategija;
extern StrategijosPagalHex pagrindineStrategija;

void vykdytiStrategija(StrategijosPagalHex strategijosKodas);

void pirmaStrategija();
void antraStrategija();
void treciaStrategija();
void zigzagasDesinenMazas();
void zigzagasKairenMazas();
void zigzagasDesinenDidelis();
void zigzagasKairenDidelis();

/** legacy */
void zigzag_kaire_M();
void zigzag_desine_M();
void zigzag_kaire_D();
void zigzag_desine_D();
