#pragma once
#include"Grille.h"
#include <SFML/Graphics.hpp>
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
