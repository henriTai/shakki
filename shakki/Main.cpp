#pragma once
#include "Kayttoliittyma.h"
#include "Asema.h"
#include "Siirto.h"
#include <iostream>

bool onkoSallittuSiirto(std::list<Siirto> siirrot, Siirto* siirto);

int main() {
	Asema asema;
	Kayttoliittyma* k = new Kayttoliittyma(&asema);
	k->piirraLauta();
	std::list<Siirto>siirrot;
	//asema.annaLaillisetSiirrot(siirrot);
	while (true) {
		siirrot.erase(siirrot.begin(), siirrot.end());
		asema.annaLaillisetSiirrot(siirrot);
		Siirto* siirto = new Siirto(k->annaVastustajanSiirto());
		if (onkoSallittuSiirto(siirrot, siirto)) {
			asema.paivitaAsema(siirto);
			k->piirraLauta();
		}
	}



	while (true)
	{

	}
	return 0;
}

bool onkoSallittuSiirto(std::list<Siirto> siirrot, Siirto* siirto) {

	bool sallittu = false;
	while (!siirrot.empty()) {
		Siirto s = *siirrot.begin();
		if ( s == *siirto) {
			sallittu = true;
			break;
		}
		else {
			siirrot.pop_front();
		}
	}
	return sallittu;
}