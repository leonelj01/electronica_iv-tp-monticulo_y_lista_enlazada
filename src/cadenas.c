#include "cadenas.h"

const char *const cadena[NUM_CADENAS] = {
    [L1_TIPO_MAX] = "max",
    [L1_TIPO_MIN] = "min",
    [L1_INTRODUCE] = "introduce",
    [L1_LEE_TOPE] = "leeTope",
    [L1_TOMA_TOPE] = "tomaTope",
    [L1_SALIR] = "salir",
    [L1_INGRESA_TIPO] = "Ingresa \"max\" para monticulo de maximo y \"min\" "
                        "para monticulo de minimo (sin las comillas)\r\n",
    [L1_INSTRUCCIONES]= "Comandos:\r\n"
                        "\t\"introduce\", espacio y un numero entero para "
                        "insertar un nuevo numero.\r\n"
                        "\t\"leeTope\" para ver el valor en el tope del monticulo\r\n"
                        "\t\"tomaTope\" para remover el valor en el tope del "
                        "monticulo (tambien lo muestra)\r\n"
                        "\t\"salir\" para terminar.\r\n",
    [L1_MSG_INGRESADO]="Valor ingresado: ",
    [L1_MSG_TOPE_LEIDO]="Valor actualmente en el tope: ",
    [L1_MSG_TOPE_TOMADO]="Se tomo el valor en el tope, valor: ",
    [L1_MSG_LLENO]="Monticulo lleno",
    [L1_MSG_VACIO]="Monticulo vacio",
    [L1_MSG_SALIENDO] = "Saliendo...",
    [L1_MSG_NO_RECONOCIDO_INI] = "Comando no reconocido: \"",
    [L1_MSG_NO_RECONOCIDO_FIN] = "\"\r\n",
    [MAIN_CONSIGNA] = "Ingresa el numero de listado a ejecutar\r\n",
    [MAIN_LISTADO_NO_ENCONTRADO] = "No se ha encontrado el listado ",
    [L2_INSTRUCCIONES] = "Comandos:\r\n"
                         "\t\"introduce\", espacio y un numero entero para "
                         "insertar un nuevo nodo a la cabeza de la lista.\r\n"
                         "\t\"esVacia\" para determinar si la lista esta vacia\r\n"
                         "\t\"cabeza\" para leer el valor a la cabeza\r\n"
                         "\t\"cola\" para trabajar en la cola de la lista\r\n"
                         "\t\"lista\" para regresar a la lista original\r\n"
                         "\t\"remueve\" para remover nodo a la cabeza\r\n"
                         "\t\"muestraLista\" muestra todos los valores de la lista actual\r\n"
                         "\t\"salir\" para terminar\r\n",
    [L2_INTRODUCE]="introduce",
    [L2_ES_VACIA]="esVacia",
    [L2_CABEZA]="cabeza",
    [L2_COLA]="cola",
    [L2_LISTA]="lista",
    [L2_REMUEVE]="remueve",
    [L2_SALIR]="salir",
    [L2_MSG_TRUE]="true",
    [L2_MSG_FALSE]="false",
    [L2_MSG_CABEZA]="Valor a la cabeza: ",
    [L2_MSG_VACIA]="Lista vacia",
    [L2_MSG_REMOVIDO]="Valor del nodo removido: ",
    [L2_MSG_SIN_NODOS]="No se pudo crear un nuevo nodo",
    [L2_MSG_CURSOR_A_COLA]="Cursor movido a la cola de la lista",
    [L2_MSG_CURSOR_A_LISTA]="Cursor movido a la lista original",
    [L2_MSG_NODO_INSERTO]="Nodo insertado con el valor ",
    [L2_MSG_SALIENDO]="Saliendo...",
    [L2_MSG_COMANDO_NO_RECONOCIDO]="Comando no reconocido\r\n",
    [L2_PROMPT_COLA]="cola > ",
    [L2_PROMPT_LISTA]="lista > ",
    [L2_MUESTRA_LISTA]="muestraLista",
    [L2_MSG_INICIO_LISTA]="Cabeza: ",
    [L2_MSG_SEPARADOR_LISTA]=" -> ",
    [L2_MSG_FIN_LISTA]="Fin",

};