#include "Cellule.h"

Cellule::Cellule() : status(0), nbrVoisins(0){}
Cellule::Cellule(bool etat):status(etat),nbrVoisins(0){}
bool Cellule::getStatus() {return status;}
void Cellule::setStatus(bool status) {
    if (!isObstacle){
        this->status = status;
    }
    
    }

int Cellule::getNbrVoisins()  {return nbrVoisins;}
void Cellule::setNbrVoisins(int nbrVoisins) {
    this->nbrVoisins = nbrVoisins;

    }

bool Cellule::getisObstacle(){return isObstacle;}
void Cellule::setisObstacle(bool isObstacle) {
    this -> isObstacle = isObstacle;
}