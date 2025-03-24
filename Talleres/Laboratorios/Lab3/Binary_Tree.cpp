/********************************************************
 Fecha: 19 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: Arboles binarios
 Pontificia Universidad Javeriana
 Archivo: Binary_Tree.cpp
 ********************************************************/
#include <iostream>
#include "Binary_Tree.h"
using namespace std;

btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
/**Función para insertar un valor en el arbol binario**/
void btree::insert(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}
/**Función para insertar un valor en el arbol binario**/
void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
/**Función para la busqueda de un valor en el arbol binario**/
node *btree::search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}
/**Función para la busqueda de un valor en el arbol binario**/
node *btree::search(int key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}
/**Función que imprime el orden del árbol binario en orden: LDR **/
void btree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}
/**Función sobre cargada que imprime el orden del árbol binario en orden: LDR, a partir de un apuntador a un nodo **/
void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}
/**Función que imprime el orden del árbol binario en orden: LRD **/
void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}
/**Función sobre cargada que imprime el orden del árbol binario en orden: LRD, a partir de un apuntador a un nodo **/
void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}
/**Función que imprime el orden del árbol binario en orden: DLR **/
void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}
/**Función sobre cargada que imprime el orden del árbol binario en orden: DLR, a partir de un apuntador a un nodo **/
void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
}

void btree::remove(int key) {
    root = removeUtility(root, key);
}

node* btree::removeUtility(node* leaf, int key) {
    if (leaf == nullptr) return nullptr; // Árbol vacío o nodo no encontrado

    if (key < leaf->value) {
        leaf->left = removeUtility(leaf->left, key); // Buscar en el subárbol izquierdo
    } else if (key > leaf->value) {
        leaf->right = removeUtility(leaf->right, key); // Buscar en el subárbol derecho
    } else {
        // Caso 1: Nodo hoja
        if (leaf->left == nullptr && leaf->right == nullptr) {
            delete leaf;
            return nullptr;
        }
        // Caso 2: Nodo con un solo hijo
        else if (leaf->left == nullptr) {
            node* temp = leaf->right;
            delete leaf;
            return temp;
        } else if (leaf->right == nullptr) {
            node* temp = leaf->left;
            delete leaf;
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            node* minRight = leaf->right;
            while (minRight->left != nullptr) minRight = minRight->left; // Encontrar el mínimo en el subárbol derecho
            leaf->value = minRight->value; // Reemplazar el valor
            leaf->right = removeUtility(leaf->right, minRight->value); // Eliminar el duplicado
        }
    }
    return leaf;
}
