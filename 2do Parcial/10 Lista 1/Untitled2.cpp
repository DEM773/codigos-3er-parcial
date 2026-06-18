#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class listaF
{
    public:
        listaF();
        ~listaF();

        void insertar(int x);
        void mostrarDatos();
        void eliminarDato();

        void insertarFloat(float x);
        void mostrarDatosFloat();

        void archivos();

    protected:
        int datos[5];
        int ult;

        float datosF[5];
        int ultF;
};

listaF::listaF()
{
    ult = -1;
    ultF = -1;
}

listaF::~listaF()
{
}

void listaF::insertar(int x)
{
    if(ult < 4)
    {
        ult++;
        datos[ult] = x;
        cout << "Dato insertado" << endl;
    }
    else
    {
        cout << "Lista llena" << endl;
    }
}

void listaF::mostrarDatos()
{
    if(ult >= 0)
    {
        cout << "\nLista de datos:" << endl;

        for(int i = 0; i <= ult; i++)
        {
            cout << "Dato " << i + 1 << ": " << datos[i] << endl;
        }
    }
    else
    {
        cout << "No hay elementos en la lista" << endl;
    }
}

void listaF::eliminarDato()
{
    if(ult >= 0)
    {
        int pos;

        cout << "Posicion a eliminar: ";
        cin >> pos;

        pos--;

        if(pos >= 0 && pos <= ult)
        {
            for(int i = pos; i < ult; i++)
            {
                datos[i] = datos[i + 1];
            }

            ult--;
            cout << "Dato eliminado" << endl;
        }
        else
        {
            cout << "Posicion no valida" << endl;
        }
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}

void listaF::insertarFloat(float x)
{
    if(ultF < 4)
    {
        ultF++;
        datosF[ultF] = x;
        cout << "Dato decimal insertado" << endl;
    }
    else
    {
        cout << "Lista de decimales llena" << endl;
    }
}

void listaF::mostrarDatosFloat()
{
    if(ultF >= 0)
    {
        cout << "\nLista de decimales:" << endl;

        for(int i = 0; i <= ultF; i++)
        {
            cout << "Dato " << i + 1 << ": " << datosF[i] << endl;
        }
    }
    else
    {
        cout << "No hay decimales en la lista" << endl;
    }
}

void listaF::archivos()
{
    // ---------------------------------------------------
    // 1. GENERANDO ARCHIVO TXT
    // ---------------------------------------------------
    ofstream txt("listaF.txt");
    txt << "PROGRAMA DE LISTA" << endl;
    txt << endl;
    txt << "Lista de enteros:" << endl;
    if(ult >= 0)
    {
        for(int i = 0; i <= ult; i++)
        {
            txt << "Dato " << i + 1 << ": " << datos[i] << endl;
        }
    }
    else
    {
        txt << "Lista de enteros vacia" << endl;
    }
    txt << endl;
    txt << "Lista de decimales:" << endl;
    if(ultF >= 0)
    {
        for(int i = 0; i <= ultF; i++)
        {
            txt << "Dato " << i + 1 << ": " << datosF[i] << endl;
        }
    }
    else
    {
        txt << "Lista de decimales vacia" << endl;
    }
    txt.close();

    // ---------------------------------------------------
    // 2. GENERANDO ARCHIVO CSV (Se abrirá en Excel)
    // ---------------------------------------------------
    ofstream csv("listaF.csv");
    csv << "Tipo,Posicion,Dato" << endl;
    for(int i = 0; i <= ult; i++)
    {
        csv << "Entero," << i + 1 << "," << datos[i] << endl;
    }
    for(int i = 0; i <= ultF; i++)
    {
        csv << "Decimal," << i + 1 << "," << datosF[i] << endl;
    }
    csv.close();

    // ---------------------------------------------------
    // 3. GENERANDO ARCHIVO XML (Estructura limpia)
    // ---------------------------------------------------
    ofstream xml("listaF.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<listaF>" << endl;
    xml << "    <enteros>" << endl;
    for(int i = 0; i <= ult; i++)
    {
        xml << "        <dato>" << datos[i] << "</dato>" << endl;
    }
    xml << "    </enteros>" << endl;
    xml << "    <decimales>" << endl;
    for(int i = 0; i <= ultF; i++)
    {
        xml << "        <dato>" << datosF[i] << "</dato>" << endl;
    }
    xml << "    </decimales>" << endl;
    xml << "</listaF>" << endl;
    xml.close();

    // ---------------------------------------------------
    // 4. GENERANDO ARCHIVO JSON
    // ---------------------------------------------------
    ofstream json("listaF.json");
    json << "{" << endl;
    json << "    \"enteros\": [" << endl;
    for(int i = 0; i <= ult; i++)
    {
        json << "        " << datos[i];
        if(i < ult) json << ",";
        json << endl;
    }
    json << "    ]," << endl;
    json << "    \"decimales\": [" << endl;
    for(int i = 0; i <= ultF; i++)
    {
        json << "        " << datosF[i];
        if(i < ultF) json << ",";
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    // ---------------------------------------------------
    // 5. GENERANDO ARCHIVO HTML (Se abrirá en tu navegador)
    // ---------------------------------------------------
    ofstream html("listaF.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Lista</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Listas</h2>" << endl;
    html << "  <h3>Enteros</h3>\n  <table><tr><th>Posicion</th><th>Dato</th></tr>" << endl;
    for(int i = 0; i <= ult; i++) {
        html << "    <tr><td>" << i + 1 << "</td><td>" << datos[i] << "</td></tr>" << endl;
    }
    html << "  </table>" << endl;
    html << "  <h3>Decimales</h3>\n  <table><tr><th>Posicion</th><th>Dato</th></tr>" << endl;
    for(int i = 0; i <= ultF; i++) {
        html << "    <tr><td>" << i + 1 << "</td><td>" << datosF[i] << "</td></tr>" << endl;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    // ---------------------------------------------------
    // 6. GENERANDO REPORTE INTEGRADO MAESTRO (resultado_listaF.txt)
    // ---------------------------------------------------
    ofstream general("resultado_listaF.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE LISTA" << endl;
    general << endl;
    general << "Lista de enteros:" << endl;
    if(ult >= 0) {
        for(int i = 0; i <= ult; i++) general << "Dato " << i + 1 << ": " << datos[i] << endl;
    } else {
        general << "Lista de enteros vacia" << endl;
    }
    general << endl;
    general << "Lista de decimales:" << endl;
    if(ultF >= 0) {
        for(int i = 0; i <= ultF; i++) general << "Dato " << i + 1 << ": " << datosF[i] << endl;
    } else {
        general << "Lista de decimales vacia" << endl;
    }
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Posicion,Dato" << endl;
    for(int i = 0; i <= ult; i++) {
        general << "Entero," << i + 1 << "," << datos[i] << endl;
    }
    for(int i = 0; i <= ultF; i++) {
        general << "Decimal," << i + 1 << "," << datosF[i] << endl;
    }
    general << endl;

    // Bloque XML corregido con su cabecera estándar de manera limpia
    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<listaF>" << endl;
    general << "    <enteros>" << endl;
    for(int i = 0; i <= ult; i++) {
        general << "        <dato>" << datos[i] << "</dato>" << endl;
    }
    general << "    </enteros>" << endl;
    general << "    <decimales>" << endl;
    for(int i = 0; i <= ultF; i++) {
        general << "        <dato>" << datosF[i] << "</dato>" << endl;
    }
    general << "    </decimales>" << endl;
    general << "</listaF>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"enteros\": [" << endl;
    for(int i = 0; i <= ult; i++) {
        general << "        " << datos[i];
        if(i < ult) general << ",";
        general << endl;
    }
    general << "    ]," << endl;
    general << "    \"decimales\": [" << endl;
    for(int i = 0; i <= ultF; i++) {
        general << "        " << datosF[i];
        if(i < ultF) general << ",";
        general << endl;
    }
    general << "    ]" << endl;
    general << "}" << endl;

    general.close();

    // ---------------------------------------------------
    // COMANDOS DEL SISTEMA PARA ABRIR CADA ARCHIVO RESPECTIVAMENTE
    // ---------------------------------------------------
    cout << "\n[!] Guardando y abriendo todos los reportes..." << endl;
    
    system("start notepad listaF.txt");       // Abre el TXT con el bloc de notas
    system("start listaF.csv");               // Abre el CSV (Generalmente en Excel)
    system("start listaF.html");              // Abre el HTML en tu navegador web predeterminado
    system("start listaF.xml");               // Abre el XML con su visor asignado
    system("start listaF.json");              // Abre el JSON
    system("start notepad resultado_listaF.txt"); // Abre el reporte unificado
}

int main()
{
    listaF obre;
    int opcion, dato;
    float datoF;

    do
    {
        cout << "\n--- Menu de Lista ---" << endl;
        cout << "1. Insertar numero" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Eliminar dato" << endl;
        cout << "4. Insertar decimal" << endl;
        cout << "5. Mostrar decimales" << endl;
        cout << "6. Salir y Abrir Archivos" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Ingresa numero: ";
                cin >> dato;
                obre.insertar(dato);
                break;

            case 2:
                obre.mostrarDatos();
                break;

            case 3:
                obre.eliminarDato();
                break;

            case 4:
                cout << "Ingresa decimal: ";
                cin >> datoF;
                obre.insertarFloat(datoF);
                break;

            case 5:
                obre.mostrarDatosFloat();
                break;

            case 6:
                obre.archivos();
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    } while(opcion != 6);

    return 0;
}
