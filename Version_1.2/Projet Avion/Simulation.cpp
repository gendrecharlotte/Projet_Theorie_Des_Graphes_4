#include "Simulation.h"
#include <cstdlib>
#include <ctime>

///CONSTRUCTEURS/DESTRUCTEURS
Simulation::Simulation(){}
Simulation::~Simulation(){}

///METHODES
void Simulation::initialisation(DifferentsAeroports allaeroports, AllAvions allavions)
{
    srand((unsigned int)time(0));
    //COPIE DU VECTEUR CONTENANT TOUS LES AVIONS DE LA SIMULATION
    std::vector<Avion*> avions=allavions.get_liste_avions();
    //PARCOURS VECTEUR DE TOUS LES AEROPORTS
    //std::cout<<avions.size()<<std::endl;
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
            int indice_avion=rand()%(avions.size());
            //PLACEMENT DANS LE VECTEUR DES AVIONS SUR PISTES
            pistes.push_back(avions[indice_avion]);
            //SUPPRESSION DANS LE VECTEUR TEMPORAIRE DES AVIONS
            avions.erase(avions.begin()+indice_avion);
        }
        //std::cout<<avions.size()<<std::endl;
        ///SOL
        //REMPLISSAGE PAR AVIONS ALEATOIRES CONTENUS DANS LE VECTEUR
        for(int j=0;j<nb_sol_pris;j++)
        {
            //PIOCHAGE D'UN INDICE AU HASARD CORRESPONDANT A UN AVION SELECTIONNE POUR ETRE DANS LA LISTE
            int indice_avion2=rand()%(avions.size());
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
            std::cout<<"   "<<s->get_matricule()<<std::endl;
        }
        std::cout<<"sol ->"<<std::endl;
        for(auto s:(a->get_avions_au_sol()))
        {
            std::cout<<"   "<<s->get_matricule()<<std::endl;
        }
    }
}
