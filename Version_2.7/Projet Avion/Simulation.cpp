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
    //INITIALISATION AVIONS EN VOL
    std::vector<Avion*> avions_en_vol;
    //ATTRIBUTION TRAJET ALEATOIRE
    for(auto a:allavions.get_liste_avions())
    {
        std::stack<InfosAeroport*> traj;
        for(int i=0;i<rand()%5+1;i++)
        {
            traj.push(allaeroports.get_vecteur_aero()[rand()%7]);
        }
        a->set_trajet(traj);
    }
    //COPIE DU VECTEUR CONTENANT TOUS LES AVIONS DE LA SIMULATION
    std::vector<Avion*> avions=allavions.get_liste_avions();
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
            if(avions.size()!=0)
            {
                //PIOCHAGE D'UN INDICE AU HASARD CORRESPONDANT A UN AVION SELECTIONNE POUR ETRE DANS LA LISTE
                int indice_avion=rand()%(avions.size());
                //DECLARATION ALEATOIRE AVION EN DECOLLAGE/ATTERISSAGE
                avions[indice_avion]->set_etat(rand()%2 +2);
                //COMPTEUR ATTENTE ALEATOIRE
                avions[indice_avion]->set_tmp_atterir(rand()%a->get_Temps_Decollage_Atterissage());
                //SET DES COORDONNEES
                Coordonnees coo=a->get_Localisation();
                avions[indice_avion]->set_coo(coo);
                //PLACEMENT DANS LE VECTEUR DES AVIONS SUR PISTES
                pistes.push_back(avions[indice_avion]);
                //SUPPRESSION DANS LE VECTEUR TEMPORAIRE DES AVIONS
                avions.erase(avions.begin()+indice_avion);
            }
        }
        ///SOL
        //REMPLISSAGE PAR AVIONS ALEATOIRES CONTENUS DANS LE VECTEUR
        for(int j=0;j<nb_sol_pris;j++)
        {
            if(avions.size()!=0)
            {
                //PIOCHAGE D'UN INDICE AU HASARD CORRESPONDANT A UN AVION SELECTIONNE POUR ETRE DANS LA LISTE
                int indice_avion2=rand()%(avions.size());
                //DECLARATION AVION AU SOL
                avions[indice_avion2]->set_etat(1);
                //COMPTEUR ACCES PISTES ALEATOIRE
                avions[indice_avion2]->set_tmp_acces(rand()%a->get_Temps_Acces_Piste());
                //SET DES COORDONNEES
                Coordonnees coo=a->get_Localisation();
                avions[indice_avion2]->set_coo(coo);
                //PLACEMENT DANS LE VECTEUR DES AVIONS AU SOL
                sol.push_back(avions[indice_avion2]);
                //SUPPRESSION DANS LE VECTEUR TEMPORAIRE DES AVIONS
                avions.erase(avions.begin()+indice_avion2);
            }
        }
        //SETTING
        a->set_avions_sur_pistes(pistes);
        a->set_avions_au_sol(sol);
        //VERIFICATION TEMPORAIRE==========================================================================
        /*std::cout<<a->get_Nom()<<std::endl<<"pistes ->"<<std::endl;
        for(auto s:(a->get_avions_sur_pistes()))
        {
            std::cout<<"   "<<s->get_matricule()<<" "<<s->get_etat()<<" "<<s->get_trajet().size()<<std::endl;
        }
        std::cout<<"sol ->"<<std::endl;
        for(auto s:(a->get_avions_au_sol()))
        {
            std::cout<<"   "<<s->get_matricule()<<" "<<s->get_etat()<<" "<<s->get_trajet().size()<<std::endl;
        }*/
    }

    if(avions.size()!=0)
    {
        for(auto &a:avions)
        {
            a->set_etat(4);
            int x=rand()%877 + 387;
            int y=rand()%440 + 215;
            Coordonnees c;
            c.set_x(x);
            c.set_y(y);
            a->set_coo(c);
            m_avions_en_vol.push_back(a);
        }
    }
    /*std::cout<<"__________________________________________"<<std::endl<<"EN VOL :"<<std::endl;
    for(auto s:get_avions_en_vol())
    {
        std::cout<<"   "<<s->get_matricule()<<" "<<s->get_etat()<<" "<<s->get_trajet().size()<<std::endl;
    }*/
}
