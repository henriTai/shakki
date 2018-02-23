#pragma once
#include "Asema.h"
//#include "Nappula.h"
//#include "Siirto.h"
//#include "Ruutu.h"
//#include <string>
//#include <iostream> //debuggaukseen


using namespace std;

Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vd = new Daami(L"\u2655", 0, VD);
Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);
Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Daami(L"\u265B", 1, MD);
Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);

Asema::Asema()
{

	for (int i = 0;i < 8;i++) {
		for (int j = 0; j < 8;j++) {
			lauta[i][j] = NULL;
		}
	}
	lauta[0][0] = vt;
	lauta[1][0] = vr;
	lauta[2][0] = vl;
	lauta[3][0] = vd;
	lauta[4][0] = vk;
	lauta[5][0] = vl;
	lauta[6][0] = vr;
	lauta[7][0] = vt;
	for (int i = 0;i < 8; i++) {
		lauta[i][1] = vs;
		lauta[i][6] = ms;
	}
	lauta[0][7] = mt;
	lauta[1][7] = mr;
	lauta[2][7] = ml;
	lauta[3][7] = md;
	lauta[4][7] = mk;
	lauta[5][7] = ml;
	lauta[6][7] = mr;
	lauta[7][7] = mt;//[sarake][rivi]

	enPassee[0] = 0; //sarake
	enPassee[1] = 0; //rivi;
	siirtovuoro = 0;
	onkoValkeaKuningasLiikkunut = false;
	onkoMustaKuningasLiikkunut = false;
	onkoValkeaDTliikkunut = false;
	onkoValkeaKTliikkunut = false;
	onkoMustaDTliikkunut = false;
	onkoMustaKTliikkunut = false;


}


void Asema::paivitaAsema(Siirto * siirto)
{
	Ruutu alkuruutu = siirto->getAlkuruutu();
	Ruutu loppuruutu = siirto->getLoppuruutu();
	Nappula *n = 0;
	int koodi = 0;
	if (!siirto->onkoLyhytLinna() && !siirto->onkoPitkalinna()) {
		n = lauta[alkuruutu.getSarake()][alkuruutu.getRivi()];
		koodi = n->getKoodi();
	}

	//poistetaan vastustajan nappula en passeessa

	if (enPassee[0] != 0 || enPassee[1] != 0) {

		if (koodi == VS || koodi == MS) {
			if (alkuruutu.getRivi() == enPassee[1]) {
				if (alkuruutu.getSarake() == enPassee[0] + 1 || alkuruutu.getSarake() == enPassee[0] - 1) {
					if (loppuruutu.getSarake() == enPassee[0]) {
						if ((koodi == VS && loppuruutu.getRivi() == alkuruutu.getRivi() + 1) ||
							(koodi == MS && loppuruutu.getRivi() == alkuruutu.getRivi() - 1)) {
							lauta[enPassee[0]][enPassee[1]] = NULL;
						}
					}
				}
			}
		}

		enPassee[0] = 0;
		enPassee[1] = 0;
	}

	if (siirto->onkoLyhytLinna()==false&&siirto->onkoPitkalinna()==false) {

		if (!onkoValkeaKuningasLiikkunut) {
			if (koodi == vk->getKoodi()) {
				onkoValkeaKuningasLiikkunut = true;
			}
		}

		if (!onkoMustaKuningasLiikkunut) {
			if (koodi == mk->getKoodi()) {
				onkoMustaKuningasLiikkunut = true;
			}
		}

		if (!onkoValkeaDTliikkunut) {
			if (lauta[0][0] == NULL) {
				onkoValkeaDTliikkunut == true;
			}
			else if (lauta[0][0]->getKoodi() != vt->getKoodi()) {
				onkoValkeaDTliikkunut = true;
			}
			if (lauta[0][0]->getKoodi() == vt->getKoodi() && alkuruutu.getSarake() == 0 && alkuruutu.getRivi() == 0) {
				onkoValkeaDTliikkunut = true;
			}
		}

		if (!onkoValkeaKTliikkunut) {
			if (lauta[7][0] == NULL) {
				onkoValkeaKTliikkunut == true;
			}
			else if (lauta[7][0]->getKoodi() != vt->getKoodi()) {
				onkoValkeaKTliikkunut = true;
			}
			else if (lauta[7][0]->getKoodi() == vt->getKoodi() && alkuruutu.getSarake() == 7 && alkuruutu.getRivi() == 0) {
				onkoValkeaKTliikkunut = true;
			}
		}

		if (!onkoMustaDTliikkunut) {
			if (lauta[0][7] == NULL) {
				onkoMustaDTliikkunut == true;
			}
			else if (lauta[0][7]->getKoodi() != mt->getKoodi()) {
				onkoMustaDTliikkunut = true;
			}
			else if (lauta[0][7]->getKoodi() == mt->getKoodi() && alkuruutu.getSarake() == 0 && alkuruutu.getRivi() == 7) {
				onkoMustaDTliikkunut = true;
			}
		}

		if (!onkoMustaKTliikkunut) {
			if (lauta[7][7] == NULL) {
				onkoMustaKTliikkunut = true;
			}
			else if (lauta[7][7]->getKoodi() != mt->getKoodi()) {
				onkoMustaKTliikkunut = true;
			}
			else if (lauta[7][7]->getKoodi() == mt->getKoodi() && alkuruutu.getSarake() == 7 && alkuruutu.getRivi() == 7) {
				onkoMustaKTliikkunut = true;
			}
		}

		//sotilaan kaksoissiirrolla pistää en passeen päälle

		if (koodi == VS || koodi == MS) {
			int matka = loppuruutu.getRivi() - alkuruutu.getRivi();
			if (matka == 2 || matka == -2) {
				enPassee[0] = loppuruutu.getSarake();
				enPassee[1] = loppuruutu.getRivi();
			}
			//sotilaiden korotus
			else if (koodi == VS && loppuruutu.getRivi() == 7) {
				if (siirto->korotus == 'D') {
					koodi = VD;
				}
				else if (siirto->korotus == 'T') {
					koodi = VT;
				}
				else if (siirto->korotus == 'R') {
					koodi = VR;
				}
				else if (siirto->korotus == 'L') {
					koodi = VL;
				}
			}
			else if (koodi == MS && loppuruutu.getRivi() == 0) {
				if (siirto->korotus == 'D') {
					koodi = MD;
				}
				else if (siirto->korotus == 'T') {
					koodi = MT;
				}
				else if (siirto->korotus == 'R') {
					koodi = MR;
				}
				else if (siirto->korotus == 'L') {
					koodi = ML;
				}
			}
		}



		lauta[loppuruutu.getSarake()][loppuruutu.getRivi()] = getNappula(koodi);

		lauta[alkuruutu.getSarake()][alkuruutu.getRivi()] = NULL;
	}
	else if (siirtovuoro == 0 && siirto->onkoLyhytLinna()) {
		//valkoinen tekee lyhyen linnan
		lauta[5][0] = vt;
		lauta[6][0] = vk;
		lauta[4][0] = NULL;
		lauta[7][0] = NULL;
		onkoValkeaKuningasLiikkunut = true;
		onkoValkeaKTliikkunut = true;
	}
	else if (siirtovuoro == 0 && siirto->onkoPitkalinna()) {
		//valkoinen tekee pitkän linnan
		lauta[2][0] = vk;
		lauta[3][0] = vt;
		lauta[0][0] = NULL;
		lauta[4][0] = NULL;
		onkoValkeaKuningasLiikkunut = true;
		onkoValkeaDTliikkunut = true;
	}
	else if (siirtovuoro == 1 && siirto->onkoLyhytLinna()) {
		//musta tekee lyhyen linnan
		lauta[5][7] = mt;
		lauta[6][7] = mk;
		lauta[7][7] = NULL;
		lauta[4][7] = NULL;
		onkoMustaKuningasLiikkunut = true;
		onkoMustaKTliikkunut = true;
	}
	else if (siirtovuoro == 1 && siirto->onkoPitkalinna()) {
		//musta tekee pitkän linnan
		lauta[2][7] = mk;
		lauta[3][7] = mt;
		lauta[0][7] = NULL;
		lauta[4][7] = NULL;
		onkoMustaKuningasLiikkunut = true;
		onkoMustaDTliikkunut = true;
	}


	if (siirtovuoro == 1) {
		siirtovuoro = 0;
	}
	else {
		siirtovuoro = 1;
	}
	
}

Nappula* Asema::getNappula(int a) {

	if (a == VK) {
		return vk;
	}
	else if (a == VD) {
		return vd;
	}
	else if (a == VT) {
		return vt;
	}
	else if (a == VL) {
		return vl;
	}
	else if (a == VR) {
		return vr;
	}
	else if (a == VS) {
		return vs;
	}
	else if (a == MK) {
		return mk;
	}
	else if (a == MD) {
		return md;
	}
	else if (a == MT) {
		return mt;
	}
	else if (a == ML) {
		return ml;
	}
	else if (a == MR) {
		return mr;
	}
	else if (a == MS) {
		return ms;
	}

}

int Asema::getSiirtovuoro()
{
	return siirtovuoro;
}

void Asema::setSiirtovuoro(int vari)
{
	siirtovuoro = vari; //oletus että 0/1
}

bool Asema::getOnkoValkeaKuningasLiikkunut()
{
	return onkoValkeaKuningasLiikkunut;
}

bool Asema::getOnkoMustaKuningasLiikkunut()
{
	return onkoMustaKuningasLiikkunut;
}

bool Asema::getOnkoValkeaDTliikkunut()
{
	return onkoValkeaDTliikkunut;
}

bool Asema::getOnkoValkeaKTliikkunut()
{
	return onkoValkeaKTliikkunut;
}

bool Asema::getOnkoMustaDTliikkunut()
{
	return onkoMustaDTliikkunut;
}

bool Asema::getOnkoMustaKTliikkunut()
{
	return onkoMustaKTliikkunut;
}

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista)
{
	for (int sar = 0;sar < 8;sar++) {
		for (int riv = 0;riv < 8;riv++) {
			if (lauta[sar][riv] != NULL) {
				Ruutu r(riv, sar);
				lauta[sar][riv]->annaSiirrot(lista, &r, this, siirtovuoro);
			}
		}
	}
}

Ruutu Asema::kuninkaanSijainti()
{
	int vari = getSiirtovuoro();
	Ruutu ruut(0, 0);
	for (int sa = 0;sa < 8;sa++) {
		for (int ri = 0;ri < 8;ri++) {
			if (lauta[sa][ri] != NULL) {
				if ((vari == 0 && lauta[sa][ri]->getKoodi() == VK) || (vari == 1 && lauta[sa][ri]->getKoodi() == MK)) {
					return Ruutu(ri, sa);
					break;
				}
			}
		}
	}
	return ruut;
}

bool Asema::onkoMatti()
{
	Asema as = *this;
	Ruutu kunkku = kuninkaanSijainti();
	if (getSiirtovuoro() == 0) {
		as.setSiirtovuoro(1);
	}
	else {
		as.setSiirtovuoro(0);
	}

	std::list<Siirto> siirrot;
	as.annaLaillisetSiirrot(siirrot);

	for (std::list<Siirto>::const_iterator it = siirrot.begin(), end = siirrot.end();it != end;++it) {
		Siirto si = *it;
		if (si.getLoppuruutu().getRivi() == kunkku.getRivi() && si.getLoppuruutu().getSarake() == kunkku.getSarake()) {

			return true;
		}
	}
	return false;
}

std::list<Siirto> Asema::tarkistaSiirrot(std::list<Siirto>& siirrot)
{
	Ruutu ruut = kuninkaanSijainti();
	list<Siirto> tarkastetut;
	while (!siirrot.empty()) {
		Ruutu r = ruut;
		list<Siirto> uudet;
		Asema a = *this;
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

double Asema::evaluoi()
{
	double musta = 0; //negatiivinen luku, erilliset lisäkalkulaatioita varten
	double valkoinen = 0;
	for (int sar = 0; sar < 8; sar++) {
		for (int riv = 0; riv < 8; riv++){
			if (lauta[sar][riv] != NULL) {
				if (lauta[sar][riv]==vs) {
					valkoinen += 1;
				}
				else if (lauta[sar][riv]==ms){
					musta -= 1;
				}
				else if (lauta[sar][riv] == vt) {
					valkoinen += 5;
				}
				else if (lauta[sar][riv] == mt) {
					musta -= 5;
				}
				else if (lauta[sar][riv] == vl) {
					valkoinen += 3.25;
				}
				else if (lauta[sar][riv] == ml) {
					musta -= 3.25;
				}
				else if (lauta[sar][riv] == vr) {
					valkoinen += 3;
				}
				else if (lauta[sar][riv] == mr) {
					musta -= 3;
				}
				else if (lauta[sar][riv] == vd) {
					valkoinen += 9;
				}
				else if (lauta[sar][riv] == md) {
					musta -= 9;
				}
			}
		}
	}
	double ev = musta + valkoinen;
	return ev;
}

Siirto Asema::parasSiirto(int syvyys)
{
	MinMaxPaluu p;
	if (getSiirtovuoro()) {
		p = mini(syvyys);
	}
	else {
		p = maxi(syvyys);
	}
	return p.parasSiirto;
}

MinMaxPaluu Asema::maxi(int syvyys)
{
	list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);
	siirrot = tarkistaSiirrot(siirrot);

	MinMaxPaluu mm;
	mm.evaluointiArvo = -1000000;
	Ruutu nolla(0, 0);
	Siirto dummy(nolla, nolla);
	mm.parasSiirto = dummy;

	if (syvyys > 0) {
		while (!siirrot.empty()) {
			MinMaxPaluu temp;
			temp.parasSiirto = *siirrot.begin();
			Asema as = *this;
			as.paivitaAsema(&temp.parasSiirto);
			temp = as.mini(syvyys - 1);
			temp.parasSiirto = *siirrot.begin();
			if (temp.evaluointiArvo > mm.evaluointiArvo) {
				mm = temp;
			}
			siirrot.pop_front();
		}
	}
	if (syvyys == 0) {
		mm.evaluointiArvo = evaluoi();
		mm.parasSiirto = dummy;
	}

	return mm;
}

MinMaxPaluu Asema::mini(int syvyys)
{
	list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);
	siirrot = tarkistaSiirrot(siirrot);

	MinMaxPaluu mm;
	mm.evaluointiArvo = 1000000;
	Ruutu nolla(0, 0);
	Siirto dummy(nolla, nolla);
	mm.parasSiirto = dummy;

	if (syvyys > 0) {
		while (!siirrot.empty()) {
			MinMaxPaluu temp;
			temp.parasSiirto = *siirrot.begin();
			Asema as = *this;
			as.paivitaAsema(&temp.parasSiirto);
			temp = as.maxi(syvyys - 1);
			temp.parasSiirto = *siirrot.begin();
			if (temp.evaluointiArvo < mm.evaluointiArvo) {
				mm = temp;
			}
			siirrot.pop_front();
		}
	}
	if (syvyys == 0) {
		mm.evaluointiArvo = evaluoi();
		mm.parasSiirto = dummy;
	}

	return mm;
}

