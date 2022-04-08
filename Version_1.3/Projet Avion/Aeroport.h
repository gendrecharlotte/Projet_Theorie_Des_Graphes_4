#ifndef HEADERAERO_H_INCLUDED
#define HEADERAERO_H_INCLUDED

#include "AllAvions.h"

#include <iostream>
#include <fstream>
#include <vector>

class InfosAeroport
{

    private:
    int m_Num;
    std::string m_Nom;
    Coordonnees m_Localisation;
    int m_Nombres_Pistes;
    int m_Nombres_Places_Sol;
    int m_Attente_Sol;
    int m_Temps_Acces_Piste;
    int m_Delai_Anticolision;
    int m_Temps_Decollage_Atterissage;
    int m_Duree_Attente_Vol;
    int m_Distance;
    std::vector<const InfosAeroport*> m_successeurs;
    std::vector< int > m_poids;
    std::vector<Avion*> m_avions_sur_pistes;
    std::vector<Avion*> m_avions_au_sol;

    public:

    InfosAeroport();
    InfosAeroport(int Num,std::string Nom, Coordonnees Localisation, int Nombre_Pistes, int Nombres_Places_Sol,  int Attente_Sol,
     int Temps_Acces_Piste,  int Delai_Anticolision, int Temps_Decollage_Atterissage, int Duree_Attente_Vol,
     int Distance,std::vector<Avion*> avions_sur_pistes,std::vector<Avion*> avions_au_sol);
    ~InfosAeroport();

    void init_poids(int taille_s);

    int getNum() const;
    std::string get_Nom() ;
    Coordonnees get_Localisation() ;
    int get_Nombres_Pistes() ;
    int get_Nombres_Places_Sol() ;
    int get_Attente_Sol() ;
    int get_Temps_Acces_Piste() ;
    int get_Delai_Anticolision() ;
    int get_Temps_Decollage_Atterissage() ;
    int get_Duree_Attente_Vol() ;
    int get_Distance() ;
    std::vector<Avion*> get_avions_sur_pistes();
    std::vector<Avion*> get_avions_au_sol();

    const std::vector<const InfosAeroport*>& getSuccesseurs()const;
    std::vector<int> getpoids()const;

    void set_Nom(std::string n);
    void set_Localisation(Coordonnees L);
    void set_Pistes(int P);
    void set_Places(int Pla);
    void set_Attente(int A);
    void set_Acces(int Ac);
    void set_Delai(int D);
    void set_Decollage(int Dec);
    void set_Duree(int Du);
    void set_Distance(int Dis);
    void set_avions_sur_pistes(std::vector<Avion*> val);
    void set_avions_au_sol(std::vector<Avion*> val);

    void ajouterSucc(const InfosAeroport*a);
    void ajouterpoids(int a, int num_aero);
};


#endif // HEADERAERO_H_INCLUDED
