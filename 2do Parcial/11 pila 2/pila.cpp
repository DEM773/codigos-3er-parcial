#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class nodo
{
    public:
        int dato;
        nodo *sig;
};

class nodoF
{
    public:
        float dato;
        nodoF *sig;
};

class pilaNF
{
    public:
        pilaNF();
        ~pilaNF();

        void insertar(nodo *&tope, int x);
        void mostrarDatos();
        void sacarDato();

        void insertarFloat(nodoF *&topeF, float x);
        void mostrarDatosFloat();

        void archivos();

        nodo *tope;
        nodoF *topeF;
};

pilaNF::pilaNF()
{
    tope = NULL;
    topeF = NULL;
}

pilaNF::~pilaNF()
{
    nodo *aux;

    while(tope != NULL)
    {
        aux = tope;
        tope = tope->sig;
        delete aux;
    }

    nodoF *auxF;

    while(topeF != NULL)
    {
        auxF = topeF;
        topeF = topeF->sig;
        delete auxF;
    }
}

void pilaNF::insertar(nodo *&tope, int x)
{
    nodo *nuevo = new nodo();

    nuevo->dato = x;
    nuevo->sig = tope;
    tope = nuevo;

    cout << "Dato insertado" << endl;
}

void pilaNF::mostrarDatos()
{
    nodo *aux = tope;

    if(aux != NULL)
    {
        cout << "\nPila de datos:" << endl;

        while(aux != NULL)
        {
            cout << "Dato: " << aux->dato << endl;
            aux = aux->sig;
        }
    }
    else
    {
        cout << "No hay elementos en la pila" << endl;
    }
}

void pilaNF::sacarDato()
{
    nodo *aux;

    if(tope != NULL)
    {
        aux = tope;
        cout << "Dato eliminado: " << aux->dato << endl;
        tope = tope->sig;
        delete aux;
    }
    else
    {
        cout << "Pila vacia" << endl;
    }
}

void pilaNF::insertarFloat(nodoF *&topeF, float x)
{
    nodoF *nuevo = new nodoF();

    nuevo->dato = x;
    nuevo->sig = topeF;
    topeF = nuevo;

    cout << "Decimal insertado" << endl;
}

void pilaNF::mostrarDatosFloat()
{
    nodoF *aux = topeF;

    if(aux != NULL)
    {
        cout << "\nPila de decimales:" << endl;

        while(aux != NULL)
        {
            cout << "Dato: " << aux->dato << endl;
            aux = aux->sig;
        }
    }
    else
    {
        cout << "No hay decimales en la pila" << endl;
    }
}

void pilaNF::archivos()
{
    nodo *aux;
    nodoF *auxF;

    ofstream txt("pilaNF.txt");

    txt << "PROGRAMA DE PILA CON NODOS" << endl;
    txt << endl;

    txt << "Pila de enteros:" << endl;
    aux = tope;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            txt << "Dato: " << aux->dato << endl;
            aux = aux->sig;
        }
    }
    else
    {
        txt << "Pila de enteros vacia" << endl;
    }

    txt << endl;

    txt << "Pila de decimales:" << endl;
    auxF = topeF;

    if(auxF != NULL)
    {
        while(auxF != NULL)
        {
            txt << "Dato: " << auxF->dato << endl;
            auxF = auxF->sig;
        }
    }
    else
    {
        txt << "Pila de decimales vacia" << endl;
    }

    txt.close();

    ofstream csv("pilaNF.csv");

    csv << "Tipo,Posicion,Dato" << endl;

    aux = tope;
    int pos = 1;

    while(aux != NULL)
    {
        csv << "Entero," << pos << "," << aux->dato << endl;
        aux = aux->sig;
        pos++;
    }

    auxF = topeF;
    pos = 1;

    while(auxF != NULL)
    {
        csv << "Decimal," << pos << "," << auxF->dato << endl;
        auxF = auxF->sig;
        pos++;
    }

    csv.close();

    ofstream xml("pilaNF.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<pilaNF>" << endl;

    xml << "    <enteros>" << endl;
    aux = tope;

    while(aux != NULL)
    {
        xml << "        <dato>" << aux->dato << "</dato>" << endl;
        aux = aux->sig;
    }

    xml << "    </enteros>" << endl;

    xml << "    <decimales>" << endl;
    auxF = topeF;

    while(auxF != NULL)
    {
        xml << "        <dato>" << auxF->dato << "</dato>" << endl;
        auxF = auxF->sig;
    }

    xml << "    </decimales>" << endl;
    xml << "</pilaNF>" << endl;

    xml.close();

    ofstream json("pilaNF.json");

    json << "{" << endl;

    json << "    \"enteros\": [" << endl;
    aux = tope;

    while(aux != NULL)
    {
        json << "        " << aux->dato;

        if(aux->sig != NULL)
        {
            json << ",";
        }

        json << endl;
        aux = aux->sig;
    }

    json << "    ]," << endl;

    json << "    \"decimales\": [" << endl;
    auxF = topeF;

    while(auxF != NULL)
    {
        json << "        " << auxF->dato;

        if(auxF->sig != NULL)
        {
            json << ",";
        }

        json << endl;
        auxF = auxF->sig;
    }

    json << "    ]" << endl;
    json << "}" << endl;

    json.close();

    ofstream html("pilaNF.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Pila Nodos</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Pila con Nodos</h2>" << endl;
    html << "  <h3>Enteros (Desde el Tope)</h3>\n  <table><tr><th>Posicion</th><th>Dato</th></tr>" << endl;
    aux = tope;
    pos = 1;
    while(aux != NULL) {
        html << "    <tr><td>" << pos << "</td><td>" << aux->dato << "</td></tr>" << endl;
        aux = aux->sig;
        pos++;
    }
    html << "  </table>" << endl;
    html << "  <h3>Decimales (Desde el Tope)</h3>\n  <table><tr><th>Posicion</th><th>Dato</th></tr>" << endl;
    auxF = topeF;
    pos = 1;
    while(auxF != NULL) {
        html << "    <tr><td>" << pos << "</td><td>" << auxF->dato << "</td></tr>" << endl;
        auxF = auxF->sig;
        pos++;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_pilaNF.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE PILA CON NODOS" << endl;
    general << endl;

    general << "Pila de enteros:" << endl;
    aux = tope;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            general << "Dato: " << aux->dato << endl;
            general << "Dato: " << aux->dato << endl;
            aux = aux->sig;
        }
    }
    else
    {
        general << "Pila de enteros vacia" << endl;
    }

    general << endl;

    general << "Pila de decimales:" << endl;
    auxF = topeF;

    if(auxF != NULL)
    {
        while(auxF != NULL)
        {
            general << "Dato: " << auxF->dato << endl;
            auxF = auxF->sig;
        }
    }
    else
    {
        general << "Pila de decimales vacia" << endl;
    }

    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Posicion,Dato" << endl;

    aux = tope;
    pos = 1;

    while(aux != NULL)
    {
        general << "Entero," << pos << "," << aux->dato << endl;
        aux = aux->sig;
        pos++;
    }

    auxF = topeF;
    pos = 1;

    while(auxF != NULL)
    {
        general << "Decimal," << pos << "," << auxF->dato << endl;
        auxF = auxF->sig;
        pos++;
    }

    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<pilaNF>" << endl;

    general << "    <enteros>" << endl;
    aux = tope;

    while(aux != NULL)
    {
        general << "        <dato>" << aux->dato << "</dato>" << endl;
        aux = aux->sig;
    }

    general << "    </enteros>" << endl;

    general << "    <decimales>" << endl;
    auxF = topeF;

    while(auxF != NULL)
    {
        general << "        <dato>" << auxF->dato << "</dato>" << endl;
        auxF = auxF->sig;
    }

    general << "    </decimales>" << endl;
    general << "</pilaNF>" << endl;

    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;

    general << "    \"enteros\": [" << endl;
    aux = tope;

    while(aux != NULL)
    {
        general << "        " << aux->dato;

        if(aux->sig != NULL)
        {
            general << ",";
        }

        general << endl;
        aux = aux->sig;
    }

    general << "    ]," << endl;

    general << "    \"decimales\": [" << endl;
    auxF = topeF;

    while(auxF != NULL)
    {
        general << "        " << auxF->dato;

        if(auxF->sig != NULL)
        {
            general << ",";
        }

        general << endl;
        auxF = auxF->sig;
    }

    general << "    ]" << endl;
    general << "}" << endl;

    general.close();

    cout << "\n[!] Guardando y abriendo todos los reportes de la pila..." << endl;
    
    system("start notepad pilaNF.txt");   
    system("start pilaNF.csv"); 
    system("start pilaNF.html"); 
    system("start pilaNF.xml"); 
    system("start pilaNF.json"); 
    system("start notepad resultado_pilaNF.txt");
}

int main()
{
    pilaNF obre;
    int opcion, dato;
    float datoF;

    do
    {
        cout << "\n--- Menu de Pila ---" << endl;
        cout << "1. Insertar numero" << endl;
        cout << "2. Quitar numero" << endl;
        cout << "3. Mostrar pila" << endl;
        cout << "4. Insertar decimal" << endl;
        cout << "5. Mostrar decimales" << endl;
        cout << "6. Salir y Abrir Archivos" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Ingresa numero: ";
                cin >> dato;
                obre.insertar(obre.tope, dato);
                break;

            case 2:
                obre.sacarDato();
                break;

            case 3:
                obre.mostrarDatos();
                break;

            case 4:
                cout << "Ingresa decimal: ";
                cin >> datoF;
                obre.insertarFloat(obre.topeF, datoF);
                break;

            case 5:
                obre.mostrarDatosFloat();
                break;

            case 6:
                obre.archivos();
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    } while(opcion != 6);

    return 0;
}
