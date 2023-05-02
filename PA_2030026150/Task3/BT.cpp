#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include "BT.h"

static inline Node* createNode(int x){
	Node* no = (Node*)malloc(sizeof(Node));
	no->key = x;
	no->left = NULL;
	no->right = NULL;
	return no;
}

Node* findNode(Node *root, int x){
    if(!root)
        return NULL;
    if (root->key == x)
        return root;
    
    Node* leftre = findNode(root->left,x);
    if (leftre)
        return leftre;
    
    Node* rightre = findNode(root->right, x);
    return rightre;
}



Node* constructBT(int matrix[][3], int rowNum){
    // convert the matrix into tree.
    if(matrix[0][0] == -1){
        // which means the tree is empty.
        printTree(NULL);
    }
    //otherwise, construct first 3 node of tree.
    Node *root = (Node*)malloc(sizeof(Node));
    root -> key = matrix[0][0];
    Node *leftChild = (Node*)malloc(sizeof(Node));
    leftChild -> key = matrix[0][1];
    leftChild -> left = NULL;
    leftChild -> right = NULL;
    Node *rightChild = (Node*)malloc(sizeof(Node));
    rightChild -> key = matrix[0][2];
    rightChild -> left = NULL;
    rightChild -> right = NULL;
    root -> left = leftChild;
    root -> right = rightChild;
    //then construct rest nodes by find the parent node.
    for(int i = 1; i < rowNum; i++){
      // use find node to find parent.
      Node *newNode = findNode(root, matrix[i][0]);
      newNode -> key = matrix[i][0];
      if(matrix[i][1] != -1){
        Node *newLeftChild = (Node*)malloc(sizeof(Node));
        newLeftChild -> key = matrix[i][1];
        newNode -> left = newLeftChild;
      }
      if(matrix[i][2] != -1){
        Node *newRightChild = (Node*)malloc(sizeof(Node));
        newRightChild -> key = matrix[i][2];
        newNode -> right = newRightChild;
      }
     
    }
    return root;
}


