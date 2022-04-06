#include "Menu.h"

Menu::Menu(){} //constructeur

Menu::~Menu(){} //destructeur

void Menu::affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports)
{
    int selec; //selection utilisateur
    int selec2;
    do
    {
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
            Aeroports.display();
            Avions.affichage();
            do
            {
                std::cout<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==2)
        {
            std::cout<<"Affichage reseau..."<<std::endl;
            do
            {
                std::cout<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==3)
        {
            std::cout<<"Calcul et affichage..."<<std::endl;
            ///CHOIX AEROPORT ET AVION
            std::string aero_dep;
            int type_dep;
            bool saisie=true; //si la saisie est correct, true, sinon false
            do
            {
                std::cout << "Veuillez saisir l'aeroport de depart : ";
                std::cin>>aero_dep;
                std::cout<<"Veuillez saisir le type d'avion : ";
                std::cin>>type_dep;
                if((aero_dep!="Paris" && aero_dep!="NewYork" && aero_dep!="Haiti" && aero_dep!="LaPaz" && aero_dep!="CapeTown" && aero_dep!="Bangkok" && aero_dep!="Perth") || (type_dep!=1 && type_dep!=3))
                {
                    saisie=false;
                    std::cout<<"Saisie incorrecte, veuillez réessayer."<<std::endl;
                }
                else
                {
                    saisie=true;
                }
            }while(!saisie);
            //lancement du sous-programme
            do
            {
                std::cout<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        system("CLS");
    }while(selec2!=1);
}
