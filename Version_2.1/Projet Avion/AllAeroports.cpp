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
bool DifferentsAeroports::Dijkstra (int depart,int arrive,DifferentsAeroports Aeroports, int type, AllAvions Allavions)
{

    bool satisfied=false;
    bool condition=false;
    std::stack<InfosAeroport*> chemin_aero;
    std::string choix;
    int compteur=0;

    Avion* vol;
    std::vector<Avion*> m_vect_avi;
    m_vect_avi=Allavions.get_liste_avions();
    //on parcourt le vecteur avion pour r??cuperer les donn??s de l'avion
    for(int i=0; i< (int)m_vect_avi.size(); i++ )
    {
        if(m_vect_avi[i]->get_type()==type)
        {
            vol=m_vect_avi[i];
        }
    }

    std::vector<InfosAeroport*> m_vect_aero=Aeroports.get_vecteur_aero();
    //variable qui verifie si tout les sommet ont ??t?? valid??
    bool sparcouru = false;
    //vector de sommet et leurs etat
    std::vector<int> decouverte((int) m_vect_aero.size(), 0); // 0 : connait pas,   1: connait ,   2 : valid??
    //vector qui comptabilise le poids du chemin
    std::vector<int>poid_final((int) m_vect_aero.size(), 0);
    //vecteur qui r??cup??re les predecesseur
    std::vector<int>predecesseur((int) m_vect_aero.size(), -1);

    //on met notre sommet a connait car on vient de le rencontrer
    decouverte[depart] = 1;

    //faire tant que l'on a pas valid?? tous les sommets
    do
    {
        //on actualise a un poids tr??s lourd pour que lorsque l'on compare les poids, le plus leger soit pris
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
        //le sommet de d??part est valid??
        decouverte[sommet_actuel->getNum()] = 2;

        //parours du sommet choisi
        for(auto s : sommet_actuel->getSuccesseurs())
        {
            //si le vecteur d??couverte est a 0
            if(decouverte[s->getNum()] == 0 && vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]) >0)
            {
                //on d??couvre le prochain sommet
                decouverte[s->getNum()] = 1;
                //r??cup??re le pr??decesseur
                predecesseur[s->getNum()] = sommet_actuel->getNum();
                //met le nouveau poids
                poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];

                satisfied=true;
            }
            //si il ?? ??t?? deja connu
            else if(decouverte[s->getNum()] == 1 && vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]) > 0)
            {
                // std::cout<<std::endl <<"oups";
                //et que le poids final nouveau est inferieur ?? l'ancien
                if(poid_final[s->getNum()] > poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()])
                {
                    predecesseur[s->getNum()] = sommet_actuel->getNum();
                    //alors on change de chemin
                    poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];
                    satisfied=true;

                }
                //std::cout<<std::endl <<poid_final[s->getNum()]<<" s  "<<s->getNum()<<"   " << sommet_actuel->getNum()<<std::endl;
            }
            else if(decouverte[s->getNum()] == 0 && vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]) <0)
            {
                satisfied=false;
            }
            else if(decouverte[s->getNum()] == 1 && vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]) <0)
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

        compteur++;

        if(compteur>100)
        {
            condition=true;
            //satisfied=false;
        }

        //std::cout<<"c= "<<compteur<<std::endl;
    }
    while((!sparcouru) && (condition==false));

    //si chemin trouv??
    if(satisfied==true)
    {
        system("CLS");
        //Recuperation stack du chemin a prendre
        chemin_aero=Conversion_stack(predecesseur,arrive,depart, m_vect_aero);

        //affichage du chemin
        display_chemin(chemin_aero,arrive,depart, poid_final);
    }

    //retourne si on a trouv?? ou pas
    return satisfied;
}

///sous programme de dijkstra pour recuperer le stack chemin
std::stack<InfosAeroport*> DifferentsAeroports::Dijkstra2 (int depart,int arrive,DifferentsAeroports Aeroports, int type, AllAvions Allavions)
{
    std::stack<InfosAeroport*> chemin_aero;
    std::string choix;

    Avion* vol;
    std::vector<Avion*> m_vect_avi;
    m_vect_avi=Allavions.get_liste_avions();
    //on parcourt le vecteur avion pour r??cuperer les donn??s de l'avion
    for(int i=0; i< (int)m_vect_avi.size(); i++ )
    {
        if(m_vect_avi[i]->get_type()==type)
        {
            vol=m_vect_avi[i];
        }
    }

    std::vector<InfosAeroport*> m_vect_aero=Aeroports.get_vecteur_aero();
    //variable qui verifie si tout les sommet ont ??t?? valid??
    bool sparcouru = false;
    //vector de sommet et leurs etat
    std::vector<int> decouverte((int) m_vect_aero.size(), 0); // 0 : connait pas,   1: connait ,   2 : valid??
    //vector qui comptabilise le poids du chemin
    std::vector<int>poid_final((int) m_vect_aero.size(), 0);
    //vecteur qui r??cup??re les predecesseur
    std::vector<int>predecesseur((int) m_vect_aero.size(), -1);

    //on met notre sommet a connait car on vient de le rencontrer
    decouverte[depart] = 1;

    //faire tant que l'on a pas valid?? tous les sommets
    do
    {
        //on actualise a un poids tr??s lourd pour que lorsque l'on compare les poids, le plus leger soit pris
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
        //le sommet de d??part est valid??
        decouverte[sommet_actuel->getNum()] = 2;

        //parours du sommet choisi
        for(auto s : sommet_actuel->getSuccesseurs())
        {
            //si le vecteur d??couverte est a 0
            if(decouverte[s->getNum()] == 0 && vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]) >0)
            {
                //on d??couvre le prochain sommet
                decouverte[s->getNum()] = 1;
                //r??cup??re le pr??decesseur
                predecesseur[s->getNum()] = sommet_actuel->getNum();
                //met le nouveau poids
                poid_final[s->getNum()] = poid_final[sommet_actuel->getNum()] + sommet_actuel->getpoids()[s->getNum()];
            }
            //si il ?? ??t?? deja connu
            else if(decouverte[s->getNum()] == 1 && vol->cl_consomation(sommet_actuel->getpoids()[s->getNum()]) >0)
            {
                // std::cout<<std::endl <<"oups";
                //et que le poids final nouveau est inferieur ?? l'ancien
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

    //affichage
    chemin_aero=Conversion_stack(predecesseur,arrive,depart, m_vect_aero);

    return chemin_aero;
}

/*std::stack<int> DifferentsAeroports::Creer_stack_chemin(std::vector<int>predecesseur,int arrive, int depart)
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

    return chemin;
}*/

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
    std::cout<<std::endl<< "Total de : "<< poid_final[arrive] <<" km"<<std::endl;
}

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
