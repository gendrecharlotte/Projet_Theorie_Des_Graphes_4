#include "Aeroport.h"


InfosAeroport :: InfosAeroport(){}
InfosAeroport :: InfosAeroport(string Nom, string Localisation, int Nombres_Pistes, int Nombres_Places_Sol,  string Attente_Sol,
     string Temps_Acces_Piste,  string Delai_Anticolision, string Temps_Decollage_Atterissage, string Duree_Attente_Vol,
     int Distance) : m_Nom(Nom), m_Localisation(Localisation),  m_Nombres_Pistes(Nombres_Pistes),
     m_Nombres_Places_Sol(Nombres_Places_Sol), m_Attente_Sol(Attente_Sol), m_Temps_Acces_Piste(Temps_Acces_Piste),
     m_Delai_Anticolision(Delai_Anticolision), m_Temps_Decollage_Atterissage(Temps_Decollage_Atterissage),
     m_Duree_Attente_Vol(Duree_Attente_Vol), m_Distance(Distance){}
InfosAeroport ::~InfosAeroport(){}

string InfosAeroport::get_Nom(){return m_Nom;}
string InfosAeroport::get_Localisation(){return m_Localisation;}
int InfosAeroport::get_Nombres_Pistes(){return m_Nombres_Pistes;}
int InfosAeroport::get_Nombres_Places_Sol(){return m_Nombres_Places_Sol;}
string InfosAeroport::get_Attente_Sol(){return m_Attente_Sol;}
string InfosAeroport::get_Temps_Acces_Piste(){return m_Temps_Acces_Piste;}
string InfosAeroport::get_Delai_Anticolision(){return m_Delai_Anticolision;}
string InfosAeroport::get_Temps_Decollage_Atterissage(){return m_Temps_Decollage_Atterissage;}
string InfosAeroport::get_Duree_Attente_Vol(){return m_Duree_Attente_Vol;}
int InfosAeroport::get_Distance(){return m_Distance;}

void InfosAeroport::set_Nom(string n)
{
    m_Nom = n;
}

void InfosAeroport::set_Localisation(string L)
{
    m_Localisation = L;
}

void InfosAeroport::set_Pistes(int P)
{
    m_Nombres_Pistes = P;
}

void InfosAeroport::set_Places(int Pla)
{
    m_Nombres_Places_Sol = Pla;
}

void InfosAeroport::set_Attente(string A)
{
    m_Attente_Sol=A;
}

void InfosAeroport::set_Acces(string Ac)
{
    m_Temps_Acces_Piste = Ac;
}

void InfosAeroport::set_Delai(string D)
{
    m_Delai_Anticolision = D;
}

void InfosAeroport::set_Decollage(string Dec)
{
    m_Temps_Decollage_Atterissage = Dec;
}


void InfosAeroport::set_Duree(string Du)
{
    m_Duree_Attente_Vol = Du;
}

void InfosAeroport::set_Distance(int Dis)
{
    m_Distance = Dis;
}



