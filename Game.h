#pragma once
#include "GrilleGraphique.h"
#include "Grille.h"
#include <thread>
#include <chrono>

class Game {
public:
    Grille* plateau;
    std::string sourceJeu;

    int tourActuel,tourMax;

    bool modeGraphique;
    Game()=default;
    ~Game();
    Game(std::string sourceJeu, bool graphique = false, int maxTours = 12);
    void chargerFichier(/*const std::string& string*/);
    void sauvegarderEtat(const std::string& fichierSortie);
    void sauvegardeFichier(GrilleGraphique* g);

    void Jouer();
};