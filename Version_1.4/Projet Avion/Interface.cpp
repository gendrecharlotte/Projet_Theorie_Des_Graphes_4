#include "Interface.h"

//                                 #include <stdio.h>
//                                 #include <stdlib.h>
#define WIDTH 1556
#define HEIGHT 815

///CONSTRUCTEURS/DESTRUCTEURS
Interface::Interface(){}
Interface::~Interface(){}
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
    //int green = makecol(0,0,255);
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
            allegro_exit(); exit(EXIT_FAILURE);
        }
        ///ERREUR OUVERTURE IMAGE
        if (!image)
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit(); exit(EXIT_FAILURE);
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
        //line(page,716, int y1, int y2, int color);
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
        ///ERREUR OUVERTURE IMAGE
        if (!image || !a->get_img())
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit(); exit(EXIT_FAILURE);
        }
    }
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
            allegro_exit(); exit(EXIT_FAILURE);
        }
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,grille,0,0);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        if((mouse_x>=710 && mouse_x<=722) && (mouse_y>=198 && mouse_y<=210))
        {
            /*Coordonnees c;
            c.set_x(716);
            c.set_y(204);
            InfosAeroport v=findAeroport2(c,aeroports)
            textprintf_ex(page, cn,716, 204,red,white, "%s",v->get_Nom()+"(716,204)");*/
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
        //line(page,716, int y1, int y2, int color);
        ///AVIONS
        for(auto a:avions.get_liste_avions())
        {
            draw_sprite(page,a->get_img(),a->get_coo().get_x(),a->get_coo().get_y());
            if((mouse_x>=a->get_coo().get_x() && mouse_x<=a->get_coo().get_x()+25) && (mouse_y>=a->get_coo().get_y() && mouse_y<=a->get_coo().get_y()+25))
            {
                //std::cout<<a->get_matricule()<<std::endl;
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+25,red,white,"%d",a->get_matricule());
                textprintf_ex(page, cn,a->get_coo().get_x()+25, a->get_coo().get_y()+25,red,white,"%d",a->get_matricule());
            }
        }
        ///AFFICHAGE BUFFER
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    allegro_exit(); // pr terminer le programme
}
