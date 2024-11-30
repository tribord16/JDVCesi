#include "Grille.h"


Grille::Grille(int x, int y) : ligne(x), col(y) {
    plateauJeu = new Cellule**[ligne];  
    for (int i = 0; i < ligne; i++) {
        plateauJeu[i] = new Cellule*[col];
        for (int j = 0; j < col; j++) {
            plateauJeu[i][j] = new Cellule();
            std::cout<<"bonjour"<<std::endl; 
        }
    }

}

Grille::~Grille() {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            delete plateauJeu[i][j];  
        }
        delete[] plateauJeu[i]; 
    }
    delete[] plateauJeu;  
}


void Grille::afficherPlateau(){
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << plateauJeu[i][j]->getStatus() << " "; 
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}

int Grille::Voisin(int i, int j){
  int voisinsEnVie = 0;

    if (i > 0)
    {
        voisinsEnVie += plateauJeu[i - 1][j]->getStatus();

        if (j > 0)
        {
            voisinsEnVie += plateauJeu[i - 1][j - 1]->getStatus();
        }
        if (j < (ligne - 1))
        {
            voisinsEnVie += plateauJeu[i - 1][j + 1]->getStatus();
        }
    }

    if (i < (ligne - 1))
    {
        voisinsEnVie += plateauJeu[i + 1][j]->getStatus();

        if (j > 0)
        {
            voisinsEnVie += plateauJeu[i + 1][j - 1]->getStatus();
        }
        if (j < (col - 1))
        {
            voisinsEnVie += plateauJeu[i + 1][j + 1]->getStatus();
        }
    }

    if (j > 0)
    {
        voisinsEnVie += plateauJeu[i][j - 1]->getStatus();
    }

    if (j < (col - 1))
    {
        voisinsEnVie += plateauJeu[i][j + 1]->getStatus();
    }

    return voisinsEnVie;
}

void Grille::compterVoisine(){
  for (int i=0; i< ligne; i++){
    for (int j=0; j<col; j++){
        plateauJeu[i][j]->setNbrVoisins(Voisin(i,j));

    }
  }
  //afficherPlateauVoisins();

}

void Grille::afficherPlateauVoisins(){
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << plateauJeu[i][j]->getNbrVoisins() << " "; 
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}
void Grille::setEtats(bool** Etats){
  for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            plateauJeu[i][j]->setStatus(Etats[i][j]); 
        }
    }
}

void Grille::jouerTour() {
    bool** nouveauEtat = new bool*[ligne];
    for (int i = 0; i < ligne; ++i) {
        nouveauEtat[i] = new bool[col];
        for (int j = 0; j < col; ++j) {
            int voisins = plateauJeu[i][j]->getNbrVoisins();
            if (plateauJeu[i][j]->getStatus()) { 
                nouveauEtat[i][j] = (voisins == 2 || voisins == 3);
            } else { 
                nouveauEtat[i][j] = (voisins == 3);
            }
        }
    }

    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < col; ++j) {
            plateauJeu[i][j]->setStatus(nouveauEtat[i][j]);
        }
        delete[] nouveauEtat[i];
    }
    delete[] nouveauEtat;
}
