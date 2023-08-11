#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    // return esValida(th, ti);
    if (esValida(th, ti))
        return true;
    else
        return false;

}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, dato region ) {
	vector < int > resultado = {-1, -1, -1, -1, -1, -1};
	
	// TODO
    resultado.clear();

    for(int i=1;i<=maximaCantidadDeHabitacionesEnRegion(th, region);i++){
        resultado.push_back(cantHogaresConNHabitaciones(th, region, i));
    }

	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};
	// TODO


    for(int i=0;i<CANTIDAD_DE_REGIONES;i++){
        resp[i].second = proporcionDeCasasConHC(th,ti, resp[i].first);
    }

    return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    return proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int resp = 0;
    for(int i = 0; i < th.size(); i++) {
        hogar h = th[i];
        if(tieneCasaPropia(h) && tieneCasaChica(h, ti)) {
            resp += monto;
        }
    }

    return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi resp;
    for (int i= 0; i<ti.size(); i++) {
        for (int h =0; h<th.size(); h++) {
            if (ti[i][ItemInd::INDCODUSU]==th[h][ItemHogar::HOGCODUSU]) {
                resp.push_back(make_pair(th[h],ti[i]));
            }
        }
    }

    return  resp;

}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {

    ordenarTablaHogares(th);
    ordenarTablaIndividuos(ti, th);

}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    hogar h = {};
    vector < hogar > resp = {h};

    // TODO
    resp.clear();
    vector < hogar > temp;
    int diferenciaTemp;

    for(int i=0;i<th.size();i++){
        for(int j=0;j<th.size();j++){

            if(i !=j && diferenciaDeIngresos(ti,th[i], th[j])>0){

                temp.push_back(th[i]);
                temp.push_back(th[j]);
                diferenciaTemp = diferenciaDeIngresos(ti, th[i], th[j]);
                buscarSiguientesHogares(th, ti, diferenciaTemp, temp, j, ingresos(th[j], ti));

                if(temp.size()>resp.size()){
                    resp.clear();
                    for(int i=0;i<temp.size();i++) {
                        resp.push_back(temp[i]);
                    }
                }
            }

            temp.clear();
        }
    }

    if (resp.size()<3){ //Correccion para la reentrega
        resp.clear();
    }

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
    cambiaRegionesGBAaPampeana(th);
	
	return;
}

// Implementacion Problema 11
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
	vector < int > resp = {};
	
	// TODO
    int distanciasSize = distancias.size();

    resp.push_back(cantHogaresEnAnillo(0,distancias[0],centro, th));

    for(int i=0;i<distanciasSize-1;i++){  // Consultar sobre la especificacion si i=0 o i=1
        resp.push_back(cantHogaresEnAnillo(distancias[i],distancias[i+1],centro, th));
    }
	
	return resp;
}

// Implementacion Problema 10
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {};
    eph_i rti = {};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);
    // Recorro y agrego a los individuos que cumplen la condicion a la respuesta
    for (int i = 0; i < ti.size(); ++i) {
        individuo ind = ti[i];
        if(cumpleCondicion(busqueda, ind)) {
            resp.second.push_back(ind);
        }
    }
    // Recorro los individuos agregados a la respuesta para agregar sus hogares y eliminarlos del vector inicial
    for(int i = 0; i < resp.second.size(); ++i) {
        individuo individuoAgregado = resp.second[i];
        // Agrego los hogares a la respuesta
        for(int indexHogar = 0; indexHogar < th.size(); ++indexHogar) {
            if(individuoAgregado[ItemInd::INDCODUSU] == th[indexHogar][ItemHogar::HOGCODUSU] && !hogarEnVector(th[indexHogar], resp.first)) {
                resp.first.push_back(th[indexHogar]);
                break;
            }
        }
        // Elimino a los individuos agregados del vector original
        eph_i::iterator it = ti.begin();
        while (it != ti.end()) {
            individuo individuoAComparar = *it;
            if(individuoAgregado == individuoAComparar) {
                ti.erase(it);
                break;
            }
            it++;
        }
    }
    // Recorro los hogares y los individuos restantes del vector original para eliminar los hogares que ya no estèn
    eph_h::iterator iterador = th.begin();
    while (iterador != th.end()) {
        hogar hogarABuscar = *iterador;
        bool hogarTieneIndividuo = false;
        for(int i = 0; i < ti.size(); i++) {
            individuo ind = ti[i];
            if(hogarABuscar[ItemHogar::HOGCODUSU] == ind[ItemInd::INDCODUSU]) {
                hogarTieneIndividuo = true;
                break;
            }
        }
        if(!hogarTieneIndividuo) {
            th.erase(iterador);
            iterador--;
        }
        iterador++;
    }


	
	return resp;
}


