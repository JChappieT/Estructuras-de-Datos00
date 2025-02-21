#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "biblioteca.h"

using namespace std;

int main() {

    //Se solicita el nombre del archivo
    cout << "Ingrese el nombre del archivo \n";
    string nombreArchivo;
    cin >> nombreArchivo;
    cout << "Con la Subcadena ordenada: \n";
    //Se llama a la función imprimirOrdenada
    imprimirOrdenada(nombreArchivo);


    cout << "Con la Subcadena al reves: \n";
    //Se llama a la función imprimirReversa
    imprimirReversa(nombreArchivo);
    return 0;
}