#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "Coordonnees.h"
//#include "Aeroport.h"///////////////////////////////////////////////////////////////////aled

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

class Avion
{
private:
    ///ATTRIBUTS
    int m_matricule;
    int m_type;
    int m_consomation;
    int m_capacite;
    BITMAP *m_img;
    Coordonnees m_coo;
    bool m_da;
    //std::stack<Aeroport*> m_trajet;
public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Avion();
    Avion(int matricule,int type, int consomation, int capacite,BITMAP *img,Coordonnees coo, bool da/*,std::stack<Aeroport*> trajet*/);
    ~Avion();
    ///GETTERS/SETTERS
    int get_matricule()const;
    int get_type()const;
    int get_consomation()const;
    int get_capacite()const;
    BITMAP *get_img()const;
    Coordonnees get_coo()const;
    bool get_da()const;
    //std::stack<Aeroport*> get_trajet()const;
    void set_matricule(int val);
    void set_type(int val);
    void set_consomation(int val);
    void set_capacite(int val);
    void set_img(BITMAP *val);
    void set_coo(Coordonnees val);
    void set_da(bool da);
    //void set_trajet(std::stack<Aeroport*> val);
};

#endif // AVION_H_INCLUDED
