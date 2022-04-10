#include "Voyageur.h"

//constructeur/destructeur
Voyageur::Voyageur() {}
Voyageur::Voyageur(std::string nom,std::string depart,std::string arrivee, Avion* avion, int horaire):m_nom(nom),m_depart(depart), m_arrivee(arrivee), m_avion(*avion),m_horaire(horaire) {}
Voyageur::~Voyageur() {}

//getters/setters
std::string Voyageur::get_nom()const
{
    return m_nom;
}
std::string Voyageur::get_depart()const
{
    return m_depart;
}
std::string Voyageur::get_arrivee()const
{
    return m_arrivee;
}
Avion Voyageur::get_avion()const
{
    return m_avion;
}
int Voyageur::get_horaire()const
{
    return m_horaire;
}
void Voyageur::set_nom(std::string val)
{
    m_nom=val;
}
void Voyageur::set_depart(std::string val)
{
    m_depart=val;
}
void Voyageur::set_arrivee(std::string val)
{
    m_arrivee=val;
}
void Voyageur::set_avion(Avion val)
{
    m_avion=val;
}
void Voyageur::set_horaire(int val)
{
    m_horaire=val;
}

//Ecriture d'un nouveau vol dans un fichier
void Voyageur::write_Voyageur(Voyageur* voyageur)
{
    std::ofstream myFile("liste_voyageurs.txt",std::ios::app);
    if (!myFile)
    {
        throw std::runtime_error( "Impossible d'ouvrir en ecriture");
    }

    myFile << "\n" << voyageur->get_nom() <<"\n"; //Ecriture nom individu
    myFile << voyageur->get_depart()<<"\n"; //Ecriture ville de depart
    myFile << voyageur->get_arrivee()<<"\n"; //Ecriture ville d'arrivee
    myFile << (voyageur->get_avion()).get_matricule()<<"\n"; //Ecriture matricule d'avion
    myFile << (voyageur->get_avion()).get_type()<<"\n"; //Ecriture type d'avion
    myFile << (voyageur->get_avion()).get_consomation()<<"\n"; //Ecriture conso avion
    myFile << (voyageur->get_avion()).get_capacite()<<"\n"; //Ecriture capacite avion
    myFile << (voyageur->get_avion()).get_vitesse()<<"\n"; //Ecriture vitesse avion
    myFile << voyageur->get_horaire(); //Ecriture horaire du vol

    //fermeture de fichier
    myFile.close();
}

//affichage d'un voyageur
void Voyageur::display(Voyageur a)
{
    std::cout<<std::endl<<"    Nom                 : "<< a.get_nom()<<std::endl;
    std::cout<<"    Depart              : "<< a.get_depart()<<std::endl;
    std::cout<<"    Arrivee             : "<<a.get_arrivee()<<std::endl;
    std::cout<<"    Matricule           : "<<(a.get_avion()).get_matricule();
    std::cout<<"    Type                : "<< (a.get_avion()).get_type();
    std::cout<<"    Consommation        : "<<(a.get_avion()).get_consomation()<<" L/km";
    std::cout<<"    Capacite reservoir  : "<<(a.get_avion()).get_capacite()<<" L"<<std::endl;
    std::cout<<"    Vitesse             : "<<(a.get_avion()).get_vitesse()<<"UV"<<std::endl;
    std::cout<<"    Heure de depart     : "<<a.get_horaire()<<std::endl;
}
