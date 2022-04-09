#include "Simulation.h"
#include <cstdlib>
#include <ctime>

///CONSTRUCTEURS/DESTRUCTEURS
Simulation::Simulation(){}
Simulation::Simulation(std::vector<Avion*> avions_en_vol):m_avions_en_vol(avions_en_vol){}
Simulation::~Simulation(){}

///GETTERS/SETTERS
std::vector<Avion*> Simulation::get_avions_en_vol()const{return m_avions_en_vol;}
void Simulation::set_avions_en_vol(std::vector<Avion*> val){m_avions_en_vol=val;}
///METHODES
void Simulation::initialisation(DifferentsAeroports allaeroports, AllAvions allavions)
{
    srand((unsigned int)time(0));
    //COPIE DU VECTEUR CONTENANT TOUS LES AVIONS DE LA SIMULATION
    std::vector<Avion*> avions=allavions.get_liste_avions();
    //INITIALISATION AVIONS EN VOL
    std::vector<Avion*> avions_en_vol;
    //PARCOURS VECTEUR DE TOUS LES AEROPORTS
    for(auto &a : (allaeroports.get_vecteur_aero()))
    {
        //CREATION VECTEUR RECEVANT AVIONS SUR PISTES QU'ON SETTERA POUR A
        std::vector<Avion*> pistes;
        //CREATION VECTEUR RECEVANT AVIONS AU SOL QU'ON SETTERA POUR A
        std::vector<Avion*> sol;
        //CHOIX ALEATOIRE DU NOMBRE DE PISTES À REMPLIR SELON LE NOMBRE DE PISTES DE L'AEROPORT
        int nb_pistes_prises=rand()%(a->get_Nombres_Pistes());
        int nb_sol_pris=rand()%(a->get_Nombres_Places_Sol());
        ///PISTES
        //REMPLISSAGE PAR AVIONS ALEATOIRES CONTENUS DANS LE VECTEUR
        for(int i=0;i<nb_pistes_prises;i++)
        {
            //PIOCHAGE D'UN INDICE AU HASARD CORRESPONDANT A UN AVION SELECTIONNE POUR ETRE DANS LA LISTE
            int indice_avion=rand()%(avions.size()+1);
            //DECLARATION ALEATOIR AVION EN DECOLLAGE/ATTERISSAGE
            avions[indice_avion]->set_da(rand()%2);
            //SET DES COORDONNEES
            avions[indice_avion]->set_coo(a->get_Localisation());
            //PLACEMENT DANS LE VECTEUR DES AVIONS SUR PISTES
            pistes.push_back(avions[indice_avion]);
            //SUPPRESSION DANS LE VECTEUR TEMPORAIRE DES AVIONS
            avions.erase(avions.begin()+indice_avion);
        }
        ///SOL
        //REMPLISSAGE PAR AVIONS ALEATOIRES CONTENUS DANS LE VECTEUR
        for(int j=0;j<nb_sol_pris;j++)
        {
            //PIOCHAGE D'UN INDICE AU HASARD CORRESPONDANT A UN AVION SELECTIONNE POUR ETRE DANS LA LISTE
            int indice_avion2=rand()%(avions.size());
            //SET DES COORDONNEES
            avions[indice_avion2]->set_coo(a->get_Localisation());
            //PLACEMENT DANS LE VECTEUR DES AVIONS AU SOL
            sol.push_back(avions[indice_avion2]);
            //SUPPRESSION DANS LE VECTEUR TEMPORAIRE DES AVIONS
            avions.erase(avions.begin()+indice_avion2);
        }
        //SETTING
        a->set_avions_sur_pistes(pistes);
        a->set_avions_au_sol(sol);
        //VERIFICATION TEMPORAIRE==========================================================================
        std::cout<<a->get_Nom()<<std::endl<<"pistes ->"<<std::endl;
        for(auto s:(a->get_avions_sur_pistes()))
        {
            std::cout<<"   "<<s->get_matricule()<<" "<<s->get_da()<<std::endl;
        }
        std::cout<<"sol ->"<<std::endl;
        for(auto s:(a->get_avions_au_sol()))
        {
            std::cout<<"   "<<s->get_matricule()<<std::endl;
        }
    }
    for(auto &a:avions)
    {
        int x=rand()%877+387;
        int y=rand()%440+215;
        Coordonnees c;
        c.set_x(x);
        c.set_y(y);
        a->set_coo(c);
        m_avions_en_vol.push_back(a);
    }
    std::cout<<"__________________________________________"<<std::endl<<"EN VOL :"<<std::endl;
    for(auto s:get_avions_en_vol())
    {
        std::cout<<"   "<<s->get_matricule()<<std::endl;
    }
}
