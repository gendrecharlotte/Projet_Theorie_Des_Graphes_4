#include "Interface.h"
#include <allegro.h>
//                                 #include <stdio.h>
//                                 #include <stdlib.h>
#define WIDTH 1556
#define HEIGHT 815

///CONSTRUCTEURS/DESTRUCTEURS
Interface::Interface(){}
Interface::~Interface(){}
///METHODES
void Interface::affichage_interface()
{
    ///CREATION VARIABLES BUFFER+IMAGE
    BITMAP *page;
    BITMAP *image;
    ///INITIALISATION ALLEGRO
    allegro_init();
    install_keyboard();
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
    while(!key[KEY_ESC])
    {
        ///NETTOYAGE BUFFER
        clear_bitmap(page);
        ///ERREUR OUVERTURE IMAGE
        if (!image)
        {
            allegro_message("pas pu trouver/charger carte.bmp");
            allegro_exit(); exit(EXIT_FAILURE);
        }
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        circlefill(page, 391, 220, 6, red); //newyork
        circlefill(page, 347, 367, 6, red); //haiti
        circlefill(page, 371, 565, 6, red); //lapaz
        circlefill(page, 800, 657, 6, red); //capetown
        circlefill(page, 1218, 402, 6, red); //bangkok
        circlefill(page, 1264, 653, 6, red); //perth
        ///AFFICHAGE BUFFER
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    allegro_exit(); // pr terminer le programme
}
