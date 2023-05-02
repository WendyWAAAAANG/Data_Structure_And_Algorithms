#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BST.h"

//function implementation.
Node* createNode(int x){
	Node* no = (Node*)malloc(sizeof(Node));
	no->key = x;
	no->left = NULL;
	no->right = NULL;
	return no;
}

Node* insertNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement
	if ((*proot) == 0){
		*proot = createNode(x);
		return *proot;
	}

	if ((*proot)->key == x)
		return NULL;
	
	if ((*proot)->key > x)
		return insertNode(&(*proot)->left, x);
	else
		return insertNode(&(*proot)->right, x);
}

void inOrderScan(Node *root, int *fore, int *res){
    if(root == NULL){
        //which means the tree is empty.
        return;
    }

    //otherwise, we search the BST by in-order traverse.
    //scan left subtree recursively.
    inOrderScan(root -> left, fore, res);

    //do the comparison and update.
    if(*fore == 9999){
        //check the initial status.
        //let fore equals to root's value.
        *fore = root -> key;
    }
    //otherwise, we can update the result of res.
    else{
        //fmin!!! used to find minimum value quickly.
        //let res be the smallest distince all the time.
        //*res = fmin(*res, (root -> key) - *fore);
        *res = *res < (root -> key) - *fore ? *res : (root -> key) - *fore;
        *fore = root -> key;
    }
    // //fmin!!! used to find minimum value quickly.
    // //let res be the smallest distince all the time.
    // *res = fmin(*res, (root -> key) - *(fore));
    // *fore = root -> key;

    //scan right subtree recursively.
    inOrderScan(root -> right, fore, res);
    return;
}

int minDist(Node *root){
    //declare a variable to store the min distance of node.
    int dis = 9999;
    int fore = 9999;
    //do the in-order traversal.
    inOrderScan(root,&fore, &dis);
    return dis;
}