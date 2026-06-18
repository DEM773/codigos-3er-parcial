#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct dato
{
    int num;
};

class burbuja
{
    public:
        burbuja();
        ~burbuja();

        void leerDatos();
        void ordenarDatos();
        void mostrarDatos();
        void archivos();

    protected:
        dato datos[5];
};

burbuja::burbuja()
{
}

burbuja::~burbuja()
{
}

void burbuja::leerDatos()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Dato " << i + 1 << ": ";
        cin >> datos[i].num;
    }
}

void burbuja::ordenarDatos()
{
    dato aux;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4 - i; j++)
        {
            if(datos[j].num > datos[j + 1].num)
            {
                aux = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = aux;
            }
        }
    }
}

void burbuja::mostrarDatos()
{
    cout << "Nuevo tipo de dato ordenado: ";
    for(int i = 0; i < 5; i++)
    {
        cout << datos[i].num << " ";
    }
    cout << endl;
}

void burbuja::archivos()
{
    ofstream txt("burbuja.txt");
    txt << "PROGRAMA METODO BURBUJA" << endl;
    txt << "Datos ordenados: ";
    for(int i = 0; i < 5; i++)
    {
        txt << datos[i].num << " ";
    }
    txt << endl;
    txt.close();

    ofstream csv("burbuja.csv");
    csv << "Posicion,Valor" << endl;
    for(int i = 0; i < 5; i++)
    {
        csv << i + 1 << "," << datos[i].num << endl;
    }
    csv.close();

    ofstream xml("burbuja.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<burbuja>" << endl;
    for(int i = 0; i < 5; i++)
    {
        xml << "    <dato>" << datos[i].num << "</dato>" << endl;
    }
    xml << "</burbuja>" << endl;
    xml.close();

    ofstream json("burbuja.json");
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

    ofstream general("resultado_burbuja.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA METODO BURBUJA" << endl;
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
    general << "<burbuja>" << endl;
    for(int i = 0; i < 5; i++)
    {
        general << "    <dato>" << datos[i].num << "</dato>" << endl;
    }
    general << "</burbuja>" << endl;
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
        cout << "1. Abrir Burbuja TXT" << endl;
        cout << "2. Abrir Burbuja CSV" << endl;
        cout << "3. Abrir Burbuja XML" << endl;
        cout << "4. Abrir Burbuja JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad burbuja.txt");
                break;
            case 2:
                system("start notepad burbuja.csv");
                break;
            case 3:
                system("start notepad burbuja.xml");
                break;
            case 4:
                system("start notepad burbuja.json");
                break;
            case 5:
                system("start notepad resultado_burbuja.txt");
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
    burbuja obbu;

    cout << endl;
    cout << "NUEVO TIPO DE DATO" << endl;

    obbu.leerDatos();
    obbu.ordenarDatos();
    obbu.mostrarDatos();
    obbu.archivos();

    return 0;
}
