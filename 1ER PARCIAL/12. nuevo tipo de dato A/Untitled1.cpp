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

class registro
{
    public:
        registro();
        ~registro();

        void guardarAutos();
        void mostrarAutos();
        void guardarPersonas();
        void mostrarPersonas();
        void archivos();

    protected:
        autoo autos[3];
        persona personas[3];
};

registro::registro()
{
}

registro::~registro()
{
}

void registro::guardarAutos()
{
    for(int i = 0; i < 3; i++)
    {
        cout << "Auto " << i + 1 << endl;
        cout << "Precio: ";
        cin >> autos[i].precio;
        cout << "Anio: ";
        cin >> autos[i].anio;
    }
}

void registro::mostrarAutos()
{
    cout << endl;
    cout << "Lista de autos" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << "Auto " << i + 1 << endl;
        cout << "Precio: " << autos[i].precio << endl;
        cout << "Anio: " << autos[i].anio << endl;
    }
}

void registro::guardarPersonas()
{
    for(int i = 0; i < 3; i++)
    {
        cout << "Persona " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "Apellido paterno: ";
        cin >> personas[i].ap;
        cout << "Apellido materno: ";
        cin >> personas[i].am;
        cout << "Genero: ";
        cin >> personas[i].genero;
        cout << "Edad: ";
        cin >> personas[i].edad;
    }
}

void registro::mostrarPersonas()
{
    cout << endl;
    cout << "Lista de personas" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << "Persona " << i + 1 << endl;
        cout << "Nombre: " << personas[i].nombre << endl;
        cout << "Apellido paterno: " << personas[i].ap << endl;
        cout << "Apellido materno: " << personas[i].am << endl;
        cout << "Genero: " << personas[i].genero << endl;
        cout << "Edad: " << personas[i].edad << endl;
    }
}

void registro::archivos()
{
    ofstream txt("registro.txt");
    txt << "PROGRAMA DE REGISTRO" << endl;
    txt << endl;
    txt << "LISTA DE AUTOS" << endl;
    for(int i = 0; i < 3; i++)
    {
        txt << "Auto " << i + 1 << endl;
        txt << "Precio: " << autos[i].precio << endl;
        txt << "Anio: " << autos[i].anio << endl;
    }
    txt << endl;
    txt << "LISTA DE PERSONAS" << endl;
    for(int i = 0; i < 3; i++)
    {
        txt << "Persona " << i + 1 << endl;
        txt << "Nombre: " << personas[i].nombre << endl;
        txt << "Apellido paterno: " << personas[i].ap << endl;
        txt << "Apellido materno: " << personas[i].am << endl;
        txt << "Genero: " << personas[i].genero << endl;
        txt << "Edad: " << personas[i].edad << endl;
    }
    txt.close();

    ofstream csv("registro.csv");
    csv << "Tipo,Numero,Dato1,Dato2,Dato3,Dato4,Dato5" << endl;
    for(int i = 0; i < 3; i++)
    {
        csv << "Auto," << i + 1 << "," << autos[i].precio << "," << autos[i].anio << ",,, " << endl;
    }
    for(int i = 0; i < 3; i++)
    {
        csv << "Persona," << i + 1 << "," << personas[i].nombre << "," << personas[i].ap << ",";
        csv << personas[i].am << "," << personas[i].genero << "," << personas[i].edad << endl;
    }
    csv.close();

    ofstream xml("registro.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<registro>" << endl;
    xml << "    <autos>" << endl;
    for(int i = 0; i < 3; i++)
    {
        xml << "        <auto>" << endl;
        xml << "            <precio>" << autos[i].precio << "</precio>" << endl;
        xml << "            <anio>" << autos[i].anio << "</anio>" << endl;
        xml << "        </auto>" << endl;
    }
    xml << "    </autos>" << endl;
    xml << "    <personas>" << endl;
    for(int i = 0; i < 3; i++)
    {
        xml << "        <persona>" << endl;
        xml << "            <nombre>" << personas[i].nombre << "</nombre>" << endl;
        xml << "            <apellidoPaterno>" << personas[i].ap << "</apellidoPaterno>" << endl;
        xml << "            <apellidoMaterno>" << personas[i].am << "</apellidoMaterno>" << endl;
        xml << "            <genero>" << personas[i].genero << "</genero>" << endl;
        xml << "            <edad>" << personas[i].edad << "</edad>" << endl;
        xml << "        </persona>" << endl;
    }
    xml << "    </personas>" << endl;
    xml << "</registro>" << endl;
    xml.close();

    ofstream json("registro.json");
    json << "{" << endl;
    json << "    \"autos\": [" << endl;
    for(int i = 0; i < 3; i++)
    {
        json << "        {" << endl;
        json << "            \"precio\": " << autos[i].precio << "," << endl;
        json << "            \"anio\": " << autos[i].anio << endl;
        json << "        }";
        if(i < 2) json << ",";
        json << endl;
    }
    json << "    ]," << endl;
    json << "    \"personas\": [" << endl;
    for(int i = 0; i < 3; i++)
    {
        json << "        {" << endl;
        json << "            \"nombre\": \"" << personas[i].nombre << "\"," << endl;
        json << "            \"apellidoPaterno\": \"" << personas[i].ap << "\"," << endl;
        json << "            \"apellidoMaterno\": \"" << personas[i].am << "\"," << endl;
        json << "            \"genero\": \"" << personas[i].genero << "\"," << endl;
        json << "            \"edad\": " << personas[i].edad << endl;
        json << "        }";
        if(i < 2) json << ",";
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_registro.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE REGISTRO" << endl;
    general << endl;
    general << "LISTA DE AUTOS" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "Auto " << i + 1 << endl;
        general << "Precio: " << autos[i].precio << endl;
        general << "Anio: " << autos[i].anio << endl;
    }
    general << endl;
    general << "LISTA DE PERSONAS" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "Persona " << i + 1 << endl;
        general << "Nombre: " << personas[i].nombre << endl;
        general << "Apellido paterno: " << personas[i].ap << endl;
        general << "Apellido materno: " << personas[i].am << endl;
        general << "Genero: " << personas[i].genero << endl;
        general << "Edad: " << personas[i].edad << endl;
    }
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Numero,Dato1,Dato2,Dato3,Dato4,Dato5" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "Auto," << i + 1 << "," << autos[i].precio << "," << autos[i].anio << ",,," << endl;
    }
    for(int i = 0; i < 3; i++)
    {
        general << "Persona," << i + 1 << "," << personas[i].nombre << "," << personas[i].ap << ",";
        general << personas[i].am << "," << personas[i].genero << "," << personas[i].edad << endl;
    }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; // ¡Inyectada la cabecera XML que faltaba en el reporte!
    general << "<registro>" << endl;
    general << "    <autos>" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "        <auto>" << endl;
        general << "            <precio>" << autos[i].precio << "</precio>" << endl;
        general << "            <anio>" << autos[i].anio << "</anio>" << endl;
        general << "        </auto>" << endl;
    }
    general << "    </autos>" << endl;
    general << "    <personas>" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "        <persona>" << endl;
        general << "            <nombre>" << personas[i].nombre << "</nombre>" << endl;
        general << "            <apellidoPaterno>" << personas[i].ap << "</apellidoPaterno>" << endl;
        general << "            <apellidoMaterno>" << personas[i].am << "</apellidoMaterno>" << endl;
        general << "            <genero>" << personas[i].genero << "</genero>" << endl;
        general << "            <edad>" << personas[i].edad << "</edad>" << endl;
        general << "        </persona>" << endl;
    }
    general << "    </personas>" << endl;
    general << "</registro>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"autos\": [" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "        { \"precio\": " << autos[i].precio << ", \"anio\": " << autos[i].anio << " }";
        if(i < 2) general << ",";
        general << endl;
    }
    general << "    ]," << endl;
    general << "    \"personas\": [" << endl;
    for(int i = 0; i < 3; i++)
    {
        general << "        { \"nombre\": \"" << personas[i].nombre << "\", ";
        general << "\"ap\": \"" << personas[i].ap << "\", ";
        general << "\"am\": \"" << personas[i].am << "\", ";
        general << "\"genero\": \"" << personas[i].genero << "\", ";
        general << "\"edad\": " << personas[i].edad << " }";
        if(i < 2) general << ",";
        general << endl;
    }
    general << "    ]" << endl;
    general << "}" << endl;
    general.close();

    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Registro TXT" << endl;
        cout << "2. Abrir Registro CSV" << endl;
        cout << "3. Abrir Registro XML" << endl;
        cout << "4. Abrir Registro JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad registro.txt");
                break;
            case 2:
                system("start notepad registro.csv");
                break;
            case 3:
                system("start notepad registro.xml");
                break;
            case 4:
                system("start notepad registro.json");
                break;
            case 5:
                system("start notepad resultado_registro.txt");
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
    registro obre;

    obre.guardarAutos();
    obre.guardarPersonas();
    obre.mostrarAutos();
    obre.mostrarPersonas();
    obre.archivos();

    return 0;
}
