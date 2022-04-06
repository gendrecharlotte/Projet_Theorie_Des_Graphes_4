#include "AllVoyageur.h"

///CONSTRUCTEURS/DESTRUCTEURS
//AllVoyageurs::AllVoyageurs(){}
AllVoyageurs::~AllVoyageurs(){}
AllVoyageurs::AllVoyageurs() //le constructeur lit le fichier pour consruire le vecteur de tous les Voyageur
{
    int nbr_personne;
    std::cout<<"Combien de vol souhaitez-vous enregistrer ? ";
    std::cin>>nbr_personne;
    std::cout<<std::endl;
    for(int i=0; i<nbr_personne; i++)
    {


        std::string nom_client;//récupère le nom du client
        std::cout<<"Veuillez entrer votre nom : ";
        std::cin>>nom_client;
        std::cout<<std::endl;

        std::string lieu_depart;//récupère l'aeroport de départ
        std::cout<<"D'ou souhaitez-vous partir ? ";
        std::cin>>lieu_depart;
        std::cout<<std::endl;

        std::string lieu_arrivee;//récupère l'aeroport d'arrivéé
        std::cout<<"Ou souhaitez-vous arriver ? ";
        std::cin>>lieu_arrivee;
        std::cout<<std::endl;

        int heure_depart;//récupère l'aeroport de départ
        std::cout<<"A quelle heure souhaitez vous partir ? ";
        std::cin>>heure_depart;
        std::cout<<std::endl;

        //met tout les infos dans un vecteur de class avion
        m_liste_voyageur.push_back(new Voyageur(nom_client, lieu_depart, lieu_arrivee, heure_depart));
    }
}

//getteur et setteur
std::vector<Voyageur*> AllVoyageurs::get_liste_Voyageur(){return m_liste_voyageur;}
void AllVoyageurs::set_liste_Voyageurs(std::vector<Voyageur*> val){m_liste_voyageur=val;}

//Methode
void AllVoyageurs::affichage()
{
    std::vector<Voyageur*> vect=get_liste_Voyageur();
    for(auto a:vect)
    {
        std::cout<<"    Nom             : "<< a->get_nom()<<std::endl;
        std::cout<<"    Depart          : "<< a->get_depart()<<std::endl;
        std::cout<<"    Arrivee         : "<<a->get_arrivee()<<std::endl;
        std::cout<<"    Heure de depart : "<<a->get_horaire()<<std::endl;
    }
}
