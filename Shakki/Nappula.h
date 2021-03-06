#pragma once
#include <string>
#include <list>
//#include "Asema.h"
#include "Siirto.h"

using namespace std;

static bool onLaudalla(int sarake, int rivi) {
	if (rivi < 0) return false;
	if (sarake < 0) return false;
	if (rivi > 7) return false;
	if (sarake > 7)return false;
	return true;
}

class Asema;

enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS,
};

class Nappula {

private:
	std::wstring unicode;
	int vari; // valkea = 0, musta = 1
	int _koodi; // VT, VR, MT tms.
	static int kSotilas[64];
	static int lSotilas[64];
	static int kRatsu[64];
	static int lRatsu[64];
	static int kLahetti[64];
	static int lLahetti[64];
	static int kTorni[64];
	static int lTorni[64];
	static int kDaami[64];
	static int lDaami[64];
	static int kKuningas[64];
	static int lKuningas[64];

public:
	Nappula(std::wstring, int, int);
	Nappula() {};

	virtual void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari) = 0;//<
	bool onkoRuutuListalla(std::list<Siirto>& vastustaja, int sarake, int rivi);
	int positioBonus(int sarake, int rivi, bool loppupeli);

	void setKoodi(int);
	int getKoodi();
	void setUnicode(std::wstring);
	std::wstring getUnicode();
	void setVari(int);
	int getVari();
};


class Torni : public virtual Nappula { // virtual = kantaluokka peritään moniperinnässä vain kerran!
public:
	Torni(std::wstring w, int a, int b) :Nappula(w, a, b) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);//<
};

class Ratsu : public Nappula {
public:
	Ratsu(std::wstring w, int a, int b) :Nappula(w, a, b) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);//<
};

class Lahetti : public virtual Nappula { // virtual = kantaluokka peritään moniperinnässä vain kerran!
public:
	Lahetti(std::wstring w, int a, int b) :Nappula(w, a, b) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);//<
};

class Daami : public Lahetti, public Torni { // Moniperintä!
public:
	Daami(std::wstring w, int a, int b) :Nappula(w, a, b), Lahetti(w, a, b), Torni(w, a, b) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);//<
};

class Kuningas : public Nappula {
public:
	Kuningas(std::wstring w, int a, int b) :Nappula(w, a, b) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);//<
};

class Sotilas : public Nappula {
public:
	Sotilas(std::wstring w, int a, int b):Nappula(w,a,b) {}
	void annaSiirrot(std::list<Siirto>& lista, Ruutu*, Asema*, int vari);//<
private:
	void lisaaSotilaanKorotukset(Siirto*, std::list<Siirto>& lista, Asema*);//<
};