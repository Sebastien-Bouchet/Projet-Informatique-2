#include "header.h"
#define id_sol 0
#define id_joueur1 1
#define id_four 4
#define id_comptoire 5
#define id_assiette 10

void affichage_cuisine(element sol[12][20],BITMAP *cuisine,BITMAP *mur,element* perso1){
    int blanc = makecol(255,255,255), noir = makecol(0,0,0);

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 20; ++j) {
            if(sol[i][j].id == id_sol) {
                sol[i][j].image[0] = load_bitmap("cuisine/sol.bmp", NULL);
                rectfill(mur,sol[i][j].x,sol[i][j].y,(j+1)*(SCREEN_W/20),(i+1)*(SCREEN_H/12),blanc);
                stretch_blit(sol[i][j].image[0], cuisine, 0,0, sol[i][j].image[0]->w, sol[i][j].image[0]->h, sol[i][j].x, sol[i][j].y,SCREEN_W / 20, SCREEN_H / 12);
            }
            else if(sol[i][j].id == id_joueur1){
                sol[i][j].image[0] = load_bitmap("cuisine/sol.bmp",NULL);
                rectfill(mur,sol[i][j].x,sol[i][j].y,(j+1)*(SCREEN_W/20),(i+1)*(SCREEN_H/12),blanc);
                perso1->x = sol[i][j].x;
                perso1->y = sol[i][j].y;
                stretch_blit(sol[i][j].image[0],cuisine,0,0,sol[i][j].image[0]->w,sol[i][j].image[0]->h,sol[i][j].x, sol[i][j].y,SCREEN_W/20,SCREEN_H/12);
            }
            else if(sol[i][j].id == id_four){
                sol[i][j].image[0] = load_bitmap("cuisine/four.bmp",NULL);
                stretch_blit(sol[i][j].image[0],cuisine,0,0,sol[i][j].image[0]->w,sol[i][j].image[0]->h,sol[i][j].x, sol[i][j].y,SCREEN_W/20,SCREEN_H/12);
            }
            else if(sol[i][j].id == id_comptoire){
                sol[i][j].image[0] = load_bitmap("cuisine/comptoire.bmp",NULL);
                stretch_blit(sol[i][j].image[0],cuisine,0,0,sol[i][j].image[0]->w,sol[i][j].image[0]->h,sol[i][j].x, sol[i][j].y,SCREEN_W/20,SCREEN_H/12);
            }
            else if(sol[i][j].id == id_assiette){
                sol[i][j].image[0] = load_bitmap("cuisine/assiette.bmp",NULL);
                stretch_blit(sol[i][j].image[0],cuisine,0,0,sol[i][j].image[0]->w,sol[i][j].image[0]->h,sol[i][j].x, sol[i][j].y,SCREEN_W/20,SCREEN_H/12);
            }
        }
    }
}

void collision(BITMAP *mur,element *perso){
    int noir = makecol(0,0,0);
    if((getpixel(mur,perso->x+20,perso->y + (SCREEN_H/10)) == noir) || (getpixel(mur,perso->x+120,perso->y + (SCREEN_H/10)) == noir) || (getpixel(mur,perso->x+70,perso->y + (SCREEN_H/10)) == noir)){
        perso->x = perso->ancient_x;
        perso->y = perso->ancient_y;
    }
    if((getpixel(mur,perso->x+20,perso->y + perso->image[0]->h) == noir) || (getpixel(mur,perso->x+120,perso->y + perso->image[0]->h) == noir) || (getpixel(mur,perso->x+70,perso->y + perso->image[0]->h) == noir)){
        perso->x = perso->ancient_x;
        perso->y = perso->ancient_y;
    }
}

int chargement_niveau(element sol[12][20]){
    int id;
    FILE* file = fopen("niveautest.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 0;
    }
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 20; ++j) {
            fscanf(file,"%d",&id);
            sol[i][j].id = id;
            sol[i][j].x = j*(SCREEN_W/20);
            sol[i][j].y = i*(SCREEN_H/12);
        }
    }
    free(file);
    return 0;
}
void jeu1() {
    int couleur_fond = makecol(255, 255, 255);
    //int couleur = makecol(230, 230, 230);
    clear_to_color(screen, couleur_fond);
    BITMAP *page= create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *cuisine = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *mur = create_bitmap(SCREEN_W,SCREEN_H);
    element perso1;
    element perso2;
    element sol[12][20];
    chargement_niveau(sol);
    perso1.image[0] = load_bitmap("zombie/zombieD_1.bmp",NULL); perso1.x = 50; perso1.y = 50;
    perso1.image[1] = load_bitmap("zombie/zombieD_2.bmp",NULL);
    perso1.image[2] = load_bitmap("zombie/zombieD_3.bmp",NULL);
    perso1.image[3] = load_bitmap("zombie/zombieD_4.bmp",NULL);
    perso1.image[4] = load_bitmap("zombie/zombieG_1.bmp",NULL);
    perso1.image[5] = load_bitmap("zombie/zombieG_2.bmp",NULL);
    perso1.image[6] = load_bitmap("zombie/zombieG_3.bmp",NULL);
    perso1.image[7] = load_bitmap("zombie/zombieG_4.bmp",NULL);
    perso1.image[8] = load_bitmap("zombie/zombieH_1.bmp",NULL);
    perso1.image[9] = load_bitmap("zombie/zombieH_2.bmp",NULL);
    perso1.image[10] = load_bitmap("zombie/zombieH_3.bmp",NULL);
    perso1.image[11] = load_bitmap("zombie/zombieH_4.bmp",NULL);
    perso1.image[12] = load_bitmap("zombie/zombieB_1.bmp",NULL);
    perso1.image[13] = load_bitmap("zombie/zombieB_2.bmp",NULL);
    perso1.image[14] = load_bitmap("zombie/zombieB_3.bmp",NULL);
    perso1.image[15] = load_bitmap("zombie/zombieB_4.bmp",NULL);
    perso2.image[0] = load_bitmap("font_menu.bmp",NULL); perso2.x = 50; perso2.y = 50;
    affichage_cuisine(sol , cuisine, mur ,&perso1);
    perso1.ancient_x = perso1.x;
    perso1.ancient_y = perso1.y;
    /*rectfill(screen, 50, 25, 100, 150, couleur);
    rectfill(screen, 250, 25, 200, 150, couleur);
    rectfill(screen, 110, 175, 190, 200, couleur);*/
    int i =0,vitesse_anim=1;
    while (!key[KEY_ESC]) {
        if(perso1.x >  0) {
            if (key[KEY_A]) {
                perso1.ancient_x = perso1.x;
                perso1.x -= 5;
                if(vitesse_anim == 7) {
                    if (i > 6 || i<4) {
                        i = 5;
                    }
                    else {
                        i++;
                    }
                }
                if(vitesse_anim > 7){
                    vitesse_anim = 0;
                }
            }
        }
        if(perso1.x < SCREEN_W-perso1.image[0]->w) {
            if (key[KEY_D]) {
                perso1.ancient_x = perso1.x;
                perso1.x += 5;
                if(vitesse_anim == 7) {
                    if (i > 2) {
                        i = 0;
                    } else {
                        i++;
                    }
                }
                if(vitesse_anim > 7){
                    vitesse_anim = 0;
                }
            }
        }
        if(perso1.y >  0) {
            if (key[KEY_W]) {
                perso1.ancient_y = perso1.y;
                perso1.y -= 5;
                if(vitesse_anim == 7) {
                    if (i > 10 || i<8) {
                        i = 9;
                    }
                    else {
                        i++;
                    }
                }
                if(vitesse_anim > 7){
                    vitesse_anim = 0;
                }
            }
        }
        if(perso1.y < SCREEN_H-perso1.image[0]->h) {
            if (key[KEY_S]) {
                perso1.ancient_y = perso1.y;
                perso1.y += 5;
                if(vitesse_anim == 7) {
                    if (i > 14 || i<12) {
                        i = 13;
                    }
                    else {
                        i++;
                    }
                }
                if(vitesse_anim > 7){
                    vitesse_anim = 0;
                }
            }
        }
        if(perso2.x >  0) {
            if (key[KEY_LEFT]) {
                perso2.ancient_x = perso2.x;
                perso2.x -= 5;
            }
        }
        if(perso2.x < SCREEN_W-50) {
            if (key[KEY_RIGHT]) {
                perso2.ancient_x = perso2.x;
                perso2.x += 5;
            }
        }
        if(perso2.y >  0) {
            if (key[KEY_UP]) {
                perso2.ancient_y = perso2.y;
                perso2.y -= 5;
            }
        }
        if(perso2.y < SCREEN_H-50) {
            if (key[KEY_DOWN]) {
                perso2.ancient_y = perso2.y;
                perso2.y += 5;
            }
        }
        vitesse_anim+=1;
        collision(mur,&perso1);
        //stretch_blit(perso2.image[0],page,0,0,perso2.image[0]->w,perso2.image[0]->h,0,0,SCREEN_W,SCREEN_H);
        blit(cuisine,page,0,0,0,0,SCREEN_W,SCREEN_H);
        //blit(mur,page,0,0,0,0,SCREEN_W,SCREEN_H);
        stretch_sprite(page,perso1.image[i],perso1.x,perso1.y,SCREEN_W*0.07,SCREEN_H*0.174);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(page);
    }
}

void menu(){
    BITMAP *page = create_bitmap(SCREEN_W,SCREEN_H);
    element font_menu;
    element selecteur;
    font_menu.image[0] = load_bitmap("font_menu2.bmp",NULL);
    selecteur.image[0] =load_bitmap("fleche2.bmp",NULL);
    int couleur_fond = makecol(255,255,255);
    int quitter=1;
    /*int couleur = makecol(0,0,0);
    int couleur_2 = makecol(0,50,200);*/
    clear_to_color(screen,couleur_fond);
    show_mouse(screen);
    selecteur.x=0;
    selecteur.y=0;
    while (quitter){
        clear_bitmap(page);
        if(mouse_x > SCREEN_W*0.37 && mouse_x <SCREEN_W*0.57){
            if(mouse_y > SCREEN_H*0.44 && mouse_y < SCREEN_H*0.55){
                selecteur.x=SCREEN_W*0.37;
                selecteur.y=SCREEN_H*0.47;
                //rectfill(screen,100,250,600,300,couleur_2);
                //textprintf_centre_ex(screen,font,350,275,couleur_fond,couleur_2,"le jeu la");
                if(mouse_b){
                    jeu1();
                    clear_to_color(screen,couleur_fond);
                }
            }
            else if(mouse_y > SCREEN_H*0.56 && mouse_y < SCREEN_H*0.67){
                selecteur.x=SCREEN_W*0.37;
                selecteur.y=SCREEN_H*0.59;
                if(mouse_b){
                    quitter=0;
                }
                //rectfill(screen,260,280,395,335,couleur);
                //textprintf_centre_ex(screen,font,350,275,couleur_fond,couleur,"le jeu la");
            }
        }
        if(mouse_x > SCREEN_W*0.09 && mouse_x < SCREEN_W*0.34){
            //rectfill(screen,65,250,239,307,couleur_2);
            if(mouse_y > SCREEN_H*0.44 && mouse_y < SCREEN_H*0.55){
                selecteur.x=SCREEN_W*0.09;
                selecteur.y=SCREEN_H*0.47;
                //rectfill(screen,100,250,600,300,couleur_2);
                //textprintf_centre_ex(screen,font,350,275,couleur_fond,couleur_2,"le jeu la");

            }
            else if(mouse_y > SCREEN_H*0.56 && mouse_y < SCREEN_H*0.67){
                selecteur.x=SCREEN_W*0.09;
                selecteur.y=SCREEN_H*0.59;
                //rectfill(screen,260,280,395,335,couleur);
                //textprintf_centre_ex(screen,font,350,275,couleur_fond,couleur,"le jeu la");
            }
        }
        stretch_blit(font_menu.image[0],page,0,0,font_menu.image[0]->w,font_menu.image[0]->h,0,0,SCREEN_W,SCREEN_H);
        //blit(font_menu.image,page,0,0,0,0,SCREEN_W,SCREEN_H);
        //blit(selecteur.image,page,0,0,selecteur.x,selecteur.y,selecteur.image->w,selecteur.image->h)!;
        stretch_sprite(page,selecteur.image[0],selecteur.x,selecteur.y,SCREEN_W*0.07,SCREEN_H*0.05);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}