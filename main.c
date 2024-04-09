#include <stdio.h>
#include <allegro.h>
#include "header.h"
#define id_sol 0
#define id_joueur1 1
#define id_four 4
#define id_comptoire 5
#define id_assiette 10

int main() {
    allegro_init();
    install_mouse();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1800,1000,0,0) != 0){
        allegro_message("erreur d'ouverture");
        return 1;
    }
    menu();
    allegro_exit();
    return 0;
} END_OF_MAIN()
