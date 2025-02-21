#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "biblioteca.h"

using namespace std;

void imprimirOrdenada(string nombreArchivo){

    queue<string> colaPalabras;  // Cola para mantener el orden de lectura

    ifstream archivo(nombreArchivo); // Abrir el archivo
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }
    string palabra, subcadena, linea;
    int cantidadP=0;
    int numeroLinea=0;
    archivo >> subcadena; // Leer el numero de lineas, que no me sirve para nada, en el codigo que hicimos
    archivo >> subcadena;  // Leer la subcadena

    while (getline(archivo, linea)) { // Leer línea por línea
        numeroLinea++;

        istringstream streamLinea(linea); // Convertir línea en stream para separar palabras

        while (streamLinea >> palabra) { // Extraer palabras de la línea
            colaPalabras.push({palabra, numeroLinea});
            if (colaPalabras.front().find(subcadena) != string::npos) {
                cantidadP++; //Contador de numero de palabras que contienen la subcadena
                cout << colaPalabras.front() << " Linea: " << numeroLinea << endl;
            }
            colaPalabras.pop();
            
            
        }
        cout << "Numero de palabras que contienen la subcadena en el archivo: " << cantidadP <<endl;
    }
    archivo.close(); // Cerrar el archivo

}

void imprimirReversa(string nombreArchivo){
    stack<pair<string, int>> pilaPalabras; // Pila (palabra, línea) para mantener el orden de lectura

    ifstream archivo(nombreArchivo); // Abrir el archivo
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }
    string palabra, subcadena, linea;
    int cantidadP=0;
    int numeroLinea=0;
    archivo >> subcadena; // Leer el numero de lineas, que no me sirve para nada, en el codigo que hicimos
    archivo >> subcadena;  // Leer la subcadena
    string invertida = subcadena;
    reverse(invertida.begin(), invertida.end());

    while (getline(archivo, linea)) { // Leer línea por línea
        numeroLinea++;
        istringstream streamLinea(linea);
        while (streamLinea >> palabra) { // Extraer palabras de la línea
            pilaPalabras.push({palabra, numeroLinea});

        }
    }

    archivo.close();

    std::cout << "Palabras que contienen la subcadena \"" << subcadenaInvertida << "\" (subcadena invertida):\n";

    // Buscar en la pila (orden inverso de lectura)
    while (!pilaPalabras.empty()) {
        auto [palabra, linea] = pilaPalabras.top();
        pilaPalabras.pop();

        if (palabra.find(invertida) != string::npos) {
            cout << << " Linea: " << numeroLinea << endl;
        }
    }

}