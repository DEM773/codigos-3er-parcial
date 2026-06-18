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

tam::tam()
{
}

tam::~tam()
{
}

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
    cout << endl;
    cout << "Datos de la Persona Guardada:" << endl;
    cout << "Nombre Completo: " << p.nombre << " " << p.ap << " " << p.am << endl;
    cout << "Genero: " << p.genero << " | Edad: " << p.edad << endl;

    cout << endl;
    cout << "Tipos de datos creados" << endl;
    cout << "autoo: " << sizeof(autoo) << " bytes" << endl;
    cout << "persona: " << sizeof(persona) << " bytes" << endl;
}

void tam::archivos(persona p)
{
    ofstream txt("tam.txt");
    txt << "DATOS CAPTURADOS" << endl;
    txt << "Nombre: " << p.nombre << " " << p.ap << " " << p.am << endl;
    txt << "Genero: " << p.genero << endl;
    txt << "Edad: " << p.edad << endl;
    txt << endl;
    txt << "TIPOS DE DATOS BASICOS" << endl;
    txt << "char: " << sizeof(char) << " bytes" << endl;
    txt << "int: " << sizeof(int) << " bytes" << endl;
    txt << "float: " << sizeof(float) << " bytes" << endl;
    txt << "double: " << sizeof(double) << " bytes" << endl;
    txt << endl;
    txt << "TIPOS DE DATOS CREADOS" << endl;
    txt << "autoo: " << sizeof(autoo) << " bytes" << endl;
    txt << "persona: " << sizeof(persona) << " bytes" << endl;
    txt.close();

    ofstream csv("tam.csv");
    csv << "Tipo,Propiedad,Valor o Bytes" << endl;
    csv << "Persona,Nombre," << p.nombre << endl;
    csv << "Persona,ApellidoP," << p.ap << endl;
    csv << "Persona,ApellidoM," << p.am << endl;
    csv << "Persona,Genero," << p.genero << endl;
    csv << "Persona,Edad," << p.edad << endl;
    csv << "Basico,char," << sizeof(char) << endl;
    csv << "Basico,int," << sizeof(int) << endl;
    csv << "Basico,float," << sizeof(float) << endl;
    csv << "Basico,double," << sizeof(double) << endl;
    csv << "Creado,autoo," << sizeof(autoo) << endl;
    csv << "Creado,persona," << sizeof(persona) << endl;
    csv.close();

    ofstream xml("tam.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<tamanios>" << endl;
    xml << "    <persona>" << endl;
    xml << "        <nombre>" << p.nombre << "</nombre>" << endl;
    xml << "        <apellidoP>" << p.ap << "</apellidoP>" << endl;
    xml << "        <apellidoM>" << p.am << "</apellidoM>" << endl;
    xml << "        <genero>" << p.genero << "</genero>" << endl;
    xml << "        <edad>" << p.edad << "</edad>" << endl;
    xml << "    </persona>" << endl;
    xml << "    <basicos>" << endl;
    xml << "        <char>" << sizeof(char) << "</char>" << endl;
    xml << "        <int>" << sizeof(int) << "</int>" << endl;
    xml << "        <float>" << sizeof(float) << "</float>" << endl;
    xml << "        <double>" << sizeof(double) << "</double>" << endl;
    xml << "    </basicos>" << endl;
    xml << "    <creados>" << endl;
    xml << "        <autoo>" << sizeof(autoo) << "</autoo>" << endl;
    xml << "        <persona>" << sizeof(persona) << "</persona>" << endl;
    xml << "    </creados>" << endl;
    xml << "</tamanios>" << endl;
    xml.close();

    ofstream json("tam.json");
    json << "{" << endl;
    json << "    \"persona\": {" << endl;
    json << "        \"nombre\": \"" << p.nombre << "\"," << endl;
    json << "        \"apellidoP\": \"" << p.ap << "\"," << endl;
    json << "        \"apellidoM\": \"" << p.am << "\"," << endl;
    json << "        \"genero\": \"" << p.genero << "\"," << endl;
    json << "        \"edad\": " << p.edad << endl;
    json << "    }," << endl;
    json << "    \"basicos\": {" << endl;
    json << "        \"char\": " << sizeof(char) << "," << endl;
    json << "        \"int\": " << sizeof(int) << "," << endl;
    json << "        \"float\": " << sizeof(float) << "," << endl;
    json << "        \"double\": " << sizeof(double) << endl;
    json << "    }," << endl;
    json << "    \"creados\": {" << endl;
    json << "        <autoo>: " << sizeof(autoo) << "," << endl;
    json << "        \"persona\": " << sizeof(persona) << endl;
    json << "    }" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_tam.txt");
    general << "ARCHIVO TXT" << endl;
    general << "DATOS CAPTURADOS" << endl;
    general << "Nombre: " << p.nombre << " " << p.ap << " " << p.am << endl;
    general << "Genero: " << p.genero << endl;
    general << "Edad: " << p.edad << endl;
    general << "TIPOS DE DATOS BASICOS" << endl;
    general << "char: " << sizeof(char) << " bytes" << endl;
    general << "int: " << sizeof(int) << " bytes" << endl;
    general << "float: " << sizeof(float) << " bytes" << endl;
    general << "double: " << sizeof(double) << " bytes" << endl;
    general << "TIPOS DE DATOS CREADOS" << endl;
    general << "autoo: " << sizeof(autoo) << " bytes" << endl;
    general << "persona: " << sizeof(persona) << " bytes" << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Propiedad,Valor o Bytes" << endl;
    general << "Persona,Nombre," << p.nombre << endl;
    general << "Persona,Edad," << p.edad << endl;
    general << "Basico,char," << sizeof(char) << endl;
    general << "Creado,persona," << sizeof(persona) << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<tamanios>" << endl;
    general << "    <persona>" << endl;
    general << "        <nombre>" << p.nombre << "</nombre>" << endl;
    general << "    </persona>" << endl;
    general << "</tamanios>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"persona\": {" << endl;
    general << "        \"nombre\": \"" << p.nombre << "\"" << endl;
    general << "    }" << endl;
    general << "}" << endl;
    general.close();

    // --- MENÚ CON TU FORMATO ORIGINAL RENGLÓN POR RENGLÓN ---
    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Tamaños TXT" << endl;
        cout << "2. Abrir Tamaños CSV" << endl;
        cout << "3. Abrir Tamaños XML" << endl;
        cout << "4. Abrir Tamaños JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad tam.txt");
                break;
            case 2:
                system("start notepad tam.csv");
                break;
            case 3:
                system("start notepad tam.xml");
                break;
            case 4:
                system("start notepad tam.json");
                break;
            case 5:
                system("start notepad resultado_tam.txt");
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
    tam obj;
    persona p;

    cout << "=== CAPTURA DE DATOS DE PERSONA ===" << endl;
    cout << "Nombre: ";
    cin >> p.nombre;
    cout << "Apellido Paterno: ";
    cin >> p.ap;
    cout << "Apellido Materno: ";
    cin >> p.am;
    cout << "Genero: ";
    cin >> p.genero;
    cout << "Edad: ";
    cin >> p.edad;
    cout << "===================================" << endl;

    obj.basicos();
    obj.creados(p);
    obj.archivos(p);

    return 0;
}
