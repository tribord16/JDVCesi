#pragma once

#include "Cellule.h"
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
class Grille {
    
public:
    std::vector<std::vector<Cellule>> plateauJeu;
    //Cellule*** plateauJeu;
    int ligne,col;
    bool enPause, jeuEnCours, sauvegarder;
    Grille()=default;
    virtual ~Grille() {}
    Grille(int x, int y, bool pause=false);


    void afficherPlateau() ; //inisialiser
    int Voisin(int i, int j) ;
    void compterVoisine();

    void afficherPlateauVoisins();
    void setEtats(const std::vector<std::vector<bool>>&Etats);
    void jouerTour();
    void mettreEnPause();
    bool isEnPause() const {return enPause;}
};

class GrilleGraphique : public Grille {
public:
    sf::RenderWindow window;
    int tailleCellule, hauteurFenetre,largeurFenetre;
    GrilleGraphique(int x, int y, int tailleCellule = 80);

    sf::Clock clock;

    void afficher();
    void update();
    void afficherCellule(int i, int j, bool vivant);
    void afficherMenu();
    void gererMenu();
    void interaction();
    

};
