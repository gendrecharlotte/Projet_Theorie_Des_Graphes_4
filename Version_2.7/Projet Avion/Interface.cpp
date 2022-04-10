#include "Interface.h"

//                                 #include <stdio.h>
//                                 #include <stdlib.h>
#define WIDTH 1556
#define HEIGHT 815

///CONSTRUCTEURS/DESTRUCTEURS
Interface::Interface() {}
Interface::~Interface() {}
///METHODES
void Interface::affichage_interface(DifferentsAeroports aeroports,int type)
{
    ///CREATION VARIABLES BUFFER+IMAGES+POLICES
    BITMAP *page;
    BITMAP *image;
    BITMAP *grille;
    FONT *cn;
    ///INITIALISATION ALLEGRO
    allegro_init();
    install_keyboard();
    install_mouse();
    /// OUVERTURE MODE GRAPHIQUE
    set_color_depth(desktop_color_depth());
    ///ERREUR OUVERTURE MODE GRAPHIQUE
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WIDTH,HEIGHT,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///DEFINITIONS COULEURS
    int red = makecol(255,0,0);
    int white = makecol(255,255,255);
    //int blue = makecol(0,255,0);
    int green = makecol(110,230,28);
    int yellow = makecol(255,201,14);
    ///CREATION BUFFER
    page=create_bitmap(SCREEN_W,SCREEN_H);
    ///CHARGEMENT CARTE
    image=load_bitmap("images/carte.bmp",NULL);
    ///CHARGEMENT AVION
    ///DEFINITION POILICE
    cn=load_font("fonts/couriernew.pcx",NULL,NULL);
    grille=load_bitmap("images/grille.bmp",NULL);
    show_mouse(screen);
    while(!key[KEY_ESC])
    {
        ///NETTOYAGE BUFFER
        clear_bitmap(page);
        ///ERREUR POLICE
        if (!cn)
        {
            allegro_message("pas pu trouver/charger couriernew.pcx");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
        ///ERREUR OUVERTURE IMAGE
        if (!image)
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,grille,0,0);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        if((mouse_x>=710 && mouse_x<=722) && (mouse_y>=198 && mouse_y<=210))
        {
            textprintf_ex(page, cn,716, 204,red,white, "PARIS(716,204)"); ///////////////////////////////////////////utiliser findaeroport2 pour automatisation
            textprintf_ex(page, cn,716, 220,red,white, "PISTES:3");
            textprintf_ex(page, cn,716, 236,red,white, "PLACES_SOL:10");
        }
        circlefill(page, 391, 220, 6, red); //newyork
        if((mouse_x>=385 && mouse_x<=397) && (mouse_y>=214 && mouse_y<=226))
        {
            textprintf_ex(page, cn,391, 220,red,white, "NEWYORK(391,220)");
            textprintf_ex(page, cn,391, 236,red,white, "PISTES:5");
            textprintf_ex(page, cn,391, 252,red,white, "PLACES_SOL:12");
        }
        circlefill(page, 347, 367, 6, red); //haiti
        if((mouse_x>=341 && mouse_x<=353) && (mouse_y>=361 && mouse_y<=373))
        {
            textprintf_ex(page, cn,347, 367,red,white, "HAITI(347,367)");
            textprintf_ex(page, cn,347, 383,red,white, "PISTES:1");
            textprintf_ex(page, cn,347, 399,red,white, "PLACES_SOL:4");
        }
        circlefill(page, 371, 565, 6, red); //lapaz
        if((mouse_x>=365 && mouse_x<=377) && (mouse_y>=559 && mouse_y<=571))
        {
            textprintf_ex(page, cn,371, 565,red,white, "LAPAZ(371,565)");
            textprintf_ex(page, cn,371, 581,red,white, "PISTES:1");
            textprintf_ex(page, cn,371, 597,red,white, "PLACES_SOL:6");
        }
        circlefill(page, 800, 657, 6, red); //capetown
        if((mouse_x>=794 && mouse_x<=806) && (mouse_y>=651 && mouse_y<=663))
        {
            textprintf_ex(page, cn,800, 657,red,white, "CAPETOWN(800,657)");
            textprintf_ex(page, cn,800, 673,red,white, "PISTES:2");
            textprintf_ex(page, cn,800, 689,red,white, "PLACES_SOL:6");
        }
        circlefill(page, 1218, 402, 6, red); //bangkok
        if((mouse_x>=1212 && mouse_x<=1224) && (mouse_y>=396 && mouse_y<=408))
        {
            textprintf_ex(page, cn,1218, 402,red,white, "BANGKOK(1218,402)");
            textprintf_ex(page, cn,1218, 418,red,white, "PISTES:2");
            textprintf_ex(page, cn,1218, 434,red,white, "PLACES_SOL:5");
        }
        circlefill(page, 1264, 653, 6, red); //perth
        if((mouse_x>=1258 && mouse_x<=1270) && (mouse_y>=647 && mouse_y<=659))
        {
            textprintf_ex(page, cn,1264, 653,red,white, "PERTH(1264,653)");
            textprintf_ex(page, cn,1264, 669,red,white, "PISTES:5");
            textprintf_ex(page, cn,1264, 685,red,white, "PLACES_SOL:12");
            textprintf_ex(page, cn,1264, 701,red,white, "DELAI_SOL:6UT");
            textprintf_ex(page, cn,1264, 717,red,white, "ACCES_PISTES:2UT");
        }
        ///ARCS
        if(type==1)
        {
            line(page, 716, 205, 391, 220, green);
            line(page, 347, 367, 391, 220, green);
            line(page, 347, 367, 371, 565, green);
            line(page, 1218, 402, 1264, 653, green);
        }
        else if(type==2)
        {
            line(page, 716, 205, 391, 220, yellow);
            line(page, 347, 367, 391, 220, yellow);
            line(page, 347, 367, 371, 565, yellow);
            line(page, 1218, 402, 1264, 653, yellow);
            line(page, 800, 657, 716, 205, yellow);
            line(page, 716, 205, 347, 367, yellow);
        }
        else
        {
            line(page, 716, 205, 391, 220, red);
            line(page, 347, 367, 391, 220, red);
            line(page, 347, 367, 371, 565, red);
            line(page, 1218, 402, 1264, 653, red);
            line(page, 800, 657, 716, 205, red);
            line(page, 716, 205, 347, 367, red);
            line(page, 1218, 402, 371, 565, red);
            line(page, 800, 657, 391, 220, red);
            line(page, 716, 205, 1264, 653, red);
        }
        ///AFFICHAGE BUFFER
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        //std::cout<<mouse_x<<","<<mouse_y<<std::endl;
    }
    allegro_exit(); // pr terminer le programme
}

void Interface::interface_simulation(AllAvions avions,DifferentsAeroports aeroports,Simulation simulation)
{
    ///CREATION VARIABLES BUFFER+IMAGES+POLICES
    BITMAP *page;
    BITMAP *image;
    BITMAP *grille;
    FONT *cn;
    int total_UT=0;
    ///INITIALISATION ALLEGRO
    allegro_init();
    install_keyboard();
    install_mouse();
    /// OUVERTURE MODE GRAPHIQUE
    set_color_depth(desktop_color_depth());
    ///ERREUR OUVERTURE MODE GRAPHIQUE
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WIDTH,HEIGHT,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///DEFINITIONS COULEURS
    int red = makecol(255,0,0);
    int white = makecol(255,255,255);
    //int blue = makecol(0,255,0);
    //int green = makecol(0,0,255);
    ///CREATION BUFFER
    page=create_bitmap(SCREEN_W,SCREEN_H);
    ///CHARGEMENT CARTE
    image=load_bitmap("images/carte.bmp",NULL);
    ///CHARGEMENT GRILLE
    grille=load_bitmap("images/grille.bmp",NULL);
    ///CHARGEMENT AVIONS IMAGES
    for(auto a:avions.get_liste_avions())
    {
        if(a->get_type()==1)
        {
            a->set_img(load_bitmap("images/avion_1.bmp",NULL));
        }
        else if(a->get_type()==2)
        {
            a->set_img(load_bitmap("images/avion_2.bmp",NULL));
        }
        else if(a->get_type()==3)
        {
            a->set_img(load_bitmap("images/avion_3.bmp",NULL));
        }
        ///ERREUR OUVERTURE IMAGES
        if (!image || !a->get_img() || !grille)
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    ///DEFINITION POLICE
    cn=load_font("fonts/couriernew.pcx",NULL,NULL);
    ///ERREUR POLICE
    if (!cn)
    {
        allegro_message("pas pu trouver/charger couriernew.pcx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
    while(!key[KEY_ESC])
    {
        ///NETTOYAGE BUFFER
        clear_bitmap(page);
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,grille,0,0);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        circlefill(page, 391, 220, 6, red); //newyork
        circlefill(page, 347, 367, 6, red); //haiti
        circlefill(page, 371, 565, 6, red); //lapaz
        circlefill(page, 800, 657, 6, red); //capetown
        circlefill(page, 1218, 402, 6, red); //bangkok
        circlefill(page, 1264, 653, 6, red); //perth
        ///AVIONS
        for(auto a:avions.get_liste_avions())
        {
            draw_sprite(page,a->get_img(),a->get_coo().get_x(),a->get_coo().get_y());
            if((mouse_x>=a->get_coo().get_x() && mouse_x<=a->get_coo().get_x()+25) && (mouse_y>=a->get_coo().get_y() && mouse_y<=a->get_coo().get_y()+25))
            {
                //std::cout<<a->get_matricule()<<std::endl;
                std::string s="(";
                s+=std::to_string(a->get_coo().get_x());
                s+=",";
                s+=std::to_string(a->get_coo().get_y());
                s+=")";
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+25,red,white,"%d",a->get_matricule());
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+41,red,white,s.c_str());
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+57,red,white,a->get_trajet().top()->get_Nom().c_str());
            }
        }
        if((mouse_x>=710 && mouse_x<=722) && (mouse_y>=198 && mouse_y<=210))
        {
            textprintf_ex(page, cn,716, 204,red,white, "PARIS(716,204)"); ///////////////////////////////////////////utiliser findaeroport2 pour automatisation
            textprintf_ex(page, cn,716, 220,red,white, "PISTES:3");
            textprintf_ex(page, cn,716, 236,red,white, "PLACES_SOL:10");
        }
        if((mouse_x>=385 && mouse_x<=397) && (mouse_y>=214 && mouse_y<=226))
        {
            textprintf_ex(page, cn,391, 220,red,white, "NEWYORK(391,220)");
            textprintf_ex(page, cn,391, 236,red,white, "PISTES:5");
            textprintf_ex(page, cn,391, 252,red,white, "PLACES_SOL:12");
        }
        if((mouse_x>=341 && mouse_x<=353) && (mouse_y>=361 && mouse_y<=373))
        {
            textprintf_ex(page, cn,347, 367,red,white, "HAITI(347,367)");
            textprintf_ex(page, cn,347, 383,red,white, "PISTES:1");
            textprintf_ex(page, cn,347, 399,red,white, "PLACES_SOL:4");
        }
        if((mouse_x>=365 && mouse_x<=377) && (mouse_y>=559 && mouse_y<=571))
        {
            textprintf_ex(page, cn,371, 565,red,white, "LAPAZ(371,565)");
            textprintf_ex(page, cn,371, 581,red,white, "PISTES:1");
            textprintf_ex(page, cn,371, 597,red,white, "PLACES_SOL:6");
        }
        if((mouse_x>=794 && mouse_x<=806) && (mouse_y>=651 && mouse_y<=663))
        {
            textprintf_ex(page, cn,800, 657,red,white, "CAPETOWN(800,657)");
            textprintf_ex(page, cn,800, 673,red,white, "PISTES:2");
            textprintf_ex(page, cn,800, 689,red,white, "PLACES_SOL:6");
        }
        if((mouse_x>=1212 && mouse_x<=1224) && (mouse_y>=396 && mouse_y<=408))
        {
            textprintf_ex(page, cn,1218, 402,red,white, "BANGKOK(1218,402)");
            textprintf_ex(page, cn,1218, 418,red,white, "PISTES:2");
            textprintf_ex(page, cn,1218, 434,red,white, "PLACES_SOL:5");
        }
        if((mouse_x>=1258 && mouse_x<=1270) && (mouse_y>=647 && mouse_y<=659))
        {
            textprintf_ex(page, cn,1264, 653,red,white, "PERTH(1264,653)");
            textprintf_ex(page, cn,1264, 669,red,white, "PISTES:5");
            textprintf_ex(page, cn,1264, 685,red,white, "PLACES_SOL:12");
            textprintf_ex(page, cn,1264, 701,red,white, "DELAI_SOL:6UT");
            textprintf_ex(page, cn,1264, 717,red,white, "ACCES_PISTES:2UT");
        }
        ///ARCS
        //line(page,716, int y1, int y2, int color);
        ///AFFICHAGE BUFFER
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        ///MISE A JOUR COMPTEUR
        total_UT++;
        ///MISE A JOUR SIMULATION
        //appel fonction maj simulation.maj();
    }
    allegro_exit(); // pr terminer le programme
}

//=================================================================================================================================================

void Interface::test(AllAvions avions,DifferentsAeroports aeroports,Simulation simulation, Voyageur* voyageur, int choix)
{
    Coordonnees coo;
    std::stack<InfosAeroport*> traj;
    ///CREATION VARIABLES BUFFER+IMAGES+POLICES
    BITMAP *page;
    BITMAP *image;
    BITMAP *grille;
    //BITMAP *avion_spe;
    FONT *cn;
    int total_UT=0;
    ///INITIALISATION ALLEGRO
    allegro_init();
    install_keyboard();
    install_mouse();
    /// OUVERTURE MODE GRAPHIQUE
    set_color_depth(desktop_color_depth());
    ///ERREUR OUVERTURE MODE GRAPHIQUE
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WIDTH,HEIGHT,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///DEFINITIONS COULEURS
    int red = makecol(255,0,0);
    int white = makecol(255,255,255);
    //int blue = makecol(0,255,0);
    int green = makecol(110,230,28);
    int yellow = makecol(255,201,14);
    ///CREATION BUFFER
    page=create_bitmap(SCREEN_W,SCREEN_H);
    ///CHARGEMENT CARTE
    image=load_bitmap("images/carte.bmp",NULL);
    ///CHARGEMENT GRILLE
    grille=load_bitmap("images/grille.bmp",NULL);

    ///CHARGEMENT AVIONS IMAGES

    for(auto a: avions.get_liste_avions())
    {
        if((voyageur->get_avion()).get_matricule()==a->get_matricule())
        {
            //set le trajet de l'avion
            a->set_trajet((voyageur->get_avion()).get_trajet());
            //set les coordonnées de depart
            a->set_coo((voyageur->get_avion()).get_trajet().top()->get_Localisation());

            //definition de l'image en fonction du type d'avion
            if(a->get_type()==1)
            {
                a->set_img(load_bitmap("images/avion_1_selec.bmp",NULL));
            }
            else if(a->get_type()==2)
            {
                a->set_img(load_bitmap("images/avion_2_selec.bmp",NULL));
            }
            else if(a->get_type()==3)
            {
                a->set_img(load_bitmap("images/avion_3_selec.bmp",NULL));
            }
        }

        ///ERREUR OUVERTURE IMAGES
        if (!image || !a->get_img() || !grille)
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    ///DEFINITION POLICE
    cn=load_font("fonts/couriernew.pcx",NULL,NULL);
    ///ERREUR POLICE
    if (!cn)
    {
        allegro_message("pas pu trouver/charger couriernew.pcx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    show_mouse(screen);
    while(!key[KEY_ESC])
    {


        ///NETTOYAGE BUFFER
        clear_bitmap(page);
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,grille,0,0);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        circlefill(page, 391, 220, 6, red); //newyork
        circlefill(page, 347, 367, 6, red); //haiti
        circlefill(page, 371, 565, 6, red); //lapaz
        circlefill(page, 800, 657, 6, red); //capetown
        circlefill(page, 1218, 402, 6, red); //bangkok
        circlefill(page, 1264, 653, 6, red); //perth
        ///AVIONS
        for(auto a:avions.get_liste_avions())
        {
            coo=a->get_coo();
            traj=a->get_trajet();
            draw_sprite(page,a->get_img(),a->get_coo().get_x(),a->get_coo().get_y());
            //tant qu'il y a encore un trajet a realiser
            if(traj.size()!=0 && a->get_etat()>=2)
            {
                //mise a jour des coordonnées
                draw_sprite(page,a->get_img(),a->get_coo().get_x(),a->get_coo().get_y());

                if(choix==1)//si l'utilisateur veut un aperçu de certaines trajectoires
                {
                    if(a->get_type()==3 && a->get_matricule()%2==0) //%2 pour ne pas avoir trop de choses à afficher
                        line(page, a->get_coo().get_x()+12, a->get_coo().get_y()+12, traj.top()->get_Localisation().get_x(), traj.top()->get_Localisation().get_y(), red);
                    else if(a->get_type()==2 && a->get_matricule()%2==0)
                        line(page, a->get_coo().get_x()+12, a->get_coo().get_y()+12, traj.top()->get_Localisation().get_x(), traj.top()->get_Localisation().get_y(), yellow);
                    else if(a->get_type()==1 && a->get_matricule()%2==0)
                        line(page, a->get_coo().get_x()+12, a->get_coo().get_y()+12, traj.top()->get_Localisation().get_x(), traj.top()->get_Localisation().get_y(), green);
                }

                if(a->get_coo().get_y()<traj.top()->get_Localisation().get_y())
                {
                    coo.set_y(coo.get_y()+10);
                    a->set_coo(coo);
                }
                else if(a->get_coo().get_y()>traj.top()->get_Localisation().get_y())
                {
                    coo.set_y(coo.get_y()-10);
                    a->set_coo(coo);
                }
                if(a->get_coo().get_x()<traj.top()->get_Localisation().get_x())
                {
                    coo.set_x(coo.get_x()+10);
                    a->set_coo(coo);
                }
                else if(a->get_coo().get_x()>traj.top()->get_Localisation().get_x())
                {
                    coo.set_x(coo.get_x()-10);
                    a->set_coo(coo);
                }
                if(abs(a->get_coo().get_y()-traj.top()->get_Localisation().get_y())<=10&&abs(a->get_coo().get_x()-a->get_trajet().top()->get_Localisation().get_x())<=10)
                {
                    a->set_coo(traj.top()->get_Localisation()); //on le considère arrivé
                    //std::stack<InfosAeroport*> traj;
                    //traj=a->get_trajet();
                    if(a->get_tmp_atterir()>=2*traj.top()->get_Temps_Decollage_Atterissage())
                        traj.pop();
                    else
                        a->set_tmp_atterir(a->get_tmp_atterir()+1);
                    a->set_trajet(traj);
                }

                ///LISTE DE TRAJET NON VIDE/CARBURANT/AVION EN VOL===================================================================================================================================
                /*if(traj.size()!=0 && a->get_capacite()>0 && a->get_etat()==4)
                {
                //draw_sprite(page,a->get_img(),a->get_coo().get_x(),a->get_coo().get_y());
                if(a->get_coo().get_y()<traj.top()->get_Localisation().get_y())
                {
                    coo.set_y(coo.get_y()+10);
                    a->set_coo(coo);
                }
                else if(a->get_coo().get_y()>traj.top()->get_Localisation().get_y())
                {
                    coo.set_y(coo.get_y()-10);
                    a->set_coo(coo);
                }
                if(a->get_coo().get_x()<traj.top()->get_Localisation().get_x())
                {
                    coo.set_x(coo.get_x()+10);
                    a->set_coo(coo);
                }
                else if(a->get_coo().get_x()>traj.top()->get_Localisation().get_x())
                {
                    coo.set_x(coo.get_x()-10);
                    a->set_coo(coo);
                }
                ///ARRIVEE A PROXIMITE DU HAUT DE LA PILE DE TRAJET
                if(abs(a->get_coo().get_y()-traj.top()->get_Localisation().get_y())<=10&&abs(a->get_coo().get_x()-a->get_trajet().top()->get_Localisation().get_x())<=10)
                {
                    coo=traj.top()->get_Localisation();
                    a->set_coo(coo); //on le considère arrivé
                    ///SI PISTES DISPONIBLES
                    if(traj.top()->get_avions_sur_pistes().size()<(unsigned)traj.top()->get_Nombres_Pistes())
                    {
                        ///LANCEMENT PHASE ATTERISSAGE
                        a->set_etat(3);
                        a->set_tmp_atterir(0);
                        ///AJOUT AU VECTEUR DES PISTES PRISES
                        std::vector<Avion*> vect=traj.top()->get_avions_sur_pistes();
                        vect.push_back(a);
                        traj.top()->set_avions_sur_pistes(vect);
                    }
                }
                }
                ///AVION EN COURS D'ATTERISSAGE
                else if(a->get_etat()==3)
                {
                ///TEMPS D'ATTERRISSAGE ECOULÉ
                if(a->get_tmp_atterir()>=traj.top()->get_Temps_Decollage_Atterissage())
                {
                    ///SI DERNIERE DESTINATION ATTEINTE
                    if(traj.size()<=1)
                    {
                        ///PASSAGE SUR PLACES AU SOL
                        if(traj.top()->get_avions_au_sol().size()<(unsigned)traj.top()->get_Nombres_Places_Sol())
                        {
                            a->set_etat(1);
                            std::vector<Avion*> vect2=traj.top()->get_avions_au_sol();
                            vect2.push_back(a);
                            traj.top()->set_avions_au_sol(vect2);
                            std::vector<Avion*> vect=traj.top()->get_avions_sur_pistes();
                            //int ind=0;
                            for(unsigned int i=0;i<vect.size();i++)
                            {
                                if(vect[i]->get_matricule()==a->get_matricule())
                                    vect.erase(vect.begin()+i);
                            }
                            //vect.erase(vect.begin()+ind-1);
                            traj.top()->set_avions_sur_pistes(vect);
                            traj.pop();
                            a->set_trajet(traj);
                        }
                    }
                    else
                    {
                        a->set_tmp_atterir(0);
                        a->set_etat(2);
                    }
                }
                else
                {
                    a->set_tmp_atterir(a->get_tmp_atterir()+1);
                }
                }
                ///SI DECOLLAGE
                else if(a->get_etat()==2)
                {
                ///TEMPS ECOULE
                if(traj.size()!=0 && a->get_tmp_atterir()>=traj.top()->get_Temps_Decollage_Atterissage())
                {
                    ///MISE EN VOL
                    a->set_etat(4);
                    std::vector<Avion*> vect=traj.top()->get_avions_sur_pistes();
                    for(unsigned int i=0;i<vect.size();i++)
                    {
                        if(vect[i]->get_matricule()==a->get_matricule())
                        {
                            vect.erase(vect.begin()+i);
                        }
                    }
                    traj.top()->set_avions_sur_pistes(vect);
                    a->set_tmp_atterir(0);
                }
                ///SINON UPDATE COMPTEUR
                else
                {
                    a->set_tmp_atterir(a->get_tmp_atterir()+1);
                }
                }
                ///SI AVION AU SOL
                else
                {
                ///SI L'AVION DOIT ALLER VERS UNE AUTRE DESTINATION
                if(traj.size()!=0 && (traj.top()->get_Localisation().get_x()!=a->get_coo().get_x() && traj.top()->get_Localisation().get_y()!=a->get_coo().get_y()))
                {
                    if(traj.top()->get_avions_sur_pistes().size()<(unsigned)traj.top()->get_Nombres_Pistes())
                    {
                        a->set_etat(2);
                        a->set_tmp_atterir(0);
                    }
                }
                }*/
            }
            else if(a->get_etat()==1)
            {
                if(a->get_tmp_acces()>=traj.top()->get_Temps_Acces_Piste())
                    a->set_etat(4);
                else
                    a->set_tmp_acces(a->get_tmp_acces()+1);
            }
            coo.set_z(0);
            a->set_coo(coo);
            int test_x_min,test_x_max, test_y_min, test_y_max;
            for(auto k:avions.get_liste_avions())
            {

                test_x_max=(k->get_coo().get_x())+5;
                test_x_min=(k->get_coo().get_x())-5;
                test_y_min=(k->get_coo().get_y())-5;
                test_y_max=(k->get_coo().get_x())+5;
                if (a->get_coo().get_x()<test_x_max && a->get_coo().get_x()>test_x_min && a->get_coo().get_y()<test_y_max && a->get_coo().get_y()>test_y_min && a->get_coo().get_z()==k->get_coo().get_z())
                {
                    if(a!=k)
                    {

                        coo.set_z(coo.get_z()+10);
                        a->set_coo(coo);

                        if(a->get_coo().get_z()>=10 && a->get_coo().get_z()<20 && a->get_type()==1)
                        {
                            a->set_img(load_bitmap("images/avion_11.bmp",NULL));
                        }
                        else if(a->get_coo().get_z()>=10 && a->get_coo().get_z()<20 && a->get_type()==2)
                        {
                            a->set_img(load_bitmap("images/avion_22.bmp",NULL));
                        }
                        else if(a->get_coo().get_z()>=10 && a->get_coo().get_z()<20 && a->get_type()==3)
                        {
                            a->set_img(load_bitmap("images/avion_33.bmp",NULL));
                        }
                        else if(a->get_coo().get_z()>=20 && a->get_coo().get_z()<30 && a->get_type()==1)
                        {
                            a->set_img(load_bitmap("images/avion_111.bmp",NULL));
                        }
                        else if(a->get_coo().get_z()>=20 && a->get_coo().get_z()<30 && a->get_type()==2)
                        {
                            a->set_img(load_bitmap("images/avion_222.bmp",NULL));
                        }
                        else if(a->get_coo().get_z()>=20 && a->get_coo().get_z()<30 && a->get_type()==3)
                        {
                            a->set_img(load_bitmap("images/avion_333.bmp",NULL));
                        }
                        else if(a->get_coo().get_z()>=30 && a->get_type()==3)
                        {
                            a->set_img(load_bitmap("images/scratch.bmp",NULL));
                        }

                    }
                }
            }
            if(a->get_coo().get_z()==0 &&a->get_type()==1)
            {
                a->set_img(load_bitmap("images/avion_1.bmp",NULL));
            }
            else if(a->get_coo().get_z()==0 && a->get_type()==2)
            {
                a->set_img(load_bitmap("images/avion_2.bmp",NULL));
            }
            else if(a->get_coo().get_z()==0 && a->get_type()==3)
            {
                a->set_img(load_bitmap("images/avion_3.bmp",NULL));
            }
            if((mouse_x>=a->get_coo().get_x() && mouse_x<=a->get_coo().get_x()+25) && (mouse_y>=a->get_coo().get_y() && mouse_y<=a->get_coo().get_y()+25))
            {
                //std::cout<<a->get_matricule()<<std::endl;
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+25,red,white,"%d",a->get_matricule());
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+41,red,white,a->get_trajet().top()->get_Nom().c_str());
            }


            //affichage des informations avec la souris
            if((mouse_x>=a->get_coo().get_x() && mouse_x<=a->get_coo().get_x()+25) && (mouse_y>=a->get_coo().get_y() && mouse_y<=a->get_coo().get_y()+25))
            {
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+25,red,white,"%d",a->get_matricule());
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+41,red,white,a->get_trajet().top()->get_Nom().c_str());
            }
        }

        //affichage des infos des aeroports
        if((mouse_x>=710 && mouse_x<=722) && (mouse_y>=198 && mouse_y<=210))
        {
            textprintf_ex(page, cn,716, 204,red,white, "PARIS(716,204)");
            textprintf_ex(page, cn,716, 220,red,white, "PISTES:3");
            textprintf_ex(page, cn,716, 236,red,white, "PLACES_SOL:10");
        }
        if((mouse_x>=385 && mouse_x<=397) && (mouse_y>=214 && mouse_y<=226))
        {
            textprintf_ex(page, cn,391, 220,red,white, "NEWYORK(391,220)");
            textprintf_ex(page, cn,391, 236,red,white, "PISTES:5");
            textprintf_ex(page, cn,391, 252,red,white, "PLACES_SOL:12");
        }
        if((mouse_x>=341 && mouse_x<=353) && (mouse_y>=361 && mouse_y<=373))
        {
            textprintf_ex(page, cn,347, 367,red,white, "HAITI(347,367)");
            textprintf_ex(page, cn,347, 383,red,white, "PISTES:1");
            textprintf_ex(page, cn,347, 399,red,white, "PLACES_SOL:4");
        }
        if((mouse_x>=365 && mouse_x<=377) && (mouse_y>=559 && mouse_y<=571))
        {
            textprintf_ex(page, cn,371, 565,red,white, "LAPAZ(371,565)");
            textprintf_ex(page, cn,371, 581,red,white, "PISTES:1");
            textprintf_ex(page, cn,371, 597,red,white, "PLACES_SOL:6");
        }
        if((mouse_x>=794 && mouse_x<=806) && (mouse_y>=651 && mouse_y<=663))
        {
            textprintf_ex(page, cn,800, 657,red,white, "CAPETOWN(800,657)");
            textprintf_ex(page, cn,800, 673,red,white, "PISTES:2");
            textprintf_ex(page, cn,800, 689,red,white, "PLACES_SOL:6");
        }
        if((mouse_x>=1212 && mouse_x<=1224) && (mouse_y>=396 && mouse_y<=408))
        {
            textprintf_ex(page, cn,1218, 402,red,white, "BANGKOK(1218,402)");
            textprintf_ex(page, cn,1218, 418,red,white, "PISTES:2");
            textprintf_ex(page, cn,1218, 434,red,white, "PLACES_SOL:5");
        }
        if((mouse_x>=1258 && mouse_x<=1270) && (mouse_y>=647 && mouse_y<=659))
        {
            textprintf_ex(page, cn,1264, 653,red,white, "PERTH(1264,653)");
            textprintf_ex(page, cn,1264, 669,red,white, "PISTES:5");
            textprintf_ex(page, cn,1264, 685,red,white, "PLACES_SOL:12");
            textprintf_ex(page, cn,1264, 701,red,white, "DELAI_SOL:6UT");
            textprintf_ex(page, cn,1264, 717,red,white, "ACCES_PISTES:2UT");
        }

        ///AFFICHAGE UT
        textprintf_ex(page, cn,5, 779,red,white, "UT : ");
        textprintf_ex(page, cn,5, 795,red,white, "%d",total_UT);
        ///AFFICHAGE BUFFER
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        ///MISE A JOUR COMPTEUR
        total_UT++;
        Sleep(2000);
        ///MISE A JOUR SIMULATION
        //appel fonction maj simulation.maj();
    }
    allegro_exit(); // pr terminer le programme
}

//tracer un trajet en mode graphique
void Interface::tracer_chemin(Voyageur& voyageur)
{
    int x1=0;
    int y1=0;
    int x2=0;
    int y2=0;
    std::stack<InfosAeroport*> chemin_a_tracer=(voyageur.get_avion()).get_trajet();

    ///CREATION VARIABLES BUFFER+IMAGES+POLICES
    BITMAP *page;
    BITMAP *image;
    BITMAP *grille;
    FONT *cn;
    ///INITIALISATION ALLEGRO
    allegro_init();
    install_keyboard();
    install_mouse();
    /// OUVERTURE MODE GRAPHIQUE
    set_color_depth(desktop_color_depth());
    ///ERREUR OUVERTURE MODE GRAPHIQUE
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WIDTH,HEIGHT,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///DEFINITIONS COULEURS
    int red = makecol(255,0,0);
    //int blue = makecol(0,255,0);
    //int green = makecol(0,0,255);
    ///CREATION BUFFER
    page=create_bitmap(SCREEN_W,SCREEN_H);
    ///CHARGEMENT CARTE
    image=load_bitmap("images/carte.bmp",NULL);
    /*///CHARGEMENT AVIONS IMAGES
        if((voyageur.get_avion()).get_type()==1)
        {
            (voyageur.get_avion()).set_img(load_bitmap("images/avion_1.bmp",NULL));
        }
        else if((voyageur.get_avion()).get_type()==2)
        {
            (voyageur.get_avion()).set_img(load_bitmap("images/avion_2.bmp",NULL));
        }
        else if((voyageur.get_avion()).get_type()==3)
        {
            (voyageur.get_avion()).set_img(load_bitmap("images/avion_3.bmp",NULL));
        }
        ///ERREUR OUVERTURE IMAGE
        if (!image || !(voyageur.get_avion()).get_img())
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }*/

    ///DEFINITION POLICE
    cn=load_font("fonts/couriernew.pcx",NULL,NULL);
    grille=load_bitmap("images/grille.bmp",NULL);
    show_mouse(screen);

    while(!key[KEY_ESC])
    {
        ///NETTOYAGE BUFFER
        clear_bitmap(page);
        ///ERREUR POLICE
        if (!cn)
        {
            allegro_message("pas pu trouver/charger couriernew.pcx");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,grille,0,0);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        circlefill(page, 391, 220, 6, red); //newyork
        circlefill(page, 347, 367, 6, red); //haiti
        circlefill(page, 371, 565, 6, red); //lapaz
        circlefill(page, 800, 657, 6, red); //capetown
        circlefill(page, 1218, 402, 6, red); //bangkok
        circlefill(page, 1264, 653, 6, red); //perth

        if(chemin_a_tracer.size()!=0)
        {
            unsigned int taille=chemin_a_tracer.size();
            for(unsigned int i=0; i<taille; i++)
            {
                //Enregistrer les prochains points
                x2=((chemin_a_tracer.top())->get_Localisation()).get_x();
                y2=((chemin_a_tracer.top())->get_Localisation()).get_y();

                //Si pas le premier aeroport
                if(x1!=0 && y1!=0)
                {
                    //tracer un trait de point1 à point2
                    line(page, x1,y1,x2,y2,red);
                }
                //On enregistre x1 et y1 pour le prochain aeroport
                x1=x2;
                y1=y2;
                //On retire l'aeroport actuel
                chemin_a_tracer.pop();
                ///AFFICHAGE BUFFER
                blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }
        //Tant que la pile n'est pas vide

        /*draw_sprite(page,(voyageur.get_avion()).get_img(),(voyageur.get_avion()).get_coo().get_x(),(voyageur.get_avion()).get_coo().get_y());
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);*/

    }
    allegro_exit(); // pr terminer le programme
}

