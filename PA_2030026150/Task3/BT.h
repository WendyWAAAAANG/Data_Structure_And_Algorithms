typedef struct Node 
{
  int key;
  Node *left, *right;
} Node;

Node* findNode(Node *root, int x);

Node* constructBT(int matrix[][3], int rowNum);


void printTree(Node * root);
