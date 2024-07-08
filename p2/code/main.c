/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * GROUP: 3.4
 * DATE: 26 / 04 / 24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

int strToCategory(const char* string);
/* strToCategory (string) -> int
 * Función constructora:
 *  Objetivo:
 *      Convierte la string que representa la categoría en la equivalencia al enum
 *      (tUserCategory).
 *  Entrada:
 *      string -> string que representa la categoría.
 *  Salida:
 *      int -> entero que representa la categoría segun el enum tUserCategory.
 *  Precondición:
 *      Debe ser o una categoría válida, o "basic" o "pro".
*/

void categoryToStr(char* string, tUserCategory cat);
/* categoryToStr (string, tUserCategory) -> string
 * Función constructora:
 *  Objetivo:
 *      Convierte un enum (el que representa la categoría) en cadena de caracteres.
 *  Entrada:
 *      cat -> enum tUserCategory.
 *  Salida:
 *      string -> string que representa el nombre de la categoría.
 *  Precondición:
 *      Debe ser o 0 -> basic o 1 -> pro
*/

tPlayTime getUserInfo(tItemU item, char *name, char *category);
/* getUserInfo (string, string, tListU, tPosU) -> tPlayTime, string, string
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
 *      tPlayTime -> total de minutos reproducidos por el usuario.
 *      name -> string que representa el nombre de usuario.
 *      category -> string que representa la categoría del usuario.
 *  Precondición:
 *      La categoría debe ser 0 -> basic o 1 -> pro.
*/

void printSongs(tListS list);
/* printSongs (tList)
 * Función observadora:
 *  Objetivo:
 *      Mostrar por pantalla una lista de canciones, si la lista está vacía muestra:
 *      "No songs"
 *  Entrada:
 *      list -> La lista de canciones.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void removeSongList(tListS *songList);
/* removeSongList (tList) -> tList
 * Función destructora:
 *  Objetivo:
 *      Se eliminan todas las canciones de una lista de usuarios.
 *  Entrada:
 *      songlist -> Lista con las canciones a eliminar.
 *  Salida:
 *      songlist -> Lista de canciones vacía.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void new(char *name, char *category, tListU* list);
/* new (string, string, tList) -> tList
 * Función constructora:
 *  Objetivo:
 *      Se incorporará un usuario en la posición correspondiente en lista ordenada de
 *      usuarios, con la categoría indicada, con su contador de tiempo de reproducción
 *      en minutos a 0 y con su lista de canciones inicializada pero vacía.
 *  Entrada:
 *      name -> nombre del nuevo usuario.
 *      category -> categoría del nuevo usuario.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> La lista con un nuevo usuario.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
 *  Poscondición:
 *      La orden de los elementos de la lista pueden haber variado.
*/

void delete(char *username, tListU* list);
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

void upgrade(char *user, tListU* list);
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

void add(char* userName, char* songTitle, tListU *userData);
/* add (string, string, tList) -> tList
 * Función modificadora:
 *  Objetivo:
 *      Se buscará al usuario en la lista y se le añadira una canción a su lista
 *      de canciones.
 *  Entrada:
 *      userName -> nombre usuario a buscar y a actualizar.
 *      songTitle -> nombre de la canción a añadir.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> Lista con la canción añadida al usuario correspondiente.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void play(char* userName, char* songTitle, const char* minutes, tListU *userData);
/* play (string, string, string, tList) -> tList
 * Función modificadora:
 *  Objetivo:
 *      Se buscará al usuario en la lista y se buscará la canción en su lista de
 *      reproducción. Si la canción está en la lista, se incrementarán en los minutos
 *      indicados (minutes) tanto el contador de reproducción de la propia canción
 *      (playTime) como el contador de reproducción total del usuario (totalPlayTime).
 *  Entrada:
 *      userName -> Nombre usuario para reproducir la canción.
 *      songtitle -> Nombre de la canción.
 *      minutes -> Minutos reproducidos de la canción.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> Lista con el usuario con la nueva reproducción.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void stats(tListU userData);
/* stats (tList)
 * Función observadora:
 *  Objetivo:
 *      Se mostrará por pantalla la lista completa de usuarios actuales incluyendo todas
 *      las canciones de sus correspondientes listas de reproducción, si una lista está
 *      vacía se indicará con "No songs" y  también se imprimirán estadisticas de
 *      reproducción.
 *  Entrada:
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

void removeBasic(const char* maxTime, tListU *userData);
/* removeBasic (string, tList) -> tList
 * Función destructora:
 *  Objetivo:
 *      Se eliminarán de la lista aquellos usuarios basic que hayan excedido el tiempo
 *      máximo de reproducción maxTime.
 *  Entrada:
 *      maxTime -> Tiempo máximo.
 *      list -> Lista que representa la base de datos de los usuarios.
 *  Salida:
 *      list -> Lista con lo usuarios basic que hayan excedido el maxTime eliminados.
 *  Precondición:
 *      La lista debe estár previamente inicializada.
*/

int strToCategory(const char* string) {
    if (strcmp(string, "basic") == 0) { // Si es basic, devuelve 0
        return basic;
    } // Si no es basic, es pro, devuelve 1
    return pro;
}

void categoryToStr(char* string, tUserCategory cat) {
    if (cat == basic) { // Si es 0, devuelve "basic"
        strcpy(string,"basic");
    } else { // Si ni es 0, es 1, devuelve "pro"
        strcpy(string, "pro");
    }
}

tPlayTime getUserInfo(tItemU item, char *name, char *category) {
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

void removeSongList(tListS *songList) {
    tPosS p = lastS(*songList); // Obtenemos el último elemento

    while (!isEmptyListS(*songList)) {  // Mientras la lista no esté vacía
        deleteAtPositionS(p, songList);
        p = lastS(*songList);
    } // Buscamos el último elemento y lo eliminamos
      // Menos costoso que borrar el primero
}

void new(char *name, char *category, tListU* list) {
    tItemU item; tUserCategory cat; // cat = categoría a inserter

    if (findItemU(name, *list) == NULLU) { // Si no existe ya el usuario
        // Set username
        strcpy(item.userName, name);
        // Set category
        cat = strToCategory(category);
        item.userCategory = cat;
        // Set number of plays to 0
        item.totalPlayTime = 0;
        // inicializar la lista de canciones
        createEmptyListS(&item.songList);
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
    tItemU user;
    tUserName name;
    char category[6];
    tPlayTime totalPlayT;
    tPosU pos;

    // Busca la posición del usuario en la lista
    pos = findItemU(username, *list);
    if (pos != NULLU) { // Si la posición existe
        user = getItemU(pos, *list);
        // Get print info
        totalPlayT = getUserInfo(user, name ,category);
        removeSongList(&user.songList); // Borrar la lista de canciones
        updateItemU(user, pos, list); // Actualizamos el item
        deleteAtPositionU(pos, list); // Elimina el usuario de la lista
        printf("* Delete: user %s category %s totalplaytime %d\n",
               name, category, totalPlayT);
    } else {
        // Mensaje de error si la eliminación no fue posible
        puts("+ Error: Delete not possible");
    }
}

void upgrade(char *user, tListU* list) {
    tPosU pos = findItemU(user, *list); // Busca la posición del usuario
    tItemU item;

    if (pos != NULLU) {
        // Si el usuario existe
        item = getItemU(pos, *list); // Obtiene el usuario
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
    const tPosU posU = findItemU(userName, *userData);
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

void play(char* userName, char* songTitle, const char* minutes, tListU *userData) {
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
    tPosU pos;
    tItemU item; tUserName name; char category[6]; tPlayTime nPlayT;
    int basicUsers = 0, proUsers = 0; int basicPlaysT = 0, proPlaysT = 0;
    float basicAvgT = 0, proAvgT = 0;

    if (!isEmptyListU(userData)) { // Si la lista no está vacía
        pos = firstU(userData); // Obtiene la primera posición de la lista
        while (pos != NULLU) { // Mientras la lista no estea vacía
            // Obtiene el usuario de la lista
            item = getItemU(pos, userData);
            // Obtiene la información
            nPlayT = getUserInfo(item, name, category);
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
            // Promedio de reproducciones para usuarios "básicos"
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

void removeBasic(const char* maxTime, tListU *userData) {
    const int maxPlays = atoi(maxTime); // string a int
    tItemU user;
    tPosU p, pAux;  // pAux, función de p para guardar el primer elemento o el anterior
    bool error = true; // bool para imprimir o no el error

    if (!isEmptyListU(*userData)) {
        pAux = firstU(*userData); p = pAux;
        while(p != NULLU) {
            user = getItemU(p, *userData); // obtenemos al usuario
            if (user.userCategory == basic && user.totalPlayTime > maxPlays) { // Eliminar
                printf("Removing user %s totalplaytime %d\n",
                       user.userName, user.totalPlayTime);
                removeSongList(&user.songList); // Eliminamos la lista de canciones
                updateItemU(user, p, userData); // Actualizamos el usuario
                deleteAtPositionU(p, userData); // Eliminamos al usuario
                if (p == pAux) { // Primer elemento, next es first otra vez
                    pAux = firstU(*userData);
                    p = pAux;
                } else { // En el medio, volvemos al elemento anterior
                    p = pAux;
                    p = nextU(p, *userData); // avanzamos al siguiente valor
                }
                error = false; // no imprimir el error
            } else {
                pAux = p; // Guardamos el anterior
                p = nextU(p, *userData); // avanzamos al siguiente valor
            }
        }
    }
    if (error)
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
            printf("%s %c: maxtime %s\n",
                   commandNumber, command, param1);
            removeBasic(param1, userData);
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
