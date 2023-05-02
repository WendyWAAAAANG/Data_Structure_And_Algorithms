#include "BST.h"

int main(void)
{
    /* test cases */
    Node* root = NULL;
    insertNode(&root,5);
    insertNode(&root,2);
    insertNode(&root,0);
    insertNode(&root,3);
    insertNode(&root,7);
    printTree(root);
    printf("The minimun distance is:%d\n",minDist(root));

    Node* root1 = NULL;
    insertNode(&root1,8);
    insertNode(&root1,1);
    insertNode(&root1,15);
    insertNode(&root1,12);
    insertNode(&root1,25);
    printTree(root1);
    printf("The minimun distance is:%d\n",minDist(root1));

    Node* root2 = NULL;
    insertNode(&root2,8);
    insertNode(&root2,1);
    printTree(root2);
    printf("The minimun distance is:%d\n",minDist(root2));


     Node* root3 = NULL;
    insertNode(&root3,20);
    insertNode(&root3,10);
    insertNode(&root3,50);
    insertNode(&root3,2);
    insertNode(&root3,19);
    insertNode(&root3,21);
    printTree(root3);
    printf("The minimun distance is:%d\n",minDist(root3));   

    return 0;

}

/**************************** sample output
    5
   / \
  2   7
 / \
0   3

The minimun distance is:1
  8
 / \
1  15
   / \
  /   \
 12   25

The minimun distance is:3
  8
 /
1

The minimun distance is:7
     20
     / \
    /   \
   /     \
  10     50
 / \     /
2  19   21

The minimun distance is:1
****************************************/