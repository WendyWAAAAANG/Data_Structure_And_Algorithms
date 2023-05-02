#include "BST.h"
#include "stdlib.h"

Node* finMin(Node *root){
	if(root == NULL){
		//which means the tree is empty.
		return NULL;
	}
	if(root -> left == NULL){
		//which means the node only has right child.
		//just return the right child of it.
		return root;
	}
	//otherwise, we will scan the left subtree of the node.
	return finMin(root -> left);
}

Node* insertNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement.
	if(*proot == NULL){
		//which means the root is empty.
		//so we just create a new node as root of tree.
		*proot = (Node*)malloc(sizeof(Node));
		(*proot) -> key = x;
		(*proot) -> left = NULL;
		(*proot) -> right = NULL;
		return *proot;
	}
	else if((*proot) -> key == x){
		//which means node with value of x is already exist.
		return NULL;
	}
	else if((*proot) -> key > x){
		//whihc means we will keep scanning the left subtree.
		return insertNode(&(*proot) -> left, x);
	}
	else{
		return insertNode(&(*proot) -> right, x);
	}
	return 0;
}

Node* deleteNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement
	Node *root = *proot;
	if(root == NULL){
		//which means the tree is empty,
		//we cannot delete any elements, just return null.
		return NULL;
	}
	else if(root -> key == x){
		//which means the current node is exactly we want to delete.
		//we check which case of the node:
		//case 1: root is leaf.
		if(root -> left == NULL && root -> right == NULL){
			//which means the node is a leaf.
			//just set itself to be null.
			*proot = NULL;
		}
		//case 2: root has only left child.
		else if(root -> left != NULL && root -> right == NULL){
			//which means the node only has left child.
			//then set the root as the left child of tree.
			*proot = root -> left;
		}
		else if(root -> left == NULL && root -> right != NULL){
			//which means the node only has right child.
			//then set the root as the right child of tree.
			*proot = root -> right;
		}
		else{
			//which means the node has two children,
			//we will move the root to right-min node.
			Node *minRight = finMin(root -> right);
			Node *dMinRight = deleteNode(&(root -> right), minRight -> key);
			dMinRight -> left = root -> left;
			dMinRight -> right = root -> right;
			*proot = dMinRight;
		}
		return root;
	}
	else if(root -> key > x){
		return deleteNode(&(root -> left), x);
	}
	else{
		return deleteNode(&(root -> right), x);
	}	
}

Node* findNode(Node *root, int x){
	// insert your code here and remove the "return 0" statement.
	if(root == NULL){
		//which means the tree is empty.
		return NULL;
	}
	if(root -> key == x){
		//which means current node is exactly what we want.
		return root;
	}
	if(root -> key > x){
		//which means we will recursively scan left subtree.
		return findNode(root -> left, x);
	}
	//otherwise, keep scan right subtree.
	return findNode(root -> right, x);
}

void destroyTree(Node **root){
	// insert your code here
	if(*root == NULL){
		//which means the tree is already empty.
		//just return withous doing anything.
		return;
	}
	else if((*root) -> left == NULL & (*root) -> right == NULL){
		//which means the current node is a leaf.
		//just free it.
		free(*root);
		return;
	}
	else if((*root) -> left == NULL & (*root) -> right != NULL){
		//recursively scan the right subtree.
		destroyTree(&((*root) -> right));
		//and free the current node.
		free(*root);
	}
	else if((*root) -> left != NULL & (*root) -> right == NULL){
		//recursively scan the left subtree.
		destroyTree(&((*root) -> left));
		//and free the current node.
		free(*root);
	}
	else{
		//which means the node has two children.
		//and follows the post-order.
		//recursively scan the left subtree.
		destroyTree(&((*root) -> left));
		//recursively scan the right subtree.
		destroyTree(&((*root) -> right));
		//and free the current node.
		free(*root);
	}
	//set the pointer points to null.
	*root = NULL;
	return;
	// Node* root = *proot;
	// if(root ==NULL){
	// 	return;
	// }
	// else{
	// 	destroyTree(&(root->left));
	// 	destroyTree(&(root->right));
	// 	free(root);
	// 	*proot=NULL;
	// 	// root = NULL;
	// 	return;
	// }
}
