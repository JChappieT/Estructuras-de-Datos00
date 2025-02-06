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

/*Funcion que imprime el vector de cualquier tipo; v < 10 elementos*/ 
template <class T> void impresionVector(vector<T> &v);
/**Funcion para ordenar vector método burbuja**/
template <class T> void burbujaOrdenar(vector<T>& v);

template <class iterador, class T> bool BinarySearch01(iterador first, iterador last, const T& valor);

int main(int argc, char* argv[]){
	if (argc < 2){
		cout << "Cantidad de argumentos invalida\n";
		exit(0);
	}
    int sumaNumeros = sumaRecursiva(9);
	int cuadradosPares(33);
	int cuadradosPares2(33);
	int numFib = fibNumero(9);
	string palabra = "Palabra";
	char substring = 'g';
	bool caracter = lineal(palabra, substring, palabra.length()-1);

	cout << "Suma: " << sumaNumeros << endl;

    int resultado, n;
	srand(time(NULL)); //Generación Semilla aleatoriedad
	int dim = atoi(argv[1]);
    n = dim;
    //Se crean las matrices
    int **mA =new int *[n];
    int **mB =new int *[n];
    int **mC =new int *[n];


	/*Generación Vectores de Prueba*/
	vector<int> v01(dim);
	vector<int> v02(dim);
	vector<int> v03(dim);
	
	for(int i=0; i < dim; i++){
		v01[i] = rand()%(200);		
		v02[i] = rand()%(300);		
		v03[i] = rand()%(400);		
	}

    /** Vector Inicial **/
    cout << "\nVector inicial:\n";
	impresionVector(v01);
	
	auto t0 = high_resolution_clock::now();
	burbujaOrdenar(v01);
	auto t1 = high_resolution_clock::now();
	cout << "Tiempo ejecucion: " << duration_cast<microseconds>(t1-t0).count() << " micro_s\n";

	/** Vector Ordenado recursivamente **/
	cout << "\nVector Ordenado por burbuja:\n";
	impresionVector(v01);

    //COMPLEJIDAD
    bool result0 = BinarySearch00(v01, 8, 0, v01.size());
	encontradoBinary(result0);

	bool result1 = BinarySearch01(v01.begin(),v01.end(), 8);  
	encontradoBinary(result1);

	bool result2 = BinarySearch01(v01.begin(), v01.end(), 8);
	encontradoBinary(result2);

	bool result3 = BinarySearch02(v01, 8, 0, v01.size());
	encontradoBinary(result3);
	/*(result3 == -1) 
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result3;	
	*/

    //Se inicializan las matrices
    iniMatriz(mA, mB, mC, n); 
          
    //Multiplicamos las matrices A x B = C
    multiMatrices(mA,mB,mC,n);

    //Se imprimen las matices
    cout << "\nMatriz A\n"; 
    mostrMatrices(mA, n);
    
    cout << "\nMatriz B\n"; 
    mostrMatrices(mB, n);

    cout << "\nMatriz C\n"; 
    mostrMatrices(mC, n);

	/*ELIMINAR LA RESERVA DE MEMORIA*/
	elimnarmatriz(mA, mB, mC, n);
	

	return 0;
}









