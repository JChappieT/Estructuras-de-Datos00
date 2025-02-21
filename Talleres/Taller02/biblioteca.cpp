#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "biblioteca.h"

using namespace std;

//Función que imprime las palabras que contienen la subcadena, la linea en la que aparecen y el numero total de palabras que la contienen
void imprimirOrdenada(string a){

    queue<string> colaPalabras;  // Cola para mantener el orden de lectura

    ifstream archivo(a); // Abrir el archivo
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }
    string palabra, subcadena, linea;
    int cantidadP=0;
    int numeroLinea=0;
    archivo >> subcadena; // Leer el numero de lineas, que no me sirve para nada, en el codigo que hicimos
    archivo >> subcadena;  // Leer la subcadena
    cout << subcadena << endl;
    while (getline(archivo, linea)) { // Leer línea por línea
        numeroLinea++;

        istringstream streamLinea(linea); // Convertir línea en stream para separar palabras

        while (streamLinea >> palabra) { // Extraer palabras de la línea
            colaPalabras.push(palabra);
            if (colaPalabras.front().find(subcadena) != string::npos) {
                cantidadP++; //Contador de numero de palabras que contienen la subcadena
                cout << colaPalabras.front() << " Linea: " << numeroLinea+1 << endl;
            }
            colaPalabras.pop();
            
            
        }
        
    }
    cout << "Numero de palabras que contienen la subcadena en el archivo: " << cantidadP <<endl;
    archivo.close(); // Cerrar el archivo

}

//Función que imprime las palabras que contienen la subcadena invertida, la linea en la que aparecen y  el numero total de palabras que la contienen
void imprimirReversa(string a){
    stack<pair<string, int>> pilaPalabras; // Pila (palabra, línea) para mantener el orden de lectura

    ifstream archivo(a); // Abrir el archivo
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
    cout << invertida << endl;

    while (getline(archivo, linea)) { // Leer línea por línea
        numeroLinea++;
        istringstream streamLinea(linea);
        while (streamLinea >> palabra) { // Extraer palabras de la línea
            pilaPalabras.push({palabra, numeroLinea});

        }
    }

    archivo.close();// Cerrar el archivo

    // Buscar en la pila (orden inverso de lectura)
    while (!pilaPalabras.empty()) {
        auto [palabra, numeroLinea] = pilaPalabras.top();
        pilaPalabras.pop();

        if (palabra.find(invertida) != string::npos) {
            cantidadP++; //Contador de numero de palabras que contienen la subcadena invertida
            cout << palabra << " Linea: " << numeroLinea+1 << endl;
        }
    }
    cout << "Numero de palabras que contienen la subcadena invertida en el archivo: " << cantidadP <<endl;
}