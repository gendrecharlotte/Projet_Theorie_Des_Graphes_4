#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "AllAeroports.h"

class Simulation
{
private:

public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Simulation();
    ~Simulation();
    ///METHODES
    void initialisation(DifferentsAeroports aeroports, AllAvions allavions);
};

#endif // SIMULATION_H_INCLUDED
