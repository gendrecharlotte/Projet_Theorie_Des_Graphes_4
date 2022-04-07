#ifndef HEADERAERO_H_INCLUDED
#define HEADERAERO_H_INCLUDED

#include "AllAvions.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class InfosAeroport
{

    private:
    int m_Num;
    string m_Nom;
    Coordonnees m_Localisation;
    int m_Nombres_Pistes;
    int m_Nombres_Places_Sol;
    string m_Attente_Sol;
    string m_Temps_Acces_Piste;
    string m_Delai_Anticolision;
    string m_Temps_Decollage_Atterissage;
    string m_Duree_Attente_Vol;
    int m_Distance;
    std::vector<const InfosAeroport*> m_successeurs;
    std::vector< int > m_poids;

    public:

    InfosAeroport();
    InfosAeroport(int Num,string Nom, Coordonnees Localisation, int Nombre_Pistes, int Nombres_Places_Sol,  string Attente_Sol,
     string Temps_Acces_Piste,  string Delai_Anticolision, string Temps_Decollage_Atterissage, string Duree_Attente_Vol,
     int Distance);
    ~InfosAeroport();

    void init_poids(int taille_s);

    int getNum() const;
    string get_Nom() ;
    Coordonnees get_Localisation() ;
    int get_Nombres_Pistes() ;
    int get_Nombres_Places_Sol() ;
    string get_Attente_Sol() ;
    string get_Temps_Acces_Piste() ;
    string get_Delai_Anticolision() ;
    string get_Temps_Decollage_Atterissage() ;
    string get_Duree_Attente_Vol() ;
    int get_Distance() ;

    const std::vector<const InfosAeroport*>& getSuccesseurs()const;
    std::vector<int> getpoids()const;

    void set_Nom(string n);
    void set_Localisation(Coordonnees L);
    void set_Pistes(int P);
    void set_Places(int Pla);
    void set_Attente(string A);
    void set_Acces(string Ac);
    void set_Delai(string D);
    void set_Decollage(string Dec);
    void set_Duree(string Du);
    void set_Distance(int Dis);

    void ajouterSucc(const InfosAeroport*a);
    void ajouterpoids(int a, int num_aero);
};


#endif // HEADERAERO_H_INCLUDED
