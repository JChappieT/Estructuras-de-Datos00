#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Clases.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Error en los argumentos.\n";
        return 1;
    }
    ColaP colaP;
    ArchivoTexto archivoTexto;
    archivoTexto.setNombreArchivo(argv[1]);
    archivoTexto.leerArchivo();
    for (const auto& linea : archivoTexto.getListaLineas()) {
        cout << linea << endl;
    };
    
    colaP.setArchivoTexto(archivoTexto);
    cout << "\nNombre de archivo: \n" << colaP.getArchivoTexto().getNombreArchivo() << endl;
    colaP.llenarCola();
    cout << "\nCon la Subcadena |" << colaP.getArchivoTexto().getSubcadena() << "| ordenada: \n";
    //Se llama a la función imprimirOrdenada
    colaP.imprimirOrdenada();

    colaP.llenarCola();
    colaP.invertirSubcadena();
    cout << "\nCon la Subcadena |" << colaP.getInvSubcadena() << "| invertida: \n";
    //Se llama a la función imprimirReversa
    colaP.imprimirInvertida();
    
    return 0;
}