#include <stdlib.h>
#include "main.h"
#include "serie.h"
#include "timer_sistema.h"
#include "cadenas.h"

int main(void)
{
    enum{LBUFFER=5};
    static char buffer[LBUFFER];
    TS_init();
    Serie_init(9600);
    #ifdef ESPERA_PRUEBAS
    TS_espera(ESPERA_PRUEBAS);
    #endif
    for(;;){
        Serie_enviaCadena(cadena[MAIN_CONSIGNA]);
        Serie_recibePalabra(buffer,LBUFFER);
        int num = atoi(buffer); 
        switch(num)
        {
        case 1:
            listado1();
        break;case 2:
            listado2();
        break;default:
            Serie_enviaCadena(cadena[MAIN_LISTADO_NO_ENCONTRADO]);
            Serie_enviaEntero(num);
        }
        Serie_enviaNuevaLinea();
    }
    return 0;
}