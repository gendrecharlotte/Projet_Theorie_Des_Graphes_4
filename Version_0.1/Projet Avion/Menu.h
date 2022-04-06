#include <iostream>
#include <unistd.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "AllAeroports.h"

class Menu
{
private:

public:
    Menu();
    ~Menu();
    void affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports);
};

#endif // MENU_H_INCLUDED
