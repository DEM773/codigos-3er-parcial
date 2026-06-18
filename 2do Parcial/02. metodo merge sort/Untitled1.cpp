#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct dato
{
    int num;
};

class merge
{
    public:
        merge();
        ~merge();

        void leerDatos();
        void ordenarDatos();
        void mostrarDatos();
        void archivos();

    protected:
        dato datos[5];

        void mergeDatos(int izq, int der);
        void unirDatos(int izq, int medio, int der);
};

merge::merge()
{
}

merge::~merge()
{
}

void merge::leerDatos()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Dato " << i + 1 << ": ";
        cin >> datos[i].num;
    }
}

void merge::ordenarDatos()
{
    mergeDatos(0, 4);
}

void merge::mostrarDatos()
{
    cout << "Nuevo tipo de dato ordenado: ";
    for(int i = 0; i < 5; i++)
    {
        cout << datos[i].num << " ";
    }
    cout << endl;
}

void merge::mergeDatos(int izq, int der)
{
    if(izq < der)
    {
        int medio = (izq + der) / 2;
        mergeDatos(izq, medio);
        mergeDatos(medio + 1, der);
        unirDatos(izq, medio, der);
    }
}

void merge::unirDatos(int izq, int medio, int der)
{
    dato aux[5];
    int i = izq;
    int j = medio + 1;
    int k = izq;

    while(i <= medio && j <= der)
    {
        if(datos[i].num < datos[j].num)
        {
            aux[k] = datos[i];
            i++;
        }
        else
        {
            aux[k] = datos[j];
            j++;
        }
        k++;
    }

    while(i <= medio)
    {
        aux[k] = datos[i];
        i++;
        k++;
    }

    while(j <= der)
    {
        aux[k] = datos[j];
        j++;
        k++;
    }

    for(int x = izq; x <= der; x++)
    {
        datos[x] = aux[x];
    }
}

void merge::archivos()
{
    ofstream txt("merge.txt");
    txt << "PROGRAMA METODO MERGE" << endl;
    txt << "Datos ordenados: ";
    for(int i = 0; i < 5; i++)
    {
        txt << datos[i].num << " ";
    }
    txt << endl;
    txt.close();

    ofstream csv("merge.csv");
    csv << "Posicion,Valor" << endl;
    for(int i = 0; i < 5; i++)
    {
        csv << i + 1 << "," << datos[i].num << endl;
    }
    csv.close();

    ofstream xml("merge.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<merge>" << endl;
    for(int i = 0; i < 5; i++)
    {
        xml << "    <dato>" << datos[i].num << "</dato>" << endl;
    }
    xml << "</merge>" << endl;
    xml.close();

    ofstream json("merge.json");
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

    ofstream general("resultado_merge.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA METODO MERGE" << endl;
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
    general << "<merge>" << endl;
    for(int i = 0; i < 5; i++)
    {
        general << "    <dato>" << datos[i].num << "</dato>" << endl;
    }
    general << "</merge>" << endl;
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
        cout << "1. Abrir Merge TXT" << endl;
        cout << "2. Abrir Merge CSV" << endl;
        cout << "3. Abrir Merge XML" << endl;
        cout << "4. Abrir Merge JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad merge.txt");
                break;
            case 2:
                system("start notepad merge.csv");
                break;
            case 3:
                system("start notepad merge.xml");
                break;
            case 4:
                system("start notepad merge.json");
                break;
            case 5:
                system("start notepad resultado_merge.txt");
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
    merge obme;

    cout << endl;
    cout << "NUEVO TIPO DE DATO" << endl;

    obme.leerDatos();
    obme.ordenarDatos();
    obme.mostrarDatos();
    obme.archivos();

    return 0;
}
