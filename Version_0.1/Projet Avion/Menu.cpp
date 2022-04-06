#include "Menu.h"

Menu::Menu(){} //constructeur

Menu::~Menu(){} //destructeur

void Menu::affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports)
{
    int selec; //selection utilisateur
    do
    {
        std::cout<<"Bienvenue."<<std::endl;
        sleep(1);
        std::cout<<"    Pour afficher la liste des aeroports et des differents types d'avions avec leurs caracteristiques, tapez 1."<<std::endl<<"    Pour afficher le reseau d'aeroports, tapez 2."<<std::endl<<"    Pour calculer et afficher l'arbre des plus courts chemins (pour un type d'avion a partir d'un aeroport), tapez 3."<<std::endl<<"    Pour quitter, tapez 4."<<std::endl;
        std::cin>>selec;
        system("CLS");
    }while(selec != 1 && selec!=2 && selec != 3 && selec != 4);
    if(selec==1)
    {
        std::cout<<"Affichage aeroports et avions..."<<std::endl;
        Avions.affichage();
    }
    else if(selec==2)
    {
        std::cout<<"Affichage reseau..."<<std::endl;
        Aeroports.display();
    }
    else if(selec==3)
    {
        std::cout<<"Calcul et affichage..."<<std::endl;
        //lancement du sous-programme
    }
}
