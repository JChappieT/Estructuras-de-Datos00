/********************************************************
 Fecha: 2 de Abril de 2025
 Autores:Jeronimo Chaparro Tenorio.
 Materia: Estructura de Datos.
 Tema: LBORATORIO ÁRBOL ROJO NEGRO
 Pontificia Universidad Javeriana
 Archivo: main.cpp
 ********************************************************/
#include <bits/stdc++.h>
   #include "biblioteca.h"
   using namespace std;
    

   // Driver Code
   int main()
   {
       RBTree tree;
    
       tree.insert(11);
       tree.insert(19);
       tree.insert(7);
       tree.insert(14);
       tree.insert(17);
       tree.insert(31);
       tree.insert(26);
       tree.insert(45);
       tree.insert(70);
    
       cout << "Inoder Traversal of Created Tree\n";
       tree.inorder();
    
       cout << "\n\nLevel Order Traversal of Created Tree\n";
       tree.levelOrder();
       cout << "\n";
    
       return 0;

        /*Observaciones:
        El árbol no presenta un destructor lo que significa que una vez creados los nodos dinámicos no se puede liberar memoria
        El código no maneja errores, como: Intentar insertar valores repetidos o Árbol vacío en algunos métodos.
        Los resultados fueron:
        Inoder Traversal of Created Tree
        7  11  14  17  19  26  31  45  70

        Level Order Traversal of Created Tree
        11  7  19  14  31  17  26  45  70
        */
       /*Conclusión:
       El código implementa corredtamente un árbol Rojo Negro junto con su busqueda, inserción y eliminación con complejidad O(log n),
       pero puede mejorarse con ciertas funciones garantizan un correcto funciionamiento del programa.
       */
   }