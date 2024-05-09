#include "lista_enlazada.h"
#include <stddef.h>
#include <stdbool.h>

void NodoListaEnlazada_inicializa(NodoListaEnlazada *nodo,int valor)
{
    (void)nodo,(void)valor;
}
void ListaEnlazada_inicializa(ListaEnlazada *lista)
{
    (void)lista;
}
void ListaEnlazada_inserta(ListaEnlazada *lista, NodoListaEnlazada *nodo)
{
    (void)lista,(void)nodo;
}
NodoListaEnlazada *ListaEnlazada_obtNodoCabeza(ListaEnlazada *lista)
{
    (void)lista;
    return NULL;
}
bool ListaEnlazada_esVacia(ListaEnlazada *lista)
{
    (void)lista;
    return true;
}
int ListaEnlazada_obtCabeza(ListaEnlazada *lista, int *valor)
{
    (void)lista,(void)valor;
    return -1;
}
ListaEnlazada *ListaEnlazada_obtCola(ListaEnlazada *lista)
{
    return lista;
}
NodoListaEnlazada *ListaEnlazada_remueveCabeza(ListaEnlazada *lista)
{
    (void)lista;
    return NULL;
}
