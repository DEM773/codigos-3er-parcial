#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cctype>

using namespace std;

struct Nodo {
    string nombre;
    string descripcion;

    Nodo* padre;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(string nuevoNombre, string nuevaDescripcion) {
        nombre = nuevoNombre;
        descripcion = nuevaDescripcion;

        padre = NULL;
        izquierdo = NULL;
        derecho = NULL;
    }
};

struct RegistroNodo {
    string nombre;
    string descripcion;
    string padre;
    string posicion;
    bool padreEsNulo;
};

Nodo* raiz = NULL;

string archivoActual = "arbol.json";

void mostrarMenu();

void agregarRaiz();
void agregarHijo();
void agregarPadre();

void mostrarArbol();
void mostrarEstructura(Nodo* nodo, int espacio);
void mostrarRelaciones(Nodo* nodo);

void mostrarRecorridos();
void preorden(Nodo* nodo);
void inorden(Nodo* nodo);
void postorden(Nodo* nodo);

void buscarNodoMenu();
Nodo* buscarNodo(Nodo* nodo, string nombre);

void eliminarNodoMenu();
void liberarArbol(Nodo*& nodo);

void mostrarInformacion();
int contarNodos(Nodo* nodo);
int calcularAltura(Nodo* nodo);

string agregarExtensionJSON(string nombre);
void registrarArchivoJSON(string nombre);

void guardarJSON();
void guardarRegistrosJSON(
    ofstream& archivo,
    Nodo* nodo,
    bool& primero
);

string escaparJSON(string texto);
bool obtenerCampoCadena(
    string linea,
    string clave,
    string& valor,
    bool& esNulo
);

void cargarJSON();
void abrirJSON();

int main() {
#ifdef _WIN32
    system("cls");
#endif

    int opcion;

    do {
        mostrarMenu();

        cout << "Elige una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\nDebes escribir un numero valido.\n";
            continue;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        switch (opcion) {
            case 1:
                agregarRaiz();
                break;

            case 2:
                agregarHijo();
                break;

            case 3:
                agregarPadre();
                break;

            case 4:
                mostrarArbol();
                break;

            case 5:
                mostrarRecorridos();
                break;

            case 6:
                buscarNodoMenu();
                break;

            case 7:
                eliminarNodoMenu();
                break;

            case 8:
                mostrarInformacion();
                break;

            case 9:
                guardarJSON();
                break;

            case 10:
                cargarJSON();
                break;

            case 11:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion incorrecta.\n";
        }

    } while (opcion != 11);

    liberarArbol(raiz);

    return 0;
}

void mostrarMenu() {
    cout << "\n";
    cout << "========================================\n";
    cout << "        SISTEMA DE ARBOL BINARIO\n";
    cout << "========================================\n";
    cout << "1. Agregar nodo raiz\n";
    cout << "2. Agregar hijo a un padre\n";
    cout << "3. Agregar padre a un nodo\n";
    cout << "4. Mostrar padres e hijos\n";
    cout << "5. Mostrar recorridos del arbol\n";
    cout << "6. Buscar un nodo\n";
    cout << "7. Eliminar un nodo y sus hijos\n";
    cout << "8. Consultar informacion del arbol\n";
    cout << "9. Guardar arbol en JSON\n";
    cout << "10. Cargar arbol desde JSON\n";
    cout << "11. Salir\n";
    cout << "========================================\n";
}

void agregarRaiz() {
    string nombre;
    string descripcion;

    if (raiz != NULL) {
        cout << "\nEl arbol ya tiene una raiz.\n";
        cout << "Raiz actual: " << raiz->nombre << endl;
        return;
    }

    cout << "\nAGREGAR NODO RAIZ\n";

    cout << "Nombre de la raiz: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        cout << "\nEl nombre no puede estar vacio.\n";
        return;
    }

    cout << "Descripcion de la raiz: ";
    getline(cin, descripcion);

    raiz = new Nodo(
        nombre,
        descripcion
    );

    cout << "\nLa raiz se agrego correctamente.\n";
}

Nodo* buscarNodo(
    Nodo* nodo,
    string nombre
) {
    if (nodo == NULL) {
        return NULL;
    }

    if (nodo->nombre == nombre) {
        return nodo;
    }

    Nodo* encontrado;

    encontrado = buscarNodo(
        nodo->izquierdo,
        nombre
    );

    if (encontrado != NULL) {
        return encontrado;
    }

    return buscarNodo(
        nodo->derecho,
        nombre
    );
}

void agregarHijo() {
    string nombrePadre;
    string nombreHijo;
    string descripcion;
    int posicion;

    if (raiz == NULL) {
        cout << "\nPrimero debes agregar la raiz.\n";
        return;
    }

    cout << "\nAGREGAR HIJO\n";

    cout << "Nombre del nodo padre: ";
    getline(cin, nombrePadre);

    Nodo* padre = buscarNodo(
        raiz,
        nombrePadre
    );

    if (padre == NULL) {
        cout << "\nEl nodo padre no existe.\n";
        return;
    }

    cout << "Nombre del nuevo hijo: ";
    getline(cin, nombreHijo);

    if (nombreHijo.empty()) {
        cout << "\nEl nombre no puede estar vacio.\n";
        return;
    }

    if (
        buscarNodo(
            raiz,
            nombreHijo
        ) != NULL
    ) {
        cout << "\nYa existe un nodo con ese nombre.\n";
        return;
    }

    cout << "Descripcion del nuevo hijo: ";
    getline(cin, descripcion);

    cout << "\n1. Hijo izquierdo\n";
    cout << "2. Hijo derecho\n";
    cout << "Elige la posicion: ";
    cin >> posicion;

    if (cin.fail()) {
        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        cout << "\nDebes escribir una opcion valida.\n";
        return;
    }

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    if (posicion == 1) {
        if (padre->izquierdo != NULL) {
            cout << "\nEl padre ya tiene hijo izquierdo.\n";
            cout << "Hijo actual: ";
            cout << padre->izquierdo->nombre << endl;
            return;
        }

        Nodo* nuevo = new Nodo(
            nombreHijo,
            descripcion
        );

        nuevo->padre = padre;
        padre->izquierdo = nuevo;

        cout << "\nHijo izquierdo agregado correctamente.\n";
    } else if (posicion == 2) {
        if (padre->derecho != NULL) {
            cout << "\nEl padre ya tiene hijo derecho.\n";
            cout << "Hijo actual: ";
            cout << padre->derecho->nombre << endl;
            return;
        }

        Nodo* nuevo = new Nodo(
            nombreHijo,
            descripcion
        );

        nuevo->padre = padre;
        padre->derecho = nuevo;

        cout << "\nHijo derecho agregado correctamente.\n";
    } else {
        cout << "\nOpcion incorrecta.\n";
    }
}

void agregarPadre() {
    string nombreNodo;
    string nombrePadre;
    string descripcionPadre;
    int posicion;

    if (raiz == NULL) {
        cout << "\nEl arbol esta vacio.\n";
        cout << "Primero debes agregar una raiz.\n";
        return;
    }

    cout << "\nAGREGAR PADRE A UN NODO\n";

    cout << "Nombre del nodo que recibira un padre: ";
    getline(cin, nombreNodo);

    Nodo* hijo = buscarNodo(
        raiz,
        nombreNodo
    );

    if (hijo == NULL) {
        cout << "\nEl nodo no existe.\n";
        return;
    }

    cout << "Nombre del nuevo padre: ";
    getline(cin, nombrePadre);

    if (nombrePadre.empty()) {
        cout << "\nEl nombre del padre no puede estar vacio.\n";
        return;
    }

    if (
        buscarNodo(
            raiz,
            nombrePadre
        ) != NULL
    ) {
        cout << "\nYa existe un nodo con ese nombre.\n";
        return;
    }

    cout << "Descripcion del nuevo padre: ";
    getline(cin, descripcionPadre);

    cout << "\nEl nodo " << hijo->nombre;
    cout << " sera hijo del nuevo padre.\n";
    cout << "1. Sera hijo izquierdo\n";
    cout << "2. Sera hijo derecho\n";
    cout << "Elige la posicion: ";
    cin >> posicion;

    if (cin.fail()) {
        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        cout << "\nDebes escribir una opcion valida.\n";
        return;
    }

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    if (
        posicion != 1 &&
        posicion != 2
    ) {
        cout << "\nOpcion incorrecta.\n";
        return;
    }

    Nodo* padreAnterior = hijo->padre;

    Nodo* nuevoPadre = new Nodo(
        nombrePadre,
        descripcionPadre
    );

    nuevoPadre->padre = padreAnterior;

    if (posicion == 1) {
        nuevoPadre->izquierdo = hijo;
    } else {
        nuevoPadre->derecho = hijo;
    }

    hijo->padre = nuevoPadre;

    if (padreAnterior == NULL) {
        raiz = nuevoPadre;

        cout << "\nEl nuevo padre se convirtio";
        cout << " en la raiz del arbol.\n";
    } else {
        if (
            padreAnterior->izquierdo ==
            hijo
        ) {
            padreAnterior->izquierdo =
                nuevoPadre;
        } else if (
            padreAnterior->derecho ==
            hijo
        ) {
            padreAnterior->derecho =
                nuevoPadre;
        }

        cout << "\nEl nuevo padre fue agregado";
        cout << " correctamente.\n";
    }

    cout << "Nuevo padre: ";
    cout << nuevoPadre->nombre << endl;

    cout << "Nodo hijo: ";
    cout << hijo->nombre << endl;

    if (posicion == 1) {
        cout << "Posicion del hijo: Izquierda\n";
    } else {
        cout << "Posicion del hijo: Derecha\n";
    }
}

void mostrarEstructura(
    Nodo* nodo,
    int espacio
) {
    if (nodo == NULL) {
        return;
    }

    espacio += 8;

    mostrarEstructura(
        nodo->derecho,
        espacio
    );

    cout << endl;

    for (
        int i = 8;
        i < espacio;
        i++
    ) {
        cout << " ";
    }

    cout << nodo->nombre << endl;

    mostrarEstructura(
        nodo->izquierdo,
        espacio
    );
}

void mostrarRelaciones(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    cout << "\n----------------------------------------\n";
    cout << "Nodo: " << nodo->nombre << endl;

    cout << "Descripcion: ";

    if (nodo->descripcion.empty()) {
        cout << "Sin descripcion\n";
    } else {
        cout << nodo->descripcion << endl;
    }

    if (nodo->padre == NULL) {
        cout << "Padre: No tiene, es la raiz\n";
    } else {
        cout << "Padre: ";
        cout << nodo->padre->nombre << endl;
    }

    if (nodo->izquierdo == NULL) {
        cout << "Hijo izquierdo: No tiene\n";
    } else {
        cout << "Hijo izquierdo: ";
        cout << nodo->izquierdo->nombre << endl;
    }

    if (nodo->derecho == NULL) {
        cout << "Hijo derecho: No tiene\n";
    } else {
        cout << "Hijo derecho: ";
        cout << nodo->derecho->nombre << endl;
    }

    mostrarRelaciones(
        nodo->izquierdo
    );

    mostrarRelaciones(
        nodo->derecho
    );
}

void mostrarArbol() {
    if (raiz == NULL) {
        cout << "\nEl arbol esta vacio.\n";
        return;
    }

    cout << "\nESTRUCTURA DEL ARBOL\n";
    cout << "El hijo derecho aparece arriba";
    cout << " y el izquierdo abajo.\n";

    mostrarEstructura(
        raiz,
        0
    );

    cout << "\n";
    cout << "========================================\n";
    cout << "RELACIONES ENTRE PADRES E HIJOS\n";
    cout << "========================================\n";

    mostrarRelaciones(raiz);
}

void preorden(Nodo* nodo) {
    if (nodo != NULL) {
        cout << nodo->nombre << " ";

        preorden(
            nodo->izquierdo
        );

        preorden(
            nodo->derecho
        );
    }
}

void inorden(Nodo* nodo) {
    if (nodo != NULL) {
        inorden(
            nodo->izquierdo
        );

        cout << nodo->nombre << " ";

        inorden(
            nodo->derecho
        );
    }
}

void postorden(Nodo* nodo) {
    if (nodo != NULL) {
        postorden(
            nodo->izquierdo
        );

        postorden(
            nodo->derecho
        );

        cout << nodo->nombre << " ";
    }
}

void mostrarRecorridos() {
    if (raiz == NULL) {
        cout << "\nEl arbol esta vacio.\n";
        return;
    }

    cout << "\nRECORRIDOS DEL ARBOL\n";

    cout << "Preorden: ";
    preorden(raiz);
    cout << endl;

    cout << "Inorden: ";
    inorden(raiz);
    cout << endl;

    cout << "Postorden: ";
    postorden(raiz);
    cout << endl;
}

void buscarNodoMenu() {
    string nombre;

    if (raiz == NULL) {
        cout << "\nEl arbol esta vacio.\n";
        return;
    }

    cout << "\nBUSCAR UN NODO\n";
    cout << "Nombre del nodo: ";
    getline(cin, nombre);

    Nodo* encontrado = buscarNodo(
        raiz,
        nombre
    );

    if (encontrado == NULL) {
        cout << "\nEl nodo no existe.\n";
        return;
    }

    cout << "\nNODO ENCONTRADO\n";
    cout << "Nombre: ";
    cout << encontrado->nombre << endl;

    cout << "Descripcion: ";

    if (encontrado->descripcion.empty()) {
        cout << "Sin descripcion\n";
    } else {
        cout << encontrado->descripcion << endl;
    }

    if (encontrado->padre == NULL) {
        cout << "Padre: No tiene, es la raiz\n";
    } else {
        cout << "Padre: ";
        cout << encontrado->padre->nombre << endl;
    }

    if (encontrado->izquierdo == NULL) {
        cout << "Hijo izquierdo: No tiene\n";
    } else {
        cout << "Hijo izquierdo: ";
        cout << encontrado->izquierdo->nombre << endl;
    }

    if (encontrado->derecho == NULL) {
        cout << "Hijo derecho: No tiene\n";
    } else {
        cout << "Hijo derecho: ";
        cout << encontrado->derecho->nombre << endl;
    }
}

void liberarArbol(Nodo*& nodo) {
    if (nodo != NULL) {
        liberarArbol(
            nodo->izquierdo
        );

        liberarArbol(
            nodo->derecho
        );

        delete nodo;
        nodo = NULL;
    }
}

void eliminarNodoMenu() {
    string nombre;

    if (raiz == NULL) {
        cout << "\nEl arbol esta vacio.\n";
        return;
    }

    cout << "\nELIMINAR NODO\n";
    cout << "Nombre del nodo que deseas eliminar: ";
    getline(cin, nombre);

    Nodo* nodoEliminar = buscarNodo(
        raiz,
        nombre
    );

    if (nodoEliminar == NULL) {
        cout << "\nEl nodo no existe.\n";
        return;
    }

    if (nodoEliminar == raiz) {
        liberarArbol(raiz);

        cout << "\nSe elimino la raiz";
        cout << " y todo el arbol.\n";
        return;
    }

    Nodo* padre = nodoEliminar->padre;

    if (
        padre->izquierdo ==
        nodoEliminar
    ) {
        padre->izquierdo = NULL;
    } else if (
        padre->derecho ==
        nodoEliminar
    ) {
        padre->derecho = NULL;
    }

    liberarArbol(
        nodoEliminar
    );

    cout << "\nEl nodo y todos sus hijos";
    cout << " fueron eliminados.\n";
}

int contarNodos(Nodo* nodo) {
    if (nodo == NULL) {
        return 0;
    }

    return 1
        + contarNodos(
            nodo->izquierdo
        )
        + contarNodos(
            nodo->derecho
        );
}

int calcularAltura(Nodo* nodo) {
    if (nodo == NULL) {
        return 0;
    }

    int alturaIzquierda;
    int alturaDerecha;

    alturaIzquierda = calcularAltura(
        nodo->izquierdo
    );

    alturaDerecha = calcularAltura(
        nodo->derecho
    );

    if (
        alturaIzquierda >
        alturaDerecha
    ) {
        return alturaIzquierda + 1;
    }

    return alturaDerecha + 1;
}

void mostrarInformacion() {
    if (raiz == NULL) {
        cout << "\nEl arbol esta vacio.\n";
        return;
    }

    cout << "\nINFORMACION DEL ARBOL\n";

    cout << "Nombre de la raiz: ";
    cout << raiz->nombre << endl;

    cout << "Descripcion de la raiz: ";

    if (raiz->descripcion.empty()) {
        cout << "Sin descripcion\n";
    } else {
        cout << raiz->descripcion << endl;
    }

    cout << "Cantidad de nodos: ";
    cout << contarNodos(raiz) << endl;

    cout << "Altura del arbol: ";
    cout << calcularAltura(raiz) << endl;
}

string agregarExtensionJSON(string nombre) {
    if (nombre.length() < 5) {
        nombre += ".json";
    } else {
        string extension;

        extension = nombre.substr(
            nombre.length() - 5
        );

        if (extension != ".json") {
            nombre += ".json";
        }
    }

    return nombre;
}

void registrarArchivoJSON(string nombre) {
    ifstream lectura(
        "lista_json.txt"
    );

    string archivo;
    bool encontrado = false;

    while (
        getline(
            lectura,
            archivo
        )
    ) {
        if (archivo == nombre) {
            encontrado = true;
        }
    }

    lectura.close();

    if (!encontrado) {
        ofstream escritura(
            "lista_json.txt",
            ios::app
        );

        escritura << nombre << endl;
        escritura.close();
    }
}

string escaparJSON(string texto) {
    string resultado;

    for (
        size_t i = 0;
        i < texto.length();
        i++
    ) {
        if (texto[i] == '\\') {
            resultado += "\\\\";
        } else if (texto[i] == '"') {
            resultado += "\\\"";
        } else if (texto[i] == '\n') {
            resultado += "\\n";
        } else if (texto[i] == '\t') {
            resultado += "\\t";
        } else {
            resultado += texto[i];
        }
    }

    return resultado;
}

void guardarRegistrosJSON(
    ofstream& archivo,
    Nodo* nodo,
    bool& primero
) {
    if (nodo == NULL) {
        return;
    }

    if (!primero) {
        archivo << ",\n";
    }

    archivo << "        {";

    archivo << "\"nombre\":\"";
    archivo << escaparJSON(
        nodo->nombre
    );
    archivo << "\",";

    archivo << "\"descripcion\":\"";
    archivo << escaparJSON(
        nodo->descripcion
    );
    archivo << "\",";

    archivo << "\"padre\":";

    if (nodo->padre == NULL) {
        archivo << "null";
    } else {
        archivo << "\"";
        archivo << escaparJSON(
            nodo->padre->nombre
        );
        archivo << "\"";
    }

    archivo << ",";

    archivo << "\"posicion\":\"";

    if (nodo->padre == NULL) {
        archivo << "raiz";
    } else if (
        nodo->padre->izquierdo ==
        nodo
    ) {
        archivo << "izquierdo";
    } else {
        archivo << "derecho";
    }

    archivo << "\"}";

    primero = false;

    guardarRegistrosJSON(
        archivo,
        nodo->izquierdo,
        primero
    );

    guardarRegistrosJSON(
        archivo,
        nodo->derecho,
        primero
    );
}

void guardarJSON() {
    string nombre;

    if (raiz == NULL) {
        cout << "\nNo hay un arbol para guardar.\n";
        return;
    }

    cout << "\nNombre del arbol para guardar: ";
    getline(cin, nombre);

    if (nombre.empty()) {
        nombre = "arbol";
    }

    nombre = agregarExtensionJSON(
        nombre
    );

    archivoActual = nombre;

    ofstream archivo(
        archivoActual.c_str()
    );

    if (!archivo.is_open()) {
        cout << "\nNo se pudo crear el archivo JSON.\n";
        return;
    }

    archivo << "{\n";

    archivo << "    \"tipo\": ";
    archivo << "\"Arbol binario manual\",\n";

    archivo << "    \"cantidadNodos\": ";
    archivo << contarNodos(raiz);
    archivo << ",\n";

    archivo << "    \"altura\": ";
    archivo << calcularAltura(raiz);
    archivo << ",\n";

    archivo << "    \"nodos\": [\n";

    bool primero = true;

    guardarRegistrosJSON(
        archivo,
        raiz,
        primero
    );

    archivo << "\n";
    archivo << "    ]\n";
    archivo << "}\n";

    archivo.close();

    registrarArchivoJSON(
        archivoActual
    );

    cout << "\nArbol guardado correctamente en ";
    cout << archivoActual << endl;

    abrirJSON();
}

bool obtenerCampoCadena(
    string linea,
    string clave,
    string& valor,
    bool& esNulo
) {
    string textoClave;

    textoClave = "\"" + clave + "\"";

    size_t posicionClave;

    posicionClave = linea.find(
        textoClave
    );

    if (
        posicionClave ==
        string::npos
    ) {
        return false;
    }

    size_t dosPuntos;

    dosPuntos = linea.find(
        ':',
        posicionClave +
        textoClave.length()
    );

    if (
        dosPuntos ==
        string::npos
    ) {
        return false;
    }

    size_t posicion = dosPuntos + 1;

    while (
        posicion < linea.length() &&
        isspace(
            static_cast<unsigned char>(
                linea[posicion]
            )
        )
    ) {
        posicion++;
    }

    if (
        linea.substr(
            posicion,
            4
        ) == "null"
    ) {
        valor = "";
        esNulo = true;
        return true;
    }

    if (
        posicion >= linea.length() ||
        linea[posicion] != '"'
    ) {
        return false;
    }

    posicion++;

    valor = "";
    esNulo = false;

    while (
        posicion < linea.length()
    ) {
        char caracter =
            linea[posicion];

        if (caracter == '"') {
            return true;
        }

        if (caracter == '\\') {
            posicion++;

            if (
                posicion >=
                linea.length()
            ) {
                return false;
            }

            char especial =
                linea[posicion];

            if (especial == 'n') {
                valor += '\n';
            } else if (especial == 't') {
                valor += '\t';
            } else if (especial == '"') {
                valor += '"';
            } else if (especial == '\\') {
                valor += '\\';
            } else {
                valor += especial;
            }
        } else {
            valor += caracter;
        }

        posicion++;
    }

    return false;
}

void cargarJSON() {
    ifstream lista(
        "lista_json.txt"
    );

    vector<string> archivos;
    string nombre;

    int opcion;
    int contador = 1;

    cout << "\nARCHIVOS JSON GUARDADOS\n";

    if (!lista.is_open()) {
        cout << "No hay archivos JSON guardados.\n";
        return;
    }

    while (
        getline(
            lista,
            nombre
        )
    ) {
        if (!nombre.empty()) {
            archivos.push_back(
                nombre
            );

            cout << contador;
            cout << ". ";
            cout << nombre << endl;

            contador++;
        }
    }

    lista.close();

    if (archivos.empty()) {
        cout << "\nNo hay archivos JSON guardados.\n";
        return;
    }

    cout << "\nEscoge el numero del arbol";
    cout << " que quieres abrir: ";

    cin >> opcion;

    if (cin.fail()) {
        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        cout << "\nDebes escribir un numero valido.\n";
        return;
    }

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    if (
        opcion < 1 ||
        opcion >
        static_cast<int>(
            archivos.size()
        )
    ) {
        cout << "\nOpcion incorrecta.\n";
        return;
    }

    archivoActual =
        archivos[opcion - 1];

    ifstream archivo(
        archivoActual.c_str()
    );

    if (!archivo.is_open()) {
        cout << "\nNo se encontro el archivo ";
        cout << archivoActual << endl;
        return;
    }

    vector<RegistroNodo> registros;

    string linea;

    while (
        getline(
            archivo,
            linea
        )
    ) {
        if (
            linea.find("\"nombre\"") !=
            string::npos
        ) {
            RegistroNodo registro;

            bool nombreNulo = false;
            bool descripcionNula = false;
            bool padreNulo = false;
            bool posicionNula = false;

            bool nombreCorrecto;
            bool descripcionCorrecta;
            bool padreCorrecto;
            bool posicionCorrecta;

            nombreCorrecto =
                obtenerCampoCadena(
                    linea,
                    "nombre",
                    registro.nombre,
                    nombreNulo
                );

            descripcionCorrecta =
                obtenerCampoCadena(
                    linea,
                    "descripcion",
                    registro.descripcion,
                    descripcionNula
                );

            padreCorrecto =
                obtenerCampoCadena(
                    linea,
                    "padre",
                    registro.padre,
                    padreNulo
                );

            posicionCorrecta =
                obtenerCampoCadena(
                    linea,
                    "posicion",
                    registro.posicion,
                    posicionNula
                );

            registro.padreEsNulo =
                padreNulo;

            if (
                nombreCorrecto &&
                descripcionCorrecta &&
                padreCorrecto &&
                posicionCorrecta
            ) {
                registros.push_back(
                    registro
                );
            }
        }
    }

    archivo.close();

    if (registros.empty()) {
        cout << "\nEl archivo JSON no contiene nodos validos.\n";
        return;
    }

    Nodo* nuevaRaiz = NULL;
    bool error = false;

    for (
        size_t i = 0;
        i < registros.size();
        i++
    ) {
        if (
            registros[i].padreEsNulo ||
            registros[i].posicion ==
            "raiz"
        ) {
            if (nuevaRaiz != NULL) {
                error = true;
                break;
            }

            nuevaRaiz = new Nodo(
                registros[i].nombre,
                registros[i].descripcion
            );
        } else {
            if (nuevaRaiz == NULL) {
                error = true;
                break;
            }

            Nodo* padre = buscarNodo(
                nuevaRaiz,
                registros[i].padre
            );

            if (padre == NULL) {
                error = true;
                break;
            }

            if (
                buscarNodo(
                    nuevaRaiz,
                    registros[i].nombre
                ) != NULL
            ) {
                error = true;
                break;
            }

            Nodo* nuevo = new Nodo(
                registros[i].nombre,
                registros[i].descripcion
            );

            nuevo->padre = padre;

            if (
                registros[i].posicion ==
                "izquierdo"
            ) {
                if (
                    padre->izquierdo !=
                    NULL
                ) {
                    delete nuevo;
                    error = true;
                    break;
                }

                padre->izquierdo = nuevo;
            } else if (
                registros[i].posicion ==
                "derecho"
            ) {
                if (
                    padre->derecho !=
                    NULL
                ) {
                    delete nuevo;
                    error = true;
                    break;
                }

                padre->derecho = nuevo;
            } else {
                delete nuevo;
                error = true;
                break;
            }
        }
    }

    if (
        error ||
        nuevaRaiz == NULL
    ) {
        liberarArbol(
            nuevaRaiz
        );

        cout << "\nNo se pudo cargar el arbol.\n";
        cout << "El archivo JSON tiene";
        cout << " relaciones incorrectas.\n";

        return;
    }

    liberarArbol(raiz);

    raiz = nuevaRaiz;

    cout << "\nArbol cargado correctamente desde ";
    cout << archivoActual << endl;

    cout << "Raiz cargada: ";
    cout << raiz->nombre << endl;

    cout << "Nodos cargados: ";
    cout << contarNodos(raiz) << endl;

    abrirJSON();
}

void abrirJSON() {
#ifdef _WIN32
    string comando;

    comando =
        "start notepad \"" +
        archivoActual +
        "\"";

    system(
        comando.c_str()
    );

#elif __APPLE__
    string comando;

    comando =
        "open -t \"" +
        archivoActual +
        "\"";

    system(
        comando.c_str()
    );

#else
    string comando;

    comando =
        "xdg-open \"" +
        archivoActual +
        "\"";

    system(
        comando.c_str()
    );
#endif
}
