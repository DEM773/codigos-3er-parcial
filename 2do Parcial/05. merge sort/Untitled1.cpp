#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int n = 5;

class Mez
{
    public:
        char x;
        Mez();
        ~Mez();
};

Mez::Mez()
{
}

Mez::~Mez()
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

void leemez(Mez v[], int n)
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

void vermez(Mez v[], int n)
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

void mergeent(int v[], int pos[], int ini, int m, int fin)
{
    int i = ini;
    int j = m + 1;
    int k = 0;
    int aux[n];

    while(i <= m && j <= fin)
    {
        if(v[pos[i]] <= v[pos[j]])
        {
            aux[k] = pos[i];
            i++;
        }
        else
        {
            aux[k] = pos[j];
            j++;
        }
        k++;
    }

    while(i <= m)
    {
        aux[k] = pos[i];
        i++;
        k++;
    }

    while(j <= fin)
    {
        aux[k] = pos[j];
        j++;
        k++;
    }

    for(int t = 0; t < k; t++)
    {
        pos[ini + t] = aux[t];
    }
}

void msortent(int v[], int pos[], int ini, int fin)
{
    if(ini < fin)
    {
        int m = (ini + fin) / 2;
        msortent(v, pos, ini, m);
        msortent(v, pos, m + 1, fin);
        mergeent(v, pos, ini, m, fin);
    }
}

void mergecar(char v[], int pos[], int ini, int m, int fin)
{
    int i = ini;
    int j = m + 1;
    int k = 0;
    int aux[n];

    while(i <= m && j <= fin)
    {
        if(v[pos[i]] <= v[pos[j]])
        {
            aux[k] = pos[i];
            i++;
        }
        else
        {
            aux[k] = pos[j];
            j++;
        }
        k++;
    }

    while(i <= m)
    {
        aux[k] = pos[i];
        i++;
        k++;
    }

    while(j <= fin)
    {
        aux[k] = pos[j];
        j++;
        k++;
    }

    for(int t = 0; t < k; t++)
    {
        pos[ini + t] = aux[t];
    }
}

void msortcar(char v[], int pos[], int ini, int fin)
{
    if(ini < fin)
    {
        int m = (ini + fin) / 2;
        msortcar(v, pos, ini, m);
        msortcar(v, pos, m + 1, fin);
        mergecar(v, pos, ini, m, fin);
    }
}

void mergemez(Mez v[], int pos[], int ini, int m, int fin)
{
    int i = ini;
    int j = m + 1;
    int k = 0;
    int aux[n];

    while(i <= m && j <= fin)
    {
        if(v[pos[i]].x <= v[pos[j]].x)
        {
            aux[k] = pos[i];
            i++;
        }
        else
        {
            aux[k] = pos[j];
            j++;
        }
        k++;
    }

    while(i <= m)
    {
        aux[k] = pos[i];
        i++;
        k++;
    }

     while(j <= fin)
    {
        aux[k] = pos[j];
        j++;
        k++;
    }

    for(int t = 0; t < k; t++)
    {
        pos[ini + t] = aux[t];
    }
}

void msortmez(Mez v[], int pos[], int ini, int fin)
{
    if(ini < fin)
    {
        int m = (ini + fin) / 2;
        msortmez(v, pos, ini, m);
        msortmez(v, pos, m + 1, fin);
        mergemez(v, pos, ini, m, fin);
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

void verordmez(Mez v[], int pos[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << v[pos[i]].x << " ";
    }
    cout << endl;
}

void archivos(int e[], char c[], Mez m[], int pe[], int pc[], int pm[], int n)
{
    ofstream txt("mez.txt");
    txt << "PROGRAMA DE ORDENAMIENTO MERGE" << endl;
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
    for(int i = 0; i < n; i++) { txt << m[i].x << " "; }
    txt << endl;

    txt << "Nuevo tipo ordenado: ";
    for(int i = 0; i < n; i++) { txt << m[pm[i]].x << " "; }
    txt << endl;
    txt.close();

    ofstream csv("mez.csv");
    csv << "Tipo,Posicion,Original,Ordenado" << endl;
    for(int i = 0; i < n; i++) { csv << "Entero," << i + 1 << "," << e[i] << "," << e[pe[i]] << endl; }
    for(int i = 0; i < n; i++) { csv << "Caracter," << i + 1 << "," << c[i] << "," << c[pc[i]] << endl; }
    for(int i = 0; i < n; i++) { csv << "NuevoTipo," << i + 1 << "," << m[i].x << "," << m[pm[i]].x << endl; }
    csv.close();

    ofstream xml("mez.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<mez>" << endl;
    xml << "    <enteros>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << e[i] << "\" ordenado=\"" << e[pe[i]] << "\" />" << endl; }
    xml << "    </enteros>" << endl;
    xml << "    <caracteres>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << c[i] << "\" ordenado=\"" << c[pc[i]] << "\" />" << endl; }
    xml << "    </caracteres>" << endl;
    xml << "    <nuevoTipo>" << endl;
    for(int i = 0; i < n; i++) { xml << "        <dato original=\"" << m[i].x << "\" ordenado=\"" << m[pm[i]].x << "\" />" << endl; }
    xml << "    </nuevoTipo>" << endl;
    xml << "</mez>" << endl;
    xml.close();

    ofstream json("mez.json");
    json << "{" << endl;
    json << "    \"enterosOrdenados\": [";
    for(int i = 0; i < n; i++) { json << e[pe[i]]; if(i < n - 1) json << ", "; }
    json << "]," << endl;
    json << "    \"caracteresOrdenados\": [";
    for(int i = 0; i < n; i++) { json << "\"" << c[pc[i]] << "\""; if(i < n - 1) json << ", "; }
    json << "]," << endl;
    json << "    \"nuevoTipoOrdenado\": [";
    for(int i = 0; i < n; i++) { json << "\"" << m[pm[i]].x << "\""; if(i < n - 1) json << ", "; }
    json << "]" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_mez.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE ORDENAMIENTO MERGE" << endl;
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
    for(int i = 0; i < n; i++) { general << m[i].x << " "; }
    general << endl;
    general << "Posiciones: ";
    for(int i = 0; i < n; i++) { general << pm[i] << " "; }
    general << endl;
    general << "Nuevo tipo ordenado: ";
    for(int i = 0; i < n; i++) { general << m[pm[i]].x << " "; }
    general << endl << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Tipo,Posicion,Original,Ordenado" << endl;
    for(int i = 0; i < n; i++) { general << "Entero," << i + 1 << "," << e[i] << "," << e[pe[i]] << endl; }
    for(int i = 0; i < n; i++) { general << "Caracter," << i + 1 << "," << c[i] << "," << c[pc[i]] << endl; }
    for(int i = 0; i < n; i++) { general << "NuevoTipo," << i + 1 << "," << m[i].x << "," << m[pm[i]].x << endl; }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; 
    general << "<mez>" << endl;
    general << "    <enteros>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << e[i] << "\" ordenado=\"" << e[pe[i]] << "\" />" << endl; }
    general << "    </enteros>" << endl;
    general << "    <caracteres>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << c[i] << "\" ordenado=\"" << c[pc[i]] << "\" />" << endl; }
    general << "    </caracteres>" << endl;
    general << "    <nuevoTipo>" << endl;
    for(int i = 0; i < n; i++) { general << "        <dato original=\"" << m[i].x << "\" ordenado=\"" << m[pm[i]].x << "\" />" << endl; }
    general << "    </nuevoTipo>" << endl;
    general << "</mez>" << endl;
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
    for(int i = 0; i < n; i++) { general << "\"" << m[pm[i]].x << "\""; if(i < n - 1) general << ", "; }
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
        cout << "1. Abrir Mezcla TXT" << endl;
        cout << "2. Abrir Mezcla CSV" << endl;
        cout << "3. Abrir Mezcla XML" << endl;
        cout << "4. Abrir Mezcla JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad mez.txt");
                break;
            case 2:
                system("start notepad mez.csv");
                break;
            case 3:
                system("start notepad mez.xml");
                break;
            case 4:
                system("start notepad mez.json");
                break;
            case 5:
                system("start notepad resultado_mez.txt");
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
    Mez m[n];
    int pm[n];

    cout << "captura de enteros\n";
    leeent(e, n);

    cout << "\ncaptura de caracteres\n";
    leecar(c, n);

    cout << "\ncaptura de nuevo tipo de dato\n";
    leemez(m, n);

    inipos(pe, n);
    inipos(pc, n);
    inipos(pm, n);

    msortent(e, pe, 0, n - 1);
    msortcar(c, pc, 0, n - 1);
    msortmez(m, pm, 0, n - 1);

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
    vermez(m, n);
    cout << "pos:\n";
    verpos(pm, n);
    cout << "ordenados:\n";
    verordmez(m, pm, n);

    archivos(e, c, m, pe, pc, pm, n);

    return 0;
}
