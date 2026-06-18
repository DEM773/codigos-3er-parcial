#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class factorial
{
    public:
        factorial();
        ~factorial();

        int fact(int n);
};

factorial::factorial()
{
}

factorial::~factorial()
{
}

int factorial::fact(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    factorial obfa;
    int n, resultado;

    cout << "Numero: ";
    cin >> n;

    resultado = obfa.fact(n);

    cout << "Factorial: " << resultado << endl;

    ofstream txt("factorial.txt");
    txt << "PROGRAMA DE FACTORIAL" << endl;
    txt << "Numero: " << n << endl;
    txt << "Factorial: " << resultado << endl;
    txt.close();

    ofstream csv("factorial.csv");
    csv << "Numero,Factorial" << endl;
    csv << n << "," << resultado << endl;
    csv.close();

    ofstream xml("factorial.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<factorial>" << endl;
    xml << "    <numero>" << n << "</numero>" << endl;
    xml << "    <resultado>" << resultado << "</resultado>" << endl;
    xml << "</factorial>" << endl;
    xml.close();

    ofstream json("factorial.json");
    json << "{" << endl;
    json << "    \"numero\": " << n << "," << endl;
    json << "    \"factorial\": " << resultado << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_factorial.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE FACTORIAL" << endl;
    general << "Numero: " << n << endl;
    general << "Factorial: " << resultado << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Numero,Factorial" << endl;
    general << n << "," << resultado << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; // ¡Cabecera XML agregada con éxito!
    general << "<factorial>" << endl;
    general << "    <numero>" << n << "</numero>" << endl;
    general << "    <resultado>" << resultado << "</resultado>" << endl;
    general << "</factorial>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"numero\": " << n << "," << endl;
    general << "    \"factorial\": " << resultado << endl;
    general << "}" << endl;
    general.close();

    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Factorial TXT" << endl;
        cout << "2. Abrir Factorial CSV" << endl;
        cout << "3. Abrir Factorial XML" << endl;
        cout << "4. Abrir Factorial JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad factorial.txt");
                break;
            case 2:
                system("start notepad factorial.csv");
                break;
            case 3:
                system("start notepad factorial.xml");
                break;
            case 4:
                system("start notepad factorial.json");
                break;
            case 5:
                system("start notepad resultado_factorial.txt");
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
