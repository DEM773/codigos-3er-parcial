#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class operaciones
{
    public:
        operaciones() {}
        ~operaciones() {}
};

template <class T>
T suma(T a, T b)
{
    return a + b;
}

int main()
{
    operaciones obj;
    int a, b;
    float x, y;

    cout << "Enteros: ";
    cin >> a >> b;
    cout << "Suma enteros: " << suma(a, b) << endl;

    cout << "Decimales: ";
    cin >> x >> y;
    cout << "Suma decimales: " << suma(x, y) << endl;

    
    ofstream txt("operaciones.txt");
    txt << "PROGRAMA DE OPERACIONES\nEntero 1: " << a << "\nEntero 2: " << b << "\nSuma enteros: " << suma(a, b) << "\nDecimal 1: " << x << "\nDecimal 2: " << y << "\nSuma decimales: " << suma(x, y) << endl;
    txt.close();

    ofstream csv("operaciones.csv");
    csv << "Tipo,Numero1,Numero2,Resultado\nEnteros," << a << "," << b << "," << suma(a, b) << "\nDecimales," << x << "," << y << "," << suma(x, y) << endl;
    csv.close();

    ofstream xml("operaciones.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<operaciones>\n    <enteros>\n        <numero1>" << a << "</numero1>\n        <numero2>" << b << "</numero2>\n        <resultado>" << suma(a, b) << "</resultado>\n    </enteros>\n    <decimales>\n        <numero1>" << x << "</numero1>\n        <numero2>" << y << "</numero2>\n        <resultado>" << suma(x, y) << "</resultado>\n    </decimales>\n</operaciones>" << endl;
    xml.close();

    ofstream json("operaciones.json");
    json << "{\n    \"enteros\": {\n        \"numero1\": " << a << ",\n        \"numero2\": " << b << ",\n        \"resultado\": " << suma(a, b) << "\n    },\n    \"decimales\": {\n        \"numero1\": " << x << ",\n        \"numero2\": " << y << ",\n        \"resultado\": " << suma(x, y) << "\n    }\n}" << endl;
    json.close();

    ofstream general("resultado_operaciones.txt");
    general << "ARCHIVO TXT\nPROGRAMA DE OPERACIONES\nEntero 1: " << a << "\nEntero 2: " << b << "\nSuma enteros: " << suma(a, b) << "\nDecimal 1: " << x << "\nDecimal 2: " << y << "\nSuma decimales: " << suma(x, y) << "\n\nARCHIVO CSV\nTipo,Numero1,Numero2,Resultado\nEnteros," << a << "," << b << "," << suma(a, b) << "\nDecimales," << x << "," << y << "," << suma(x, y) << "\n\nARCHIVO XML\n<operaciones>\n    <enteros>\n        <numero1>" << a << "</numero1>\n        <numero2>" << b << "</numero2>\n        <resultado>" << suma(a, b) << "</resultado>\n    </enteros>\n</operaciones>\n\nARCHIVO JSON\n{\n    \"enteros\": {\n        \"numero1\": " << a << ",\n        \"numero2\": " << b << ",\n        \"resultado\": " << suma(a, b) << "\n    }\n}" << endl;
    general.close();

   
    int opcion;
    do
    {
        cout << "\n=====================================\n   ELIGA EL ARCHIVO A ABRIR EN BLOC   \n=====================================" << endl;
        cout << "1. Abrir Operaciones TXT\n2. Abrir Operaciones CSV\n3. Abrir Operaciones XML\n4. Abrir Operaciones JSON\n5. Abrir Reporte General\n6. Salir\n=====================================\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1: system("start notepad operaciones.txt"); break;
            case 2: system("start notepad operaciones.csv"); break;
            case 3: system("start notepad operaciones.xml"); break;
            case 4: system("start notepad operaciones.json"); break;
            case 5: system("start notepad resultado_operaciones.txt"); break;
            case 6: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(opcion != 6);

    return 0;
}
