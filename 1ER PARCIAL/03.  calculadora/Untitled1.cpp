#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Calcu
{
    public:
        Calcu();
        ~Calcu();

        int suma(int a, int b);
        int resta(int a, int b);
        int multi(int a, int b);
        float divi(float a, float b);

        void resultado();
};

Calcu::Calcu()
{
}

Calcu::~Calcu()
{
}

int Calcu::suma(int a, int b)
{
    return a + b;
}

int Calcu::resta(int a, int b)
{
    return a - b;
}

int Calcu::multi(int a, int b)
{
    return a * b;
}

float Calcu::divi(float a, float b)
{
    return a / b;
}

void Calcu::resultado()
{
    int a, b;

    cout << "Numero 1: ";
    cin >> a;

    cout << "Numero 2: ";
    cin >> b;

    cout << "Suma: " << suma(a, b) << endl;
    cout << "Resta: " << resta(a, b) << endl;
    cout << "Multiplicacion: " << multi(a, b) << endl;
    cout << "Division: " << divi(a, b) << endl;

    // --- SE MANTIENE INTACTA TU GENERACIÓN DE ARCHIVOS ---
    ofstream txt("calculadora.txt");
    txt << "PROGRAMA DE CALCULADORA" << endl;
    txt << "Numero 1: " << a << endl;
    txt << "Numero 2: " << b << endl;
    txt << "Suma: " << suma(a, b) << endl;
    txt << "Resta: " << resta(a, b) << endl;
    txt << "Multiplicacion: " << multi(a, b) << endl;
    txt << "Division: " << divi(a, b) << endl;
    txt.close();

    ofstream csv("calculadora.csv");
    csv << "Numero 1,Numero 2,Suma,Resta,Multiplicacion,Division" << endl;
    csv << a << "," << b << "," << suma(a, b) << "," << resta(a, b) << "," << multi(a, b) << "," << divi(a, b) << endl;
    csv.close();

    ofstream xml("calculadora.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<calculadora>" << endl;
    xml << "    <numero1>" << a << "</numero1>" << endl;
    xml << "    <numero2>" << b << "</numero2>" << endl;
    xml << "    <suma>" << suma(a, b) << "</suma>" << endl;
    xml << "    <resta>" << resta(a, b) << "</resta>" << endl;
    xml << "    <multiplicacion>" << multi(a, b) << "</multiplicacion>" << endl;
    xml << "    <division>" << divi(a, b) << "</division>" << endl;
    xml << "</calculadora>" << endl;
    xml.close();

    ofstream json("calculadora.json");
    json << "{" << endl;
    json << "    \"numero1\": " << a << "," << endl;
    json << "    \"numero2\": " << b << "," << endl;
    json << "    \"suma\": " << suma(a, b) << "," << endl;
    json << "    \"resta\": " << resta(a, b) << "," << endl;
    json << "    \"multiplicacion\": " << multi(a, b) << "," << endl;
    json << "    \"division\": " << divi(a, b) << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_calculadora.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE CALCULADORA" << endl;
    general << "Numero 1: " << a << endl;
    general << "Numero 2: " << b << endl;
    general << "Suma: " << suma(a, b) << endl;
    general << "Resta: " << resta(a, b) << endl;
    general << "Multiplicacion: " << multi(a, b) << endl;
    general << "Division: " << divi(a, b) << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Numero 1,Numero 2,Suma,Resta,Multiplicacion,Division" << endl;
    general << a << "," << b << "," << suma(a, b) << "," << resta(a, b) << "," << multi(a, b) << "," << divi(a, b) << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<calculadora>" << endl;
    general << "    <numero1>" << a << "</numero1>" << endl;
    general << "    <numero2>" << b << "</numero2>" << endl;
    general << "    <suma>" << suma(a, b) << "</suma>" << endl;
    general << "    <resta>" << resta(a, b) << "</resta>" << endl;
    general << "    <multiplicacion>" << multi(a, b) << "</multiplicacion>" << endl;
    general << "    <division>" << divi(a, b) << "</division>" << endl;
    general << "</calculadora>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"numero1\": " << a << "," << endl;
    general << "    \"numero2\": " << b << "," << endl;
    general << "    \"suma\": " << suma(a, b) << "," << endl;
    general << "    \"resta\": " << resta(a, b) << "," << endl;
    general << "    \"multiplicacion\": " << multi(a, b) << "," << endl;
    general << "    \"division\": " << divi(a, b) << endl;
    general << "}" << endl;
    general.close();

    // --- AQUÍ COMIENZA EL MENÚ DE SELECCIÓN ---
    int opcion;
    do
    {
        cout << "\n=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Calculadora TXT" << endl;
        cout << "2. Abrir Calculadora CSV" << endl;
        cout << "3. Abrir Calculadora XML" << endl;
        cout << "4. Abrir Calculadora JSON" << endl;
        cout << "5. Abrir Reporte General (Todos)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad calculadora.txt");
                break;
            case 2:
                system("start notepad calculadora.csv");
                break;
            case 3:
                system("start notepad calculadora.xml");
                break;
            case 4:
                system("start notepad calculadora.json");
                break;
            case 5:
                system("start notepad resultado_calculadora.txt");
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
    Calcu obj;
    obj.resultado();
    return 0;
}
