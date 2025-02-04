/*Fecha 29 01 2025 
        Autor: Jeronimo Chaparro Tenorio
        Tema: Programacion modular, complejidad algoritmica c++
        Materia: Estructuras de Datos
*/

#include <cstdlib> //libreria para creacion de numeros aleatorios
#include <iostream>
using namespace std;

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
        int n = atoi(argv[1]);
        int **mA =new int *[n];
        int **mB =new int *[n];
        int **mC =new int *[n];

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
