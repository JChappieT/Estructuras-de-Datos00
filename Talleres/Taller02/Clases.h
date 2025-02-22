#ifndef _CLASES_H_
#define _CLASES_H_

#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>

using namespace std;

class ArchivoTexto{
    private:
        string nombreArchivo;
        string subcadena;
        list<string> listaLineas;
    public:
        // Destructor
        ~ArchivoTexto();
        //Funcion  que le asigna un valor al dato nombreArchivo
        void setNombreArchivo(string nombreArchivo);
        //Funcion  que devuelve el dato nombreArchivo
        string getNombreArchivo();
        //Funcion  que le asigna un valor al dato subcadena
        void setSubcadena(string subcadena);
        //Funcion  que devuelve el dato subcadena
        string getSubcadena();
        //Funcion  que le asigna un valor al dato listaLineas
        void setListaLineas(list<string> listaLineas);
        //Funcion  que devuelve el dato listaLineas
        list<string> getListaLineas();
        //Función que lee el archivo y guarda el texto en la lista listaLineas y la subcadena en el dato subcadena
        void leerArchivo();
    };

    class ColaP{
        private:
            queue<pair<string, int>> colaPalabras;  // Cola para mantener el orden de lectura
            ArchivoTexto archivoTexto; // Objeto de la clase ArchivoTexto con todo el texto del archivo
            string invSubcadena;
        public:
            // Destructor
            ~ColaP();
            //Funcion  que le asigna un valor al dato colaPalabras
            void setColaPalabras(queue<pair<string, int>> colaPalabras);
            //Funcion  que devuelve el dato colaPalabras
            queue<pair<string, int>> getColaParabras();
            //Funcion  que le asigna un valor al dato archivoTexto
            void setArchivoTexto(ArchivoTexto archivoTexto);
            //Funcion  que devuelve el dato archivoTexto
            ArchivoTexto getArchivoTexto(); 
            //Funcion  que le asigna un valor al dato invSubcadena
            void setInvSubcadena(string invSubcadena);
            //Funcion  que devuelve el dato invSubcadena
            string getInvSubcadena();
            //Función que llena la cola con las palabras del archivo y la linea en la que aparecen
            void llenarCola();
            //Función que imprime las palabras que contienen la subcadena, la linea en la que aparecen y el numero total de palabras que la contienen
            void imprimirOrdenada();
            //Función que imprime las palabras que contienen la subcadena invertida, la linea en la que aparecen y  el numero total de palabras que la contienen
            void imprimirInvertida();

            void invertirSubcadena();
    };
#endif