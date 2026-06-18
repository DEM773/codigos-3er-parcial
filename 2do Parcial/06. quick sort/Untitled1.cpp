#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int n = 5;

class Rap
{
    public:
        char x;
        Rap();
        ~Rap();
};

Rap::Rap()
{
}

Rap::~Rap()
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

void leerap(Rap v[], int n)
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

void verrap(Rap v[], int n)
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

int partent(int v[], int pos[], int ini, int fin)
{
    int piv = v[pos[fin]];
    int i = ini - 1;
    int aux;

    for(int j = ini; j < fin; j++)
    {
        if(v[pos[j]] <= piv)
        {
            i++;
            aux = pos[i];
            pos[i] = pos[j];
            pos[j] = aux;
        }
    }

    aux = pos[i + 1];
    pos[i + 1] = pos[fin];
    pos[fin] = aux;

    return i + 1;
}

void qsortent(int v[], int pos[], int ini, int fin)
{
    if(ini < fin)
    {
        int p = partent(v, pos, ini, fin);

        qsortent(v, pos, ini, p - 1);
        qsortent(v, pos, p + 1, fin);
    }
}

int partcar(char v[], int pos[], int ini, int fin)
{
    char piv = v[pos[fin]];
    int i = ini - 1;
    int aux;

    for(int j = ini; j < fin; j++)
    {
        if(v[pos[j]] <= piv)
        {
            i++;
            aux = pos[i];
            pos[i] = pos[j];
            pos[j] = aux;
        }
    }

    aux = pos[i + 1];
    pos[i + 1] = pos[fin];
    pos[fin] = aux;

    return i + 1;
}

void qsortcar(char v[], int pos[], int ini, int fin)
{
    if(ini < fin)
    {
        int p = partcar(v, pos, ini, fin);

        qsortcar(v, pos, ini, p - 1);
        qsortcar(v, pos, p + 1, fin);
    }
}

int partrap(Rap v[], int pos[], int ini, int fin)
{
    char piv = v[pos[fin]].x;
    int i = ini - 1;
    int aux;

    for(int j = ini; j < fin; j++)
    {
        if(v[pos[j]].x <= piv)
        {
            i++;
            aux = pos[i];
            pos[i] = pos[j];
            pos[j] = aux;
        }
    }

    aux = pos[i + 1];
    pos[i + 1] = pos[fin];
    pos[fin] = aux;

    return i + 1;
}

void qsortrap(Rap v[], int pos[], int ini, int fin)
{
    if(ini < fin)
    {
        int p = partrap(v, pos, ini, fin);

        qsortrap(v, pos, ini, p - 1);
        qsortrap(v, pos, p + 1, fin);
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

void verordrap(Rap v[], int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[pos[i]].x << " ";
    }
    cout << endl;
}

void archivos(int e[], char c[], Rap r[], int pe[], int pc[], int pr[], int n)
{
    ofstream txt("rap.txt");
    txt << "PROGRAMA DE ORDENAMIENTO QUICK" << endl;
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
    for(int i = 0; i < n; i++) { txt << r[i].x << " "; }
    txt << endl;

    txt << "Nuevo tipo ordenado: ";
    for(int i = 0; i < n; i++) { txt << r[pr[i]].x << " "; }
    txt << endl;
    txt.close();

    ofstream csv("rap.csv");
    csv << "Tipo,Posicion,Original,Ordenado" << endl;
    for(int i = 0; i < n; i++) { csv << "Entero," << i + 1 << "," << e[i] << "," << e[pe[i]] << endl; }
    for(int i = 0; i < n; i++) { csv << "Caracter," << i + 1 << "," << c[i] << "," << c[pc[i]] << endl; }
    for(int i = 0; i < n; i++) { csv << "NuevoTipo," << i + 1 << "," << r[i].x << "," << r[pr[i]].x << endl; }
    csv.close();

    ofstream xml("rap.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<rap>" << endl;
    xml << "    <enteros>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << e[i] << "\" ordenado=\"" << e[pe[i]] << "\" />" << endl; }
    xml << "    </enteros>" << endl;
    xml << "    <caracteres>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << c[i] << "\" ordenado=\"" << c[pc[i]] << "\" />" << endl; }
    xml << "    </caracteres>" << endl;
    xml << "    <nuevoTipo>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << r[i].x << "\" ordenado=\"" << r[pr[i]].x << "\" />" << endl; }
    xml << "    </nuevoTipo>" << endl;
    xml << "</rap>" << endl;
    xml.close();

    ofstream json("rap.json");
    json << "{" << endl;
    json << "    \"enterosOrdenados\": [";
    for(int i = 0; i < n; i++) { json << e[pe[i]]; if(i < n - 1) json << ", "; }
    json << "]," << endl;
    json << "    \"caracteresOrdenados\": [";
    for(int i = 0; i < n; i++) { json << "\"" << c[pc[i]] << "\""; if(i < n - 1) json << ", "; }
    json << "]," << endl;
    json << "    \"nuevoTipoOrdenado\": [";
    for(int i = 0; i < n; i++) { json << "\"" << r[pr[i]].x << "\""; if(i < n - 1) json << ", "; }
    json << "]" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_rap.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE ORDENAMIENTO QUICK" << endl;
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
    for(int i = 0; i < n; i++) { general << r[i].x << " "; }
    general << endl;
    general << "Posiciones: ";
    for(int i = 0; i < n; i++) { general << pr[i] << " "; }
    general << endl;
    general << "Nuevo tipo ordenado: ";
    for(int i = 0; i < n; i++) { general << r[pr[i]].x << " "; }
    general << endl << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Posicion,Original,Ordenado" << endl;
    for(int i = 0; i < n; i++) { general << "Entero," << i + 1 << "," << e[i] << "," << e[pe[i]] << endl; }
    for(int i = 0; i < n; i++) { general << "Caracter," << i + 1 << "," << c[i] << "," << c[pc[i]] << endl; }
    for(int i = 0; i < n; i++) { general << "NuevoTipo," << i + 1 << "," << r[i].x << "," << r[pr[i]].x << endl; }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; 
    general << "<rap>" << endl;
    general << "    <enteros>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << e[i] << "\" ordenado=\"" << e[pe[i]] << "\" />" << endl; }
    general << "    </enteros>" << endl;
    general << "    <caracteres>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << c[i] << "\" ordenado=\"" << c[pc[i]] << "\" />" << endl; }
    general << "    </caracteres>" << endl;
    general << "    <nuevoTipo>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << r[i].x << "\" ordenado=\"" << r[pr[i]].x << "\" />" << endl; }
    general << "    </nuevoTipo>" << endl;
    general << "</rap>" << endl;
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
    for(int i = 0; i < n; i++) { general << "\"" << r[pr[i]].x << "\""; if(i < n - 1) general << ", "; }
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
        cout << "1. Abrir Quicksort TXT" << endl;
        cout << "2. Abrir Quicksort CSV" << endl;
        cout << "3. Abrir Quicksort XML" << endl;
        cout << "4. Abrir Quicksort JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad rap.txt");
                break;
            case 2:
                system("start notepad rap.csv");
                break;
            case 3:
                system("start notepad rap.xml");
                break;
            case 4:
                system("start notepad rap.json");
                break;
            case 5:
                system("start notepad resultado_rap.txt");
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
    Rap r[n];
    int pr[n];

    cout << "captura de enteros\n";
    leeent(e, n);

    cout << "\ncaptura de caracteres\n";
    leecar(c, n);

    cout << "\ncaptura de nuevo tipo de dato\n";
    leerap(r, n);

    inipos(pe, n);
    inipos(pc, n);
    inipos(pr, n);

    qsortent(e, pe, 0, n - 1);
    qsortcar(c, pc, 0, n - 1);
    qsortrap(r, pr, 0, n - 1);

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
    verrap(r, n);
    cout << "pos:\n";
    verpos(pr, n);
    cout << "ordenados:\n";
    verordrap(r, pr, n);

    archivos(e, c, r, pe, pc, pr, n);

    return 0;
}
