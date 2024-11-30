#pragma once
#include <string>
#include <iostream>


class Cellule {
private:
    bool status;
    int nbrVoisins;

public:
    Cellule();
    Cellule(bool etat);

    bool getStatus();
    void setStatus(bool status);

    int getNbrVoisins() ;
    void setNbrVoisins(int nbrVoisins);

};
