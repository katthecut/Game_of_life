#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class game_of_life
{
private:
    static const unsigned int STUPACA = 40;
    static const unsigned int REDAKA = 20;

    bool _generacija[REDAKA][STUPACA];
    bool _sljedeca_generacija[REDAKA][STUPACA];
    int _starost[REDAKA][STUPACA];

    bool slucajna_vrijednost();
    bool celija_zauzeta(int i, int j);
    int broj_susjeda(int i, int j);

public:
    game_of_life();

    void sljedeca_generacija();

    void iscrtaj(sf::RenderWindow& window);
};

#endif