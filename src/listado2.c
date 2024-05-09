#include <string.h> // strcmp
#include <stdlib.h> // atoi
#include "serie.h"
#include "cadenas.h"
#include "lista_enlazada.h"

void listado2(void)
{
    enum{NUM_NODOS=16,LBUFFER=20};
    static NodoListaEnlazada nodos[NUM_NODOS];
    static ListaEnlazada nodosLibres[1];
    static ListaEnlazada lista[1];
    static char buffer[LBUFFER];
    int continuar=1;
    int valor;
    ListaEnlazada *cursor = lista;
    NodoListaEnlazada *nodo;

    ListaEnlazada_inicializa(nodosLibres);
    ListaEnlazada_inicializa(lista);
    for(int i=0;i<NUM_NODOS;++i){
        NodoListaEnlazada_inicializa(nodos+i,0);
        ListaEnlazada_inserta(nodosLibres,nodos+i);
    }
    Serie_enviaCadena(cadena[L2_INSTRUCCIONES]);
    while(continuar){
        if(lista == cursor){
            Serie_enviaCadena(cadena[L2_PROMPT_LISTA]);
        }else{
            Serie_enviaCadena(cadena[L2_PROMPT_COLA]);
        }
        Serie_recibePalabra(buffer,LBUFFER);
        if(!strcmp(cadena[L2_ES_VACIA],buffer)){
            if(ListaEnlazada_esVacia(cursor)){
                Serie_enviaCadena(cadena[L2_MSG_TRUE]);
            }else{
                Serie_enviaCadena(cadena[L2_MSG_FALSE]);
            }
        }else if(!strcmp(cadena[L2_CABEZA],buffer)){
            if(!ListaEnlazada_obtCabeza(cursor,&valor)){
                Serie_enviaCadena(cadena[L2_MSG_CABEZA]);
                Serie_enviaEntero(valor);
            }else{
                Serie_enviaCadena(cadena[L2_MSG_VACIA]);
            }
        }else if(!strcmp(cadena[L2_COLA],buffer)){
            cursor = ListaEnlazada_obtCola(cursor);
            Serie_enviaCadena(cadena[L2_MSG_CURSOR_A_COLA]);           
        }else if(!strcmp(cadena[L2_LISTA],buffer)){
            cursor = lista;
            Serie_enviaCadena(cadena[L2_MSG_CURSOR_A_LISTA]);
        }else if(!strcmp(cadena[L2_REMUEVE],buffer)){
            if(!ListaEnlazada_obtCabeza(cursor,&valor)){
                nodo = ListaEnlazada_remueveCabeza(cursor);
                ListaEnlazada_inserta(nodosLibres,nodo);
                Serie_enviaCadena(cadena[L2_MSG_REMOVIDO]);
                Serie_enviaEntero(valor);
            }else{
                Serie_enviaCadena(cadena[L2_MSG_VACIA]);
            }
        }else if(!strcmp(cadena[L2_INTRODUCE],buffer)){
            Serie_recibePalabra(buffer,LBUFFER);
            valor = atoi(buffer);
            nodo = ListaEnlazada_remueveCabeza(nodosLibres);
            if(nodo){
                NodoListaEnlazada_inicializa(nodo,valor);
                ListaEnlazada_inserta(cursor,nodo);
                Serie_enviaCadena(cadena[L2_MSG_NODO_INSERTO]);
                Serie_enviaEntero(valor);
            }else{
                Serie_enviaCadena(cadena[L2_MSG_SIN_NODOS]);
            }
        }else if(!strcmp(cadena[L2_MUESTRA_LISTA],buffer)){
            Serie_enviaCadena(cadena[L2_MSG_INICIO_LISTA]);
            for(ListaEnlazada *p = cursor;
                    !ListaEnlazada_obtCabeza(p,&valor);
                    p = ListaEnlazada_obtCola(p)){
                Serie_enviaEntero(valor);
                Serie_enviaCadena(cadena[L2_MSG_SEPARADOR_LISTA]);
            }
            Serie_enviaCadena(cadena[L2_MSG_FIN_LISTA]);

        }else if(!strcmp(cadena[L2_SALIR],buffer)){
            Serie_enviaCadena(cadena[L2_MSG_SALIENDO]);
            continuar=0;
        }else{
            Serie_enviaCadena(cadena[L2_MSG_COMANDO_NO_RECONOCIDO]);
            Serie_enviaCadena(cadena[L2_INSTRUCCIONES]);
        }
        Serie_enviaNuevaLinea();
    }
}