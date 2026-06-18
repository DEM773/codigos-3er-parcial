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

class lista
{
    public:
        lista();
        ~lista();

        void insertar(nodo *&cab, int x, float y);
        void mostrarDatos();
        void eliminarDato();
        void archivos();

        nodo *cab;
};

lista::lista()
{
    cab = NULL;
}

lista::~lista()
{
    nodo *aux;

    while(cab != NULL)
    {
        aux = cab;
        cab = cab->sig;
        delete aux;
    }
}

void lista::insertar(nodo *&cab, int x, float y)
{
    nodo *nuevo;
    nodo *aux;

    nuevo = new nodo();
    nuevo->dato = x;
    nuevo->dato2 = y;
    nuevo->sig = NULL;

    if(cab == NULL)
    {
        cab = nuevo;
    }
    else
    {
        aux = cab;

        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }

    cout << "Datos insertados" << endl;
}

void lista::mostrarDatos()
{
    nodo *aux;
    int i = 1;

    if(cab == NULL)
    {
        cout << "No hay elementos en la lista" << endl;
        return;
    }

    cout << endl;
    cout << "Lista de datos" << endl;

    aux = cab;

    while(aux != NULL)
    {
        cout << "Dato " << i << ": " << aux->dato << endl;
        cout << "Decimal " << i << ": " << aux->dato2 << endl;
        aux = aux->sig;
        i++;
    }
}

void lista::eliminarDato()
{
    int pos;
    int i;
    nodo *aux;
    nodo *ant;

    if(cab == NULL)
    {
        cout << "Lista vacia" << endl;
        return;
    }

    cout << "Posicion a eliminar: ";
    cin >> pos;

    if(pos == 1)
    {
        aux = cab;
        cab = cab->sig;
        cout << "Dato eliminado: " << aux->dato << " y decimal: " << aux->dato2 << endl;
        delete aux;
        return;
    }

    ant = cab;
    aux = cab->sig;
    i = 2;

    while(aux != NULL && i < pos)
    {
        ant = aux;
        aux = aux->sig;
        i++;
    }

    if(aux != NULL)
    {
        ant->sig = aux->sig;
        cout << "Dato eliminado: " << aux->dato << " y decimal: " << aux->dato2 << endl;
        delete aux;
    }
    else
    {
        cout << "Posicion no valida" << endl;
    }
}

void lista::archivos()
{
    nodo *aux;
    int pos;

    ofstream txt("lista2.txt");

    txt << "PROGRAMA DE LISTA CON NODOS" << endl;
    txt << endl;
    txt << "Lista de datos" << endl;

    aux = cab;
    pos = 1;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            txt << "Dato " << pos << ": " << aux->dato << endl;
            txt << "Decimal " << pos << ": " << aux->dato2 << endl;
            aux = aux->sig;
            pos++;
        }
    }
    else
    {
        txt << "Lista vacia" << endl;
    }

    txt.close();

    ofstream csv("lista2.csv");

    csv << "Posicion,Dato,Decimal" << endl;

    aux = cab;
    pos = 1;

    while(aux != NULL)
    {
        csv << pos << "," << aux->dato << "," << aux->dato2 << endl;
        aux = aux->sig;
        pos++;
    }

    csv.close();

    ofstream xml("lista2.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<lista2>" << endl;

    aux = cab;

    while(aux != NULL)
    {
        xml << "    <nodo>" << endl;
        xml << "        <dato>" << aux->dato << "</dato>" << endl;
        xml << "        <decimal>" << aux->dato2 << "</decimal>" << endl;
        xml << "    </nodo>" << endl;

        aux = aux->sig;
    }

    xml << "</lista2>" << endl;

    xml.close();

    ofstream json("lista2.json");

    json << "{" << endl;
    json << "    \"lista\": [" << endl;

    aux = cab;

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

    ofstream html("lista2.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Lista Nodos</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Lista con Nodos</h2>" << endl;
    html << "  <table><tr><th>Posicion</th><th>Dato</th><th>Decimal</th></tr>" << endl;
    aux = cab;
    pos = 1;
    while(aux != NULL) {
        html << "    <tr><td>" << pos << "</td><td>" << aux->dato << "</td><td>" << aux->dato2 << "</td></tr>" << endl;
        aux = aux->sig;
        pos++;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_lista2.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE LISTA CON NODOS" << endl;
    general << endl;
    general << "Lista de datos" << endl;

    aux = cab;
    pos = 1;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            general << "Dato " << pos << ": " << aux->dato << endl;
            general << "Decimal " << pos << ": " << aux->dato2 << endl;
            aux = aux->sig;
            pos++;
        }
    }
    else
    {
        general << "Lista vacia" << endl;
    }

    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato,Decimal" << endl;

    aux = cab;
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
    general << "<lista2>" << endl;

    aux = cab;

    while(aux != NULL)
    {
        general << "    <nodo>" << endl;
        general << "        <dato>" << aux->dato << "</dato>" << endl;
        general << "        <decimal>" << aux->dato2 << "</decimal>" << endl;
        general << "    </nodo>" << endl;

        aux = aux->sig;
    }

    general << "</lista2>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"lista\": [" << endl;

    aux = cab;

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

    cout << "\n[!] Guardando y abriendo todos los reportes de la lista..." << endl;

    system("start notepad lista2.txt");
    system("start lista2.csv");
    system("start lista2.html");
    system("start lista2.xml");
    system("start lista2.json");
    system("start notepad resultado_lista2.txt");
}

int main()
{
    lista obre;
    int opcion, dato;
    float decimal;

    do
    {
        cout << "\n--- Menu de Lista ---" << endl;
        cout << "1. Insertar datos" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Eliminar dato" << endl;
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

                obre.insertar(obre.cab, dato, decimal);
                break;

            case 2:
                obre.mostrarDatos();
                break;

            case 3:
                obre.eliminarDato();
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
