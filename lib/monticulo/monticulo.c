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
void Monticulo_inicializa(
        Monticulo *m,int *celdas,int numCeldas,TipoMonticulo tipo)
{
    m->celdas = celdas;           // Puntero al array de celdas
    m->capacidad = numCeldas;     // Establece la capacidad del montículo
    m->tamano = 0;                // Inicialmente está vacío
    m->tipo = tipo;               // Establece el tipo de montículo (máximo o mínimo)
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
    if (m->tamano >= m->capacidad) {
        return -1; // Montículo lleno
    }
    
    // Insertar el nuevo valor al final del montículo
    int i = m->tamano;
    m->celdas[i] = valor;
    m->tamano++;
    
    // Reordenar el montículo para mantener la propiedad del heap
    int padre = (i - 1) / 2;
    while (i > 0 && 
        ((m->tipo == Monticulo_MAXIMO && m->celdas[i] > m->celdas[padre]) ||
        (m->tipo == Monticulo_MINIMO && m->celdas[i] < m->celdas[padre]))) {
        // Intercambiar el valor actual con su padre
        int temp = m->celdas[i];
        m->celdas[i] = m->celdas[padre];
        m->celdas[padre] = temp;
        
        // Mover el índice al padre
        i = padre;
        padre = (i - 1) / 2;
    }
    
    return 0; // Valor introducido correctamente
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
    if (m->tamano == 0) {
        return -1; // Montículo vacío
    }
    *destino = m->celdas[0];
    return 0; // Valor leído
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
    if (m->tamano == 0) {
        return -1; // Montículo vacío
    }
    
    // Obtener el valor en la cima
    *destino = m->celdas[0];
    
    // Reemplazar el valor en la cima con el último valor
    m->tamano--;
    m->celdas[0] = m->celdas[m->tamano];
    
    // Reordenar el montículo para mantener la propiedad del heap
    int i = 0;
    int izquierda = 1;
    int derecha = 2;
    
    while (izquierda < m->tamano) {
        int mayor = i;
        
        // Comparar con el hijo izquierdo
        if ((m->tipo == Monticulo_MAXIMO && m->celdas[izquierda] > m->celdas[mayor]) ||
            (m->tipo == Monticulo_MINIMO && m->celdas[izquierda] < m->celdas[mayor])) {
            mayor = izquierda;
        }
        
        // Comparar con el hijo derecho
        if (derecha < m->tamano &&
            ((m->tipo == Monticulo_MAXIMO && m->celdas[derecha] > m->celdas[mayor]) ||
            (m->tipo == Monticulo_MINIMO && m->celdas[derecha] < m->celdas[mayor]))) {
            mayor = derecha;
        }
        
        if (mayor != i) {
            // Intercambiar el valor actual con el mayor hijo
            int temp = m->celdas[i];
            m->celdas[i] = m->celdas[mayor];
            m->celdas[mayor] = temp;
            
            // Mover el índice al hijo
            i = mayor;
            izquierda = 2 * i + 1;
            derecha = 2 * i + 2;
        } else {
            break; // El montículo ya está ordenado
        }
    }
    
    return 0; // Valor tomado correctamente
}