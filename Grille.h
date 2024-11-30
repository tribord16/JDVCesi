#pragma once

#include "Cellule.h"
#include <iostream>
#include <string>
#include <fstream>

#include <vector>
class Grille {
    
public:
    std::vector<std::vector<Cellule>> plateauJeu;
    //Cellule*** plateauJeu;
    int ligne,col;
    Grille()=default;
    Grille(int x, int y);


    void afficherPlateau() ; //inisialiser
    int Voisin(int i, int j) ;
    void compterVoisine();

    void afficherPlateauVoisins();
    void setEtats(const std::vector<std::vector<bool>>&Etats);
    void jouerTour();



};