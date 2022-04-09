#include "Avion.h"

///CONSTRUCTEURS/DESTRUCTEURS
Avion::Avion(){}
Avion::Avion(int vitesse,int matricule,int type, int consomation, int capacite,BITMAP *img,Coordonnees coo, bool da/*,std::stack<Aeroport*> trajet*/):m_vitesse(vitesse), m_matricule(matricule),m_type(type),m_consomation(consomation),m_capacite(capacite),m_img(img),m_coo(coo),m_da(da)/*,m_trajet(trajet)*/{}
Avion::~Avion(){}
///GETTERS/SETTERS
int Avion::get_vitesse()const{return m_vitesse;};
int Avion::get_matricule()const{return m_matricule;}
int Avion::get_type()const{return m_type;}
int Avion::get_consomation()const{return m_consomation;}
int Avion::get_capacite()const{return m_capacite;}
BITMAP* Avion::get_img()const{return m_img;}
Coordonnees Avion::get_coo()const{return m_coo;}
bool Avion::get_da()const{return m_da;}
//std::stack<Aeroport*> Avion::get_trajet()const{return m_trajet;}
void Avion::set_vitesse(int val){m_vitesse=val;};
void Avion::set_matricule(int val){m_matricule=val;}
void Avion::set_type(int val){m_type=val;}
void Avion::set_consomation(int val){m_consomation=val;}
void Avion::set_capacite(int val){m_capacite=val;}
void Avion::set_img(BITMAP *val){m_img=val;}
void Avion::set_coo(Coordonnees val){m_coo=val;}
void Avion::set_da(bool val){m_da=val;}
//void Avion::set_trajet(std::stack<Aeroport*> val){m_trajet=val;}
