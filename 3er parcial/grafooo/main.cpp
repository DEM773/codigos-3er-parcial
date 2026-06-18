#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    Grafo appGrafo;
    int opcion;
    string orig, dest, nombreArista, nuevoNodo;
    int peso, tiempo;

    do {
        cout << "\n=============================================" << endl;
        cout << "      APLICACION DE GRAFOS INTERACTIVA       " << endl;
        cout << "=============================================" << endl;
        cout << "1. Registrar un nuevo Nodo" << endl;
        cout << "2. Crear una Ruta/Arista" << endl;
        cout << "3. Ver Nodos registrados" << endl;
        cout << "4. Ver Tabla de Aristas" << endl;
        cout << "5. Calcular caminos" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) { 
            cout << "\n[ERROR] Entrada invalida!" << endl;
            cin.clear(); 
            while (cin.get() != '\n'); 
            opcion = 0; continue;
        }

        switch (opcion) {
            case 1:
                cout << "\nNombre del Nodo: "; cin >> nuevoNodo;
                appGrafo.agregarNodo(nuevoNodo);
                break;
            case 2:
                cout << "\nNodo Inicial: "; cin >> orig;
                cout << "Nodo Final: "; cin >> dest;
                cout << "Nombre Arista: "; cin >> nombreArista;
                cout << "Peso: "; cin >> peso;
                cout << "Tiempo: "; cin >> tiempo;
                appGrafo.agregarRuta(orig, dest, nombreArista, peso, tiempo);
                break;
            case 3:
                appGrafo.mostrarNodos();
                break;
            case 4:
                appGrafo.mostrarRutasCargadas();
                break;
            case 5:
                cout << "\nOrigen: "; cin >> orig;
                cout << "Destino: "; cin >> dest;
                cout << "\n-------------------------------------" << endl;
                cout << "Rutas encontradas: " << appGrafo.obtenerTotalCaminos(orig, dest) << endl;
                appGrafo.buscarRutaMasCortaDijkstra(orig, dest);
                cout << "-------------------------------------" << endl;
                break;
            case 6:
                appGrafo.archivos();
                cout << "\nSaliendo de la aplicacion..." << endl;
                break;
            default:
                cout << "\nOpcion no valida." << endl;
        }
    } while (opcion != 6);

    return 0;
}
