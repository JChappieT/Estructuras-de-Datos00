/****** Clases de Recursión y Código en C++
 * Autor: J. Corredor y Jeronimo Chaparro Tenorio
 * Fecha: 04 - 02 - 2025
 * Materia: Estructuras de Datos
 * Tópico: Notación Big O
 * *********/

#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>
#include "biblioteca.h"

using namespace std;
using namespace chrono;

/******** >>> Funciones y Utilidades a Usar: COMPLEJIDAD <<< ********/

/*** Búsqueda Binaria ***/
bool BinarySearch00(vector<int> v, int valor, int first, int last){
		if (last >= first){
			int mid = first+(last-first)/2;
			// valor Encontrado justo en la mitad
			if(v[mid] == valor)
				return true;
			//Busqueda en la mitad superior
			if(v[mid] > valor)
				return BinarySearch00(v, valor, first, mid-1);
			//Busqueda en la mitad inferior 
			return BinarySearch00(v, valor, mid+1, last);
		}
		//Valor no Encontrado
		return false;
}

/** Template Busqueda Binaria **/
/* Los elementos son comparados usando el operador < 
   Dos elementos a y b son considerados equivalentes sí
   				(!(a<b) && !(b<a)).
   */

bool BinarySearch02(vector<int> v, int valor, int first, int last){
	while (first <= last){
		int mid = first + (last-first)/2;
		if(v[mid] == valor)
			return true;
		if(v[mid] < valor)
			first = mid + 1;
		else
			last = mid - 1;
	}
	return false;
}


/**Impresion de Resultado Búsqueda**
void resultados(int valor, int indice){
	if (indice == -1)
		cout << "Valor #-> " << valor << " <-# no encontrado" << endl;
	else
		cout << "Valor #-> " << valor << " <-# encontrado en el indice: #-> " << indice << " <-#" << endl; 
}
**/

/** IMPRESION Encontrado o no **/
void encontradoBinary(bool resultado){
	if(resultado == 1)
		cout << "Valor encontrado" << endl;
	else		
		cout << "Valor NO encontrado" << endl;
}

/******** >>> Funciones y Utilidades a Usar: FICHERO <<< ********/

int sumaRecursiva(int n){
	if(n <= 1) {
		return n;
	}
	else{
		return n + sumaRecursiva(n-1);
	}
}

int cuadradosPares(int n){
	if(n == 0){
		return n;
	}
	else if(n % 2 == 0) {
		return n*n + cuadradosPares(n-1);
	} else {
		return cuadradosPares(n - 1);
	}
}

int cuadradosPares2(int n){
	if(n == 0){
		return n;
	} else {
		return pow(n+n,2) + cuadradosPares2(n - 1);
	}
}

int fibNumero(int n){
 	if(n <= 1){
		return n;
	} else {
		return fibNumero(n-1) + fibNumero(n-2);
	}
}


bool lineal(string s, char c, int l){
	if(l < 0){
		return false;
	} else if (s[l] == c){
		return true;		
	} else {
		return lineal(s, c, l-1);
	}
}

/******** >>> Funciones y Utilidades a Usar: MATRICES <<< ********/
//Funcion para inicializar las matrices
void iniMatriz(int **a,int **b, int **c, int n){
    //Se inicializa el generador de n aleatorios
    srand(time(0));
    //Se inicia cada matriz
    for(int i=0; i<n; i++){
        a[i]=new int [n]{0};
        b[i]=new int [n]{0};
        c[i]=new int [n]{0};

        for(int j=0; j<n; j++){
            a[i][j] = (rand() % (51));
            b[i][j] = (rand() % (51));
            c[i][j] = 0;
        }
    }
}

//Funcion para mostrar las matrices
void mostrMatrices(int **a, int n){
    //Se imprimen las matices
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }cout << "\n";
    }
}

//Funcion para multiplicar matrices
void multiMatrices(int **a, int **b, int **c,  int n){
    //Se multiplican AxB = C
    for(int i=0; i<n; i++){         //filas
        for(int j=0;j<n;j++){   //Columnas
            int suma=0;
            for(int k=0;k<n;k++){
                suma+=a[i][k]*b[k][j];
            }
            c[i][j]=suma;
        }
    }       
} 

/*Funcion para eliminar las matrices*/
void elimnarmatriz(int **a, int **b, int **c, int n){
	for (int i = 0; i < n; i++){
		delete a[n];
		delete b[n];
		delete c[n];
	}
	delete[] a;
	delete[] b;
	delete[] c;
}









