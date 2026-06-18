#include "Grafo.h"

void Grafo::agregarNodo(string nodo) {
    bool existe = false;
    for (size_t i = 0; i < nodos.size(); ++i) {
        if (nodos[i] == nodo) {
            existe = true;
            break;
        }
    }
    if (!existe) {
        nodos.push_back(nodo);
    }
}

void Grafo::agregarRuta(string ni, string nf, string ae, int p, int t) {
    agregarNodo(ni);
    agregarNodo(nf);
    
    Ruta nuevaRuta = {ni, nf, ae, p, t};
    rutas.push_back(nuevaRuta);
    
    listaAdyacencia[ni].push_back(pair<string, int>(nf, p));
}

void Grafo::mostrarNodos() {
    cout << "\n=== NODOS DISPONIBLES ===" << endl;
    if (nodos.empty()) {
        cout << "(No hay nodos registrados aun)" << endl;
    } else {
        for (size_t i = 0; i < nodos.size(); ++i) {
            cout << "[" << nodos[i] << "] ";
        }
        cout << endl;
    }
    cout << "=========================" << endl;
}

void Grafo::mostrarRutasCargadas() {
    cout << "\n=== TABLA DE RUTAS / ARISTAS ===" << endl;
    cout << "ni\tnf\tae\tp\tt" << endl;
    cout << "-------------------------------" << endl;
    if (rutas.empty()) {
        cout << "(No hay rutas registradas aun)" << endl;
    } else {
        for (size_t i = 0; i < rutas.size(); ++i) {
            cout << rutas[i].origen << "\t" 
                 << rutas[i].destino << "\t" 
                 << rutas[i].nombreArista << "\t" 
                 << rutas[i].peso << "\t" 
                 << rutas[i].tiempo << endl;
        }
    }
    cout << "================================" << endl;
}

void Grafo::contarTodasLasRutas(string actual, string destino, map<string, bool>& visitado, int& contador) {
    if (actual == destino) {
        contador++;
        return;
    }
    
    visitado[actual] = true;
    vector<pair<string, int> >& vecinos = listaAdyacencia[actual];
    
    for (size_t i = 0; i < vecinos.size(); ++i) {
        string siguienteNodo = vecinos[i].first;
        if (!visitado[siguienteNodo]) {
            contarTodasLasRutas(siguienteNodo, destino, visitado, contador);
        }
    }
    visitado[actual] = false;
}

int Grafo::obtenerTotalCaminos(string origen, string destino) {
    map<string, bool> visitado;
    int contador = 0;
    contarTodasLasRutas(origen, destino, visitado, contador);
    return contador;
}

void Grafo::buscarRutaMasCortaDijkstra(string origen, string destino) {
    map<string, int> distancias;
    map<string, string> predecesores;
    
    for (size_t i = 0; i < nodos.size(); ++i) {
        distancias[nodos[i]] = INT_MAX;
    }
    distancias[origen] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
    pq.push(pair<int, string>(0, origen));

    while (!pq.empty()) {
        string u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distancias[u]) continue;

        vector<pair<string, int> >& vecinos = listaAdyacencia[u];
        for (size_t i = 0; i < vecinos.size(); ++i) {
            string v = vecinos[i].first;
            int pesoEnArista = vecinos[i].second;

            if (distancias[u] + pesoEnArista < distancias[v]) {
                distancias[v] = distancias[u] + pesoEnArista;
                predecesores[v] = u;
                pq.push(pair<int, string>(distancias[v], v));
            }
        }
    }

    if (distancias[destino] == INT_MAX) {
        cout << "RESULTADO: No existe conexion de " << origen << " a " << destino << "." << endl;
    } else {
        cout << "RESULTADO DIJKSTRA (Ruta Optima por Peso):" << endl;
        cout << " -> Costo/Peso Total: " << distancias[destino] << endl;
        
        vector<string> camino;
        string actual = destino;
        while (actual != origen) {
            camino.push_back(actual);
            actual = predecesores[actual];
        }
        camino.push_back(origen);
        reverse(camino.begin(), camino.end());

        cout << " -> Camino a seguir: (";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i];
            if (i < camino.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    }
}
