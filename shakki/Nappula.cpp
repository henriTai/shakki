#pragma once
#include "Nappula.h"
#include "Asema.h"

using namespace std;



bool Nappula::onkoRuutuListalla(std::list<Siirto>& vastustaja, int sarake, int rivi)
{
	Ruutu ruutu(rivi, sarake);
	Siirto s;
	for (std::list<Siirto>::const_iterator it = vastustaja.begin(), end = vastustaja.end(); it != end; ++it) {
		s = *it;
		Ruutu loppu = s.getLoppuruutu();
		if (loppu.getRivi() == ruutu.getRivi() && loppu.getSarake() == ruutu.getSarake()) {
			return true;
			break;
		}
	}
	return false;
}

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

					if (rivi < 6) {
						lista.push_back(s);
					}
					else {
						//valkoinen korotus suoralla etenemisellä
						lisaaSotilaanKorotukset(&s, lista, a);
					}
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

					if (loppu.getRivi() < 6) {
						lista.push_back(s);
					}
					else {
						//valkoinen korotus syömällä vasemmalta
						lisaaSotilaanKorotukset(&s, lista, a);
					}
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

					if (loppu.getRivi() < 6) {
						lista.push_back(s);
					}
					else {
						//valkoinen korotus syömällä oikealta
						lisaaSotilaanKorotukset(&s, lista, a);
					}
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

					if (rivi > 1) {
						lista.push_back(s);
					}
					else {
						//mustan korotus suoralla etenemisellä
						lisaaSotilaanKorotukset(&s, lista, a);
					}
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

					if (loppu.getRivi() > 0) {
						lista.push_back(s);
					}
					else {
						//mustan korotus syömällä vasemmalta
						lisaaSotilaanKorotukset(&s, lista, a);
					}
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

					if (loppu.getRivi() > 0) {
						lista.push_back(s);
					}
					else {
						//mustan korotus syömällä oikealta
						lisaaSotilaanKorotukset(&s, lista, a);
					}
				}
			}
		}
	}

	if (a->enPassee[0] != 0 && a->enPassee[1] != 0) {
		if ((rivi == a->enPassee[1]) && (sar + 1 == a->enPassee[0] || sar - 1 == a->enPassee[0]) &&
			(a->lauta[a->enPassee[0]][a->enPassee[1]]->getVari()!=a->lauta[sar][rivi]->getVari())) {
			Ruutu alku(rivi, sar);
			int loppurivi;
			if (vari == 0) {
				loppurivi = rivi + 1;
			}
			else {
				loppurivi = rivi - 1;
			}
			Ruutu loppu(loppurivi, a->enPassee[0]);
			Siirto s(alku, loppu);
			lista.push_back(s);
		}
	}
}

void Sotilas::lisaaSotilaanKorotukset(Siirto * s, std::list<Siirto>& lista, Asema * a)
{
	Siirto d(s->getAlkuruutu(), s->getLoppuruutu(), 'D');
	Siirto t(s->getAlkuruutu(), s->getLoppuruutu(), 'T');
	Siirto r(s->getAlkuruutu(), s->getLoppuruutu(), 'R');
	Siirto l(s->getAlkuruutu(), s->getLoppuruutu(), 'L');
	lista.push_back(d);
	lista.push_back(t);
	lista.push_back(r);
	lista.push_back(l);
}

void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu * r, Asema * a, int vari)
{
	//lista vastustajan uhkaamista ruuduista, kuningas täytyy hoitaa erikseen ettei tule looppi
	std::list<Siirto>vastustaja;
	int tVari;

	if (vari == 0) {
		tVari = 1;
	}
	else {
		tVari = 0;
	}

	for (int sa = 0; sa < 8;sa++) {
		for (int ri = 0;ri < 8;ri++) {
			if (a->lauta[sa][ri] != NULL) {
				if (a->lauta[sa][ri]->getVari() == tVari) {
					if (!(a->lauta[sa][ri]->getKoodi() == MK && tVari == 1) && !(a->lauta[sa][ri]->getKoodi() == VK && tVari == 0)) {
						Ruutu *ruut = new Ruutu(ri, sa);
						a->lauta[sa][ri]->annaSiirrot(vastustaja, ruut, a, tVari);
					}

					else if ((tVari == 0 && a->lauta[sa][ri]->getKoodi() == VK) ||
						(tVari == 1 && a->lauta[sa][ri]->getKoodi() == MK)) {

						//
						if (onLaudalla(sa - 1, ri - 1)) {
							if (a->lauta[sa - 1][ri - 1] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri - 1, sa - 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa - 1, ri)) {
							if (a->lauta[sa - 1][ri] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri, sa - 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa - 1, ri + 1)) {
							if (a->lauta[sa - 1][ri + 1] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri + 1, sa - 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa, ri - 1)) {
							if (a->lauta[sa][ri - 1] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri - 1, sa);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa, ri + 1)) {
							if (a->lauta[sa][ri + 1] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri + 1, sa);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa + 1, ri - 1)) {
							if (a->lauta[sa + 1][ri - 1] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri - 1, sa + 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa + 1, ri)) {
							if (a->lauta[sa + 1][ri] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri, sa + 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						if (onLaudalla(sa + 1, ri + 1)) {
							if (a->lauta[sa + 1][ri + 1] == NULL) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri + 1, sa + 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
					}
				}
			}
		}
	}

	//

	int sar = r->getSarake();
	int rivi = r->getRivi();

	if (a->lauta[sar][rivi]->getVari() == vari) {

		if (onLaudalla(sar - 1, rivi) && !onkoRuutuListalla(vastustaja, sar-1, rivi)) {
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
		if (onLaudalla(sar + 1, rivi) && !onkoRuutuListalla(vastustaja, sar + 1, rivi)) {
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
		if (onLaudalla(sar, rivi - 1) && !onkoRuutuListalla(vastustaja, sar, rivi - 1)) {
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
		if (onLaudalla(sar, rivi + 1) && !onkoRuutuListalla(vastustaja, sar, rivi + 1)) {
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
		if (onLaudalla(sar - 1, rivi - 1) && !onkoRuutuListalla(vastustaja, sar - 1, rivi - 1)) {
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
		if (onLaudalla(sar - 1, rivi + 1) && !onkoRuutuListalla(vastustaja, sar - 1, rivi + 1)) {
			if (a->lauta[sar - 1][rivi + 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi + 1, sar - 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar - 1][rivi + 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi + 1, sar - 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi - 1) && !onkoRuutuListalla(vastustaja, sar + 1, rivi -1)) {
			if (a->lauta[sar + 1][rivi - 1] == NULL) {
				Ruutu alku(rivi, sar);
				Ruutu loppu(rivi - 1, sar + 1);
				Siirto s(alku, loppu);
				lista.push_back(s);
			}
			else {
				Nappula* eka = a->lauta[sar][rivi];
				Nappula* toinen = a->lauta[sar + 1][rivi - 1];
				if (eka->getVari() != toinen->getVari()) {
					Ruutu alku(rivi, sar);
					Ruutu loppu(rivi - 1, sar + 1);
					Siirto s(alku, loppu);
					lista.push_back(s);
				}
			}
		}
		if (onLaudalla(sar + 1, rivi + 1) && !onkoRuutuListalla(vastustaja, sar + 1, rivi + 1)) {
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
			if (a->lauta[1][0] == NULL && a->lauta[2][0] == NULL && a->lauta[3][0] == NULL
				&& !onkoRuutuListalla(vastustaja, 1, 0) && !onkoRuutuListalla(vastustaja, 2, 0)
				&& !onkoRuutuListalla(vastustaja, 3, 0)) {
				Siirto s(false, true);
				lista.push_back(s);
			}
		}
		if (vari == 0 && a->getOnkoValkeaKuningasLiikkunut() == false && a->getOnkoValkeaKTliikkunut() == false) {
			//valkea lyhyt torni
			if (a->lauta[5][0] == NULL && a->lauta[6][0] == NULL && !onkoRuutuListalla(vastustaja, 5, 0)
				&& !onkoRuutuListalla(vastustaja, 6, 0)) {
				Siirto s(true, false);
				lista.push_back(s);
			}
		}
		if (vari == 1 && a->getOnkoMustaKuningasLiikkunut() == false && a->getOnkoMustaDTliikkunut() == false) {
			//musta pitkä torni
			if (a->lauta[1][7] == NULL && a->lauta[2][7] == NULL && a->lauta[3][7] == NULL
				&& !onkoRuutuListalla(vastustaja, 1, 7) && !onkoRuutuListalla(vastustaja, 2, 7)
				&& !onkoRuutuListalla(vastustaja, 3, 7)) {
				Siirto s(false, true);
				lista.push_back(s);
			}
		}
		if (vari == 1 && a->getOnkoMustaKuningasLiikkunut() == false && a->getOnkoMustaKTliikkunut() == false) {
			//musta lyhyt torni
			if (a->lauta[5][7] == NULL && a->lauta[6][7] == NULL && !onkoRuutuListalla(vastustaja, 5, 7)
				&& !onkoRuutuListalla(vastustaja, 6, 7)) {
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
