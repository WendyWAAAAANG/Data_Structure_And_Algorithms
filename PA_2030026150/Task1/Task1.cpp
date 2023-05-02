// #include <stdio.h>
// #include <stdlib.h>

// // define the structure.
// typedef struct Node {
//     /* data */
//     double data;
//     Node *next;
// } Node;


// // functions declaration.
// int DeleteNodes(Node **phead, double x);
// void RemoveDuplicates(Node **phead);
// void ReverseList(Node **phead);

// // function implementataion.
// int DeleteNodes(Node **phead, double x){
//     // remove all the elements from a linked list that have value x.
//     // return the number of occurrences.
//     // firsly we check whether the list is empty.
//     if(*phead == NULL){
//         // which means the list is empty.
//         return 0;
//     }
//     // declare a counter to record coourrences of x.
//     int counter = 0;
//     // declare pointers for traverse.
//     Node *currNode = *phead;
//     Node *foreNode = NULL;
//     while(currNode != NULL){
//         // then we continue to scan the node.
//         // check value of currNode.
//         if(currNode -> data == x && currNode == *phead){
//             // increase the counter.
//             counter++;
//             // which means the head of list should be changed.
//             free(*phead);
//             *phead = currNode -> next;
//             currNode = (*phead) -> next;
//             foreNode = *phead;
//         }
//         else if(currNode -> data == x){
//             // increase counter.
//             counter++;
//             // which means the node should be removed.
//             foreNode -> next = currNode -> next;
//             free(currNode);
//         }
//         // otherwise, move to next point.
//         foreNode = currNode;
//         currNode = currNode -> next;
//     }
//     // which means all node that data = x are removed.
//     return counter;
// }

// void RemoveDuplicates(Node **phead){
//     // remove duplicates from sorted list.
//     // delete all nodes thar have duplicate calues,
//     // leaving only nodes with distinct values.
//     // firstly check whether the list is empty.
//     if(*phead == NULL){
//         // which means the list is empty.
//         return;
//     }
//     // otherwise, we can check the list use loop.
//     // declare pointers for traverse.
//     Node *currNode = (*phead) -> next;
//     Node *foreNode = *phead;
//     Node *tempNode = currNode;
//     // use while statement to traverse the list.
//     while(currNode != NULL){
//         // continously traverse the whole list.
//         if(currNode -> data == foreNode -> data){
//             // which means there are duplicate nodes,
//             // we fix the foreNode to check whether duplicate still exist.
//             while(currNode -> data == foreNode -> data){
//                 // save the next node and free current node.
//                 tempNode = currNode;
//                 currNode = currNode -> next;
//                 free(tempNode);
//             }
//             // otherwise, we can save the next foreNode.
//             foreNode -> next = currNode;
//         }
//         // otherwise, continusely scan the next node.
//         foreNode = currNode;
//         currNode = currNode -> next;
//     }
//     // end loop, we can simply return.
//     return;
// }

// void ReverseList(Node **phead){
//     // reverse the linked list.
//     // firstly check whether the list is empty.
//     if(*phead == NULL){
//         // which means the list is empty.
//         return;
//     }
//     // otherwise, we can use iteration to reverse the list.
//     Node *currNode = *phead;
//     Node *foreNode = NULL;
//     while(currNode != NULL){
//         // declare a temp node to store the node after currNode.
//         Node *temp = currNode -> next;
//         // change the node currNode points to.
//         currNode -> next = foreNode;
//         // update the node.
//         foreNode = currNode;
//         currNode = temp;
//     }
//     // update the head node.
//     *phead = foreNode;
//     return;
// } 