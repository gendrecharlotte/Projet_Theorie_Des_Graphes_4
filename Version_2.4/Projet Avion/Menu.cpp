#include "Menu.h"

Menu::Menu(){} //constructeur

Menu::~Menu(){} //destructeur

void Menu::affichage_menu(AllAvions Avions,DifferentsAeroports Aeroports,Interface I, AllVoyageurs Voyageurs)
{
    int selec=0; //selection utilisateur
    int selec2;
    //Voyageur* voya;
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
            std::cout<<"Calcul et affichage du PCC"<<std::endl;
            ///CHOIX AEROPORT ET AVION

            Aeroports.Calcul_PCC(Aeroports, Avions);
            do
            {
                std::cout<<std::endl<<"Pour revenir au menu, tapez 0." <<std::endl<<"Pour quitter, tapez 1."<<std::endl;
                std::cin>>selec2;
            }while(selec2!=0 && selec2!=1);
        }
        else if(selec==4)
        {
            std::cout<<"Creation de vol"<<std::endl;
            sleep(1);

            Simulation simulation;
            //PLACEMENTS DES AEROPORTS ET AVIONS
            simulation.initialisation(Aeroports,Avions);////////////////////////////////////////////////////Simulation
            Voyageur voya=Voyageurs.CreerVoyageurs(Aeroports, Avions, I);

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

            //On récupère le vol qui nous interesse
            Voyageur* voyage=Voyageurs.RechercheVoyageur(Voyageurs);

            int choix=1;
            do
            {
                std::cout<<std::endl<<"Pour un apercu des trajets pendant la simulation, tapez 1."<<std::endl<<"Sinon, tapez 0."<<std::endl;
                std::cin>>choix;
            }while(choix!=0 && choix!=1);

            //simulation
            I.test(Avions, Aeroports, simulation, voyage, choix);

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
