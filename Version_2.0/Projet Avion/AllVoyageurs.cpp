#include "AllVoyageurs.h"

///CONSTRUCTEURS/DESTRUCTEURS
AllVoyageurs::AllVoyageurs() {}
AllVoyageurs::AllVoyageurs(std::string Fichier, AllAvions* Avions)
{

    //Avion avion;
    std::string nom;
    std::string depart, arrive;
    int matricule, type, consommation, capacite, vitesse;
    int horaire;

    //Ouverture de fichier
    std::ifstream myFile{Fichier};

    //message d'erreur d'ouverture de fichier
    if (!myFile)
    {
        throw std::runtime_error( "Impossible d'ouvrir en lecture ");
    }


    //tant que le fichier n'est pas a sa fin
    while(myFile.good())
    {
        //lecture du nom
        myFile >> nom;
        //erreur lecture nom
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture du nom");
        }

        //lecture de l'aeroport de depart
        myFile >> depart;
        //erreur lecture aeroport de depart
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture de l'aeroport de depart");
        }
        //lecture de l'aeroport d'arrive
        myFile >> arrive;
        //erreur lecture aeroport d'arrive
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture de l'aeroport d'arrive");
        }

        //lecture de matricule
        myFile >> matricule;
        //erreur lecture de matricule
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture du matricule");
        }

        //lecture du type d'avion
        myFile >> type;
        //erreur lecture du type
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture du type");
        }

        //lecture de la consommation
        myFile >> consommation;
        //erreur lecture de la consommation
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture de la consommation");
        }

        //lecture de capacité
        myFile >> capacite;
        //erreur de lecture de capacité
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture de la capacite");
        }

        //lecture de vitesse
        myFile >> vitesse;
        //erreur de lecture de capacité
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture de la vitesse");
        }


        //lecture d'horaire
        myFile >> horaire;
        //erreur de lecture d'horaire
        if(myFile.fail() )
        {
            throw std::runtime_error("Erreur de lecture de l'horaire");
        }

        //variables temporaires
        BITMAP *img;
        Coordonnees coo(0,0);
        std::stack<InfosAeroport*> trajet;

        //ajout dans le vecteur de voyageurs
        m_liste_voyageur.push_back(new Voyageur (nom, depart, arrive, (new Avion (matricule, type, consommation, capacite,vitesse,0,0,0,img,coo,false,trajet)), horaire));
        /*Avion avion(matricule, type, consommation, capacite);
        Avions->remove_avion(&avion);*/
    }

}

AllVoyageurs::~AllVoyageurs() {}

//Creation d'un voyageur/ vol
Voyageur AllVoyageurs::CreerVoyageurs(DifferentsAeroports Aeroports, AllAvions Avions, Interface I)
{
    ///VARIABLES
    bool satisfied=false;
    std::string nom_client;//récupère le nom du client
    int heure_depart;//récupère l'aeroport de départ
    DifferentsAeroports diff;
    std::string aero_dep;
    std::string aero_arr;
    int depart, arrivee;
    int type_def;
    int indice_aero;
    std::string choix;
    Avion* engin;
    std::stack<InfosAeroport*> chemin_aero;

    //tant que l'utilisateur n'est pas satisfait
    do
    {
        system("CLS");
        bool saisie1=true; //si la saisie est correct, true, sinon false
        bool saisie2=true;
        bool avion_dispo;
        bool avion_trouve=false;
        bool choix_avion=false;

        //Nom utilisateur
        std::cout<<"Veuillez entrer votre nom : ";
        std::cin>>nom_client;
        std::cout<<std::endl;

        //Heure de départ
        std::cout<<"A quelle heure souhaitez vous partir ? ";
        std::cin>>heure_depart;
        std::cout<<std::endl;

        do
        {

            //choix aeroport de depart
            do
            {
                //entrée nom aeroport de depart
                std::cout << "Veuillez saisir l'aeroport de depart : ";
                std::cin>>aero_dep;

                //message d'erreur
                if(aero_dep!="Paris" && aero_dep!="NewYork" && aero_dep!="Haiti" && aero_dep!="LaPaz" && aero_dep!="CapeTown" && aero_dep!="Bangkok" && aero_dep!="Perth")
                {
                    saisie1=false;
                    std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
                }
                else
                {
                    saisie1=true;
                }

            }
            while(!saisie1);

            //Recherche indice de l'aeroport
            indice_aero=diff.findAeroport(aero_dep, Aeroports);

            //message si il n'y a pas d'avions disponibles
            if(((Aeroports.get_vecteur_aero())[indice_aero]->get_avions_au_sol()).size()==0)
            {
                std::cout<<std::endl<<"Il n'y a pas d'avions disponibles a cette horaire."<<std::endl;
            }
            else
            {
                avion_dispo=true;
            }
        }
        while(avion_dispo==false);

        //choix type d'avion
        do
        {

            do
            {
                system("CLS");

                std::vector<Avion*> avions_disponibles=(Aeroports.get_vecteur_aero())[indice_aero]->get_avions_au_sol();
                std::cout<<std::endl<<"Voici les avions disponibles: "<<std::endl;
                for(auto a:avions_disponibles)
                {
                    std::cout<<"Matricule : "<<a->get_matricule();
                    std::cout<<"    Type : "<< a->get_type();
                    std::cout<<std::endl;
                }

                std::cout<<std::endl<<"Veuillez saisir le matricule d'avion : ";
                std::cin>>type_def;

                for(auto a:avions_disponibles)
                {
                    if(type_def==a->get_matricule())
                    {
                        avion_trouve=true;
                        engin=a;
                    }
                }

                if(avion_trouve==false)
                {
                    std::cout<<"Cet avion est introuvable.";
                    Sleep(2000);
                }

            }
            while(avion_trouve==false);


            //choixi aeroport d'arrive
            do
            {
                std::cout << "Veuillez saisir l'aeroport d'arrive : ";
                std::cin>>aero_arr;
                if((aero_arr!="Paris" && aero_arr!="NewYork" && aero_arr!="Haiti" && aero_arr!="LaPaz" && aero_arr!="CapeTown" && aero_arr!="Bangkok" && aero_arr!="Perth"))
                {
                    saisie2=false;
                    std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
                }
                else
                {
                    saisie2=true;
                }

            }
            while(!saisie2);

            //Recuperer indice aeroports
            depart=diff.findAeroport(aero_dep, Aeroports);
            arrivee=diff.findAeroport(aero_arr, Aeroports);

            //Calcul chemin le plus court
            choix_avion=diff.Dijkstra(depart,arrivee,Aeroports, engin->get_type(),Avions);

            if(choix_avion==false)
            {
                std::cout<<std::endl<<"Ce vol n'est pas possible avec cet avion, reessayez"<<std::endl;
                Sleep(2000);
            }

        }
        while(choix_avion==false);
        Voyageur voya (nom_client, aero_dep, aero_arr, engin, heure_depart);

        do
        {
            //affichage
            chemin_aero=diff.Dijkstra2(depart, arrivee, Aeroports, engin->get_type(),Avions);
            engin->set_trajet(chemin_aero);
            Voyageur voya (nom_client, aero_dep, aero_arr, engin, heure_depart);

            I.tracer_chemin(voya);

            std::cout<<std::endl<<"Ce chemin vous convient-il? (Oui/Non)"<<std::endl;
            std::cin>>choix;

            if((choix!="Oui")&&(choix!="Non"))
            {
                std::cout<<std::endl<<"Erreur d'entree, veuillez reessayer";
                Sleep(2000);
            }
        }
        while((choix!="Oui")&&(choix!="Non"));

        if(choix=="Oui")
        {
            satisfied=true;
        }

    }
    while(satisfied==false);

    //met tout les infos dans un vecteur de class avion


    Voyageur voyageur(nom_client, aero_dep, aero_arr, engin, heure_depart);

    m_liste_voyageur.push_back(new Voyageur (nom_client, aero_dep, aero_arr, engin, heure_depart));
    voyageur.write_Voyageur(&voyageur);
    //(Aeroports.get_vecteur_aero())[depart]->remove_avion_aero(engin);

    system("CLS");
    voyageur.display(voyageur);
    std::cout<<std::endl;


    return voyageur;
}

//getteur et setteur
std::vector<Voyageur*> AllVoyageurs::get_liste_Voyageur()
{
    return m_liste_voyageur;
}
void AllVoyageurs::set_liste_Voyageurs(std::vector<Voyageur*> val)
{
    m_liste_voyageur=val;
}

//Methode
void AllVoyageurs::affichage()
{
    std::vector<Voyageur*> vect=get_liste_Voyageur();
    for(auto a:vect)
    {
        std::cout<<std::endl<<"    Nom                : "<< a->get_nom()<<std::endl;
        std::cout<<"    Depart             : "<< a->get_depart()<<std::endl;
        std::cout<<"    Arrivee            : "<<a->get_arrivee()<<std::endl;
        std::cout<<"    Matricule          : "<<(a->get_avion()).get_matricule();
        std::cout<<"    Type: "<< (a->get_avion()).get_type();
        std::cout<<"    Consommation: "<<(a->get_avion()).get_consomation()<<" L/km";
        std::cout<<"    Capacite reservoir: "<<(a->get_avion()).get_capacite()<<" L"<<std::endl;
        std::cout<<"    Heure de depart    : "<<a->get_horaire()<<std::endl;

    }
}
