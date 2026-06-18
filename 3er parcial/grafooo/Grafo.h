#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Ruta {
    string origen;       
    string destino;      
    string nombreArista; 
    int peso;            
    int tiempo;          
};

class Grafo {
private:
    vector<string> nodos; 
    vector<Ruta> rutas;   
    map<string, vector<pair<string, int> > > listaAdyacencia; 

    void contarTodasLasRutas(string actual, string destino, map<string, bool>& visitado, int& contador);

public:
    void agregarNodo(string nodo);
    void agregarRuta(string ni, string nf, string ae, int p, int t);
    void mostrarNodos();
    void mostrarRutasCargadas();
    int obtenerTotalCaminos(string origen, string destino);
    void buscarRutaMasCortaDijkstra(string origen, string destino);
    void archivos();
};

#endif
