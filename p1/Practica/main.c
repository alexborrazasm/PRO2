/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alexandre Borrazás Mancebo   LOGIN 1: alexandre.bmancebo
 * AUTHOR 2: Carlos Losada Gómez          LOGIN 2: carlos.lgomez
 * GROUP: 3.4
 * DATE: 16 / 03 / 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

tSong getSong(char *name);
/* getSong (string) -> tSong
 * Función constructora:
 *  Objetivo:
 *      Crea un tipo tSong, a partir de nombre (string).
 *  Entrada:
 *      name -> string.
 *  Salida:
 *      tSong -> struct tSong
*/

void getCategory(char *output, tUserCategory input);
/* getCategory (string, tUserCategory) -> string
 * Función constructora:
 *  Objetivo:
 *      Convierte un enum (el que representa la categoría) en cadena de caracteres.
 *  Entrada:
 *      input -> enum tUserCategory.
 *  Salida:
 *      output -> string que representa el nombre de la categoría.
 *  Precondición:
 *      Debe ser o 0 -> basic o 1 -> pro
*/

tNumPlay getUserInfo(char *name, char *category, tList list, tPosL pos);
/* getUserInfo (string, string, tList, tPosL) -> tNumPLay, string, string
 * Función constructora:
 *  Objetivo:
 *      Obtiene la información de un usuario(nombre, categoría y número de
 *      reproducciones), a partir de una lista.
 *  Entrada:
 *      name -> string que representa el nombre de usuario.
 *      category -> string que representa la categoría del usuario.
 *      list -> Lista de donde sacar la información.
 *      pos -> Posición de la lista.
 *  Salida:
 *      tNumPlay -> número de reproducciones.
 *      name -> string que representa el nombre de usuario.
 *      category -> string que representa la categoría del usuario.
 *  Precondición:
 *      Debe ser o 0 -> basic o 1 -> pro
*/

void new(char *name, char *category, tList* list);
/* new (string, string, tList) -> tList
 * Función constructora:
 *  Objetivo:
 *      Se incorporará un usuario al final de la lista de usuarios, con la categoría
 *      indicada y con su número de reproducciones inicializado a 0.
 *  Entrada:
 *      name -> nombre del nuevo usuario.
 *      category -> categoría del nuevo usuario.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> La lista con un nuevo usuario.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void delete(char *username, tList* list);
/* delete (string, tList) -> tList
 * Función destructora:
 *  Objetivo:
 *      Se buscará al usuario en la lista y posteriormente se eliminará de la misma.
 *  Entrada:
 *      name -> nombre usuario a buscar y a eliminar.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> Lista sin el usuario.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void upgrade(char *user, tList* list);
/* upgrade (string, tList) -> tList
 * Función modificadora:
 *  Objetivo:
 *      Se buscará al usuario en la lista y se actualizará su categoría a pro.
 *  Entrada:
 *      name -> nombre usuario a buscar y a actualizar.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> Lista con la categoría del usuario cambiada.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void play(char *user, char *songSring, tList* list);
/* play (string, tList) -> tList
 * Función modificadora:
 *  Objetivo:
 *      Se buscará al usuario en la lista y se incrementará su contador de
 *      reproducciones en 1.
 *  Entrada:
 *      name -> Nombre usuario a buscar y a actualizar.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> Lista con el usuario con una nueva reproducción.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void stats(tList list);
/* stats (tList)
 * Función observadora:
 *  Objetivo:
 *      se mostrará por pantalla la lista completa de usuarios actuales.
 *  Entrada:
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

tSong getSong(char *name) {
    tSong song;
    strcpy(song.songTitle, name); // Copia el nombre a la estructura tSong
    return song;
}

void getCategory(char *output, tUserCategory input) { // gets category string
    // WARNING, it only considers pro or basic, it does not check errors
    if (input == basic) {
        strcpy(output,"basic");
    } else {
        strcpy(output, "pro");
    }
}

tNumPlay getUserInfo(char *name, char *category, tList list, tPosL pos) {
    tItemL item = getItem(pos, list);
    strcpy(name, item.userName);
    getCategory(category, item.userCategory);
    return item.numPlay;
}

void new(char *name, char *category, tList* list) {
    tItemL item;
    // Set username
    strcpy(item.userName, name);
    // Set category
    if (strcmp(category, "basic") == 0) {
        item.userCategory = basic; // Establece la categoría del usuario como básica
    } else if (strcmp(category, "pro") == 0) {
        item.userCategory = pro; // Establece la categoría del usuario como pro
    } else {
        // Mensaje de error si la categoría no es válida
        printf("+ Error: New category not valid\n");
        return;
    }
    // Set number of plays to 0
    item.numPlay = 0;
    // Add to list
    if (findItem(name, *list) == LNULL) {  // ¿El nombre de usuario existe?
        // Intenta insertar el usuario en la lista
        if (insertItem(item, LNULL, list)) {
            printf("* New: user %s category %s\n", name, category);
            return; // Inserción correcta
        }
    }
    // Inserción incorrecta
    printf("+ Error: New not possible\n");
}

void delete(char *username, tList* list) {
    tUserName name;
    char category[6];
    tNumPlay nPlay;
    tPosL pos;
    pos = findItem(username, *list); // Busca la posición del usuario en la lista
    if (pos != LNULL) {
        // Get print info
        nPlay = getUserInfo(name ,category, *list, pos);
        deleteAtPosition(pos, list); // Elimina el usuario de la lista
        printf("* Delete: user %s category %s numplays %d\n", name, category, nPlay);
    } else {
        // Mensaje de error si la eliminación no fue posible
        printf("+ Error: Delete not possible\n");
    }
}

void upgrade(char *user, tList* list) {
    tPosL pos = findItem(user, *list); // Busca la posición del usuario en la lista
    tItemL item;

    // Si la lista no está vacía y el usuario existe
    if (!isEmptyList(*list) && pos != LNULL) {
        item = getItem(pos, *list); // Obtiene el usuario en la posición encontrada
        if (item.userCategory != pro) {
            item.userCategory = pro; // Actualiza la categoría a "pro"
            updateItem(item, pos, list); // Actualiza el usuario en la lista
            printf("* Upgrade: user %s category %s\n", user, "pro");
            return;
        }
    }
    // Mensaje de error, la actualización no fue posible
    printf("+ Error: Upgrade not possible\n");
}

void play(char *user, char *songString, tList* list) {
    tPosL pos = findItem(user, *list); // Busca la posición del usuario en la lista
    tItemL item;
    tSong song = getSong(songString);

    if (pos != LNULL) { // Si el usuario existe en la lista
        item = getItem(pos, *list); // Obtiene el usuario en la posición encontrada
        item.numPlay++; // Incrementa el número de reproducciones
        updateItem(item, pos, list); // Actualiza el usuario en la lista
        printf("* Play: user %s plays song %s numplays %d\n", user, song.songTitle, item.numPlay);
    } else {
        // Mensaje de error si la reproducción no fue posible
        printf("+ Error: Play not possible\n");
    }
}

void stats(tList list) {
    tPosL pos; tItemL item; tUserName name; char category[6]; tNumPlay nPlay;
    int basicUsers = 0, proUsers = 0;  int basicPlays = 0, proPlays = 0;
    float basicAvg = 0, proAvg = 0;

    if (!isEmptyList(list)) { // Si la lista no está vacía
        pos = first(list); // Obtiene la primera posición de la lista
        while (pos != LNULL) { // Mientras la lista no estea vacía
            item = getItem(pos, list); // Obtiene el usuario de la lista
            nPlay = getUserInfo(name, category, list, pos); // Obtiene la información
            pos = next(pos, list); // Obtiene la posición del siguiente usuario
            // Imprime la información del usuario
            printf("User %s category %s numplays %d\n", name, category, nPlay);
            // Cuenta usuario por categoría y reproducciones para luego hacer el promedio
            if (item.userCategory == basic) {
                basicUsers++;
                basicPlays += item.numPlay;
            } else if (item.userCategory == pro) {
                proUsers++;
                proPlays += item.numPlay;
            } else {
                printf("+ Error: stats category\n");
            }
        }
        // Calcula el promedio de reproducciones por usuario para cada categoría
        if (basicUsers > 0) { // Avoid division by zero
            // Promedio de reproducciones para usuarios básicos
            basicAvg = (float)basicPlays/(float)basicUsers;
        }
        if (proUsers > 0) { // Avoid division by zero
            // Promedio de reproducciones para usuarios "pro"
            proAvg = (float)proPlays/(float)proUsers;
        }

        // Muestra las estadísticas generales
        printf("Category  Users  Plays  Average\n"
                      "Basic     %5d %6d %8.2f\n"
                      "Pro       %5d %6d %8.2f\n",
                      basicUsers, basicPlays, basicAvg,
                      proUsers, proPlays, proAvg);
    } else {
        // Mensaje de error si no es posible calcular las estadísticas
        printf("+ Error: Stats not possible\n");
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList* userdata) {
    puts("********************");
    switch (command) {
        case 'N': // Nuevo usuario
            //printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            new(param1, param2, userdata);
            break;
        case 'D': // Eliminar usuario
            printf("%s %c: user %s\n", commandNumber, command, param1);
            delete(param1, userdata);
            break;
        case 'U': // Actualizar categoría
            printf("%s %c: user %s\n", commandNumber, command, param1);
            upgrade(param1, userdata);
            break;
        case 'P': // Reproducir canción
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            play(param1, param2, userdata);
            break;
        case 'S': // Mostrar estadísticas
            printf("%s %c:\n", commandNumber, command);
            stats(*userdata);
            break;
        default:
            printf("+ Error: Invalid option, try again\n");
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        tList userdata;
        createEmptyList(&userdata);

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, &userdata);
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






