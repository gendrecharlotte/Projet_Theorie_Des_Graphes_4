#include "Avion.h"

///CONSTRUCTEURS/DESTRUCTEURS
Avion::Avion(){}
Avion::Avion(int vitesse,int matricule,int type, int consomation, int capacite,int tmp_sol,int tmp_acces,int tmp_atterir,BITMAP *img,Coordonnees coo, bool da,std::stack<InfosAeroport*> trajet):m_matricule(matricule),m_type(type),m_consomation(consomation),m_capacite(capacite),m_tmp_sol(tmp_sol),m_tmp_acces(tmp_acces),m_tmp_atterir(tmp_atterir),m_img(img),m_coo(coo),m_da(da),m_trajet(trajet){}
Avion::~Avion(){}
///GETTERS/SETTERS
int Avion::get_vitesse()const{return m_vitesse;};
int Avion::get_matricule()const{return m_matricule;}
int Avion::get_type()const{return m_type;}
int Avion::get_consomation()const{return m_consomation;}
int Avion::get_capacite()const{return m_capacite;}
int Avion::get_tmp_sol()const{return m_tmp_sol;}
int Avion::get_tmp_acces()const{return m_tmp_acces;}
int Avion::get_tmp_atterir()const{return m_tmp_atterir;}
BITMAP* Avion::get_img()const{return m_img;}
Coordonnees Avion::get_coo()const{return m_coo;}
bool Avion::get_da()const{return m_da;}
std::stack<InfosAeroport*> Avion::get_trajet()const{return m_trajet;}
void Avion::set_vitesse(int val){m_vitesse=val;};
void Avion::set_matricule(int val){m_matricule=val;}
void Avion::set_type(int val){m_type=val;}
void Avion::set_consomation(int val){m_consomation=val;}
void Avion::set_capacite(int val){m_capacite=val;}
void Avion::set_tmp_sol(int val){m_tmp_sol=val;}
void Avion::set_tmp_acces(int val){m_tmp_acces=val;}
void Avion::set_tmp_atterir(int val){m_tmp_atterir=val;}
void Avion::set_img(BITMAP *val){m_img=val;}
void Avion::set_coo(Coordonnees val){m_coo=val;}
void Avion::set_da(bool val){m_da=val;}
void Avion::set_trajet(std::stack<InfosAeroport*> val){m_trajet=val;}

//création d'une fonction qui va calculer la consomation d'un avion en km
int Avion::cl_consomation(int distance_parcourut)
{
    //on commence par calculer la quantité que perd l'avion au décolage
    int cons=m_capacite;
    int cons_deco;
    int cons_atter;
    int cons_vol;
    //std::cout<<std::endl<<cons;
    cons_deco= ((cons*10)/100);
    //std::cout<<std::endl<<cons_deco;
    //ensuite on calcul la consomation à l'attérissage
    cons_atter=((cons*6)/100);
    //std::cout<<std::endl<<cons_atter;
    //on calcul ensuite la consomation en vol
    cons_vol= (m_consomation*(distance_parcourut));
    //std::cout<<std::endl<<cons_vol;
    //std::cout<<std::endl<<distance_parcourut;
    cons=cons-(cons_deco+cons_atter+cons_vol);

    return cons;
}