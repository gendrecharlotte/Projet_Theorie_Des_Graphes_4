#include "Menu.h"

using namespace std;

int main()
{
    Menu m;
    Interface I;
    AllAvions Avions("DonneesAvions.txt");
    DifferentsAeroports Aeroports{"Aeroports.txt"};
    m.affichage_menu(Avions, Aeroports,I);
    return 0;
}
