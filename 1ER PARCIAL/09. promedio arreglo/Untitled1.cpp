#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class promeA
{
    public:
        promeA();
        ~promeA();

        void leer();
        void suma();
        void promedio();
        void media();
        void maximo();
        void minimo();
        void archivos();

    protected:
        int n[5];
};

promeA::promeA()
{
}

promeA::~promeA()
{
}

void promeA::leer()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Numero " << i + 1 << ": ";
        cin >> n[i];
    }
}

void promeA::suma()
{
    int s = 0;
    for(int i = 0; i < 5; i++)
    {
        s = s + n[i];
    }
    cout << "Suma: " << s << endl;
}

void promeA::promedio()
{
    int s = 0;
    for(int i = 0; i < 5; i++)
    {
        s = s + n[i];
    }
    cout << "Promedio: " << s / 5.0 << endl;
}

void promeA::media()
{
    int aux[5];
    int temp;

    for(int i = 0; i < 5; i++)
    {
        aux[i] = n[i];
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

void promeA::maximo()
{
    int m = n[0];
    for(int i = 1; i < 5; i++)
    {
        if(n[i] > m)
        {
            m = n[i];
        }
    }
    cout << "Maximo: " << m << endl;
}

void promeA::minimo()
{
    int m = n[0];
    for(int i = 1; i < 5; i++)
    {
        if(n[i] < m)
        {
            m = n[i];
        }
    }
    cout << "Minimo: " << m << endl;
}

void promeA::archivos()
{
    int s = 0;
    int max = n[0];
    int min = n[0];
    float prom;
    int aux[5];
    int temp;
    int med;

    for(int i = 0; i < 5; i++)
    {
        s = s + n[i];

        if(n[i] > max)
        {
            max = n[i];
        }

        if(n[i] < min)
        {
            min = n[i];
        }

        aux[i] = n[i];
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

    ofstream txt("promeA.txt");
    txt << "PROGRAMA DE PROMEDIO Y MEDIA" << endl;
    txt << "Numero 1: " << n[0] << endl;
    txt << "Numero 2: " << n[1] << endl;
    txt << "Numero 3: " << n[2] << endl;
    txt << "Numero 4: " << n[3] << endl;
    txt << "Numero 5: " << n[4] << endl;
    txt << "Suma: " << s << endl;
    txt << "Promedio: " << prom << endl;
    txt << "Media: " << med << endl;
    txt << "Maximo: " << max << endl;
    txt << "Minimo: " << min << endl;
    txt.close();

    ofstream csv("promeA.csv");
    csv << "Numero1,Numero2,Numero3,Numero4,Numero5,Suma,Promedio,Media,Maximo,Minimo" << endl;
    csv << n[0] << "," << n[1] << "," << n[2] << "," << n[3] << "," << n[4] << ",";
    csv << s << "," << prom << "," << med << "," << max << "," << min << endl;
    csv.close();

    ofstream xml("promeA.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<promedio>" << endl;
    xml << "    <numero1>" << n[0] << "</numero1>" << endl;
    xml << "    <numero2>" << n[1] << "</numero2>" << endl;
    xml << "    <numero3>" << n[2] << "</numero3>" << endl;
    xml << "    <numero4>" << n[3] << "</numero4>" << endl;
    xml << "    <numero5>" << n[4] << "</numero5>" << endl;
    xml << "    <suma>" << s << "</suma>" << endl;
    xml << "    <promedio>" << prom << "</promedio>" << endl;
    xml << "    <media>" << med << "</media>" << endl;
    xml << "    <maximo>" << max << "</maximo>" << endl;
    xml << "    <minimo>" << min << "</minimo>" << endl;
    xml << "</promedio>" << endl;
    xml.close();

    ofstream json("promeA.json");
    json << "{" << endl;
    json << "    \"numero1\": " << n[0] << "," << endl;
    json << "    \"numero2\": " << n[1] << "," << endl;
    json << "    \"numero3\": " << n[2] << "," << endl;
    json << "    \"numero4\": " << n[3] << "," << endl;
    json << "    \"numero5\": " << n[4] << "," << endl;
    json << "    \"suma\": " << s << "," << endl;
    json << "    \"promedio\": " << prom << "," << endl;
    json << "    \"media\": " << med << "," << endl;
    json << "    \"maximo\": " << max << "," << endl;
    json << "    \"minimo\": " << min << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_promeA.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE PROMEDIO Y MEDIA" << endl;
    general << "Numero 1: " << n[0] << endl;
    general << "Numero 2: " << n[1] << endl;
    general << "Numero 3: " << n[2] << endl;
    general << "Numero 4: " << n[3] << endl;
    general << "Numero 5: " << n[4] << endl;
    general << "Suma: " << s << endl;
    general << "Promedio: " << prom << endl;
    general << "Media: " << med << endl;
    general << "Maximo: " << max << endl;
    general << "Minimo: " << min << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Numero1,Numero2,Numero3,Numero4,Numero5,Suma,Promedio,Media,Maximo,Minimo" << endl;
    general << n[0] << "," << n[1] << "," << n[2] << "," << n[3] << "," << n[4] << ",";
    general << s << "," << prom << "," << med << "," << max << "," << min << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; // ¡Corregido aquí también!
    general << "<promedio>" << endl;
    general << "    <numero1>" << n[0] << "</numero1>" << endl;
    general << "    <numero2>" << n[1] << "</numero2>" << endl;
    general << "    <numero3>" << n[2] << "</numero3>" << endl;
    general << "    <numero4>" << n[3] << "</numero4>" << endl;
    general << "    <numero5>" << n[4] << "</numero5>" << endl;
    general << "    <suma>" << s << "</suma>" << endl;
    general << "    <promedio>" << prom << "</promedio>" << endl;
    general << "    <media>" << med << "</media>" << endl;
    general << "    <maximo>" << max << "</maximo>" << endl;
    general << "    <minimo>" << min << "</minimo>" << endl;
    general << "</promedio>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"numero1\": " << n[0] << "," << endl;
    general << "    \"numero2\": " << n[1] << "," << endl;
    general << "    \"numero3\": " << n[2] << "," << endl;
    general << "    \"numero4\": " << n[3] << "," << endl;
    general << "    \"numero5\": " << n[4] << "," << endl;
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
        cout << "1. Abrir Reporte TXT" << endl;
        cout << "2. Abrir Reporte CSV" << endl;
        cout << "3. Abrir Reporte XML" << endl;
        cout << "4. Abrir Reporte JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "=====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad promeA.txt");
                break;
            case 2:
                system("start notepad promeA.csv");
                break;
            case 3:
                system("start notepad promeA.xml");
                break;
            case 4:
                system("start notepad promeA.json");
                break;
            case 5:
                system("start notepad resultado_promeA.txt");
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
    promeA obj;

    obj.leer();
    obj.suma();
    obj.promedio();
    obj.media();
    obj.maximo();
    obj.minimo();
    obj.archivos();

    return 0;
}
