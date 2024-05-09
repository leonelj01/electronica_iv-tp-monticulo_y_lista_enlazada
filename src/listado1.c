#include <string.h> // strcmp
#include <stdlib.h> // atoi
#include "serie.h"
#include "monticulo.h"
#include "cadenas.h"

void listado1(void)
{
    enum{CAPACIDAD=16,LBUFFER=20};
    static int datos[CAPACIDAD];
    Monticulo m[1];
    char buffer[LBUFFER];
    TipoMonticulo tipo = Monticulo_NUM_TIPOS;
    int continuar = 1;

    while(tipo == Monticulo_NUM_TIPOS){
        Serie_enviaCadena(cadena[L1_INGRESA_TIPO]);
        Serie_recibePalabra(buffer,LBUFFER);
        if (!strcmp(cadena[L1_TIPO_MAX],buffer)){
            tipo = Monticulo_MAXIMO;
        }else if(!strcmp(cadena[L1_TIPO_MIN],buffer)){
            tipo = Monticulo_MINIMO;
        }
    }
    Monticulo_inicializa(m,datos,CAPACIDAD,tipo);
    Serie_enviaCadena(cadena[L1_INSTRUCCIONES]);
    int valor;
    while(continuar){
        Serie_recibePalabra(buffer,LBUFFER);
        if(!strcmp(cadena[L1_INTRODUCE],buffer)){
            Serie_recibePalabra(buffer,LBUFFER);
            valor = atoi(buffer);
            if (!Monticulo_introduce(m,valor)){
                Serie_enviaCadena(cadena[L1_MSG_INGRESADO]);
                Serie_enviaEntero(valor);
            }else{
                Serie_enviaCadena(cadena[L1_MSG_LLENO]);
            }
        }else if(!strcmp(cadena[L1_LEE_TOPE],buffer)){
            if(!Monticulo_leeTope(m,&valor)){
                Serie_enviaCadena(cadena[L1_MSG_TOPE_LEIDO]);
                Serie_enviaEntero(valor);
            }else{
                Serie_enviaCadena(cadena[L1_MSG_VACIO]);
            }
        }else if(!strcmp(cadena[L1_TOMA_TOPE],buffer)){
            if(!Monticulo_tomaTope(m,&valor)){
                Serie_enviaCadena(cadena[L1_MSG_TOPE_TOMADO]);
                Serie_enviaEntero(valor);
            }else{
                Serie_enviaCadena(cadena[L1_MSG_VACIO]);
            }
        }else if(!strcmp(cadena[L1_SALIR],buffer)){
            Serie_enviaCadena(cadena[L1_MSG_SALIENDO]);
            continuar = 0;
        }else{
            Serie_enviaCadena(cadena[L1_MSG_NO_RECONOCIDO_INI]);
            Serie_enviaCadena(buffer);
            Serie_enviaCadena(cadena[L1_MSG_NO_RECONOCIDO_FIN]);
            Serie_enviaCadena(cadena[L1_INSTRUCCIONES]);
        }
        Serie_enviaNuevaLinea();
    }
}