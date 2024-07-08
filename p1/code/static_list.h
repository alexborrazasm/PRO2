/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alexandre Borrazás Mancebo   LOGIN 1: alexandre.bmancebo
 * AUTHOR 2: Carlos Losada Gómez          LOGIN 2: carlos.lgomez
 * GROUP: 3.4
 * DATE: 16 / 03 / 2024
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

#define LNULL (-1)  // Macro que define la posición nula
#define MAX 25      // Macro que define el tamaño máximo del array

typedef int tPosL;
typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

void createEmptyList(tList* L);
/* createEmptyList (tList) -> tList
 * Función generadora:
 *  Objetivo:
 *      Crea una lista vacía y la inicializa.
 *  Entrada:
 *      L -> Puntero a la lista a inicializar.
 *  Salida:
 *      L -> una lista vacía.
 *  Postcondición:
 *      La lista sin datos.
 */

bool isEmptyList(tList L);
/* isEmptyList (tList) -> bool
 * Función observadora:
 *  Objetivo:
 *      Determina si la lista está o no vacía.
 *  Entrada:
 *      L -> Lista a comprobar.
 *  Salida:
 *      Bool -> True (verdadero) si la lista está vacía.
 *              False (falso) en el caso contrario.
 */

tPosL first(tList L);
/* first (tList) -> tPosL
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del primer elemento de la lista.
 *  Entrada:
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosL -> Posición del primer elemento de la lista.
 *  Precondición:
 *      La lista no está vacía.
*/

tPosL last(tList L);
/* last (tList) -> tPosL
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del último elemento de la lista.
 *  Entrada:
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosL -> Posición del último elemento de la lista.
 *  Precondición:
 *      La lista no está vacía.
*/
tPosL next(tPosL p, tList L);
/* next (tPosL, tList) -> tPosL
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del elemento siguiente al actual.
 *  Entrada:
 *      p -> Posición del elemento actual.
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosL -> Posición del elemento siguiente o LNULL si es el último.
 *  Precondición:
 *      p es una posición válida de la lista.
*/

tPosL previous(tPosL p, tList L);
/* previous (tPosL, tList) -> tPosL
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del elemento anterior al actual.
 *  Entrada:
 *      p -> Posición del elemento actual.
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosL -> Posición del elemento anterior o LNULL si es el primero.
 *  Precondición:
 *      p es una posición válida de la lista.
*/

bool insertItem(tItemL d, tPosL p, tList* L);
/* insertItem (tItemL, tPosL, tList) -> tList, bool
 * Función modificadora:
 *  Objetivo:
 *      Inserta un elemento en la lista antes de la posición indicada.
 *      Si la posición es LNULL, entonces se añade al final.
 *  Entrada:
 *      d -> Elemento a insertar.
 *      p -> Posición antes del cual debe ser insertado d.
 *      L -> Lista donde vamos a insertar.
 *  Salida:
 *      L -> Lista con el elemento d insertado en la posición correspondiente.
 *      bool -> True (verdadero) si el elemento fue insertado correctamente.
 *              False en el caso contrario
 *  Precondición:
 *      La lista está inicializada, la posición es válida o bien LNULL.
 *  Postcondición:
 *      Las posiciones de la lista posteriores a p pueden haber variado.
*/
void deleteAtPosition(tPosL p, tList* L);
/* deleteAtPosition (tPosL, tList) -> tList
 * Función destructora:
 *  Objetivo:
 *      Elimina de la lista el elemento que ocupa la posición indicada.
 *  Entrada:
 *      p -> Posición del elemento a eliminar.
 *      L -> Lista a modificar.
 *  Salida:
 *      L -> Lista sin el elemento correspondiente a p.
 *  Precondición:
 *      p es una posición válida en la lista.
 *  Postcondición:
 *      Las posiciones de los elementos de la lista posteriores a p pueden haber variado.
 */

tItemL getItem(tPosL p, tList L);
/* getItem (tPosL, tList) -> tItemL
 * Función observadora:
 *  Objetivo:
 *      Recupera el contenido de un elemento de la lista.
 *  Entrada:
 *      p -> Posición del elemento buscado.
 *      L -> Lista donde buscar.
 *  Salida:
 *      tItemL -> Contenido del elemento que está en p.
 *  Precondición:
 *      p es una posición válida en la lista.
 */

void updateItem(tItemL d, tPosL p, tList* L);
/* updateItem (tItemL, tPosL, tList) -> tList
 * Función modificadora:
 *  Objetivo:
 *      Modifica el contenido de un elemento de la lista en la posición p
 *  Entrada:
 *      d -> Nuevo item a asignar en el elemento p.
 *      p -> Posición del elemento a modificar.
 *      L -> Lista a modificar.
 *  Salida:
 *      L -> Lista con el contenido del elemento modificado.
 *  Precondición:
 *      p es una posición válida en la lista.
 */

tPosL findItem(tUserName d, tList L);
/* findItem (tUserName, tList) -> tPosL
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del primer elemento de la lista cuyo nombre de usuario se
 *      corresponda con el indicado (o LNULL si no existe tal elemento).
 *  Entrada:
 *      d -> Nombre de usuario a buscar.
 *      L -> Lista donde buscar.
 *  Salida:
 *      tPosL -> Posición del elemento encontrado o LNULL si no se encuentra.
 */

#endif
