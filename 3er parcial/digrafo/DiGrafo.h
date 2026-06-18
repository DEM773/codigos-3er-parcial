#ifndef DiGRAFO_H
#define DiGRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Estructura para las aristas dirigidas (arcos)
struct Ruta {
    string origen;       // Nodo de salida (ni)
    string destino;      // Nodo de llegada (nf)
    string nombreArista; // Nombre del arco (ae)
    int peso;            // Costo (p)
    int tiempo;          // Duracion (t)
};

class Grafo {
private:
    vector<string> nodos; 
    vector<Ruta> rutas;   
    map<string, vector<pair<string, int> > > listaAdyacencia; 

    // Algoritmo de busqueda para contar caminos en un digrafo
    void contarTodasLasRutas(string actual, string destino, map<string, bool>& visitado, int& contador);

public:
    void agregarNodo(string nodo);
    void agregarRutaDirigida(string ni, string nf, string ae, int p, int t);
    void mostrarNodos();
    void mostrarRutasCargadas();
    int obtenerTotalCaminos(string origen, string destino);
    void buscarRutaMasCortaDijkstra(string origen, string destino);
};

#endif
