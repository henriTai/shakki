#pragma once
#include <tchar.h>
#include "Kayttoliittyma.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

void Kayttoliittyma::taustavari(int x, int y)
{
	if (x % 2 == 0) {
		if (y % 2 == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN);
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN | BACKGROUND_BLUE);
		}
	}
	else {
		if (y % 2 == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN | BACKGROUND_BLUE);
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
				BACKGROUND_GREEN);
		}
	}
}

Kayttoliittyma::Kayttoliittyma(Asema * asema)
{
	this->asema = asema;
}

void Kayttoliittyma::piirraLauta()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	for (int i = 7;i >= 0;i--) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_GREEN 
			|BACKGROUND_BLUE);
		wcout << " " << i + 1 << " ";
		for(int j = 0; j < 8; j++) {
			taustavari(j, i);
			if (asema->lauta[j][i] == NULL) {
				wcout << "   ";
			}
			else {
				//wcout << " n ";
				wcout << " " << asema->lauta[j][i]->getUnicode() << " ";
			}
		}
		wcout << endl;
	}
	wcout << "    a  b  c  d  e  f  g  h " << endl;

}

Siirto Kayttoliittyma::annaVastustajanSiirto()
{
	Siirto siirto;
	string vastaus="";
	bool annettu = false;

	while (!annettu) {
		wcout << "Anna vastustajan siirto: ";
		cin >> vastaus;

		if (vastaus == "O-O"||vastaus=="o-o") {
			siirto = Siirto(true, false);
			annettu = true;
			continue;
		}

		if (vastaus == "O-O-O" || vastaus == "o-o-o") {
			siirto = Siirto(false, true);
			annettu = true;
			continue;
		}

		if (!oikeaMuoto(vastaus)) {
			continue;
		}

		int a_rivi = (int)vastaus.at(2) - 49; //49, koska inputtina annettu 1 on koneelle 0
		int a_sar = muunnaKirjain(vastaus, 1);
		int l_rivi = (int)vastaus.at(5) - 49;
		int l_sar = muunnaKirjain(vastaus, 4);

		Ruutu alku = Ruutu(a_rivi, a_sar);
		Ruutu loppu = Ruutu(l_rivi, l_sar);

		if (vastaus.length() == 6) {

			siirto = Siirto(alku, loppu);
		}
		else if (vastaus.length() == 7) {
			char c = vastaus.at(6);
			siirto = Siirto(alku, loppu, c);
		}
		annettu = true;

	}
	// Rg1-f3
	return siirto;
}

bool Kayttoliittyma::oikeaMuoto(string v) {

	if (v.length() != 6 && v.length() !=7) {
		return false;
	}
	char a = v.at(0);
	if (a !='K'&& a != 'D' && a != 'T' && a != 'L' && a != 'R' && a != 'S') {
		return false;
	}

	a = v.at(1);

	if (a != 'a' && a != 'b' && a != 'c' && a != 'd' && a != 'e' && a != 'f' && a != 'g' && a != 'h') {

		return false;
	}

	a = v.at(2);

	if (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8') {

		return false;
	}

	a = v.at(3);

	if (a != '-') {

		return false;

	}

	a = v.at(4);

	if (a != 'a' && a != 'b' && a != 'c' && a != 'd' && a != 'e' && a != 'f' && a != 'g' && a != 'h') {

		return false;
	}

	a = v.at(5);

	if (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8') {

		return false;
	}

	if (v.length() == 7) {
		a = v.at(6);
		if (a != 'T'&&a != 'L'&&a != 'R'&&a != 'D') {
			return false;
		}
	}

	return true;
}

int Kayttoliittyma::muunnaKirjain(string s, int a) {

	int paluu;

	if (s.at(a) == 'a') {
		return 0;
	}
	else if (s.at(a) == 'b') {
		return 1;
	}
	else if (s.at(a) == 'c') {
		return 2;
	}
	else if (s.at(a) == 'd') {
		return 3;
	}
	else if (s.at(a) == 'e') {
		return 4;
	}
	else if (s.at(a) == 'f') {
		return 5;
	}
	else if (s.at(a) == 'g') {
		return 6;
	}
	else if (s.at(a) == 'h') {
		return 7;
	}
	else {
		return -1;
	}



}

void Kayttoliittyma::Matti()
{
	wcout << "Matti" << endl;
}

void Kayttoliittyma::Shakki()
{
	wcout << "Shakki" << endl;
}

