/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * AUTHOR 2: Carlos Losada Gómez        LOGIN 2: carlos.lgomez
 * GROUP: 3.4
 * DATE: 11 / 04 / 24
 */

#ifndef SONG_LIST_H
#define SONG_LIST_H

#include <string.h>
#include "types.h"

#define NULLS (-1)  // Macro que define la posición nula
#define MAX 25      // Macro que define el tamaño máximo del array

typedef int tPosS;
typedef tSong tItemS;
typedef struct {
    tItemS data[MAX];
    tPosS lastPos;
} tListS;

void createEmptyListS(tListS* L);
/* createEmptyListS (tListS) -> tListS
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

bool isEmptyListS(tListS L);
/* isEmptyListS (tListS) -> bool
 * Función observadora:
 *  Objetivo:
 *      Determina si la lista está o no vacía.
 *  Entrada:
 *      L -> Lista a comprobar.
 *  Salida:
 *      Bool -> True (verdadero) si la lista está vacía.
 *              False (falso) en el caso contrario.
 */

tPosS firstS(tListS L);
/* firstS (tListS) -> tPosS
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del primer elemento de la lista.
 *  Entrada:
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosS -> Posición del primer elemento de la lista.
 *  Precondición:
 *      La lista no está vacía.
*/

tPosS lastS(tListS L);
/* lastS (tListS) -> tPosS
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del último elemento de la lista.
 *  Entrada:
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosS -> Posición del último elemento de la lista.
 *  Precondición:
 *      La lista no está vacía.
*/
tPosS nextS(tPosS p, tListS L);
/* nextS (tPosS, tListS) -> tPosS
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del elemento siguiente al actual.
 *  Entrada:
 *      p -> Posición del elemento actual.
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosS -> Posición del elemento siguiente o NULLS si es el último.
 *  Precondición:
 *      p es una posición válida de la lista.
*/

tPosS previousS(tPosS p, tListS L);
/* previousS (tPosS, tListS) -> tPosS
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del elemento anterior al actual.
 *  Entrada:
 *      p -> Posición del elemento actual.
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosS -> Posición del elemento anterior o NULLS si es el primero.
 *  Precondición:
 *      p es una posición válida de la lista.
*/

bool insertItemS(tItemS d, tPosS p, tListS* L);
/* insertItemS (tItemS, tPosS, tListS) -> tListS, bool
 * Función modificadora:
 *  Objetivo:
 *      Inserta un elemento en la lista antes de la posición indicada.
 *      Si la posición es NULLS, entonces se añade al final.
 *  Entrada:
 *      d -> Elemento a insertar.
 *      p -> Posición antes del cual debe ser insertado d.
 *      L -> Lista donde vamos a insertar.
 *  Salida:
 *      L -> Lista con el elemento d insertado en la posición correspondiente.
 *      bool -> True (verdadero) si el elemento fue insertado correctamente.
 *              False en el caso contrario
 *  Precondición:
 *      La lista está inicializada, la posición es válida o bien NULLS.
 *  Postcondición:
 *      Las posiciones de la lista posteriores a p pueden haber variado.
*/
void deleteAtPositionS(tPosS p, tListS* L);
/* deleteAtPositionS (tPosS, tListS) -> tListS
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

tItemS getItemS(tPosS p, tListS L);
/* getItemS (tPosS, tListS) -> tItemS
 * Función observadora:
 *  Objetivo:
 *      Recupera el contenido de un elemento de la lista.
 *  Entrada:
 *      p -> Posición del elemento buscado.
 *      L -> Lista donde buscar.
 *  Salida:
 *      tItemS -> Contenido del elemento que está en p.
 *  Precondición:
 *      p es una posición válida en la lista.
 */

void updateItemS(tItemS d, tPosS p, tListS* L);
/* updateItemS (tItemS, tPosS, tListS) -> tListS
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

tPosS findItemS(tSongTitle s, tListS L);
/* findItemS (tUserName, tListS) -> tPosS
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del primer elemento de la lista cuyo nombre de usuario se
 *      corresponda con el indicado (o NULLS si no existe tal elemento).
 *  Entrada:
 *      d -> Nombre de usuario a buscar.
 *      L -> Lista donde buscar.
 *  Salida:
 *      tPosS -> Posición del elemento encontrado o NULLS si no se encuentra.
 */

#endif
