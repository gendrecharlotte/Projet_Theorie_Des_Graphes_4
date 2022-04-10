#include "AllAeroports.h"

DifferentsAeroports::DifferentsAeroports() {}
DifferentsAeroports::~DifferentsAeroports() {}

//lecture du fichier d'aeroports
DifferentsAeroports::DifferentsAeroports(std::string Fichier)
{
    //verification lecture de fichier
    std::ifstream ifs{Fichier};
    //message d'erreur
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + Fichier );

    //lecture nombre d'aeroports
    int Nombres_Aeroports;
    ifs >> Nombres_Aeroports;
    //message d'erreur
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre aero");

    //lecture taille du graphe
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    //lecture de chaque aeroport pour le mettre dans le vecteur aeroport
    std::string Nomaero;
    int local_x, local_y,local_z=0, NbPistes, NbPlaces, DistanceVol, AttenteSol, AccesPiste, TempsDecol, DelaiAnticol,DureeVol;
    for(int i=0; i<Nombres_Aeroports; i++)
    {
        ifs>>Nomaero>>local_x>>local_y>>NbPistes>>NbPlaces>>AttenteSol>>AccesPiste>>DelaiAnticol>>TempsDecol>>DureeVol>>DistanceVol;
        std::vector<Avion*> vide;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture aero");
        Coordonnees Localisation(local_x,local_y,local_z);
        m_vect_aero.push_back(new InfosAeroport(i,Nomaero,Localisation, NbPistes, NbPlaces, AttenteSol, AccesPiste, DelaiAnticol, TempsDecol, DureeVol, DistanceVol, vide, vide));

        m_vect_aero[i]->init_poids(Nombres_Aeroports);
    }

    int num1,num2,poids;

    //ajout des successeurs de chaque sommet avec leurs poids respectifs, graphe non ordonné
    for(int j=0; j<taille; j++)
    {
        ifs>>num1>>num2>>poids;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc");
        m_vect_aero[num1]->ajouterSucc(m_vect_aero[num2]);
        m_vect_aero[num1]->ajouterpoids(poids, num2);
        m_vect_aero[num2]->ajouterSucc(m_vect_aero[num1]);
        m_vect_aero[num2]->ajouterpoids(poids, num1);
    }
}

std::vector<InfosAeroport*> DifferentsAeroports::get_vecteur_aero()
{
    return m_vect_aero;
}
void DifferentsAeroports::set_vect_aero(std::vector<InfosAeroport*> val)
{
    m_vect_aero=val;
}

//trouver l'indice de l'aeroport en fonction du nom de l'aeroport
int DifferentsAeroports::findAeroport(std::string nomaero,DifferentsAeroports Aeroports)
{
    bool trouve=false;

    int numero;

    for(unsigned int i=0; i<(Aeroports.get_vecteur_aero()).size(); i++)
    {
        //comparaison
        if(nomaero==(Aeroports.get_vecteur_aero())[i]->get_Nom())
        {
            trouve=true;
            numero=i;
        }
    }

    if(trouve==false)
    {
        std::cout<<"Erreur";
    }

    return numero;
}

//Trouver l'indice de l'aeroport en fonction des coordonnées
int DifferentsAeroports::findAeroport2(Coordonnees coo,DifferentsAeroports Aeroports)
{

    int numero;

    for(unsigned int i=0; i<(Aeroports.get_vecteur_aero()).size(); i++)
    {
        //comparaison
        if((coo.get_x()==(Aeroports.get_vecteur_aero())[i]->get_Localisation().get_x())&&(coo.get_y()==(Aeroports.get_vecteur_aero())[i]->get_Localisation().get_y()))
        {
            numero=i;
        }
    }

    return numero;
}

//Affichage du vecteur aeroports
void DifferentsAeroports::display()
{
    std::vector<InfosAeroport*> vect=get_vecteur_aero();
    for(auto a:vect)
    {
        std::cout<<" Nom                             : "<< a->get_Nom()<<std::endl;
        std::cout<<"    Coordonnees                  : "<<"("<<(a->get_Localisation()).get_x()<<","<<(a->get_Localisation()).get_y()<<")"<<std::endl;
        std::cout<<"    Pistes                       : "<<a->get_Nombres_Pistes()<<std::endl;
        std::cout<<"    Places au sol                : "<<a->get_Nombres_Places_Sol()<<std::endl;
        std::cout<<"    Delai obligatoire sol        : "<<a->get_Attente_Sol()<<" UT"<<std::endl;
        std::cout<<"    Temps acces pistes           : "<<a->get_Temps_Acces_Piste()<<" UT"<<std::endl;
        std::cout<<"    Delai anticollision          : "<<a->get_Delai_Anticolision()<<" UT"<<std::endl;
        std::cout<<"    Temps decollage/atterisssage : "<<a->get_Temps_Decollage_Atterissage()<<" UT"<<std::endl;
        std::cout<<"    Duree attente vol            : "<<a->get_Duree_Attente_Vol()<<" UT"<<std::endl;
        std::cout<<"    Distance                     : "<<a->get_Distance()<<std::endl<<std::endl;

    }
}

///sous programme de dijkstra
bool DifferentsAeroports::Dijkstra (int depart,int arrive,DifferentsAeroports Aeroports, int type, AllAvions Allavions)
{

    bool satisfied=false;
    bool condition=false;
    bool valide_cons=false;
    std::stack<InfosAeroport*> chemin_aero;
    std::string choix;
    int compteur=0;

    Avion* vol;
    std::vector<Avion*> m_vect_avi;
    m_vect_avi=Allavions.get_liste_avions();
    //on parcourt le vecteur avion pour récuperer les donnés de l'avion
    for(int i=0; i< (int)m_vect_avi.size(); i++ )
    {
        if(m_vect_avi[i]->get_type()==type)
        {
            vol=m_vect_avi[i];
        }
    }

    std::vector<InfosAeroport*> m_vect_aero=Aeroports.get_vecteur_aero();
    //variable qui verifie si tout les sommet ont été validé
    bool sparcouru = false;
    //vector de sommet et leurs etat
    std::vector<int> decouverte((int) m_vect_aero.size(), 0); // 0 : connait pas,   1: connait ,   2 : validé
    //vector qui comptabilise le poids du chemin
    std::vector<int>poid_final((int) m_vect_aero.size(), 0);
    //vecteur qui récupère les predecesseur
    std::vector<int>predecesseur((int) m_vect_aero.size(), -1);

    //on met notre sommet a connait car on vient de le rencontrer
    decouverte[depart] = 1;

    //faire tant que l'on a pas validé tous les sommets
    do
    {
        //on actualise a un poids très lourd pour que lorsque l'on compare les poids, le plus leger soit pris
        int poid_actuel = 150000;
        InfosAeroport * sommet_actuel;

        //Choix du prochain sommet
        for(int i = 0; i<(int) decouverte.size(); i++)
        {
            if(decouverte[i] == 1 && poid_final[i] < poid_actuel)
            {
                sommet_actuel = m_vect_aero[i];
                poid_actuel = poid_final[i];
            }
        }
        //le sommet de départ est validé
        decouverte[sommet_actuel->getNum()] = 2;

        //parours du sommet choisi
        for(auto s : sommet_actuel->getSuccesseurs())
        {
            valide_cons=vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]);

            //si le vecteur découverte est a 0
            if(decouverte[s->getNum()] == 0 && valide_cons==true)
            {
                //on découvre le prochain sommet
                decouverte[s->getNum()] = 1;
                //récupère le prédecesseur
                predecesseur[s->getNum()] = sommet_actuel->getNum();
                //met le nouveau poids
                poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];

                satisfied=true;
            }
            //si il à été deja connu
            else if(decouverte[s->getNum()] == 1 && valide_cons==true)
            {
                // std::cout<<std::endl <<"oups";
                //et que le poids final nouveau est inferieur à l'ancien
                if(poid_final[s->getNum()] > poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()])
                {
                    predecesseur[s->getNum()] = sommet_actuel->getNum();
                    //alors on change de chemin
                    poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];
                }
                satisfied=true;
            }
            //si la distance est trop grande et que le sommet n'est pas découvert
            else if (decouverte[arrive] != 2 && valide_cons==false)
            {
                satisfied=false;
            }
        }

        //Savoir si tous les sommets sont parcourus
        int cpt = 0;
        for(auto som : decouverte)
        {
            if(som == 2)
            {
                cpt ++;
            }
            if(cpt == (int)decouverte.size())
            {
                sparcouru = true;
            }
        }

        //compteur pour compter le nombre de fois que la boucle tourne
        compteur++;

        //si la boucle s'est executée trop de fois
        if(compteur>100)
        {
            condition=true;
        }
    }
    while((!sparcouru) && (condition==false)); //tant que tout n'est pas découvert ou si la

    //si chemin trouvé
    if(satisfied==true)
    {
        system("CLS");
        //Recuperation stack du chemin a prendre
        chemin_aero=Conversion_stack(predecesseur,arrive,depart, m_vect_aero);

        //affichage du chemin
        display_chemin(chemin_aero,arrive,depart, poid_final);
    }

    //retourne si on a trouvé ou pas
    return satisfied;
}

///sous programme de dijkstra qui renvoie le trajet
std::stack<InfosAeroport*> DifferentsAeroports::Dijkstra2 (int depart,int arrive,DifferentsAeroports Aeroports, int type, AllAvions Allavions)
{
    std::stack<InfosAeroport*> chemin_aero;
    std::string choix;

    std::vector<InfosAeroport*> m_vect_aero=Aeroports.get_vecteur_aero();
    //variable qui verifie si tout les sommet ont été validé
    bool sparcouru = false;
    //vector de sommet et leurs etat
    std::vector<int> decouverte((int) m_vect_aero.size(), 0); // 0 : connait pas,   1: connait ,   2 : validé
    //vector qui comptabilise le poids du chemin
    std::vector<int>poid_final((int) m_vect_aero.size(), 0);
    //vecteur qui récupère les predecesseur
    std::vector<int>predecesseur((int) m_vect_aero.size(), -1);

    //on met notre sommet a connait car on vient de le rencontrer
    decouverte[depart] = 1;

    //faire tant que l'on a pas validé tous les sommets
    do
    {
        //on actualise a un poids très lourd pour que lorsque l'on compare les poids, le plus leger soit pris
        int poid_actuel = 150000;
        InfosAeroport * sommet_actuel;

        //Choix du prochain sommet
        for(int i = 0; i<(int) decouverte.size(); i++)
        {
            if(decouverte[i] == 1 && poid_final[i] < poid_actuel)
            {
                sommet_actuel = m_vect_aero[i];
                poid_actuel = poid_final[i];
            }
        }
        //le sommet de départ est validé
        decouverte[sommet_actuel->getNum()] = 2;

        //parours du sommet choisi
        for(auto s : sommet_actuel->getSuccesseurs())
        {


            //si le vecteur découverte est a 0
            if(decouverte[s->getNum()] == 0)
            {
                //on découvre le prochain sommet
                decouverte[s->getNum()] = 1;
                //récupère le prédecesseur
                predecesseur[s->getNum()] = sommet_actuel->getNum();
                //met le nouveau poids
                poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];
            }
            //si il à été deja connu
            else if(decouverte[s->getNum()] == 1)
            {
                // std::cout<<std::endl <<"oups";
                //et que le poids final nouveau est inferieur à l'ancien
                if(poid_final[s->getNum()] > poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()])
                {
                    predecesseur[s->getNum()] = sommet_actuel->getNum();
                    //alors on change de chemin
                    poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];

                }
            }
        }

        //Savoir si tous les sommets sont parcourus
        int cpt = 0;
        for(auto som : decouverte)
        {
            if(som == 2)
            {
                cpt ++;
            }
            if(cpt == (int)decouverte.size())
            {
                sparcouru = true;
            }
        }
    }
    while(!sparcouru);

    //affichage
    chemin_aero=Conversion_stack(predecesseur,arrive,depart, m_vect_aero);

    return chemin_aero;
}

//Affichage d'un trajet
void DifferentsAeroports::display_chemin(std::stack<InfosAeroport* >chemin,int arrive, int depart, std::vector<int>poid_final)
{
    //Affichage du chemin
    std::cout<<std::endl<<"Voici votre trajet a realiser : "<<std::endl<<std::endl;
    do
    {
        std::cout<<(chemin.top())->get_Nom()<<std::endl;
        if(chemin.size()!=1)
            std::cout<<"v"<<std::endl;
        chemin.pop();

    }
    while(!chemin.empty());

    //poid total du chemin
    std::cout<<std::endl<< "Total de : "<< poid_final[arrive] <<" UE"<<std::endl;
}

//renvoie d'une pile contenant le trajet d'un avion
std::stack<InfosAeroport*> DifferentsAeroports::Conversion_stack(std::vector<int>predecesseur,int arrive, int depart, std::vector<InfosAeroport*> m_vect_aero)
{
    std::stack<InfosAeroport*> chemin_aero;
    int svoyage=arrive;

    do
    {
        chemin_aero.push(m_vect_aero[svoyage]);
        svoyage=predecesseur[svoyage];

    }
    while(svoyage!=depart);

    chemin_aero.push(m_vect_aero[svoyage]);

    return chemin_aero;
}

//calcul du pcc en fonction du type d'avion
void DifferentsAeroports::Calcul_PCC(DifferentsAeroports Aeroports, AllAvions Avions)
{
    //Variables
    bool satisfied=false;

    std::string aero_dep;
    std::string aero_arr;
    std::stack<InfosAeroport*> chemin_aero;
    int depart, arrivee;
    Avion* engin;
    int choix;

    //choix de l'aeroport de depart
    do
    {
        fflush(stdin);
        //entrée nom aeroport de depart
        std::cout << std::endl<<"Veuillez saisir l'aeroport de depart : ";
        std::cin>>aero_dep;

        //message d'erreur
        if(aero_dep!="Paris" && aero_dep!="NewYork" && aero_dep!="Haiti" && aero_dep!="LaPaz" && aero_dep!="CapeTown" && aero_dep!="Bangkok" && aero_dep!="Perth")
        {
            std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
        }
    }
    while(aero_dep!="Paris" && aero_dep!="NewYork" && aero_dep!="Haiti" && aero_dep!="LaPaz" && aero_dep!="CapeTown" && aero_dep!="Bangkok" && aero_dep!="Perth");

    //choix de l'aeroport d'arrivee
    do
    {
        std::cout << std::endl<<"Veuillez saisir l'aeroport d'arrive : ";
        std::cin>>aero_arr;
        if((aero_arr!="Paris" && aero_arr!="NewYork" && aero_arr!="Haiti" && aero_arr!="LaPaz" && aero_arr!="CapeTown" && aero_arr!="Bangkok" && aero_arr!="Perth"))
        {
            std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
        }
    }
    while((aero_arr!="Paris" && aero_arr!="NewYork" && aero_arr!="Haiti" && aero_arr!="LaPaz" && aero_arr!="CapeTown" && aero_arr!="Bangkok" && aero_arr!="Perth"));

    //choix du type d'avion
    do
    {
        std::cout << std::endl<<"Veuillez saisir le type d'avion utilise: ";
        std::cin>>choix;

        if(choix!=1 && choix!=2 && choix!=3)
        {
            std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
        }
    }
    while(choix!=1 && choix!=2 && choix!=3);

    //on recupere un avion lambda
    for(auto a:Avions.get_liste_avions())
    {
        if(choix==a->get_type())
        {
            engin=a; //on recupere l'avion en question
        }
    }

    //Recuperer indice aeroports
    depart=Aeroports.findAeroport(aero_dep, Aeroports);
    arrivee=Aeroports.findAeroport(aero_arr, Aeroports);

    //Calcul chemin le plus court
    satisfied=Aeroports.Dijkstra(depart,arrivee,Aeroports, engin->get_type(),Avions);

    //message d'impossibilité
    if(satisfied==false)
    {
        std::cout<<std::endl<<"Ce trajet n'est pas realisable."<<std::endl;
    }

}
