#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "Clases.h"

using namespace std;
// Destructor
ArchivoTexto::~ArchivoTexto() {
    // Limpiar la lista de líneas
    
}
//Funcion  que le asigna un valor al dato nombreArchivo
void ArchivoTexto::setNombreArchivo(string nombreArchivo){
    this->nombreArchivo = nombreArchivo;
}
//Funcion  que devuelve el dato nombreArchivo
string ArchivoTexto::getNombreArchivo(){
    return nombreArchivo;
}
//Funcion  que le asigna un valor al dato subcadena
void ArchivoTexto::setSubcadena(string subcadena){
    this->subcadena = subcadena;
}
//Funcion  que devuelve el dato subcadena
string ArchivoTexto::getSubcadena(){
    return subcadena;
}
//Funcion  que le asigna un valor al dato listaLineas
void ArchivoTexto::setListaLineas(list<string> listaLineas){
    this->listaLineas = listaLineas;
}
//Funcion  que devuelve el dato listaLineas
list<string> ArchivoTexto::getListaLineas(){
    return listaLineas;
}
//Función que lee el archivo y guarda el texto en la lista listaLineas y la subcadena en el dato subcadena
void ArchivoTexto::leerArchivo() {
    ifstream archivo(this->nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    string linea;
    archivo >> subcadena; // Leer el número de líneas (no lo usamos)
    archivo >> subcadena; // Leer la subcadena

    getline(archivo, linea); // Consumir el salto de línea pendiente

    while (getline(archivo, linea)) {
        listaLineas.push_back(linea); // Guardar línea completa
    }

    archivo.close();
}


// Destructor
ColaP::~ColaP() {
    // Limpiar la cola de palabras
    while (!colaPalabras.empty()) {
        colaPalabras.pop();
    }
}
//Funcion  que le asigna un valor al dato colaPalabras
void ColaP::setColaPalabras(queue<pair<string, int>> colaPalabras){
    this->colaPalabras = colaPalabras;
}
//Funcion  que devuelve el dato colaPalabras
queue<pair<string, int>> ColaP::getColaParabras(){
    return colaPalabras;
}
//Funcion  que le asigna un valor al dato archivoTexto
void ColaP::setArchivoTexto(ArchivoTexto archivoTexto){
    this->archivoTexto = archivoTexto;
}
//Funcion  que devuelve el dato archivoTexto
ArchivoTexto ColaP::getArchivoTexto(){
    return archivoTexto;
}
//Funcion  que le asigna un valor al dato invSubcadena
void ColaP::setInvSubcadena(string invSubcadena){
    this->invSubcadena = invSubcadena;
}
//Funcion  que devuelve el dato invSubcadena
string ColaP::getInvSubcadena(){
    return invSubcadena;
}
//Función que llena la cola con las palabras del archivo y la linea en la que aparecen
void ColaP::llenarCola(){
    int numeroLinea=0;
    string palabra;
    
    for(const auto& linea : archivoTexto.getListaLineas()) {
        numeroLinea++;
        istringstream streamLinea(linea);
        while (streamLinea >> palabra) { // Extraer palabras de la línea
            this->colaPalabras.push({palabra, numeroLinea});     
        }
    }
    
}
//Función que imprime las palabras que contienen la subcadena, la linea en la que aparecen y el numero total de palabras que la contienen
void ColaP::imprimirOrdenada(){
    string palabra;
    int numeroLinea;
    int cantidadP=0;
    // Buscar en la pila (orden inverso de lectura)
    while (!colaPalabras.empty()) {
        auto [palabra, numeroLinea] = colaPalabras.front();
        colaPalabras.pop();

        if (palabra.find(archivoTexto.getSubcadena()) != string::npos) {
            cantidadP++; //Contador de numero de palabras que contienen la subcadena invertida
            cout << palabra << " Linea: " << numeroLinea+2 << endl;
        }
    }
    cout << "Numero de palabras que contienen la subcadena ordenada en el archivo: " << cantidadP <<endl;
}
//Función que imprime las palabras que contienen la subcadena invertida, la linea en la que aparecen y  el numero total de palabras que la contienen
void ColaP::imprimirInvertida(){
    string palabra;
    int numeroLinea;
    int cantidadP=0;
    // Buscar en la pila (orden inverso de lectura)
    while (!colaPalabras.empty()) {
        auto [palabra, numeroLinea] = colaPalabras.front();
        colaPalabras.pop();

        if (palabra.find(invSubcadena) != string::npos) {
            cantidadP++; //Contador de numero de palabras que contienen la subcadena invertida
            cout << palabra << " Linea: " << numeroLinea+2 << endl;
        }
    }
    cout << "Numero de palabras que contienen la subcadena invertida en el archivo: " << cantidadP <<endl;
}

void ColaP::invertirSubcadena(){
    invSubcadena = archivoTexto.getSubcadena();
    reverse(invSubcadena.begin(), invSubcadena.end());
    this->setInvSubcadena(invSubcadena);
}
