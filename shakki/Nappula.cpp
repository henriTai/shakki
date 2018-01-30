#include "Nappula.h"
#include <string>

using namespace std;

Nappula::Nappula(wstring asema, int v, int k) {
	unicode = asema;
	vari = v;
	_koodi = k;

}


void Nappula::setKoodi(int koodi) {
	_koodi = koodi;
}

int Nappula::getKoodi() {
	return _koodi;
}

void Nappula::setUnicode(wstring asema) {
	unicode = asema;

}

std::wstring Nappula::getUnicode()
{
	return unicode;
}



void Nappula::setVari(int v) {
	vari = v;
}

int Nappula::getVari() {
	return vari;
}