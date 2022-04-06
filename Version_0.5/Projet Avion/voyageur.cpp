#include "voyageur.h"

//constructeur/destructeur
Voyageur::Voyageur(){}
Voyageur::Voyageur(std::string nom,std::string depart,std::string arrivee, int horaire):m_nom(nom),m_depart(depart), m_arrivee(arrivee),m_horaire(horaire){}
Voyageur::~Voyageur(){}
//getters/setters
std::string Voyageur::get_nom()const{return m_nom;}
std::string Voyageur::get_depart()const{return m_depart;}
std::string Voyageur::get_arrivee()const{return m_arrivee;}
int Voyageur::get_horaire()const{return m_horaire;}
void Voyageur::set_nom(std::string val){m_nom=val;}
void Voyageur::set_depart(std::string val){m_depart=val;}
void Voyageur::set_arrivee(std::string val){m_arrivee=val;}
void Voyageur::set_horaire(int val){m_horaire=val;}
