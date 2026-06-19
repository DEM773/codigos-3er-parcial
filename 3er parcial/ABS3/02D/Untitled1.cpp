#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Conexion {
    string origen;
    string destino;
    string nombre;
    int tiempo;
    double costo;
};

vector<Conexion> conexiones;
string archivoActual = "rutas_digrafo.xml";

void mostrarMenu();
void agregarConexion();
void mostrarRutas();
void calcularRutaCorta();
void guardarXML();
void cargarXML();
void graficar();
void abrirXML();

vector<string> obtenerNodos();
int buscarNodo(vector<string> nodos, string nombre);
string extraerDato(string linea, string inicio, string fin);
int convertirEntero(string texto);
double convertirDecimal(string texto);

string agregarExtensionXML(string nombre);
void registrarArchivoXML(string nombre);

int main() {
    int opcion;

    do {
        mostrarMenu();

        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                agregarConexion();
                break;

            case 2:
                mostrarRutas();
                break;

            case 3:
                calcularRutaCorta();
                break;

            case 4:
                guardarXML();
                abrirXML();
                break;

            case 5:
                cargarXML();
                break;

            case 6:
                graficar();
                break;

            case 7:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion incorrecta.\n";
        }

    } while (opcion != 7);

    return 0;
}

void mostrarMenu() {
    cout << "\n====================================\n";
    cout << "     SISTEMA DE DIGRAFO DE RUTAS\n";
    cout << "====================================\n";
    cout << "1. Agregar una conexion con ida y vuelta\n";
    cout << "2. Mostrar todas las rutas\n";
    cout << "3. Calcular ruta mas corta\n";
    cout << "4. Guardar datos en XML\n";
    cout << "5. Cargar datos desde XML\n";
    cout << "6. Graficar (Generar Digrafo)\n";
    cout << "7. Salir\n";
    cout << "====================================\n";
}

void agregarConexion() {
    Conexion ida, vuelta;

    cout << "\nNUEVA CONEXION CON IDA Y VUELTA\n";

    cout << "Nodo de Origen: ";
    getline(cin, ida.origen);

    cout << "Nodo de Destino: ";
    getline(cin, ida.destino);

    cout << "Nombre de la Conexion: ";
    getline(cin, ida.nombre);

    cout << "Tiempo estimado: ";
    cin >> ida.tiempo;

    cout << "Costo de la ruta: ";
    cin >> ida.costo;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    conexiones.push_back(ida);

    vuelta.origen = ida.destino;
    vuelta.destino = ida.origen;
    vuelta.nombre = ida.nombre + " (Vuelta)";
    vuelta.tiempo = ida.tiempo;
    vuelta.costo = ida.costo;

    conexiones.push_back(vuelta);

    cout << "\nConexion de ida y vuelta creada exitosamente.\n";
}

void mostrarRutas() {
    size_t i;

    if (conexiones.empty()) {
        cout << "\nNo existen conexiones registradas.\n";
        return;
    }

    cout << "\nTODAS LAS RUTAS REGISTRADAS\n";

    for (i = 0; i < conexiones.size(); i++) {
        cout << "\nConexion #" << i + 1 << endl;
        cout << "Origen -> Destino: " << conexiones[i].origen << " -> " << conexiones[i].destino << endl;
        cout << "Nombre: " << conexiones[i].nombre << endl;
        cout << "Tiempo: " << conexiones[i].tiempo << " minutos" << endl;
        cout << "Costo: $" << conexiones[i].costo << endl;
    }
}

vector<string> obtenerNodos() {
    vector<string> nodos;
    size_t i;

    for (i = 0; i < conexiones.size(); i++) {
        if (find(nodos.begin(), nodos.end(), conexiones[i].origen) == nodos.end()) {
            nodos.push_back(conexiones[i].origen);
        }

        if (find(nodos.begin(), nodos.end(), conexiones[i].destino) == nodos.end()) {
            nodos.push_back(conexiones[i].destino);
        }
    }

    return nodos;
}

int buscarNodo(vector<string> nodos, string nombre) {
    size_t i;

    for (i = 0; i < nodos.size(); i++) {
        if (nodos[i] == nombre) {
            return i;
        }
    }

    return -1;
}

void calcularRutaCorta() {
    string origen;
    string destino;

    vector<string> nodos;
    vector<int> distancia;
    vector<int> anterior;
    vector<bool> visitado;
    vector<int> recorrido;

    int inicio, final, cantidad, infinito;
    int i, j, nodoActual, vecino, nodo;

    if (conexiones.empty()) {
        cout << "\nNo hay rutas registradas.\n";
        return;
    }

    cout << "\nCALCULAR RUTA MAS CORTA\n";
    cout << "Nodo de origen: ";
    getline(cin, origen);

    cout << "Nodo de destino: ";
    getline(cin, destino);

    nodos = obtenerNodos();

    inicio = buscarNodo(nodos, origen);
    final = buscarNodo(nodos, destino);

    if (inicio == -1 || final == -1) {
        cout << "\nUno de los nodos no existe.\n";
        return;
    }

    cantidad = nodos.size();
    infinito = numeric_limits<int>::max();

    distancia.resize(cantidad, infinito);
    anterior.resize(cantidad, -1);
    visitado.resize(cantidad, false);

    distancia[inicio] = 0;

    for (i = 0; i < cantidad; i++) {
        nodoActual = -1;

        for (j = 0; j < cantidad; j++) {
            if (!visitado[j]) {
                if (nodoActual == -1 || distancia[j] < distancia[nodoActual]) {
                    nodoActual = j;
                }
            }
        }

        if (nodoActual == -1 || distancia[nodoActual] == infinito) {
            break;
        }

        visitado[nodoActual] = true;

        for (j = 0; j < (int)conexiones.size(); j++) {
            if (conexiones[j].origen == nodos[nodoActual]) {
                vecino = buscarNodo(nodos, conexiones[j].destino);

                if (vecino != -1) {
                    if (distancia[nodoActual] + conexiones[j].tiempo < distancia[vecino]) {
                        distancia[vecino] = distancia[nodoActual] + conexiones[j].tiempo;
                        anterior[vecino] = nodoActual;
                    }
                }
            }
        }
    }

    if (distancia[final] == infinito) {
        cout << "\nNo existe una ruta valida entre esos nodos.\n";
        return;
    }

    nodo = final;
    while (nodo != -1) {
        recorrido.push_back(nodo);
        nodo = anterior[nodo];
    }

    reverse(recorrido.begin(), recorrido.end());

    cout << "\nRUTA MAS CORTA ENCONTRADA\n";
    cout << "Recorrido: ";

    for (i = 0; i < (int)recorrido.size(); i++) {
        cout << nodos[recorrido[i]];
        if (i < (int)recorrido.size() - 1) {
            cout << " -> ";
        }
    }

    double costoTotal = 0.0;

    for (i = 0; i < (int)recorrido.size() - 1; i++) {
        string u = nodos[recorrido[i]];
        string v = nodos[recorrido[i + 1]];

        for (j = 0; j < (int)conexiones.size(); j++) {
            if (conexiones[j].origen == u && conexiones[j].destino == v) {
                costoTotal += conexiones[j].costo;
                break;
            }
        }
    }

    cout << "\nTiempo total: " << distancia[final] << " minutos\n";
    cout << "Precio total: $" << costoTotal << "\n";
}

string agregarExtensionXML(string nombre) {
    if (nombre.length() < 4) {
        nombre = nombre + ".xml";
    } else {
        string extension = nombre.substr(nombre.length() - 4);
        if (extension != ".xml") {
            nombre = nombre + ".xml";
        }
    }
    return nombre;
}

void registrarArchivoXML(string nombre) {
    ifstream lectura("lista_xml.txt");
    string archivo;
    bool encontrado = false;

    while (getline(lectura, archivo)) {
        if (archivo == nombre) {
            encontrado = true;
        }
    }
    lectura.close();

    if (!encontrado) {
        ofstream escritura("lista_xml.txt", ios::app);
        escritura << nombre << endl;
        escritura.close();
    }
}

void guardarXML() {
    string nombre;
    cout << "\nNombre del digrafo para guardar: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        nombre = "digrafo_rutas";
    }

    nombre = agregarExtensionXML(nombre);
    archivoActual = nombre;

    ofstream archivo(archivoActual.c_str());
    size_t i;

    if (!archivo.is_open()) {
        cout << "\nNo se pudo crear el archivo XML.\n";
        return;
    }

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    archivo << "<sistemaRutas>\n";

    for (i = 0; i < conexiones.size(); i++) {
        archivo << "<conexion>\n";
        archivo << "<origen>" << conexiones[i].origen << "</origen>\n";
        archivo << "<destino>" << conexiones[i].destino << "</destino>\n";
        archivo << "<nombre>" << conexiones[i].nombre << "</nombre>\n";
        archivo << "<tiempo>" << conexiones[i].tiempo << "</tiempo>\n";
        archivo << "<costo>" << conexiones[i].costo << "</costo>\n";
        archivo << "</conexion>\n";
    }

    archivo << "</sistemaRutas>\n";
    archivo.close();

    registrarArchivoXML(archivoActual);

    cout << "\nDatos guardados correctamente en " << archivoActual << endl;
}

void abrirXML() {
#ifdef _WIN32
    string comando = "start notepad \"" + archivoActual + "\"";
    system(comando.c_str());
#elif __APPLE__
    string comando = "open -t \"" + archivoActual + "\"";
    system(comando.c_str());
#else
    string comando = "xdg-open \"" + archivoActual + "\"";
    system(comando.c_str());
#endif
}

string extraerDato(string linea, string inicio, string fin) {
    size_t posicionInicio = linea.find(inicio);
    size_t posicionFin = linea.find(fin);

    if (posicionInicio == string::npos || posicionFin == string::npos) {
        return "";
    }

    posicionInicio += inicio.length();
    return linea.substr(posicionInicio, posicionFin - posicionInicio);
}

int convertirEntero(string texto) {
    stringstream convertir;
    int numero = 0;
    convertir << texto;
    convertir >> numero;
    return numero;
}

double convertirDecimal(string texto) {
    stringstream convertir;
    double numero = 0.0;
    convertir << texto;
    convertir >> numero;
    return numero;
}

void cargarXML() {
    ifstream lista("lista_xml.txt");
    vector<string> archivos;
    string nombre;
    int opcion;
    int contador = 1;

    cout << "\nARCHIVOS XML GUARDADOS\n";

    if (!lista.is_open()) {
        cout << "No hay archivos XML guardados.\n";
        return;
    }

    while (getline(lista, nombre)) {
        if (!nombre.empty()) {
            archivos.push_back(nombre);
            cout << contador << ". " << nombre << endl;
            contador++;
        }
    }

    lista.close();

    if (archivos.empty()) {
        cout << "\nNo hay archivos XML guardados.\n";
        return;
    }

    cout << "\nEscoge el numero del grafo que quieres abrir: ";
    cin >> opcion;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (opcion < 1 || opcion > (int)archivos.size()) {
        cout << "\nOpcion incorrecta.\n";
        return;
    }

    archivoActual = archivos[opcion - 1];

    ifstream archivo(archivoActual.c_str());

    string linea, dato;
    Conexion nueva;

    if (!archivo.is_open()) {
        cout << "\nNo se encontro el archivo " << archivoActual << endl;
        return;
    }

    conexiones.clear();

    while (getline(archivo, linea)) {
        if (linea.find("<conexion>") != string::npos) {
            nueva.origen = "";
            nueva.destino = "";
            nueva.nombre = "";
            nueva.tiempo = 0;
            nueva.costo = 0.0;
        }

        if (linea.find("<origen>") != string::npos) {
            nueva.origen = extraerDato(linea, "<origen>", "</origen>");
        }

        if (linea.find("<destino>") != string::npos) {
            nueva.destino = extraerDato(linea, "<destino>", "</destino>");
        }

        if (linea.find("<nombre>") != string::npos) {
            nueva.nombre = extraerDato(linea, "<nombre>", "</nombre>");
        }

        if (linea.find("<tiempo>") != string::npos) {
            dato = extraerDato(linea, "<tiempo>", "</tiempo>");
            nueva.tiempo = convertirEntero(dato);
        }

        if (linea.find("<costo>") != string::npos) {
            dato = extraerDato(linea, "<costo>", "</costo>");
            nueva.costo = convertirDecimal(dato);
        }

        if (linea.find("</conexion>") != string::npos) {
            conexiones.push_back(nueva);
        }
    }

    archivo.close();

    cout << "\nDatos cargados correctamente desde " << archivoActual << endl;
    cout << "Conexiones cargadas: " << conexiones.size() << endl;

    abrirXML();
}

void graficar() {
    ofstream archivo("grafica.dot");
    size_t i;

    if (conexiones.empty()) {
        cout << "\nNo existen conexiones para graficar.\n";
        return;
    }

    if (!archivo.is_open()) {
        cout << "\nNo se pudo crear la grafica.\n";
        return;
    }

    archivo << "digraph SistemaRutasDirigidas {\n";
    archivo << "    rankdir=LR;\n";
    archivo << "    node [shape=circle];\n";

    for (i = 0; i < conexiones.size(); i++) {
        archivo << "    \"" << conexiones[i].origen << "\" -> \"" << conexiones[i].destino
                << "\" [label=\"" << conexiones[i].nombre
                << " T: " << conexiones[i].tiempo
                << " C: $" << conexiones[i].costo << "\"];\n";
    }

    archivo << "}\n";
    archivo.close();

    cout << "\nGrafica del Digrafo guardada en grafica.dot\n";

#ifdef _WIN32
    system("start notepad grafica.dot");
#elif __APPLE__
    system("open -t grafica.dot");
#else
    system("xdg-open grafica.dot");
#endif
}
