#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class numero
{
    public:
        int valor;
};

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
        numero arreglo[5];
        numero *p;
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
        cout << "numero " << i + 1 << ": ";
        cin >> (p + i)->valor;
    }
}

void puntero::suma()
{
    int s = 0;

    for(int i = 0; i < 5; i++)
    {
        s = s + (p + i)->valor;
    }

    cout << "suma: " << s << endl;
}

void puntero::promedio()
{
    int s = 0;

    for(int i = 0; i < 5; i++)
    {
        s = s + (p + i)->valor;
    }

    cout << "promedio: " << s / 5.0 << endl;
}

void puntero::media()
{
    int aux[5];
    int temp;

    for(int i = 0; i < 5; i++)
    {
        aux[i] = (p + i)->valor;
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

    cout << "media: " << aux[2] << endl;
}

void puntero::maximo()
{
    int m = p->valor;

    for(int i = 1; i < 5; i++)
    {
        if((p + i)->valor > m)
        {
            m = (p + i)->valor;
        }
    }

    cout << "maximo: " << m << endl;
}

void puntero::minimo()
{
    int m = p->valor;

    for(int i = 1; i < 5; i++)
    {
        if((p + i)->valor < m)
        {
            m = (p + i)->valor;
        }
    }

    cout << "minimo: " << m << endl;
}

void puntero::archivos()
{
    int s = 0;
    int max = p->valor;
    int min = p->valor;
    float prom;
    int aux[5];
    int temp;
    int med;

    for(int i = 0; i < 5; i++)
    {
        s = s + (p + i)->valor;

        if((p + i)->valor > max)
        {
            max = (p + i)->valor;
        }

        if((p + i)->valor < min)
        {
            min = (p + i)->valor;
        }

        aux[i] = (p + i)->valor;
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

    txt << "PROGRAMA DE PUNTERO CON OBJETOS" << endl;
    txt << endl;
    txt << "Numero 1: " << (p + 0)->valor << endl;
    txt << "Numero 2: " << (p + 1)->valor << endl;
    txt << "Numero 3: " << (p + 2)->valor << endl;
    txt << "Numero 4: " << (p + 3)->valor << endl;
    txt << "Numero 5: " << (p + 4)->valor << endl;
    txt << "Suma: " << s << endl;
    txt << "Promedio: " << prom << endl;
    txt << "Media: " << med << endl;
    txt << "Maximo: " << max << endl;
    txt << "Minimo: " << min << endl;

    txt.close();

    ofstream csv("puntero.csv");

    csv << "Numero1,Numero2,Numero3,Numero4,Numero5,Suma,Promedio,Media,Maximo,Minimo" << endl;
    csv << (p + 0)->valor << "," << (p + 1)->valor << "," << (p + 2)->valor << ",";
    csv << (p + 3)->valor << "," << (p + 4)->valor << ",";
    csv << s << "," << prom << "," << med << "," << max << "," << min << endl;

    csv.close();

    ofstream xml("puntero.xml");

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<puntero>" << endl;
    xml << "    <numero1>" << (p + 0)->valor << "</numero1>" << endl;
    xml << "    <numero2>" << (p + 1)->valor << "</numero2>" << endl;
    xml << "    <numero3>" << (p + 2)->valor << "</numero3>" << endl;
    xml << "    <numero4>" << (p + 3)->valor << "</numero4>" << endl;
    xml << "    <numero5>" << (p + 4)->valor << "</numero5>" << endl;
    xml << "    <suma>" << s << "</suma>" << endl;
    xml << "    <promedio>" << prom << "</promedio>" << endl;
    xml << "    <media>" << med << "</media>" << endl;
    xml << "    <maximo>" << max << "</maximo>" << endl;
    xml << "    <minimo>" << min << "</minimo>" << endl;
    xml << "</puntero>" << endl;

    xml.close();

    ofstream json("puntero.json");

    json << "{" << endl;
    json << "    \"numero1\": " << (p + 0)->valor << "," << endl;
    json << "    \"numero2\": " << (p + 1)->valor << "," << endl;
    json << "    \"numero3\": " << (p + 2)->valor << "," << endl;
    json << "    \"numero4\": " << (p + 3)->valor << "," << endl;
    json << "    \"numero5\": " << (p + 4)->valor << "," << endl;
    json << "    \"suma\": " << s << "," << endl;
    json << "    \"promedio\": " << prom << "," << endl;
    json << "    \"media\": " << med << "," << endl;
    json << "    \"maximo\": " << max << "," << endl;
    json << "    \"minimo\": " << min << endl;
    json << "}" << endl;

    json.close();

    ofstream html("puntero.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte Puntero Objetos</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Reporte Estadistico de Arreglo con Punteros</h2>" << endl;
    html << "  <h3>Valores Ingresados</h3>" << endl;
    html << "  <ul>" << endl;
    for(int i = 0; i < 5; i++) {
        html << "    <li>Numero " << i + 1 << ": " << (p + i)->valor << "</li>" << endl;
    }
    html << "  </ul>" << endl;
    html << "  <h3>Calculos Estadisticos</h3>" << endl;
    html << "  <table>" << endl;
    html << "    <tr><th>Metrica</th><th>Valor</th></tr>" << endl;
    html << "    <tr><td>Suma</td><td>" << s << "</td></tr>" << endl;
    html << "    <tr><td>Promedio</td><td>" << prom << "</td></tr>" << endl;
    html << "    <tr><td>Media</td><td>" << med << "</td></tr>" << endl;
    html << "    <tr><td>Maximo</td><td>" << max << "</td></tr>" << endl;
    html << "    <tr><td>Minimo</td><td>" << min << "</td></tr>" << endl;
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_puntero.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE PUNTERO CON OBJETOS" << endl;
    general << endl;
    general << "Numero 1: " << (p + 0)->valor << endl;
    general << "Numero 2: " << (p + 1)->valor << endl;
    general << "Numero 3: " << (p + 2)->valor << endl;
    general << "Numero 4: " << (p + 3)->valor << endl;
    general << "Numero 5: " << (p + 4)->valor << endl;
    general << "Suma: " << s << endl;
    general << "Promedio: " << prom << endl;
    general << "Media: " << med << endl;
    general << "Maximo: " << max << endl;
    general << "Minimo: " << min << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Numero1,Numero2,Numero3,Numero4,Numero5,Suma,Promedio,Media,Maximo,Minimo" << endl;
    general << (p + 0)->valor << "," << (p + 1)->valor << "," << (p + 2)->valor << ",";
    general << (p + 3)->valor << "," << (p + 4)->valor << ",";
    general << s << "," << prom << "," << med << "," << max << "," << min << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    general << "<puntero>" << endl;
    general << "    <numero1>" << (p + 0)->valor << "</numero1>" << endl;
    general << "    <numero2>" << (p + 1)->valor << "</numero2>" << endl;
    general << "    <numero3>" << (p + 2)->valor << "</numero3>" << endl;
    general << "    <numero4>" << (p + 3)->valor << "</numero4>" << endl;
    general << "    <numero5>" << (p + 4)->valor << "</numero5>" << endl;
    general << "    <suma>" << s << "</suma>" << endl;
    general << "    <promedio>" << prom << "</promedio>" << endl;
    general << "    <media>" << med << "</media>" << endl;
    general << "    <maximo>" << max << "</maximo>" << endl;
    general << "    <minimo>" << min << "</minimo>" << endl;
    general << "</puntero>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"numero1\": " << (p + 0)->valor << "," << endl;
    general << "    \"numero2\": " << (p + 1)->valor << "," << endl;
    general << "    \"numero3\": " << (p + 2)->valor << "," << endl;
    general << "    \"numero4\": " << (p + 3)->valor << "," << endl;
    general << "    \"numero5\": " << (p + 4)->valor << "," << endl;
    general << "    \"suma\": " << s << "," << endl;
    general << "    \"promedio\": " << prom << "," << endl;
    general << "    \"media\": " << med << "," << endl;
    general << "    \"maximo\": " << max << "," << endl;
    general << "    \"minimo\": " << min << endl;
    general << "}" << endl;

    general.close();

    cout << "\n[!] Guardando y abriendo todos los reportes estadisticos..." << endl;

    system("start notepad puntero.txt");
    system("start puntero.csv");
    system("start puntero.html");
    system("start puntero.xml");
    system("start puntero.json");
    system("start notepad resultado_puntero.txt");
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
