#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Interface.h"

#include <iostream>
#include <unistd.h>

class Menu
{
private:

public:
    Menu();
    ~Menu();
    void affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports,Interface I);
};

#endif // MENU_H_INCLUDED
