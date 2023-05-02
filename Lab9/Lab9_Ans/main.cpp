#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main() 
{
  Node * root = NULL;    
  
  printf("\nAfter inserting key 10..\n");
  insertNode(&root,10);
  printTree(root);

  printf("\nAfter inserting key 5..\n");
  insertNode(&root,5);
  printTree(root);

  printf("\nAfter inserting key 15..\n");
  insertNode(&root,15);
  printTree(root);

  printf("\nAfter inserting elements 9, 13..\n");
  insertNode(&root,9);
  insertNode(&root,13);
  printTree(root);

  printf("\nAfter inserting elements 2, 6, 12, 14, ..\n");
  insertNode(&root,2);
  insertNode(&root,6);
  insertNode(&root,12);
  insertNode(&root,14);
  printTree(root);
  simplePrintTree(root);

  
  printf("\n\nAfter deleting a node (14) with no child..\n");
  Node* node = deleteNode(&root,14);
  if (node != NULL)
    free(node);
  printTree(root);

  printf("\n\nAfter deleting a node (13) with left child..\n");
  node = deleteNode(&root,13);
  if (node != NULL)
    free(node);
  printTree(root);

  printf("\n\nAfter deleting a node (5) with left and right children..\n");
  node = deleteNode(&root,5);
  if (node != NULL)
    free(node);
  printTree(root);

  printf("\n\nAfter deleting a node (10) with left and right children..\n");
  node = deleteNode(&root,10);
  if (node != NULL)
    free(node);
  printTree(root);

  destroyTree(&root);

  printf("\n\nAfter destroy tree..\n");
  printTree(root);
  return 0;
}


/***************************** sample output

After inserting key 10..
10

After inserting key 5..
 10
 /
5

After inserting key 15..
 10
 / \
5  15

After inserting elements 9, 13..
   10
   / \
  /   \
 /     \
5      15
 \     /
  9   13

After inserting elements 2, 6, 12, 14, ..
     10
     / \
    /   \
   /     \
  5      15
 / \     /
2   9   13
   /   / \
  6   /   \
     12   14


After deleting a node (14) with no child..
     10
     / \
    /   \
   /     \
  5      15
 / \     /
2   9   13
   /   /
  6   12


After deleting a node (13) with left child..
     10
     / \
    /   \
   /     \
  5      15
 / \     /
2   9   12
   /
  6


After deleting a node (5) with left and right children..
     10
     / \
    /   \
   /     \
  6      15
 / \     /
2   9   12


After deleting a node (10) with left and right children..
   12
   / \
  6  15
 / \
2   9


After destroy tree..
**************************************************************/