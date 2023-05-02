#include "BT.h"

int main(void)
{
    /* test cases */
    int tree1[3][3] = {{1, 2, 3}, {2, 4, 5}, {3, 6, 7}};
    Node *root = constructBT(tree1, 3);
    printTree(root);

    int tree2[3][3] = {{1, 2, 3}, {2, 4, -1}, {3, -1, 6}};
    Node *root2 = constructBT(tree2, 3);
    printTree(root2);

    int tree3[][3] = {{1, 2, 3}, {2, 4, -1}, {3, -1, 6}, {6, 4, 11}};
    Node *root3 = constructBT(tree3, 4);
    printTree(root3);
}

/********************** sample output
      1
     / \
    /   \
   /     \
  2       3
 / \     / \
4   5   6   7

    1
   / \
  2   3
 /     \
4       6

    1
   / \
  2   3
 /     \
4       6
       / \
      4  11
***************************************/