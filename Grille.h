#pragma once

#include "Cellule.h"
#include <iostream>
#include <string>
#include <fstream>
class Grille {
public:
    Cellule*** plateauJeu;
    int ligne,col;
    Grille()=default;
    Grille(int x, int y);
    ~Grille();

    void afficherPlateau();
    void compterVoisine();

    void afficherPlateauVoisins();
    void setEtats(bool** Etats);

    int Voisin(int i, int j);
    void jouerTour();



};