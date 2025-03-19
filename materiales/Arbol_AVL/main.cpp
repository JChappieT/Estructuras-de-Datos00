
/********************************************************
 Fecha: 18 de marzo de 2025
 
 Materia: Estructura de Datos.
 Tema: Arboles AVL
 Pontificia Universidad Javeriana
 Archivo: main.cpp
 ********************************************************/
#include "avlArbol.h"
using namespace std;

int main(){
    AVL<int> avl;
    avl.insert(2);
    avl.insert(3);
    avl.insert(10);
    avl.insert(19);
    avl.insert(1);
    avl.insert(40);
    avl.insert(23);
    avl.insert(54);
    avl.insert(53);
    avl.insert(48);
    avl.insert(32);
    avl.insert(35);
    

    cout << "Arbol in Order " << endl;
    avl.inorder();
    cout << "Transversal " << endl;
    avl.levelOrder();
    avl.remove(2);
    avl.remove(32);

    cout << "\nArbol in order despues de eliminar 2 y 32" << endl;
    avl.inorder();
    cout << "Transversal " << endl;
    avl.levelOrder();
    return 0;
}