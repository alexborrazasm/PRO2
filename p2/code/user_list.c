/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo
 * GROUP: 3.4
 * DATE: 26 / 04 / 24
 */

#include "user_list.h"
#include "song_list.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

tPosU findPosition (tListU L, tItemU d);
/* createNodeU (tListU L, tItemU d) -> tPosU
 * Función observadora:
 *  Objetivo:
 *      Busca la posición del un item de una lisa ordenada por el nombre de
 *      usuario.
 *  Entrada:
 *      L -> Lista en la cual buscar.
 *      d -> item del que queremos saber su posición.
 *  Salida:
 *      tPosL -> posición encontrada.
 *  Precondición:
 *      La lista no está vacía.
*/

bool createNodeU(tPosU* p);
/* createNodeU (tPosU) -> tPosU, bool
 * Función constructora:
 *  Objetivo:
 *      Crear un nuevo nodo en una lista enlazada dinámica, asignando memoria
 *      para él.
 *  Entrada:
 *      p -> Puntero al nodo a crear.
 *  Salida:
 *      p -> Puntero al nodo creado.
 *      bool -> Verdadero si la creación del nodo fue exitosa, falso en caso
 *      contrario.
*/

void createEmptyListU(tListU* L) {
    *L=NULLU; // Inicializa la lista como vacía
}

bool isEmptyListU(tListU L) {
    return L == NULLU; // Devuelve L, siempre apunta al primer elemento de la lista
}

tPosU firstU(tListU L) {
    return L; // Devuelve la primera posición de la lista
}

tPosU lastU(tListU L) {
    tPosU q;

    // Itera hasta encontrar el último elemento de la lista
    for (q = L; q->next != NULLU; q = q->next);
    return q; // Devuelve la última posición de la lista
}

tPosU previousU(tPosU p, tListU L) {
    tPosU q;

    if (p==L) return NULLU;  // Si p es el primer elemento, devuelve NULLU
    else {
        for(q=L; q->next!=p; q=q->next); // Itera hasta encontrar el elemento
        return q;                        // anterior a p
    }
}

tPosU nextU(tPosU p, tListU L) {
    UNUSED(L);
    return p->next; // Devuelve NULLU si es el último, y si no el siguiente
}

tPosU findPosition (tListU L, tItemU d) {
    tPosU p;

    p = L; // p apunta al primer elemento de la lista
    while ((p->next != NULLU) && (strcmp(p->next->data.userName, d.userName) < 0))
        p = p->next;

    return p;
}

bool insertItemU(tItemU d, tListU* L) {
    tPosU q, p;

    // Comprobar la dirección de memoria
    if (!createNodeU(&q)) { // Crea un nuevo nodo para almacenar el elemento
        return false;       // En el caso de no poder crearlo, devuelve falso
    }else {
        q->data = d;       // Asigna el valor del elemento al nuevo nodo
        q->next = NULLU;   // Establece el siguiente nodo como LNULL, valor por defecto
        if (*L == NULLU) { // Lista vacía
            *L = q;        // el nuevo nodo se convierte en el primero
            // Casos en el que la lista ya tiene elementos
        } else if (strcmp(d.userName, (*L)->data.userName) < 0) {
            // El elemento es menor que todos los de la lista
            q->next = *L;
            *L = q;
        } else{
            // Buscamos su posición
            p = findPosition(*L, d);
            q->next = p->next;
            p->next = q;
        }
        return true; // La inserción fue exitosa
    }
}

void deleteAtPositionU(tPosU p, tListU* L) {
    tPosU r, q;

    if (p == *L) { // p es el primer elemento
        *L = p->next; // Lo elimina
    } else if (p->next == NULLU) { // p está al final
        r = previousU(p, *L); // Obtiene el elemento anterior a p
        r->next = NULLU; // Elimina el último elemento
    } else { // p posición intermedia
        q = p->next;
        p->next = q->next;
        p->data = q->data;
        p = q;
    }
    free(p); // Libera la memoria del nodo eliminado
}

tItemU getItemU(tPosU p, tListU L) {
    UNUSED(L);
    return(p->data); // Devuelve el dato almacenado en la posición p
}

void updateItemU(tItemU d, tPosU p, tListU* L) {
    UNUSED(L);
    p->data=d; // Actualiza el dato almacenado en la posición p
}

tPosU findItemU (tUserName d, tListU L) {
    tPosU p;

    for (p = L; (p != NULLU) && strcmp(p->data.userName, d) < 0; p = p->next);
    // Si la lista está vacía o si p = NULLU
    if ((p != NULLU) && (strcmp(p->data.userName, d) == 0)) {
        return p; // Si lo encuentra lo devuelve
    }
    return NULLU; // Si no lo encuntra
}

bool createNodeU(tPosU *p){
    // Crear variable dinámica con el tamaño del struct tNodeU, inicializa el puntero
    *p = malloc(sizeof( struct tNodeU));
    if (*p == NULLU) return false;  // Si no se puede asignar memoria, devuelve false
    else return true;             // true si el nodo se crea correctamente
}

