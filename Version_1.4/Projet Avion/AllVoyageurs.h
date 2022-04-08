#ifndef ALLVOYAGEUR_H_INCLUDED
#define ALLVOYAGEUR_H_INCLUDED

 ///-------Biblioth?ue------------------///
#include "Voyageur.h"

#include <iostream>
#include <fstream>
#include <vector>

///------Class-------------------------///
//La class allvoyageur permet d'enregisterr plusieurs voyageurs

class AllVoyageurs{
    private:
    //attributs
    std::vector<Voyageur*> m_liste_voyageur;
public:
    //constructeur et destructeur
    AllVoyageurs();
    //AllVoyageurs(std::string nomFichier);
    ~AllVoyageurs();
    //getteur et setteur
    std::vector<Voyageur*> get_liste_Voyageur();
    void set_liste_Voyageurs(std::vector<Voyageur*> val);
    //methode
    void affichage();
    //methode calculer teps?
};

#endif // ALLVOYAGEUR_H_INCLUDED
