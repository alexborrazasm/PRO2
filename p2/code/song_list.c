/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * GROUP: 3.4
 * DATE: 26 / 04 / 24
 */
#include "song_list.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

void createEmptyListS(tListS* L){
    // Establecemos la última posición de la lista definida como nula
    L->lastPos = NULLS;
}

bool isEmptyListS(tListS L) {
    UNUSED(L);
    // Si la última posición es NULLS, la lista está vacía
    return L.lastPos == NULLS; // true o false
}

tPosS firstS(tListS L) {
    UNUSED(L);
    // El primer elemento de una lista implementada con arrays es siempre 0
    return 0;
}

tPosS lastS(tListS L) {
    // Devolvemos el último elemento guardado en el struct tListS
    return L.lastPos;
}

tPosS nextS(tPosS p, tListS L) {
    if (p == L.lastPos) // Si p es la última posición de la lista
        return NULLS;   // Devolvemos nulo
    else                // Si la siguiente posición de p
        return p + 1;   // En arrays p + 1
}

tPosS previousS(tPosS p, tListS L) {
    UNUSED(L);
    if (p==0)           // Si p es el primer elemento
        return NULLS;   // Devolvemos nulo
    else                // Si no el elemento anterior
        return p - 1;   // En arrays p - 1
}

bool insertItemS(tItemS d, tPosS p, tListS* L) {
    tPosS q; // temp

    //  enough space?
    if (L->lastPos == MAX - 1) { // Si no tenemos suficiente espacio, no se puede insertar
        return false;            // Error en la inserción
    } else {
        L->lastPos++;            // Última posición + 1
        if (p == NULLS) {        // Lista vacía
            L->data[L->lastPos] = d;  // Insertar al final
        } else { // Si no es vacía tenemos que mover todas las posiciones siguientes
            for (q = L->lastPos; q > p; q--) {
                L->data[q] = L->data[q - 1];
            }
            L->data[q] = d;  // Insertar en la posición q (justo antes de p)
        }
        return true;  // Éxito en la inserción
    }
}

void deleteAtPositionS(tPosS p, tListS* L) {
    tPosS q;
    
    // Mover elementos hacia la izquierda, sobrescribiendo el elemento en la posición p
    for (q = p; q < L->lastPos; q++)
        L->data[q] = L->data[q+1];
    L->lastPos--;  //Disminuir el contador de elementos en la lista
}

tItemS getItemS(tPosS p, tListS L) {
    return L.data[p];  // Devuelve el elemento en la posición p de la lista L
}

void updateItemS(tItemS d, tPosS p, tListS* L) {
    L->data[p] = d; // Asigna el valor d al elemento en la posición p de la lista L
}

tPosS findItemS(tSongTitle s, tListS L) {
    tPosS  p;

    if (isEmptyListS(L)) // Si la lista está vacía, no puede contener el elemento
        return NULLS;
    else {
        // Búsqueda
        for (p = 0; p <= L.lastPos && strcmp(L.data[p].songTitle, s) != 0; p++);
        // Si encontró el elemento
        if (strcmp(L.data[p].songTitle, s) == 0)
            return p;  // Lo devuelve
        else
            return NULLS;  // Si no lo encontró, devuelve nulo
    }
}