#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida(eph_h th, eph_i ti);
void ordenarTablaHogares(eph_h &th);
void ordenarTablaIndividuos(eph_i &ti, eph_h th);
float proporcionTeleworking(eph_h th, eph_i ti);

// Ejercicio 2
int maximaCantidadDeHabitacionesEnRegion(eph_h th, dato region);
int cantHogaresConNHabitaciones(eph_h th, dato region, dato habitaciones);

// Ejercicio 3
float proporcionDeCasasConHC(eph_h th, eph_i ti, dato region);

// Ejercicio 5
bool tieneCasaPropia(hogar h);
bool tieneCasaChica(hogar h, eph_i ti);

// Ejercicio 8
int ingresos(hogar h, eph_i ti);
int diferenciaDeIngresos(eph_i ti, hogar hog1, hogar hog2);
void buscarSiguientesHogares(eph_h th, eph_i ti, int dif, vector<hogar>& temp, int hogarAnterior, int maximoActual);

// Ejercicio 9
void cambiaRegionesGBAaPampeana(eph_h &th);

// Ejercicio 10
bool cumpleCondicion(vector<pair<int, dato>> busqueda, individuo ind);
bool hogarEnVector(hogar h, vector<hogar> vec);

// Ejercicio 11
int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th);

#endif //SOLUCION_AUXILIARES_H


