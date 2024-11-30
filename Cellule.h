#pragma once
#include <string>
#include <iostream>


class Cellule {
private:
    bool status;
    int nbrVoisins;
    bool isObstacle;

public:
    Cellule();
    Cellule(bool etat);

    bool getStatus() ;
    void setStatus(bool status);

    bool getisObstacle() ;
    void setisObstacle(bool isObstacle);

    int getNbrVoisins() ;
    void setNbrVoisins(int nbrVoisins);

};
