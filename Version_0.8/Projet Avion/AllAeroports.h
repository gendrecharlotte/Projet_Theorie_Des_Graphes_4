#ifndef ALLAEROPORTS_H_INCLUDED
#define ALLAEROPORTS_H_INCLUDED

#include "Aeroport.h"
#include "AllAvions.h"
#include <iostream>
#include <fstream>
#include <vector>

class DifferentsAeroports
{
private:
    std::vector<InfosAeroport*> m_vect_aero;
    std::vector<InfosAeroport*> m_validation;
public:
    DifferentsAeroports();
    DifferentsAeroports(string Fichier);
    ~DifferentsAeroports();

    std::vector<InfosAeroport*>get_vecteur_aero();
    void set_vect_aero(std::vector<InfosAeroport*> val);

    int findAeroport(std::string nomaero,DifferentsAeroports Aeroports);

    void display();

    void Dijkstra (int depart,int arrive);
};

#endif // ALLAEROPORTS_H_INCLUDED
