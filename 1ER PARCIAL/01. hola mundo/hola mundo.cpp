#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class HMundo
{
public:
    HMundo();
    ~HMundo();

    void saludo();
    void crearTXT();
    void crearCSV();
    void crearXML();
    void crearJSON();
    void crearTodoJunto();
};

HMundo::HMundo()
{
}

HMundo::~HMundo()
{
}

void HMundo::saludo()
{
    cout << "Hola Mundo" << endl;
}

void HMundo::crearTXT()
{
    ofstream archivo("hola_mundo.txt");

    archivo << "Hola Mundo" << endl;

    archivo.close();
}

void HMundo::crearCSV()
{
    ofstream archivo("hola_mundo.csv");

    archivo << "Mensaje" << endl;
    archivo << "Hola Mundo" << endl;

    archivo.close();
}

void HMundo::crearXML()
{
    ofstream archivo("hola_mundo.xml");

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    archivo << "<mensaje>" << endl;
    archivo << "    <texto>Hola Mundo</texto>" << endl;
    archivo << "</mensaje>" << endl;

    archivo.close();
}

void HMundo::crearJSON()
{
    ofstream archivo("hola_mundo.json");

    archivo << "{" << endl;
    archivo << "    \"mensaje\": \"Hola Mundo\"" << endl;
    archivo << "}" << endl;

    archivo.close();
}

void HMundo::crearTodoJunto()
{
    ofstream archivo("resultado_general.txt");

    archivo << "ARCHIVO TXT" << endl;
    archivo << "Hola Mundo" << endl;
    archivo << endl;

    archivo << "ARCHIVO CSV" << endl;
    archivo << "Mensaje" << endl;
    archivo << "Hola Mundo" << endl;
    archivo << endl;

    archivo << "ARCHIVO XML" << endl;
    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    archivo << "<mensaje>" << endl;
    archivo << "    <texto>Hola Mundo</texto>" << endl;
    archivo << "</mensaje>" << endl;
    archivo << endl;

    archivo << "ARCHIVO JSON" << endl;
    archivo << "{" << endl;
    archivo << "    \"mensaje\": \"Hola Mundo\"" << endl;
    archivo << "}" << endl;

    archivo.close();
}

int main()
{
    HMundo obM;
    int opcion;

    do
    {
        cout << "\n===== MENU DE ARCHIVOS =====" << endl;
        cout << "1. Crear archivo TXT" << endl;
        cout << "2. Crear archivo CSV" << endl;
        cout << "3. Crear archivo XML" << endl;
        cout << "4. Crear archivo JSON" << endl;
        cout << "5. Crear todos los archivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                obM.crearTXT();
                system("start notepad hola_mundo.txt");
                break;

            case 2:
                obM.crearCSV();
                system("start notepad hola_mundo.csv");
                break;

            case 3:
                obM.crearXML();
                system("start notepad hola_mundo.xml");
                break;

            case 4:
                obM.crearJSON();
                system("start notepad hola_mundo.json");
                break;

            case 5:
                obM.crearTXT();
                obM.crearCSV();
                obM.crearXML();
                obM.crearJSON();
                obM.crearTodoJunto();
                system("start notepad resultado_general.txt");
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while(opcion != 0);

    return 0;
}
