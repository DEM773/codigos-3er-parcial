#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class T>
class calcuTemp
{
    public:
        calcuTemp();
        ~calcuTemp();

        T suma(T a, T b);
};

template <class T>
calcuTemp<T>::calcuTemp() {}

template <class T>
calcuTemp<T>::~calcuTemp() {}

template <class T>
T calcuTemp<T>::suma(T a, T b)
{
    return a + b;
}


void generarTXT(int a, int b, int sInt, float x, float y, float sFloat)
{
    ofstream txt("calcuTemp.txt");
    txt << "PROGRAMA TEMPLATE" << endl;
    txt << "Enteros: " << a << " y " << b << endl;
    txt << "Suma enteros: " << sInt << endl;
    txt << "Decimales: " << x << " y " << y << endl;
    txt << "Suma decimales: " << sFloat << endl;
    txt.close();
}

void generarCSV(int a, int b, int sInt, float x, float y, float sFloat)
{
    ofstream csv("calcuTemp.csv");
    csv << "Tipo,Numero1,Numero2,Resultado" << endl;
    csv << "Enteros," << a << "," << b << "," << sInt << endl;
    csv << "Decimales," << x << "," << y << "," << sFloat << endl;
    csv.close();
}

void generarXML(int a, int b, int sInt, float x, float y, float sFloat)
{
    ofstream xml("calcuTemp.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<calculo>" << endl;
    xml << "    <enteros>" << endl;
    xml << "        <numero1>" << a << "</numero1>" << endl;
    xml << "        <numero2>" << b << "</numero2>" << endl;
    xml << "        <resultado>" << sInt << "</resultado>" << endl;
    xml << "    </enteros>" << endl;
    xml << "    <decimales>" << endl;
    xml << "        <numero1>" << x << "</numero1>" << endl;
    xml << "        <numero2>" << y << "</numero2>" << endl;
    xml << "        <resultado>" << sFloat << "</resultado>" << endl;
    xml << "    </decimales>" << endl;
    xml << "</calculo>" << endl;
    xml.close();
}

void generarJSON(int a, int b, int sInt, float x, float y, float sFloat)
{
    ofstream json("calcuTemp.json");
    json << "{" << endl;
    json << "    \"enteros\": {" << endl;
    json << "        \"numero1\": " << a << "," << endl;
    json << "        \"numero2\": " << b << "," << endl;
    json << "        \"resultado\": " << sInt << endl;
    json << "    }," << endl;
    json << "    \"decimales\": {" << endl;
    json << "        \"numero1\": " << x << "," << endl;
    json << "        \"numero2\": " << y << "," << endl;
    json << "        \"resultado\": " << sFloat << endl;
    json << "    }" << endl;
    json << "}" << endl;
    json.close();
}

void generarGeneral(int a, int b, int sInt, float x, float y, float sFloat)
{
    ofstream general("resultado_calcuTemp.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA TEMPLATE" << endl;
    general << "Enteros: " << a << " y " << b << endl;
    general << "Suma enteros: " << sInt << endl;
    general << "Decimales: " << x << " y " << y << endl;
    general << "Suma decimales: " << sFloat << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Numero1,Numero2,Resultado" << endl;
    general << "Enteros," << a << "," << b << "," << sInt << endl;
    general << "Decimales," << x << "," << y << "," << sFloat << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<calculo>" << endl;
    general << "    <enteros>" << endl;
    general << "        <numero1>" << a << "</numero1>" << endl;
    general << "        <numero2>" << b << "</numero2>" << endl;
    general << "        <resultado>" << sInt << "</resultado>" << endl;
    general << "    </enteros>" << endl;
    general << "    <decimales>" << endl;
    general << "        <numero1>" << x << "</numero1>" << endl;
    general << "        <numero2>" << y << "</numero2>" << endl;
    general << "        <resultado>" << sFloat << "</resultado>" << endl;
    general << "    </decimales>" << endl;
    general << "</calculo>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"enteros\": {" << endl;
    general << "        \"numero1\": " << a << "," << endl;
    general << "        \"numero2\": " << b << "," << endl;
    general << "        \"resultado\": " << sInt << endl;
    general << "    }," << endl;
    general << "    \"decimales\": {" << endl;
    general << "        \"numero1\": " << x << "," << endl;
    general << "        \"numero2\": " << y << "," << endl;
    general << "        \"resultado\": " << sFloat << endl;
    general << "    }" << endl;
    general << "}" << endl;
    general.close();
}


int main()
{
    calcuTemp<int> obj1;
    calcuTemp<float> obj2;

    int a, b;
    float x, y;

    cout << "Enteros: ";
    cin >> a >> b;
    int sumaInt = obj1.suma(a, b);
    cout << "Suma: " << sumaInt << endl;

    cout << "Decimales: ";
    cin >> x >> y;
    float sumaFloat = obj2.suma(x, y);
    cout << "Suma: " << sumaFloat << endl;

    generarTXT(a, b, sumaInt, x, y, sumaFloat);
    generarCSV(a, b, sumaInt, x, y, sumaFloat);
    generarXML(a, b, sumaInt, x, y, sumaFloat);
    generarJSON(a, b, sumaInt, x, y, sumaFloat);
    generarGeneral(a, b, sumaInt, x, y, sumaFloat);

    // --- MENÚ DE SELECCIÓN INTERACTIVO ---
    int opcion;
    do
    {
        cout << "\n=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Template TXT" << endl;
        cout << "2. Abrir Template CSV" << endl;
        cout << "3. Abrir Template XML" << endl;
        cout << "4. Abrir Template JSON" << endl;
        cout << "5. Abrir Reporte General (Todos)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad calcuTemp.txt");
                break;
            case 2:
                system("start notepad calcuTemp.csv");
                break;
            case 3:
                system("start notepad calcuTemp.xml");
                break;
            case 4:
                system("start notepad calcuTemp.json");
                break;
            case 5:
                system("start notepad resultado_calcuTemp.txt");
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(opcion != 6);

    return 0;
}
