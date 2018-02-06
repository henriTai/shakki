#pragma once
#include "Ruutu.h"

Ruutu::Ruutu(int rivi, int sarake)
{
	this->rivi = rivi;
	this->sarake = sarake;
}

int Ruutu::getRivi()
{
	return rivi;
}

int Ruutu::getSarake()
{
	return sarake;
}
