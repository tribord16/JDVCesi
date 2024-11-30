#include "Game.h"
#include "Grille.h"


Game::Game(std::string sourceJeu, int maxTours) : sourceJeu(sourceJeu), tourMax(maxTours),tourActuel(1), plateau(0,0){
    chargerFichier();
    
}

void Game::Jouer(){
    tourActuel = 1;
    while(tourActuel < tourMax){
        plateau.afficherPlateau();

        plateau.compterVoisine();
        //plateau->afficherPlateauVoisins();

        plateau.jouerTour();


        //plateau->setEtats(pJeu);
        //plateau->afficherPlateau();
        tourActuel++;
    }

    //plateau->afficherPlateauVoisins();

}

void Game::chargerFichier(/*const std::string& source*/){

    std::ifstream inFile(sourceJeu);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        
    }

    std::string line,temp;
    int ligne, col;
    if(getline(inFile,line)) {
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
   
    plateau = Grille(ligne, col);

    std::vector<std::vector<bool>> pJeu (ligne, std::vector<bool> (col));
        

    for(int j = 0; j < ligne;j++){
        if(getline(inFile,line)){
            int ct = 0;
            for(int i = 0; i <line.size();i++){
                if(line[i]!=' '){
                    if(line[i]=='0') {pJeu[j][ct] = 0; ct++;}
                    else if(line[i]=='1') {pJeu[j][ct] = 1; ct++;}
                    

                }
            }
        }

    }
        
    plateau.setEtats(pJeu);
    
            

    
}

