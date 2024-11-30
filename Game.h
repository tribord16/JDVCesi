#pragma once

#include "Grille.h"


class Game {
public:
    Grille plateau;
    std::string sourceJeu;

    int tourActuel,tourMax;

    Game()=default;

    Game(std::string sourceJeu, int maxTours = 10);
    void chargerFichier(/*const std::string& string*/);
    

    void Jouer();
};