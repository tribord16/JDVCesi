#include "Game.h"
#include "Grille.h"


Game::Game(std::string sourceJeu){
    this->sourceJeu = sourceJeu;

    LireFichierprocessFile();
    plateau = new Grille(ligne,col);
    plateau->afficherPlateau();
    Jouer();
    
}

void Game::Jouer(){
    plateau->setEtats(pJeu);

    plateau->afficherPlateau();

    plateau->compterVoisine();
    //plateau->afficherPlateauVoisins();

    plateau->jouerTour();


    //plateau->setEtats(pJeu);
    plateau->afficherPlateau();

    //plateau->afficherPlateauVoisins();

}

void Game::LireFichierprocessFile(/*const std::string& source*/){

    std::ifstream inFile(sourceJeu);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        
    }

    std::string line,temp;
    if(getline(inFile,line)) {
        std::cout << "line" << std::endl;
        int cnt = 0;
        for (char lettre : line){ 
            if(lettre == ' ') {            
                cnt++;
                
                if(cnt==1) {
                    ligne = std::stoi(temp);
                    temp.clear();
                }
            } else {
                temp.push_back(lettre);
            }
        }
        col = std::stoi(temp);

    }
       
    std::cout<<ligne <<" " << col <<std::endl;

    pJeu = new bool*[ligne];
    for (int i = 0; i < ligne; i++) {
        pJeu[i] = new bool[col];
    }

    for(int j = 0; j < ligne;j++){
        if(getline(inFile,line)){
            int ct = 0;
            for(int i = 0; i <line.length();i++){
                if(line[i]!=' '){
                    if(line[i]=='0') {pJeu[j][ct] = 0; ct++;}
                    else if(line[i]=='1') {pJeu[j][ct] = 1; ct++;}
                    

                }
            }
        }

    }
    
}

