#ifndef ALLAVIONS_H_INCLUDED
#define ALLAVIONS_H_INCLUDED

#include "Avion.h"
#include <iostream>
#include <fstream>
#include <vector>

class AllAvions
{
private:
    ///ATTRIBUTS
    std::vector<Avion*> m_liste_avions;
public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    AllAvions();
    AllAvions(std::string nomFichier);
    ~AllAvions();
    ///GETTERS/SETTERS
    std::vector<Avion*> get_liste_avions();
    void set_liste_avions(std::vector<Avion*> val);
    ///AFFICHAGE
    void affichage();
};

#endif // ALLAVIONS_H_INCLUDED
