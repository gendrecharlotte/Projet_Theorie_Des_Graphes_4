#include "Avion.h"

///CONSTRUCTEURS/DESTRUCTEURS
Avion::Avion(){}
Avion::Avion(int type, int consomation, int capacite):m_type(type),m_consomation(consomation),m_capacite(capacite){}
Avion::~Avion(){}
///GETTERS/SETTERS
int Avion::get_type()const{return m_type;}
int Avion::get_consomation()const{return m_consomation;}
int Avion::get_capacite()const{return m_capacite;}
void Avion::set_type(int val){m_type=val;}
void Avion::set_consomation(int val){m_consomation=val;}
void Avion::set_capacite(int val){m_capacite=val;}
