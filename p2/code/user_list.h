/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * GROUP: 3.4
 * DATE: 26 / 04 / 24
 */

#ifndef USER_LIST_H
#define USER_LIST_H

#include<stdlib.h>
#include "types.h"
#include "song_list.h"

#define NULLU NULL

typedef struct tNodeU *tPosU;

typedef struct tItemU {
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
} tItemU;

struct tNodeU {
    tItemU data;
    tPosU next;
};

typedef tPosU tListU;

void createEmptyListU(tListU* L);
/* createEmptyListU (tListU) -> tListU
 * Función constructora:
 *  Objetivo:
 *      Crea una lista vacía.
 *  Entrada:
 *      L -> Puntero a la lista a inicializar.
 *  Salida:
 *      L -> una lista vacía.
 *  Poscondición:
 *      La lista apuntada por L queda inicializada como vacía.
*/

bool isEmptyListU(tListU L);
/* isEmptyListU (tListU) -> bool
 * Función observadora:
 *  Objetivo:
 *      Determina si la lista está vacía o no.
 *  Entrada:
 *      L -> Lista a verificar.
 *  Salida:
 *      bool -> Verdadero si la lista está vacía, falso en caso contrario.
*/

tPosU firstU(tListU L);
/* firstU (tListU) -> tPosU
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del primer elemento de la lista.
 *  Entrada:
 *      L -> Lista.
 *  Salida:
 *      tPosU -> Posición del primer elemento de la lista.
 *  Precondición:
 *      La lista no está vacía.
*/

tPosU lastU(tListU L);
/* lastU (tListU) -> tPosU
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del último elemento de la lista.
 *  Entrada:
 *      L -> Lista a manipular.
 *  Salida:
 *      tPosU -> Posición del último elemento de la lista.
 *  Precondición:
 *      La lista no está vacía.
*/

tPosU nextU(tPosU p, tListU L);
/* nextU (tPosU, tListU) -> tPosU
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del elemento siguiente al actual.
 *  Entrada:
 *      p -> Posición actual en la lista.
 *      L -> Lista.
 *  Salida:
 *      tPosU -> Posición del elemento siguiente o NULLU si es el último.
 *  Precondición:
 *      La posición p pertenece a la lista L.
*/

tPosU previousU(tPosU p, tListU L);
/* previousU (tPosU, tListU) -> tPosU
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del elemento anterior al indicado.
 *  Entrada:
 *      p -> Posición actual en la lista.
 *      L -> Lista.
 *  Salida:
 *      tPosU -> Posición del elemento anterior al indicado.
 *  Precondición:
 *      La posición p pertenece a la lista L.
*/

bool insertItemU(tItemU d, tListU* L);
/* insertItemU (tItemU, tListU) -> tListU, bool
 * Función modificadora:
 *  Objetivo:
 *      Inserta un elemento en la lista de forma ordenada en función del campo
 *      userName.
 *      Si la posición es NULLU, entonces se añade al final.
 *  Entrada:
 *      d -> Elemento a insertar.
 *      L -> Puntero a la lista donde se realizará la inserción.
 *  Salida:
 *      L -> Lista con el elemento d insertado en la posición correspondiente.
 *      bool -> Verdadero si la inserción fue exitosa, falso en caso contrario.
 *  Precondición:
 *      La lista debe estar inicializada.
 *  Poscondición:
 *      Las posiciones de los elementos de la lista posteriores al insertado
 *      pueden cambiar de valor.
*/

void deleteAtPositionU(tPosU p, tListU* L);
/* deleteAtPositionU (tPosU, tListU) -> tListU
 * Función modificadora:
 *  Objetivo:
 *      Elimina un usuario en la posición indicada de la lista.
 *  Entrada:
 *      p -> Posición del elemento a eliminar.
 *      L -> Puntero a la lista donde se realizará la eliminación.
 *  Salida:
 *      L -> Lista sin el elemento correspondiente a p.
 *  Precondición:
 *      La posición p pertenece a la lista L y la lista de canciones está vacía.
 *  Poscondición:
 *      Las posiciones de los elementos de la lista posteriores a p pueden haber
 *      variado.
*/

tItemU getItemU(tPosU p, tListU L);
/* getItemU (tPosU, tListU) -> tItemU
 * Función observadora:
 *  Objetivo:
 *      Devuelve el elemento en la posición indicada de la lista.
 *  Entrada:
 *      p -> Posición del elemento a obtener.
 *      L -> Lista a manipular.
 *  Salida:
 *      tItemU -> Elemento en la posición indicada de la lista.
 *  Precondición:
 *      La posición p pertenece a la lista L.
*/

void updateItemU(tItemU d, tPosU p, tListU* L);
/* updateItemU (tItemU, tPosU, tListU) -> tListU
 * Función modificadora:
 *  Objetivo:
 *      Actualiza el elemento en la posición indicada de la lista.
 *  Entrada:
 *      d -> Nuevo valor del elemento.
 *      p -> Posición del elemento a actualizar.
 *      L -> Puntero a la lista donde se realizará la actualización.
 *  Salida:
 *      L -> Lista con el contenido del elemento modificado.
 *  Precondición:
 *      La posición p pertenece a la lista L.
 *  Poscondición:
 *      El elemento en la posición p de la lista L es actualizado con el valor
 *      d.
*/

tPosU findItemU(tUserName d, tListU L);
/* findItemU (tUserName, tListU) -> tPosU
 * Función observadora:
 *  Objetivo:
 *      Devuelve la posición del primer elemento de la lista cuyo nombre de
 *      usuario se corresponda con el indicado (o NULLU si no existe tal
 *      elemento).
 *  Entrada:
 *      d -> Nombre de usuario a buscar.
 *      L -> Lista.
 *  Salida:
 *      tPosU -> Posición del elemento con el nombre de usuario indicado.
*/

#endif
