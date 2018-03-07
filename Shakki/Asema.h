#pragma once
#include "Nappula.h"
#include <list>
#include "MinMaxPaluu.h"


class Asema {

private:
	static Nappula *vk;
	static Nappula* vd;
	static Nappula* vt;
	static Nappula* vl;
	static Nappula* vr;
	static Nappula* vs;
	static Nappula* mk;
	static Nappula* md;
	static Nappula* mt;
	static Nappula* ml;
	static Nappula* mr;
	static Nappula* ms;

	int siirtovuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTliikkunut;
	bool onkoValkeaKTliikkunut;
	bool onkoMustaDTliikkunut;
	bool onkoMustaKTliikkunut;
	Nappula* getNappula(int);


public:
	Asema();
	Nappula* lauta[8][8];
	int enPassee[2];

	void paivitaAsema(Siirto* siirto);
	int getSiirtovuoro();
	void setSiirtovuoro(int vari);
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaDTliikkunut();
	bool getOnkoMustaKTliikkunut();
	void annaLaillisetSiirrot(std::list<Siirto>& lista);
	Ruutu kuninkaanSijainti();
	bool onkoShakki();
	std::list<Siirto> tarkistaSiirrot(std::list<Siirto>& siirrot);
	int evaluoi();
	void skaalain(int&, int& paluu);
	void mg_eg_phase_evaluaatio(int&, int&, int&);
	void evaluoiSotilaat(string &bb, int &mgSotilaat, int &egSotilaat);
	bool sotilasEristyksissa(int &i, string &bb, int vari);
	bool sotilasTakaperin(int &i, string &bb, int vari);
	bool sotilaatJonossa(int &i, string &bb, int vari);
	void sotilaanTuki(int &i, string &bb, int vari, bool &tuki, bool &rivissa, bool &vastassa);
	void sotilasAsemaBonus(int &i, string &bb, int vari, int &midGame, int &endGame);
	void wpc_bpc_wnpm_b_npm_wb_bb_kings(int&, int&, int&, int&, int&, int&,int&,int&,int&,int&);
	int mob_bonus(int nappula, int sar, int riv, int mgeg);
	bool oppositeBishops();
	Siirto parasSiirto(int syvyys);
	int alfaBeta(Siirto &s, int syvyys, bool ylin, int alfa, int beta, bool maxing);
	MinMaxPaluu maxi(int syvyys);//kutsutaan valkoisen vuorolla
	MinMaxPaluu mini(int syvyys);//kutsutaan mustan vuorolla;

};
