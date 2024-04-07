#include <stdio.h>
#include <allegro.h>
#include <unistd.h>
#include "header.h"

typedef struct Element {
    int id;
    int x, y, ancien_x, ancien_y;
    int etat; // Etat 1, 2, 3 pour [pas cuit, cuit, brûlé], etc.
    BITMAP *image[10];
} element;




typedef struct {
    int x, y;
    int dx, dy;
    int couper;
    int prendre;
    int poser;
    BITMAP *image;
} Action;

typedef struct {
    int x, y;
    BITMAP *image;
} Aliment;

void deplacement(Action Dragon, Aliment tomate, BITMAP *page) {
    if ((Dragon.x >= tomate.x - 5 && Dragon.x <= tomate.x + 5) &&
        (Dragon.y >= tomate.y - 5 && Dragon.y <= tomate.y + 5)) {
        if (key[KEY_V]) {
            while (key[KEY_V]) {
                tomate.x = Dragon.x;
                tomate.y = Dragon.y;
                Dragon.image = load_bitmap("../images/dragon/moustique.bmp", NULL);
                stretch_blit(Dragon.image, page, 0, 0, Dragon.image->w, Dragon.image->h, Dragon.x, Dragon.y, 50, 50);
                stretch_blit(tomate.image, page, 0, 0, tomate.image->w, tomate.image->h, tomate.x, tomate.y, 50, 50);
            }
        }
    }
}

int main() {
    allegro_init();
    install_keyboard();
    install_mouse();

    /*FILE *fichier = fopen("map.txt", "r");   // Ouverture du fichier en mode lecture
    if (fichier == NULL) {       // On vérifie que le fichier puisse s'ouvrir
        printf("Erreur lors de l'ouverture du fichier.\n");
        return -1;
    }*/

    // Initialiser la profondeur de couleurs de votre écran
    set_color_depth(desktop_color_depth());

    // Ouvrir une fenêtre
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Erreur d'ouverture de la fenetre");
        return 1;
    }

    BITMAP *page = create_bitmap(SCREEN_W, SCREEN_H);

    Action Dragon;
    Action Serpent;
    Action Sol;
    Aliment tomate;

    Dragon.x = 200, Dragon.y = 200, Dragon.dx = 0, Dragon.dy = 0;
    Serpent.x = 100, Serpent.y = 100, Serpent.dx = 0, Serpent.dy = 0;
    Sol.x = 0, Sol.y = 0, Sol.dx = 0, Sol.dy = 0;
    tomate.x = 400;
    tomate.y = 400;

    tomate.image = load_bitmap("../images/dragon/crabe.bmp", NULL);
    Dragon.image = load_bitmap("../images/dragon/dragon.bmp", NULL);
    Serpent.image = load_bitmap("../images/dragon/serpent.bmp", NULL);
    Sol.image = load_bitmap("../images/dragon/screensol_24bit.bmp", NULL);

    if (Dragon.image == NULL) {
        printf("Dragon pas ici");
        exit(-1);
    }
    if (Serpent.image == NULL) {
        printf("Serpent pas trouve");
        exit(-1);
    }
    if (Sol.image == NULL) {
        printf("Sol inexistant");
        exit(-1);
    }

    int CaseW = SCREEN_W/20;
    int CaseH = SCREEN_H/12;

    while (!key[KEY_ESC]) {
        clear_bitmap(page);
        //DeplacementJoueurs(Dragon, Serpent);
        if (key[KEY_LEFT]) {
            Dragon.dx = -3;
        }
        if (key[KEY_UP]) {
            Dragon.dy = -3;
        }
        if (key[KEY_RIGHT]) {
            Dragon.dx = 3;
        }
        if (key[KEY_DOWN]) {
            Dragon.dy = 3;
        }
        else if (!key[KEY_LEFT] && !key[KEY_UP] && !key[KEY_RIGHT] && !key[KEY_DOWN]){
            Dragon.dx = 0;
            Dragon.dy = 0;
        }

        if (key[KEY_A]) {
            Serpent.dx = -3;
        }
        if (key[KEY_W]) {
            Serpent.dy = -3;
        }
        if (key[KEY_D]) {
            Serpent.dx = 3;
        }
        if (key[KEY_S]) {
            Serpent.dy = 3;
        }
        else if (!key[KEY_A] && !key[KEY_W] && !key[KEY_D] && !key[KEY_S]){
            Serpent.dx = 0;
            Serpent.dy = 0;
        }


        if ((Dragon.x + Dragon.dx) + 50 > SCREEN_W) {
            Dragon.dx *= -1;
        } else if ((Dragon.x + Dragon.dx) < 0) {
            Dragon.dx *= -1;
        } else {
            Dragon.x += Dragon.dx;
        }

        if ((Dragon.y + Dragon.dy) + 50 > SCREEN_H) {
            Dragon.dy *= -1;
        } else if ((Dragon.y + Dragon.dy) < 0) {
            Dragon.dy *= -1;
        } else {
            Dragon.y += Dragon.dy;
        }


        if ((Serpent.x + Serpent.dx) + 50 > SCREEN_W) {
            Serpent.dx *= -1;
        } else if ((Serpent.x + Serpent.dx) < 0) {
            Serpent.dx *= -1;
        } else {
            Serpent.x += Serpent.dx;
        }

        if ((Serpent.y + Serpent.dy) + 50 > SCREEN_H) {
            Serpent.dy *= -1;
        } else if ((Serpent.y + Serpent.dy) < 0) {
            Serpent.dy *= -1;
        } else {
            Serpent.y += Serpent.dy;
        }

        /*//Découpage
        if ((Dragon.x + Dragon.dx) == //bloc découpage//) {
            if (//S'il y a une pomme sur le bloc découpage. Par ex, if (10 == 2) — si on dit que pomme = 10 et bloc découpage = 2)// {
                Pomme.image = imagetmp;
                Pomme.decoupee = imagetmp;
                Pomme.image = NULL;
            }
        }*/

        for (int ligne = 0; ligne < 12; ligne++) {
            for (int colonne = 0; colonne < 20; colonne++) {
                stretch_blit(Sol.image, page, 0, 0, Sol.image->w, Sol.image->h, colonne * CaseW, ligne * CaseH, CaseW, CaseH);
            }
        }
        deplacement(Dragon, tomate, page);
        stretch_blit(tomate.image, page, 0, 0, tomate.image->w, tomate.image->h, tomate.x, tomate.y, 50, 50);
        stretch_blit(Dragon.image, page, 0, 0, Dragon.image->w, Dragon.image->h, Dragon.x, Dragon.y, 50, 50);
        stretch_blit(Serpent.image, page, 0, 0, Serpent.image->w, Serpent.image->h, Serpent.x, Serpent.y, 50, 50);
        /*draw_sprite(page, Dragon.image, Dragon.x, Dragon.y);
        draw_sprite(page, Serpent.image, Serpent.x, Serpent.y);*/
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(20);
    }
    allegro_exit();
    return 0;
} END_OF_MAIN()
