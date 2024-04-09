#ifndef BETA_JEU_HEADER_H
#define BETA_JEU_HEADER_H
#include <stdio.h>
#include <allegro.h>

typedef struct Element {
    int id;
    int x, y,ancient_x,ancient_y;//position x et y
    int etat;//etat 1,2 et 3 pour [pas cuit,cuit,brulé] ou [pas coupé,coupé,rien] ou [vide,presque plein,plein] ou [normal, main pleine,occupé]
    BITMAP *image[16];
} element;

void affichage_cuisine(element sol[12][20],BITMAP *cuisine,BITMAP *mur,element* perso1);
void collision(BITMAP *mur,element *perso);
int chargement_niveau(element sol[12][20]);
void jeu1();
void menu();
#endif //BETA_JEU_HEADER_H
