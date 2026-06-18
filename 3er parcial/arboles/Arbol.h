#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Estructura para cada Nodo del Árbol General
struct NodoArbol {
    string nombre;
    NodoArbol* padre;
    vector<NodoArbol*> hijos;

    NodoArbol(string nom, NodoArbol* pad = NULL) {
        nombre = nom;
        padre = pad;
    }
};

class Arbol {
private:
    NodoArbol* raiz;

    // Funciones auxiliares recursivas
    NodoArbol* buscarNodoRecursivo(NodoArbol* actual, string nombreABuscar);
    void mostrarEstructuraRecursiva(NodoArbol* actual, string prefijo, bool esUltimo);
    void recolectarHojas(NodoArbol* actual, vector<string>& hojas);
    void liberarMemoria(NodoArbol* actual);

public:
    Arbol();
    ~Arbol();

    bool establecerRaiz(string nombreRaiz);
    bool insertarHijo(string nombrePadre, string nombreHijo);
    void mostrarEstructuraVisual();
    void mostrarHojas();
    void consultarInformacionNodo(string nombreNodo);
    bool estaVacio();
};

#endif
