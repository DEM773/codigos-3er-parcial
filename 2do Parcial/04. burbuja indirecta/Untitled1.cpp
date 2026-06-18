#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int n = 5;

class Ord
{
    public:
        char x;
        Ord();
        ~Ord();
};

Ord::Ord()
{
}

Ord::~Ord()
{
}

void leeent(int v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "entero [" << i + 1 << "]: ";
        cin >> v[i];
    }
}

void leecar(char v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "caracter [" << i + 1 << "]: ";
        cin >> v[i];
    }
}

void leeord(Ord v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "dato [" << i + 1 << "]: ";
        cin >> v[i].x;
    }
}

void verent(int v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void vercar(char v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void verord(Ord v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i].x << " ";
    }
    cout << endl;
}

void verpos(int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << pos[i] << " ";
    }
    cout << endl;
}

void inipos(int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        pos[i] = i;
    }
}

void bubent(int v[], int pos[], int n)
{
    int aux;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(v[pos[j]] > v[pos[j + 1]])
            {
                aux = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = aux;
            }
        }
    }
}

void bubcar(char v[], int pos[], int n)
{
    int aux;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(v[pos[j]] > v[pos[j + 1]])
            {
                aux = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = aux;
            }
        }
    }
}

void bubord(Ord v[], int pos[], int n)
{
    int aux;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(v[pos[j]].x > v[pos[j + 1]].x)
            {
                aux = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = aux;
            }
        }
    }
}

void verordent(int v[], int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[pos[i]] << " ";
    }
    cout << endl;
}

void verordcar(char v[], int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[pos[i]] << " ";
    }
    cout << endl;
}

void verordord(Ord v[], int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[pos[i]].x << " ";
    }
    cout << endl;
}

void archivos(int e[], char c[], Ord o[], int pe[], int pc[], int po[], int n)
{
    ofstream txt("ord.txt");
    txt << "PROGRAMA DE ORDENAMIENTO" << endl;
    txt << endl;

    txt << "Enteros originales: ";
    for(int i = 0; i < n; i++) { txt << e[i] << " "; }
    txt << endl;

    txt << "Enteros ordenados: ";
    for(int i = 0; i < n; i++) { txt << e[pe[i]] << " "; }
    txt << endl << endl;

    txt << "Caracteres originales: ";
    for(int i = 0; i < n; i++) { txt << c[i] << " "; }
    txt << endl;

    txt << "Caracteres ordenados: ";
    for(int i = 0; i < n; i++) { txt << c[pc[i]] << " "; }
    txt << endl << endl;

    txt << "Nuevo tipo original: ";
    for(int i = 0; i < n; i++) { txt << o[i].x << " "; }
    txt << endl;

    txt << "Nuevo tipo ordenado: ";
    for(int i = 0; i < n; i++) { txt << o[po[i]].x << " "; }
    txt << endl;
    txt.close();

    ofstream csv("ord.csv");
    csv << "Tipo,Posicion,Original,Ordenado" << endl;
    for(int i = 0; i < n; i++) { csv << "Entero," << i + 1 << "," << e[i] << "," << e[pe[i]] << endl; }
    for(int i = 0; i < n; i++) { csv << "Caracter," << i + 1 << "," << c[i] << "," << c[pc[i]] << endl; }
    for(int i = 0; i < n; i++) { csv << "NuevoTipo," << i + 1 << "," << o[i].x << "," << o[po[i]].x << endl; }
    csv.close();

    ofstream xml("ord.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<ordenamiento>" << endl;
    xml << "    <enteros>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << e[i] << "\" ordenado=\"" << e[pe[i]] << "\" />" << endl; }
    xml << "    </enteros>" << endl;
    xml << "    <caracteres>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << c[i] << "\" ordenado=\"" << c[pc[i]] << "\" />" << endl; }
    xml << "    </caracteres>" << endl;
    xml << "    <nuevoTipo>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << o[i].x << "\" ordenado=\"" << o[po[i]].x << "\" />" << endl; }
    xml << "    </nuevoTipo>" << endl;
    xml << "</ordenamiento>" << endl;
    xml.close();

    ofstream json("ord.json");
    json << "{" << endl;
    json << "    \"enterosOrdenados\": [";
    for(int i = 0; i < n; i++) { json << e[pe[i]]; if(i < n - 1) json << ", "; }
    json << "]," << endl;
    json << "    \"caracteresOrdenados\": [";
    for(int i = 0; i < n; i++) { json << "\"" << c[pc[i]] << "\""; if(i < n - 1) json << ", "; }
    json << "]," << endl;
    json << "    \"nuevoTipoOrdenado\": [";
    for(int i = 0; i < n; i++) { json << "\"" << o[po[i]].x << "\""; if(i < n - 1) json << ", "; }
    json << "]" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_ord.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE ORDENAMIENTO" << endl;
    general << endl;

    general << "Enteros originales: ";
    for(int i = 0; i < n; i++) { general << e[i] << " "; }
    general << endl;
    general << "Posiciones: ";
    for(int i = 0; i < n; i++) { general << pe[i] << " "; }
    general << endl;
    general << "Enteros ordenados: ";
    for(int i = 0; i < n; i++) { general << e[pe[i]] << " "; }
    general << endl << endl;

    general << "Caracteres originales: ";
    for(int i = 0; i < n; i++) { general << c[i] << " "; }
    general << endl;
    general << "Posiciones: ";
    for(int i = 0; i < n; i++) { general << pc[i] << " "; }
    general << endl;
    general << "Caracteres ordenados: ";
    for(int i = 0; i < n; i++) { general << c[pc[i]] << " "; }
    general << endl << endl;

    general << "Nuevo tipo original: ";
    for(int i = 0; i < n; i++) { general << o[i].x << " "; }
    general << endl;
    general << "Posiciones: ";
    for(int i = 0; i < n; i++) { general << po[i] << " "; }
    general << endl;
    general << "Nuevo tipo ordenado: ";
    for(int i = 0; i < n; i++) { general << o[po[i]].x << " "; }
    general << endl << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Posicion,Original,Ordenado" << endl;
    for(int i = 0; i < n; i++) { general << "Entero," << i + 1 << "," << e[i] << "," << e[pe[i]] << endl; }
    for(int i = 0; i < n; i++) { general << "Caracter," << i + 1 << "," << c[i] << "," << c[pc[i]] << endl; }
    for(int i = 0; i < n; i++) { general << "NuevoTipo," << i + 1 << "," << o[i].x << "," << o[po[i]].x << endl; }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; 
    general << "<ordenamiento>" << endl;
    general << "    <enteros>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << e[i] << "\" ordenado=\"" << e[pe[i]] << "\" />" << endl; }
    general << "    </enteros>" << endl;
    general << "    <caracteres>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << c[i] << "\" ordenado=\"" << c[pc[i]] << "\" />" << endl; }
    general << "    </caracteres>" << endl;
    general << "    <nuevoTipo>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << o[i].x << "\" ordenado=\"" << o[po[i]].x << "\" />" << endl; }
    general << "    </nuevoTipo>" << endl;
    general << "</ordenamiento>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"enterosOrdenados\": [";
    for(int i = 0; i < n; i++) { general << e[pe[i]]; if(i < n - 1) general << ", "; }
    general << "]," << endl;
    general << "    \"caracteresOrdenados\": [";
    for(int i = 0; i < n; i++) { general << "\"" << c[pc[i]] << "\""; if(i < n - 1) general << ", "; }
    general << "]," << endl;
    general << "    \"nuevoTipoOrdenado\": [";
    for(int i = 0; i < n; i++) { general << "\"" << o[po[i]].x << "\""; if(i < n - 1) general << ", "; }
    general << "]" << endl;
    general << "}" << endl;
    general.close();

    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Ordenamiento TXT" << endl;
        cout << "2. Abrir Ordenamiento CSV" << endl;
        cout << "3. Abrir Ordenamiento XML" << endl;
        cout << "4. Abrir Ordenamiento JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad ord.txt");
                break;
            case 2:
                system("start notepad ord.csv");
                break;
            case 3:
                system("start notepad ord.xml");
                break;
            case 4:
                system("start notepad ord.json");
                break;
            case 5:
                system("start notepad resultado_ord.txt");
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
    int e[n], pe[n];
    char c[n];
    int pc[n];
    Ord o[n];
    int po[n];

    cout << "captura de enteros\n";
    leeent(e, n);

    cout << "\ncaptura de caracteres\n";
    leecar(c, n);

    cout << "\ncaptura de nuevo tipo de dato\n";
    leeord(o, n);

    inipos(pe, n);
    inipos(pc, n);
    inipos(po, n);

    bubent(e, pe, n);
    bubcar(c, pc, n);
    bubord(o, po, n);

    cout << "\nenteros originales:\n";
    verent(e, n);
    cout << "pos:\n";
    verpos(pe, n);
    cout << "ordenados:\n";
    verordent(e, pe, n);

    cout << "\ncaracteres originales:\n";
    vercar(c, n);
    cout << "pos:\n";
    verpos(pc, n);
    cout << "ordenados:\n";
    verordcar(c, pc, n);

    cout << "\nnuevo tipo original:\n";
    verord(o, n);
    cout << "pos:\n";
    verpos(po, n);
    cout << "ordenados:\n";
    verordord(o, po, n);

    archivos(e, c, o, pe, pc, po, n);

    return 0;
}
