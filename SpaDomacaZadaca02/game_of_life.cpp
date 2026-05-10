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

    //Grid
    sf::RectangleShape horizontalnaLinija(
        sf::Vector2f(800.f, 1.f)
    );

    horizontalnaLinija.setFillColor(
        sf::Color(236, 228, 214)
    );

    sf::RectangleShape vertikalnaLinija(
        sf::Vector2f(1.f, 400.f)
    );

    vertikalnaLinija.setFillColor(
        sf::Color(236, 228, 214)
    );

    // Horizontalne linije
    for (int i = 0; i <= REDAKA; i++)
    {
        horizontalnaLinija.setPosition(
            0,
            i * velicina
        );

        window.draw(horizontalnaLinija);
    }

    // Vertikalne linije
    for (int j = 0; j <= STUPACA; j++)
    {
        vertikalnaLinija.setPosition(
            j * velicina,
            0
        );

        window.draw(vertikalnaLinija);
    }

    //X oblik

    sf::RectangleShape linija1(sf::Vector2f(22.f, 4.f));
    sf::RectangleShape linija2(sf::Vector2f(22.f, 4.f));

    //da X bude u sredini (tj sredina linije)
    linija1.setOrigin(11.f, 2.f);
    linija2.setOrigin(11.f, 2.f);

    linija1.setRotation(45.f);
    linija2.setRotation(-45.f);

    linija1.setFillColor(sf::Color(195, 38, 95));
    linija2.setFillColor(sf::Color(195, 38, 95));

    linija1.setFillColor(
        sf::Color(195, 38, 95)
    );

    linija2.setFillColor(
        sf::Color(195, 38, 95)
    );

    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            if (_generacija[i][j])
            {
                float cx = j * velicina + velicina / 2.f;
                float cy = i * velicina + velicina / 2.f;

                linija1.setPosition(cx, cy);
                linija2.setPosition(cx, cy);

                window.draw(linija1);
                window.draw(linija2);
            }
        }
    }
}