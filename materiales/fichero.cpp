#include <iostream>
#include <string>
#include <math.h>

using namespace std;

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


int main(){
	int sumaNumeros = sumaRecursiva(9);
	int cuadradosPares(33);
	int cuadradosPares2(33);
	int numFib = fibNumero(9);
	string palabra = "Palabra";
	char substring = 'g';
	bool caracter = lineal(palabra, substring, palabra.length()-1);

	cout << "Suma: " << sumaNumeros << endl;


	
}
