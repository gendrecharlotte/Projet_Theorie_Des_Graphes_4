#include "Menu.h"

using namespace std;

int main()
{
    Menu m;
    Interface I;
    AllAvions Avions("DonneesAvions.txt");
    DifferentsAeroports Aeroports{"Aeroports.txt"};
    AllVoyageurs Voyageurs("liste_voyageurs.txt",Avions, Aeroports);
    m.affichage_menu(Avions, Aeroports,I, Voyageurs);
    return 0;
}
END_OF_MAIN()
