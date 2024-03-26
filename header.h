#ifndef PROJET_INFORMATIQUE_2_HEADER_H
#define PROJET_INFORMATIQUE_2_HEADER_H

#include <stdio.h>
#include <allegro.h>
#include <unistd.h>

typedef struct {
    int x, y;
    int dx, dy;
    int couper;
    int prendre;
    int poser;
    BITMAP *image;
} Action;

//void DeplacementJoueurs(Action Dragon, Action Serpent);

#endif //PROJET_INFORMATIQUE_2_HEADER_H
