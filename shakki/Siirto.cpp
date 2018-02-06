#pragma once
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

bool Siirto::onkoPitkalinna()
{
	return pitkalinna;
}

bool Siirto::operator==(const Siirto & rhs)
{
	Siirto s = rhs;
	if (this->onkoLyhytLinna() && s.onkoLyhytLinna()) {
		return true;
	}
	else if (this->onkoPitkalinna() && s.onkoPitkalinna()) {
		return true;
	}
	else if (this->alkuRuutu.getRivi()==s.alkuRuutu.getRivi() && this->alkuRuutu.getSarake() == s.alkuRuutu.getSarake() &&
		this->loppuRuutu.getRivi() == s.loppuRuutu.getRivi() && this->loppuRuutu.getSarake() == s.loppuRuutu.getSarake()) {
		return true;
	}
	return false;
}

