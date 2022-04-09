#include "AllAeroports.h"

DifferentsAeroports::DifferentsAeroports() {}
DifferentsAeroports::~DifferentsAeroports() {}

DifferentsAeroports::DifferentsAeroports(std::string Fichier)
{
    std::ifstream ifs{Fichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + Fichier );
    int Nombres_Aeroports;
    ifs >> Nombres_Aeroports;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre aero");
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string Nomaero;
    int local_x, local_y, NbPistes, NbPlaces, DistanceVol, AttenteSol, AccesPiste, TempsDecol, DelaiAnticol,DureeVol;
    for(int i=0; i<Nombres_Aeroports; i++)
    {
        ifs>>Nomaero>>local_x>>local_y>>NbPistes>>NbPlaces>>AttenteSol>>AccesPiste>>DelaiAnticol>>TempsDecol>>DureeVol>>DistanceVol;
        std::vector<Avion*> vide;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture aero");
        Coordonnees Localisation(local_x,local_y);
        m_vect_aero.push_back(new InfosAeroport(i,Nomaero,Localisation, NbPistes, NbPlaces, AttenteSol, AccesPiste, DelaiAnticol, TempsDecol, DureeVol, DistanceVol, vide, vide));

        m_vect_aero[i]->init_poids(Nombres_Aeroports);
    }

    int num1,num2,poids;
    //int x=taille*2;
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

int DifferentsAeroports::findAeroport(std::string nomaero,DifferentsAeroports Aeroports)
{
    bool trouve=false;

    int numero;

    for(unsigned int i=0; i<(Aeroports.get_vecteur_aero()).size(); i++)
    {
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

int DifferentsAeroports::findAeroport2(Coordonnees coo,DifferentsAeroports Aeroports)
{

    int numero;

    for(unsigned int i=0; i<(Aeroports.get_vecteur_aero()).size(); i++)
    {
        if((coo.get_x()==(Aeroports.get_vecteur_aero())[i]->get_Localisation().get_x())&&(coo.get_y()==(Aeroports.get_vecteur_aero())[i]->get_Localisation().get_y()))
        {
            numero=i;
        }
    }

    return numero;
}

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
void DifferentsAeroports::Dijkstra (int depart,int arrive,DifferentsAeroports Aeroports)
{
    bool satisfied=false;
    std::string choix;

    do
    {
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
                if(decouverte[s->getNum()] == 1)
                {
                    // std::cout<<std::endl <<"oups";
                    //et que le poids final nouveau est inferieur à l'ancien
                    if(poid_final[s->getNum()] > poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()])
                    {
                        predecesseur[s->getNum()] = sommet_actuel->getNum();
                        //alors on change de chemin
                        poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];

                    }
                    //std::cout<<std::endl <<poid_final[s->getNum()]<<" s  "<<s->getNum()<<"   " << sommet_actuel->getNum()<<std::endl;
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

        do
        {
            system("CLS");

            //affichage
            display_chemin(predecesseur,arrive,depart,m_vect_aero, poid_final);

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

}

void DifferentsAeroports::display_chemin(std::vector<int>predecesseur,int arrive, int depart, std::vector<InfosAeroport*> m_vect_aero, std::vector<int>poid_final)
{
    std::stack<int>chemin;

    //Inversion du vecteur predecesseur pour l'affichage
    int svoyage=arrive;
    do
    {

        chemin.push(svoyage);
        svoyage=predecesseur[svoyage];

    }
    while(svoyage!=depart);

    chemin.push(svoyage);

    //Affichage du chemin
    std::cout<<std::endl<<"Voici votre trajet a realiser : "<<std::endl<<std::endl;
    do
    {
        std::cout<<m_vect_aero[chemin.top()]->get_Nom()<<std::endl;
        if(chemin.size()!=1)
            std::cout<<"v"<<std::endl;
        chemin.pop();

    }
    while(!chemin.empty());

    //poid total du chemin
    std::cout<<std::endl<< "Total de : "<< poid_final[arrive] <<" km"<<std::endl;
}
