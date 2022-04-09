#ifndef PERTURBATIONS_H_INCLUDED
#define PERTURBATIONS_H_INCLUDED

#include "AllAvions.h"
#include "Coordonnees.h"

class Perturbation
{
private:

public:
    ///CONSTRUCTEURS/DESTRUCTEURS
    Perturbation();
    ~Perturbation();
    ///METHODES
    void init(AllAvions allavions, Coordonnees coord1, Coordonnees coord2);
};

#endif // PERTURBATIONS_H_INCLUDED
