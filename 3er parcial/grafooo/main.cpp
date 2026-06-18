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
        cout << "1. Registrar un nuevo Nodo (Ej: A, B, C...)" << endl;
        cout << "2. Crear una Ruta/Arista (Conectar nodos)" << endl;
        cout << "3. Ver Nodos registrados en el sistema" << endl;
        cout << "4. Ver Tabla de Aristas/Rutas creadas" << endl;
        cout << "5. Calcular caminos y Ruta Optima (Dijkstra)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) { 
            cout << "\n[ERROR] ¡Entrada invalida! Reintentando..." << endl;
            cin.clear(); 
            while (cin.get() != '\n'); 
            opcion = 0; 
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "\nIngrese el nombre del Nodo: ";
                cin >> nuevoNodo;
                appGrafo.agregarNodo(nuevoNodo);
                cout << "¡Nodo [" << nuevoNodo << "] registrado!" << endl;
                break;
                
            case 2:
                cout << "\n--- DATOS DE LA NUEVA ARISTA ---" << endl;
                cout << "Nodo Inicial (ni): ";
                cin >> orig;
                cout << "Nodo Final (nf): ";
                cin >> dest;
                cout << "Nombre de la Arista (ae): ";
                cin >> nombreArista;
                
                cout << "Peso / Costo (p): ";
                while (!(cin >> peso)) {
                    cout << "[!] Invalido. Ingrese un numero para el peso: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                
                cout << "Tiempo (t): ";
                while (!(cin >> tiempo)) {
                    cout << "[!] Invalido. Ingrese un numero para el tiempo: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                
                appGrafo.agregarRuta(orig, dest, nombreArista, peso, tiempo);
                cout << "¡Conexion creada exitosamente!" << endl;
                break;
                
            case 3:
                appGrafo.mostrarNodos();
                break;
                
            case 4:
                appGrafo.mostrarRutasCargadas();
                break;
                
            case 5:
                cout << "\nIngrese el Nodo de Origen: ";
                cin >> orig;
                cout << "Ingrese el Nodo de Destino: ";
                cin >> dest;
                
                cout << "\n---------------------------------------------" << endl;
                int total;
                total = appGrafo.obtenerTotalCaminos(orig, dest);
                cout << "Cantidad de rutas posibles encontradas: " << total << endl;
                
                appGrafo.buscarRutaMasCortaDijkstra(orig, dest);
                cout << "---------------------------------------------" << endl;
                break;
                
            case 6:
                cout << "\nSaliendo de la aplicacion..." << endl;
                break;
                
            default:
                cout << "\nOpcion no valida. Reintente." << endl;
        }
    } while (opcion != 6);

    return 0;
}
