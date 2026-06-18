#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Opera
{
    public:
        Opera();
        ~Opera();
};

class Calcu : public Opera
{
    public:
        Calcu();
        ~Calcu();

        int suma(int a, int b);
        int suma(int a, int b, int c);

        void resultado();
};

Opera::Opera()
{
}

Opera::~Opera()
{
}

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

int Calcu::suma(int a, int b, int c)
{
    return a + b + c;
}

void Calcu::resultado()
{
    int a, b, c;
    int suma2, suma3;

    cout << "Dos numeros: ";
    cin >> a >> b;

    suma2 = suma(a, b);

    cout << "Suma de 2 numeros: " << suma2 << endl;

    cout << "Tres numeros: ";
    cin >> a >> b >> c;

    suma3 = suma(a, b, c);

    cout << "Suma de 3 numeros: " << suma3 << endl;

    // --- SE MANTIENE INTACTA TU GENERACIÓN DE ARCHIVOS ---
    ofstream txt("sobrecarga.txt");
    txt << "PROGRAMA DE SOBRECARGA" << endl;
    txt << "Suma de 2 numeros: " << suma2 << endl;
    txt << "Suma de 3 numeros: " << suma3 << endl;
    txt.close();

    ofstream csv("sobrecarga.csv");
    csv << "Operacion,Resultado" << endl;
    csv << "Suma de 2 numeros," << suma2 << endl;
    csv << "Suma de 3 numeros," << suma3 << endl;
    csv.close();

    ofstream xml("sobrecarga.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<sobrecarga>" << endl;
    xml << "    <sumaDosNumeros>" << suma2 << "</sumaDosNumeros>" << endl;
    xml << "    <sumaTresNumeros>" << suma3 << "</sumaTresNumeros>" << endl;
    xml << "</sobrecarga>" << endl;
    xml.close();

    ofstream json("sobrecarga.json");
    json << "{" << endl;
    json << "    \"sumaDosNumeros\": " << suma2 << "," << endl;
    json << "    \"sumaTresNumeros\": " << suma3 << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_sobrecarga.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE SOBRECARGA" << endl;
    general << "Suma de 2 numeros: " << suma2 << endl;
    general << "Suma de 3 numeros: " << suma3 << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Operacion,Resultado" << endl;
    general << "Suma de 2 numeros," << suma2 << endl;
    general << "Suma de 3 numeros," << suma3 << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<sobrecarga>" << endl;
    general << "    <sumaDosNumeros>" << suma2 << "</sumaDosNumeros>" << endl;
    general << "    <sumaTresNumeros>" << suma3 << "</sumaTresNumeros>" << endl;
    general << "</sobrecarga>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"sumaDosNumeros\": " << suma2 << "," << endl;
    general << "    \"sumaTresNumeros\": " << suma3 << endl;
    general << "}" << endl;
    general.close();

    // --- MENÚ DE SELECCIÓN INTEGRADO AL FINAL ---
    int opcion;
    do
    {
        cout << "\n=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Sobrecarga TXT" << endl;
        cout << "2. Abrir Sobrecarga CSV" << endl;
        cout << "3. Abrir Sobrecarga XML" << endl;
        cout << "4. Abrir Sobrecarga JSON" << endl;
        cout << "5. Abrir Reporte General (Todos)" << endl;
        cout << "6. Salir" << endl;
        cout << "=====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad sobrecarga.txt");
                break;
            case 2:
                system("start notepad sobrecarga.csv");
                break;
            case 3:
                system("start notepad sobrecarga.xml");
                break;
            case 4:
                system("start notepad sobrecarga.json");
                break;
            case 5:
                system("start notepad resultado_sobrecarga.txt");
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
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
