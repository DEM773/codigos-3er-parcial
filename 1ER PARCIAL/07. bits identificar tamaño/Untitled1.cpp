#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class autoo
{
    public:
        float precio;
        int anio;
};

class persona
{
    public:
        string nombre;
        string ap;
        string am;
        string genero;
        int edad;
};

class tam
{
    public:
        tam();
        ~tam();

        void basicos();
        void creados(persona p); 
        void archivos(persona p); 
};

tam::tam() {}
tam::~tam() {}

void tam::basicos()
{
    cout << "Tipos de datos basicos" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
}

void tam::creados(persona p)
{
    cout << "\nDatos de la Persona Guardada:" << endl;
    cout << "Nombre Completo: " << p.nombre << " " << p.ap << " " << p.am << endl;
    cout << "Genero: " << p.genero << " | Edad: " << p.edad << endl;
    cout << "\nTipos de datos creados en memoria:" << endl;
    cout << "autoo: " << sizeof(autoo) << " bytes" << endl;
    cout << "persona: " << sizeof(persona) << " bytes" << endl;
}

void tam::archivos(persona p)
{
    // --- OFSTREAM CON DATOS REALES + TAMAÑOS ---
    ofstream txt("tam.txt");
    txt << "DATOS CAPTURADOS\nNombre: " << p.nombre << " " << p.ap << " " << p.am << "\nGenero: " << p.genero << "\nEdad: " << p.edad << "\n\nTAMANIOS\nchar: " << sizeof(char) << " bytes\nint: " << sizeof(int) << " bytes\nfloat: " << sizeof(float) << " bytes\ndouble: " << sizeof(double) << " bytes\nautoo: " << sizeof(autoo) << " bytes\npersona: " << sizeof(persona) << " bytes" << endl;
    txt.close();

    ofstream csv("tam.csv");
    csv << "Tipo,Propiedad,Valor/Bytes\nPersona,Nombre," << p.nombre << "\nPersona,Apellido_P," << p.ap << "\nPersona,Apellido_M," << p.am << "\nPersona,Genero," << p.genero << "\nPersona,Edad," << p.edad << "\nBytes,char," << sizeof(char) << "\nBytes,int," << sizeof(int) << "\nBytes,autoo," << sizeof(autoo) << "\nBytes,persona," << sizeof(persona) << endl;
    csv.close();

    ofstream xml("tam.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<tamanios>\n    <persona>\n        <nombre>" << p.nombre << "</nombre>\n        <apellidoP>" << p.ap << "</apellidoP>\n        <apellidoM>" << p.am << "</apellidoM>\n        <genero>" << p.genero << "</genero>\n        <edad>" << p.edad << "</edad>\n    </persona>\n    <bytes>\n        <char>" << sizeof(char) << "</char>\n        <int>" << sizeof(int) << "</int>\n        <autoo>" << sizeof(autoo) << "</autoo>\n        <persona>" << sizeof(persona) << "</persona>\n    </bytes>\n</tamanios>" << endl;
    xml.close();

    ofstream json("tam.json");
    json << "{\n    \"persona\": {\n        \"nombre\": \"" << p.nombre << "\",\n        \"apellido_p\": \"" << p.ap << "\",\n        \"apellido_m\": \"" << p.am << "\",\n        \"genero\": \"" << p.genero << "\",\n        \"edad\": " << p.edad << "\n    },\n    \"bytes\": {\n        \"char\": " << sizeof(char) << ",\n        \"int\": " << sizeof(int) << ",\n        \"autoo\": " << sizeof(autoo) << ",\n        \"persona\": " << sizeof(persona) << "\n    }\n}" << endl;
    json.close();

    ofstream general("resultado_tam.txt");
    general << "REPORTE GENERAL DE DATOS\n=========================\nNombre: " << p.nombre << " " << p.ap << "\nEdad: " << p.edad << "\n\nTAMAÑOS EN DISCO:\nChar: " << sizeof(char) << " bytes\nInt: " << sizeof(int) << " bytes\nClase Auto: " << sizeof(autoo) << " bytes\nClase Persona: " << sizeof(persona) << " bytes" << endl;
    general.close();

    // --- MENÚ COMPACTO ---
    int opcion;
    do
    {
        cout << "\n=====================================\n   ELIGA EL ARCHIVO A ABRIR EN BLOC   \n=====================================" << endl;
        cout << "1. Abrir Tamaños TXT\n2. Abrir Tamaños CSV\n3. Abrir Tamaños XML\n4. Abrir Tamaños JSON\n5. Abrir Reporte General\n6. Salir\n=====================================\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1: system("start notepad tam.txt"); break;
            case 2: system("start notepad tam.csv"); break;
            case 3: system("start notepad tam.xml"); break;
            case 4: system("start notepad tam.json"); break;
            case 5: system("start notepad resultado_tam.txt"); break;
            case 6: cout << "Saliendo del menu..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(opcion != 6);
}

int main()
{
    tam obj;
    persona p;

    
    cout << "=== CAPTURA DE DATOS DE PERSONA ===" << endl;
    cout << "Nombre: "; cin >> p.nombre;
    cout << "Apellido Paterno: "; cin >> p.ap;
    cout << "Apellido Materno: "; cin >> p.am;
    cout << "Genero: "; cin >> p.genero;
    cout << "Edad: "; cin >> p.edad;
    cout << "===================================\n" << endl;

    obj.basicos();
    obj.creados(p);
    obj.archivos(p);

    return 0;
}
