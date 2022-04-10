#ifndef VOYAGEUR_H_INCLUDED
#define VOYAGEUR_H_INCLUDED

///------Bibliotheque---------------------------------------------///
#include "AllAeroports.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

///------Class--------------------------------------------------///
//La class voyageur va permettre de renseigner quelle vols nous souhaitons prendre
class Voyageur{
private:
    //attributs
    std::string m_nom;
    std::string m_depart;
    std::string m_arrivee;
    Avion m_avion;
    int m_horaire;
    //std::stack<Aeroport*>m_chemin;

public:
    //constructeur/destructeur
    Voyageur();
    Voyageur(std::string nom,std::string depart,std::string arrivee, Avion* avion, int horaire);
    ~Voyageur();
    //getteur et setteur
    std::string get_nom()const;
    std::string get_depart()const;
    std::string get_arrivee()const;
    Avion get_avion()const;
    int get_horaire()const;
    void set_nom(std::string val);
    void set_depart(std::string val);
    void set_arrivee(std::string val);
    void set_avion(Avion val);
    void set_horaire(int val);

    void write_Voyageur(Voyageur* voyageur);
    void display(Voyageur a);

};


#endif // VOYAGEUR_H_INCLUDED
