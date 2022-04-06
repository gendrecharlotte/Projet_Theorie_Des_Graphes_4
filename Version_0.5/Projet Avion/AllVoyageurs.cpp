#include "AllVoyageur.h"

///CONSTRUCTEURS/DESTRUCTEURS
//AllVoyageurs::AllVoyageurs(){}
AllVoyageurs::~AllVoyageurs(){}
AllVoyageurs::AllVoyageurs() //le constructeur lit le fichier pour consruire le vecteur de tous les Voyageur
{
    int nbr_personne;
    std::cout<<"combien de vol souhaites vous enregistrer?: ";
    std::cin>>nbr_personne;
    std::cout<<std::endl;
    for(int i=0; i<nbr_personne; i++)
    {


        std::string nom_client;//récupère le nom du client
        std::cout<<"veuillez entrez votre nom: ";
        std::cin>>nom_client;
        std::cout<<std::endl;

        std::string lieu_depart;//récupère l'aeroport de départ
        std::cout<<"D'ou souhaitez vous partir?: ";
        std::cin>>lieu_depart;
        std::cout<<std::endl;

        std::string lieu_arrivee;//récupère l'aeroport d'arrivéé
        std::cout<<"Ou souhaitez vous arrivez?: ";
        std::cin>>lieu_arrivee;
        std::cout<<std::endl;

        int heure_depart;//récupère l'aeroport de départ
        std::cout<<"A quelle heure souhaitez vous partir?: ";
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
        std::cout<<"Votre nom : "<< a->get_nom();
        std::cout<<"    départ: "<< a->get_depart();
        std::cout<<"    arrivee: "<<a->get_arrivee();
        std::cout<<"    heure de depart: "<<a->get_horaire()<<std::endl;
    }
}
