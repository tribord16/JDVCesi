#include "Grille.h"


Grille::Grille(int x, int y, bool pause) : ligne(x), col(y), enPause(pause), sauvegarder(false), jeuEnCours(true){
    
    plateauJeu.resize(ligne, std::vector<Cellule>(col));
}


void Grille::mettreEnPause(){
    enPause = !enPause;
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

void GrilleGraphique::afficherMenu(){
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Erreur de chargement de la police" << std::endl;
        return;
    }

    sf::Text menu("Le menu de jeu", font, 30);
    menu.setFillColor(sf::Color::Green);
    menu.setPosition(largeurFenetre / 2 - menu.getLocalBounds().width / 2, hauteurFenetre / 4);
    window.draw(menu);
    
    window.display();
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


/*void GrilleGraphique::gererMenu(){
    interaction();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        std::string fichierSauvegarde;
        std::cout << "Entrer un nom de sauvegarde " ;
        std::cin >> fichierSauvegarde;
        sauvegarderEtat(fichierSauvegarde);
    }
}
*/
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
        if(event.type == sf::Event::Closed){
            window.close();
            enPause = jeuEnCours = false;
            break;
        } 
            
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {mettreEnPause();}
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {sauvegarder=true;}
    }
}

