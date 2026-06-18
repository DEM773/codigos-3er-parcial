#include "Grafo.h"

void Grafo::agregarNodo(string nodo) {
    bool existe = false;
    for (size_t i = 0; i < nodos.size(); ++i) {
        if (nodos[i] == nodo) { existe = true; break; }
    }
    if (!existe) nodos.push_back(nodo);
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
    if (nodos.empty()) { cout << "(No hay nodos)" << endl; } 
    else {
        for (size_t i = 0; i < nodos.size(); ++i) cout << "[" << nodos[i] << "] ";
        cout << endl;
    }
}

void Grafo::mostrarRutasCargadas() {
    cout << "\n=== TABLA DE RUTAS ===" << endl;
    cout << "ni\tnf\tae\tp\tt" << endl;
    if (rutas.empty()) { cout << "(No hay rutas)" << endl; } 
    else {
        for (size_t i = 0; i < rutas.size(); ++i) {
            cout << rutas[i].origen << "\t" << rutas[i].destino << "\t" 
                 << rutas[i].nombreArista << "\t" << rutas[i].peso << "\t" << rutas[i].tiempo << endl;
        }
    }
}

void Grafo::contarTodasLasRutas(string actual, string destino, map<string, bool>& visitado, int& contador) {
    if (actual == destino) { contador++; return; }
    visitado[actual] = true;
    vector<pair<string, int> >& vecinos = listaAdyacencia[actual];
    for (size_t i = 0; i < vecinos.size(); ++i) {
        string sig = vecinos[i].first;
        if (!visitado[sig]) contarTodasLasRutas(sig, destino, visitado, contador);
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
    for (size_t i = 0; i < nodos.size(); ++i) distancias[nodos[i]] = INT_MAX;
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
            int pesoArista = vecinos[i].second;
            if (distancias[u] + pesoArista < distancias[v]) {
                distancias[v] = distancias[u] + pesoArista;
                predecesores[v] = u;
                pq.push(pair<int, string>(distancias[v], v));
            }
        }
    }

    if (distancias[destino] == INT_MAX) {
        cout << "RESULTADO: No existe conexion." << endl;
    } else {
        cout << "RESULTADO DIJKSTRA:\n -> Costo Total: " << distancias[destino] << endl;
        vector<string> camino;
        string actual = destino;
        while (actual != origen) { camino.push_back(actual); actual = predecesores[actual]; }
        camino.push_back(origen);
        reverse(camino.begin(), camino.end());
        cout << " -> Camino: (";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i]; if (i < camino.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    }
}

void Grafo::archivos() {
    if (nodos.empty()) return;

    ofstream txt("grafo_app.txt");
    txt << "REPORTES DE GRAFOS\n\nNodos:\n";
    for (size_t i = 0; i < nodos.size(); ++i) txt << "- " << nodos[i] << endl;
    txt.close();

    ofstream csv("grafo_app.csv");
    csv << "NodoInicial,NodoFinal,Arista,Peso,Tiempo\n";
    for (size_t i = 0; i < rutas.size(); ++i) {
        csv << rutas[i].origen << "," << rutas[i].destino << "," << rutas[i].nombreArista << "," << rutas[i].peso << "," << rutas[i].tiempo << "\n";
    }
    csv.close();

    ofstream xml("grafo_app.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<grafo>\n";
    for (size_t i = 0; i < rutas.size(); ++i) xml << "  <arista><origen>" << rutas[i].origen << "</origen></arista>\n";
    xml << "</grafo>\n";
    xml.close();

    ofstream json("grafo_app.json");
    json << "{\n  \"aristas\": [\n";
    for (size_t i = 0; i < rutas.size(); ++i) {
        json << "    {\"origen\": \"" << rutas[i].origen << "\"}" << (i < rutas.size() - 1 ? "," : "") << "\n";
    }
    json << "  ]\n}\n";
    json.close();

    ofstream html("grafo_app.html");
    html << "<html><body><h2>Tabla de Rutas</h2><table border='1'><tr><th>Origen</th><th>Destino</th></tr>";
    for (size_t i = 0; i < rutas.size(); ++i) {
        html << "<tr><td>" << rutas[i].origen << "</td><td>" << rutas[i].destino << "</td></tr>";
    }
    html << "</table></body></html>";
    html.close();

    ofstream general("resultado_grafo_general.txt");
    general << "====================================\n REPORTES GENERALES CONSOLIDADOS\n====================================\n";
    for (size_t i = 0; i < rutas.size(); ++i) general << "Ruta: " << rutas[i].origen << " -> " << rutas[i].destino << endl;
    general.close();

    cout << "\n[!] Abriendo reportes en formatos nativos..." << endl;
    system("notepad grafo_app.txt");
    system("cmd /c start grafo_app.csv");
    system("explorer grafo_app.html");
    system("notepad grafo_app.xml");
    system("notepad grafo_app.json");
    system("notepad resultado_grafo_general.txt");
}
