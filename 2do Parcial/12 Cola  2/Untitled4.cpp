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

class cola
{
    public:
        cola();
        ~cola();

        void guardarDatos();
        void insertar(nodo *&frente, nodo *&fin, int x, float y);
        void mostrarDatos();
        void sacarDato();
        void archivos();

        nodo *frente;
        nodo *fin;
};

cola::cola()
{
    frente = NULL;
    fin = NULL;
}

cola::~cola()
{
    nodo *aux;

    while(frente != NULL)
    {
        aux = frente;
        frente = frente->sig;
        delete aux;
    }

    fin = NULL;
}

void cola::insertar(nodo *&frente, nodo *&fin, int x, float y)
{
    nodo *nuevo;

    nuevo = new nodo();

    nuevo->dato = x;
    nuevo->dato2 = y;
    nuevo->sig = NULL;

    if(frente == NULL)
    {
        frente = nuevo;
        fin = nuevo;
    }
    else
    {
        fin->sig = nuevo;
        fin = nuevo;
    }
}

void cola::guardarDatos()
{
    int x;
    float y;

    for(int i = 0; i < 5; i++)
    {
        cout << "dato " << i + 1 << ": ";
        cin >> x;

        cout << "decimal " << i + 1 << ": ";
        cin >> y;

        insertar(frente, fin, x, y);
    }
}

void cola::mostrarDatos()
{
    nodo *aux;

    aux = frente;

    if(aux != NULL)
    {
        cout << "\ncola de datos" << endl;

        while(aux != NULL)
        {
            cout << "dato: " << aux->dato << endl;
            cout << "decimal: " << aux->dato2 << endl;
            aux = aux->sig;
        }
    }
    else
    {
        cout << "no hay datos" << endl;
    }
}

void cola::sacarDato()
{
    nodo *aux;

    if(frente != NULL)
    {
        aux = frente;

        cout << "eliminado: " << aux->dato << endl;
        cout << "decimal eliminado: " << aux->dato2 << endl;

        frente = frente->sig;

        if(frente == NULL)
        {
            fin = NULL;
        }

        delete aux;
    }
    else
    {
        cout << "cola vacia" << endl;
    }
}

void cola::archivos()
{
    nodo *aux;

    ofstream txt("cola2.txt");

    txt << "PROGRAMA DE COLA CON NODOS" << endl;
    txt << endl;
    txt << "Cola de datos" << endl;

    aux = frente;

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
        txt << "Cola vacia" << endl;
    }

    txt.close();

    ofstream csv("cola2.csv");

    csv << "Posicion,Dato,Decimal" << endl;

    aux = frente;
    int pos = 1;

    while(aux != NULL)
    {
        csv << pos << "," << aux->dato << "," << aux->dato2 << endl;
        aux = aux->sig;
        pos++;
    }

    csv.close();

    ofstream xml("cola2.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<cola2>" << endl;

    aux = frente;

    while(aux != NULL)
    {
        xml << "    <nodo>" << endl;
        xml << "        <dato>" << aux->dato << "</dato>" << endl;
        xml << "        <decimal>" << aux->dato2 << "</decimal>" << endl;
        xml << "    </nodo>" << endl;

        aux = aux->sig;
    }

    xml << "</cola2>" << endl;

    xml.close();

    ofstream json("cola2.json");

    json << "{" << endl;
    json << "    \"cola\": [" << endl;

    aux = frente;

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

    ofstream html("cola2.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Cola Nodos</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Cola con Nodos</h2>" << endl;
    html << "  <table><tr><th>Posicion</th><th>Dato</th><th>Decimal</th></tr>" << endl;
    aux = frente;
    pos = 1;
    while(aux != NULL) {
        html << "    <tr><td>" << pos << "</td><td>" << aux->dato << "</td><td>" << aux->dato2 << "</td></tr>" << endl;
        aux = aux->sig;
        pos++;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_cola2.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE COLA CON NODOS" << endl;
    general << endl;
    general << "Cola de datos" << endl;

    aux = frente;

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
        general << "Cola vacia" << endl;
    }

    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato,Decimal" << endl;

    aux = frente;
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
    general << "<cola2>" << endl;

    aux = frente;

    while(aux != NULL)
    {
        general << "    <nodo>" << endl;
        general << "        <dato>" << aux->dato << "</dato>" << endl;
        general << "        <decimal>" << aux->dato2 << "</decimal>" << endl;
        general << "    </nodo>" << endl;

        aux = aux->sig;
    }

    general << "</cola2>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"cola\": [" << endl;

    aux = frente;

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

    general << "     ]" << endl;
    general << "}" << endl;

    general.close();

    cout << "\n[!] Guardando y abriendo todos los reportes de la cola..." << endl;

    system("start notepad cola2.txt");
    system("start cola2.csv");
    system("start cola2.html");
    system("start cola2.xml");
    system("start cola2.json");
    system("start notepad resultado_cola2.txt");
}

int main()
{
    cola obre;
    int opcion;
    int x;
    float y;

    do
    {
        cout << "\n--- Menu de Cola ---" << endl;
        cout << "1. Insertar dato" << endl;
        cout << "2. Mostrar datos" << endl;
        cout << "3. Eliminar dato" << endl;
        cout << "4. Salir y Abrir Archivos" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Ingresa entero: ";
                cin >> x;

                cout << "Ingresa decimal: ";
                cin >> y;

                obre.insertar(obre.frente, obre.fin, x, y);
                break;

            case 2:
                obre.mostrarDatos();
                break;

            case 3:
                obre.sacarDato();
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
