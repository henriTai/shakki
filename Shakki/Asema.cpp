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
	else {
		return NULL;
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

bool Asema::onkoShakki()
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

int Asema::evaluoi()
{
	int mg;
	int eg;
	int vaihe;
	double paluu = 1;
	mg_eg_phase_evaluaatio(mg, eg, vaihe);
	int skaalaaja;
	skaalain(eg, skaalaaja);
	eg = eg*skaalaaja / 64;
	if (mg*vaihe + eg*(128 - vaihe) != 0) {
		return paluu*(mg*vaihe + eg*(128 - vaihe)) / 128;
		return mg;
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
	string bitboard = "0000000000000000000000000000000000000000000000000000000000000000";
	
	int musta_mid = 0;
	int musta_end = 0;
	int valk_mid = 0;
	int valk_end = 0;

	int mgSotilaat = 0;
	int egSotilaat = 0;

	int mg_limit = 15258;
	int eg_limit = 3915;
	int non_pawn_w = 0;
	int non_pawn_b = 0;
	int non_pawn = 0;

	int mgmob_v = 0;
	int mgmob_m = 0;
	int egmob_v = 0;
	int egmob_m = 0;


	int ind_mk=0;
	int ind_vk=0;


	for (int sar = 0; sar < 8; sar++) {
		for (int riv = 0; riv < 8; riv++) {
			if (lauta[sar][riv] != NULL) {
				int mid_bonus = lauta[sar][riv]->positioBonus(sar, riv, 0);
				int end_bonus = lauta[sar][riv]->positioBonus(sar, riv, 1);
				if (lauta[sar][riv] == vs) {
					valk_mid += (171 + mid_bonus);
					valk_end += (240 + end_bonus);
					bitboard.at(riv * 8 + sar) = 'S';
				}
				else if (lauta[sar][riv] == ms) {
					musta_mid -= (171+mid_bonus);
					musta_end -= (240 + end_bonus);
					bitboard.at(riv * 8 + sar) = 's';
				}
				else if (lauta[sar][riv] == vt) {
					valk_mid += (1282 + mid_bonus);
					valk_end += (1373 + end_bonus);
					non_pawn_w += 1282;
					bitboard.at(riv * 8 + sar) = 'T';
					mgmob_v += mob_bonus(VT, sar, riv, 0);
					egmob_v += mob_bonus(VT, sar, riv, 1);
				}
				else if (lauta[sar][riv] == mt) {
					musta_mid -= (1282 + mid_bonus);
					musta_end -= (1373 + end_bonus);
					non_pawn_b += 1282;
					bitboard.at(riv * 8 + sar) = 't';
					mgmob_m += mob_bonus(MT, sar, riv, 0);
					egmob_m += mob_bonus(MT, sar, riv, 1);
				}
				else if (lauta[sar][riv] == vl) {
					valk_mid += (826 + mid_bonus);
					valk_end += (891 + end_bonus);
					non_pawn_w += 826;
					bitboard.at(riv * 8 + sar) = 'L';
					mgmob_v += mob_bonus(VL, sar, riv, 0);
					egmob_v += mob_bonus(VL, sar, riv, 1);
				}
				else if (lauta[sar][riv] == ml) {
					musta_mid -= (826 + mid_bonus);
					musta_end -= (891 + end_bonus);
					non_pawn_b += 826;
					bitboard.at(riv * 8 + sar) = 'l';
					mgmob_m += mob_bonus(ML, sar, riv, 0);
					egmob_m += mob_bonus(ML, sar, riv, 1);
				}
				else if (lauta[sar][riv] == vr) {
					valk_mid += (764 + mid_bonus);
					valk_end += (848 + end_bonus);
					non_pawn_w += 764;
					bitboard.at(riv * 8 + sar) = 'R';
					mgmob_v += mob_bonus(VR, sar, riv, 0);
					egmob_v += mob_bonus(VR, sar, riv, 1);
				}
				else if (lauta[sar][riv] == mr) {
					musta_mid -= (764 + mid_bonus);
					musta_end -= (848 + end_bonus);
					non_pawn_b += 764;
					bitboard.at(riv * 8 + sar) = 'r';
					mgmob_m += mob_bonus(MR, sar, riv, 0);
					egmob_m += mob_bonus(MR, sar, riv, 1);
				}
				else if (lauta[sar][riv] == vd) {
					valk_mid += (2526 + mid_bonus);
					valk_end += (2646 + end_bonus);
					non_pawn_w += 2526;
					bitboard.at(riv * 8 + sar) = 'D';
					mgmob_v += mob_bonus(VD, sar, riv, 0);
					egmob_v += mob_bonus(VD, sar, riv, 1);
				}
				else if (lauta[sar][riv] == md) {
					musta_mid -= (2526 + mid_bonus);
					musta_end -= (2646 + end_bonus);
					non_pawn_b += 2526;
					bitboard.at(riv * 8 + sar) = 'd';
					mgmob_m += mob_bonus(MD, sar, riv, 0);
					egmob_m += mob_bonus(MD, sar, riv, 1);
				}
				else if (lauta[sar][riv] == vk) {
					valk_mid += mid_bonus;
					valk_end += end_bonus;
					bitboard.at(riv * 8 + sar) = 'K';
					ind_vk = riv * 8 + sar;
				}
				else if (lauta[sar][riv] == mk) {
					musta_mid -= mid_bonus;
					musta_end -= end_bonus;
					bitboard.at(riv * 8 + sar) = 'k';
					ind_mk = riv * 8 + sar;
				}
			}
		}
	}
	evaluoiSotilaat(bitboard, mgSotilaat, egSotilaat);


	int mob_mg = mgmob_v - mgmob_m;
	
	mid = valk_mid + musta_mid + mgSotilaat + mgmob_v - mgmob_m;
	end = valk_end + musta_end + egSotilaat + egmob_v - egmob_m;

	//vaihe
	non_pawn = non_pawn_w + non_pawn_b;

	if (mg_limit < non_pawn) {
		non_pawn = mg_limit;
	}
	if (eg_limit > non_pawn) {
		non_pawn = eg_limit;
	}
	phase = ((non_pawn - eg_limit)*128)/(mg_limit - eg_limit);

}



void Asema::evaluoiSotilaat(string & bb, int & mgSotilaat, int & egSotilaat)
{
	int mg_e = 0;
	int eg_e = 0;
	for (int i = 0; i < bb.length(); i++) {
		if (bb.at(i) == 'S') {
			if (sotilasEristyksissa(i, bb, 0)) {
				mg_e -= 13;
				eg_e -= 18;
			}
			else {
				if (sotilasTakaperin(i, bb, 0)) {
					mg_e -= 24;
					eg_e -= 12;
				}
			}
			if (sotilaatJonossa(i, bb, 0)) {
				mg_e -= 18;
				eg_e -= 38;
			}
			sotilasAsemaBonus(i, bb, 0, mg_e, eg_e);
		}
		else if (bb.at(i) == 's') {
			if (sotilasEristyksissa(i, bb, 1)) {
				mg_e += 13;
				eg_e += 18;
			}
			else {
				if (sotilasTakaperin(i, bb, 1)) {
					mg_e += 24;
					eg_e += 12;
				}
			}
			if (sotilaatJonossa(i, bb, 1)) {
				mg_e += 18;
				eg_e += 38;
			}
			sotilasAsemaBonus(i, bb, 1, mg_e, eg_e);
		}
	}
	mgSotilaat = mg_e;
	egSotilaat = eg_e;
}

bool Asema::sotilasEristyksissa(int& i, string & bb, int vari)
{
	if (vari == 0) {
		//ei rivin eka
		if (i % 8 != 0) {
			int vasen = i - 1;
			while (vasen < bb.length()) {
				if (bb.at(vasen) == 'S') {
					return false;
				}
				vasen += 8;
			}
		}//ei rivin vika
		if (i % 8 != 7) {
			int oikea = i + 1;
			while (oikea < bb.length()) {
				if (bb.at(oikea) == 'S') {
					return false;
				}
				oikea += 8;
			}
		}
	}
	else {
		//ei rivin eka
		if (i % 8 != 0) {
			int vasen = i - 1;
			while (vasen > 0) {
				if (bb.at(vasen) == 's') {
					return false;
				}
				vasen -= 8;
			}
		}//ei rivin vika
		if (i % 8 != 7) {
			int oikea = i + 1;
			while (oikea > 0) {
				if (bb.at(oikea) == 's') {
					return false;
				}
				oikea -= 8;
			}
		}
	}
	return true;
}

bool Asema::sotilasTakaperin(int & i, string & bb, int vari)
{
	if (vari == 0) {
		//
		if (i / 8 >= 4) {
			return false;
		}
		if (i % 8 != 0) {
			if (bb.at(i - 9) == 's') {
				return false;
			}
		}
		if (i % 8 != 7) {
			if (bb.at(i - 7) == 's') {
				return false;
			}
		}
		int rivi = 7;
		for (int y = 0;y < 8;y++) {
			if (i % 8 != 0) {
				if (bb.at(i - 1) == 'S') {
					rivi = y;
				}
			}
			else if (i % 8 != 7) {
				if (bb.at(i + 1) == 'S') {
					rivi = y;
				}
			}
			else if (y < i / 8) {
				if (i % 8 != 0 && (y * 8 + (i % 8) - 1 > 0)) {
					if (bb.at(y * 8 + (i % 8) - 1) == 's') rivi = y;
				}
				else if (bb.at(y * 8 + (i % 8)) == 's') {
					rivi = y;
				}
				else if (i % 8 != 7) {
					if (bb.at(y * 8 + (i % 8) + 1) == 's') {
						rivi = y;
					}
				}
			}
		}
		if (rivi >= i / 8) {
			return false;
		}
		if (i % 8 != 0 && ((rivi * 8 + (i % 8) - 1) > 0)) {
			if (bb.at(rivi * 8 + (i % 8) - 1) == 'S') {
				return true;
			}
			if (bb.at(rivi * 8 + (i % 8) == 'S')) return true;
			if (i % 8 != 7) {
				if (bb.at(rivi * 8 + (i % 8) + 1) == 'S') return true;
			}
		}
	}
	else {
		if (i / 8 <= 3) {
			return false;
		}
		if (i % 8 != 0) {
			if (bb.at(i + 7) == 'S') {
				return false;
			}
		}
		if (i % 8 != 7) {
			if (bb.at(i + 9) == 'S') {
				return false;
			}
		}
		int rivi = 0;
		for (int y = 7; y >= 0; y--) {
			if (i % 8 != 0) {
				if (bb.at(i - 1) == 's') {
					rivi = y;
				}
			}
			else if (i % 8 != 7) {
				if (bb.at(i + 1) == 's') {
					rivi = y;
				}
			}
			else if (y > i / 8) {
				if (i % 8 != 0 && ((y * 8 + (i % 8) - 1) < bb.length())) {
					if (bb.at(y * 8 + (i % 8) - 1) == 'S') rivi = y;
				}
				else if (bb.at(y * 8 + (i % 8)) == 'S') {
					rivi = y;
				}
				else if (i % 8 != 7 && (bb.at(y * 8 + (i % 8) + 1) < bb.length())) {
					if (bb.at(y * 8 + (i % 8) + 1) == 'S') {
						rivi = y;
					}
				}
			}
		}
		if (rivi <= i / 8) {
			return false;
		}
		if (i % 8 != 0) {
			if (bb.at(rivi * 8 + (i % 8) - 1) == 's') {
				return true;
			}
			if (bb.at(rivi * 8 + (i % 8) == 's')) return true;
			if (i % 8 != 7) {
				if ((rivi * 8 + (i % 8) + 1) < bb.length()) {
					if (bb.at(rivi * 8 + (i % 8) + 1) == 's') return true;
				}
			}
		}
	}
	return false;
}

bool Asema::sotilaatJonossa(int & i, string & bb, int vari)
{
	if (vari == 0) {
		if (bb.at(i + 8) != 'S') {
			return false;
		}
		if (i % 8 != 0) {
			if (bb.at(i + 7) == 'S') {
				return false;
			}
		}
		if (i % 8 != 7) {
			if (bb.at(i + 9) == 'S') {
				return false;
			}
		}
	}
	else {
		if (bb.at(i - 8) != 's') {
			return false;
		}
		if (i % 8 != 0) {
			if (bb.at(i - 9) == 's') {
				return false;
			}
		}
		if (i % 8 != 7) {
			if (bb.at(i - 7) == 's') {
				return false;
			}
		}
	}
	return true;
}

void Asema::sotilaanTuki(int & i, string & bb, int vari, bool &tuettu, bool &rivissa, bool &vastassa)
{
	if (i % 8 != 0) {
		if (vari == 0) {
			if (bb.at(i + 7) == 'S') {
				tuettu=true;
			}
			if (bb.at(i - 1) == 'S') {
				rivissa=true;
			}
		}
		else {
			if (bb.at(i - 9) == 's') {
				tuettu=true;
			}
			if (bb.at(i - 1) == 's') {
				rivissa=true;
			}
		}
	}
	if (i % 8 != 7) {
		if (vari == 0) {
			if (bb.at(i + 9) == 'S') {
				tuettu=true;
			}
			if (bb.at(i + 1) == 'S') {
				rivissa=true;
			}
		}
		else {
			if (bb.at(i - 7) == 's') {
				tuettu=true;
			}
			if (bb.at(i + 1) == 's') {
				rivissa=true;
			}
		}
	}
	if (vari == 0) {
		int toinen = i + 8;
		while (toinen < bb.length()) {
			if (bb.at(toinen) == 's') {
				vastassa = true;
				break;
			}
			toinen += 8;
		}
	}
	else {
		int toinen = i - 8;
		while (toinen >= 0) {
			if (bb.at(toinen) == 'S') {
				vastassa = true;
				break;
			}

			toinen -= 8;
		}
	}
}

void Asema::sotilasAsemaBonus(int & i, string & bb, int vari, int &midGame, int &endGame)
{
	bool tuettu = false;
	bool rivissa = false;
	bool vastassa = false;
	sotilaanTuki(i, bb, vari, tuettu, rivissa, vastassa);
	if (!tuettu && !rivissa) {
		return;
	}
	int rivi;
	if (vari == 0) {
		rivi = i / 8;
	}
	else {
		rivi = 7 - i / 8;
	}
	int r1 = 0;
	int r2 = 0;
	if (rivi == 1) {
		r1 = 13;
	}
	else if (rivi == 2) {
		r1 = 24;
		r2 = 13;
	}
	else if (rivi == 3) {
		r1 = 18;
		r2 = 24;
	}
	else if (rivi == 4) {
		r1 = 76;
		r2 = 18;
	}
	else if (rivi == 5) {
		r1 = 100;
		r2 = 76;
	}
	else if (rivi == 6) {
		r1 = 175;
		r2 = 100;
	}
	else if (rivi == 7) {
		r1 = 330;
		r2 = 175;
	}
	int bonus = r2;
	if (rivissa) {
		bonus += ((r1 - r2) / 2);
	}
	if (vastassa) {
		bonus = bonus / 2;
	}
	if (tuettu) {
		bonus += 17;
	}
	if (vari == 0) {
		midGame += bonus;
		endGame += (bonus*(rivi + 1) / 4);
	}
	else {
		midGame -= bonus;
		endGame -= (bonus*(rivi + 1) / 4);
	}

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

int Asema::mob_bonus(int nappula, int sar, int riv, int mgeg)
{
	list <Siirto> lista;
	Ruutu r(riv, sar);
	Asema as = *this;
	if (getSiirtovuoro() == 0) {
		as.setSiirtovuoro(1);
	}
	else {
		as.setSiirtovuoro(0);
	}
	as.lauta[sar][riv]->annaSiirrot(lista, &r, this, siirtovuoro);
	int ind;
	if (lista.empty()) {
		ind = 0;
	}
	else {
		ind = lista.size();
	}
	int mob;
	if ((nappula == VR || nappula == MR )) {

		if (mgeg == 0) {
			int taulukko[9] = { -75,-57,-9,-2,6,14,22,29,36 };
			mob = taulukko[ind];
		}
		else {
			int taulukko[9] = { -76,-54,-28,-10,5,12,26,29,29 };
			mob = taulukko[ind];
		}

	}
	else if (nappula == VL || nappula == ML) {
		if (mgeg == 0) {
			int taulukko[14] = { -48,-20,16,26,38,51,55,63,63,68,81,81,91,98 };
			mob = taulukko[ind];
		}
		else {
			int taulukko[14] = { -59,-23,-3,13,24,42,54,57,65,73,78,86,88,97 };
			mob = taulukko[ind];
		}
	}
	else if (nappula == VT || nappula == MT) {
		if (mgeg == 0) {
			int taulukko[15] = { -58,-27,-15,-10,-5,-2,9,16,30,29,32,38,46,48,58 };
			mob = taulukko[ind];
		}
		else {
			int taulukko[15] = { -76,-18,28,55,69,82,112,118,132,142,155,165,166,169,171 };
			mob = taulukko[ind];
		}
	}
	else if (nappula == VD || nappula == MD) {
		if (mgeg == 0) {
			int taulukko[28] = { -39,-21,3,3,14,22,28,41,43,48,56,60,60,66,67,70,71,73,79,88,88,99,102,102,106,109,113,116 };
			mob = taulukko[ind];
		}
		else {
			int taulukko[28] = { -36,-15,8,18,34,54,61,73,79,92,94,104,113,120,123,126,133,136,140,143,148,166,170,175,184,191,206,212 };
			mob = taulukko[ind];
		}
	}
	return mob;
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
	/*
	MinMaxPaluu p;
	if (getSiirtovuoro()) {
		p = mini(syvyys);
	}
	else {
		p = maxi(syvyys);
	}
	return p.parasSiirto;
	*/
	
	int alfa = -1000000;
	int beta = 1000000;

	Ruutu nolla(0, 0);
	Siirto temppi(nolla, nolla);

	if (getSiirtovuoro()) {

		int paluu = alfaBeta(temppi, syvyys, syvyys, alfa, beta, false);
		return temppi;
	}
	else {

		int paluu = alfaBeta(temppi, syvyys, true, alfa, beta, true);
		return temppi;
	}
	
}

int Asema::alfaBeta(Siirto &paluuSiirto, int syvyys, bool ylin, int alfa, int beta, bool maxing)
{
	list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);
	siirrot = tarkistaSiirrot(siirrot);


	Ruutu nolla(0, 0);
	Siirto tehtySiirto(nolla, nolla);

	if (syvyys == 0) {
		if (maxing) {
			if (siirrot.size() == 0) {
				if (onkoShakki()) {
					return -1000000;

				}
				else {
					return 0;
				}
			}
			else {
				return evaluoi();
			}
		}
		else {
			if (siirrot.size() == 0) {
				if (onkoShakki()) {
					return 1000000;

				}
				else {
					return 0;
				}
			}
			else {
				return evaluoi();
			}
		}
	}
	else if (maxing) {
		int v = -1000000;
		if (ylin) tehtySiirto = *siirrot.begin();
		if (siirrot.size() == 0) {
			if (onkoShakki()) {
				return -1000000;

			}
			else {
				return 0;
			}
		}
		for each (auto a in siirrot) {
			Asema as = *this;
			as.paivitaAsema(&a);
			int paluu = as.alfaBeta(tehtySiirto, syvyys-1, false, alfa, beta, false);
			if (paluu > v) {
				v = paluu;
				tehtySiirto = a;
			}
			if (paluu > alfa) {
				alfa = paluu;
			}
			if (beta <= alfa) {//alf
				break;
			}
		}
		if (ylin) paluuSiirto = tehtySiirto;
		return v;
	}
	else {
		int v = 1000000;
		if (ylin) tehtySiirto = *siirrot.begin();
		if (siirrot.size() == 0) {
			if (onkoShakki()) {
				return 1000000;

			}
			else {
				return 0;
			}
		}
		for each (auto a in siirrot) {
			Asema as = *this;
			as.paivitaAsema(&a);
			int paluu = as.alfaBeta(tehtySiirto, syvyys-1, false, alfa, beta, true);
			if (paluu < v) {
				v = paluu;
				tehtySiirto = a;
			}
			if (paluu < beta) {
				beta = paluu;
			}
			if (beta <= alfa) {//beta
				break;
			}
		}
		if (ylin) paluuSiirto = tehtySiirto;
		return v;
	}

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
			if (onkoShakki()) {
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
			if (onkoShakki()) {
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

