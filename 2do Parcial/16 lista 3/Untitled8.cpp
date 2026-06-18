#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>

using namespace std;

class lista
{
    public:
        lista();
        ~lista();

        void insertar(int x, float y);
        void mostrarDatos();
        void eliminarDato();
        void archivos();

    private:
        list<int> datos;
        list<float> datos2;
};

lista::lista()
{
}

lista::~lista()
{
}

void lista::insertar(int x, float y)
{
    datos.push_back(x);
    datos2.push_back(y);
    cout << "Datos insertados" << endl;
}

void lista::mostrarDatos()
{
    list<int>::iterator it;
    list<float>::iterator it2;
    int i = 1;

    if(datos.empty() || datos2.empty())
    {
        cout << "No hay elementos en la lista" << endl;
        return;
    }

    cout << endl;
    cout << "Lista de datos" << endl;

    it = datos.begin();
    it2 = datos2.begin();

    while(it != datos.end() && it2 != datos2.end())
    {
        cout << "Dato " << i << ": " << *it << endl;
        cout << "Decimal " << i << ": " << *it2 << endl;

        it++;
        it2++;
        i++;
    }
}

void lista::eliminarDato()
{
    int pos;
    int i = 1;
    list<int>::iterator it;
    list<float>::iterator it2;

    if(datos.empty() || datos2.empty())
    {
        cout << "Lista vacia" << endl;
        return;
    }

    cout << "Posicion a eliminar: ";
    cin >> pos;

    it = datos.begin();
    it2 = datos2.begin();

    while(it != datos.end() && it2 != datos2.end())
    {
        if(i == pos)
        {
            cout << "Dato eliminado: " << *it << endl;
            cout << "Decimal eliminado: " << *it2 << endl;

            datos.erase(it);
            datos2.erase(it2);

            return;
        }

        i++;
        it++;
        it2++;
    }

    cout << "Posicion no valida" << endl;
}

void lista::archivos()
{
    list<int>::iterator it;
    list<float>::iterator it2;
    int pos;

    ofstream txt("lista2.txt");

    txt << "PROGRAMA DE LISTA CON LIST" << endl;
    txt << endl;
    txt << "Lista de datos" << endl;

    if(datos.empty() || datos2.empty())
    {
        txt << "Lista vacia" << endl;
    }
    else
    {
        it = datos.begin();
        it2 = datos2.begin();
        pos = 1;

        while(it != datos.end() && it2 != datos2.end())
        {
            txt << "Dato " << pos << ": " << *it << endl;
            txt << "Decimal " << pos << ": " << *it2 << endl;

            it++;
            it2++;
            pos++;
        }
    }

    txt.close();

    ofstream csv("lista2.csv");

    csv << "Posicion,Dato,Decimal" << endl;

    it = datos.begin();
    it2 = datos2.begin();
    pos = 1;

    while(it != datos.end() && it2 != datos2.end())
    {
        csv << pos << "," << *it << "," << *it2 << endl;

        it++;
        it2++;
        pos++;
    }

    csv.close();

    ofstream xml("lista2.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<lista2>" << endl;

    it = datos.begin();
    it2 = datos2.begin();

    while(it != datos.end() && it2 != datos2.end())
    {
        xml << "    <dato>" << endl;
        xml << "        <entero>" << *it << "</entero>" << endl;
        xml << "        <decimal>" << *it2 << "</decimal>" << endl;
        xml << "    </dato>" << endl;

        it++;
        it2++;
    }

    xml << "</lista2>" << endl;

    xml.close();

    ofstream json("lista2.json");

    json << "{" << endl;
    json << "    \"lista\": [" << endl;

    it = datos.begin();
    it2 = datos2.begin();

    while(it != datos.end() && it2 != datos2.end())
    {
        json << "        {" << endl;
        json << "            \"dato\": " << *it << "," << endl;
        json << "            \"decimal\": " << *it2 << endl;
        json << "        }";

        it++;
        it2++;

        if(it != datos.end() && it2 != datos2.end())
        {
            json << ",";
        }

        json << endl;
    }

    json << "    ]" << endl;
    json << "}" << endl;

    json.close();

    ofstream html("lista2.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Lista List</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Lista con std::list</h2>" << endl;
    html << "  <table><tr><th>Posicion</th><th>Dato</th><th>Decimal</th></tr>" << endl;
    it = datos.begin();
    it2 = datos2.begin();
    pos = 1;
    while(it != datos.end() && it2 != datos2.end()) {
        html << "    <tr><td>" << pos << "</td><td>" << *it << "</td><td>" << *it2 << "</td></tr>" << endl;
        it++;
        it2++;
        pos++;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_lista2.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE LISTA CON LIST" << endl;
    general << endl;
    general << "Lista de datos" << endl;

    if(datos.empty() || datos2.empty())
    {
        general << "Lista vacia" << endl;
    }
    else
    {
        it = datos.begin();
        it2 = datos2.begin();
        pos = 1;

        while(it != datos.end() && it2 != datos2.end())
        {
            general << "Dato " << pos << ": " << *it << endl;
            general << "Decimal " << pos << ": " << *it2 << endl;

            it++;
            it2++;
            pos++;
        }
    }

    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato,Decimal" << endl;

    it = datos.begin();
    it2 = datos2.begin();
    pos = 1;

    while(it != datos.end() && it2 != datos2.end())
    {
        general << pos << "," << *it << "," << *it2 << endl;

        it++;
        it2++;
        pos++;
    }

    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<lista2>" << endl;

    it = datos.begin();
    it2 = datos2.begin();

    while(it != datos.end() && it2 != datos2.end())
    {
        general << "    <dato>" << endl;
        general << "        <entero>" << *it << "</entero>" << endl;
        general << "        <decimal>" << *it2 << "</decimal>" << endl;
        general << "    </dato>" << endl;

        it++;
        it2++;
    }

    general << "</lista2>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"lista\": [" << endl;

    it = datos.begin();
    it2 = datos2.begin();

    while(it != datos.end() && it2 != datos2.end())
    {
        general << "        {" << endl;
        general << "            \"dato\": " << *it << "," << endl;
        general << "            \"decimal\": " << *it2 << endl;
        general << "        }";

        it++;
        it2++;

        if(it != datos.end() && it2 != datos2.end())
        {
            general << ",";
        }

        general << endl;
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

                obre.insertar(dato, decimal);
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
