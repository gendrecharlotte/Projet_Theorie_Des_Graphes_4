#include "Menu.h"

Menu::Menu(){} //constructeur

Menu::~Menu(){} //destructeur

void Menu::affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports,Interface I)
{
    int selec=0; //selection utilisateur
    int selec2;
    do
    {
        do
        {
            std::cout<<"Bienvenue."<<std::endl;
            sleep(1);
            std::cout<<"    Pour afficher la liste des aeroports et des differents types d'avions avec leurs caracteristiques, tapez 1.";
            std::cout<<std::endl<<"    Pour afficher le reseau d'aeroports, tapez 2.";
            std::cout<<std::endl<<"    Pour calculer et afficher l'arbre des plus courts chemins (pour un type d'avion a partir d'un aeroport), tapez 3.";
            std::cout<<std::endl<<"    Pour choisir un vol, tapez 4.";
            std::cout<<std::endl<<"    Pour lancer une simulation, tapez 5.";
            std::cout<<std::endl<<"    Pour quitter, tapez 6."<<std::endl;
            std::cin>>selec;
            system("CLS");
        }while(selec != 1 && selec!=2 && selec != 3 && selec != 4 && selec!=5 && selec!=6);
        if(selec==1)
        {
            std::cout<<"Affichage aeroports et avions..."<<std::endl;
            sleep(1);
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
            int type;
            bool saisie=true; //si la saisie est correct, true, sinon false
            do
            {
                std::cout<<"Choisissez un type d'avion pour l'affichage du reseau : ";
                std::cin>>type;
                if(type!=1 && type!=2 && type!=3)
                {
                    saisie=false;
                    std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
                }
                else
                {
                    saisie=true;
                }
            }while(!saisie);
            std::cout<<"Affichage reseau..."<<std::endl;
            sleep(1);
            I.affichage_interface(Aeroports,type);
            do
            {
                std::cout<<std::endl<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==3)
        {
            std::cout<<"Calcul et affichage..."<<std::endl;
            ///CHOIX AEROPORT ET AVION
            DifferentsAeroports diff;
            std::string aero_dep;
            std::string aero_arr;
            int depart, arrivee;
            int type_dep;
            bool saisie1=true; //si la saisie est correct, true, sinon false
            bool saisie2=true;

            //choix type d'avion
            do
            {
                system("CLS");
                std::cout<<"Veuillez saisir le type d'avion : ";
                std::cin>>type_dep;

                if((type_dep!=1)&&(type_dep!=2)&&(type_dep!=3))
                {
                    std::cout<<"Saisie incorrecte, veuillez choisir entre 1 (court), 2 (moyen) ou 3 (long).";
                    Sleep(3000);
                }

            }while((type_dep!=1)&&(type_dep!=2)&&(type_dep!=3));


            //choix aeroport de depart
            do
            {
                std::cout << "Veuillez saisir l'aeroport de depart : ";
                std::cin>>aero_dep;

                if(aero_dep!="Paris" && aero_dep!="NewYork" && aero_dep!="Haiti" && aero_dep!="LaPaz" && aero_dep!="CapeTown" && aero_dep!="Bangkok" && aero_dep!="Perth")
                {
                    saisie1=false;
                    std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
                }
                else
                {
                    saisie1=true;
                }

            }while(!saisie1);

            //choixi aeroport d'arrive
            do
            {
                std::cout << "Veuillez saisir l'aeroport d'arrive : ";
                std::cin>>aero_arr;
                if((aero_arr!="Paris" && aero_arr!="NewYork" && aero_arr!="Haiti" && aero_arr!="LaPaz" && aero_arr!="CapeTown" && aero_arr!="Bangkok" && aero_arr!="Perth"))
                {
                    saisie2=false;
                    std::cout<<"Saisie incorrecte, veuillez reessayer."<<std::endl;
                }
                else
                {
                    saisie2=true;
                }

            }while(!saisie2);

            //Recuperer indice aeroports
            depart=diff.findAeroport(aero_dep, Aeroports);
            arrivee=diff.findAeroport(aero_arr, Aeroports);

            //Calcul chemin le plus court
            diff.Dijkstra(depart,arrivee,Aeroports);

            do
            {
                std::cout<<std::endl<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==4)
        {
            AllVoyageurs voyageurs;
            std::cout<<"Affichage vol choisi..."<<std::endl;
            sleep(1);
            voyageurs.affichage();
            do
            {
                std::cout<<std::endl<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==5)
        {
            Simulation simulation;
            //PLACEMENTS DES AEROPORTS ET AVIONS
            simulation.initialisation(Aeroports,Avions);////////////////////////////////////////////////////Simulation
            I.interface_simulation(Avions,Aeroports,simulation);
            do
            {
                std::cout<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==6)
        {
            selec2=1;
        }
        system("CLS");
    }while(selec2!=1);
}
