#ifndef ALLAEROPORTS_H_INCLUDED
#define ALLAEROPORTS_H_INCLUDED

#include "Aeroport.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <windows.h>

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

    bool Dijkstra (int depart,int arrive,DifferentsAeroports Aeroports, int type, AllAvions Allavions);
    std::stack<InfosAeroport*> Dijkstra2 (int depart,int arrive,DifferentsAeroports Aeroports, int type, AllAvions Allavions);

    //std::stack<int> Creer_stack_chemin(std::vector<int>predecesseur,int arrive, int depart);

    void display_chemin(std::stack<InfosAeroport*>chemin,int arrive, int depart, std::vector<int>poid_final);
    std::stack<InfosAeroport*> Conversion_stack(std::vector<int>predecesseur,int arrive, int depart, std::vector<InfosAeroport*> m_vect_aero);
};

#endif // ALLAEROPORTS_H_INCLUDED
