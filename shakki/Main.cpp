#include "Kayttoliittyma.h"
#include "Asema.h"
#include "Nappula.h"
#include "Ruutu.h"
#include "Siirto.h"

int main() {
	Asema asema;
	Kayttoliittyma* k = new Kayttoliittyma(&asema);
	k->piirraLauta();
	while (true) {
		Siirto* siirto = new Siirto(k->annaVastustajanSiirto());
		asema.paivitaAsema(siirto);
		k->piirraLauta();
	}



	while (true)
	{

	}
	return 0;
}