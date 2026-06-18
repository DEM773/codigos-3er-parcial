#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Sum
{
public:
    Sum();
    ~Sum();

    int suma(int a, int b);
    void resultado();

    void crearTXT(int a, int b, int res);
    void crearCSV(int a, int b, int res);
    void crearXML(int a, int b, int res);
    void crearJSON(int a, int b, int res);
    void crearTodoJunto(int a, int b, int res);
};

Sum::Sum()
{
}

Sum::~Sum()
{
}

int Sum::suma(int a, int b)
{
    return a + b;
}

void Sum::crearTXT(int a, int b, int res)
{
    ofstream archivo("suma.txt");

    archivo << "PROGRAMA DE SUMA" << endl;
    archivo << "Numero a: " << a << endl;
    archivo << "Numero b: " << b << endl;
    archivo << "Resultado: " << res << endl;

    archivo.close();
}

void Sum::crearCSV(int a, int b, int res)
{
    ofstream archivo("suma.csv");

    archivo << "Numero A,Numero B,Resultado" << endl;
    archivo << a << "," << b << "," << res << endl;

    archivo.close();
}

void Sum::crearXML(int a, int b, int res)
{
    ofstream archivo("suma.xml");

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    archivo << "<suma>" << endl;
    archivo << "    <numeroA>" << a << "</numeroA>" << endl;
    archivo << "    <numeroB>" << b << "</numeroB>" << endl;
    archivo << "    <resultado>" << res << "</resultado>" << endl;
    archivo << "</suma>" << endl;

    archivo.close();
}

void Sum::crearJSON(int a, int b, int res)
{
    ofstream archivo("suma.json");

    archivo << "{" << endl;
    archivo << "    \"numeroA\": " << a << "," << endl;
    archivo << "    \"numeroB\": " << b << "," << endl;
    archivo << "    \"resultado\": " << res << endl;
    archivo << "}" << endl;

    archivo.close();
}

void Sum::crearTodoJunto(int a, int b, int res)
{
    ofstream archivo("resultado_suma.txt");

    archivo << "ARCHIVO TXT" << endl;
    archivo << "PROGRAMA DE SUMA" << endl;
    archivo << "Numero a: " << a << endl;
    archivo << "Numero b: " << b << endl;
    archivo << "Resultado: " << res << endl;
    archivo << endl;

    archivo << "ARCHIVO CSV" << endl;
    archivo << "Numero A,Numero B,Resultado" << endl;
    archivo << a << "," << b << "," << res << endl;
    archivo << endl;

    archivo << "ARCHIVO XML" << endl;
    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    archivo << "<suma>" << endl;
    archivo << "    <numeroA>" << a << "</numeroA>" << endl;
    archivo << "    <numeroB>" << b << "</numeroB>" << endl;
    archivo << "    <resultado>" << res << "</resultado>" << endl;
    archivo << "</suma>" << endl;
    archivo << endl;

    archivo << "ARCHIVO JSON" << endl;
    archivo << "{" << endl;
    archivo << "    \"numeroA\": " << a << "," << endl;
    archivo << "    \"numeroB\": " << b << "," << endl;
    archivo << "    \"resultado\": " << res << endl;
    archivo << "}" << endl;

    archivo.close();
}

void Sum::resultado()
{
    int a, b, res;
    int opcion;

    cout << "Ingresa numero a: ";
    cin >> a;

    cout << "Ingresa numero b: ";
    cin >> b;

    res = suma(a, b);

    cout << "La suma es: " << res << endl;

    do
    {
        cout << "\n===== MENU DE ARCHIVOS =====" << endl;
        cout << "1. Crear archivo TXT" << endl;
        cout << "2. Crear archivo CSV" << endl;
        cout << "3. Crear archivo XML" << endl;
        cout << "4. Crear archivo JSON" << endl;
        cout << "5. Crear archivo General" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                crearTXT(a, b, res);
                system("start notepad suma.txt");
                break;

            case 2:
                crearCSV(a, b, res);
                system("start notepad suma.csv");
                break;

            case 3:
                crearXML(a, b, res);
                system("start notepad suma.xml");
                break;

            case 4:
                crearJSON(a, b, res);
                system("start notepad suma.json");
                break;

            case 5:
                crearTodoJunto(a, b, res);
                system("start notepad resultado_suma.txt");
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while(opcion != 0);
}

int main()
{
    Sum obs;

    obs.resultado();

    return 0;
}
