#include "AllAeroports.h"

DifferentsAeroports::DifferentsAeroports(){}
DifferentsAeroports::~DifferentsAeroports(){}

DifferentsAeroports::DifferentsAeroports(std::string Fichier)
{
    std::ifstream ifs{Fichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + Fichier );
    int Nombres_Aeroports;
    ifs >> Nombres_Aeroports;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre aero");
    string Nomaero, Local, AttenteSol, AccesPiste, TempsDecol, DelaiAnticol,DureeVol;
    int NbPistes, NbPlaces, DistanceVol;
    for(int i=0;i<Nombres_Aeroports;i++)
    {
        ifs>>Nomaero>>Local>>NbPistes>>NbPlaces>>AttenteSol>>AccesPiste>>DelaiAnticol>>TempsDecol>>DureeVol>>DistanceVol;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture aero");
        m_vect_aero.push_back(new InfosAeroport(Nomaero,Local, NbPistes, NbPlaces, AttenteSol, AccesPiste, DelaiAnticol, TempsDecol, DureeVol, DistanceVol));
    }
}


std::vector<InfosAeroport*> DifferentsAeroports::get_vecteur_aero(){return m_vect_aero;}
void DifferentsAeroports::set_vect_aero(std::vector<InfosAeroport*> val){m_vect_aero=val;}
void DifferentsAeroports::display()
{
    vector<InfosAeroport*> vect=get_vecteur_aero();
    for(auto a:vect)
    {
        std::cout<<" Nom aeroport : "<< a->get_Nom();
        std::cout<<"    Lieu aeroport : "<<a->get_Localisation()<<std::endl;
        std::cout<<"    Nombres Pistes : "<<a->get_Nombres_Pistes();
        std::cout<<"    Nombres Places: "<<a->get_Nombres_Places_Sol()<<std::endl;
        std::cout<<"    Attente Sol : "<<a->get_Attente_Sol();
        std::cout<<"    Temps Acces Piste : "<<a->get_Temps_Acces_Piste()<<std::endl;
        std::cout<<"    Delai Anticollision : "<<a->get_Delai_Anticolision();
        std::cout<<"    Temps Decollage Atterisssage : "<<a->get_Temps_Decollage_Atterissage()<<std::endl;
        std::cout<<"    Duree Attente Vol : "<<a->get_Duree_Attente_Vol();
        std::cout<<"    Distance : "<<a->get_Distance()<<std::endl;





    }
}
