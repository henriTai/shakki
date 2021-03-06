#pragma once
#include "Kayttoliittyma.h"
#include "Asema.h"
#include "Siirto.h"
#include <iostream>
#include <algorithm>



bool onkoSallittuSiirto(std::list<Siirto> siirrot, Siirto* siirto);
void kaytetaanAloitusKirjastoa(Asema &asema, Kayttoliittyma *k, int puoli);

int main() {
	Asema asema;
	Kayttoliittyma* k = new Kayttoliittyma(&asema);
	int puoli = k->valitsePuoli();
	int syvyys = k->valitseSyvyys();
	if (k->aloitusKirjasto()) {
		kaytetaanAloitusKirjastoa(asema, k, puoli);
	}
	k->piirraLauta();
	std::list<Siirto>siirrot;
	//asema.annaLaillisetSiirrot(siirrot);
	while (true) {
		siirrot.erase(siirrot.begin(), siirrot.end());
		asema.annaLaillisetSiirrot(siirrot);
		siirrot = asema.tarkistaSiirrot(siirrot);
		
		if (asema.onkoShakki()) {
			k->shakki();
		}
		if (siirrot.empty()) {
			if (asema.onkoShakki()) {
				k->matti();
			}
			else {
				k->patti();
			}

			break;
		}
		if (asema.getSiirtovuoro() != puoli) {
			Siirto siirto(k->annaVastustajanSiirto(asema.getSiirtovuoro()));
			if (onkoSallittuSiirto(siirrot, &siirto)) {
				asema.paivitaAsema(&siirto);
			}
		}
		else {

			Siirto siirto = asema.parasSiirto(syvyys);
			asema.paivitaAsema(&siirto);
			k->tulostaSiirto(siirto, asema.getSiirtovuoro());
		}
		k->piirraLauta();
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
void kaytetaanAloitusKirjastoa(Asema &asema, Kayttoliittyma *k, int puoli) {


}

