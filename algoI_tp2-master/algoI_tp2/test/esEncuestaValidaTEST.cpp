#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;

TEST(esEncuestaValidaTEST, valida) {

    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_TRUE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaSinHogares) {

    eph_h th = {};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaSinTodosLosAtributosIndividuos) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};
    eph_i ti = {{22114},
                {22114, 2020}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaSinTodosLosAtributosHogares) {
    eph_h th = {{}};
    eph_i ti = {{22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaIndividuosSinHogares) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaHogaresCodusuRepetidos) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22114, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaIndividuosCodusuYComponenteRepetidos) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   1,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaDistintoAnioHogares) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2021,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaDistintoAnioEntreHogaresEIndividuos) {
    eph_h th = {{22114, 2021,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22866, 2021,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2021,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaDistintoTrimestreEntreIndividuos) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  2,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}
TEST(esEncuestaValidaTEST, invalidaDormitoriosMayoresAHabitaciones) {
    //                                                cantidad de dormitorios
    //                                        cantidad de habitaciones  |
    //                                                              |   |
    //                                                              v   v
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22866, 2020,   1,  317157, 627217, 2,  42, 1,  1,  2,  5,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};
    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, validaMenosOIgualA20MiembrosEnElHogar) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};
    eph_i ti;

    for (int i = 1; i <= 20; i++) {
        individuo individuo_actual = {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10};
        individuo_actual[COMPONENTE] = i;
        ti.push_back(individuo_actual);
    }

    EXPECT_TRUE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, invalidaTrimestreNegativo) {
    eph_h th = {{22114, 2020,   -3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};
    eph_i ti = {{22114, 2020,   1,  0,  -3,  1,  18, 0,  0,  20000,  10}};

    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, validaTrimestreEnRango) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};
    eph_i ti = {{22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};
    EXPECT_TRUE(esEncuestaValida(th, ti));

    th[0][HOGTRIMESTRE] = 1;
    ti[0][INDTRIMESTRE] = 1;
    EXPECT_TRUE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, validaAnioNegativo) {
    eph_h th = {{22114, -2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};
    eph_i ti = {{22114, -2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};
    EXPECT_TRUE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, validaeph2018_100) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2018_100", th, ti );

    EXPECT_TRUE(esEncuestaValida(th, ti) );
}

TEST(esEncuestaValidaTEST, validaeph2020_100) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2020_100", th, ti );

    EXPECT_TRUE(  esEncuestaValida(th, ti) );
}

TEST(esEncuestaValidaTEST, hayHogarSinIndividuo) {
    eph_h th = {
                {22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {22113, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}
                };
    eph_i ti = {{22113, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, masHabitacionesParaDormirQueHabitaciones) {
    eph_h th = {
            {22113, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  4,  2}
    };
    eph_i ti = {{22113, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, cantidadColumnasIndividuoIncorrecta) {
    eph_h th = {
            {22113, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}
    };
    eph_i ti = {{22113, 2020,   1,  0,  3,  1,  18, 0,  0,  20000}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, cantidadHabitantesEnUnHogarMayorQue21) {
    eph_h th = {
            {22113, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}
    };
    eph_i ti = {
            {22113, 2020,   1,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   2,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   3,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   4,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   5,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   6,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   7,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   8,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   9,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   10,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   11,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   12,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   13,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   14,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   15,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   16,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   17,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   18,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   19,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   20,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   21,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   22,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   23,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   24,  0,  3,  1,  18, 0,  0,  20000, 10},
            {22113, 2020,   25,  0,  3,  1,  18, 0,  0,  20000, 10}
    };
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

TEST(esEncuestaValidaTEST, hogarInvalido) {
    // EL rango esperado del parámetro MAS_500 es 0 o 1. Se lo pone en 2 para que el hogar sea inválido
    eph_h th = {
            {22113, 2020,   3,  319611, 629088, 3,  41, 2,  1,  3,  1,  2}
    };
    eph_i ti = {{22113, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};
    EXPECT_FALSE(esEncuestaValida(th, ti));
}

