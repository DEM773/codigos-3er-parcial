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

class lista
{
    public:
        lista();
        ~lista();

        void guardarDatos();
        void mostrarDatos();
        void archivos();

    protected:
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

void lista::guardarDatos()
{
    int x;
    nodo *nuevo, *aux;

    for(int i = 0; i < 5; i++)
    {
        cout << "dato " << i + 1 << ": ";
        cin >> x;

        nuevo = new nodo();
        nuevo->dato = x;
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
    }
}

void lista::mostrarDatos()
{
    nodo *aux;

    cout << endl;
    cout << "lista de datos" << endl;

    aux = cab;

    while(aux != NULL)
    {
        cout << "dato: " << aux->dato << endl;
        aux = aux->sig;
    }
}

void lista::archivos()
{
    nodo *aux;
    int pos;

    
    ofstream txt("lista.txt");
    txt << "PROGRAMA DE LISTA SIMPLE" << endl;
    txt << endl;
    txt << "Lista de datos" << endl;
    aux = cab;
    while(aux != NULL)
    {
        txt << "Dato: " << aux->dato << endl;
        aux = aux->sig;
    }
    txt.close();

    
    ofstream csv("lista.csv");
    csv << "Posicion,Dato" << endl;
    aux = cab;
    pos = 1;
    while(aux != NULL)
    {
        csv << pos << "," << aux->dato << endl;
        aux = aux->sig;
        pos++;
    }
    csv.close();

  
    ofstream xml("lista.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<lista>" << endl;
    aux = cab;
    while(aux != NULL)
    {
        xml << "    <dato>" << aux->dato << "</dato>" << endl;
        aux = aux->sig;
    }
    xml << "</lista>" << endl;
    xml.close();

    
    ofstream json("lista.json");
    json << "{" << endl;
    json << "    \"datos\": [" << endl;
    aux = cab;
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
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();


    ofstream general("resultado_lista.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE LISTA SIMPLE" << endl << endl;
    general << "Lista de datos" << endl;
    aux = cab;
    while(aux != NULL)
    {
        general << "Dato: " << aux->dato << endl;
        aux = aux->sig;
    }
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato" << endl;
    aux = cab;
    pos = 1;
    while(aux != NULL)
    {
        general << pos << "," << aux->dato << endl;
        aux = aux->sig;
        pos++;
    }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; // Inyección de cabecera XML exitosa
    general << "<lista>" << endl;
    aux = cab;
    while(aux != NULL)
    {
        general << "    <dato>" << aux->dato << "</dato>" << endl;
        aux = aux->sig;
    }
    general << "</lista>" << endl << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"datos\": [" << endl;
    aux = cab;
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
    general << "    ]" << endl;
    general << "}" << endl;
    general.close();

    
    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Lista TXT" << endl;
        cout << "2. Abrir Lista CSV" << endl;
        cout << "3. Abrir Lista XML" << endl;
        cout << "4. Abrir Lista JSON" << endl;
        cout << "5. Abrir Reporte General Unificado" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad lista.txt");
                break;
            case 2:
                system("start notepad lista.csv");
                break;
            case 3:
                system("start notepad lista.xml");
                break;
            case 4:
                system("start notepad lista.json");
                break;
            case 5:
                system("start notepad resultado_lista.txt");
                break;
            case 6:
                cout << "Saliendo del menu..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(opcion != 6); 
}

int main()
{
    lista obre;

    obre.guardarDatos();
    obre.mostrarDatos();
    obre.archivos();

    return 0;
}
