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
    int matricule,type,consomation,capacite,vitesse; //temps pour création d'un nouvel avion
    BITMAP *img;
    Coordonnees coo(0,0);
    std::stack<InfosAeroport*> trajet;
    for(int i=0;i<nb_avions;i++)
    {
        ifs>>matricule>>type>>consomation>>capacite>>vitesse; //lecture données avion
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture avion"); //exception
        m_liste_avions.push_back(new Avion(matricule,type,consomation,capacite,0,0,0,0,vitesse,img,coo,false,trajet)); //création+ajout au vecteur
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

/*//Retirer un avion du vecteur avions
void AllAvions::remove_avion(Avion* avion)
{
    int compteur, valeur_compteur;
    std::vector<Avion*> vect=get_liste_avions();
    for(auto a:vect)
    {
        if(a->get_matricule()==avion->get_matricule())
        {
            valeur_compteur=compteur;
        }
        else
            compteur++;
    }

    m_liste_avions.erase(m_liste_avions.begin()+valeur_compteur);
}*/
