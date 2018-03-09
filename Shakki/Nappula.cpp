#pragma once
#include "Nappula.h"
#include "Asema.h"

using namespace std;

int Nappula::kSotilas[] = {
	0,  0,  0,  0,  0,  0,  0,  0,
	-11,  6,  7,  3,  3,  7,  6,-11,
	-18, -2, 19, 24, 24, 19, -2,-18,
	-17, -9, 20, 35, 35, 20, -9,-17,
	-6,  5,  3, 21, 21,  3,  5, -6,
	-6, -8, -6, -2, -2, -6, -8, -6,
	-4, 20, -8, -4, -4, -8, 20, -4,
	0,  0,  0,  0,  0,  0,  0,  0
};
int Nappula::lSotilas[] = {
	0,  0,  0,  0,  0,  0,  0,  0,
	7, -4,  8, -2, -2,  8, -4,  7,
	-4, -5,  5,  4,  4,  5, -5, -4,
	3,  3, -8, -3, -3, -8,  3,  3,
	8,  9,  7, -6, -6,  7,  9, -8,
	8, -5,  2,  4,  4,  2, -5,  8,
	3, -9,  1, 18, 18,  1, -9,  3,
	0,  0,  0,  0,  0,  0,  0,  0
};
int Nappula::kRatsu[] = {
	-161, -96, -80, -73, -73, -80, -96,-161,
	-83, -43, -21, -10, -10, -21, -43, -83,
	-71, -22,   0,   9,   9,   0, -22, -71,
	-25,  18,  43,  47,  47,  43,  18, -25,
	-26,  16,  38,  50,  50,  38,  16, -26,
	-11,  37,  56,  65,  65,  56,  37, -11,
	-63, -19,   5,  14,  14,   5, -19, -63,
	-195, -67, -42, -29, -29, -42, -67,-195
};
int Nappula::lRatsu[] = {
	-105, -82, -46, -14, -14, -46, -82,-105,
	-69, -54, -17,   9,   9, -17, -54, -69,
	-50, -39,  -7,  28,  28,  -7, -39, -50,
	-41, -25,   6,  38,  38,   6, -25, -41,
	-46, -25,   3,  40,  40,   3, -25, -46,
	-54, -38,  -7,  27,  27,  -7, -38, -54,
	-65, -50, -24,  13,  13, -24, -50, -65,
	-109, -89, -50, -13, -13, -50, -89,-109
};
int Nappula::kLahetti[] = {
	-44, -13, -25, -34, -34, -25, -13, -44,
	-20,  20,  12,   1,   1,  12,  20, -20,
	-9,  27,  21,  11,  11,  21,  27,  -9,
	-11,  28,  21,  10,  10,  21,  28, -11,
	-11,  27,  16,   9,   9,  16,  27, -11,
	-17,  16,  12,   2,   2,  12,  16, -17,
	-23,  17,   6,  -2,  -2,   6,  17, -23,
	-35, -11, -19, -29, -29, -19, -11, -35
};
int Nappula::lLahetti[] = {
	-58, -31, -37, -19, -19, -37, -31, -58,
	-34,  -9, -14,   4,   4, -14,  -9, -34,
	-23,   0,  -3,  16,  16,  -3,   0, -23,
	-26,  -3,  -5,  16,  16,  -5,  -3, -26,
	-26,  -4,  -7,  14,  14,  -7,  -4, -26,
	-24,  -2,   0,  13,  13,   0,  -2, -24,
	-34, -10, -12,   6,   6, -12, -10, -34,
	-55, -32, -36, -17, -17, -36, -32, -55
};
int Nappula::kTorni[] = {
	-25, -16, -16,  -9,  -9, -16, -16, -25,
	-21,  -8,  -3,   0,   0,  -3,  -8, -21,
	-21,  -9,  -4,   2,   2,  -4,  -9, -21,
	-22,  -6,  -1,   2,   2,  -1,  -6, -22,
	-22,  -7,   0,   1,   1,   0,  -7, -22,
	-21,  -7,   0,   2,   2,   0,  -7, -21,
	-12,   4,   8,  12,  12,   8,   4, -12,
	-23, -15, -11,  -5,  -5, -11, -15, -23
};
int Nappula::lTorni[] = {
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};
int Nappula::kDaami[] = {
	0,  -4,  -3,  -1,  -1,  -3,  -4,   0,
	-4,   6,   9,   8,   8,   9,   6,  -4,
	-2,   6,   9,   9,   9,   9,   6,  -2,
	-1,   8,  10,   7,   7,  10,   8,  -1,
	-3,   9,   8,   7,   7,   8,   9,  -3,
	-2,   6,   8,  10,  10,   8,   6,  -2,
	-2,   7,   7,   6,   6,   7,   7,  -2,
	-1,  -4,  -1,   0,   0,  -1,  -4,  -1

};
int Nappula::lDaami[] = {
	-71, -56, -42, -29, -29, -42, -56, -71,
	-56, -30, -21,  -5,  -5, -21, -30, -56,
	-39, -17,  -8,   5,   5,  -8, -17, -39,
	-29,  -5,   9,  19,  19,   9,  -5, -29,
	-27,  -5,  10,  21,  21,  10,  -5, -27,
	-40, -16, -10,   3,   3, -10, -16, -40,
	-55, -30, -21,  -6,  -6, -21, -30, -55,
	-74, -55, -43, -30, -30, -43, -55, -74
};
int Nappula::kKuningas[] = {
	267, 320, 270, 195, 195, 270, 320, 267,
	264, 304, 238, 180, 180, 238, 304, 264,
	200, 245, 176, 110, 110, 176, 245, 200,
	177, 185, 148, 110, 110, 148, 185, 177,
	149, 177, 115,  66,  66, 115, 177, 149,
	118, 159,  84,  41,  41,  84, 159, 118,
	87, 128,  63,  20,  20,  63, 128,  87,
	63,  88,  47,   0,   0,  47,  88,  63
};
int Nappula::lKuningas[] = {
	0,  48,  75,  84,  84,  75,  48,   0,
	43,  92, 143, 132, 132, 143,  92,  43,
	83, 138, 167, 165, 165, 167, 138,  83,
	106, 169, 169, 179, 179, 169, 169, 106,
	108, 163, 200, 203, 203, 200, 163, 108,
	95, 155, 176, 174, 174, 176, 155,  95,
	50,  99, 122, 139, 139, 122,  99,  50,
	9,  55,  80,  90,  90,  80,  55,   9
};


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

int Nappula::positioBonus(int sarake, int rivi, bool loppupeli)
{
	int paluu = 0;
	int indeksi;

	if (vari) {//musta
		indeksi = 63 - (rivi * 8 + sarake);
	}
	else {//valkoinen
		indeksi = rivi * 8 + sarake;
	}

	switch (_koodi) {
	case VS :
		if (loppupeli) {
			paluu = lSotilas[indeksi];
		}
		else {
			paluu = kSotilas[indeksi];
		}
		break;
	case MS:
		if (loppupeli) {
			paluu = lSotilas[indeksi];
		}
		else {
			paluu = kSotilas[indeksi];
		}
		break;
	case VT:
		if (loppupeli) {
			paluu = lTorni[indeksi];
		}
		else {
			paluu = kTorni[indeksi];
		}
		break;
	case MT:
		if (loppupeli) {
			paluu = lTorni[indeksi];
		}
		else {
			paluu = kTorni[indeksi];
		}
		break;
	case VL:
		if (loppupeli) {
			paluu = lLahetti[indeksi];
		}
		else {
			paluu = kLahetti[indeksi];
		}
		break;
	case ML:
		if (loppupeli) {
			paluu = lLahetti[indeksi];
		}
		else {
			paluu = kLahetti[indeksi];
		}
		break;
	case VR:
		if (loppupeli) {
			paluu = lRatsu[indeksi];
		}
		else {
			paluu = kRatsu[indeksi];
		}
		break;
	case MR:
		if (loppupeli) {
			paluu = lRatsu[indeksi];
		}
		else {
			paluu = kRatsu[indeksi];
		}
		break;
	case VD:
		if (loppupeli) {
			paluu = lDaami[indeksi];
		}
		else {
			paluu = kDaami[indeksi];
		}
		break;
	case MD:
		if (loppupeli) {
			paluu = lDaami[indeksi];
		}
		else {
			paluu = kDaami[indeksi];
		}
		break;
	case VK:
		if (loppupeli) {
			paluu = lKuningas[indeksi];
		}
		else {
			paluu = kKuningas[indeksi];
		}
		break;
	case MK:
		if (loppupeli) {
			paluu = lKuningas[indeksi];
		}
		else {
			paluu = kKuningas[indeksi];
		}
		break;
	default:
		paluu = 0;
		break;
	}

	return paluu;
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

					if (loppu.getRivi() < 7) {
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

					if (loppu.getRivi() < 7) {
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
			if (a->lauta[sa][ri] != NULL) {//ei ole null
				if (a->lauta[sa][ri]->getVari() == tVari) {//on vastustajan väriä
					if (!(a->lauta[sa][ri]->getKoodi() == MK && tVari == 1) && !(a->lauta[sa][ri]->getKoodi() == VK && tVari == 0)) {
						Ruutu ruut(ri, sa);
						if (a->lauta[sa][ri]->getKoodi() == VS) {
							if (onLaudalla(sa + 1, ri + 1)) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri + 1, sa + 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
							if (onLaudalla(sa - 1, ri + 1)) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri + 1, sa - 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						else if (a->lauta[sa][ri]->getKoodi() == MS) {
							if (onLaudalla(sa + 1, ri - 1)) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri - 1, sa + 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
							if (onLaudalla(sa - 1, ri - 1)) {
								Ruutu alku(ri, sa);
								Ruutu loppu(ri - 1, sa - 1);
								Siirto s(alku, loppu);
								vastustaja.push_back(s);
							}
						}
						else {
							a->lauta[sa][ri]->annaSiirrot(vastustaja, &ruut, a, tVari);
						}
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
				&& !onkoRuutuListalla(vastustaja, 4, 0) && !onkoRuutuListalla(vastustaja, 2, 0)
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
				&& !onkoRuutuListalla(vastustaja, 4, 7) && !onkoRuutuListalla(vastustaja, 2, 7)
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
