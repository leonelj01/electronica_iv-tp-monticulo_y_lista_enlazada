#include <unity.h>
#include "monticulo.h"

static struct Datos{
    int aux;
    int guarda1[4];
    int celdas[16];
    int guarda2[4];
    Monticulo m[1];
} datos;

enum{ N_CELDAS = sizeof datos.celdas / sizeof *datos.celdas,
      PATRON_VALOR = 0xBADBEEF};

#define PATRON_GUARDA_1i {1111,2222,3333,4444} 
#define PATRON_GUARDA_2i {5555,6666,7777,8888} 
#define PATRON_GUARDA_1 ((int[4])PATRON_GUARDA_1i)
#define PATRON_GUARDA_2 ((int[4])PATRON_GUARDA_2i)


void setUp(void)
{
    datos = (struct Datos){
        .aux = PATRON_VALOR,
        .guarda1 = PATRON_GUARDA_1i,
        .celdas  = {},
        .guarda2 = PATRON_GUARDA_2i,
        .m       = {}};
}
void tearDown(void)
{
    TEST_ASSERT_EQUAL_HEX_ARRAY(PATRON_GUARDA_1,datos.guarda1,4);
    TEST_ASSERT_EQUAL_HEX_ARRAY(PATRON_GUARDA_2,datos.guarda2,4);
}

static void util_inicializaMonticulo(TipoMonticulo t)
{
    Monticulo_inicializa(datos.m,datos.celdas,N_CELDAS,t);
}

static void test_monticuloVacio(void)
{
    int r;
    util_inicializaMonticulo(Monticulo_MAXIMO);
    r = Monticulo_leeTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(-1,r);
    TEST_ASSERT_EQUAL(PATRON_VALOR,datos.aux);
}

static void test_monticuloLeeTope(void)
{
    int r;
    util_inicializaMonticulo(Monticulo_MAXIMO);
    r = Monticulo_introduce(datos.m,1);
    TEST_ASSERT_EQUAL(0,r);
    r = Monticulo_leeTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(0,r);
    TEST_ASSERT_EQUAL(1,datos.aux);
    datos.aux = PATRON_VALOR;
    r = Monticulo_leeTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(0,r);
    TEST_ASSERT_EQUAL(1,datos.aux);
}
static void test_monticuloTomaTope(void)
{
    int r;
    util_inicializaMonticulo(Monticulo_MAXIMO);
    Monticulo_introduce(datos.m,1);
    r = Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(0,r);
    TEST_ASSERT_EQUAL(1,datos.aux);
    datos.aux = PATRON_VALOR;
    r = Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(-1,r);
    TEST_ASSERT_EQUAL(PATRON_VALOR,datos.aux);
}

static void test_monticuloMaxIntroduce(void)
{
    int r;
    util_inicializaMonticulo(Monticulo_MAXIMO);
    Monticulo_introduce(datos.m,1);
    Monticulo_introduce(datos.m,3);
    r = Monticulo_leeTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(0,r);
    TEST_ASSERT_EQUAL(3,datos.aux);
}
static void test_monticuloMax153(void)
{
    int r;
    util_inicializaMonticulo(Monticulo_MAXIMO);
    Monticulo_introduce(datos.m,1);
    Monticulo_introduce(datos.m,5);
    Monticulo_introduce(datos.m,3);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(5,datos.aux);
    r = Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(0,r);
    TEST_ASSERT_EQUAL(3,datos.aux);
    r = Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(0,r);
    TEST_ASSERT_EQUAL(1,datos.aux);
}
static void test_monticuloMax351(void)
{
    util_inicializaMonticulo(Monticulo_MAXIMO);
    Monticulo_introduce(datos.m,3);
    Monticulo_introduce(datos.m,5);
    Monticulo_introduce(datos.m,1);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(5,datos.aux);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(3,datos.aux);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(1,datos.aux);
}
static void test_monticuloMin153(void)
{
    util_inicializaMonticulo(Monticulo_MINIMO);
    Monticulo_introduce(datos.m,1);
    Monticulo_introduce(datos.m,5);
    Monticulo_introduce(datos.m,3);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(1,datos.aux);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(3,datos.aux);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(5,datos.aux);
}
static void test_monticuloMin351(void)
{
    util_inicializaMonticulo(Monticulo_MINIMO);
    Monticulo_introduce(datos.m,3);
    Monticulo_introduce(datos.m,5);
    Monticulo_introduce(datos.m,1);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(1,datos.aux);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(3,datos.aux);
    Monticulo_tomaTope(datos.m,&datos.aux);
    TEST_ASSERT_EQUAL(5,datos.aux);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_monticuloVacio);
    RUN_TEST(test_monticuloLeeTope);
    RUN_TEST(test_monticuloTomaTope);
    RUN_TEST(test_monticuloMaxIntroduce);
    RUN_TEST(test_monticuloMax153);
    RUN_TEST(test_monticuloMax351);
    RUN_TEST(test_monticuloMin153);
    RUN_TEST(test_monticuloMin351);
    UNITY_END();
    return 0;
}