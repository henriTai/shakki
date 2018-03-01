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
	bool onkoMatti();
	std::list<Siirto> tarkistaSiirrot(std::list<Siirto>& siirrot);
	double evaluoi();
	void skaalain(int&, int& paluu);
	void mg_eg_phase_evaluaatio(int&, int&, int&);
	void wpc_bpc_wnpm_b_npm_wb_bb_kings(int&, int&, int&, int&, int&, int&,int&,int&,int&,int&);
	bool oppositeBishops();
	Siirto parasSiirto(int syvyys);
	MinMaxPaluu maxi(int syvyys);//kutsutaan valkoisen vuorolla
	MinMaxPaluu mini(int syvyys);//kutsutaan mustan vuorolla;

};
