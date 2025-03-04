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

int main(){
	//Se le solicita al usuario que ingrese una opcion del menu
	int opcion;
	cout << "Menu: \n 1. Matrices \n 2. Suma Recursiva y otras operaciones\n 3. Complejidad \n 4. Salir\n";
	cin >> opcion;

	//Declaración de la variable palabra que se utilizara en el case 2
	string palabra = "Palabra";

	//Declaracion del vector de prueba para el case 3
	vector<int> v01(0);
	int n, dim, sumaNumeros, cpares, cpares2, numFib;
	char substring;
	int **mA, **mB, **mC;
	bool caracter, result0, result1, result2;
	time_point<high_resolution_clock> t1, t0;
	//Switch Case
	switch (opcion){
	case 1:
		/* Matrices */
		cout << "Ingrese el la dimension de las matrices simetricas A, B y C \n";
		cin >> n;
		//Se crean las matrices
		mA =new int *[n];
		mB =new int *[n];
		mC =new int *[n];

		//Se inicializan las matrices
		iniMatriz(mA, mB, mC, n); 
			
		//Multiplicamos las matrices A x B = C
		multiMatrices(mA,mB,mC,n);

		//Se imprimen las matices
		cout << "\nMatriz A\n"; 
		mostrMatrices(mA, n);
		
		cout << "\nMatriz B\n"; 
		mostrMatrices(mB, n);

		cout << "\nMatriz C = A x B\n"; 
		mostrMatrices(mC, n);

		/*ELIMINAR LA RESERVA DE MEMORIA*/
		elimnarmatriz(mA, mB, mC, n);
		
		break;
	
	case 2:
		/* Suma Recursiva */
		cout << "Ingrese un numero para la suma recursiva \n";
		cin >> n;
		sumaNumeros = sumaRecursiva(n);
		cpares = cuadradosPares(33);
		cpares2 = cuadradosPares2(33);
		numFib = fibNumero(9);
		substring = 'g';
		caracter = lineal(palabra, substring, palabra.length()-1);
		cout << "Resultado de la suma Suma: " << sumaNumeros << endl;
		
		break;
	
	case 3:
		/* Complejidad */
		cout << "Ingrese un numero < 20 para definir el tamano del vector \n";
		cin >> dim;
		srand(time(NULL)); //Generación Semilla aleatoriedad

		/*Cambio de tamaño del Vector de Prueba*/
		v01.resize(dim);
		/*Se ingresan valores al vector*/
		for(int i=0; i < dim; i++){
			v01[i] = rand()%(200);		
		}

		/** Vector Inicial **/
		cout << "\nVector inicial:\n";
		impresionVector(v01);
		
		cout << "\nSe empieza a organizar el vector por metodo de burbuja:";
		t0 = high_resolution_clock::now();
		burbujaOrdenar(v01);
		t1 = high_resolution_clock::now();
		/*Tiempo transcurrido en la ordenación del vector*/
		cout << "\nTiempo ejecucion: " << duration_cast<microseconds>(t1-t0).count() << " micro_s\n";

		/** Vector Ordenado recursivamente **/
		cout << "\nVector Ordenado por burbuja:\n";
		impresionVector(v01);

		cout << "\nBusqueda Binaria de la primera forma:\n";
		//COMPLEJIDAD busquedas binarias con 3 metodos diferentes
		result0 = BinarySearch00(v01, 8, 0, v01.size());
		encontradoBinary(result0);

		cout << "\nBusqueda Binaria de la segunda forma:\n";
		result1 = BinarySearch01(v01.begin(),v01.end(), 8);  
		encontradoBinary(result1);

		cout << "\nBusqueda Binaria de la tercera forma:\n";
		result2 = BinarySearch02(v01, 8, 0, v01.size());
		encontradoBinary(result2);

		break;
	
	case 4:
		/* Salir */
		return 0;

		break;
	
	default:
		return 0;
		break;
	}	
	
	return 0;
}











