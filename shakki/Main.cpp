#pragma once
#include "Kayttoliittyma.h"
#include "Asema.h"
#include "Siirto.h"
#include <iostream>

bool onkoSallittuSiirto(std::list<Siirto> siirrot, Siirto* siirto);
list<Siirto> tarkistaSiirrot(std::list<Siirto>& siirrot, Asema as);
bool onkoMatti(Asema as);
Ruutu* kuninkaanSijainti(Asema as);

int main() {
	Asema asema;
	Kayttoliittyma* k = new Kayttoliittyma(&asema);
	k->piirraLauta();
	std::list<Siirto>siirrot;
	//asema.annaLaillisetSiirrot(siirrot);
	while (true) {
		siirrot.erase(siirrot.begin(), siirrot.end());
		asema.annaLaillisetSiirrot(siirrot);
		if (onkoMatti(asema)) {
			k->Matti();
		}
		siirrot = tarkistaSiirrot(siirrot, asema);
		if (siirrot.empty()) {
			k->Shakki();
			break;
		}
		
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

list<Siirto> tarkistaSiirrot(std::list<Siirto>& siirrot, Asema as)
{
	Ruutu *ruut = kuninkaanSijainti(as);
	list<Siirto> tarkastetut;
	while (!siirrot.empty()) {
		Ruutu r = *ruut;
		list<Siirto> uudet;
		Asema a = as;
		Siirto s = *siirrot.begin();
		if (s.getAlkuruutu().getRivi() == r.getRivi() && s.getAlkuruutu().getSarake() == r.getSarake()) {
			r = s.getLoppuruutu();
		}
		a.paivitaAsema(&s);
		a.annaLaillisetSiirrot(uudet);
		bool ok = true;
		for (std::list<Siirto>::const_iterator it = uudet.begin(), end = uudet.end();it != end;++it) {
			Siirto si = *it;
			if (si.getLoppuruutu().getRivi() == r.getRivi() && si.getLoppuruutu().getSarake() == r.getSarake()) {
				ok = false;
				break;
			}
		}
		if (ok) {

			tarkastetut.push_back(s);
		}
		siirrot.pop_front();

	}
	return tarkastetut;

}

bool onkoMatti(Asema as) {
	Ruutu* kunkku = kuninkaanSijainti(as);
	if (as.getSiirtovuoro() == 0) {
		as.setSiirtovuoro(1);
	}
	else {
		as.setSiirtovuoro(0);
	}

	std::list<Siirto> siirrot;
	as.annaLaillisetSiirrot(siirrot);
	
	for (std::list<Siirto>::const_iterator it = siirrot.begin(), end = siirrot.end();it != end;++it) {
		Siirto si = *it;
		if (si.getLoppuruutu().getRivi() == kunkku->getRivi() && si.getLoppuruutu().getSarake() == kunkku->getSarake()) {

			return true;
		}
	}

	return false;
}

Ruutu* kuninkaanSijainti(Asema as) {
	int vari = as.getSiirtovuoro();
	Ruutu *ruut = NULL;
	for (int sa = 0;sa < 8;sa++) {
		for (int ri = 0;ri < 8;ri++) {
			if (as.lauta[sa][ri] != NULL) {
				if ((vari == 0 && as.lauta[sa][ri]->getKoodi() == VK) || (vari == 1 && as.lauta[sa][ri]->getKoodi() == MK)) {
					ruut = new Ruutu(ri, sa);
					break;
				}
			}
		}
	}
	if (ruut == NULL) {
		ruut = new Ruutu(0, 0);
	}
	return ruut;
}
