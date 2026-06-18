#include <iostream>
#include "Arbol.h"

using namespace std;

int main() {
    Arbol miArbol;
    int opcion;
    string nombrePadre, nombreHijo, nodoAConsultar;

    do {
        cout << "\n=============================================" << endl;
        cout << "      CONSTRUCTOR DE ARBOLES GENERALES       " << endl;
        cout << "=============================================" << endl;
        cout << "1. Inicializar / Definir Nodo Raiz" << endl;
        cout << "2. Agregar Nodo Hijo (Definiendo su Padre)" << endl;
        cout << "3. Ver Arbol Completo (Estructura Visual)" << endl;
        cout << "4. Ver Listado de Nodos Hoja (Terminales)" << endl;
        cout << "5. Consultar un Nodo (Ver Padre e Hijos)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) { 
            cout << "\n[ERROR] Entrada invalida. Restableciendo menu..." << endl;
            cin.clear(); 
            while (cin.get() != '\n'); 
            opcion = 0; 
            continue;
        }

        switch (opcion) {
            case 1:
                if (miArbol.estaVacio()) {
                    cout << "\nIngrese el nombre para el Nodo Raiz (Ej: Principal, A, Jefe): ";
                    cin >> nombreHijo;
                    miArbol.establecerRaiz(nombreHijo);
                    cout << "¡Raiz [" << nombreHijo << "] creada con exito!" << endl;
                } else {
                    cout << "\n[!] El arbol ya posee una raiz configurada." << endl;
                }
                break;
                
            case 2:
                cout << "\n¿A que Nodo Padre le vas a colgar el hijo?: ";
                cin >> nombrePadre;
                cout << "Ingrese el nombre del nuevo Nodo Hijo: ";
                cin >> nombreHijo;
                if (miArbol.insertarHijo(nombrePadre, nombreHijo)) {
                    cout << "¡Nodo [" << nombreHijo << "] enlazado como hijo de [" << nombrePadre << "]!" << endl;
                }
                break;
                
            case 3:
                miArbol.mostrarEstructuraVisual();
                break;
                
            case 4:
                miArbol.mostrarHojas();
                break;
                
            case 5:
                cout << "\nIngrese el nombre del nodo que deseas inspeccionar: ";
                cin >> nodoAConsultar;
                miArbol.consultarInformacionNodo(nodoAConsultar);
                break;
                
            case 6:
                if (!miArbol.estaVacio()) {
                    miArbol.archivos();
                } else {
                    cout << "\n[!] Arbol vacio. No se generaron reportes." << endl;
                }
                cout << "\nCerrando el organizador jerarquico..." << endl;
                break;
                
            default:
                cout << "\nOpcion no valida. Reintente." << endl;
        }
    } while (opcion != 6);

    return 0;
}
