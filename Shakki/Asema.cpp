#pragma once
#include "Asema.h"
#include <future>



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

		if (koodi == vk->getKoodi()) {
			if (!onkoValkeaKuningasLiikkunut) {
				onkoValkeaKuningasLiikkunut = true;
			}
		}

		else if (koodi == mk->getKoodi()) {
			if (!onkoMustaKuningasLiikkunut) {
				onkoMustaKuningasLiikkunut = true;
			}
		}

		if (!onkoValkeaDTliikkunut) {
			if (lauta[0][0] == NULL) {
				onkoValkeaDTliikkunut = true;
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
				onkoValkeaKTliikkunut = true;
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
				onkoMustaDTliikkunut = true;
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
	int mg;
	int eg;
	int vaihe;
	mg_eg_phase_evaluaatio(mg, eg, vaihe);
	int skaalaaja;
	skaalain(eg, skaalaaja);
	eg = eg*skaalaaja / 64;
	if (mg*vaihe + eg*(128 - vaihe) != 0) {
		return (mg*vaihe + eg*(128 - vaihe)) / 128;
	}
	else {
		return 0;
	}
	//return mg;
}

void Asema::skaalain(int &eg, int &paluu)
{
	int whitePawnCount = 0;
	int blackPawnCount = 0;
	int whiteNonPawnMat = 0;
	int blackNonPawnMat = 0;
	int whiteBishopCount = 0;
	int blackBishopCount = 0;
	int _Kx = 0;
	int _Ky = 0;
	int _kx = 0;
	int _ky = 0;
	int sf = 64;
	wpc_bpc_wnpm_b_npm_wb_bb_kings(whitePawnCount, blackPawnCount, whiteNonPawnMat, blackNonPawnMat, whiteBishopCount, blackBishopCount, _Kx, _Ky, _kx, _ky);

	int pc_w;
	int pc_b;
	int npm_w;
	int npm_b;
	if (eg > 0) {
		pc_w = whitePawnCount;
		pc_b = blackPawnCount;
		npm_w = whiteNonPawnMat;
		npm_b = blackNonPawnMat;
	}
	else {
		pc_b = whitePawnCount;
		pc_w = blackPawnCount;
		npm_b = whiteNonPawnMat;
		npm_w = blackNonPawnMat;
	}
	if (pc_w == 0 && (npm_w - npm_b <= 826)) {
		if (npm_w < 1282) {
			sf = 0;
		}
		else {
			if (npm_b <= 826) {
				sf = 4;
			}
			else {
				sf = 14;
			}
		}
	}
	if (pc_w == 1 && (npm_w - npm_b <= 826)) {
		sf = 48;
	}
	if (sf == 64 || sf == 48) {
		if (whiteBishopCount == 1 && blackBishopCount == 1 ) {
			if (oppositeBishops()) {
				if (npm_w == 826 && npm_b == 826) {
					if (pc_w + pc_b > 1) {
						sf = 31;
					}
					else {
						sf = 9;
					}
				}
				else {
					sf = 46;
				}
			}
		}
		else {
			int temp_eg;
			if (eg < 0) {
				temp_eg = 0 - eg;
			}
			else {
				temp_eg = eg;
			}
			if (temp_eg <= 826 && pc_w <= 2) {
				int kuningas_x;
				int kuningas_y;
				bool kingPassed = true;
				if (eg > 0) {
					kuningas_x = _kx;
					kuningas_y = _ky;
					if (kuningas_y < 7) {
						for (int rivi = kuningas_y+1;rivi < 8;rivi++) {
							if ((kuningas_x - 1) >= 0 && (rivi + 1 <= 7)) {
								if (lauta[kuningas_x - 1][rivi + 1] != NULL) {
									if (lauta[kuningas_x - 1][rivi + 1] == vs) {
										kingPassed = false;
									}
								}
							}
							if (lauta[kuningas_x][rivi] != NULL) {
								if (lauta[kuningas_x][rivi] == vs) {
									kingPassed = false;
								}
							}
							if (kuningas_x + 1 < 8 && rivi + 1 < 8) {
								if (lauta[kuningas_x + 1][rivi + 1] != NULL) {
									if (lauta[kuningas_x + 1][rivi + 1] == vs) {
										kingPassed = false;
									}
								}
							}
						}
					}
				}
				else {
					kuningas_x = _Kx;
					kuningas_y = _Ky;
					if (kuningas_y > 0) {
						for (int rivi = kuningas_y-1;rivi >= 0;rivi--) {
							if ((kuningas_x - 1) >= 0 && (rivi - 1 >= 0)) {
								if (lauta[kuningas_x - 1][rivi - 1] != NULL) {
									if (lauta[kuningas_x - 1][rivi - 1] == ms) {
										kingPassed = false;
									}
								}
							}
							if (lauta[kuningas_x][rivi] != NULL) {
								if (lauta[kuningas_x][rivi] == ms) {
									kingPassed = false;
								}
							}
							if (kuningas_x + 1 < 8 && rivi - 1 >= 0) {
								if (lauta[kuningas_x + 1][rivi - 1] != NULL) {
									if (lauta[kuningas_x + 1][rivi - 1] == ms) {
										kingPassed = false;
									}
								}
							}
						}

					}
				}
				if (!kingPassed) {
					sf = 37 + 7 * pc_w;
				}
			}
		}
	}
	paluu = sf;

}

void Asema::mg_eg_phase_evaluaatio(int & mid, int & end, int &phase)
{
	int musta_mid = 0;
	int musta_end = 0;
	int valk_mid = 0;
	int valk_end = 0;

	int mg_limit = 15258;
	int eg_limit = 3915;
	int non_pawn = 0;

	for (int sar = 0; sar < 8; sar++) {
		for (int riv = 0; riv < 8; riv++) {
			if (lauta[sar][riv] != NULL) {
				int mid_bonus = lauta[sar][riv]->positioBonus(sar, riv, 0);
				int end_bonus = lauta[sar][riv]->positioBonus(sar, riv, 1);
				if (lauta[sar][riv] == vs) {
					valk_mid += (171 + mid_bonus);
					valk_end += (171 + end_bonus);
				}
				else if (lauta[sar][riv] == ms) {
					musta_mid -= (171+mid_bonus);
					musta_end -= (171 + end_bonus);
				}
				else if (lauta[sar][riv] == vt) {
					valk_mid += (1282 + mid_bonus);
					valk_end += (1282 + end_bonus);
					non_pawn += 1282;
				}
				else if (lauta[sar][riv] == mt) {
					musta_mid -= (1282 + mid_bonus);
					musta_end -= (1282 + end_bonus);
					non_pawn += 1282;
				}
				else if (lauta[sar][riv] == vl) {
					valk_mid += (826 + mid_bonus);
					valk_end += (826 + end_bonus);
					non_pawn += 826;
				}
				else if (lauta[sar][riv] == ml) {
					musta_mid -= (826 + mid_bonus);
					musta_end -= (826 + end_bonus);
					non_pawn += 826;
				}
				else if (lauta[sar][riv] == vr) {
					valk_mid += (764 + mid_bonus);
					valk_end += (764 + end_bonus);
					non_pawn += 764;
				}
				else if (lauta[sar][riv] == mr) {
					musta_mid -= (764 + mid_bonus);
					musta_end -= (764 + end_bonus);
					non_pawn += 764;
				}
				else if (lauta[sar][riv] == vd) {
					valk_mid += (2526 + mid_bonus);
					valk_end += (2526 + end_bonus);
					non_pawn += 2526;
				}
				else if (lauta[sar][riv] == md) {
					musta_mid -= (2526 + mid_bonus);
					musta_end -= (2526 + end_bonus);
					non_pawn += 2526;
				}
				else if (lauta[sar][riv] == vk) {
					valk_mid += mid_bonus;
					valk_end += end_bonus;
				}
				else if (lauta[sar][riv] == mk) {
					musta_mid -= mid_bonus;
					musta_end -= end_bonus;
				}
			}
		}
	}
	mid = valk_mid + musta_mid;
	end = valk_end + musta_end;

	if (mg_limit < non_pawn) {
		non_pawn = mg_limit;
	}
	if (eg_limit > non_pawn) {
		non_pawn = eg_limit;
	}
	phase = (non_pawn-eg_limit)/(mg_limit-eg_limit);

}

void Asema::wpc_bpc_wnpm_b_npm_wb_bb_kings(int & wPawnCount, int &bPawnCount, int &wNonPawnMat, int &bNonPawnMat, int& wBishops, int& bBishops, int& wk_x, int& wk_y, int& bk_x, int& bk_y)
{
	wPawnCount = 0; //white pawn count
	bPawnCount = 0;
	wNonPawnMat = 0; //white nonpawn material
	bNonPawnMat = 0;
	wBishops = 0;
	bBishops = 0;

	for (int sar = 0; sar < 8; sar++) {
		for (int riv = 0; riv < 8; riv++) {
			if (lauta[sar][riv] != NULL) {
				if (lauta[sar][riv] == vs) {
					wPawnCount++;
				}
				else if (lauta[sar][riv] == ms) {
					bPawnCount++;
				}
				else if (lauta[sar][riv] == vt) {
					wNonPawnMat += 1282;
				}
				else if (lauta[sar][riv] == mt) {
					bNonPawnMat += 1282;
				}
				else if (lauta[sar][riv] == vl) {
					wNonPawnMat += 826;
					wBishops++;
				}
				else if (lauta[sar][riv] == ml) {
					bNonPawnMat += 826;
					bBishops++;
				}
				else if (lauta[sar][riv] == vr) {
					wNonPawnMat += 764;
				}
				else if (lauta[sar][riv] == mr) {
					bNonPawnMat += 764;
				}
				else if (lauta[sar][riv] == vd) {
					wNonPawnMat += 2526;
				}
				else if (lauta[sar][riv] == md) {
					bNonPawnMat += 2526;
				}
				else if (lauta[sar][riv] == vk) {
					wk_x = sar;
					wk_y = riv;
				}
				else if (lauta[sar][riv] == mk) {
					bk_x = sar;
					bk_y = riv;
				}
			}
		}
	}

}

bool Asema::oppositeBishops()
{
	bool yksLoytynyt=false;
	int wBis = 0;
	int bBis = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (lauta[i][j] == vl) {
				wBis = (i + j) % 2;
				if (yksLoytynyt) {
					j = 7;
				}
				else {
					yksLoytynyt = true;
				}
			}
			if (lauta[i][j] == ml) {
				bBis = (i + j) % 2;
				if (yksLoytynyt) {
					j = 7;
				}
				else {
					yksLoytynyt = true;
				}
			}
		}
		if (yksLoytynyt) {
			i = 7;
		}
	}

	return false;
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

	MinMaxPaluu mm;
	mm.evaluointiArvo = -1000000;

	list<Siirto> siirrot;
	//vector<future<MinMaxPaluu>>minmaxit;
	annaLaillisetSiirrot(siirrot);
	siirrot = tarkistaSiirrot(siirrot);
	

	Ruutu nolla(0, 0);
	Siirto dummy(nolla, nolla);
	mm.parasSiirto = dummy;

	if (syvyys >0) {
		/*for each (auto a in siirrot) {
			Asema as = *this;
			as.paivitaAsema(&a);
			minmaxit.push_back(async(launch::async, &Asema::mini, as, syvyys - 1));
		}
		for (int i = 0; i < siirrot.size();i++) {
			Siirto s = *siirrot.begin();
			MinMaxPaluu temp;
			minmaxit.at(i).wait();
			temp = minmaxit.at(i).get();
			temp.parasSiirto = s;
			if (temp.evaluointiArvo > mm.evaluointiArvo) {
				mm = temp;
			}
			siirrot.pop_front();
		}*/
		for each(auto a in siirrot) {
			MinMaxPaluu temp;
			Asema as = *this;
			as.paivitaAsema(&a);
			temp = as.mini(syvyys - 1);
			temp.parasSiirto = a;
			if (temp.evaluointiArvo > mm.evaluointiArvo) {
				mm.evaluointiArvo = temp.evaluointiArvo;
				mm.parasSiirto = temp.parasSiirto;
			}
		}
	}

	if (syvyys == 0) {
		mm.parasSiirto = dummy;
		if (siirrot.size() == 0) {
			if (onkoMatti()) {
				mm.evaluointiArvo = -1000000;

			}
			else {
				mm.evaluointiArvo = 0;
			}
		}
		else {
			mm.evaluointiArvo = evaluoi();
		}

	}

	return mm;
}

MinMaxPaluu Asema::mini(int syvyys)
{
	MinMaxPaluu mm;
	mm.evaluointiArvo = 1000000;

	list<Siirto> siirrot;
	//vector<future<MinMaxPaluu>>minmaxit;
	annaLaillisetSiirrot(siirrot);
	siirrot = tarkistaSiirrot(siirrot);


	Ruutu nolla(0, 0);
	Siirto dummy(nolla, nolla);
	mm.parasSiirto = dummy;

	if (syvyys > 0) {
		/*for each (auto a in siirrot) {
			Asema as = *this;
			as.paivitaAsema(&a);
			minmaxit.push_back(async(launch::async, &Asema::maxi, as, syvyys - 1));
		}
		for (int i = 0; i < siirrot.size();i++) {
			Siirto s = *siirrot.begin();
			MinMaxPaluu temp;
			minmaxit.at(i).wait();
			temp = minmaxit.at(i).get();
			temp.parasSiirto = s;
			if (temp.evaluointiArvo < mm.evaluointiArvo) {
				mm = temp;
			}
			siirrot.pop_front();
		}*/
	
		for each(auto a in siirrot) {
			MinMaxPaluu temp;
			Asema as = *this;
			as.paivitaAsema(&a);
			temp = as.maxi(syvyys - 1);
			temp.parasSiirto = a;
			if (temp.evaluointiArvo < mm.evaluointiArvo) {
				mm.evaluointiArvo = temp.evaluointiArvo;
				mm.parasSiirto = temp.parasSiirto;
			}
		}
	}

	if (syvyys == 0) {
		mm.parasSiirto = dummy;
		if (siirrot.size() == 0) {
			if (onkoMatti()) {
				mm.evaluointiArvo = 1000000;

			}
			else {
				mm.evaluointiArvo = 0;
			}
		}
		else {
			mm.evaluointiArvo = evaluoi();
		}
	}

	return mm;
}

