#include "game_of_life.h"

game_of_life::game_of_life()
{
    srand(time(0));

    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

bool game_of_life::slucajna_vrijednost()
{
    int x = rand() % 100;

    if (x < 25)
    {
        return true;
    }

    return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
    if (i < 0 || j < 0 || i >= REDAKA || j >= STUPACA)
    {
        return false;
    }

    return _generacija[i][j];
}

void game_of_life::sljedeca_generacija()
{
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            int broj_susjeda = 0;

            if (celija_zauzeta(i - 1, j - 1)) broj_susjeda++;
            if (celija_zauzeta(i - 1, j)) broj_susjeda++;
            if (celija_zauzeta(i - 1, j + 1)) broj_susjeda++;
            if (celija_zauzeta(i, j - 1)) broj_susjeda++;
            if (celija_zauzeta(i, j + 1)) broj_susjeda++;
            if (celija_zauzeta(i + 1, j - 1)) broj_susjeda++;
            if (celija_zauzeta(i + 1, j)) broj_susjeda++;
            if (celija_zauzeta(i + 1, j + 1)) broj_susjeda++;

            if (_generacija[i][j])
            {
                if (broj_susjeda == 2 || broj_susjeda == 3)
                {
                    _sljedeca_generacija[i][j] = true;
                }
                else
                {
                    _sljedeca_generacija[i][j] = false;
                }
            }
            else
            {
                if (broj_susjeda == 3)
                {
                    _sljedeca_generacija[i][j] = true;
                }
                else
                {
                    _sljedeca_generacija[i][j] = false;
                }
            }
        }
    }

    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::iscrtaj(sf::RenderWindow& window)
{
    int velicina = 20;

    sf::RectangleShape celija(
        sf::Vector2f(velicina - 1, velicina - 1)
    );

    celija.setFillColor(sf::Color::White);

    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            if (_generacija[i][j])
            {
                celija.setPosition(j * velicina, i * velicina);

                window.draw(celija);
            }
        }
    }
}