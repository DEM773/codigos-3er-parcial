#include "Arbol.h"

Arbol::Arbol() {
    raiz = NULL;
}

Arbol::~Arbol() {
    liberarMemoria(raiz);
}

void Arbol::liberarMemoria(NodoArbol* actual) {
    if (actual == NULL) return;
    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        liberarMemoria(actual->hijos[i]);
    }
    delete actual;
}

bool Arbol::estaVacio() {
    return raiz == NULL;
}

NodoArbol* Arbol::buscarNodoRecursivo(NodoArbol* actual, string nombreABuscar) {
    if (actual == NULL) return NULL;
    if (actual->nombre == nombreABuscar) return actual;

    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        NodoArbol* encontrado = buscarNodoRecursivo(actual->hijos[i], nombreABuscar);
        if (encontrado != NULL) return encontrado;
    }
    return NULL;
}

bool Arbol::establecerRaiz(string nombreRaiz) {
    if (raiz != NULL) {
        cout << "[!] El arbol ya tiene una raiz llamada: " << raiz->nombre << endl;
        return false;
    }
    raiz = new NodoArbol(nombreRaiz);
    return true;
}

bool Arbol::insertarHijo(string nombrePadre, string nombreHijo) {
    if (raiz == NULL) {
        cout << "[!] Primero debes establecer el nodo Raiz (Opcion 1)." << endl;
        return false;
    }

    NodoArbol* nodoPadre = buscarNodoRecursivo(raiz, nombrePadre);
    if (nodoPadre == NULL) {
        cout << "[ERROR] No se encontro ningun nodo con el nombre '" << nombrePadre << "' para ser el padre." << endl;
        return false;
    }

    if (buscarNodoRecursivo(raiz, nombreHijo) != NULL) {
        cout << "[ERROR] El nodo '" << nombreHijo << "' ya existe en el arbol. Usa un nombre unico." << endl;
        return false;
    }

    NodoArbol* nuevoHijo = new NodoArbol(nombreHijo, nodoPadre);
    nodoPadre->hijos.push_back(nuevoHijo);
    return true;
}

void Arbol::mostrarEstructuraRecursiva(NodoArbol* actual, string prefijo, bool esUltimo) {
    if (actual == NULL) return;

    cout << prefijo;
    cout << (esUltimo ? "+-- " : "+-- ");
    cout << actual->nombre << endl;

    string nuevoPrefijo = prefijo + (esUltimo ? "    " : "¦   ");
    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        bool esElUltimoHijo = (i == actual->hijos.size() - 1);
        mostrarEstructuraRecursiva(actual->hijos[i], nuevoPrefijo, esElUltimoHijo);
    }
}

void Arbol::mostrarEstructuraVisual() {
    if (raiz == NULL) {
        cout << "(El arbol esta totalmente vacio)" << endl;
        return;
    }
    cout << "\n=== REPRESENTACION GRAFICA DEL ARBOL ===" << endl;
    cout << raiz->nombre << " (Raiz)" << endl;
    
    for (size_t i = 0; i < raiz->hijos.size(); ++i) {
        bool esUltimo = (i == raiz->hijos.size() - 1);
        mostrarEstructuraRecursiva(raiz->hijos[i], "", esUltimo);
    }
    cout << "=========================================" << endl;
}

void Arbol::recolectarHojas(NodoArbol* actual, vector<string>& hojas) {
    if (actual == NULL) return;
    
    if (actual->hijos.empty()) {
        hojas.push_back(actual->nombre);
        return;
    }

    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        recolectarHojas(actual->hijos[i], hojas);
    }
}

void Arbol::mostrarHojas() {
    if (raiz == NULL) {
        cout << "(El arbol esta vacio)" << endl;
        return;
    }
    vector<string> hojas;
    recolectarHojas(raiz, hojas);

    cout << "\n=== NODOS HOJA (TERMINALES) ===" << endl;
    for (size_t i = 0; i < hojas.size(); ++i) {
        cout << "[" << hojas[i] << "] ";
    }
    cout << "\n==============================" << endl;
}

void Arbol::consultarInformacionNodo(string nombreNodo) {
    if (raiz == NULL) {
        cout << "(El arbol esta vacio)" << endl;
        return;
    }

    NodoArbol* nodo = buscarNodoRecursivo(raiz, nombreNodo);
    if (nodo == NULL) {
        cout << "[!] Nodo no encontrado en el sistema." << endl;
        return;
    }

    cout << "\n--- PROPIEDADES DEL NODO [" << nodo->nombre << "] ---" << endl;
    
    if (nodo->padre == NULL) {
        cout << " -> Rol: Raiz del Arbol (No tiene padre)" << endl;
    } else {
        cout << " -> Nodo Padre: " << nodo->padre->nombre << endl;
    }

    cout << " -> Hijos asignados: ";
    if (nodo->hijos.empty()) {
        cout << "(Ninguno. Es un nodo Hoja)" << endl;
    } else {
        for (size_t i = 0; i < nodo->hijos.size(); ++i) {
            cout << "[" << nodo->hijos[i]->nombre << "] ";
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
}
