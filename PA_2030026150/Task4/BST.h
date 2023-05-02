#ifndef __BST_H___
#define __BST_H___
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
  int key;
  Node *left, *right;
} Node;

Node* insertNode(Node **proot, int x);

void printTree(Node * root);

int minDist(Node* root);

#endif