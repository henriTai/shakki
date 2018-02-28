#pragma once
#include "Asema.h"
#include "Siirto.h"
#include <string>

using namespace std;

class Kayttoliittyma {
private:
	void taustavari(int x, int y);
	bool oikeaMuoto(string);

public:
	Kayttoliittyma(Asema* asema);
	Asema* asema;
	void piirraLauta();
	Siirto annaVastustajanSiirto(int pelaaja);
	void tulostaSiirto(Siirto s, int vuoro);
	int valitsePuoli();
	int valitseSyvyys();
	bool aloitusKirjasto();
	int muunnaKirjain(string, int);
	void matti();
	void shakki();
	void patti();
	void keskipeliin();
	void virheTietokannassa();
};

