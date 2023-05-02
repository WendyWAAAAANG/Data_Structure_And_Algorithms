// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "list.h"

// // Write all your functions here.

// bool IsEmpty(Node* head) {
//   // If the head node is NULL then the linked list is empty.
//     if(head == NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }   
// }

// Node* InsertNode(Node** phead, int index, double x) {
//     //return null if index is invalid because of <0.
//     if(index < 0){
//         return NULL;
//         }

//     //set the iteraters.
//     int currIndex = 1;
//     Node* currNode = *phead;    //that is currNode points to the head in main function.
//     while(currNode != NULL && currIndex < index){
//         currNode = currNode -> next;
//         currIndex++;
//     }

//     if(index > 0 && currNode == NULL){
//         //which means the index exceed the length of the current lists.
//         return NULL;
//     }

//     //In the rest cases is that the index is vaild.
//     //create a new node firstly.
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode -> data = x;
//     if(index == 0){
//         //newNode -> data = x;
//         newNode -> next = *phead;
//         *phead = newNode;
//     }
//     else{
//         //newNode -> data = x;
//         newNode -> next = currNode -> next;
//         currNode -> next = newNode;
//         //currNode -> data = x;
//     }
//     return newNode;
// }

// int FindNode(Node* head, double x) {
//     //set the iteraters.
//     int currIndex = 1;
//     Node* currNode = head;

//     //use loop to find the data.
//     while(currNode != NULL ){
//         if(currNode -> data == x){
//             //which means we find the node that data equals to x.
//             return currIndex;
//         }
//         currNode = currNode -> next;
//         currIndex++;
//     }
// }
//     // if(currNode == NULL && currNode -> data != x){
//     //     //which we cannot find such data that equals to x.
//     //     return 0;
//     // }
//     // if(currNode -> data == x && currNode != NULL){
//     //     return currIndex;
//     // }

//     // //method 2: if statements in loop.
//     // while(currNode != NULL){
//     //     if(currNode -> data == x){
//     //         return currIndex;
//     //     }
//     //     else{
//     //         currNode = currNode -> next;
//     //         currIndex++;
//     //     }
//     // }
//     // return currIndex;


// int DeleteNode(Node** phead, double x) {
//     //set the iteraters.
//     int currIndex = 1;
//     Node* currNode = *phead;
//     Node* foreNode = NULL;

//     while(currNode != NULL && currNode -> data != x){
//         foreNode = currNode;
//         currNode = currNode -> next;
//         currIndex++;
//     }
//     if(currNode == NULL){
//         //which means we cannot find such node that data equals to x.
//         return 0;
//     }

//     if(currNode != NULL && foreNode ==NULL){
//         *phead = currNode -> next;
//     }
//     else{
//         foreNode -> next = currNode -> next;
//     }
//     free(currNode);
//     return currIndex;
// }

// void DisplayList(Node* head) {
//     //???why declare another pointer?
//     Node* currNode = head;
//     while(currNode != NULL){
//         printf("%f ", currNode -> data);
//         currNode = currNode -> next;
//     }
//     printf("\n");
//     return;
// }

// void DestroyList(Node* head){
//     Node* currNode = head;
//     Node* foreNode = NULL;
//     while(currNode != NULL){
//         foreNode = currNode -> next;
//         free(currNode);
//         currNode = foreNode;
//     }
//     return;

// }

// // Testing all the functions:
// int main(void) {
//   Node* head = NULL;

//   // Output: true
//   printf("%s\n", IsEmpty(head) ? "true" : "false");

//   // Must output an empty line:
//   DisplayList(head);

//   // Must output "insert failed":
//   Node* result = InsertNode(&head, 20, 7);
//   printf("%s\n", result == NULL ? "insert failed" : "insert succeeded");

//   // Output: 0.000000 1.000000 2.000000 3.000000 4.000000
//   for(int i = 0; i < 5; i++) {
//     InsertNode(&head, i, i);
//   }
//   DisplayList(head);

//   // Output: false
//   printf("%s\n", IsEmpty(head) ? "true" : "false");

//   // Output: 4.000000 3.000000 2.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
//   for(int i = 0; i < 5; i++) {
//     InsertNode(&head, 0, i);
//   }
//   DisplayList(head);

//   // Output: 0.000000 is at position 5
//   //         2.000000 is at position 3
//   //         4.000000 is at position 1
//   //         6.000000 is not in the list
//   for(int i = 0; i < 7; i += 2) {
//     int idx = FindNode(head, i);
//     if(idx > 0) {
//       printf("%f is at position %d\n", (double)i, idx);
//     } else {
//       printf("%f is not in the list\n", (double)i);
//     }
//   }

//   // Output: inserted 10.000000
//   //         4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
//   Node *in = InsertNode(&head, 3, 10);
//   printf("inserted %f\n", in->data);
//   DisplayList(head);

//   // Output: 4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000 4.000000
//   //         3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000 4.000000
//   //         3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000
//   DeleteNode(&head, 0); // Delete in the middle of the list.
//   DisplayList(head);
//   DeleteNode(&head, 4); // Delete at the front of the list.
//   DisplayList(head);
//   DeleteNode(&head, 4); // Delete at the end of the list.
//   DisplayList(head);

//   DestroyList(head);

//   return 0;
// }