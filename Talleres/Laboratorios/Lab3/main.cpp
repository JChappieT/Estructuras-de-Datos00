/********************************************************
 Fecha: 19 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Arboles binarios
 Pontificia Universidad Javeriana
 Archivo: main.cpp
 ********************************************************/
#include <iostream>
#include "Binary_Tree.h"
using namespace std;

int main(){

	//btree tree;
	btree *tree = new btree();

	tree->insert(2);
	tree->insert(3);
	tree->insert(10);
	tree->insert(19);
	tree->insert(1);
	tree->insert(40);
	tree->insert(23);
	tree->insert(54);
	tree->insert(53);	
	tree->insert(48);
	tree->insert(32);
	tree->insert(35);
	cout << "Arbol in Order " << endl;
	//tree->preorder_print();
	tree->inorder_print();
	//tree->postorder_print();
	cout << "Arbol in Order, despues de eliminar 2 y 32 " << endl;
	tree->remove(2);
	tree->remove(32);
	tree->inorder_print();
	delete tree;

}