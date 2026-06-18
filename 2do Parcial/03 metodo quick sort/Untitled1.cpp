#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct dato
{
    int num;
};

class quick
{
    public:
        quick();
        ~quick();

        void leerDatos();
        void ordenarDatos();
        void mostrarDatos();
        void archivos();

    protected:
        dato datos[5];

        void quickDatos(int izq, int der);
};

quick::quick()
{
}

quick::~quick()
{
}

void quick::leerDatos()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Dato " << i + 1 << ": ";
        cin >> datos[i].num;
    }
}

void quick::ordenarDatos()
{
    quickDatos(0, 4);
}

void quick::mostrarDatos()
{
    cout << "Nuevo tipo de dato ordenado: ";
    for(int i = 0; i < 5; i++)
    {
        cout << datos[i].num << " ";
    }
    cout << endl;
}

void quick::quickDatos(int izq, int der)
{
    int i = izq;
    int j = der;
    int pivote = datos[(izq + der) / 2].num;
    dato aux;

    while(i <= j)
    {
        while(datos[i].num < pivote)
        {
            i++;
        }

        while(datos[j].num > pivote)
        {
            j--;
        }

        if(i <= j)
        {
            aux = datos[i];
            datos[i] = datos[j];
            datos[j] = aux;

            i++;
            j--;
        }
    }

    if(izq < j)
    {
        quickDatos(izq, j);
    }

    if(i < der)
    {
        quickDatos(i, der);
    }
}

void quick::archivos()
{
    ofstream txt("quick.txt");
    txt << "PROGRAMA METODO QUICK" << endl;
    txt << "Datos ordenados: ";
    for(int i = 0; i < 5; i++)
    {
        txt << datos[i].num << " ";
    }
    txt << endl;
    txt.close();

    ofstream csv("quick.csv");
    csv << "Posicion,Valor" << endl;
    for(int i = 0; i < 5; i++)
    {
        csv << i + 1 << "," << datos[i].num << endl;
    }
    csv.close();

    ofstream xml("quick.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<quick>" << endl;
    for(int i = 0; i < 5; i++)
    {
        xml << "    <dato>" << datos[i].num << "</dato>" << endl;
    }
    xml << "</quick>" << endl;
    xml.close();

    ofstream json("quick.json");
    json << "{" << endl;
    json << "    \"datosOrdenados\": [" << endl;
    for(int i = 0; i < 5; i++)
    {
        json << "        " << datos[i].num;
        if(i < 4)
        {
            json << ",";
        }
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_quick.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA METODO QUICK" << endl;
    general << "Datos ordenados: ";
    for(int i = 0; i < 5; i++)
    {
        general << datos[i].num << " ";
    }
    general << endl << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Valor" << endl;
    for(int i = 0; i < 5; i++)
    {
        general << i + 1 << "," << datos[i].num << endl;
    }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<quick>" << endl;
    for(int i = 0; i < 5; i++)
    {
        general << "    <dato>" << datos[i].num << "</dato>" << endl;
    }
    general << "</quick>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"datosOrdenados\": [" << endl;
    for(int i = 0; i < 5; i++)
    {
        general << "        " << datos[i].num;
        if(i < 4)
        {
            general << ",";
        }
        general << endl;
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
        cout << "1. Abrir Quick TXT" << endl;
        cout << "2. Abrir Quick CSV" << endl;
        cout << "3. Abrir Quick XML" << endl;
        cout << "4. Abrir Quick JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad quick.txt");
                break;
            case 2:
                system("start notepad quick.csv");
                break;
            case 3:
                system("start notepad quick.xml");
                break;
            case 4:
                system("start notepad quick.json");
                break;
            case 5:
                system("start notepad resultado_quick.txt");
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
    quick obqu;

    cout << endl;
    cout << "NUEVO TIPO DE DATO" << endl;

    obqu.leerDatos();
    obqu.ordenarDatos();
    obqu.mostrarDatos();
    obqu.archivos();

    return 0;
}
