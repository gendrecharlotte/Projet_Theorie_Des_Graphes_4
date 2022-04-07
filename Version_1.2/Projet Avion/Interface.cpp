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
void Interface::affichage_interface(int type)
{
    ///CREATION VARIABLES BUFFER+IMAGES+POLICES
    BITMAP *page;
    BITMAP *image;
    BITMAP *grille;
    BITMAP *avion1;
    FONT *cn;
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
    /*///DEFINITION POILICE
    cn=load_font("polices/couriernew.pcx,",NULL,NULL);
    if (!cn)
    {
        allegro_message("pas pu trouver/charger couriernew.pcx");
        allegro_exit(); exit(EXIT_FAILURE);
    }*/
    ///DEFINITIONS COULEURS
    int red = makecol(255,0,0);
    //int blue = makecol(0,255,0);
    //int green = makecol(0,0,255);
    ///CREATION BUFFER
    page=create_bitmap(SCREEN_W,SCREEN_H);
    ///CHARGEMENT CARTE
    image=load_bitmap("images/carte.bmp",NULL);
    ///CHARGEMENT AVION
    avion1=load_bitmap("images/avion_prototype.bmp",NULL);
    ///DEFINITION POILICE
    cn=load_font("fonts/couriernew.pcx",NULL,NULL);
    grille=load_bitmap("images/grille.bmp",NULL);
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
        if (!image || !avion1)
        {
            allegro_message("pas pu trouver/charger image");
            allegro_exit(); exit(EXIT_FAILURE);
        }
        ///AFFICHAGE BITMAP PAR DESSUS BUFFER
        blit(image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(page,grille,0,0);
        draw_sprite(page,avion1,50,50);
        ///DESSINS CERCLES SUR BUFFER
        circlefill(page, 716, 204, 6, red); //paris
        textout_ex(page, cn, "PARIS(716,204)",716, 204,red,-1);
        circlefill(page, 391, 220, 6, red); //newyork
        textout_ex(page, cn, "NEWYORK(391,220)",391, 220,red,-1);
        circlefill(page, 347, 367, 6, red); //haiti
        textout_ex(page, cn, "HAITI(347,367)",347, 367,red,-1);
        circlefill(page, 371, 565, 6, red); //lapaz
        textout_ex(page, cn, "LAPAZ(371,565)",371, 565,red,-1);
        circlefill(page, 800, 657, 6, red); //capetown
        textout_ex(page, cn, "CAPETOWN(800,657)",800, 657,red,-1);
        circlefill(page, 1218, 402, 6, red); //bangkok
        textout_ex(page, cn, "BANGKOK(1218,402)",1218, 402,red,-1);
        circlefill(page, 1264, 653, 6, red); //perth
        textout_ex(page, cn, "PERTH(1264,653)",1264, 653,red,-1);
        ///ARCS
        //line(page,716, int y1, int y2, int color);
        ///AFFICHAGE BUFFER
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    allegro_exit(); // pr terminer le programme
}
