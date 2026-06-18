#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class nodo
{
    public:
        int dato;
        float dato2;
        nodo *sig;
};

class pila
{
    public:
        pila();
        ~pila();

        void insertar(nodo *&tope, int x, float y);
        void mostrarDatos();
        void sacarDato();
        void archivos();

        nodo *tope;
};

pila::pila()
{
    tope = NULL;
}

pila::~pila()
{
    nodo *aux;

    while(tope != NULL)
    {
        aux = tope;
        tope = tope->sig;
        delete aux;
    }
}

void pila::insertar(nodo *&tope, int x, float y)
{
    nodo *nuevo;

    nuevo = new nodo();
    nuevo->dato = x;
    nuevo->dato2 = y;
    nuevo->sig = tope;
    tope = nuevo;

    cout << "Datos insertados" << endl;
}

void pila::mostrarDatos()
{
    nodo *aux;

    if(tope == NULL)
    {
        cout << "No hay elementos en la pila" << endl;
        return;
    }

    cout << endl;
    cout << "Pila de datos" << endl;

    aux = tope;

    while(aux != NULL)
    {
        cout << "Dato: " << aux->dato << endl;
        cout << "Decimal: " << aux->dato2 << endl;
        aux = aux->sig;
    }
}

void pila::sacarDato()
{
    nodo *aux;

    if(tope != NULL)
    {
        aux = tope;
        cout << "Dato eliminado: " << aux->dato << endl;
        cout << "Decimal eliminado: " << aux->dato2 << endl;
        tope = tope->sig;
        delete aux;
    }
    else
    {
        cout << "Pila vacia" << endl;
    }
}

void pila::archivos()
{
    nodo *aux;
    int pos;

    ofstream txt("pila2.txt");

    txt << "PROGRAMA DE PILA CON NODOS" << endl;
    txt << endl;
    txt << "Pila de datos" << endl;

    aux = tope;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            txt << "Dato: " << aux->dato << endl;
            txt << "Decimal: " << aux->dato2 << endl;
            aux = aux->sig;
        }
    }
    else
    {
        txt << "Pila vacia" << endl;
    }

    txt.close();

    ofstream csv("pila2.csv");

    csv << "Posicion,Dato,Decimal" << endl;

    aux = tope;
    pos = 1;

    while(aux != NULL)
    {
        csv << pos << "," << aux->dato << "," << aux->dato2 << endl;
        aux = aux->sig;
        pos++;
    }

    csv.close();

    ofstream xml("pila2.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<pila2>" << endl;

    aux = tope;

    while(aux != NULL)
    {
        xml << "    <nodo>" << endl;
        xml << "        <dato>" << aux->dato << "</dato>" << endl;
        xml << "        <decimal>" << aux->dato2 << "</decimal>" << endl;
        xml << "    </nodo>" << endl;

        aux = aux->sig;
    }

    xml << "</pila2>" << endl;

    xml.close();

    ofstream json("pila2.json");

    json << "{" << endl;
    json << "    \"pila\": [" << endl;

    aux = tope;

    while(aux != NULL)
    {
        json << "        {" << endl;
        json << "            \"dato\": " << aux->dato << "," << endl;
        json << "            \"decimal\": " << aux->dato2 << endl;
        json << "        }";

        if(aux->sig != NULL)
        {
            json << ",";
        }

        json << endl;

        aux = aux->sig;
    }

    json << "    ]" << endl;
    json << "}" << endl;

    json.close();

    ofstream html("pila2.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Pila Nodos</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Pila con Nodos</h2>" << endl;
    html << "  <table><tr><th>Posicion</th><th>Dato</th><th>Decimal</th></tr>" << endl;
    aux = tope;
    pos = 1;
    while(aux != NULL) {
        html << "    <tr><td>" << pos << "</td><td>" << aux->dato << "</td><td>" << aux->dato2 << "</td></tr>" << endl;
        aux = aux->sig;
        pos++;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_pila2.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE PILA CON NODOS" << endl;
    general << endl;
    general << "Pila de datos" << endl;

    aux = tope;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            general << "Dato: " << aux->dato << endl;
            general << "Decimal: " << aux->dato2 << endl;
            aux = aux->sig;
        }
    }
    else
    {
        general << "Pila vacia" << endl;
    }

    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato,Decimal" << endl;

    aux = tope;
    pos = 1;

    while(aux != NULL)
    {
        general << pos << "," << aux->dato << "," << aux->dato2 << endl;
        aux = aux->sig;
        pos++;
    }

    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<pila2>" << endl;

    aux = tope;

    while(aux != NULL)
    {
        general << "    <nodo>" << endl;
        general << "        <dato>" << aux->dato << "</dato>" << endl;
        general << "        <decimal>" << aux->dato2 << "</decimal>" << endl;
        general << "    </nodo>" << endl;

        aux = aux->sig;
    }

    general << "</pila2>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"pila\": [" << endl;

    aux = tope;

    while(aux != NULL)
    {
        general << "        {" << endl;
        general << "            \"dato\": " << aux->dato << "," << endl;
        general << "            \"decimal\": " << aux->dato2 << endl;
        general << "        }";

        if(aux->sig != NULL)
        {
            general << ",";
        }

        general << endl;

        aux = aux->sig;
    }

    general << "    ]" << endl;
    general << "}" << endl;

    general.close();

    cout << "\n[!] Guardando y abriendo todos los reportes de la pila..." << endl;

    system("start notepad pila2.txt");
    system("start pila2.csv");
    system("start pila2.html");
    system("start pila2.xml");
    system("start pila2.json");
    system("start notepad resultado_pila2.txt");
}

int main()
{
    pila obre;
    int opcion, dato;
    float decimal;

    do
    {
        cout << "\n--- Menu de Pila ---" << endl;
        cout << "1. Insertar datos" << endl;
        cout << "2. Quitar dato" << endl;
        cout << "3. Mostrar pila" << endl;
        cout << "4. Salir y Abrir Archivos" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Ingresa numero: ";
                cin >> dato;

                cout << "Ingresa decimal: ";
                cin >> decimal;

                obre.insertar(obre.tope, dato, decimal);
                break;

            case 2:
                obre.sacarDato();
                break;

            case 3:
                obre.mostrarDatos();
                break;

            case 4:
                obre.archivos();
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    } while(opcion != 4);

    return 0;
}
