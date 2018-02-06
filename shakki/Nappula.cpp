#pragma once
#include "Nappula.h"
#include "Asema.h"

using namespace std;



Nappula::Nappula(wstring asema, int v, int k) {
	unicode = asema;
	vari = v;
	_koodi = k;

}


void Nappula::setKoodi(int koodi) {
	_koodi = koodi;
}

int Nappula::getKoodi() {
	return _koodi;
}

void Nappula::setUnicode(wstring asema) {
	unicode = asema;

}

std::wstring Nappula::getUnicode()
{
	return unicode;
}



void Nappula::setVari(int v) {
	vari = v;
}

int Nappula::getVari() {
	return vari;
}

void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	int sar = r->getSarake();
	int rivi = r->getRivi();

	if (vari == 0 && a->lauta[sar][rivi]->getVari()==0) {	//valkoinen, väri=0
		//liikkuminen suoraan, eli vapaisiin ruutuihin
		if (rivi == 1) {	//alkuasemissa
			if (a->lauta[sar][2] == NULL) {
				Ruutu alku(1, sar);
				Ruutu loppu(2, sar);
				Siirto s(alku, loppu);
				lista.push_back(s);
				if (a->lauta[sar][3] == NULL) {
					Ruutu loppu2(3, sar);
					Siirto s2(alku, loppu2);
					lista.push_back(s2);
				}
			}
		}
		else {	//liikkunut
			if (rivi < 7) {
				if (a->lauta[sar][rivi + 1] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		//syöminen
		if (onLaudalla(sar - 1, rivi + 1)) {
			if (a->lauta[sar - 1][rivi + 1] != NULL) {
				Nappula* toinen = a->lauta[sar - 1][rivi + 1];
				if ( toinen->getVari() == 1) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi + 1)) {
			if (a->lauta[sar + 1][rivi + 1] != NULL) {
				Nappula* toinen = a->lauta[sar + 1][rivi + 1];
				if (toinen->getVari() == 1) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi+1, sar+1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}

	}
	else if (vari==1&& a->lauta[sar][rivi]->getVari()==1)
	{ //musta, väri=1
		   //liikkuminen suoraan, eli vapaisiin ruutuihin
		if (rivi == 6) {	//alkuasemissa
			if (a->lauta[sar][5] == NULL) {
				Ruutu alku(6, sar);
				Ruutu loppu(5, sar);
				Siirto s(alku, loppu);
				lista.push_back(s);
				if (a->lauta[sar][4] == NULL) {
					Ruutu loppu2(4, sar);
					Siirto s2(alku, loppu2);
					lista.push_back(s2);
				}
			}
		}
		else {	//liikkunut
			if (rivi > 0) {
				if (a->lauta[sar][rivi - 1] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		//syöminen
		if (onLaudalla(sar - 1, rivi - 1)) {
			if (a->lauta[sar - 1][rivi - 1] != NULL) {
				Nappula* toinen = a->lauta[sar - 1][rivi - 1];
				if (toinen->getVari() == 0) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi - 1)) {
			if (a->lauta[sar + 1][rivi - 1] != NULL) {
				Nappula* toinen = a->lauta[sar + 1][rivi - 1];
				if (toinen->getVari() == 0) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
	}
	//ohestalyönti puuttuu
}

void Sotilas::lisaaSotilaanKorotukset(Siirto * s, std::list<Siirto>& lista, Asema * a)
{
	//ei ole vielä
}

void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	int sar = r->getSarake();
	int rivi = r->getRivi();

	if (a->lauta[sar][rivi]->getVari() == vari) {

		if (onLaudalla(sar - 1, rivi)) {
			if (a->lauta[sar - 1][rivi] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi, sar - 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 1][rivi];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi)) {
			if (a->lauta[sar + 1][rivi] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi, sar + 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 1][rivi];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar, rivi - 1)) {
			if (a->lauta[sar][rivi - 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 1, sar);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar][rivi - 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar, rivi + 1)) {
			if (a->lauta[sar][rivi + 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 1, sar);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar][rivi + 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar - 1, rivi - 1)) {
			if (a->lauta[sar -1 ][rivi - 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 1, sar - 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 1][rivi - 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar - 1, rivi + 1)) {
			if (a->lauta[sar - 1][rivi + 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 1, sar + 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 1][rivi + 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi - 1)) {
			if (a->lauta[sar + 1][rivi - 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 1, sar - 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 1][rivi - 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi + 1)) {
			if (a->lauta[sar + 1][rivi + 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 1, sar + 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 1][rivi + 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (vari == 0 && a->getOnkoValkeaKuningasLiikkunut() == false && a->getOnkoValkeaDTliikkunut() == false) {
			//valkean pitkä torni
			if (a->lauta[1][0] == NULL && a->lauta[2][0] == NULL && a->lauta[3][0] == NULL) {
				Siirto s(false, true);
				lista.push_back(s);
			}
		}
		if (vari == 0 && a->getOnkoValkeaKuningasLiikkunut() == false && a->getOnkoValkeaKTliikkunut() == false) {
			//valkea lyhyt torni
			if (a->lauta[5][0] == NULL && a->lauta[6][0] == NULL) {
				Siirto s(true, false);
				lista.push_back(s);
			}
		}
		if (vari == 1 && a->getOnkoMustaKuningasLiikkunut() == false && a->getOnkoMustaDTliikkunut() == false) {
			//musta pitkä torni
			if (a->lauta[1][7] == NULL && a->lauta[2][7] == NULL && a->lauta[3][7] == NULL) {
				Siirto s(false, true);
				lista.push_back(s);
			}
		}
		if (vari == 1 && a->getOnkoMustaKuningasLiikkunut() == false && a->getOnkoMustaKTliikkunut() == false) {
			//musta lyhyt torni
			if (a->lauta[5][7] == NULL && a->lauta[6][7] == NULL) {
				Siirto s(true, false);
				lista.push_back(s);
			}
		}
	}
}

void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	int sar = r->getSarake();
	int rivi = r->getRivi();

	if (a->lauta[sar][rivi]->getVari() == vari) {

		if (onLaudalla(sar - 2, rivi - 1)) {
			if (a->lauta[sar - 2][rivi - 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 1, sar - 2);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 2][rivi - 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar - 2);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar - 2, rivi + 1)) {
			if (a->lauta[sar - 2][rivi + 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 1, sar - 2);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 2][rivi + 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar - 2);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar - 1, rivi - 2)) {
			if (a->lauta[sar - 1][rivi - 2] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 2, sar - 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 1][rivi - 2];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 2, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar - 1, rivi + 2)) {
			if (a->lauta[sar - 1][rivi + 2] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 2, sar - 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 1][rivi + 2];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 2, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi - 2)) {
			if (a->lauta[sar + 1][rivi - 2] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 2, sar + 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 1][rivi - 2];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 2, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi + 2)) {
			if (a->lauta[sar + 1][rivi + 2] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 2, sar + 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 1][rivi + 2];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 2, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 2, rivi - 1)) {
			if (a->lauta[sar + 2][rivi - 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 1, sar + 2);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 2][rivi - 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar + 2);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 2, rivi + 1)) {
			if (a->lauta[sar + 2][rivi + 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 1, sar + 2);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 2][rivi + 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar + 2);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
	}
}

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	int sar = r->getSarake();
	int rivi = r->getRivi();

	if (a->lauta[sar][rivi]->getVari() == vari) {

		int seuraavaSarake = sar;
		int seuraavaRivi = rivi;
		bool jatketaan = true;

		while (jatketaan) {
			seuraavaSarake--;
			seuraavaRivi--;
			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}

		seuraavaSarake = sar;
		seuraavaRivi = rivi;
		jatketaan = true;

		while (jatketaan) {
			seuraavaSarake--;
			seuraavaRivi++;
			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}

		seuraavaSarake = sar;
		seuraavaRivi = rivi;
		jatketaan = true;

		while (jatketaan) {
			seuraavaSarake++;
			seuraavaRivi--;
			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}

		seuraavaSarake = sar;
		seuraavaRivi = rivi;
		jatketaan = true;

		while (jatketaan) {
			seuraavaSarake++;
			seuraavaRivi++;
			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}
	}
}

void Torni::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	int sar = r->getSarake();
	int rivi = r->getRivi();

	if (a->lauta[sar][rivi]->getVari() == vari) {

		int seuraavaSarake = sar;
		int seuraavaRivi = rivi;
		bool jatketaan = true;

		while (jatketaan) {
			seuraavaSarake--;
			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}

		seuraavaSarake = sar;
		seuraavaRivi = rivi;
		jatketaan = true;

		while (jatketaan) {

			seuraavaSarake++;

			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}

		seuraavaSarake = sar;
		seuraavaRivi = rivi;
		jatketaan = true;

		while (jatketaan) {

			seuraavaRivi--;

			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}

		seuraavaSarake = sar;
		seuraavaRivi = rivi;
		jatketaan = true;

		while (jatketaan) {

			seuraavaRivi++;

			if (onLaudalla(seuraavaSarake, seuraavaRivi)) {
				if (a->lauta[seuraavaSarake][seuraavaRivi] == NULL) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(seuraavaRivi, seuraavaSarake);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
				else {
					Nappula* eka = a->lauta[sar][rivi];
					Nappula* toinen = a->lauta[seuraavaSarake][seuraavaRivi];
					if (eka->getVari() != toinen->getVari()) {
						Ruutu alku(rivi, sar);
						Ruutu loppu(seuraavaRivi, seuraavaSarake);
						Siirto s(alku, loppu);
						lista.push_back(s);
						jatketaan = false;
					}
					else {
						jatketaan = false;
					}
				}
			}
			else {
				jatketaan = false;
			}
		}
	}
}

void Daami::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	Lahetti::annaSiirrot(lista, r, a, vari);
	Torni::annaSiirrot(lista, r, a, vari);
}
