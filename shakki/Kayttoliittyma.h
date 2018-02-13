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
	Siirto annaVastustajanSiirto();
	int muunnaKirjain(string, int);
	void Matti();
	void Shakki();
};

