#include "vairuotiRobota.h"
#include "kurYraOponentas.h"
#include "motoras.h"

double oponentoPozicija;
unsigned long kiekMsReikesSuktis;

void vairuotiRobota()
{
	oponentoPozicija = kurYraOponentas(); // nuo -1 iki +1
	kiekMsReikesSuktis = abs(perKiekMsApsisukam360_TODO * (int)oponentoPozicija);

	// if (abs(oponentoPozicija) < didinimoSkaicius)
	if (oponentoPozicija == 0) // priekis
	{
		//nenaudos while ciklo, tad `loop`as vyks nesustodamas, kol oponentoPozicija pasikeis iš 0
		motor(255, 255);
	}
	else if (oponentoPozicija < 0) // kairė
	{
		motoraiSuLaiku(-255, 255, kiekMsReikesSuktis); // naudos while ciklą
	}
	else if (oponentoPozicija > 0) // dešinė
	{
		motoraiSuLaiku(255, -255, kiekMsReikesSuktis); // naudos while ciklą
	}
}
