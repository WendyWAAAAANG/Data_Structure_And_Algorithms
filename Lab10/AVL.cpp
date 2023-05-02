#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"


/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
static inline AVLNode* _createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    // new node is initially added at leaf.
    node->height = 0;
    return node;
}

//used to return the height of node.
inline int height(AVLNode* root) {
    if (root == NULL) {
        return 0;
    }
    //int left = height(root->left);
    //int right = height(root->right);
    //return (left > right ? left : right) + 1;
    return root->height;
}

// //used to get the height of tree.
// int getHeight(AVLNode *root) {
//     if(root == NULL) {
//         //which means the root is empty,
//         //simply return the default height -1.
//         return -1;
//     }
//     else{
//         //get the height use '->'.
//         return root -> height;
//     }
// }

// Checks whether the root is balanced or not.
// Note: this function assumes that root is not NULL.
bool isBalanced(AVLNode* root) {
    //get subtree's height recursively.
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    //calculate the difference of subtrees' height.
    int diff = leftHeight - rightHeight;
    //take the absolute value of difference.
    int d = diff < 0 ? -diff : diff;
    if (d <= 1) {
        //which means the tree is balanced.
        return true;
    }
    else {
        return false;
    }
}

// //set a global variable which describe the height of each node.
// // int nodeHeight = 0;
// //define a function to check whether the node is balanced.
// bool isBalanced(AVLNode *root){
//     if(root -> height > 1 || root -> height < -1){
//         //which means the current is unbalanced.
//         return false;
//     }
//     //otherwise, the node is balanced.
//     return true;
// }

inline int updateHeight(AVLNode* root) {
    if(root == NULL){
        //which means the tree is not exist.
        return -1;
    }
    int left = 0;
    int right = 0;
    if (root->left == NULL && root->right == NULL) {
        //which means the tree is empty.
        //so the height of this root is 0.
        root->height = 0;
        return 0;
    }
    if (root->left != NULL) {
        //update the height of left subtree recursively.
        left = updateHeight(root->left);
    }
    if (root->right != NULL) {
        //update the height of right subtree recursively.
        right = updateHeight(root->right);
    }
    //finally update the height of initial root,
    //remember to plus one.
    int height = (left > right ? left : right) + 1;
    root->height = height;
    return height;
}

// Computes the case (1, 2, 3, or 4) when the root is not balanced.
// See slide 2, chapter 11.
// Note: this function assumes that root is not NULL.
// Note: this function is only called when the tree is unbalanced (see the
// rebalance function below).  To be unbalanced, the tree must have at
// least one non-empty subtree.  If the tree has at least one non-empty
// subtree then the first "if" test in the code below guarantees that we
// will never look at an empty subtree (if any), which in turn guarantees
// that all our pointer dereferences root->...->left/right will never fail.
int checkCase(AVLNode* root) {
    //get the height of subtrees.
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    //then check the cases by checking the height of subtree.
    if (leftHeight > rightHeight) {
        // Tree is left heavy.
        int leftLeftHeight = height(root->left->left);
        int leftRightHeight = height(root->left->right);
        if (leftLeftHeight >= leftRightHeight) {
            // Tree is left left heavy.
            // The = above is to use left left (not left right) when the left
            // subtree is perfectly balanced (see slide 25, chapter 11).
            return 1;
        }
        else {
            // Tree is left right heavy.
            return 2;
        }
    }
    else {
        // Tree is right heavy.
        int rightLeftHeight = height(root->right->left);
        int rightRightHeight = height(root->right->right);
        if (rightRightHeight >= rightLeftHeight) {
            // Tree is right right heavy.
            // The = above is to use right right (not right left) when the right
            // subtree is perfectly balanced (see slide 25, chapter 11).
            return 4;
        }
        else {
            // Tree is right left heavy.
            return 3;
        }
    }
}

static inline AVLNode* rightRotate(AVLNode** A_ptr) {
    // //no way! may lost tree.
    // (*A_ptr) -> right = (*A_ptr) -> right -> right;
    // *A_ptr = (*A_ptr) -> left;
    // //update the height of tree.
    // updateHeight((*A_ptr) -> right);
    // updateHeight(*A_ptr);
    // return *A_ptr;
    //declare a copy of each node.
    AVLNode* k2 = *A_ptr, * k1 = k2->left, * Y = k1->right;
    //change the pointer of each node.
    *A_ptr = k1;
    k1->right = k2;
    k2->left = Y;
    //update the height of tree.
    updateHeight(k2);
    return *A_ptr;
}

static inline AVLNode* leftRotate(AVLNode** A_ptr) {
    //declare a copy of each node.
    AVLNode* k1 = *A_ptr, * k2 = k1->right, * Y = k2->left;
    //change the pointer of each node.
    *A_ptr = k2;
    k2->left = k1;
    k1->right = Y;
    //update the height of tree.
    updateHeight(k1);
    updateHeight(k2);
    return *A_ptr;
}

static inline AVLNode* rebalance(AVLNode** root) {
    if(*root == NULL){
        //which means the tree is empty.
        return NULL;
    }
    if (isBalanced(*root)) {
        //which means the root is already balnce,
        //simply return.
        return *root;
    }
    //otherwise, we divide 4 cases to balance the tree.
    if (checkCase(*root) == 1) {
        //which refers to the left-left case.
        rightRotate(root);
    }
    else if (checkCase(*root) == 4) {
        //which refers to the right-right case.
        leftRotate(root);
    }
    else if (checkCase(*root) == 2) {
        //which refers to the left-right case.
        leftRotate(&((*root)->left));
        rightRotate(root);
    }
    else {
        //which refers the right-left case.
        rightRotate(&((*root)->right));
        leftRotate(root);
    }
    return NULL;
}

AVLNode* insertNode(AVLNode** proot, int x) {
    //declare a root of tree.
    AVLNode* root = *proot;
    //declare a new node.
    AVLNode* newNode = NULL;
    //firstly check whether the tree is exist.
    if (root == NULL) {
        //which means the tree is not exist.
        //just create a new node.
        root = _createNode(x);
        *proot = root;
        return *proot;
    }
    //otherwise, we check value of root.
    //then check whether the key is already exist.
    if (root->key == x) {
        //which means the key is already in the tree,
        //we cannot insert again.
        return NULL;
    }
    if (root->key > x) {
        //which means we will recursively search the left subtree.
        newNode = insertNode(&(root->left), x);
    }
    else {
        //otherwise, we recursively search the right subtreee.
        newNode = insertNode(&(root->right), x);
    }
    //update the height of tree.
    updateHeight(root);
    //and reabalance the tree.
    rebalance(&root);
    return newNode;
}

// AVLNode* finMin(AVLNode *root){
// 	if(root == NULL){
// 		//which means the tree is empty.
// 		return NULL;
// 	}
// 	if(root -> left == NULL){
// 		//which means the node only has right child.
// 		//just return the right child of it.
// 		return root;
// 	}
// 	//otherwise, we will scan the left subtree of the node.
// 	return finMin(root -> left);
// }

AVLNode* deleteMin(AVLNode** proot) {
    // insert your code here and remove the "return 0" statement
    //remove and return the min node.
    //in the sun-tree lead by root.
    //AVLNode* root = *proot;
    AVLNode* minNode = NULL;
    if ((*proot)->left == NULL) {
        //which means teh root is the min node.
        //with no left child.
        minNode = *proot;
        //delete the min node, change the root.
        *proot = (*proot)->right;
        return minNode;
    }
    minNode = deleteMin(&((*proot)->left));
    updateHeight(*proot);
    rebalance(proot);
    return minNode;
}

AVLNode* deleteRoot(AVLNode** proot) {
    //remove and return the root.
    AVLNode* currNode = *proot;
    if ((*proot)->left == NULL) {
        //which means the tree does not have left subtree.
        //so move pointer to right subtree.
        *proot = (*proot)->right;
        return currNode;
    }
    if ((*proot)->right == NULL) {
        //which means the tree does not have right subtree.
        //so move pointer to left subtree.
        *proot = (*proot)->left;
        return currNode;
    }
    //otherwise, the root has two children.
    //we will delete right-min child or left-max child.
    AVLNode* minNode = deleteMin(&((*proot)->right));
    minNode->left = (*proot)->left;
    minNode->right = (*proot)->right;
    *proot = minNode;
    return currNode;
}


AVLNode* deleteNode(AVLNode** proot, int x) {
    if (*proot == NULL) {
        //which means the tree does not exist.
        return NULL;
    }
    //otherwise, declare a pointer to futher delete node recursively.
    AVLNode* matchNode = NULL;
    if ((*proot)->key > x) {
        matchNode = deleteNode(&((*proot)->left), x);
    }
    else if ((*proot)->key < x) {
        matchNode = deleteNode(&((*proot)->right), x);
    }
    else {
        matchNode = deleteRoot(proot);
    }
    // Note: at this point *proot might be NULL because we have just deleted
    // a node and the AVL tree might be empty now:
    updateHeight(*proot);
    rebalance(proot);
    return matchNode;
}

void destroyTree(AVLNode** root) {
    // insert your code here
    // TODO: Post order
    if (root == NULL || *root == NULL)
        return;
    //otherwise, destroy left and right subtree recursively.
    destroyTree(&(*root)->left);
    destroyTree(&(*root)->right);
    //free memory of current root, set pointer points to NULL.
    free(*root);
    *root = NULL;
    return;
}
