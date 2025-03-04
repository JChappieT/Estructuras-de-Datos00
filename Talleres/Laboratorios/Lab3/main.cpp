/********************************************************
 Fecha: 04 de marzo de 2025
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

	tree->insert(7);
	tree->insert(3);
	tree->insert(0);
	tree->insert(5);
	tree->insert(-3);
	tree->insert(1);
	tree->insert(4);
	tree->insert(6);
	tree->insert(20);	
	tree->insert(15);
	tree->insert(25);
	tree->insert(30);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;

}