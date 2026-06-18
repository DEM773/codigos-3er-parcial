#include <iostream>
#include "DiGrafo.h"

using namespace std;

int main() {
    Grafo appDigrafo;
    int opcion;
    string orig, dest, nombreArista, nuevoNodo;
    int peso, tiempo;

    do {
        cout << "\n=============================================" << endl;
        cout << "      SISTEMA DE DIGRAFOS (RUTAS DIRIGIDAS)   " << endl;
        cout << "=============================================" << endl;
        cout << "1. Registrar un Nodo" << endl;
        cout << "2. Crear un Arco Dirigido (Origen -> Destino)" << endl;
        cout << "3. Ver Nodos registrados" << endl;
        cout << "4. Ver Tabla de Arcos / Caminos" << endl;
        cout << "5. Calcular Caminos Opciones y Dijkstra" << endl;
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
                cout << "\nIngrese el nombre del Nodo: ";
                cin >> nuevoNodo;
                appDigrafo.agregarNodo(nuevoNodo);
                cout << "¡Nodo [" << nuevoNodo << "] registrado!" << endl;
                break;
                
            case 2:
                cout << "\n--- DATOS DEL NUEVO ARCO DIRIGIDO ---" << endl;
                cout << "Nodo de Origen (ni): ";
                cin >> orig;
                cout << "Nodo de Destino (nf): ";
                cin >> dest;
                cout << "Nombre del Arco (ae): ";
                cin >> nombreArista;
                
                cout << "Peso / Costo (p): ";
                while (!(cin >> peso)) {
                    cout << "[!] Invalido. Ingrese un numero entero: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                
                cout << "Tiempo (t): ";
                while (!(cin >> tiempo)) {
                    cout << "[!] Invalido. Ingrese un numero entero: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                
                appDigrafo.agregarRutaDirigida(orig, dest, nombreArista, peso, tiempo);
                cout << "¡Arco dirigido creado exitosamente!" << endl;
                break;
                
            case 3:
                appDigrafo.mostrarNodos();
                break;
                
            case 4:
                appDigrafo.mostrarRutasCargadas();
                break;
                
            case 5:
                cout << "\nIngrese el Nodo de Origen Inicial: ";
                cin >> orig;
                cout << "Ingrese el Nodo de Destino Final: ";
                cin >> dest;
                
                cout << "\n---------------------------------------------" << endl;
                int total;
                total = appDigrafo.obtenerTotalCaminos(orig, dest);
                cout << "Cantidad de rutas dirigidas encontradas: " << total << endl;
                
                appDigrafo.buscarRutaMasCortaDijkstra(orig, dest);
                cout << "---------------------------------------------" << endl;
                break;
                
            case 6:
                appDigrafo.archivos();
                cout << "\nCerrando el sistema de Digrafos..." << endl;
                break;
                
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}
