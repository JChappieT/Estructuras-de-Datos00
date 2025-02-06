#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_
/****** Clases de Recursión y Código en C++
 * Autor: J. Corredor y Jeronimo Chaparro Tenorio
 * Fecha: 04 - 02 - 2025
 * Materia: Estructuras de Datos
 * Tópico: Notación Big O
 * *********/
 using namespace std;

/*Funcion que imprime el vector de cualquier tipo; v < 10 elementos*/ 
template <class T> void impresionVector(vector<T> &v){
		if(v.size() <= 20){
			for(int i=0; i < v.size(); i++)
				cout << v[i] << " ";
			cout << "\n";
		}	
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
/******** >>> Funciones y Utilidades a Usar: COMPLEJIDAD <<< ********/
/*** Búsqueda Binaria ***/
bool BinarySearch00(vector<int> v, int valor, int first, int last);

/** Template Busqueda Binaria **/
/* Los elementos son comparados usando el operador < 
   Dos elementos a y b son considerados equivalentes sí
   				(!(a<b) && !(b<a)).
   */
template <class iterador, class T> bool BinarySearch01(iterador first, iterador last, const T& valor){
		first = lower_bound(first, last, valor);
		return (first!=last && !(valor<*first));
}

bool BinarySearch02(vector<int> v, int valor, int first, int last);
/**Impresion de Resultado Búsqueda**
void resultados(int valor, int indice){
	if (indice == -1)
		cout << "Valor #-> " << valor << " <-# no encontrado" << endl;
	else
		cout << "Valor #-> " << valor << " <-# encontrado en el indice: #-> " << indice << " <-#" << endl; 
}


**/
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
/*Funcion para iniciar los vectores*/
void iniciVectores(int* v01, int* v02, int* v03, int n);

#endif