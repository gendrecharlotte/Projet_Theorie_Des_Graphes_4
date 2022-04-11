#ifndef ALLVOYAGEUR_H_INCLUDED
#define ALLVOYAGEUR_H_INCLUDED

 ///-------Biblioth?ue------------------///
#include "Interface.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

///------Class-------------------------///
//La class allvoyageur permet d'enregisterr plusieurs voyageurs

class AllVoyageurs{
    private:
    //attributs
    std::vector<Voyageur*> m_liste_voyageur;
public:
    //constructeur et destructeur
    AllVoyageurs();
    AllVoyageurs(std::string Fichier,AllAvions Avions, DifferentsAeroports Aeroports);
    //AllVoyageurs(std::string nomFichier);
    ~AllVoyageurs();

    Voyageur CreerVoyageurs(DifferentsAeroports Aeroports, AllAvions Avions, Interface I);
    Voyageur* RechercheVoyageur(AllVoyageurs voyageurs);
    //getteur et setteur
    std::vector<Voyageur*> get_liste_Voyageur();
    void set_liste_Voyageurs(std::vector<Voyageur*> val);
    //methode
    void affichage();
    //methode calculer teps?
};

#endif // ALLVOYAGEUR_H_INCLUDED
