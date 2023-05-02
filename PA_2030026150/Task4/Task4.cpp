// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// //structure & function declaration.
// typedef struct Node Node;
// int minDist(Node *root);
// void inOrderScan(Node *root, int *res);

// //structure implementation.
// typedef struct Node{
//   int key;
//   struct Node *left, *right;
// } Node;

// //function implementation.
// void inOrderScan(Node *root, int *res){
//     Node *forNode = root;
//     int fore = root -> key;
//     if(root == NULL){
//         //which means the tree is empty.
//         return;
//     }
//     //otherwise, we search the BST by in-order traverse.
//     //scan left subtree recursively.
//     inOrderScan(root -> left, res);

//     //do the comparison and update.
//     // if(fore == -1){
//     //     //check the initial status.
//     //     //let fore equals to root's value.
//     //     fore = root -> key;
//     // }
//     //otherwise, we can update the result of res.
//     // else{
//         // //fmin!!! used to find minimum value quickly.
//         // //let res be the smallest distince all the time.
//         // *res = fmin(*res, (root -> key) - (fore));
//         // fore = root -> key;
//     // }

//     //fmin!!! used to find minimum value quickly.
//     //let res be the smallest distince all the time.
//     *res = fmin(*res, (root -> key) - (fore));
//     fore = root -> key;
//     //scan right subtree recursively.
//     inOrderScan(root -> right, res);
//     return;
// }

// int minDist(Node *root){
//     //declare a variable to store the min distance of node.
//     int dis = 0;
//     //do the in-order traversal.
//     inOrderScan(root, &dis);
//     return dis;
// }

// // int main(){
// //     constructBT();
// //     int res = minDist(*root);
// //     printf("%d", res);
// //     return 0;
// // }