#include "Menu.h"

using namespace std;

int main()
{
    Menu m;
    Interface I;
    AllAvions Avions("DonneesAvions.txt");
    AllVoyageurs Voyageurs("liste_voyageurs.txt",&Avions);
    DifferentsAeroports Aeroports{"Aeroports.txt"};
    m.affichage_menu(Avions, Aeroports,I, Voyageurs);
    return 0;
}
END_OF_MAIN()
