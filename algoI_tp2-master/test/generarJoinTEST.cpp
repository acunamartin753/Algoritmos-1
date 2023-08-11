#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;


TEST(generarJoinTEST, casoFacil) {
    eph_h th = {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
               {31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
               {22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
               {20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};

    eph_i ti = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
               {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
               {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
               {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6},
               {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
               {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
               {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
               {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};


    join_hi junta = {{{20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1},
                      {20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1}},
                     {{20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1},
                      {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1}},
                     {{22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                      {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1}},
                     {{22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                      {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                      {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                      {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                      {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                      {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}}};

    EXPECT_TRUE(esEncuestaValida(th, ti));

    join_hi obtenido = generarJoin(th, ti);

    sort(junta.begin(), junta.end());
    sort(obtenido.begin(), obtenido.end());

    EXPECT_EQ(junta, obtenido);
}

// Nuevos casos de test

TEST(generarJoinTEST, tablaIndividuosDesordenada) {
    eph_h th = {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                {31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                {20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};

    eph_i ti = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
                {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};


    join_hi junta = {{{20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1},
                             {20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1}},
                     {{20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1},
                             {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1}},
                     {{22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                             {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1}},
                     {{22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                             {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                             {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                             {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                             {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}}};

    EXPECT_TRUE(esEncuestaValida(th, ti));

    join_hi obtenido = generarJoin(th, ti);

    sort(junta.begin(), junta.end());
    sort(obtenido.begin(), obtenido.end());

    EXPECT_EQ(junta, obtenido);
}

TEST(generarJoinTEST, unHogarMuchosIndividuos) {
    eph_h th = {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2}};

    eph_i ti = {{22114, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {22114, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22114, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {22114, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {22114, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1}};


    join_hi junta = {{{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1}}};

    EXPECT_TRUE(esEncuestaValida(th, ti));

    join_hi obtenido = generarJoin(th, ti);

    sort(junta.begin(), junta.end());
    sort(obtenido.begin(), obtenido.end());

    EXPECT_EQ(junta, obtenido);
}

TEST(generarJoinTEST, unIndividuoPorHogar) {
    eph_h th = {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                {31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                {20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};

    eph_i ti = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};


    join_hi junta = {{{20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1},
                             {20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1}},
                     {{22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},
                             {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1}},
                     {{31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                             {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1}},
                     {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2},
                             {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}}};

    EXPECT_TRUE(esEncuestaValida(th, ti));

    join_hi obtenido = generarJoin(th, ti);

    sort(junta.begin(), junta.end());
    sort(obtenido.begin(), obtenido.end());

    EXPECT_EQ(junta, obtenido);
}
