#pragma once

#include "Cellule.h"
#include <iostream>
#include <string>
#include <fstream>
class Grille {
    
public:
    std::vector<std::vector<Cellule>> plateauJeu;
    //Cellule*** plateauJeu;
    int ligne,col;
    Grille()=default;
    Grille(int x, int y);
    ~Grille();

    void afficherPlateau(); //inisialiser
    int Voisin(int i, int j);
    void compterVoisine();

    void afficherPlateauVoisins();
    void setEtats(const std::vector<bool>>Etats);
    void jouerTour();



};