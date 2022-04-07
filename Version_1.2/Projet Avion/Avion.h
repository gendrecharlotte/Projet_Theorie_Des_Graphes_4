#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "Interface.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Avion
{
private:
    ///ATTRIBUTS
    int m_matricule;
    int m_type;
    int m_consomation;
    int m_capacite;
public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Avion();
    Avion(int matricule,int type, int consomation, int capacite);
    ~Avion();
    ///GETTERS/SETTERS
    int get_matricule()const;
    int get_type()const;
    int get_consomation()const;
    int get_capacite()const;
    void set_matricule(int val);
    void set_type(int val);
    void set_consomation(int val);
    void set_capacite(int val);
};

#endif // AVION_H_INCLUDED
