#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "Coordonnees.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

class InfosAeroport; //

class Avion
{
private:
    ///ATTRIBUTS
    int m_matricule;
    int m_type;
    int m_consomation;
    int m_capacite;
    int m_tmp_sol;
    int m_tmp_acces;
    int m_tmp_atterir;
    int m_etat;
    BITMAP *m_img;
    Coordonnees m_coo;
    bool m_da;
    std::stack<InfosAeroport*> m_trajet;
public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Avion();
    Avion(int matricule,int type, int consomation, int capacite,int tmp_sol,int tmp_acces,int tmp_atterir,int etat,BITMAP *img,Coordonnees coo, bool da,std::stack<InfosAeroport*> trajet);
    ~Avion();
    ///GETTERS/SETTERS
    int get_matricule()const;
    int get_type()const;
    int get_consomation()const;
    int get_capacite()const;
    int get_tmp_sol()const;
    int get_tmp_acces()const;
    int get_tmp_atterir()const;
    int get_etat()const;
    BITMAP *get_img()const;
    Coordonnees get_coo()const;
    bool get_da()const;
    std::stack<InfosAeroport*> get_trajet()const;
    void set_matricule(int val);
    void set_type(int val);
    void set_consomation(int val);
    void set_capacite(int val);
    void set_tmp_sol(int val);
    void set_tmp_acces(int val);
    void set_tmp_atterir(int val);
    void set_etat(int val);
    void set_img(BITMAP *val);
    void set_coo(Coordonnees val);
    void set_da(bool da);
    void set_trajet(std::stack<InfosAeroport*> val);
    bool cl_consomation(int distance_parcourut);
};

#endif // AVION_H_INCLUDED
