/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alexandre Borrazás Mancebo   LOGIN 1: alexandre.bmancebo
 * AUTHOR 2: Carlos Losada Gómez          LOGIN 2: carlos.lgomez
 * GROUP: 3.4
 * DATE: 16 / 03 / 2024
 */

#ifndef PRO2_2023_P1_TYPES_H
#define PRO2_2023_P1_TYPES_H


#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

typedef char tUserName[NAME_LENGTH_LIMIT];
typedef char tSongTitle[NAME_LENGTH_LIMIT];
typedef int tNumPlay;

// Define la estructura de datos de la categoría del usuario
typedef enum {basic, pro} tUserCategory;  // basic -> 0 y pro -> 1

// Define una estructura de datos para representar al un usuario de FIC music
typedef struct tItemL {
    tUserName userName;          // Nombre de usuario string 25 char
    tNumPlay numPlay;            // entero que presenta en número de reproducciones
    tUserCategory userCategory;
} tItemL;

typedef struct tSong{
    tSongTitle songTitle;
} tSong;

#endif //PRO2_2023_P1_TYPES_H
