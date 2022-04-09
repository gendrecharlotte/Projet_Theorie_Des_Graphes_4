#ifndef ALLAEROPORTS_H_INCLUDED
#define ALLAEROPORTS_H_INCLUDED

#include "Aeroport.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

class DifferentsAeroports
{
private:
    std::vector<InfosAeroport*> m_vect_aero;
    std::vector<InfosAeroport*> m_validation;
public:
    DifferentsAeroports();
    DifferentsAeroports(std::string Fichier);
    ~DifferentsAeroports();

    std::vector<InfosAeroport*>get_vecteur_aero();
    void set_vect_aero(std::vector<InfosAeroport*> val);

    int findAeroport(std::string nomaero,DifferentsAeroports Aeroports);
    int findAeroport2(Coordonnees coo,DifferentsAeroports Aeroports);

    void display();

    void Dijkstra (int depart,int arrive,DifferentsAeroports Aeroports);

    void display_chemin(std::vector<int>predecesseur,int arrive, int depart,std::vector<InfosAeroport*> m_vect_aero, std::vector<int>poid_final);
};

#endif // ALLAEROPORTS_H_INCLUDED
