#include <iostream>
#include <unistd.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "AllVoyageurs.h"
#include <windows.h>

class Menu
{
private:

public:
    Menu();
    ~Menu();
    void affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports,Interface I, AllVoyageurs Voyageurs);
};

#endif // MENU_H_INCLUDED
