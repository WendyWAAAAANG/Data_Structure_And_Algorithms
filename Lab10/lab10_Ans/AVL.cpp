#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
static inline AVLNode *_createNode(int key)
{
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; // new node is initially added at leaf
    return (node);
}

inline int height(AVLNode *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

inline int updateHeight(AVLNode *root)
{
    if (root == NULL)
        return 0;
    int left = 0, right = 0;
    if (root->left == NULL && root->right == NULL) {
        root->height = 0;
        return 0;
    }
    if (root->left != NULL)
        left = updateHeight(root->left);
    if (root -> right != NULL)
        right = updateHeight(root->right);
    int height = (left > right ? left : right) + 1;
    root->height = height;
    return height;
}

inline int getBalance(AVLNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

static inline AVLNode* rightRotate(AVLNode **A_ptr)
{
    //       A                                         B
    //      / (root)             right rotate         / \
    //     B left                                    C   A
    //    / \                ------------>              /
    //  key  C   B_right                                   B_right
    //   (LL-imbalance)
    AVLNode * A = *A_ptr;

    AVLNode *B = A->left;
    AVLNode *B_right = B->right;

    B->right = A;
    A->left = B_right;

    *A_ptr = B;
    // update A B height
    // A->height = height(A);
    updateHeight(A);
    // B->height = height(B);
    updateHeight(B);
    return B;
}

static inline AVLNode* leftRotate(AVLNode **A_ptr)
{
    //  A                          B
    //   \                        / \
    //    B   --------->         A   C
    //   / \                      \
    //  B_l C                    B_l

    AVLNode *A = *A_ptr;

    AVLNode *B = A->right;
    AVLNode *B_left = B->left;

    B->left = A;
    A->right = B_left;

    *A_ptr = B;
    // A->height = height(A);
    updateHeight(A);
    // B->height = height(B);
    updateHeight(B);
    return B;
}

static inline AVLNode* rebalance(AVLNode **root){
     //, int key)
    int balance = getBalance(*root);
    if (balance == 0 || balance == 1 || balance == -1)
        return *root;
    //       A                                         B
    //      / (root)             right rotate         / \
    //     B                                         C   A
    //    / left                ------------>
    //   C  key
    //  /    (LL-imbalance)
    if (balance > 1 && getBalance((*root)->left) > 0){
        // && key < (*root)->left->key)
        return rightRotate(root);
    }

    // RR-imbalance
    if (balance < -1 && getBalance((*root)->right) < 0){
        // && key > (*root)->right->key)
        return leftRotate(root);
    }    
    //   A
    //  /
    // B
    //  \
    //   C 
    // LR-imbalance
    if (balance > 1 && getBalance((*root)->left) < 0){
        //&& key > (*root)->left->key)
        // do leftRotate first
        //       A
        //      /
        //     C
        //    /
        //   B
        (*root)->left = leftRotate(&(*root)->left);  // leftRoate B
        return rightRotate(root); // rightRotate A;
    }

    //   A
    //    \
    //     B
    //    /
    //   C 
    // RL-imbalance
    if (balance < -1 && getBalance((*root)->right) > 0){
        //&& key < (*root)->right->key)
        (*root)->right = rightRotate(&(*root)->right);
        return leftRotate(root);
    }
    return *root;
}

AVLNode *insertNode(AVLNode **proot, int x){
    AVLNode *root = *proot;
    if (root == NULL)
    {
        AVLNode *node = _createNode(x);
        *proot = node;
        return node;
    }
    else if (root->key == x)
    {
        return NULL;
    }
    if (x < root->key)
        (*proot)->left = insertNode(&root->left, x);
    else
        (*proot)->right = insertNode(&root->right, x);

    updateHeight(root);
    AVLNode *rotatedNode = rebalance(proot); //, x);
    // if (rotatedNode->left == *origin_root || rotatedNode->right == *origin_root)
    // {
    //     *origin_root = rotatedNode;
    //     updateHeight(*origin_root);
    // }
    
    return rotatedNode;
}

// inline AVLNode* findMin(AVLNode *proot)
// {
// 	if (proot == NULL)
// 		return NULL;
// 	if (proot->left == NULL)
// 	{
// 		return proot;
// 	}	
// 	return findMin(proot->left);
// }


AVLNode *deleteMin(AVLNode **proot)
{
    AVLNode* node = *proot;
	if (node == NULL)
		return NULL;
    if (node->left == NULL)
    {
        *proot = node->right;
        return node;
    }
    AVLNode *minNode = deleteMin(&(*proot)->left);
    updateHeight(*proot);
    rebalance(proot);
    return minNode;
}

AVLNode *deleteRoot(AVLNode **proot)
{
    AVLNode* node = *proot;
    // delete root
    if (node->left == NULL && node->right == NULL)
    {
        *proot = NULL;
    }
    else if (node->left != NULL && node->right == NULL)
    {
        *proot = node->left;
        // (*proot)->height = height(*proot);
    }
    else if (node->right != NULL && node->left == NULL)
    {
        *proot = node->right;
        // (*proot)->height = height(*proot);
    }
    else
    {
        AVLNode *minNode = deleteMin(&(*proot)->right);
        minNode->left = (*proot)->left;
        minNode->right = (*proot)->right;
        *proot = minNode;
    }
    return node;
}


AVLNode* deleteNode(AVLNode **proot, int x) {

	AVLNode* node = *proot;
	if (node == NULL)
	{
		return NULL;
	}	

	if (node->key == x)
	{
        node = deleteRoot(proot);
	}
	else if (x < node->key)
		node = deleteNode(&(node->left), x);
	else
		node = deleteNode(&(node->right), x);

    // (*proot)->height = height(*proot);
    updateHeight(*proot);
    AVLNode *rotatedNode = rebalance(proot); //, x);
    // if (rotatedNode->left == *origin_root || rotatedNode->right == *origin_root)
    // {
    //     *origin_root = rotatedNode;
    // }
    return node;

}

void destroyTree(AVLNode **root){
	// insert your code here
	// TODO: Post order
	if (root == NULL || *root == NULL)
		return;
	
	destroyTree(&(*root)->left);
	destroyTree(&(*root)->right);
	free(*root);
	*root = NULL;
}

// int main(void)
// {
//     AVLNode *root = NULL;

//     // printf("\nAfter inserting key 10..\n");
//     // insertNode(&root, 10);
//     // printTree(root);

//     // printf("\nAfter inserting key 5..\n");
//     // insertNode(&root, 5);
//     // printTree(root);

//     // printf("\nAfter inserting key 15..\n");
//     // insertNode(&root, 15);
//     // printTree(root);

//     // printf("\nAfter inserting elements 9, 13..\n");
//     // insertNode(&root, 9);
//     // insertNode(&root, 13);
//     // printTree(root);

//     // printf("\nAfter inserting elements 2, 6, 12, 14, ..\n");
//     // insertNode(&root, 2);
//     // insertNode(&root, 6);
//     // insertNode(&root, 12);
//     // insertNode(&root, 14);
//     // printTree(root);



//     // insertNode(&root, 10, &root);
//     // insertNode(&root, 20, &root);
//     // insertNode(&root, 30, &root);
//     // printTree(root);

//     // insertNode(&root, 40, &root);
//     // printTree(root);
//     // insertNode(&root, 50, &root);
//     // printTree(root);

//     // insertNode(&root, 25, &root);
//     // printTree(root);



//  // {13, 25, 58, 80, 15, 82, 6, 65, 29, 70, 68}
//     insertNode(&root, 13);
//     insertNode(&root, 25);
//     insertNode(&root, 58);
//     insertNode(&root, 80);
//     insertNode(&root, 15);
//     insertNode(&root, 82);
//     insertNode(&root, 6);
//     insertNode(&root, 65);
//     insertNode(&root, 29);
//     insertNode(&root, 70);
//     insertNode(&root, 68);
//     printTree(root);

//     deleteNode(&root, 13);
//     printTree(root);

//     deleteNode(&root, 58);
//     printTree(root);
// }