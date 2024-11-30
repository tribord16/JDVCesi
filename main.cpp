#include "Game.h"

int main(){

    std::string source;

    std::cout << "Entrez le fichier source : ";
    std::cin >> source;
    bool modeGraphique = true;


    Game game(source,modeGraphique);
    game.Jouer();
    
    
    

    return 0;
}