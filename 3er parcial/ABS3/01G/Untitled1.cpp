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

string archivoActual = "rutas.xml";

void mostrarMenu();
void agregarConexion();
void mostrarRutas();
void calcularRutaCorta();
void guardarXML();
void cargarXML();
void graficar();
void abrirXML();

vector<string> obtenerNodos();

int buscarNodo(
    vector<string> nodos,
    string nombre
);

string extraerDato(
    string linea,
    string inicio,
    string fin
);

int convertirEntero(string texto);
double convertirDecimal(string texto);

// Funciones para manejar varios XML
string agregarExtensionXML(string nombre);
void registrarArchivoXML(string nombre);
void mostrarArchivosXML();

int main() {
    int opcion;

    do {
        mostrarMenu();

        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

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
    cout << "        SISTEMA DE RUTAS (TDA)\n";
    cout << "====================================\n";
    cout << "1. Agregar una conexion (Arista)\n";
    cout << "2. Mostrar todas las rutas\n";
    cout << "3. Calcular ruta mas corta (Dijkstra)\n";
    cout << "4. Guardar datos en XML\n";
    cout << "5. Cargar datos desde XML\n";
    cout << "6. Graficar\n";
    cout << "7. Salir\n";
    cout << "====================================\n";
}

void agregarConexion() {
    Conexion nueva;

    cout << "\nNUEVA CONEXION\n";

    cout << "Nodo de Origen: ";
    getline(cin, nueva.origen);

    cout << "Nodo de Destino: ";
    getline(cin, nueva.destino);

    cout << "Nombre de la Conexion (Arista): ";
    getline(cin, nueva.nombre);

    cout << "Tiempo estimado: ";
    cin >> nueva.tiempo;

    cout << "Costo de la ruta: ";
    cin >> nueva.costo;

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    conexiones.push_back(nueva);

    cout << "\nConexion creada exitosamente.\n";
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

        cout << "Origen: "
             << conexiones[i].origen
             << endl;

        cout << "Destino: "
             << conexiones[i].destino
             << endl;

        cout << "Nombre: "
             << conexiones[i].nombre
             << endl;

        cout << "Tiempo: "
             << conexiones[i].tiempo
             << " minutos"
             << endl;

        cout << "Costo: $"
             << conexiones[i].costo
             << endl;
    }
}

vector<string> obtenerNodos() {
    vector<string> nodos;
    size_t i;

    for (i = 0; i < conexiones.size(); i++) {

        if (
            find(
                nodos.begin(),
                nodos.end(),
                conexiones[i].origen
            ) == nodos.end()
        ) {
            nodos.push_back(
                conexiones[i].origen
            );
        }

        if (
            find(
                nodos.begin(),
                nodos.end(),
                conexiones[i].destino
            ) == nodos.end()
        ) {
            nodos.push_back(
                conexiones[i].destino
            );
        }
    }

    return nodos;
}

int buscarNodo(
    vector<string> nodos,
    string nombre
) {
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

    int inicio;
    int final;
    int cantidad;
    int infinito;
    int i;
    int j;
    int nodoActual;
    int vecino;
    int nodo;

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
                if (
                    nodoActual == -1 ||
                    distancia[j] <
                    distancia[nodoActual]
                ) {
                    nodoActual = j;
                }
            }
        }

        if (nodoActual == -1) {
            break;
        }

        if (distancia[nodoActual] == infinito) {
            break;
        }

        visitado[nodoActual] = true;

        for (
            j = 0;
            j < (int)conexiones.size();
            j++
        ) {
            vecino = -1;

            if (
                conexiones[j].origen ==
                nodos[nodoActual]
            ) {
                vecino = buscarNodo(
                    nodos,
                    conexiones[j].destino
                );

            } else if (
                conexiones[j].destino ==
                nodos[nodoActual]
            ) {
                vecino = buscarNodo(
                    nodos,
                    conexiones[j].origen
                );
            }

            if (vecino != -1) {
                if (
                    distancia[nodoActual] +
                    conexiones[j].tiempo <
                    distancia[vecino]
                ) {
                    distancia[vecino] =
                        distancia[nodoActual] +
                        conexiones[j].tiempo;

                    anterior[vecino] =
                        nodoActual;
                }
            }
        }
    }

    if (distancia[final] == infinito) {
        cout << "\nNo existe una ruta entre esos nodos.\n";
        return;
    }

    nodo = final;

    while (nodo != -1) {
        recorrido.push_back(nodo);
        nodo = anterior[nodo];
    }

    reverse(
        recorrido.begin(),
        recorrido.end()
    );

    cout << "\nRUTA MAS CORTA\n";
    cout << "Recorrido: ";

    for (
        i = 0;
        i < (int)recorrido.size();
        i++
    ) {
        cout << nodos[recorrido[i]];

        if (
            i <
            (int)recorrido.size() - 1
        ) {
            cout << " -> ";
        }
    }

    // Cálculo del precio acumulado de la ruta final
    double costoTotal = 0.0;
    for (i = 0; i < (int)recorrido.size() - 1; i++) {
        string u = nodos[recorrido[i]];
        string v = nodos[recorrido[i + 1]];
        
        for (j = 0; j < (int)conexiones.size(); j++) {
            if ((conexiones[j].origen == u && conexiones[j].destino == v) ||
                (conexiones[j].destino == u && conexiones[j].origen == v)) {
                costoTotal += conexiones[j].costo;
                break; 
            }
        }
    }

    cout << "\nTiempo total: "
         << distancia[final]
         << " minutos\n";

    cout << "Precio total: $" 
         << costoTotal 
         << "\n";
}

string agregarExtensionXML(string nombre) {
    if (nombre.length() < 4) {
        nombre = nombre + ".xml";
    } else {
        string extension =
            nombre.substr(
                nombre.length() - 4
            );

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
        ofstream escritura(
            "lista_xml.txt",
            ios::app
        );

        escritura << nombre << endl; 
        escritura.close();
    }
}

void mostrarArchivosXML() {
    ifstream archivo("lista_xml.txt");

    string nameFile;
    int numero = 1;
    bool hayArchivos = false;

    cout << "\nARCHIVOS XML GUARDADOS\n";

    if (!archivo.is_open()) {
        cout << "No hay archivos XML guardados.\n";
        return;
    }

    while (getline(archivo, nameFile)) {
        if (!nameFile.empty()) {
            cout << numero
                 << ". "
                 << nameFile
                 << endl;

            numero++;
            hayArchivos = true;
        }
    }

    archivo.close();

    if (!hayArchivos) {
        cout << "No hay archivos XML guardados.\n";
    }
}

void guardarXML() {
    string nombre;

    cout << "\nNombre del grafo para guardar: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        nombre = "rutas";
    }

    nombre = agregarExtensionXML(nombre);
    archivoActual = nombre;

    ofstream archivo(
        archivoActual.c_str()
    );

    size_t i;

    if (!archivo.is_open()) {
        cout << "\nNo se pudo crear el archivo XML.\n";
        return;
    }

    archivo << "<?xml version=\"1.0\" "
            << "encoding=\"UTF-8\"?>"
            << endl;

    archivo << "<sistemaRutas>"
            << endl;

    for (i = 0; i < conexiones.size(); i++) {
        archivo << "<conexion>"
                << endl;

        archivo << "<origen>"
                << conexiones[i].origen
                << "</origen>"
                << endl;

        archivo << "<destino>"
                << conexiones[i].destino
                << "</destino>"
                << endl;

        archivo << "<nombre>"
                << conexiones[i].nombre
                << "</nombre>"
                << endl;

        archivo << "<tiempo>"
                << conexiones[i].tiempo
                << "</tiempo>"
                << endl;

        archivo << "<costo>"
                << conexiones[i].costo
                << "</costo>"
                << endl;

        archivo << "</conexion>"
                << endl;
    }

    archivo << "</sistemaRutas>"
            << endl;

    archivo.close();

    registrarArchivoXML(archivoActual);

    cout << "\nDatos guardados correctamente en "
         << archivoActual
         << endl;
}

void abrirXML() {
#ifdef _WIN32
    // CORREGIDO: Cadena de comando limpia y segura para Windows sin conflictos de comillas
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

string extraerDato(
    string linea,
    string inicio,
    string fin
) {
    size_t posicionInicio;
    size_t posicionFin;

    posicionInicio =
        linea.find(inicio);

    posicionFin =
        linea.find(fin);

    if (
        posicionInicio == string::npos ||
        posicionFin == string::npos
    ) {
        return "";
    }

    posicionInicio =
        posicionInicio +
        inicio.length();

    return linea.substr(
        posicionInicio,
        posicionFin - posicionInicio
    );
}

int convertirEntero(string texto) {
    stringstream convertir;
    int numero;

    convertir << texto;
    convertir >> numero;

    return numero;
}

double convertirDecimal(string texto) {
    stringstream convertir;
    double numero;

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

    // CORREGIDO: Se eliminó por completo el "name =" erróneo que causaba el fallo en la impresión
    while (getline(lista, nombre)) {
        if (!nombre.empty()) {
            archivos.push_back(nombre);

            cout << contador
                 << ". "
                 << nombre
                 << endl;

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

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    if (
        opcion < 1 ||
        opcion > (int)archivos.size()
    ) {
        cout << "\nOpcion incorrecta.\n";
        return;
    }

    archivoActual =
        archivos[opcion - 1];

    ifstream archivo(
        archivoActual.c_str()
    );

    string linea;
    string dato;
    Conexion nueva;

    if (!archivo.is_open()) {
        cout << "\nNo se encontro el archivo "
             << archivoActual
             << endl;

        return;
    }

    conexiones.clear();

    while (getline(archivo, linea)) {

        if (
            linea.find("<conexion>") !=
            string::npos
        ) {
            nueva.origen = "";
            nueva.destino = "";
            nueva.nombre = "";
            nueva.tiempo = 0;
            nueva.costo = 0.0;
        }

        if (
            linea.find("<origen>") !=
            string::npos
        ) {
            nueva.origen =
                extraerDato(
                    linea,
                    "<origen>",
                    "</origen>"
                );
        }

        if (
            linea.find("<destino>") !=
            string::npos
        ) {
            nueva.destino =
                extraerDato(
                    linea,
                    "<destino>",
                    "</destino>"
                );
        }

        if (
            linea.find("<nombre>") !=
            string::npos
        ) {
            nueva.nombre =
                extraerDato(
                    linea,
                    "<nombre>",
                    "</nombre>"
                );
        }

        if (
            linea.find("<tiempo>") !=
            string::npos
        ) {
            dato =
                extraerDato(
                    linea,
                    "<tiempo>",
                    "</tiempo>"
                );

            nueva.tiempo =
                convertirEntero(dato);
        }

        if (
            linea.find("<costo>") !=
            string::npos
        ) {
            dato =
                extraerDato(
                    linea,
                    "<costo>",
                    "</costo>"
                );

            nueva.costo =
                convertirDecimal(dato);
        }

        if (
            linea.find("</conexion>") !=
            string::npos
        ) {
            conexiones.push_back(nueva);
        }
    }

    archivo.close();

    cout << "\nDatos cargados correctamente desde "
         << archivoActual
         << endl;

    cout << "Conexiones cargadas: "
         << conexiones.size()
         << endl;

    // Ejecuta de forma automática el Bloc de notas tras cargar con éxito el XML
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

    archivo << "graph SistemaRutas {"
            << endl;

    archivo << "    rankdir=LR;"
            << endl;

    archivo << "    node [shape=circle];"
            << endl;

    for (i = 0; i < conexiones.size(); i++) {
        archivo << "    \""
                << conexiones[i].origen
                << "\" -- \""
                << conexiones[i].destino
                << "\" [label=\""
                << conexiones[i].nombre
                << " Tiempo: "
                << conexiones[i].tiempo
                << " Costo: $"
                << conexiones[i].costo
                << "\"];"
                << endl;
    }

    archivo << "}"
            << endl;

    archivo.close();

    cout << "\nGrafica guardada en grafica.dot\n";

#ifdef _WIN32

    system("start notepad grafica.dot");

#elif __APPLE__

    system("open -t grafica.dot");

#else

    system("xdg-open grafica.dot");

#endif
}
