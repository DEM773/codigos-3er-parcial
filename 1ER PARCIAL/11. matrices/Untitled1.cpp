#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class matriz
{
    public:
        matriz();
        ~matriz();

        void leerA();
        void leerB();
        void mostrarA();
        void mostrarB();
        void porConstante();
        void porMatriz();
        void archivos();

    protected:
        int A[2][2];
        int B[2][2];
        int C[2][2];
        int M[2][2];
        int constante;
};

matriz::matriz()
{
}

matriz::~matriz()
{
}

void matriz::leerA()
{
    cout << "Matriz A" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
}

void matriz::leerB()
{
    cout << "Matriz B" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }
}

void matriz::mostrarA()
{
    cout << "Matriz A" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void matriz::mostrarB()
{
    cout << "Matriz B" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

void matriz::porConstante()
{
    cout << "Constante: ";
    cin >> constante;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] * constante;
        }
    }

    cout << "Resultado A * constante" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void matriz::porMatriz()
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            M[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                M[i][j] = M[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }

    cout << "Resultado A * B" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void matriz::archivos()
{
    ofstream txt("matriz.txt");
    txt << "PROGRAMA DE MATRICES" << endl;
    txt << endl;
    txt << "Matriz A" << endl;
    txt << A[0][0] << " " << A[0][1] << endl;
    txt << A[1][0] << " " << A[1][1] << endl;
    txt << endl;
    txt << "Matriz B" << endl;
    txt << B[0][0] << " " << B[0][1] << endl;
    txt << B[1][0] << " " << B[1][1] << endl;
    txt << endl;
    txt << "Constante: " << constante << endl;
    txt << "Resultado A * constante" << endl;
    txt << C[0][0] << " " << C[0][1] << endl;
    txt << C[1][0] << " " << C[1][1] << endl;
    txt << endl;
    txt << "Resultado A * B" << endl;
    txt << M[0][0] << " " << M[0][1] << endl;
    txt << M[1][0] << " " << M[1][1] << endl;
    txt.close();

    ofstream csv("matriz.csv");
    csv << "Dato,Posicion,Valor" << endl;
    csv << "A,A00," << A[0][0] << endl;
    csv << "A,A01," << A[0][1] << endl;
    csv << "A,A10," << A[1][0] << endl;
    csv << "A,A11," << A[1][1] << endl;
    csv << "B,B00," << B[0][0] << endl;
    csv << "B,B01," << B[0][1] << endl;
    csv << "B,B10," << B[1][0] << endl;
    csv << "B,B11," << B[1][1] << endl;
    csv << "Constante,C," << constante << endl;
    csv << "A por constante,C00," << C[0][0] << endl;
    csv << "A por constante,C01," << C[0][1] << endl;
    csv << "A por constante,C10," << C[1][0] << endl;
    csv << "A por constante,C11," << C[1][1] << endl;
    csv << "A por B,M00," << M[0][0] << endl;
    csv << "A por B,M01," << M[0][1] << endl;
    csv << "A por B,M10," << M[1][0] << endl;
    csv << "A por B,M11," << M[1][1] << endl;
    csv.close();

    ofstream xml("matriz.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<matriz>" << endl;
    xml << "    <A>" << endl;
    xml << "        <a00>" << A[0][0] << "</a00>" << endl;
    xml << "        <a01>" << A[0][1] << "</a01>" << endl;
    xml << "        <a10>" << A[1][0] << "</a10>" << endl;
    xml << "        <a11>" << A[1][1] << "</a11>" << endl;
    xml << "    </A>" << endl;
    xml << "    <B>" << endl;
    xml << "        <b00>" << B[0][0] << "</b00>" << endl;
    xml << "        <b01>" << B[0][1] << "</b01>" << endl;
    xml << "        <b10>" << B[1][0] << "</b10>" << endl;
    xml << "        <b11>" << B[1][1] << "</b11>" << endl;
    xml << "    </B>" << endl;
    xml << "    <constante>" << constante << "</constante>" << endl;
    xml << "    <resultadoConstante>" << endl;
    xml << "        <c00>" << C[0][0] << "</c00>" << endl;
    xml << "        <c01>" << C[0][1] << "</c01>" << endl;
    xml << "        <c10>" << C[1][0] << "</c10>" << endl;
    xml << "        <c11>" << C[1][1] << "</c11>" << endl;
    xml << "    </resultadoConstante>" << endl;
    xml << "    <resultadoMatriz>" << endl;
    xml << "        <m00>" << M[0][0] << "</m00>" << endl;
    xml << "        <m01>" << M[0][1] << "</m01>" << endl;
    xml << "        <m10>" << M[1][0] << "</m10>" << endl;
    xml << "        <m11>" << M[1][1] << "</m11>" << endl;
    xml << "    </resultadoMatriz>" << endl;
    xml << "</matriz>" << endl;
    xml.close();

    ofstream json("matriz.json");
    json << "{" << endl;
    json << "    \"A\": [[" << A[0][0] << "," << A[0][1] << "],[" << A[1][0] << "," << A[1][1] << "]]," << endl;
    json << "    \"B\": [[" << B[0][0] << "," << B[0][1] << "],[" << B[1][0] << "," << B[1][1] << "]]," << endl;
    json << "    \"constante\": " << constante << "," << endl;
    json << "    \"resultadoConstante\": [[" << C[0][0] << "," << C[0][1] << "],[" << C[1][0] << "," << C[1][1] << "]]," << endl;
    json << "    \"resultadoMatriz\": [[" << M[0][0] << "," << M[0][1] << "],[" << M[1][0] << "," << M[1][1] << "]]" << endl;
    json << "}" << endl;
    json.close();

    ofstream general("resultado_matriz.txt");
    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA DE MATRICES" << endl;
    general << endl;
    general << "Matriz A" << endl;
    general << A[0][0] << " " << A[0][1] << endl;
    general << A[1][0] << " " << A[1][1] << endl;
    general << endl;
    general << "Matriz B" << endl;
    general << B[0][0] << " " << B[0][1] << endl;
    general << B[1][0] << " " << B[1][1] << endl;
    general << endl;
    general << "Constante: " << constante << endl;
    general << "Resultado A * constante" << endl;
    general << C[0][0] << " " << C[0][1] << endl;
    general << C[1][0] << " " << C[1][1] << endl;
    general << endl;
    general << "Resultado A * B" << endl;
    general << M[0][0] << " " << M[0][1] << endl;
    general << M[1][0] << " " << M[1][1] << endl;
    general << endl;

    general << "ARCHIVO CSV" << endl;
    general << "Dato,Posicion,Valor" << endl;
    general << "A,A00," << A[0][0] << endl;
    general << "A,A01," << A[0][1] << endl;
    general << "A,A10," << A[1][0] << endl;
    general << "A,A11," << A[1][1] << endl;
    general << "B,B00," << B[0][0] << endl;
    general << "B,B01," << B[0][1] << endl;
    general << "B,B10," << B[1][0] << endl;
    general << "B,B11," << B[1][1] << endl;
    general << "Constante,C," << constante << endl;
    general << "A por constante,C00," << C[0][0] << endl;
    general << "A por constante,C01," << C[0][1] << endl;
    general << "A por constante,C10," << C[1][0] << endl;
    general << "A por constante,C11," << C[1][1] << endl;
    general << "A por B,M00," << M[0][0] << endl;
    general << "A por B,M01," << M[0][1] << endl;
    general << "A por B,M10," << M[1][0] << endl;
    general << "A por B,M11," << M[1][1] << endl;
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; // ¡Agregada la estructura XML faltante en el reporte!
    general << "<matriz>" << endl;
    general << "    <A>" << endl;
    general << "        <a00>" << A[0][0] << "</a00>" << endl;
    general << "        <a01>" << A[0][1] << "</a01>" << endl;
    general << "        <a10>" << A[1][0] << "</a10>" << endl;
    general << "        <a11>" << A[1][1] << "</a11>" << endl;
    general << "    </A>" << endl;
    general << "    <B>" << endl;
    general << "        <b00>" << B[0][0] << "</b00>" << endl;
    general << "        <b01>" << B[0][1] << "</b01>" << endl;
    general << "        <b10>" << B[1][0] << "</b10>" << endl;
    general << "        <b11>" << B[1][1] << "</b11>" << endl;
    general << "    </B>" << endl;
    general << "    <constante>" << constante << "</constante>" << endl;
    general << "    <resultadoConstante>" << endl;
    general << "        <c00>" << C[0][0] << "</c00>" << endl;
    general << "        <c01>" << C[0][1] << "</c01>" << endl;
    general << "        <c10>" << C[1][0] << "</c10>" << endl;
    general << "        <c11>" << C[1][1] << "</c11>" << endl;
    general << "    </resultadoConstante>" << endl;
    general << "    <resultadoMatriz>" << endl;
    general << "        <m00>" << M[0][0] << "</m00>" << endl;
    general << "        <m01>" << M[0][1] << "</m01>" << endl;
    general << "        <m10>" << M[1][0] << "</m10>" << endl;
    general << "        <m11>" << M[1][1] << "</m11>" << endl;
    general << "    </resultadoMatriz>" << endl;
    general << "</matriz>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"A\": [[" << A[0][0] << "," << A[0][1] << "],[" << A[1][0] << "," << A[1][1] << "]]," << endl;
    general << "    \"B\": [[" << B[0][0] << "," << B[0][1] << "],[" << B[1][0] << "," << B[1][1] << "]]," << endl;
    general << "    \"constante\": " << constante << "," << endl;
    general << "    \"resultadoConstante\": [[" << C[0][0] << "," << C[0][1] << "],[" << C[1][0] << "," << C[1][1] << "]]," << endl;
    general << "    \"resultadoMatriz\": [[" << M[0][0] << "," << M[0][1] << "],[" << M[1][0] << "," << M[1][1] << "]]" << endl;
    general << "}" << endl;
    general.close();

    int opcion;
    do
    {
        cout << endl;
        cout << "=====================================" << endl;
        cout << "   ELIGA EL ARCHIVO A ABRIR EN BLOC   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Abrir Matriz TXT" << endl;
        cout << "2. Abrir Matriz CSV" << endl;
        cout << "3. Abrir Matriz XML" << endl;
        cout << "4. Abrir Matriz JSON" << endl;
        cout << "5. Abrir Reporte General" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                system("start notepad matriz.txt");
                break;
            case 2:
                system("start notepad matriz.csv");
                break;
            case 3:
                system("start notepad matriz.xml");
                break;
            case 4:
                system("start notepad matriz.json");
                break;
            case 5:
                system("start notepad resultado_matriz.txt");
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
    matriz obma;

    obma.leerA();
    obma.leerB();
    obma.mostrarA();
    obma.mostrarB();
    obma.porConstante();
    obma.porMatriz();
    obma.archivos();

    return 0;
}
