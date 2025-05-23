/********************************************************
 Fecha: 18 de marzo de 2025

 Materia: Estructura de Datos.
 Tema: Arboles Red-Black
 Pontificia Universidad Javeriana
 Archivo: main.cpp
 ********************************************************/

#include <iostream>
#include "RedBlackTree.h"

int main() {
    RedBlackTree tree;

    // Insert nodes into the tree
    tree.insert(11);
    tree.insert(19);
    tree.insert(7);
    tree.insert(14);
    tree.insert(17);
    tree.insert(31);
    tree.insert(26);
    tree.insert(45);

    std::cout << "Red-Black Tree structure:" << std::endl;
    tree.printTree();

    // Remove a node from the tree
    tree.remove(45);
    std::cout << "\nAfter deleting node 5:" << std::endl;
    tree.printTree();

    return 0;
}