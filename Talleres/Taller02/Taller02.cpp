#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "biblioteca.h"

using namespace std;

int main(int argc, char* argv[]) {

    cout << "\nCon la Subcadena ordenada: \n";
    //Se llama a la función imprimirOrdenada
    imprimirOrdenada(argv[1]);


    cout << "\nCon la Subcadena al reves: \n";
    //Se llama a la función imprimirReversa
    imprimirReversa(argv[1]);

    return 0;
}