#include <stdio.h>
#include <allegro.h>
#include <unistd.h>
#include "header.h"

/*
void DeplacementJoueurs (Action Dragon, Action Serpent) {

    allegro_init();
    install_keyboard();
    install_mouse();

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
    allegro_exit();
}*/