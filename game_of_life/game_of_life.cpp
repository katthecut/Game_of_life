#include "game_of_life.h"
#include <cstdlib>
#include <ctime>

game_of_life::game_of_life() {
	srand(time(0));

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

bool game_of_life::slucajna_vrijednost() {
	int x = rand() % 100;
	if (x < 25) {
		return true;
	}
	else {
		return false;
	}
}

bool game_of_life::celija_zauzeta(int i, int j) {
	if (i < 0 || j < 0 || i >= REDAKA || j >= STUPACA) {
		return false;
	}
	if (_generacija[i][j] == true) {
		return true;
	}
	else {
		return false;
	}
}

void game_of_life::iscrtaj() {
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j] == true) {
				cout << "*";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}

void game_of_life::sljedeca_generacija() {
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {

			int broj_susjeda = 0;

			if (celija_zauzeta(i - 1, j - 1)) broj_susjeda++;
			if (celija_zauzeta(i - 1, j)) broj_susjeda++;
			if (celija_zauzeta(i - 1, j + 1)) broj_susjeda++;
			if (celija_zauzeta(i, j - 1)) broj_susjeda++;
			if (celija_zauzeta(i, j + 1)) broj_susjeda++;
			if (celija_zauzeta(i + 1, j - 1)) broj_susjeda++;
			if (celija_zauzeta(i + 1, j)) broj_susjeda++;
			if (celija_zauzeta(i + 1, j + 1)) broj_susjeda++;

			if (_generacija[i][j] == true) {
				if (broj_susjeda == 2 || broj_susjeda == 3) {
					_sljedeca_generacija[i][j] = true;
				}
				else {
					_sljedeca_generacija[i][j] = false;
				}
			}
			else {
				if (broj_susjeda == 3) {
					_sljedeca_generacija[i][j] = true;
				}
				else {
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}