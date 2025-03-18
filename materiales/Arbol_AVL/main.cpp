
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
    avl.insert(9);
    avl.insert(5);
    avl.insert(10);
    avl.insert(0);
    avl.insert(6);
    avl.insert(11);
    avl.insert(-1);
    avl.insert(1);
    avl.insert(2);
    /* AVL Tree will be
         9
        / \
        1 10
       / \ \
       0 5 11
      / / \
    -1  2 6
    */

    cout << "Traversal of the AVL tree is " << endl;
    avl.preOrder();
    avl.levelOrder();
    avl.remove(10);

    /* After Deletion of 10
         1
        / \
        0 9
       / / \
      -1 5 11
      / \
      2 6
    */

    cout << "\nTraversal after deletion of 10" << endl;
    avl.preOrder();
    avl.levelOrder();
    return 0;
}