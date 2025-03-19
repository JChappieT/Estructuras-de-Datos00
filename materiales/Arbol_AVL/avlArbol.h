/********************************************************
 Fecha: 18 de marzo de 2025

 Materia: Estructura de Datos.
 Tema: Arboles AVL
 Pontificia Universidad Javeriana
 Archivo: avlArbol.h
 ********************************************************/
#ifndef _AVLARBOL_H
#define _AVLARBOL_H
#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class AVL {
    class node {
    public:
        T data; //store data in AVL
        node* left; //point to left node
        node* right; //point to right node
        int height; //the maximum path from specified node to leaves
    };
    node* root = NULL;//in the first time before adding in AVL Tree

    //function to calculate the maximum value from specified node
    int maxUtility(node* current);
    //to return height of node
    int height(node* current);

    //right rotation if not balanced in the left
    node* rightRotation(node* current);

    //left rotation if not balanced in the right
    node* leftRotation(node* current);

    //to Display the values by In Order Method .. left - node - right
    void inOrderUtility(node* current);

    //to Display the values by Pre Order Method .. node - left - right
    void preOrderUtility(node* current);

    //to Display the values by Post Order Method .. left - right - node
    void postOrderUtility(node* current);

    //to add node in the AVL Tree with balanced result
    node* insertUtility(node* current, T value);
    //to remove node from the AVL Tree with balanced result
    node* removeUtility(node* current, T value);

    //display bt level order .. level by level
    void display_BFS();
public:
    //these Function will Appear in main when use object
    void insert(T value);
    void remove(T value);
    void inorder();
    void preOrder();
    void postOrder();
    void levelOrder();
};

//Implementación de las funciones

 //function to calculate the maximum value from specified node
 template<typename T>
 int AVL<T>::maxUtility(node* current)
 {
     if (current->right == NULL) return current->data;
     else return maxUtility(current->right);
 }

 //to return height of node
 template<typename T>
 int AVL<T>::height(node* current) {
     if (current == NULL) return 0;
     return current->height;
 }

 //right rotation if not balanced in the left
 template<typename T>
 typename AVL<T>::node* AVL<T>::rightRotation(node* current) {
     node* new_node = current->left;
     current->left = new_node->right;
     new_node->right = current;
     current->height = 1 + max(height(current->left), height(current->right));
     new_node->height = 1 + max(height(new_node->left), height(new_node->right));
     return new_node;
 }

 //left rotation if not balanced in the right
 template<typename T>
 typename AVL<T>::node* AVL<T>::leftRotation(node* current) {
     node* new_node = current->right;
     current->right = new_node->left;
     new_node->left = current;
     current->height = 1 + max(height(current->left), height(current->right));
     new_node->height = 1 + max(height(new_node->left), height(new_node->right));
     return new_node;
 }

 //to Display the values by In Order Method .. left - node - right
 template<typename T>
 void AVL<T>::inOrderUtility(node* current) {
     if (current == NULL) {
         return;
     }
     inOrderUtility(current->left);
     cout << current->data << " ";
     inOrderUtility(current->right);
 }

 //to Display the values by Pre Order Method .. node - left - right
 template<typename T>
 void AVL<T>::preOrderUtility(node* current) {
     if (current == NULL) {
         return;
     }
     cout << current->data << " ";
     preOrderUtility(current->left);
     preOrderUtility(current->right);
 }

 //to Display the values by Post Order Method .. left - right - node
 template<typename T>
 void AVL<T>::postOrderUtility(node* current) {
     if (current == NULL) {
         return;
     }
     postOrderUtility(current->left);
     postOrderUtility(current->right);
     cout << current->data << " ";
 }

 //to add node in the AVL Tree with balanced result
 template<typename T>
 typename AVL<T>::node* AVL<T>::insertUtility(node* current, T value) {
     //if AVL Tree is empty
     if (current == NULL) {
         node* new_node = new node;
         new_node->data = value;
         new_node->right = NULL;
         new_node->left = NULL;
         new_node->height = 1;
         current = new_node;
         return new_node;
     }
     //if AVL Tree is not empty
     if (value < current->data) current->left = insertUtility(current->left, value); //go to the last left
     else if (value > current->data) current->right = insertUtility(current->right, value); //go to the last right
     current->height = 1 + max(height(current->left), height(current->right)); //recalculate height of new node
     int balance = height(current->left) - height(current->right); //calculate balance with defference between left and right hand sides
     //if not balanced in the left side
     if (balance > 1) {
         // Left Right Case
         /*
                  5
                 /
                3
                 \
                  4
         */
         if (value > current->left->data) {
             current->left = leftRotation(current->left);
             return rightRotation(current);
         }
             // Left Left Case
             /*
                      5
                     /
                    3
                   /
                  2
             */
         else {
             return rightRotation(current);
         }
     }
         //if not balanced in the right side
     else if (balance < -1) {
         // Right Left Case
         /*
               5
                \
                 7
                /
               6
         */
         if (value < current->right->data) {
             current->right = rightRotation(current->right);
             return leftRotation(current);
         }
             // Right Right Case
             /*
                    5
                     \
                      6
                       \
                        7
             */
         else {
             return leftRotation(current);
         }
     }
     return current;
 }

 //to remove node from the AVL Tree with balanced result
 template<typename T>
typename AVL<T>::node* AVL<T>::removeUtility(node* current, T value) {
    if (current == NULL) {
        cout << "Tree is Empty" << endl;
        return NULL;
    }

    if (value < current->data) {
        current->left = removeUtility(current->left, value);
    } else if (value > current->data) {
        current->right = removeUtility(current->right, value);
    } else {
        // Caso 1: Nodo hoja
        if (current->left == NULL && current->right == NULL) {
            delete current;
            return NULL;
        }
        // Caso 2: Nodo con un solo hijo
        else if (current->left == NULL) {
            node* temp = current->right;
            delete current;
            return temp;
        } else if (current->right == NULL) {
            node* temp = current->left;
            delete current;
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            int max = maxUtility(current->left);
            current->data = max;
            current->left = removeUtility(current->left, max);
        }
    }

    // Recalcular la altura del nodo
    current->height = 1 + max(height(current->left), height(current->right));

    // Verificar el balance del árbol
    int balance = height(current->left) - height(current->right);

    // Rotaciones para balancear el árbol
    if (balance > 1) {
        if (height(current->left->left) >= height(current->left->right)) {
            return rightRotation(current);
        } else {
            current->left = leftRotation(current->left);
            return rightRotation(current);
        }
    } else if (balance < -1) {
        if (height(current->right->right) >= height(current->right->left)) {
            return leftRotation(current);
        } else {
            current->right = rightRotation(current->right);
            return leftRotation(current);
        }
    }

    return current;
}


 //display bt level order .. level by level
 template<typename T>
 void AVL<T>::display_BFS()
 {
     if (root == NULL) cout << "Tree is empty" << endl;
     else {
         queue<node*> q;
         q.push(root);
         node* current;
         while (!q.empty()) {
             current = q.front();
             q.pop();
             cout << current->data << " ";
             if (current->left != NULL) q.push(current->left);
             if (current->right != NULL)q.push(current->right);
         }
         cout << endl;
     }
 }
 //these Function will Appear in main when use object
 template<typename T>
 void AVL<T>::insert(T value) {
     root = insertUtility(root, value);
 }
 template<typename T>
 void AVL<T>::remove(T value) {
     root = removeUtility(root, value);
 }
 template<typename T>
 void AVL<T>::inorder() {
     inOrderUtility(root);
     cout << endl;
 }
 template<typename T>
 void AVL<T>::preOrder() {
     preOrderUtility(root);
     cout << endl;
 }
 template<typename T>
 void AVL<T>::postOrder() {
     postOrderUtility(root);
     cout << endl;
 }
 template<typename T>
 void AVL<T>::levelOrder() {
     display_BFS();
 }

#endif