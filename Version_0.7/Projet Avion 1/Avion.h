#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Interface.h"

class Avion
{
private:
    ///ATTRIBUTS
    int m_type;//1=Court 2= Moyen 3= Long
    int m_consomation;
    int m_capacite;
public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Avion();
    Avion(int type, int consomation, int capacite);
    ~Avion();
    ///GETTERS/SETTERS
    int get_type()const;
    int get_consomation()const;
    int get_capacite()const;
    void set_type(int val);
    void set_consomation(int val);
    void set_capacite(int val);
};

#endif // AVION_H_INCLUDED
