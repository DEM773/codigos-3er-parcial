#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class persona
{
    public:
        string nombre;
        string ap;
        string am;
        string genero;
        int edad;
};

class registro
{
    public:
        registro();
        ~registro();

        void guardarPersonas();
        void mostrarPersonas();
        void archivos();

    protected:
        persona personas[3];
        persona *p;
};

registro::registro()
{
    p = personas;
}

registro::~registro()
{
}

void registro::guardarPersonas()
{
    for(int i = 0; i < 3; i++)
    {
        cout << "Persona " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> (p + i)->nombre;

        cout << "Apellido paterno: ";
        cin >> (p + i)->ap;

        cout << "Apellido materno: ";
        cin >> (p + i)->am;

        cout << "Genero: ";
        cin >> (p + i)->genero;

        cout << "Edad: ";
        cin >> (p + i)->edad;
    }
}

void registro::mostrarPersonas()
{
    cout << endl;
    cout << "Lista de personas" << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << "Persona " << i + 1 << endl;
        cout << "Nombre: " << (p + i)->nombre << endl;
        cout << "Apellido paterno: " << (p + i)->ap << endl;
        cout << "Apellido materno: " << (p + i)->am << endl;
        cout << "Genero: " << (p + i)->genero << endl;
        cout << "Edad: " << (p + i)->edad << endl;
    }
}

void registro::archivos()
{
    ofstream txt("registro.txt");

    txt << "PROGRAMA DE REGISTRO DE PERSONAS" << endl;
    txt << endl;
    txt << "Lista de personas" << endl;

    for(int i = 0; i < 3; i++)
    {
        txt << "Persona " << i + 1 << endl;
        txt << "Nombre: " << (p + i)->nombre << endl;
        txt << "Apellido paterno: " << (p + i)->ap << endl;
        txt << "Apellido materno: " << (p + i)->am << endl;
        txt << "Genero: " << (p + i)->genero << endl;
        txt << "Edad: " << (p + i)->edad << endl;
        txt << endl;
    }

    txt.close();

    ofstream csv("registro.csv");

    csv << "Persona,Nombre,ApellidoPaterno,ApellidoMaterno,Genero,Edad" << endl;

    for(int i = 0; i < 3; i++)
    {
        csv << i + 1 << ",";
        csv << (p + i)->nombre << ",";
        csv << (p + i)->ap << ",";
        csv << (p + i)->am << ",";
        csv << (p + i)->genero << ",";
        csv << (p + i)->edad << endl;
    }

    csv.close();

    ofstream xml("registro.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<registro>" << endl;

    for(int i = 0; i < 3; i++)
    {
        xml << "    <persona>" << endl;
        xml << "        <nombre>" << (p + i)->nombre << "</nombre>" << endl;
        xml << "        <apellidoPaterno>" << (p + i)->ap << "</apellidoPaterno>" << endl;
        xml << "        <apellidoMaterno>" << (p + i)->am << "</apellidoMaterno>" << endl;
        xml << "        <genero>" << (p + i)->genero << "</genero>" << endl;
        xml << "        <edad>" << (p + i)->edad << "</edad>" << endl;
        xml << "    </persona>" << endl;
    }

    xml << "</registro>" << endl;

    xml.close();

    ofstream json("registro.json");

    json << "{" << endl;
    json << "    \"personas\": [" << endl;

    for(int i = 0; i < 3; i++)
    {
        json << "        {" << endl;
        json << "            \"nombre\": \"" << (p + i)->nombre << "\"," << endl;
        json << "            \"apellidoPaterno\": \"" << (p + i)->ap << "\"," << endl;
        json << "            \"apellidoMaterno\": \"" << (p + i)->am << "\"," << endl;
        json << "            \"genero\": \"" << (p + i)->genero << "\"," << endl;
        json << "            \"edad\": " << (p + i)->edad << endl;
        json << "        }";

        if(i < 2)
        {
            json << ",";
        }

        json << endl;
    }

    json << "    ]" << endl;
    json << "}" << endl;

    json.close();

    ofstream html("registro.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Registro Personas</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Personas Registradas</h2>" << endl;
    html << "  <table>\n    <tr><th>#</th><th>Nombre</th><th>Apellido Paterno</th><th>Apellido Materno</th><th>Genero</th><th>Edad</th></tr>" << endl;
    for(int i = 0; i < 3; i++) {
        html << "    <tr><td>" << i + 1 << "</td><td>" << (p + i)->nombre << "</td><td>" << (p + i)->ap << "</td><td>" << (p + i)->am << "</td><td>" << (p + i)->genero << "</td><td>" << (p + i)->edad << "</td></tr>" << endl;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_registro.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE REGISTRO DE PERSONAS" << endl;
    general << endl;
    general << "Lista de personas" << endl;

    for(int i = 0; i < 3; i++)
    {
        general << "Persona " << i + 1 << endl;
        general << "Nombre: " << (p + i)->nombre << endl;
        general << "Apellido paterno: " << (p + i)->ap << endl;
        general << "Apellido materno: " << (p + i)->am << endl;
        general << "Genero: " << (p + i)->genero << endl;
        general << "Edad: " << (p + i)->edad << endl;
        general << endl;
    }

    general << "ARCHIVO CSV" << endl;
    general << "Persona,Nombre,ApellidoPaterno,ApellidoMaterno,Genero,Edad" << endl;

    for(int i = 0; i < 3; i++)
    {
        general << i + 1 << ",";
        general << (p + i)->nombre << ",";
        general << (p + i)->ap << ",";
        general << (p + i)->am << ",";
        general << (p + i)->genero << ",";
        general << (p + i)->edad << endl;
    }

    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<registro>" << endl;

    for(int i = 0; i < 3; i++)
    {
        general << "    <persona>" << endl;
        general << "        <nombre>" << (p + i)->nombre << "</nombre>" << endl;
        general << "        <apellidoPaterno>" << (p + i)->ap << "</apellidoPaterno>" << endl;
        general << "        <apellidoMaterno>" << (p + i)->am << "</apellidoMaterno>" << endl;
        general << "        <genero>" << (p + i)->genero << "</genero>" << endl;
        general << "        <edad>" << (p + i)->edad << "</edad>" << endl;
        general << "    </persona>" << endl;
    }

    general << "</registro>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"personas\": [" << endl;

    for(int i = 0; i < 3; i++)
    {
        general << "        {" << endl;
        general << "            \"nombre\": \"" << (p + i)->nombre << "\"," << endl;
        general << "            \"apellidoPaterno\": \"" << (p + i)->ap << "\"," << endl;
        general << "            \"apellidoMaterno\": \"" << (p + i)->am << "\"," << endl;
        general << "            \"genero\": \"" << (p + i)->genero << "\"," << endl;
        general << "            \"edad\": " << (p + i)->edad << endl;
        general << "        }";

        if(i < 2)
        {
            general << ",";
        }

        general << endl;
    }

    general << "    ]" << endl;
    general << "}" << endl;

    general.close();

    cout << "\n[!] Guardando y abriendo todos los reportes de registro..." << endl;

    system("start notepad registro.txt");
    system("start registro.csv");
    system("start registro.html");
    system("start registro.xml");
    system("start registro.json");
    system("start notepad resultado_registro.txt");
}

int main()
{
    registro obre;

    obre.guardarPersonas();
    obre.mostrarPersonas();
    obre.archivos();

    return 0;
}
