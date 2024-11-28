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

    bool getStatus() const;
    void setStatus(bool status);

    int getNbrVoisins() const;
    void setNbrVoisins(int nbrVoisins);

};
