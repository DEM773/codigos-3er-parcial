#include "DiGrafo.h"

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

void Grafo::agregarRutaDirigida(string ni, string nf, string ae, int p, int t) {
    agregarNodo(ni);
    agregarNodo(nf);
    
    Ruta nuevaRuta = {ni, nf, ae, p, t};
    rutas.push_back(nuevaRuta);
    
    listaAdyacencia[ni].push_back(pair<string, int>(nf, p));
}

void Grafo::mostrarNodos() {
    cout << "\n=== NODOS DISPONIBLES EN EL DIGRAFO ===" << endl;
    if (nodos.empty()) {
        cout << "(No hay nodos registrados aun)" << endl;
    } else {
        for (size_t i = 0; i < nodos.size(); ++i) {
            cout << "[" << nodos[i] << "] ";
        }
        cout << endl;
    }
    cout << "=======================================" << endl;
}

void Grafo::mostrarRutasCargadas() {
    cout << "\n=== TABLA DE ARCOS DIRIGIDOS ===" << endl;
    cout << "Origen(ni)\tDestino(nf)\tArco(ae)\tPeso(p)\tTiempo(t)" << endl;
    cout << "--------------------------------------------------------" << endl;
    if (rutas.empty()) {
        cout << "(No hay arcos registrados aun)" << endl;
    } else {
        for (size_t i = 0; i < rutas.size(); ++i) {
            cout << rutas[i].origen << "\t\t" 
                 << rutas[i].destino << "\t\t" 
                 << rutas[i].nombreArista << "\t\t" 
                 << rutas[i].peso << "\t" 
                 << rutas[i].tiempo << endl;
        }
    }
    cout << "========================================================" << endl;
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
        cout << "RESULTADO: No existe ninguna ruta dirigida valida desde " << origen << " hacia " << destino << "." << endl;
    } else {
        cout << "RESULTADO DIJKSTRA (Ruta Optima Dirigida por Peso):" << endl;
        cout << " -> Costo/Peso Total: " << distancias[destino] << endl;
        
        vector<string> camino;
        string actual = destino;
        while (actual != origen) {
            camino.push_back(actual);
            actual = predecesores[actual];
        }
        camino.push_back(origen);
        reverse(camino.begin(), camino.end());

        cout << " -> Sentido de la ruta: ";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i];
            if (i < camino.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
}

void Grafo::archivos() {
    if (nodos.empty()) return;

    ofstream txt("grafo.txt");
    txt << "SISTEMA DE DIGRAFOS (RUTAS DIRIGIDAS)" << endl << endl;
    txt << "Nodos Registrados:" << endl;
    for (size_t i = 0; i < nodos.size(); ++i) {
        txt << "- " << nodos[i] << endl;
    }
    txt << endl << "Tabla de Arcos Dirigidos:" << endl;
    for (size_t i = 0; i < rutas.size(); ++i) {
        txt << "Arco " << rutas[i].nombreArista << ": " << rutas[i].origen << " -> " << rutas[i].destino << " [Peso: " << rutas[i].peso << ", Tiempo: " << rutas[i].tiempo << "]" << endl;
    }
    txt.close();

    ofstream csv("grafo.csv");
    csv << "Origen,Destino,Arco,Peso,Tiempo" << endl;
    for (size_t i = 0; i < rutas.size(); ++i) {
        csv << rutas[i].origen << "," << rutas[i].destino << "," << rutas[i].nombreArista << "," << rutas[i].peso << "," << rutas[i].tiempo << endl;
    }
    csv.close();

    ofstream xml("grafo.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<sistema_grafos>" << endl;
    xml << "    <nodos_registrados>" << endl;
    for (size_t i = 0; i < nodos.size(); ++i) {
        xml << "        <nodo>" << nodos[i] << "</nodo>" << endl;
    }
    xml << "    </nodos_registrados>" << endl;
    xml << "    <arcos_dirigidos>" << endl;
    for (size_t i = 0; i < rutas.size(); ++i) {
        xml << "        <arco>" << endl;
        xml << "            <nombre>" << rutas[i].nombreArista << "</nombre>" << endl;
        xml << "            <origen>" << rutas[i].origen << "</origen>" << endl;
        xml << "            <destino>" << rutas[i].destino << "</destino>" << endl;
        xml << "            <peso>" << rutas[i].peso << "</peso>" << endl;
        xml << "            <tiempo>" << rutas[i].tiempo << "</tiempo>" << endl;
        xml << "        </arco>" << endl;
    }
    xml << "    </arcos_dirigidos>" << endl;
    xml << "</sistema_grafos>" << endl;
    xml.close();

    ofstream json("grafo.json");
    json << "{" << endl;
    json << "    \"nodos\": [" << endl;
    for (size_t i = 0; i < nodos.size(); ++i) {
        json << "        \"" << nodos[i] << "\"";
        if (i < nodos.size() - 1) json << ",";
        json << endl;
    }
    json << "    ]," << endl;
    json << "    \"arcos\": [" << endl;
    for (size_t i = 0; i < rutas.size(); ++i) {
        json << "        {" << endl;
        json << "            \"arco\": \"" << rutas[i].nombreArista << "\"," << endl;
        json << "            \"origen\": \"" << rutas[i].origen << "\"," << endl;
        json << "            \"destino\": \"" << rutas[i].destino << "\"," << endl;
        json << "            \"peso\": " << rutas[i].peso << "," << endl;
        json << "            \"tiempo\": " << rutas[i].tiempo << endl;
        json << "        }";
        if (i < rutas.size() - 1) json << ",";
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    ofstream html("grafo.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Sistema de Digrafos</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;} th{background-color:#e6f2ff;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Tabla de Arcos y Caminos Dirigidos</h2>" << endl;
    html << "  <table>\n    <tr><th>Origen (ni)</th><th>Destino (nf)</th><th>Arco (ae)</th><th>Peso (p)</th><th>Tiempo (t)</th></tr>" << endl;
    for (size_t i = 0; i < rutas.size(); ++i) {
        html << "    <tr><td>" << rutas[i].origen << "</td><td>" << rutas[i].destino << "</td><td>" << rutas[i].nombreArista << "</td><td>" << rutas[i].peso << "</td><td>" << rutas[i].tiempo << "</td></tr>" << endl;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_grafo.txt");
    general << "========================================" << endl;
    general << "      REPORTE INTEGRAL DEL DIGRAFO      " << endl;
    general << "========================================" << endl << endl;
    general << "1. NODOS DEL SISTEMA:" << endl;
    for (size_t i = 0; i < nodos.size(); ++i) {
        general << "   - " << nodos[i] << endl;
    }
    general << endl << "2. RELACIONES / MATRIZ DE ARCOS:" << endl;
    for (size_t i = 0; i < rutas.size(); ++i) {
        general << "   [" << rutas[i].nombreArista << "] de " << rutas[i].origen << " hacia " << rutas[i].destino << " -> Costo: " << rutas[i].peso << " | Duracion: " << rutas[i].tiempo << endl;
    }
    general.close();

    cout << "\n[!] Guardando matrices y abriendo archivos en sus formatos nativos..." << endl;

    system("notepad grafo.txt");
    system("cmd /c start grafo.csv");
    system("explorer grafo.html");
    system("notepad grafo.xml");
    system("notepad grafo.json");
    system("notepad resultado_grafo.txt");
}
