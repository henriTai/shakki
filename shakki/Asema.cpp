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
		lauta[5][0] = vk;
		lauta[4][0] = vt;
		lauta[7][0] = NULL;
		onkoValkeaKuningasLiikkunut = true;
		onkoValkeaKTliikkunut = true;
	}
	else if (siirtovuoro == 0 && siirto->onkoPitkalinna()) {
		//valkoinen tekee pitkän linnan
		lauta[3][0] = vk;
		lauta[0][0] = NULL;
		lauta[4][0] = vt;
		onkoValkeaKuningasLiikkunut = true;
		onkoValkeaDTliikkunut = true;
	}
	else if (siirtovuoro == 1 && siirto->onkoLyhytLinna()) {
		//musta tekee lyhyen linnan
		lauta[5][7] = mk;
		lauta[7][7] = NULL;
		lauta[4][7] = mt;
		onkoMustaKuningasLiikkunut = true;
		onkoMustaKTliikkunut = true;
	}
	else if (siirtovuoro == 1 && siirto->onkoPitkalinna()) {
		//musta tekee pitkän linnan
		lauta[3][7] = mk;
		lauta[0][7] = NULL;
		lauta[4][7] = mt;
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
				Ruutu *r=new Ruutu(riv, sar);
				lauta[sar][riv]->annaSiirrot(lista, r, this, siirtovuoro);
			}
		}
	}
}

