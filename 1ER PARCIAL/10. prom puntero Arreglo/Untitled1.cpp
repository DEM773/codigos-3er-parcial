#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class puntero
{
    public:
        puntero();
        ~puntero();

        void leer();
        void suma();
        void promedio();
        void media();
        void maximo();
        void minimo();
        void archivos();

    protected:
        int arreglo[5];
        int *p;
};

puntero::puntero()
{
    p = arreglo;
}

puntero::~puntero()
{
}

void puntero::leer()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Numero " << i + 1 << ": ";
        cin >> *(p + i);
    }
}

void puntero::suma()
{
    int s = 0;
    for(int i = 0; i < 5; i++)
    {
        s = s + *(p + i);
    }
    cout << "Suma: " << s << endl;
}

void puntero::promedio()
{
    int s = 0;
    for(int i = 0; i < 5; i++)
    {
        s = s + *(p + i);
    }
    cout << "Promedio: " << s / 5.0 << endl;
}

void puntero::media()
{
    int aux[5];
    int temp;

    for(int i = 0; i < 5; i++)
    {
        aux[i] = *(p + i);
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(aux[i] > aux[j])
            {
                temp = aux[i];
                aux[i] = aux[j];
                aux[j] = temp;
            }
        }
    }

    cout << "Media: " << aux[2] << endl;
}

void puntero::maximo()
{
    int m = *p;
    for(int i = 1; i < 5; i++)
    {
        if(*(p + i) > m)
        {
            m = *(p + i);
        }
    }
    cout << "Maximo: " << m << endl;
}

void puntero::minimo()
{
    int m = *p;
    for(int i = 1; i < 5; i++)
    {
        if(*(p + i) < m)
        {
            m = *(p + i);
        }
    }
    cout << "Minimo: " << m << endl;
}

void puntero::archivos()
{
    int s = 0;
    int max = *p;
    int min = *p;
    float prom;
    int aux[5];
    int temp;
    int med;

    for(int i = 0; i < 5; i++)
    {
        s = s + *(p + i);

        if(*(p + i) > max)
        {
            max = *(p + i);
        }

        if(*(p + i) < min)
        {
            min = *(p + i);
        }

        aux[i] = *(p + i);
    }

    prom = s / 5.0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(aux[i] > aux[j])
            {
                temp = aux[i];
                aux[i] = aux[j];
                aux[j] = temp;
            }
        }
    }

    med = aux[2];

    ofstream txt("puntero.txt");
    txt << "PROGRAMA CON PUNTERO" << endl;
    txt << "Numero 1: " << *(p + 0) << endl;
    txt << "Numero 2: " << *(p + 1) << endl;
    txt << "Numero 3: " << *(p + 2) << endl;
    txt << "Numero 4: " << *(p + 3) << endl;
    txt << "Numero 5: " << *(p + 4) << endl;
    txt << "Suma: " << s << endl;
    txt << "Promedio: " << prom << endl;
    txt << "Media: " << med << endl;
    txt << "Maximo: " << max << endl;
    txt << "Minimo: " << min << endl;
    txt.close();

    ofstream csv("puntero.csv");
    csv << "Numero1,Numero2,Numero3,Numero4,Numero5,Suma,Promedio,Media,Maximo,Minimo" << endl;
    csv << *(p + 0) << "," << *(p + 1) << "," << *(p + 2) << "," << *(p + 3) << "," << *(p + 4) << ",";
    csv << s << "," << prom << "," << med << "," << max << "," << min << endl;
    csv.close();

    ofstream xml("puntero.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<puntero>" << endl;
    xml << "    <numero1>" << *(p + 0) << "</numero1>" << endl;
    xml << "    <numero2>" << *(p + 1) << "</numero2>" << endl;
    xml << "    <numero3>" << *(p + 2) << "</numero3>" << endl;
    xml << "    <numero4>" << *(p + 3) << "</numero4>" << endl;
    xml << "    <numero5>" << *(p + 4) << "</numero5>" << endl;
    xml << "    <suma>" << s << "</suma>" << endl;
    xml << "    <promedio>" << prom << "</promedio>" << endl;
    xml << "    <media>" << med << "</media>" << endl;
    xml << "    <maximo>" << max << "</maximo>" << endl;
    xml << "    <minimo>" << min << "</minimo>" << endl;
    xml << "</puntero>" << endl;
    xml.close();

    ofstream json("puntero.json");
    json << "{" << endl;
    json << "    \"numero1\": " << *(p + 0) << "," << endl;
    json << "    \"numero2\": " << *(p + 1) << "," << endl;
    json << "    \"numero3\": " << *(p + 2) << "," << endl;
    json << "    \"numero4\": " << *(p + 3) << "," << endl;
    json << "    \"numero5\": " << *(p + 4) << "," << endl;
    json << "    \"suma\": " << s << "," << endl;
    json << "    \"promedio\": " << prom << "," << endl;
    json << "    \"media\": " << med << "," << endl;
    json << "    \"maximo\": " << max << "," << endl;
    json << "    \"minimo\": " << min << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_puntero.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA CON PUNTERO" << endl;
    general << "Numero 1: " << *(p + 0) << endl;
    general << "Numero 2: " << *(p + 1) << endl;
    general << "Numero 3: " << *(p + 2) << endl;
    general << "Numero 4: " << *(p + 3) << endl;
    general << "Numero 5: " << *(p + 4) << endl;
    general << "Suma: " << s << endl;
    general << "Promedio: " << prom << endl;
    general << "Media: " << med << endl;
    general << "Maximo: " << max << endl;
    general << "Minimo: " << min << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Numero1,Numero2,Numero3,Numero4,Numero5,Suma,Promedio,Media,Maximo,Minimo" << endl;
    general << *(p + 0) << "," << *(p + 1) << "," << *(p + 2) << "," << *(p + 3) << "," << *(p + 4) << ",";
    general << s << "," << prom << "," << med << "," << max << "," << min << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<puntero>" << endl;
    general << "    <numero1>" << *(p + 0) << "</numero1>" << endl;
    general << "    <numero2>" << *(p + 1) << "</numero2>" << endl;
    general << "    <numero3>" << *(p + 2) << "</numero3>" << endl;
    general << "    <numero4>" << *(p + 3) << "</numero4>" << endl;
    general << "    <numero5>" << *(p + 4) << "</numero5>" << endl;
    general << "    <suma>" << s << "</suma>" << endl;
    general << "    <promedio>" << prom << "</promedio>" << endl;
    general << "    <media>" << med << "</media>" << endl;
    general << "    <maximo>" << max << "</maximo>" << endl;
    general << "    <minimo>" << min << "</minimo>" << endl;
    general << "</puntero>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"numero1\": " << *(p + 0) << "," << endl;
    general << "    \"numero2\": " << *(p + 1) << "," << endl;
    general << "    \"numero3\": " << *(p + 2) << "," << endl;
    general << "    \"numero4\": " << *(p + 3) << "," << endl;
    general << "    \"numero5\": " << *(p + 4) << "," << endl;
    general << "    \"suma\": " << s << "," << endl;
    general << "    \"promedio\": " << prom << "," << endl;
    general << "    \"media\": " << med << "," << endl;
    general << "    \"maximo\": " << max << "," << endl;
    general << "    \"minimo\": " << min << endl;
    general << "}" << endl;
    general.close();

    
    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Puntero TXT" << endl;
        cout << "2. Abrir Puntero CSV" << endl;
        cout << "3. Abrir Puntero XML" << endl;
        cout << "4. Abrir Puntero JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad puntero.txt");
                break;
            case 2:
                system("start notepad puntero.csv");
                break;
            case 3:
                system("start notepad puntero.xml");
                break;
            case 4:
                system("start notepad puntero.json");
                break;
            case 5:
                system("start notepad resultado_puntero.txt");
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
    puntero obpu;

    obpu.leer();
    obpu.suma();
    obpu.promedio();
    obpu.media();
    obpu.maximo();
    obpu.minimo();
    obpu.archivos();

    return 0;
}
