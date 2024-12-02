#include "Grille.h"


Grille::Grille(int x, int y, bool pause) : ligne(x), col(y), enPause(pause), sauvegarder(false), jeuEnCours(true){
    //plateauJeu.resize(ligne, std::vector<Cellule>(col));
    plateauJeu.resize(ligne * col);
}
void Grille::mettreEnPause(){
    enPause = !enPause;
}

void Grille::afficherPlateau(){
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            //std::cout << plateauJeu[i][j].getStatus() << " ";
            std::cout << plateauJeu[index(i, j)].getStatus() << " "; 
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}
// Calcul du nombre de voisins vivants pour une cellule (avec la méthode hybride 1D)
int Grille::Voisin(int i, int j) {
    int voisinsEnVie = 0;

    if (i > 0) {
        voisinsEnVie += plateauJeu[index(i - 1, j)].getStatus(); // Accès à la cellule via index 1D

        if (j > 0) {
            voisinsEnVie += plateauJeu[index(i - 1, j - 1)].getStatus();
        }
        if (j < (col - 1)) {
            voisinsEnVie += plateauJeu[index(i - 1, j + 1)].getStatus();
        }
    }

    if (i < (ligne - 1)) {
        voisinsEnVie += plateauJeu[index(i + 1, j)].getStatus(); // Accès à la cellule via index 1D

        if (j > 0) {
            voisinsEnVie += plateauJeu[index(i + 1, j - 1)].getStatus();
        }
        if (j < (col - 1)) {
            voisinsEnVie += plateauJeu[index(i + 1, j + 1)].getStatus();
        }
    }

    if (j > 0) {
        voisinsEnVie += plateauJeu[index(i, j - 1)].getStatus();
    }

    if (j < (col - 1)) {
        voisinsEnVie += plateauJeu[index(i, j + 1)].getStatus();
    }

    return voisinsEnVie;
}

/*int Grille::Voisin(int i, int j){
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
}*/
void Grille::compterVoisine(){
    for (int i=0; i< ligne; i++){
        for (int j=0; j<col; j++){
            //plateauJeu[i][j].setNbrVoisins(Voisin(i,j));
            plateauJeu[index(i, j)].setNbrVoisins(Voisin(i, j));

        }
    }
}

void Grille::afficherPlateauVoisins(){
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            //std::cout << plateauJeu[i][j].getNbrVoisins() << " ";
            std::cout << plateauJeu[index(i, j)].getNbrVoisins() << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}
void Grille::setEtats(const std::vector<std::vector<bool>>&Etats){
  for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            //plateauJeu[i][j].setStatus(Etats[i][j]);
            plateauJeu[index(i, j)].setStatus(Etats[i][j]); 
        }
    }
}

/*void Grille::jouerTour() {
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
}*/
void Grille::jouerTour() {
    std::vector<std::vector<bool>> nouveauEtat(ligne, std::vector<bool>(col));
    for (int i = 0; i < ligne; ++i) {
        for (int j = 0; j < col; ++j) {
            int voisins = plateauJeu[index(i, j)].getNbrVoisins(); // Accès via index 1D
            if (plateauJeu[index(i, j)].getStatus()) { 
                nouveauEtat[i][j] = (voisins == 2 || voisins == 3);
            } else { 
                nouveauEtat[i][j] = (voisins == 3);
            }
        }
    }
    setEtats(nouveauEtat); // Mise à jour des états avec les nouveaux états
}





