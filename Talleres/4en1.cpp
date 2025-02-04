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

using namespace std;
using namespace chrono;

/******** >>> Funciones y Utilidades a Usar: RECURSION <<< ********/

/*Funcion que imprime el vector de cualquier tipo; v < 10 elementos*/ 
template <class T> void impresionVector(vector<T> &v){
		if(v.size() <= 20){
			for(int i=0; i < v.size(); i++)
				cout << v[i] << " ";
			cout << "\n";
		}	
};

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
template <class iterador, class T>
	bool BinarySearch01(iterador first, iterador last, const T& valor){
		first = lower_bound(first, last, valor);
		return (first!=last && !(valor<*first));
}

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
        a[i]=new int [n];
        b[i]=new int [n];
        c[i]=new int [n];

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

int main(int argc, char* argv[]){
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

	return 0;
}









