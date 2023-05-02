#ifndef __AVL__H__
#define __AVL__H__
// An AVL tree node
typedef struct AVLNode{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

//function declaration.
AVLNode * insertNode(AVLNode **root, int x);

AVLNode* deleteNode(AVLNode **root, int x);

void printTree(AVLNode *root);

void destroyTree(AVLNode **root);

#endif
