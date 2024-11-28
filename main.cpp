#include "Game.h"

int main(){

    std::string source;

    std::cout << "Entrez le fichier source : ";
    std::cin >> source;
    Game* game = new Game(source);
    return 0;
}