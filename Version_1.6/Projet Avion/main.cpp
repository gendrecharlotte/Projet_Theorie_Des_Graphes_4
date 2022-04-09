#include "Menu.h"
#include"algoAstar.h"//header de algo star

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
END_OF_MAIN();
