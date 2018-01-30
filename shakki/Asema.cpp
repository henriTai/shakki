#include "Asema.h"
#include "Nappula.h"
#include "Siirto.h"
#include "Ruutu.h"
#include <string>
#include <iostream> //debuggaukseen

using namespace std;

Nappula* Asema::vk = new Nappula(L"\u2654", 0, VK);
Nappula* Asema::vd = new Nappula(L"\u2655", 0, VD);
Nappula* Asema::vt = new Nappula(L"\u2656", 0, VT);
Nappula* Asema::vl = new Nappula(L"\u2657", 0, VL);
Nappula* Asema::vr = new Nappula(L"\u2658", 0, VR);
Nappula* Asema::vs = new Nappula(L"\u2659", 0, VS);
Nappula* Asema::mk = new Nappula(L"\u265A", 1, MK);
Nappula* Asema::md = new Nappula(L"\u265B", 1, MD);
Nappula* Asema::mt = new Nappula(L"\u265C", 1, MT);
Nappula* Asema::ml = new Nappula(L"\u265D", 1, ML);
Nappula* Asema::mr = new Nappula(L"\u265E", 1, MR);
Nappula* Asema::ms = new Nappula(L"\u265F", 1, MS);

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
	Nappula n = *lauta[alkuruutu.getSarake()][alkuruutu.getRivi()];
	
	
	if (n.getKoodi() == vk->getKoodi()) {
		onkoValkeaKuningasLiikkunut = true;
	}
	if (n.getKoodi() == mk->getKoodi()) {
		onkoMustaKuningasLiikkunut = true;
	}
	if (!onkoValkeaDTliikkunut) {
		if (lauta[0][0]->getKoodi() == vt->getKoodi() && alkuruutu.getSarake() == 0 && alkuruutu.getRivi() == 0) {
			onkoValkeaDTliikkunut = true;
		}
	}

	if (!onkoValkeaKTliikkunut) {
		if (lauta[7][0]->getKoodi() == vt->getKoodi() && alkuruutu.getSarake() == 7 && alkuruutu.getRivi() == 0) {
			onkoValkeaKTliikkunut = true;
		}
	}

	if (!onkoMustaDTliikkunut) {
		if (lauta[0][7]->getKoodi() == mt->getKoodi() && alkuruutu.getSarake() == 0 && alkuruutu.getRivi() == 7) {
			onkoMustaDTliikkunut = true;
		}
	}

	if (!onkoMustaKTliikkunut) {
		if (lauta[7][7]->getKoodi() == mt->getKoodi() && alkuruutu.getSarake() == 7 && alkuruutu.getRivi() == 7) {
			onkoMustaKTliikkunut = true;
		}
	}

	lauta[loppuruutu.getSarake()][loppuruutu.getRivi()] = getNappula(n.getKoodi());

	lauta[alkuruutu.getSarake()][alkuruutu.getRivi()] = NULL;


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
