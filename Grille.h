#pragma once

#include "Cellule.h"
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
class Grille {
    
public:
    //std::vector<std::vector<Cellule>> plateauJeu;
    std::vector<Cellule> plateauJeu;
    int ligne,col;
    bool enPause, jeuEnCours, sauvegarder;

    Grille()=default;
    virtual ~Grille() {}
    Grille(int x, int y, bool pause=false);


    void afficherPlateau();
    int Voisin(int i, int j);
    void compterVoisine();

    void afficherPlateauVoisins();
    void setEtats(const std::vector<std::vector<bool>>& Etats);
    //void setEtats(const std::vector<std::vector<bool>>&Etats);
    void jouerTour();
    void mettreEnPause();
    bool isEnPause() const {return enPause;}
    int index(int i, int j) const { return i * col + j; }
};


