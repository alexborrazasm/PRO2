/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alexandre Borrazás Mancebo   LOGIN 1: alexandre.bmancebo
 * AUTHOR 2: Carlos Losada Gómez          LOGIN 2: carlos.lgomez
 * GROUP: 3.4
 * DATE: 16 / 03 / 2024
 */

#include "static_list.h"
#include <string.h>

#define UNUSED(expr) do { (void)(expr); } while (0)

void createEmptyList (tList* L){
    // Establecemos la última posición de la lista definida como nula
    L->lastPos = LNULL;
}

bool isEmptyList(tList L) {
    UNUSED(L);
    // Si la última posición es LNULL, la lista está vacía
    return L.lastPos == LNULL; // true o false
}

tPosL first(tList L) {
    UNUSED(L);
    // El primer elemento de una lista implementada con arrays es siempre 0
    return 0;
}

tPosL last(tList L) {
    // Devolvemos el último elemento guardado en el struct tList
    return L.lastPos;
}

tPosL next(tPosL p, tList L) {
    if (p == L.lastPos) // Si p es la última posición de la lista
        return LNULL;   // Devolvemos nulo
    else                // Si la siguiente posición de p
        return p + 1;   // En arrays p + 1
}

tPosL previous(tPosL p, tList L) {
    UNUSED(L);
    if (p==0)           // Si p es el primer elemento
        return LNULL;   // Devolvemos nulo
    else                // Si no el elemento anterior
        return p - 1;   // En arrays p - 1
}

bool insertItem(tItemL d, tPosL p, tList* L) {
    tPosL q; // temp

    //  enough space?
    if (L->lastPos == MAX - 1) { // Si no tenemos suficiente espacio, no se puede insertar
        return false;            // Error en la inserción
    } else {
        L->lastPos++;            // Última posición + 1
        if (p == LNULL) {        // Lista vacía
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

void deleteAtPosition(tPosL p, tList* L) {
    tPosL q;
    // Mover elementos hacia la izquierda, sobrescribiendo el elemento en la posición p
    for (q = p; q < L->lastPos; q++)
        L->data[q] = L->data[q+1];
    L->lastPos--;  //Disminuir el contador de elementos en la lista
}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];  // Devuelve el elemento en la posición p de la lista L
}

void updateItem(tItemL d, tPosL p, tList* L) {
    L->data[p] = d;   // Asigna el valor d al elemento en la posición p de la lista L
}

tPosL findItem(tUserName d, tList L) {
    tPosL  p;

    if (isEmptyList(L)) // Si la lista está vacía, no puede contener el elemento
        return LNULL;
    else {
        // Búsqueda
        for (p = 0; p <= L.lastPos && strcmp(L.data[p].userName, d) != 0; p++);
        // Si encontró el elemento
        if (strcmp(L.data[p].userName, d) == 0)
            return p;  // Lo devuelve
        else
            return  LNULL;  // Si no lo encontró, devuelve nulo
    }
}
