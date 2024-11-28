#include "Cellule.h"

Cellule::Cellule() : status(0), nbrVoisins(0){}
Cellule::Cellule(bool etat):status(etat),nbrVoisins(0){}
bool Cellule::getStatus() const {return status;}
void Cellule::setStatus(bool status) {
    this->status = status;
    }

int Cellule::getNbrVoisins() const {return nbrVoisins;}
void Cellule::setNbrVoisins(int nbrVoisins) {
    this->nbrVoisins = nbrVoisins;

    }