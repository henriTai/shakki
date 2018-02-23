#pragma once
#include "Ruutu.h"

using namespace std;

class Siirto {
public:
	Siirto(Ruutu, Ruutu);
	Siirto(Ruutu, Ruutu, char);
	Siirto() {}
	Siirto(bool lyhytLinna, bool pitkaLinna); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkalinna();
	bool operator==(const Siirto& rhs);
	char korotus;

private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	bool lyhytLinna;
	bool pitkalinna;
};
