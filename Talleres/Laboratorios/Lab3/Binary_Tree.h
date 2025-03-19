/********************************************************
 Fecha: 04 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Arboles binarios
 Pontificia Universidad Javeriana
 Archivo: Binary_Tree.h
 ********************************************************/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

using namespace std;


struct node{
	int value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
	void remove(int key);

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);
	node* removeUtility(node* leaf, int key);

	node *root;
};

#endif