#pragma once

#include "Grille.h"


class Game {
public:
    Grille* plateau;
    bool** pJeu;
    std::string sourceJeu;

    int ligne,col, tourActuel,tourMax;

    Game()=default;

    Game(std::string sourceJeu);
    void LireFichierprocessFile(/*const std::string& string*/);
    

    void Jouer();
};