/****** Clases de Recursión y Código en C++
 * Autor: J. Corredor
 * Fecha: 05 - 02 - 2024
 * Tópico: Notación Big O
 * *********/

#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
#include <string>
#include <time.h>

using namespace std;
using namespace chrono;

/******** >>> Funciones y Utilidades a Usar <<< ********/

/*Funcion que imprime el vector de cualquier tipo; v < 10 elementos*/ 
template <class T> void impresionVector(vector<T>& v){
	//if (v.size() < 10){
		for(int i=0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << "\n";
	//}
}

/**Funcion para ordenar vector método burbuja**/
template <class T> void burbujaOrdenar(vector<T>& v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size()-1; j++){
			if(v[j]>v[j+1]){
				swap(v[j], v[j+1]);
			}
		}
	}
}

int BinarySearch(vector<int> v, int low, int high, int x){
	if (high >= low){
		int mid = low+(high-low)/2;
		if(v[mid] == x)
			return mid;
		if(v[mid] > x)
			return BinarySearch(v, low, (mid-1), x);
		return BinarySearch(v, low, (mid+1), x);
	}
	return -1;
}


int main(int argc, char* argv[]){
	srand(time(NULL)); //Generación Semilla aleatoriedad
	int dim = atoi(argv[1]);
	/*Generación Vectores de Prueba*/
	vector<int> v01(dim);
	vector<int> v02(dim);
	vector<int> v03(dim);
	

	for(int i=0; i < dim; i++){
		v01[i] = rand()%(200);		
		v02[i] = rand()%(300);		
		v03[i] = rand()%(400);		
	}

	impresionVector(v01);
	
	auto t0 = high_resolution_clock::now();
	burbujaOrdenar(v01);
	auto t1 = high_resolution_clock::now();
	cout << "Tiempo ejecucion: " << duration_cast<microseconds>(t1-t0).count() << " micro_s\n";

	//impresionVector(v01);
	
	int resultado = BinarySearch(v01, 0, v01.size() -1, 8);
	cout << "resultado " << resultado << endl;
	return 0;
}









