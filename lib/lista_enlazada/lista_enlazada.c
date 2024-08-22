#include "lista_enlazada.h"
#include <stddef.h>
#include <stdbool.h>

void NodoListaEnlazada_inicializa(NodoListaEnlazada *nodo, int valor)
{
    nodo->dato = valor;
    nodo->enlace = NULL;
}

void ListaEnlazada_inicializa(ListaEnlazada *lista)
{
    *lista = NULL;
}

void ListaEnlazada_inserta(ListaEnlazada *lista, NodoListaEnlazada *nodo)
{
    nodo->enlace = *lista;
    *lista = nodo;
}

NodoListaEnlazada *ListaEnlazada_obtNodoCabeza(ListaEnlazada *lista)
{
    return *lista;
}

bool ListaEnlazada_esVacia(ListaEnlazada *lista)
{
    return *lista == NULL;
}

int ListaEnlazada_obtCabeza(ListaEnlazada *lista, int *valor)
{
    if (*lista == NULL) {
        return -1;
    }
    *valor = (*lista)->dato;
    return 0;
}

ListaEnlazada *ListaEnlazada_obtCola(ListaEnlazada *lista)
{
    if (*lista == NULL) {
        return lista;
    }
    return &((*lista)->enlace);
}

NodoListaEnlazada *ListaEnlazada_remueveCabeza(ListaEnlazada *lista)
{
    if (*lista == NULL) {
        return NULL;
    }
    NodoListaEnlazada *nodoRemovido = *lista;
    *lista = (*lista)->enlace;
    return nodoRemovido;
}