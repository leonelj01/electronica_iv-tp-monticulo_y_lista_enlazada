#include "monticulo.h"
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

/**
 * @brief Inicializa una montículo con numCeldas celdas de capacidad
 * 
 * @param m 
 * @param celdas 
 * @param numCeldas 
 */
void Monticulo_inicializa(Monticulo *m,int *celdas,int numCeldas,TipoMonticulo tipo)
{
    if (tipo == Monticulo_MAXIMO)
    {
        m->v[*celdas] = 0;
        m->maxNodos = numCeldas;
        m->n = *celdas;
    }else{
        m->v[*celdas] = NULL;
        m->maxNodos = numCeldas;
        m->n = *celdas;
    }
    

    (void)m,(void)celdas,(void)numCeldas,(void)tipo;
}
/**
 * @brief Introduce un valor en el montículo
 * 
 * @param m 
 * @param valor 
 * @return int 0 Valor introducido, -1 montículo lleno
 */
int Monticulo_introduce(Monticulo *m,int valor)
{
    (void)m,(void)valor;
    return -1;
}

/**
 * @brief Lee el valor al tope del montículo, no modifica el montículo
 * 
 * @param m 
 * @param destino 
 * @return int 0 Valor leido, -1 montículo vacío
 */
int Monticulo_leeTope(const Monticulo *m,int *destino)
{
    (void)m,(void)destino;
    return -1;
}

/**
 * @brief Toma el valor al tope del montículo, el valor es removido del
 * montículo
 * 
 * @param m 
 * @param destino 
 * @return int 0 Valor tomado, -1 montículo 
 */
int Monticulo_tomaTope(Monticulo *m,int *destino)
{
    (void)m,(void)destino;
    return -1;
}
