#pragma once

#include "Grille.h"


class Game {
public:
    Grille* plateau;
    bool** pJeu;
    std::string sourceJeu;

    int ligne,col, tourActuel= 1,tourMax = 10;

    Game()=default;

    Game(std::string sourceJeu);
    void LireFichierprocessFile(/*const std::string& string*/);
    

    void Jouer();
};