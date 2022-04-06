#include "Menu.h"

using namespace std;

int main()
{
    Menu m;
    AllAvions Avions("DonneesAvions.txt");
    DifferentsAeroports Aeroports{"Aeroports.txt"};
    m.affichage_menu(Avions, Aeroports);
    return 0;
}
