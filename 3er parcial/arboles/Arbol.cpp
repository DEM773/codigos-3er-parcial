#include "Arbol.h"

Arbol::Arbol() {
    raiz = NULL;
}

Arbol::~Arbol() {
    liberarMemoria(raiz);
}

void Arbol::liberarMemoria(NodoArbol* actual) {
    if (actual == NULL) return;
    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        liberarMemoria(actual->hijos[i]);
    }
    delete actual;
}

bool Arbol::estaVacio() {
    return raiz == NULL;
}

NodoArbol* buscarNodoRecursivo(NodoArbol* actual, string nombreABuscar) {
    if (actual == NULL) return NULL;
    if (actual->nombre == nombreABuscar) return actual;

    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        NodoArbol* encontrado = buscarNodoRecursivo(actual->hijos[i], nombreABuscar);
        if (encontrado != NULL) return encontrado;
    }
    return NULL;
}

NodoArbol* Arbol::buscarNodoRecursivo(NodoArbol* actual, string nombreABuscar) {
    if (actual == NULL) return NULL;
    if (actual->nombre == nombreABuscar) return actual;

    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        NodoArbol* encontrado = buscarNodoRecursivo(actual->hijos[i], nombreABuscar);
        if (encontrado != NULL) return encontrado;
    }
    return NULL;
}

bool Arbol::establecerRaiz(string nombreRaiz) {
    if (raiz != NULL) {
        cout << "[!] El arbol ya tiene una raiz llamada: " << raiz->nombre << endl;
        return false;
    }
    raiz = new NodoArbol(nombreRaiz);
    return true;
}

bool Arbol::insertarHijo(string nombrePadre, string nombreHijo) {
    if (raiz == NULL) {
        cout << "[!] Primero debes establecer el nodo Raiz (Opcion 1)." << endl;
        return false;
    }

    NodoArbol* nodoPadre = buscarNodoRecursivo(raiz, nombrePadre);
    if (nodoPadre == NULL) {
        cout << "[ERROR] No se encontro ningun nodo con el nombre '" << nombrePadre << "' para ser el padre." << endl;
        return false;
    }

    if (buscarNodoRecursivo(raiz, nombreHijo) != NULL) {
        cout << "[ERROR] El nodo '" << nombreHijo << "' ya existe en el arbol. Usa un nombre unico." << endl;
        return false;
    }

    NodoArbol* nuevoHijo = new NodoArbol(nombreHijo, nodoPadre);
    nodoPadre->hijos.push_back(nuevoHijo);
    return true;
}

void Arbol::mostrarEstructuraRecursiva(NodoArbol* actual, string prefijo, bool esUltimo) {
    if (actual == NULL) return;

    cout << prefijo;
    cout << (esUltimo ? "+-- " : "+-- ");
    cout << actual->nombre << endl;

    string nuevoPrefijo = prefijo + (esUltimo ? "    " : "|   ");
    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        bool esElUltimoHijo = (i == actual->hijos.size() - 1);
        mostrarEstructuraRecursiva(actual->hijos[i], nuevoPrefijo, esElUltimoHijo);
    }
}

void Arbol::mostrarEstructuraVisual() {
    if (raiz == NULL) {
        cout << "(El arbol esta totalmente vacio)" << endl;
        return;
    }
    cout << "\n=== REPRESENTACION GRAFICA DEL ARBOL ===" << endl;
    cout << raiz->nombre << " (Raiz)" << endl;
    
    for (size_t i = 0; i < raiz->hijos.size(); ++i) {
        bool esUltimo = (i == raiz->hijos.size() - 1);
        mostrarEstructuraRecursiva(raiz->hijos[i], "", esUltimo);
    }
    cout << "=========================================" << endl;
}

void Arbol::recolectarHojas(NodoArbol* actual, vector<string>& hojas) {
    if (actual == NULL) return;
    
    if (actual->hijos.empty()) {
        hojas.push_back(actual->nombre);
        return;
    }

    for (size_t i = 0; i < actual->hijos.size(); ++i) {
        recolectarHojas(actual->hijos[i], hojas);
    }
}

void Arbol::mostrarHojas() {
    if (raiz == NULL) {
        cout << "(El arbol esta vacio)" << endl;
        return;
    }
    vector<string> hojas;
    recolectarHojas(raiz, hojas);

    cout << "\n=== NODOS HOJA (TERMINALES) ===" << endl;
    for (size_t i = 0; i < hojas.size(); ++i) {
        cout << "[" << hojas[i] << "] ";
    }
    cout << "\n==============================" << endl;
}

void Arbol::consultarInformacionNodo(string nombreNodo) {
    if (raiz == NULL) {
        cout << "(El arbol esta vacio)" << endl;
        return;
    }

    NodoArbol* nodo = buscarNodoRecursivo(raiz, nombreNodo);
    if (nodo == NULL) {
        cout << "[!] Nodo no encontrado en el sistema." << endl;
        return;
    }

    cout << "\n--- PROPIEDADES DEL NODO [" << nodo->nombre << "] ---" << endl;
    
    if (nodo->padre == NULL) {
        cout << " -> Rol: Raiz del Arbol (No tiene padre)" << endl;
    } else {
        cout << " -> Nodo Padre: " << nodo->padre->nombre << endl;
    }

    cout << " -> Hijos asignados: ";
    if (nodo->hijos.empty()) {
        cout << "(Ninguno. Es un nodo Hoja)" << endl;
    } else {
        for (size_t i = 0; i < nodo->hijos.size(); ++i) {
            cout << "[" << nodo->hijos[i]->nombre << "] ";
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
}

void Arbol::archivos() {
    if (raiz == NULL) return;

    vector<NodoArbol*> listaNodos;
    queue<NodoArbol*> colaNodos;
    colaNodos.push(raiz);

    while(!colaNodos.empty()) {
        NodoArbol* actual = colaNodos.front();
        colaNodos.pop();
        listaNodos.push_back(actual);
        for(size_t i = 0; i < actual->hijos.size(); ++i) {
            colaNodos.push(actual->hijos[i]);
        }
    }

    ofstream txt("arbol.txt");
    txt << "PROGRAMA CONSTRUCTOR DE ARBOLES GENERALES" << endl;
    txt << endl;
    txt << "Listado General de Nodos:" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        txt << "Nodo " << i + 1 << endl;
        txt << "Nombre: " << listaNodos[i]->nombre << endl;
        txt << "Padre: " << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << endl;
        txt << "Cantidad de Hijos: " << listaNodos[i]->hijos.size() << endl;
        txt << "Es Nodo Hoja: " << (listaNodos[i]->hijos.empty() ? "Si" : "No") << endl;
        txt << endl;
    }
    txt.close();

    ofstream csv("arbol.csv");
    csv << "Indice,NombreNodo,Padre,CantidadHijos,EsHoja" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        csv << i + 1 << ",";
        csv << listaNodos[i]->nombre << ",";
        csv << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << ",";
        csv << listaNodos[i]->hijos.size() << ",";
        csv << (listaNodos[i]->hijos.empty() ? "Si" : "No") << endl;
    }
    csv.close();

    ofstream xml("arbol.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<registro_arbol>" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        xml << "    <nodo>" << endl;
        xml << "        <id>" << i + 1 << "</id>" << endl;
        xml << "        <nombre>" << listaNodos[i]->nombre << "</nombre>" << endl;
        xml << "        <padre>" << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << "</padre>" << endl;
        xml << "        <cantidadHijos>" << listaNodos[i]->hijos.size() << "</cantidadHijos>" << endl;
        xml << "        <esHoja>" << (listaNodos[i]->hijos.empty() ? "Si" : "No") << "</esHoja>" << endl;
        xml << "    </nodo>" << endl;
    }
    xml << "</registro_arbol>" << endl;
    xml.close();

    ofstream json("arbol.json");
    json << "{" << endl;
    json << "    \"nodos\": [" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        json << "        {" << endl;
        json << "            \"id\": " << i + 1 << "," << endl;
        json << "            \"nombre\": \"" << listaNodos[i]->nombre << "\"," << endl;
        json << "            \"padre\": \"" << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << "\"," << endl;
        json << "            \"cantidadHijos\": " << listaNodos[i]->hijos.size() << "," << endl;
        json << "            \"esHoja\": \"" << (listaNodos[i]->hijos.empty() ? "Si" : "No") << "\"" << endl;
        json << "        }";
        if(i < listaNodos.size() - 1) {
            json << ",";
        }
        json << endl;
    }
    json << "    ]" << endl;
    json << "}" << endl;
    json.close();

    ofstream html("arbol.html");
    html << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte de Arbol General</title>\n";
    html << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;} th{background-color:#f2f2f2;}</style>\n</head>\n<body>" << endl;
    html << "  <h2>Matriz Jerarquica de Componentes del Arbol</h2>" << endl;
    html << "  <table>\n    <tr><th>#</th><th>Nombre Nodo</th><th>Padre</th><th>Hijos Totales</th><th>Es Hoja (Terminal)</th></tr>" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        html << "    <tr><td>" << i + 1 << "</td><td>" << listaNodos[i]->nombre << "</td><td>" << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "<em>Ninguno (Raiz)</em>") << "</td><td>" << listaNodos[i]->hijos.size() << "</td><td>" << (listaNodos[i]->hijos.empty() ? "Si" : "No") << "</td></tr>" << endl;
    }
    html << "  </table>\n</body>\n</html>" << endl;
    html.close();

    ofstream general("resultado_arbol.txt");

    general << "ARCHIVO TXT" << endl;
    general << "PROGRAMA CONSTRUCTOR DE ARBOLES GENERALES" << endl;
    general << endl;
    general << "Listado General de Nodos:" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        general << "Nodo " << i + 1 << endl;
        general << "Nombre: " << listaNodos[i]->nombre << endl;
        general << "Padre: " << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << endl;
        general << "Cantidad de Hijos: " << listaNodos[i]->hijos.size() << endl;
        general << "Es Nodo Hoja: " << (listaNodos[i]->hijos.empty() ? "Si" : "No") << endl;
        general << endl;
    }

    general << "ARCHIVO CSV" << endl;
    general << "Indice,NombreNodo,Padre,CantidadHijos,EsHoja" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        general << i + 1 << "," << listaNodos[i]->nombre << "," << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << "," << listaNodos[i]->hijos.size() << "," << (listaNodos[i]->hijos.empty() ? "Si" : "No") << endl;
    }
    general << endl;

    general << "ARCHIVO XML" << endl;
    general << "<registro_arbol>" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        general << "    <nodo>" << endl;
        general << "        <id>" << i + 1 << "</id>" << endl;
        general << "        <nombre>" << listaNodos[i]->nombre << "</nombre>" << endl;
        general << "        <padre>" << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << "</padre>" << endl;
        general << "        <cantidadHijos>" << listaNodos[i]->hijos.size() << "</cantidadHijos>" << endl;
        general << "        <esHoja>" << (listaNodos[i]->hijos.empty() ? "Si" : "No") << "</esHoja>" << endl;
        general << "    </nodo>" << endl;
    }
    general << "</registro_arbol>" << endl;
    general << endl;

    general << "ARCHIVO JSON" << endl;
    general << "{" << endl;
    general << "    \"nodos\": [" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        general << "        {" << endl;
        general << "            \"id\": " << i + 1 << "," << endl;
        general << "            \"nombre\": \"" << listaNodos[i]->nombre << "\"," << endl;
        general << "            \"padre\": \"" << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << "\"," << endl;
        general << "            \"cantidadHijos\": " << listaNodos[i]->hijos.size() << "," << endl;
        general << "            \"esHoja\": \"" << (listaNodos[i]->hijos.empty() ? "Si" : "No") << "\"" << endl;
        general << "        }";
        if(i < listaNodos.size() - 1) general << ",";
        general << endl;
    }
    general << "    ]" << endl;
    general << "}" << endl;
    general << endl;

    general << "ARCHIVO HTML" << endl;
    general << "<!DOCTYPE html>\n<html>\n<head>\n<title>Reporte de Arbol General</title>\n";
    general << "<style>body{font-family:sans-serif;padding:20px;} table{border-collapse:collapse;margin:10px 0;} th,td{border:1px solid #ccc;padding:8px;} th{background-color:#f2f2f2;}</style>\n</head>\n<body>" << endl;
    general << "  <h2>Matriz Jerarquica de Componentes del Arbol</h2>" << endl;
    general << "  <table>\n    <tr><th>#</th><th>Nombre Nodo</th><th>Padre</th><th>Hijos Totales</th><th>Es Hoja (Terminal)</th></tr>" << endl;
    for(size_t i = 0; i < listaNodos.size(); ++i) {
        general << "    <tr><td>" << i + 1 << "</td><td>" << listaNodos[i]->nombre << "</td><td>" << (listaNodos[i]->padre ? listaNodos[i]->padre->nombre : "Ninguno") << "</td><td>" << listaNodos[i]->hijos.size() << "</td><td>" << (listaNodos[i]->hijos.empty() ? "Si" : "No") << "</td></tr>" << endl;
    }
    general << "  </table>\n</body>\n</html>" << endl;

    general.close();

    cout << "\n[!] Guardando y abriendo todos los reportes del arbol..." << endl;

    system("notepad arbol.txt");
    system("cmd /c start arbol.csv");
    system("explorer arbol.html");
    system("notepad arbol.xml");
    system("notepad arbol.json");
    system("notepad resultado_arbol.txt");
}
