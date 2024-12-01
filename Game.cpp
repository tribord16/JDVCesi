#include "Game.h"
#include "Grille.h"


Game::Game(std::string sourceJeu, bool graphique, int maxTours) : modeGraphique(graphique),sourceJeu(sourceJeu), tourMax(maxTours),tourActuel(1){
    chargerFichier();
    
}

void Game::Jouer(){
    tourActuel = 1;
    while(tourActuel < tourMax){
        //plateau.update();
        if(modeGraphique){
            if(!dynamic_cast<GrilleGraphique*>(plateau)->jeuEnCours) break;
            
            
            while(dynamic_cast<GrilleGraphique*>(plateau)->isEnPause()){
                if(dynamic_cast<GrilleGraphique*>(plateau)->sauvegarder) {
                    std::string fichierSauvegarde;
                    std::cout << "Entrer un nom de sauvegarde " ;
                    std::cin >> fichierSauvegarde;
                    sauvegarderEtat(fichierSauvegarde);
                    dynamic_cast<GrilleGraphique*>(plateau)->sauvegarder=false;
                    break;
                };
               dynamic_cast<GrilleGraphique*>(plateau)->interaction();
               
                dynamic_cast<GrilleGraphique*>(plateau)->afficherMenu();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            dynamic_cast<GrilleGraphique*>(plateau)->interaction();
            dynamic_cast<GrilleGraphique*>(plateau)->update();

            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int> (0.5 * 1000)));
            

        }
        else {
            std::cout << "Tour " << tourActuel << std::endl;
            plateau->afficherPlateau();
        }

        plateau->compterVoisine();
        //plateau->afficherPlateauVoisins();

        plateau->jouerTour();


        //plateau->setEtats(pJeu);
        //plateau->afficherPlateau();
        //std::cout<<tourActuel<<std::endl;
        tourActuel++;
        
        //std::cout<<tourMax<<std::endl;
    }

    //plateau->afficherPlateauVoisins();

}

void Game::chargerFichier(/*const std::string& source*/){

    std::ifstream inFile(sourceJeu);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
        return;
        
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
    if(modeGraphique) plateau = new GrilleGraphique(ligne, col);
    else plateau = new Grille(ligne,col);

    

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
        
    plateau->setEtats(pJeu);
    
    
}
Game::~Game(){delete plateau;}

void Game::sauvegarderEtat(const std::string& fichierSortie){
    std::ofstream outFile(fichierSortie);
    if(!outFile){
        std::cerr << "Erreur decriture: impossible d'ouvrir le fichier.\n";
        return;
    }
    outFile << "touractuel: " << tourActuel << "\n";
    outFile << plateau->ligne << " " << plateau -> col << std ::endl;
    for (int i = 0; i < plateau->ligne; i++){
        for(int j = 0; j < plateau->col; j++){
            outFile <<(plateau->plateauJeu[i][j].getStatus() ? "1" : "0") << " ";
        }
        outFile << std::endl;
    }
    std::cout<< "Jeu sauvegarde dans " << fichierSortie << std::endl;
}   