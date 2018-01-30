#include "Siirto.h"
#include "Ruutu.h"

Siirto::Siirto(Ruutu alku, Ruutu loppu)
{
	alkuRuutu = alku;
	loppuRuutu = loppu;
	lyhytLinna = false; //default
	pitkalinna = false; //default
}

Siirto::Siirto(bool lyhytLinna, bool pitkaLinna)
{
	this->lyhytLinna = lyhytLinna;
	this->pitkalinna = pitkaLinna;
}

Ruutu Siirto::getAlkuruutu()
{
	return alkuRuutu;
}

Ruutu Siirto::getLoppuruutu()
{
	return loppuRuutu;
}

bool Siirto::onkoLyhytLinna()
{
	return lyhytLinna;
}

bool Siirto::onkoPitkälinna()
{
	return pitkalinna;
}
