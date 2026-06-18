#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class colaF
{
    public:
        colaF();
        ~colaF();

        void insertar(int x);
        void sacarDato();
        void mostrarCola();

        void insertarFloat(float x);
        void mostrarColaFloat();

        void archivos();

    protected:
        int datos[5];
        int frente;
        int fin;

        float datosF[5];
        int frenteF;
        int finF;
};

colaF::colaF()
{
    frente = 0;
    fin = -1;

    frenteF = 0;
    finF = -1;
}

colaF::~colaF()
{
}

void colaF::insertar(int x)
{
    if(fin < 4)
    {
        fin++;
        datos[fin] = x;
        cout << "Dato insertado" << endl;
    }
    else
    {
        cout << "Cola llena" << endl;
    }
}

void colaF::sacarDato()
{
    if(frente <= fin)
    {
        cout << "Dato eliminado: " << datos[frente] << endl;
        frente++;
    }
    else
    {
        cout << "Cola vacia" << endl;
    }
}

void colaF::mostrarCola()
{
    if(frente <= fin)
    {
        cout << "\nContenido de la cola (int):" << endl;

        for(int i = frente; i <= fin; i++)
        {
            cout << datos[i] << endl;
        }
    }
    else
    {
        cout << "No hay elementos en la cola (int)" << endl;
    }
}

void colaF::insertarFloat(float x)
{
    if(finF < 4)
    {
        finF++;
        datosF[finF] = x;
        cout << "Dato float insertado" << endl;
    }
    else
    {
        cout << "Cola float llena" << endl;
    }
}

void colaF::mostrarColaFloat()
{
    if(frenteF <= finF)
    {
        cout << "\nContenido de la cola (float):" << endl;

        for(int i = frenteF; i <= finF; i++)
        {
            cout << datosF[i] << endl;
        }
    }
    else
    {
        cout << "No hay elementos en la cola (float)" << endl;
    }
}

void colaF::archivos()
{
    ofstream txt("colaF.txt");
    txt << "PROGRAMA DE COLA" << endl;
    txt << endl;
    txt << "Contenido de la cola int:" << endl;
    if(frente <= fin) {
        for(int i = frente; i <= fin; i++) txt << datos[i] << endl;
    } else {
        txt << "Cola int vacia" << endl;
    }
    txt << endl;
    txt << "Contenido de la cola float:" << endl;
    if(frenteF <= finF) {
        for(int i = frenteF; i <= finF; i++) txt << datosF[i] << endl;
    } else {
        txt << "Cola float vacia" << endl;
    }
    txt.close();

    ofstream csv("colaF.csv");
    csv << "Tipo,Posicion,Dato" << endl;
    for(int i = frente; i <= fin; i++) {
        csv << "Int," << i << "," << datos[i] << endl;
    }
    for(int i = frenteF; i <= finF; i++) {
        csv << "Float," << i << "," << datosF[i] << endl;
    }
    csv.close();

    ofstream xml("colaF.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<colaF>" << endl;
    xml << "    <enteros>" << endl;
    for(int i = frente; i <= fin; i++) {
        xml << "        <dato>" << datos[i] << "</dato>" << endl;
    }
    xml << "    </enteros>" << endl;
    xml << "    <decimales>" << endl;
    for(int i = frenteF; i <= finF; i++) {
        xml << "        <dato>" << datosF[i] << "</dato>" << endl;
    }
    xml << "    </decimales>" << endl;
    xml << "</colaF>" << endl;
    xml.close();

    ofstream json("colaF.json");
    json << "{" << endl;
    json << "    \"enteros\": [" << endl;
    for(int i = frente; i <= fin; i++) {
        json << "        " << datos[i];
        if(i < fin) json << ",";
        json << endl;
    }
    json << "    ]," << endl;
    json << "    \"decimales\": [" << endl;
    for(int i = frenteF; i <= finF; i++) {
        json << "        " << datosF[i];
        if(i < finF) json << ",";
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    ofstream html("colaF.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Cola</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte de Colas</h2>" << endl;
    html << "  <h3>Enteros</h3>\n  <table><tr><th>Posicion</th><th>Dato</th></tr>" << endl;
    for(int i = frente; i <= fin; i++) {
        html << "    <tr><td>" << i << "</td><td>" << datos[i] << "</td></tr>" << endl;
    }
    html << "  </table>" << endl;
    html << "  <h3>Decimales</h3>\n  <table><tr><th>Posicion</th><th>Dato</th></tr>" << endl;
    for(int i = frenteF; i <= finF; i++) {
        html << "    <tr><td>" << i << "</td><td>" << datosF[i] << "</td></tr>" << endl;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_colaF.txt");
    general << "ARCHIVO TXT\nPROGRAMA DE COLA\n" << endl;
    general << "Contenido de la cola int:" << endl;
    if(frente <= fin) { for(int i = frente; i <= fin; i++) general << datos[i] << endl; }
    else { general << "Cola int vacia" << endl; }
    general << "\nContenido de la cola float:" << endl;
    if(frenteF <= finF) { for(int i = frenteF; i <= finF; i++) general << datosF[i] << endl; }
    else { general << "Cola float vacia" << endl; }
    
    general << "\nARCHIVO CSV\nTipo,Posicion,Dato" << endl;
    for(int i = frente; i <= fin; i++) general << "Int," << i << "," << datos[i] << endl;
    for(int i = frenteF; i <= finF; i++) general << "Float," << i << "," << datosF[i] << endl;

    general << "\nARCHIVO XML\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<colaF>\n    <enteros>" << endl;
    for(int i = frente; i <= fin; i++) general << "        <dato>" << datos[i] << "</dato>" << endl;
    general << "    </enteros>\n    <decimales>" << endl;
    for(int i = frenteF; i <= finF; i++) general << "        <dato>" << datosF[i] << "</dato>" << endl;
    general << "    </decimales>\n</colaF>" << endl;

    general << "\nARCHIVO JSON\n{\n    \"enteros\": [" << endl;
    for(int i = frente; i <= fin; i++) { general << "        " << datos[i]; if(i < fin) general << ","; general << endl; }
    general << "    ],\n    \"decimales\": [" << endl;
    for(int i = frenteF; i <= finF; i++) { general << "        " << datosF[i]; if(i < finF) general << ","; general << endl; }
    general << "    ]\n}" << endl;
    general.close();

    cout << "\n[!] Abriendo cada archivo con su programa correspondiente..." << endl;
    
    system("start notepad colaF.txt");
    system("start colaF.csv");
    system("start colaF.html");
    system("start colaF.xml");         
    system("start colaF.json");
    system("start notepad resultado_colaF.txt");
}

int main()
{
    colaF obre;
    int opcion, dato;
    float datoF;

    do
    {
        cout << "\n--- Menu de Cola ---" << endl;
        cout << "1. Insertar numero" << endl;
        cout << "2. Quitar numero" << endl;
        cout << "3. Mostrar cola" << endl;
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
                obre.sacarDato();
                break;

            case 3:
                obre.mostrarCola();
                break;

            case 4:
                cout << "Ingresa decimal: ";
                cin >> datoF;
                obre.insertarFloat(datoF);
                break;

            case 5:
                obre.mostrarColaFloat();
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
