#include <unity.h>
#include "lista_enlazada.h"
#include <string.h>

static struct Datos{
    NodoListaEnlazada nodos[8];
    ListaEnlazada lista[1];
}datos;

void setUp(void)
{
    memset(&datos,'X',sizeof datos);
}

void tearDown(void){}

enum{PATRON_1=0xBADBEEF};

static void test_listaVacia_esVacia(void)
{
    ListaEnlazada *const lista = datos.lista;
    bool r;
    ListaEnlazada_inicializa(lista);
    r = ListaEnlazada_esVacia(lista);
    TEST_ASSERT_TRUE_MESSAGE(r,"esVacia es verdadero para la lista vacia");
}
static void test_listaVacia_obtNodoCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *n;
    ListaEnlazada_inicializa(lista);
    n = ListaEnlazada_obtNodoCabeza(lista);
    TEST_ASSERT_NULL_MESSAGE(n,"La lista vacia no tiene nodo a la cabeza");
}
static void test_listaVacia_obtCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    int r;
    int aux=PATRON_1;
    ListaEnlazada_inicializa(lista);
    r=ListaEnlazada_obtCabeza(lista,&aux);
    TEST_ASSERT_EQUAL_MESSAGE(-1,r,"La lista vacia no tiene cabeza");
    TEST_ASSERT_EQUAL_MESSAGE(PATRON_1,aux,"No escribir basura en la variable");
}
static void test_listaVacia_obtCola(void)
{
    ListaEnlazada *const lista = datos.lista;
    ListaEnlazada *cola;
    ListaEnlazada_inicializa(lista);
    cola = ListaEnlazada_obtCola(lista);
    TEST_ASSERT_EQUAL_MESSAGE(lista,cola,"La lista vacia es su propia cola");
}
static void test_listaVacia_remueveCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *n;
    bool r;
    ListaEnlazada_inicializa(lista);
    n = ListaEnlazada_remueveCabeza(lista);
    TEST_ASSERT_NULL_MESSAGE(n,"La lista vacia no tiene nodos");
    r = ListaEnlazada_esVacia(lista);
    TEST_ASSERT_TRUE_MESSAGE(r,"La lista vacia no cambia al intentar remover la cabeza");
}
static void test_listaUnElemento_noEsVacia(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    bool r;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    ListaEnlazada_inserta(lista,nodos+0);
    r = ListaEnlazada_esVacia(lista);
    TEST_ASSERT_FALSE_MESSAGE(r,"esVacia retorna falso si la lista no es vacia");
}
static void test_listaUnElemento_obtNodoCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    NodoListaEnlazada *n;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    ListaEnlazada_inserta(lista,nodos+0);
    n = ListaEnlazada_obtNodoCabeza(lista);
    TEST_ASSERT_NOT_NULL_MESSAGE(n,"La lista de un elemento tiene nodo a la cabeza");
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+0,n,"El nodo a la cabeza debe ser el insertado");
}
static void test_listaUnElemento_obtCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    int r;
    int aux=PATRON_1;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    ListaEnlazada_inserta(lista,nodos+0);
    r=ListaEnlazada_obtCabeza(lista,&aux);
    TEST_ASSERT_EQUAL_MESSAGE(0,r,"La lista con un elemento");
    TEST_ASSERT_EQUAL_MESSAGE(1,aux,"El nodo tendra el valor con que fue inicializado");
}
static void test_listaUnElemento_obtCola(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    ListaEnlazada *cola;
    bool r;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    ListaEnlazada_inserta(lista,nodos+0);
    cola = ListaEnlazada_obtCola(lista);
    TEST_ASSERT_NOT_NULL_MESSAGE(cola,"Una lista siempre tiene cola");
    r = ListaEnlazada_esVacia(cola);
    TEST_ASSERT_TRUE_MESSAGE(r,"La cola de una lista de un elemento es una lista vacia");
}
static void test_listaUnElemento_remueveCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    NodoListaEnlazada *n;
    bool r;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    ListaEnlazada_inserta(lista,nodos+0);
    n = ListaEnlazada_remueveCabeza(lista);
    TEST_ASSERT_EQUAL_MESSAGE(nodos+0,n,"remueveCabeza retorna puntero al nodo removido");
    r = ListaEnlazada_esVacia(lista);
    TEST_ASSERT_TRUE_MESSAGE(r,"Luego de remover el ultimo nodo, la lista queda vacia");

}
static void test_listaDosElementos_obtNodoCabezaDeCola(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    NodoListaEnlazada *n;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    NodoListaEnlazada_inicializa(nodos+1,2);
    ListaEnlazada_inserta(lista,nodos+0);
    ListaEnlazada_inserta(lista,nodos+1);
    n = ListaEnlazada_obtNodoCabeza(ListaEnlazada_obtCola(lista));
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+0,n,"La cola contiene todos los nodos excepto el ultimo inserto");
}
static void test_listaDosElementos_obtCabezaDeCola(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    int aux = PATRON_1;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    NodoListaEnlazada_inicializa(nodos+1,2);
    ListaEnlazada_inserta(lista,nodos+0);
    ListaEnlazada_inserta(lista,nodos+1);
    ListaEnlazada_obtCabeza(ListaEnlazada_obtCola(lista),&aux);
    TEST_ASSERT_EQUAL_MESSAGE(1,aux,"La cola contiene todos los nodos excepto el ultimo inserto");
}
static void test_listaDosElementos_remueveCabeza(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    NodoListaEnlazada *n;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    NodoListaEnlazada_inicializa(nodos+1,2);
    ListaEnlazada_inserta(lista,nodos+0);
    ListaEnlazada_inserta(lista,nodos+1);
    n = ListaEnlazada_remueveCabeza(lista);
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+1,n,"Deber retornar puntero al nodo eliminado");
    n = ListaEnlazada_obtNodoCabeza(lista);
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+0,n,"La cabeza de la cola pasa a ser la nueva cabeza");
}
static void test_listaTresElementos_remueveMedio(void)
{
    ListaEnlazada *const lista = datos.lista;
    NodoListaEnlazada *const nodos = datos.nodos;
    NodoListaEnlazada *n;
    ListaEnlazada_inicializa(lista);
    NodoListaEnlazada_inicializa(nodos+0,1);
    NodoListaEnlazada_inicializa(nodos+1,2);
    NodoListaEnlazada_inicializa(nodos+2,3);
    ListaEnlazada_inserta(lista,nodos+0);
    ListaEnlazada_inserta(lista,nodos+1);
    ListaEnlazada_inserta(lista,nodos+2);
    n = ListaEnlazada_remueveCabeza(ListaEnlazada_obtCola(lista));
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+1,n,"Deber retornar puntero al nodo eliminado");
    n = ListaEnlazada_obtNodoCabeza(lista);
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+2,n,"No cambia la cabeza");
    n = ListaEnlazada_obtNodoCabeza(ListaEnlazada_obtCola(lista));
    TEST_ASSERT_EQUAL_PTR_MESSAGE(nodos+0,n,"El tercer nodo pasa a ser el segundo");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_listaVacia_esVacia);
    RUN_TEST(test_listaVacia_obtNodoCabeza);
    RUN_TEST(test_listaVacia_obtCabeza);
    RUN_TEST(test_listaVacia_obtCola);
    RUN_TEST(test_listaVacia_remueveCabeza);
    RUN_TEST(test_listaUnElemento_noEsVacia);
    RUN_TEST(test_listaUnElemento_obtNodoCabeza);
    RUN_TEST(test_listaUnElemento_obtCabeza);
    RUN_TEST(test_listaUnElemento_obtCola);
    RUN_TEST(test_listaUnElemento_remueveCabeza);
    RUN_TEST(test_listaDosElementos_obtNodoCabezaDeCola);
    RUN_TEST(test_listaDosElementos_obtCabezaDeCola);
    RUN_TEST(test_listaDosElementos_remueveCabeza);
    RUN_TEST(test_listaTresElementos_remueveMedio);
    UNITY_END();
    return 0;
}