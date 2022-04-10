#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "Simulation.h"

class Interface
{
private:
    ///ATTRIBUTS

public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Interface();
    ~Interface();
    ///METHODES
    void affichage_interface(DifferentsAeroports aeroports,int type);
    void interface_simulation(AllAvions avions, DifferentsAeroports aeroports, Simulation simulation);
    void tracer_chemin(Voyageur& voyageur);
};

#endif // INTERFACE_H_INCLUDED
