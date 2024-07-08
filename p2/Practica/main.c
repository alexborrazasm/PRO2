/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * AUTHOR 2: Carlos Losada Gómez        LOGIN 2: carlos.lgomez
 * GROUP: 3.4
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

int strToCategory(char* string) {
    if (strcmp(string, "basic") == 0) {
        return basic;
    } else if (strcmp(string, "pro") == 0) {
        return pro;
    } else {
        // Categoría no válida
        return 3;
    }
}

void categoryToStr(char* string, tUserCategory cat) {
    // WARNING, it only considers pro or basic, it does not check errors
    if (cat == basic) {
        strcpy(string,"basic");
    } else {
        strcpy(string, "pro");
    }
}

tPlayTime getUserInfo(char *name, char *category, tListU list, tPosU pos) {
    tItemU item = getItemU(pos, list);
    strcpy(name, item.userName);
    categoryToStr(category, item.userCategory);
    return item.totalPlayTime;
}

void printSongs(tListS list) {
    int p; tItemS item;
    if (isEmptyListS(list)) {
        puts("No songs");
    } else {
        p = firstS(list);
        while (p != NULLS) {
            item = getItemS(p, list);
            printf("Song %s playtime %d\n",
                   item.songTitle, item.playTime);
            p = nextS(p, list);
        }
    }
    puts("");
}

void new(char *name, char *category, tListU* list) {
    tItemU item;
    tUserCategory cat = strToCategory(category);
    // Set username
    strcpy(item.userName, name);
    // Set category
    if (cat == 3) {
        // Mensaje de error si la categoría no es válida
        puts("+ Error: New category not valid");
        return;
    } else { // Establecemos la categoría
        item.userCategory = cat;
    }
    // Set number of plays to 0
    item.totalPlayTime = 0;
    // inicializar la lista de canciones
    createEmptyListS(&item.songList);
    // Add to list
    if (findItemU(name, *list) == NULLU) { // Si no existe ya el usuario
        // Intenta insertar el usuario en la lista
        if (insertItemU(item, list)) {
            printf("* New: user %s category %s\n", name, category);
            return; // Inserción correcta
        }
    }
    // Inserción incorrecta
    puts("+ Error: New not possible");
}

void delete(char *username, tListU* list) {
    tUserName name;
    char category[6];
    tPlayTime totalPlayT;
    tPosU pos;
    // Busca la posición del usuario en la lista
    pos = findItemU(username, *list);
    if (pos != NULLU) {
        // Get print info
        totalPlayT = getUserInfo(name ,category, *list, pos);
        deleteAtPositionU(pos, list); // Elimina el usuario de la lista
        printf("* Delete: user %s category %s totalplaytime %d\n",
               name, category, totalPlayT);
    } else {
        // Mensaje de error si la eliminación no fue posible
        puts("+ Error: Delete not possible");
    }
}

void upgrade(char *user, tListU* list) {
    // Busca la posición del usuario en la lista
    tPosU pos = findItemU(user, *list);
    tItemU item;

    // Si la lista no está vacía y el usuario existe
    if (!isEmptyListU(*list) && pos != NULLU) {
        // Obtiene el usuario en la posición encontrada
        item = getItemU(pos, *list);
        if (item.userCategory != pro) {
            item.userCategory = pro; // Actualiza la categoría a "pro"
            updateItemU(item, pos, list);
            printf("* Upgrade: user %s category %s\n", user, "pro");
            return;
        }
    }
    // Mensaje de error, la actualización no fue posible
    puts("+ Error: Upgrade not possible");
}

void add(char* userName, char* songTitle, tListU *userData) {
    tPosU posU = findItemU(userName, *userData);
    tItemU itemU; tItemS itemS; tPosS posS;

    if (posU != NULLU) {
        itemU = getItemU(posU, *userData);
        posS = findItemS(songTitle, itemU.songList);

        if (posS == NULLS) {
            // Añadimos la canción
            strcpy(itemS.songTitle, songTitle);
            itemS.playTime = 0;
            if (insertItemS(itemS, NULLS, &itemU.songList)) {
                printf("* Add: user %s adds song %s\n",
                       itemU.userName, itemS.songTitle);
                // Actualizar el usuario con la nueva canción
                updateItemU(itemU, posU,userData);
                return;
            }
        }
    }
    puts("+ Error: Add not possible");
}

void play(char* userName, char* songTitle, char* minutes, tListU *userData) {
    tPosU posU = findItemU(userName, *userData);
    tItemU user; tPosS posS; tItemS song; int n;

    if (posU != NULLU) { // Usuario existe
        user = getItemU(posU, *userData);
        posS = findItemS(songTitle, user.songList);
        if (posS != NULLS) { // La canción existe
            song = getItemS(posS, user.songList);
            // Aumentamos contador
            n = atoi(minutes);
            user.totalPlayTime+=n;
            song.playTime+=n;
            // Mensaje de éxito
            printf("* Play: user %s plays song %s "
                   "playtime %d totalplaytime %d\n",
                   userName, song.songTitle, song.playTime, user.totalPlayTime);
            // Actualizamos las listas
            updateItemS(song, posS, &user.songList);
            updateItemU(user, posU, userData);
            return;
        }
    }
    puts("+ Error: Play not possible");
}

void stats(tListU userData) {
    tPosU pos; tItemU item; tUserName name; char category[6]; tPlayTime nPlayT;
    int basicUsers = 0, proUsers = 0; int basicPlaysT = 0, proPlaysT = 0;
    float basicAvgT = 0, proAvgT = 0;

    if (!isEmptyListU(userData)) { // Si la lista no está vacía
        pos = firstU(userData); // Obtiene la primera posición de la lista
        while (pos != NULLU) { // Mientras la lista no estea vacía
            // Obtiene el usuario de la lista
            item = getItemU(pos, userData);
            // Obtiene la información
            nPlayT = getUserInfo(name, category, userData, pos);
            pos = nextU(pos, userData); // Posición del siguiente usuario
            // Imprime la información del usuario
            printf("User %s category %s totalplaytime %d\n",
                   name, category, nPlayT);
            printSongs(item.songList);
            // Cuenta usuario por categoría y reproducciones
            if (item.userCategory == basic) {
                basicUsers++;
                basicPlaysT += item.totalPlayTime;
            } else if (item.userCategory == pro) {
                proUsers++;
                proPlaysT += item.totalPlayTime;
            } else {
                printf("+ Error: stats category\n");
            }
        }
        // Calcula el promedio de reproducciones por usuario para cada categoría
        if (basicUsers > 0) { // Avoid division by zero
            // Promedio de reproducciones para usuarios básicos
            basicAvgT = (float)basicPlaysT/(float)basicUsers;
        }
        if (proUsers > 0) { // Avoid division by zero
            // Promedio de reproducciones para usuarios "pro"
            proAvgT = (float)proPlaysT/(float)proUsers;
        }

        // Muestra las estadísticas generales
        printf("Category  Users  TimePlay  Average\n"
                      "Basic     %5d %9d %8.2f\n"
                      "Pro       %5d %9d %8.2f\n",
                      basicUsers, basicPlaysT, basicAvgT,
                      proUsers, proPlaysT, proAvgT);
    } else {
        // Mensaje de error si no es posible calcular las estadísticas
        printf("+ Error: Stats not possible\n");
    }
}

void removeB(char* max, tListU *userData) {
    int maxPlays = atoi(max);
    tItemU user; tPosU p;
    for (p = firstU(*userData); p != NULLU; p = nextU(p, *userData)) {
        user = getItemU(p, *userData);
        if (user.totalPlayTime > maxPlays) {
            printf("Removing user %s totalplaytime %d\n",
                   user.userName, user.totalPlayTime);
            deleteAtPositionU(p, userData);
            return;
        }
    }
    puts("+ Error: Remove not possible");
}

void processCommand(char *commandNumber, char command, char *param1,
                    char *param2, char *param3, tListU *userData) {
    puts("********************");
    switch (command) {
        case 'N':
            printf("%s %c: user %s category %s\n",
                   commandNumber, command, param1, param2);
            new(param1, param2, userData);
            break;
        case 'D':
            printf("%s %c: user %s\n",
                   commandNumber, command, param1);
            delete(param1, userData);
            break;
        case 'A':
            printf("%s %c: user %s song %s\n",
                   commandNumber, command, param1, param2);
            add(param1, param2, userData);
            break;
        case 'U':
            printf("%s %c: user %s\n", commandNumber, command, param1);
            upgrade(param1, userData);
            break;
        case 'P':
            printf("%s %c: user %s song %s minutes %s\n",
                   commandNumber, command, param1, param2, param3);
            play(param1, param2, param3, userData);
            break;
        case 'S':
            printf("%s %c:\n", commandNumber, command);
            stats(*userData);
            break;
        case 'R':
            printf("%s %c: maxtime %s \n",
                   commandNumber, command, param1);
            removeB(param1, userData);
            break;
        default:
            printf("+ Error: Invalid option, try again\n");
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {
        tListU userData;
        createEmptyListU(&userData);

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2,
                           param3, &userData);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}
