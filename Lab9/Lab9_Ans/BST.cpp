#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "BST.h"

Node* insertNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement
	// TODO:
	Node* root = *proot;
	if (root == NULL)
	{
		Node* node = (Node *) malloc(sizeof(Node));
		node->key = x;
		node->left = NULL;
		node->right = NULL;
		*proot = node;
		return node;
	}
	else if (root->key == x)
	{
		return NULL;
	}
	if (x < root->key)
		return insertNode(&root->left, x);
	else
		return insertNode(&root->right, x);
}

inline Node* findNode(Node *root, int x){
	// insert your code here and remove the "return 0" statement
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->key == x)
	{
		return root;
	}
	else if (x < root->key)
		return findNode(root->left, x);
	else
		return findNode(root->right, x);	
}

inline Node* findMin(Node *proot)
{
	if (proot == NULL)
		return NULL;
	if (proot->left == NULL)
	{
		return proot;
	}	
	return findMin(proot->left);
}

Node* deleteNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement
	Node* node = *proot;
	if (node == NULL)
	{
		return NULL;
	}	

	if (node->key == x)
	{
		if (node->left == NULL && node->right == NULL)
		{
			*proot = NULL;
		}
		else if (node->left != NULL && node->right == NULL)
		{
			*proot = node->left;
		}
		else if (node->right != NULL && node->left == NULL)
		{
			*proot = node->right;
		}
		else
		{
			Node* rightMinNode = findMin(node->right);
			// delete old position
			rightMinNode = deleteNode(&(node->right), rightMinNode->key); 
			rightMinNode->left = node->left;
			rightMinNode->right = node->right;
			*proot = rightMinNode;
		}
		return node;
	}
	else if (x < node->key)
		return deleteNode(&(node->left), x);
	else
		return deleteNode(&(node->right), x);	
}

void destroyTree(Node **root){
	// insert your code here
	// TODO: Post order
	if (root == NULL || *root == NULL)
		return;
	
	destroyTree(&(*root)->left);
	destroyTree(&(*root)->right);
	free(*root);
	*root = NULL;
}


inline int height(Node *root)
{
	if (root == NULL)
		return 0;
	int left = height(root->left) + 1;
	int right = height(root->right) + 1;
	return left > right ? left : right;
}

static int tmpIdx = -1;

inline void _printCurrentLevel(Node* root, int l, Node *tmp[], int gap, int currentLevel)
{
	if (root == NULL)
	{
		if (l == 1)
		{
			if (tmpIdx == -1)
			{
				tmpIdx = gap - 1;
			}
			else
			{
				tmpIdx += gap * 2;
			}
		}
		else
		{
			tmpIdx += gap - 1 + gap * (l - 1);
		}
		return;
	}
	if (l == 1) {	
		if (tmpIdx == -1)
		{
			tmpIdx = gap - 1;
		}
		else
		{
			tmpIdx += gap * 2;
		}
		
		tmp[tmpIdx] = root;
	}
	else if (l > 1)
	{
		_printCurrentLevel(root->left, l - 1, tmp, gap, currentLevel);
        _printCurrentLevel(root->right, l - 1, tmp, gap, currentLevel);
	}
}


void simplePrintTree(Node *root)
{
	if (root == NULL)
		return;
	
	int h = height(root);
	int max_num = pow(2, h) - 1;
	// int *tmp = (int *)malloc(sizeof(int)* max_num);
	// memset(tmp, 0, sizeof(int)* max_num);
	Node *tmp[max_num];
	memset(tmp, 0, sizeof(Node*)* max_num);
	// printf("%d\n", h);
	for (int i = 1; i <= h; i++)
	{
		_printCurrentLevel(root, i, tmp, (max_num + 1)/ pow(2, i), i);

		for (int j = 0; j < max_num; j++)
		{
			if (tmp[j] == NULL)
			{
				printf(" ");
			}
			else
			{
				char s[5];
				sprintf(s, "%d", tmp[j]->key);
				printf("%2s", s);
			}
		}
		printf("\n");

		for (int j = 0; j < max_num; j++)
		{
			if (tmp[j] == NULL || tmp[j]->left == NULL && tmp[j]->right == NULL)
			{
				printf(" ");
			}
			else
			{
				if (tmp[j]->left != NULL && tmp[j]->right != NULL)
					printf("/ \\");
				else if (tmp[j]->left != NULL && tmp[j]->right == NULL)
					printf(" /");
				else if (tmp[j]->left == NULL && tmp[j]->right != NULL)
				{
					printf(" \\");
				} 
			}
		}
		printf("\n");

		tmpIdx = -1;
		memset(tmp, 0, sizeof(Node*)* max_num);
	}
	// free(tmp);
	
}