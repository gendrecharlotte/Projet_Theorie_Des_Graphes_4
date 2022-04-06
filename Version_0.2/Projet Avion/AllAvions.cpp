#include "AllAvions.h"

///CONSTRUCTEURS/DESTRUCTEURS
AllAvions::AllAvions(){}
AllAvions::~AllAvions(){}
AllAvions::AllAvions(std::string nomFichier) //le constructeur lit le fichier pour consruire le vecteur de tous les avions
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier ); //exception
    int nb_avions; //lecture du nombre d'avions
    ifs >> nb_avions;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre avions"); //exception
    int type,consomation,capacite; //temps pour création d'un nouvel avion
    for(int i=0;i<nb_avions;i++)
    {
        ifs>>type>>consomation>>capacite; //lecture données avion
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture avion"); //exception
        m_liste_avions.push_back(new Avion(type,consomation,capacite)); //création+ajout au vecteur
    }
}
///GETTERS/SETTERS
std::vector<Avion*> AllAvions::get_liste_avions(){return m_liste_avions;}
void AllAvions::set_liste_avions(std::vector<Avion*> val){m_liste_avions=val;}
///AFFICHAGE
void AllAvions::affichage()
{
    std::vector<Avion*> vect=get_liste_avions();
    for(auto a:vect)
    {
        std::cout<<"type d'avion : "<< a->get_type();
        std::cout<<"    Consomation : "<<a->get_consomation()<<" L/km";
        std::cout<<"    Recipient de carburant : "<<a->get_capacite()<<" L"<<std::endl;
    }
}
