#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class pilaF
{
    public:
        pilaF();
        ~pilaF();

        void insertar(float x);
        void sacarDato();
        void mostrarPila();

        bool estaVacia();
        bool estaLlena();
        int tamano();

        void archivos();

    protected:
        float datos[5];
        int tope;
};

pilaF::pilaF()
{
    tope = -1;
}

pilaF::~pilaF()
{
}

void pilaF::insertar(float x)
{
    if(tope < 4)
    {
        tope++;
        datos[tope] = x;
        cout << "Dato insertado" << endl;
    }
    else
    {
        cout << "Pila llena" << endl;
    }
}

void pilaF::sacarDato()
{
    if(tope >= 0)
    {
        cout << "Dato eliminado: " << datos[tope] << endl;
        tope--;
    }
    else
    {
        cout << "Pila vacia" << endl;
    }
}

void pilaF::mostrarPila()
{
    if(tope >= 0)
    {
        cout << "\nContenido de la pila:" << endl;

        for(int i = tope; i >= 0; i--)
        {
            cout << datos[i] << endl;
        }
    }
    else
    {
        cout << "No hay elementos en la pila" << endl;
    }
}

bool pilaF::estaVacia()
{
    return (tope == -1);
}

bool pilaF::estaLlena()
{
    return (tope == 4);
}

int pilaF::tamano()
{
    return tope + 1;
}

void pilaF::archivos()
{
    
    ofstream txt("pilaF.txt");
    txt << "PROGRAMA DE PILA FLOAT" << endl;
    txt << endl;
    txt << "Tamano: " << tamano() << endl;

    if(tope >= 0)
    {
        txt << "Contenido de la pila:" << endl;
        for(int i = tope; i >= 0; i--)
        {
            txt << datos[i] << endl;
        }
    }
    else
    {
        txt << "Pila vacia" << endl;
    }
    txt.close();

    
    ofstream csv("pilaF.csv");
    csv << "Posicion,Dato" << endl;
    for(int i = tope; i >= 0; i--)
    {
        csv << i << "," << datos[i] << endl;
    }
    csv.close();

    
    ofstream xml("pilaF.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<pilaF>" << endl;
    xml << "    <tamano>" << tamano() << "</tamano>" << endl;
    xml << "    <datos>" << endl;
    for(int i = tope; i >= 0; i--)
    {
        xml << "        <dato>" << datos[i] << "</dato>" << endl;
    }
    xml << "    </datos>" << endl;
    xml << "</pilaF>" << endl;
    xml.close();

    
    ofstream json("pilaF.json");
    json << "{" << endl;
    json << "    \"tamano\": " << tamano() << "," << endl;
    json << "    \"datos\": [" << endl;
    for(int i = tope; i >= 0; i--)
    {
        json << "        " << datos[i];
        if(i > 0)
        {
            json << ",";
        }
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    
    ofstream general("resultado_pilaF.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE PILA FLOAT" << endl;
    general << endl;
    general << "Tamano: " << tamano() << endl;

    if(tope >= 0)
    {
        general << "Contenido de la pila:" << endl;
        for(int i = tope; i >= 0; i--)
        {
            general << datos[i] << endl;
        }
    }
    else
    {
        general << "Pila vacia" << endl;
    }
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Dato" << endl;
    for(int i = tope; i >= 0; i--)
    {
        general << i << "," << datos[i] << endl;
    }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; 
    general << "<pilaF>" << endl;
    general << "    <tamano>" << tamano() << "</tamano>" << endl;
    general << "    <datos>" << endl;
    for(int i = tope; i >= 0; i--)
    {
        general << "        <dato>" << datos[i] << "</dato>" << endl;
    }
    general << "    </datos>" << endl;
    general << "</pilaF>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"tamano\": " << tamano() << "," << endl;
    general << "    \"datos\": [" << endl;
    for(int i = tope; i >= 0; i--)
    {
        general << "        " << datos[i];
        if(i > 0)
        {
            general << ",";
        }
        general << endl;
    }
    general << "    ]" << endl;
    general << "}" << endl;
    general.close();

    
    int subOpcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Pila TXT" << endl;
        cout << "2. Abrir Pila CSV" << endl;
        cout << "3. Abrir Pila XML" << endl;
        cout << "4. Abrir Pila JSON" << endl;
        cout << "5. Abrir Reporte General Unificado" << endl;
        cout << "6. Terminar ejecucion" << endl;
        cout << "Seleccione una opcion: ";
        cin >> subOpcion;

        switch(subOpcion)
        {
            case 1:
                system("start notepad pilaF.txt");
                break;
            case 2:
                system("start notepad pilaF.csv");
                break;
            case 3:
                system("start notepad pilaF.xml");
                break;
            case 4:
                system("start notepad pilaF.json");
                break;
            case 5:
                system("start notepad resultado_pilaF.txt");
                break;
            case 6:
                cout << "Saliendo y finalizando programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(subOpcion != 6);
}

int main()
{
    pilaF obre;
    int opcion;
    float dato;

    do
    {
        cout << "\n--- Menu de Pila Float ---" << endl;
        cout << "1. Agregar elemento" << endl;
        cout << "2. Quitar elemento" << endl;
        cout << "3. Mostrar pila" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Verificar si esta llena" << endl;
        cout << "6. Mostrar tamano" << endl;
        cout << "7. Salir y Guardar Archivos" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Ingresa el dato: ";
                cin >> dato;
                obre.insertar(dato);
                break;

            case 2:
                obre.sacarDato();
                break;

            case 3:
                obre.mostrarPila();
                break;

            case 4:
                cout << (obre.estaVacia() ? "Pila vacia" : "No esta vacia") << endl;
                break;

            case 5:
                cout << (obre.estaLlena() ? "Pila llena" : "No esta llena") << endl;
                break;

            case 6:
                cout << "Tamano: " << obre.tamano() << endl;
                break;

            case 7:
                obre.archivos();
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    } while(opcion != 7);

    return 0;
}
