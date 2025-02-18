#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_
/****** Clases de Recursión y Código en C++
 * Autor: J. Corredor y Jeronimo Chaparro Tenorio
 * Fecha: 04 - 02 - 2025
 * Materia: Estructuras de Datos
 * Tópico: Notación Big O
 * *********/
#include "biblioteca.cpp"
 using namespace std;

/*Funcion que imprime el vector de cualquier tipo; v < 10 elementos*/ 
template <class T> void impresionVector(vector<T> &v);
/**Funcion para ordenar vector método burbuja**/
template <class T> void burbujaOrdenar(vector<T>& v);
/******** >>> Funciones y Utilidades a Usar: COMPLEJIDAD <<< ********/
/*** Búsqueda Binaria ***/
bool BinarySearch00(vector<int> v, int valor, int first, int last);


template <class iterador, class T> bool BinarySearch01(iterador first, iterador last, const T& valor);

bool BinarySearch02(vector<int> v, int valor, int first, int last);

/** IMPRESION Encontrado o no **/
void encontradoBinary(bool resultado);
/******** >>> Funciones y Utilidades a Usar: FICHERO <<< ********/
int sumaRecursiva(int n);
int cuadradosPares(int n);
int cuadradosPares2(int n);
int fibNumero(int n);
bool lineal(string s, char c, int l);
/******** >>> Funciones y Utilidades a Usar: MATRICES <<< ********/
//Funcion para inicializar las matrices
void iniMatriz(int **a,int **b, int **c, int n);
//Funcion para mostrar las matrices
void mostrMatrices(int **a, int n);
//Funcion para multiplicar matrices
void multiMatrices(int **a, int **b, int **c,  int n);
/*Funcion para eliminar las matrices*/
void elimnarmatriz(int **a, int **b, int **c, int n);
#endif