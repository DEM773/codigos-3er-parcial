#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class fibo
{
    public:
        fibo();
        ~fibo();

        int serie(int n);
};

fibo::fibo()
{
}

fibo::~fibo()
{
}

int fibo::serie(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return serie(n - 1) + serie(n - 2);
    }
}

int main()
{
    fibo obfi;
    int n, resultado;

    cout << "Ingresa la posicion: ";
    cin >> n;

    resultado = obfi.serie(n);

    cout << "Fibonacci: " << resultado << endl;

    ofstream txt("fibo.txt");
    txt << "PROGRAMA DE FIBONACCI" << endl;
    txt << "Posicion: " << n << endl;
    txt << "Fibonacci: " << resultado << endl;
    txt.close();

    ofstream csv("fibo.csv");
    csv << "Posicion,Fibonacci" << endl;
    csv << n << "," << resultado << endl;
    csv.close();

    ofstream xml("fibo.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<fibonacci>" << endl;
    xml << "    <posicion>" << n << "</posicion>" << endl;
    xml << "    <resultado>" << resultado << "</resultado>" << endl;
    xml << "</fibonacci>" << endl;
    xml.close();

    ofstream json("fibo.json");
    json << "{" << endl;
    json << "    \"posicion\": " << n << "," << endl;
    json << "    \"fibonacci\": " << resultado << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_fibo.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE FIBONACCI" << endl;
    general << "Posicion: " << n << endl;
    general << "Fibonacci: " << resultado << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Posicion,Fibonacci" << endl;
    general << n << "," << resultado << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; // ¡Cabecera XML inyectada correctamente!
    general << "<fibonacci>" << endl;
    general << "    <posicion>" << n << "</posicion>" << endl;
    general << "    <resultado>" << resultado << "</resultado>" << endl;
    general << "</fibonacci>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"posicion\": " << n << "," << endl;
    general << "    \"fibonacci\": " << resultado << endl;
    general << "}" << endl;
    general.close();

    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Fibonacci TXT" << endl;
        cout << "2. Abrir Fibonacci CSV" << endl;
        cout << "3. Abrir Fibonacci XML" << endl;
        cout << "4. Abrir Fibonacci JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad fibo.txt");
                break;
            case 2:
                system("start notepad fibo.csv");
                break;
            case 3:
                system("start notepad fibo.xml");
                break;
            case 4:
                system("start notepad fibo.json");
                break;
            case 5:
                system("start notepad resultado_fibo.txt");
                break;
            case 6:
                cout << "Saliendo del menu..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(opcion != 6);

    return 0;
}
