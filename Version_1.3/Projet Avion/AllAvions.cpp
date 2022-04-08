#include "AllAvions.h"

///CONSTRUCTEURS/DESTRUCTEURS
AllAvions::AllAvions(){}
AllAvions::~AllAvions(){}
AllAvions::AllAvions(std::string nomFichier) //le constructeur lit le fichier pour consruire le vecteur de tous les avions
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier ); //exception
    int nb_avions; //lecture du nombre d'avions
    ifs >> nb_avions;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre avions"); //exception
    int matricule,type,consomation,capacite; //temps pour création d'un nouvel avion
    BITMAP *img;
    Coordonnees coo(0,0);
    //std::stack<Aeroport*> trajet;
    for(int i=0;i<nb_avions;i++)
    {
        ifs>>matricule>>type>>consomation>>capacite; //lecture données avion
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture avion"); //exception
        /*if(type==3)
            img=load_bitmap("images/avion_3.bmp",NULL);
        else if(type==2)
            img=load_bitmap("images/avion_2.bmp",NULL);
        else if(type==1)
            img=load_bitmap("images/avion_1.bmp",NULL);
        if (!img)
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit(); exit(EXIT_FAILURE);
        }*/

        m_liste_avions.push_back(new Avion(matricule,type,consomation,capacite,img,coo,false/*,trajet*/)); //création+ajout au vecteur
    }
}
///GETTERS/SETTERS
std::vector<Avion*> AllAvions::get_liste_avions(){return m_liste_avions;}
void AllAvions::set_liste_avions(std::vector<Avion*> val){m_liste_avions=val;}
///AFFICHAGE
void AllAvions::affichage()
{
    std::vector<Avion*> vect=get_liste_avions();
    for(auto a:vect)
    {
        std::cout<<"Matricule : "<<a->get_matricule();
        std::cout<<"    Type : "<< a->get_type();
        std::cout<<"    Consommation : "<<a->get_consomation()<<" L/km";
        std::cout<<"    Capacite reservoir : "<<a->get_capacite()<<" L"<<std::endl;
    }
}
