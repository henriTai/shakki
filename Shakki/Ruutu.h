#pragma once

class Ruutu {
public:
	Ruutu(int rivi, int sarake);
	Ruutu() {}
	int getRivi();
	int getSarake();
private:
	int sarake;
	int rivi;
};
