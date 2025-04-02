#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_
/** C++ implementation for Red-Black Tree Insertion
http://quiz.geeksforgeeks.org/c-program-red-black-tree-insertion/
   This code is adopted from the code provided by
   Dinesh Khandelwal in comments **/
   #include <bits/stdc++.h>

   using namespace std;
    
   enum Color {RED, BLACK};
    
   struct Node
   {
       int data;
       bool color;
       Node *left, *right, *parent;
    
       // Constructor
       Node(int data)
       {
          this->data = data;
          left = right = parent = NULL;
       }
   };
    
   // Class to represent Red-Black Tree
   class RBTree
   {
   private:
       Node *root;
   protected:
       void rotateLeft(Node *&, Node *&);
       void rotateRight(Node *&, Node *&);
       void fixViolation(Node *&, Node *&);
   public:
       // Constructor
       RBTree() { root = NULL; }
       void insert(const int &n);
       void inorder();
       void levelOrder();
   
   };

   
    
   // A recursive function to do level order traversal
   void inorderHelper(Node *root);
    
   /* A utility function to insert a new node with given key
      in BST */
   Node* BSTInsert(Node* root, Node *pt);

   // Utility function to do level order traversal
   void levelOrderHelper(Node *root);

   #endif

   