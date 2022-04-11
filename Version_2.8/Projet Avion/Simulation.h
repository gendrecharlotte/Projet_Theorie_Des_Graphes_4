#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include "Voyageur.h"

class Simulation
{
private:
    std::vector<Avion*> m_avions_en_vol;
public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Simulation();
    Simulation(std::vector<Avion*> avions_en_vol);
    ~Simulation();
    ///METHODES
    std::vector<Avion*> get_avions_en_vol()const;
    void set_avions_en_vol(std::vector<Avion*> val);
    void initialisation(DifferentsAeroports aeroports, AllAvions allavions);
    void maj(DifferentsAeroports aeroports, AllAvions allavions);
};

#endif // SIMULATION_H_INCLUDED
