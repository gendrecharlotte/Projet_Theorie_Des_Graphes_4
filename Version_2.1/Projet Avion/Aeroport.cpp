#include "Aeroport.h"


InfosAeroport :: InfosAeroport() {}
InfosAeroport :: InfosAeroport(int Num, std::string Nom, Coordonnees Localisation, int Nombres_Pistes, int Nombres_Places_Sol,  int Attente_Sol,
                               int Temps_Acces_Piste,  int Delai_Anticolision, int Temps_Decollage_Atterissage, int Duree_Attente_Vol,
                               int Distance, std::vector<Avion*> avions_sur_pistes,std::vector<Avion*> avions_au_sol) : m_Num(Num), m_Nom(Nom), m_Localisation(Localisation),  m_Nombres_Pistes(Nombres_Pistes),
    m_Nombres_Places_Sol(Nombres_Places_Sol), m_Attente_Sol(Attente_Sol), m_Temps_Acces_Piste(Temps_Acces_Piste),
    m_Delai_Anticolision(Delai_Anticolision), m_Temps_Decollage_Atterissage(Temps_Decollage_Atterissage),
    m_Duree_Attente_Vol(Duree_Attente_Vol), m_Distance(Distance), m_avions_sur_pistes(avions_sur_pistes),m_avions_au_sol(avions_au_sol){}
InfosAeroport ::~InfosAeroport() {}

void InfosAeroport::init_poids(int taille_s)
{
    for(int i=0; i<taille_s; i++)
    {
        m_poids.push_back(0);
    }
}

int InfosAeroport::getNum() const
{
    return m_Num;
}

std::string InfosAeroport::get_Nom()
{
    return m_Nom;
}
Coordonnees InfosAeroport::get_Localisation()
{
    return m_Localisation;
}
int InfosAeroport::get_Nombres_Pistes()
{
    return m_Nombres_Pistes;
}

int InfosAeroport::get_Nombres_Places_Sol()
{
    return m_Nombres_Places_Sol;
}

int InfosAeroport::get_Attente_Sol()
{
    return m_Attente_Sol;
}

int InfosAeroport::get_Temps_Acces_Piste()
{
    return m_Temps_Acces_Piste;
}

int InfosAeroport::get_Delai_Anticolision()
{
    return m_Delai_Anticolision;
}

int InfosAeroport::get_Temps_Decollage_Atterissage()
{
    return m_Temps_Decollage_Atterissage;
}

int InfosAeroport::get_Duree_Attente_Vol()
{
    return m_Duree_Attente_Vol;
}
int InfosAeroport::get_Distance()
{
    return m_Distance;
}

std::vector<Avion*> InfosAeroport::get_avions_sur_pistes()
{
    return m_avions_sur_pistes;
}

std::vector<Avion*> InfosAeroport::get_avions_au_sol()
{
    return m_avions_au_sol;
}

const std::vector<const InfosAeroport*>& InfosAeroport::getSuccesseurs()const {return m_successeurs;}

std::vector<int> InfosAeroport::getpoids()const{return m_poids;}

void InfosAeroport::set_Nom(std::string n)
{
    m_Nom = n;
}

void InfosAeroport::set_Localisation(Coordonnees L)
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

void InfosAeroport::set_Attente(int A)
{
    m_Attente_Sol=A;
}

void InfosAeroport::set_Acces(int Ac)
{
    m_Temps_Acces_Piste = Ac;
}

void InfosAeroport::set_Delai(int D)
{
    m_Delai_Anticolision = D;
}

void InfosAeroport::set_Decollage(int Dec)
{
    m_Temps_Decollage_Atterissage = Dec;
}


void InfosAeroport::set_Duree(int Du)
{
    m_Duree_Attente_Vol = Du;
}

void InfosAeroport::set_Distance(int Dis)
{
    m_Distance = Dis;
}

void InfosAeroport::set_avions_sur_pistes(std::vector<Avion*> val)
{
    m_avions_sur_pistes=val;
}

void InfosAeroport::set_avions_au_sol(std::vector<Avion*> val)
{
    m_avions_au_sol=val;
}

void InfosAeroport::ajouterSucc(const InfosAeroport*a)
{
    m_successeurs.push_back(a);
}

//pour ajouter le distance entre deux point
void InfosAeroport::ajouterpoids(int a, int num_aero)
{
    m_poids[num_aero] = a;
}

/*void InfosAeroport::remove_avion_aero(Avion* avion)
{
    int compteur, valeur_compteur;
    std::vector<Avion*> vect=m_avions_au_sol;
    for(auto a:vect)
    {
        if(a->get_matricule()==avion->get_matricule())
        {
            valeur_compteur=compteur;
        }
        else
            compteur++;
    }

    m_avions_au_sol.erase(m_avions_au_sol.begin()+valeur_compteur);
}*/

