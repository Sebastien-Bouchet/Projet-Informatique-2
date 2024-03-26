cmake_minimum_required(VERSION 3.26)
project(Projet_Informatique_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Informatique_2
        main.c
        fonctions.c
        header.h)

target_link_libraries(Projet_Informatique_2 -lmingw32 -lalleg44)