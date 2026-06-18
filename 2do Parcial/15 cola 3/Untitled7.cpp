#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>

using namespace std;

class cola
{
    public:
        cola();
        ~cola();

        void insertar(int x, float y);
        void mostrarDatos();
        void sacarDato();
        void archivos();

    private:
        queue<int> datos;
        queue<float> datos2;
};

cola::cola()
{
}

cola::~cola()
{
}

void cola::insertar(int x, float y)
{
    datos.push(x);
    datos2.push(y);
    cout << "Datos insertados" << endl;
}

void cola::mostrarDatos()
{
    queue<int> aux;
    queue<float> aux2;

    if(datos.empty() || datos2.empty())
    {
        cout << "No hay elementos en la cola" << endl;
        return;
    }

    cout << endl;
    cout << "Cola de datos" << endl;

    aux = datos;
    aux2 = datos2;

    while(!aux.empty() && !aux2.empty())
    {
        cout << "Dato: " << aux.front() << endl;
        cout << "Decimal: " << aux2.front() << endl;

        aux.pop();
        aux2.pop();
    }
}

void cola::sacarDato()
{
    if(!datos.empty() && !datos2.empty())
    {
        cout << "Dato eliminado: " << datos.front() << endl;
        cout << "Decimal eliminado: " << datos2.front() << endl;

        datos.pop();
        datos2.pop();
    }
    else
    {
        cout << "Cola vacia" << endl;
    }
}

void cola::archivos()
{
    queue<int> aux;
    queue<float> aux2;
    int pos;

    ofstream txt("cola2.txt");

    txt << "PROGRAMA DE COLA CON QUEUE" << endl;
    txt << endl;
    txt << "Cola de datos" << endl;

    aux = datos;
    aux2 = datos2;
    pos = 1;

    if(aux.empty() || aux2.empty())
    {
        txt << "Cola vacia" << endl;
    }
    else
    {
        while(!aux.empty() && !aux2.empty())
        {
            txt << "Dato " << pos << ": " << aux.front() << endl;
            txt << "Decimal " << pos << ": " << aux2.front() << endl;

            aux.pop();
            aux2.pop();
            pos++;
        }
    }

    txt.close();

    ofstream csv("cola2.csv");

    csv << "Posicion,Dato,Decimal" << endl;

    aux = datos;
    aux2 = datos2;
    pos = 1;

    while(!aux.empty() && !aux2.empty())
    {
        csv << pos << "," << aux.front() << "," << aux2.front() << endl;

        aux.pop();
        aux2.pop();
        pos++;
    }

    csv.close();

    ofstream xml("cola2.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<cola2>" << endl;

    aux = datos;
    aux2 = datos2;

    while(!aux.empty() && !aux2.empty())
    {
        xml << "    <dato>" << endl;
        xml << "        <entero>" << aux.front() << "</entero>" << endl;
        xml << "        <decimal>" << aux2.front() << "</decimal>" << endl;
        xml << "    </dato>" << endl;

        aux.pop();
        aux2.pop();
    }

    xml << "</cola2>" << endl;

    xml.close();

    ofstream json("cola2.json");

    json << "{" << endl;
    json << "    \"cola\": [" << endl;

    aux = datos;
    aux2 = datos2;

    while(!aux.empty() && !aux2.empty())
    {
        json << "        {" << endl;
        json << "            \"dato\": " << aux.front() << "," << endl;
        json << "            \"decimal\": " << aux2.front() << endl;
        json << "        }";

        aux.pop();
        aux2.pop();

        if(!aux.empty() && !aux2.empty())
        {
            json << ",";
        }

        json << endl;
    }

    json << "    ]" << endl;
    json << "}" << endl;

    json.close();

    ofstream html("cola2.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Cola Queue</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Cola con Queue</h2>" << endl;
    html << "  <table><tr><th>Posicion</th><th>Dato</th><th>Decimal</th></tr>" << endl;
    aux = datos;
    aux2 = datos2;
    pos = 1;
    while(!aux.empty() && !aux2.empty()) {
        html << "    <tr><td>" << pos << "</td><td>" << aux.front() << "</td><td>" << aux2.front() << "</td></tr>" << endl;
        aux.pop();
        aux2.pop();
        pos++;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_cola2.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE COLA CON QUEUE" << endl;
    general << endl;
    general << "Cola de datos" << endl;

    aux = datos;
    aux2 = datos2;
    pos = 1;

    if(aux.empty() || aux2.empty())
    {
        general << "Cola vacia" << endl;
    }
    else
    {
        while(!aux.empty() && !aux2.empty())
        {
            general << "Dato " << pos << ": " << aux.front() << endl;
            general << "Decimal " << pos << ": " << aux2.front() << endl;

            aux.pop();
            aux2.pop();
            pos++;
        }
    }

    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato,Decimal" << endl;

    aux = datos;
    aux2 = datos2;
    pos = 1;

    while(!aux.empty() && !aux2.empty())
    {
        general << pos << "," << aux.front() << "," << aux2.front() << endl;

        aux.pop();
        aux2.pop();
        pos++;
    }

    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<cola2>" << endl;

    aux = datos;
    aux2 = datos2;

    while(!aux.empty() && !aux2.empty())
    {
        general << "    <dato>" << endl;
        general << "        <entero>" << aux.front() << "</entero>" << endl;
        general << "        <decimal>" << aux2.front() << "</decimal>" << endl;
        general << "    </dato>" << endl;

        aux.pop();
        aux2.pop();
    }

    general << "</cola2>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"cola\": [" << endl;

    aux = datos;
    aux2 = datos2;

    while(!aux.empty() && !aux2.empty())
    {
        general << "        {" << endl;
        general << "            \"dato\": " << aux.front() << "," << endl;
        general << "            \"decimal\": " << aux2.front() << endl;
        general << "        }";

        aux.pop();
        aux2.pop();

        if(!aux.empty() && !aux2.empty())
        {
            general << ",";
        }

        general << endl;
    }

    general << "    ]" << endl;
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
    int opcion, dato;
    float decimal;

    do
    {
        cout << "\n--- Menu de Cola ---" << endl;
        cout << "1. Insertar datos" << endl;
        cout << "2. Quitar dato" << endl;
        cout << "3. Mostrar cola" << endl;
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

                obre.insertar(dato, decimal);
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
