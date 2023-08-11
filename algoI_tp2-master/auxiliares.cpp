#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <math.h>

// Auxiliares ejercicio 1

int cantIndividuosQueTrabajan(eph_h vector1, eph_i vector2);

bool trabaja(individuo vector1);

bool individuoEnHogarValido(individuo vector1, eph_h vector2);

bool realizaSusTareasEnEsteHogar(individuo vector1);

bool suHogarTieneEspaciosReservadorParaElTrabajo(individuo vector1, eph_h vector2);

bool esDeCiudadGrande(individuo vector1, eph_h vector2);

bool suHogarEsCasaODepartamento(individuo vector1, eph_h vector2);

bool vacia (vector<vector<dato>> s) {
    return s.size()==0;
}

bool esMatriz( vector<vector<dato>> m) {
    for(int j = 1; j<m.size();  j++) {
        if (m[0].size() != m[j].size()) {
            return false;
        }
    }
    return true;
}

bool  cantidadCorrectaDeColumnasI( eph_i ti) {
    for (int i = 0; i<ti.size(); i++) {
        if (ti[i].size() != 11)
            return false;
    }
    return true;
}

bool cantidadCorrectaDeColumnasH (eph_h th) {
    for (int i = 0; i<th.size(); i++) {
        if ( th[i].size() != 12)
            return false;
    }
    return true;
}

bool hayHogarConCodigo (eph_h th, int c) {
    for (int h = 0; h < th.size(); h++) {
        if ( th[h][ItemHogar::HOGCODUSU] == c )
            return true;
    }
    return false;
}

bool hayIndividuosSinHogares (eph_i ti, eph_h th) {
    for (int i = 0; i<ti.size(); i++) {
        if (!hayHogarConCodigo(th, ti[i][ItemInd::INDCODUSU]))
            return true;
    }
    return false;
}

bool hayIndividuoConCodigo (eph_i ti, int c) {
    for (int i = 0; i<ti.size(); i++) {
        if (ti[i][ItemInd::INDCODUSU] == c)
            return true;
    }
    return false;
}

bool hayHogaresSinIndividuos (eph_i ti, eph_h th) {
    for (int h = 0; h < th.size(); h++ ) {
        if (!hayIndividuoConCodigo(ti, th[h][ItemHogar::HOGCODUSU]))
            return true;
    }
    return false;
}

bool mismoCodusuYComponente (individuo i1, individuo i2) {
    return (i1[ItemInd::INDCODUSU] == i2[ItemInd::INDCODUSU]) && (i1[ItemInd::COMPONENTE] == i2[ItemInd::COMPONENTE]);
}

bool hayRepetidosI (eph_i ti) {
    for (int n1 = 0; n1 < ti.size(); n1++) {
        for (int n2 = 0; n2<ti.size() && n2 != n1; n2++ ) {
            if (mismoCodusuYComponente(ti[n1], ti[n2]))
                return true;
        }
    }
    return false;
}

bool hayRepetidosH (eph_h th) {
    for (int n1 = 0; n1 < th.size(); n1++) {
        for (int n2 = 0; n2<th.size() && n2 != n1; n2++ ) {
            if (th[n1][ItemHogar::HOGCODUSU] == th[n2][ItemHogar::HOGCODUSU])
                return true;
        }
    }
    return false;
}

bool mismoAnioYTrimestre (eph_i ti, eph_h th) {
    int anio = th[0][ItemHogar::HOGANIO];
    int trimestre = th[0][ItemHogar::HOGTRIMESTRE];
    for (int i = 0; i<ti.size(); i++) {
        if ((ti[i][ItemInd::INDANIO] != anio) || (ti[i][ItemInd::INDTRIMESTRE] != trimestre))
            return false;
    }
    for (int h = 0; h < th.size(); h++) {
        if ((th[h][ItemHogar::HOGANIO] != anio) || (th[h][ItemHogar::HOGTRIMESTRE] != trimestre))
            return false;
    }
    return true;
}

bool esSuHogar(hogar h, individuo i){
    return h[ItemHogar::HOGCODUSU] == i[ItemInd::INDCODUSU];
}

int cantHabitantes (hogar h, eph_i ti) {
    int suma = 0;
    for (int k= 0; k < ti.size(); k++) {
        if (esSuHogar(h, ti[k]))
            suma++;
    }
    return suma;
}

bool menosDe21MiembrosPorHogar (eph_h th, eph_i ti) {
    for (int i = 0; i<th.size(); i++) {
        if (cantHabitantes(th[i], ti) >= 21)
            return false;
    }
    return true;
}

bool cantidadValidaDormitorios (eph_h th) {
    for (int h = 0; h<th.size(); h++) {
        if (th[h][ItemHogar::IV2] < th[h][ItemHogar::II2])
            return false;
    }
    return true;
}

bool individuoValido (individuo i) {
    return (i[ItemInd::INDCODUSU]>0 && i[ItemInd::COMPONENTE]>0 && i[ItemInd::INDTRIMESTRE]>0 && i[ItemInd::INDTRIMESTRE]<=4 && (i[ItemInd::CH4]==1 ||
            i[ItemInd::CH4]== 2) &&i[ItemInd::CH6]>=0 && (i[ItemInd::NIVEL_ED]==0 || i[ItemInd::NIVEL_ED]==1) &&
            i[ItemInd::ESTADO]>=-1 && i[ItemInd::ESTADO]<=1 && i[ItemInd::CAT_OCUP]>=0 && i[ItemInd::CAT_OCUP]<=4 && (i[ItemInd::p47T]>=0 || i[ItemInd::p47T]==-1)
            && i[ItemInd::PP04G]>=0 && i[ItemInd::PP04G]<=10 );
}

bool valoresEnRangoI(eph_i ti) {
    for (int i = 0; i<ti.size(); i++) {
        if (!individuoValido(ti[i]))
            return false;
    }
    return true;
}

bool valorRegionValido(int r) {
    return (r==1) || (40<=r && r<=44);
}

bool hogarValido(hogar h) {
    return (h[ItemHogar::HOGCODUSU]>0 && h[ItemHogar::HOGTRIMESTRE]>0 && h[ItemHogar::HOGTRIMESTRE]<=4 && h[ItemHogar::II7]>0 && h[ItemHogar::II7]<=3 &&
            valorRegionValido(h[ItemHogar::REGION]) && (h[ItemHogar::MAS_500]==0 || h[ItemHogar::MAS_500]==1) && h[ItemHogar::IV1]>0 && h[ItemHogar::IV1]<=5 &&
            h[ItemHogar::IV2]>0 && h[ItemHogar::II2]>=1 && (h[ItemHogar::II3]==1 || h[ItemHogar::II3]==2));
}

bool valoresEnRangoH (eph_h th) {
    for (int h = 0; h<th.size(); h++) {
        if (!hogarValido(th[h]))
            return false;
    }
    return true;
}

bool esValida(eph_h th, eph_i ti) {
    return (!vacia(ti) && !vacia(th) && esMatriz(ti) && esMatriz(th) && cantidadCorrectaDeColumnasI(ti) &&
            cantidadCorrectaDeColumnasH(th) && !hayIndividuosSinHogares(ti, th) && !hayHogaresSinIndividuos(ti, th) &&
            !hayRepetidosI(ti) && !hayRepetidosH(th) && mismoAnioYTrimestre(ti, th) && menosDe21MiembrosPorHogar(th, ti) &&
            cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th));
}

// Auxiliares ejercicio 2
bool esCasa(hogar h){
    return h[ItemHogar::IV1]==CASA;
}

int cantHogaresConNHabitaciones(eph_h th, dato region, dato habitaciones){
    int res=0;
    int thSize=th.size();

    for(int i=0;i<thSize;i++){
        if(esCasa(th[i]) && th[i][ItemHogar::IV2]==habitaciones && th[i][ItemHogar::REGION] == region){
            res++;
        }
    }

    return res;
}

int maximaCantidadDeHabitacionesEnRegion(eph_h th, dato region){
    int thSize=th.size();
    int res=0;

    for(int i=0;i<thSize;i++){
        if(th[i][ItemHogar::REGION] == region && th[i][ItemHogar::IV2] > res){
            res = th[i][ItemHogar::IV2];
        }
    }

    return res;
}

// Auxiliares del ejercicio 3
int cantidadDeHabitantes(hogar h, eph_i ti){
    int res = 0;
    int tiSize = ti.size();

    for(int i=0;i<tiSize;i++){
        if(esSuHogar(h, ti[i])){
            res++;
        }
    }

    return res;
}

bool esHogarValido(hogar h, dato region){
    return (esCasa(h) && h[ItemHogar::REGION]==region && h[ItemHogar::MAS_500]==0);
}

bool hogarConHacinamientoCritico(hogar h, eph_i ti){
    return (cantidadDeHabitantes(h, ti)>3*h[ItemHogar::II2]);
}

int cantHogaresValidos(eph_h th, dato region){
    int thSize=th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(esHogarValido(th[i], region)){
            res++;
        }
    }
    return res;
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, dato region){
    int thSize=th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(esHogarValido(th[i], region) && hogarConHacinamientoCritico(th[i], ti)){
            res++;
        }
    }
    return res;
}

float proporcionDeCasasConHC(eph_h th, eph_i ti, dato region){
    float res = 0;

    if(cantHogaresValidos(th, region)>0){
        res = (float)cantHogaresValidosConHC(th, ti, region)/ (float)cantHogaresValidos(th, region); // correccion para la reentrega
    }

    return res;
}

// Auxiliares ejercicio 5
bool tieneCasaPropia(hogar h) {
    return h[ItemHogar::II7] == 1;
}

bool tieneCasaChica(hogar h, eph_i ti) {
    return cantHabitantes(h, ti) - 2 > h[ItemHogar::II2];
}

//Auxiliares del ejercicio 7

void swap(vector<vector<dato>> &s, dato a, dato b){
    vector<dato> c = s[a];
    s[a]= s[b];
    s[b] = c;
}

void insertH(eph_h &th, dato i) {
    for(int j=i; j>0 ; j--) {
        if (th[j][ItemHogar::REGION] < th[j-1][ItemHogar::REGION]) //distinta REGION
            swap(th, j, j-1);
        if ((th[j][ItemHogar::REGION] == th[j-1][ItemHogar::REGION]) && th[j][ItemHogar::HOGCODUSU] < th[j-1][ItemHogar::HOGCODUSU]) //misma REGION, ordenar por HOGCODUSU
            swap(th, j, j-1);
    }
}

void ordenarTablaHogares(eph_h &th) {
    for(int i=0; i<th.size(); i++) {
        insertH(th,i);
    }
}

bool vivenJuntos (individuo i1, individuo i2) {
    return (i1[ItemInd::INDCODUSU] == i2[ItemInd::INDCODUSU]);
}

bool suhogarEstaAntes (eph_h th, individuo i1, individuo i2) {
    int a; int b;
    for (int i =0; i < th.size(); i++) {
        if (th[i][ItemHogar::HOGCODUSU]== i1[ItemInd::INDCODUSU])
            a = i;
        if (th[i][ItemHogar::HOGCODUSU]== i2[ItemInd::INDCODUSU])
            b = i;
    }
    return a<b;
}

void insertI(eph_i &ti, eph_h th, dato i) {
    for(int j=i; j>0 ; j--) {
        if (suhogarEstaAntes(th, ti[j], ti[j-1])) {
            swap(ti, j, j-1);
        }
        if (vivenJuntos(ti[j], ti[j-1]) && ti[j][ItemInd::COMPONENTE] < ti[j-1][ItemInd::COMPONENTE])
            swap(ti, j, j-1);
    }
}

void ordenarTablaIndividuos(eph_i &ti, eph_h th) {
    for(int i=0; i<ti.size(); i++) {
        insertI(ti,th, i);
    }
}

//Auxiliares del ejercicio 8
int ingresos(hogar h, eph_i ti){
    int res = 0;
    int tiSize = ti.size();

    for(int i=0;i<tiSize;i++){
        if(ti[i][ItemInd::INDCODUSU]==h[ItemHogar::HOGCODUSU] && ti[i][ItemInd::p47T]>-1){
            res += ti[i][ItemInd::p47T];
        }
    }

    return res;
}

int diferenciaDeIngresos(eph_i ti, hogar hog1, hogar hog2){
    return ingresos(hog2,ti)-ingresos(hog1,ti);
}

void buscarSiguientesHogares(eph_h th, eph_i ti, int dif, vector<hogar>& temp, int hogarAnterior, int maximoActual){
    for(int k=0;k<th.size();k++){
        if(hogarAnterior != k && diferenciaDeIngresos(ti, th[hogarAnterior], th[k]) == dif && ingresos(th[k], ti)>maximoActual){
            temp.push_back(th[k]);
            maximoActual = ingresos(th[k], ti);
            buscarSiguientesHogares(th, ti, dif, temp, k, maximoActual);
        }
    }
}

// Auxiliares del ejercicio 4
bool esCasaODepartamento(hogar h) {
    return h[ItemHogar::IV1] == 1 || h[ItemHogar::IV1] == 2;
}

bool realizaSusTareasEnEsteHogar(individuo i) {
    return i[ItemInd::PP04G] == 6;
}

bool tieneEspaciosReservadosParaElTrabajo(hogar h) {
    return h[ItemHogar::II3] == 1;
}

bool trabajaEnSuVivienda(individuo i, eph_h th) {
    return realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadorParaElTrabajo(i, th);
}

int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti) {
    int sum = 0;
    for(int indice = 0; indice < ti.capacity(); indice++) {
        individuo i = ti[indice];
        if(trabaja(i) && trabajaEnSuVivienda(i, th) && individuoEnHogarValido(i, th)) {
            sum++;
        }
    }
    return sum;
}

float proporcionTeleworking(eph_h th, eph_i ti) {
    if(cantIndividuosQueTrabajan(th, ti) > 0) {
        return (float) cantIndividuosTrabajandoEnSuVivienda(th, ti) / (float) cantIndividuosQueTrabajan(th, ti);
    } else {
        return 0;
    }
}


int cantIndividuosQueTrabajan(eph_h th, eph_i ti) {
    int sum = 0;
    for(int indice = 0; indice < ti.capacity(); indice++) {
        individuo i = ti[indice];
        if(trabaja(i) && individuoEnHogarValido(i, th)) {
            sum++;
        }
    }
    return sum;
}



bool individuoEnHogarValido(individuo i, eph_h th) {
    return esDeCiudadGrande(i, th) && suHogarEsCasaODepartamento(i, th);
}

bool trabaja(individuo i) {
    return i[ItemInd::ESTADO] == OCUPADO;
}

bool esDeCiudadGrande(individuo i, eph_h th) {
    for(int indice = 0; indice < th.capacity(); indice++) {
        if(esSuHogar(th[indice], i) && th[indice][ItemHogar::MAS_500]) {
            return true;
        }
    }
    return false;
}

bool suHogarTieneEspaciosReservadorParaElTrabajo(individuo i, eph_h th) {
    for(int indice = 0; indice < th.capacity(); indice++) {
        if(esSuHogar(th[indice], i) && tieneEspaciosReservadosParaElTrabajo(th[indice])) {
            return true;
        }
    }
    return false;
}

bool suHogarEsCasaODepartamento(individuo i, eph_h th) {
    for(int indice = 0; indice < th.capacity(); indice++) {
        if(esSuHogar(th[indice], i) && esCasaODepartamento(th[indice])) {
            return true;
        }
    }
    return false;
}



// Auxiliares del ejercicio 9
void cambiaRegionesGBAaPampeana(eph_h &th) {
    for(int indice = 0; indice < th.capacity(); indice++) {
        if(th[indice][ItemHogar::REGION] == GBA) {
            th[indice][ItemHogar::REGION] = PAMPEANA;
        }
    }
}

// Auxiliares ejercicio 10
bool cumpleCondicion(vector < pair < int, dato >> busqueda, individuo ind) {
    for(int i = 0; i < busqueda.size(); i++) {
        pair<int, dato> condicion = busqueda[i];
        if(ind[condicion.first] != condicion.second) {
            return false;
        }
    }
    return true;
}

bool hogarEnVector(hogar h, vector<hogar> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(h == vec[i]) {
            return true;
        }
    }
    return false;
}
// Auxiliares del ejercicio 11
float distanciaEuclidiana(pair < int, int > centro, int latitud, int longitud){
    float res = sqrt(pow(centro.first-latitud, 2) + pow(centro.second-longitud, 2));
    return res;
}

bool hogarEnAnillo(int distDesde, int distHasta, pair < int, int > centro, hogar h){
    bool res = false;

    if(distDesde < distanciaEuclidiana(centro, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) && distanciaEuclidiana(centro, h[ItemHogar::HOGLATITUD], h[ItemHogar::HOGLONGITUD]) <= distHasta){
        res = true;
    }

    return res;
}

int cantHogaresEnAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th){
    int thSize = th.size();
    int res = 0;

    for(int i=0;i<thSize;i++){
        if(hogarEnAnillo(distDesde, distHasta, centro, th[i])){
            res++;
        }
    }

    return res;
}


