#include "Avion.h"

///CONSTRUCTEURS/DESTRUCTEURS
Avion::Avion(){}
Avion::Avion(int matricule,int type, int consomation, int capacite,int tmp_sol,int tmp_acces,int tmp_atterir,int etat,BITMAP *img,Coordonnees coo, bool da,std::stack<InfosAeroport*> trajet):m_matricule(matricule),m_type(type),m_consomation(consomation),m_capacite(capacite),m_tmp_sol(tmp_sol),m_tmp_acces(tmp_acces),m_tmp_atterir(tmp_atterir),m_etat(etat),m_img(img),m_coo(coo),m_da(da),m_trajet(trajet){}
Avion::~Avion(){}
///GETTERS/SETTERS
int Avion::get_matricule()const{return m_matricule;}
int Avion::get_type()const{return m_type;}
int Avion::get_consomation()const{return m_consomation;}
int Avion::get_capacite()const{return m_capacite;}
int Avion::get_tmp_sol()const{return m_tmp_sol;}
int Avion::get_tmp_acces()const{return m_tmp_acces;}
int Avion::get_tmp_atterir()const{return m_tmp_atterir;}
int Avion::get_etat()const{return m_etat;}
BITMAP* Avion::get_img()const{return m_img;}
Coordonnees Avion::get_coo()const{return m_coo;}
bool Avion::get_da()const{return m_da;}
std::stack<InfosAeroport*> Avion::get_trajet()const{return m_trajet;}
void Avion::set_matricule(int val){m_matricule=val;}
void Avion::set_type(int val){m_type=val;}
void Avion::set_consomation(int val){m_consomation=val;}
void Avion::set_capacite(int val){m_capacite=val;}
void Avion::set_tmp_sol(int val){m_tmp_sol=val;}
void Avion::set_tmp_acces(int val){m_tmp_acces=val;}
void Avion::set_tmp_atterir(int val){m_tmp_atterir=val;}
void Avion::set_etat(int val){m_etat=val;}
void Avion::set_img(BITMAP *val){m_img=val;}
void Avion::set_coo(Coordonnees val){m_coo=val;}
void Avion::set_da(bool val){m_da=val;}
void Avion::set_trajet(std::stack<InfosAeroport*> val){m_trajet=val;}
