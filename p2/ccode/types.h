/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * GROUP: 3.4
 * DATE: 26 / 04 / 24
 */

#ifndef PRO2_2023_P2_TYPES_H
#define PRO2_2023_P2_TYPES_H

#define NAME_LENGTH_LIMIT 25
// Longitud máxima de un nombre de usuario y de un título de canción (constante)
#include <stdbool.h>

typedef char tUserName[NAME_LENGTH_LIMIT];
// Nombre de un usuario (string)
typedef enum {basic, pro} tUserCategory;
// Categoría de usuario (tipo enumerado: {basic, pro})
typedef int tPlayTime;
// Tiempo de reproducción, en minutos (int)
typedef char tSongTitle[NAME_LENGTH_LIMIT];
// Título de una canción (string)

typedef struct Song{
    tSongTitle songTitle;
    tPlayTime playTime;
} tSong;
/* Datos de una canción:
 * songTitle de tipo tSongTitle: título de la canción
 * playTime de tipo tPlayTime: duración de la canción
 */

#endif //PRO2_2023_P2_TYPES_H
