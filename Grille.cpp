#include "Grille.h"


Grille::Grille(int x, int y, bool pause) : ligne(x), col(y), enPause(pause){
    
    plateauJeu.resize(ligne, std::vector<Cellule>(col));
}


void Grille::mettreEnPause(){
    enPause = !enPause;
    std::cout<<"cc:"<<enPause<<std::endl;
}

void Grille::afficherPlateau(){
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << plateauJeu[i][j].getStatus() << " "; 
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}

int Grille::Voisin(int i, int j){
  int voisinsEnVie = 0;

    if (i > 0)
    {
        voisinsEnVie += plateauJeu[i - 1][j].getStatus();

        if (j > 0)
        {
            voisinsEnVie += plateauJeu[i - 1][j - 1].getStatus();
        }
        if (j < (ligne - 1))
        {
            voisinsEnVie += plateauJeu[i - 1][j + 1].getStatus();
        }
    }

    if (i < (ligne - 1))
    {
        voisinsEnVie += plateauJeu[i + 1][j].getStatus();

        if (j > 0)
        {
            voisinsEnVie += plateauJeu[i + 1][j - 1].getStatus();
        }
        if (j < (col - 1))
        {
            voisinsEnVie += plateauJeu[i + 1][j + 1].getStatus();
        }
    }

    if (j > 0)
    {
        voisinsEnVie += plateauJeu[i][j - 1].getStatus();
    }

    if (j < (col - 1))
    {
        voisinsEnVie += plateauJeu[i][j + 1].getStatus();
    }

    return voisinsEnVie;
}

void Grille::compterVoisine(){
  for (int i=0; i< ligne; i++){
    for (int j=0; j<col; j++){
        plateauJeu[i][j].setNbrVoisins(Voisin(i,j));

    }
  }
  //afficherPlateauVoisins();

}

void Grille::afficherPlateauVoisins(){
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << plateauJeu[i][j].getNbrVoisins() << " "; 
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}
void Grille::setEtats(const std::vector<std::vector<bool>>&Etats){
  for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            plateauJeu[i][j].setStatus(Etats[i][j]); 
        }
    }
}

void Grille::jouerTour() {
    std::vector<std::vector<bool>> nouveauEtat(ligne, std::vector<bool>(col));
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < col; ++j) {
            int voisins = plateauJeu[i][j].getNbrVoisins();
            if (plateauJeu[i][j].getStatus()) { 
                nouveauEtat[i][j] = (voisins == 2 || voisins == 3);
            } else { 
                nouveauEtat[i][j] = (voisins == 3);
            }
        }
    }

    setEtats(nouveauEtat);

}


GrilleGraphique::GrilleGraphique(int x, int y, int tailleCellule) : Grille(x,y), tailleCellule(tailleCellule) {
    largeurFenetre = col * tailleCellule;
    hauteurFenetre = ligne * tailleCellule;

    window.create(sf::VideoMode(largeurFenetre, hauteurFenetre), "Jeu de la vie");

}

void GrilleGraphique::afficher(){
    window.clear();

    for (int i = 0; i < ligne; i++){
        for(int j =0; j < col; j++){
            bool vivant = plateauJeu[i][j].getStatus();
            afficherCellule(i, j, vivant);
        }
    }
    window.display();
}

void GrilleGraphique::afficherCellule(int x, int y, bool vivant){
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule,tailleCellule));
    cellule.setPosition(x*tailleCellule, y*tailleCellule);

    if(vivant) cellule.setFillColor(sf::Color::Blue);
    else cellule.setFillColor(sf::Color::Black);

    window.draw(cellule);



}

void GrilleGraphique::update(){
    afficher(); 
}


void GrilleGraphique::interaction(){
    sf::Event event;
    while (window.pollEvent(event)){
        if(event.type == sf::Event::Closed) window.close();
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {mettreEnPause();}
    }
}

