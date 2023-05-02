#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

// Write all your functions here.

bool IsEmpty(Node* head) {
  // If the head node is NULL then the linked list is empty.
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }   
}

Node* InsertNode(Node** phead, int index, double x) {
    //return null if index is invalid because of <0.
    if(index < 0){
        return NULL;
        }

    //set the iteraters.
    int currIndex = 1;
    Node* currNode = *phead;    //that is currNode points to the head in main function.
    while(currNode != NULL && currIndex < index){
        currNode = currNode -> next;
        currIndex++;
    }

    if(index > 0 && currNode == NULL){
        //which means the index exceed the length of the current lists.
        return NULL;
    }

    //In the rest cases is that the index is vaild.
    //create a new node firstly.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    if(index == 0){
        //newNode -> data = x;
        newNode -> next = *phead;
        *phead = newNode;
    }
    else{
        //newNode -> data = x;
        newNode -> next = currNode -> next;
        currNode -> next = newNode;
        //currNode -> data = x;
    }
    return newNode;
}

int FindNode(Node* head, double x) {
    //set the iteraters.
    int currIndex = 1;
    Node* currNode = head;

    //use loop to find the data.
    while(currNode != NULL ){
        if(currNode -> data == x){
            //which means we find the node that data equals to x.
            return currIndex;
        }
        currNode = currNode -> next;
        currIndex++;
    }
    return 0;
}

int DeleteNode(Node** phead, double x) {
    //set the iteraters.
    int currIndex = 1;
    Node* currNode = *phead;
    Node* foreNode = NULL;

    while(currNode != NULL && currNode -> data != x){
        foreNode = currNode;
        currNode = currNode -> next;
        currIndex++;
    }
    if(currNode == NULL){
        //which means we cannot find such node that data equals to x.
        return 0;
    }

    if(currNode != NULL && foreNode == NULL){
        *phead = currNode -> next;
    }
    else{
        foreNode -> next = currNode -> next;
    }
    free(currNode);
    //set pointer as null.
    currNode = NULL;
    return currIndex;
}

void DisplayList(Node* head) {
    Node* currNode = head;
    while(currNode != NULL){
        printf("%f ", currNode -> data);
        currNode = currNode -> next;
    }
    //print a backspace after a list printed.
    printf("\n");
    return;
}

void DestroyList(Node** phead){
    Node* currNode = *phead;
    Node* foreNode = NULL;
    while(currNode != NULL){
        foreNode = currNode -> next;
        free(currNode);
        currNode = foreNode;
    }
    *phead = NULL;
    return;
}

// Testing all the functions:
int main()
{
	Node *head = 0;
	for(int i=0; i<5; i++)
		InsertNode(&head, i, i);
	DisplayList(head);
	
    for(int i=0; i<5; i++)
		InsertNode(&head, 0, i);
	DisplayList(head);
    
    InsertNode(&head,12, 7);
    //above operation is invaild,
    //because the index is exceed the length of list.
    DisplayList(head);
    //so the list will not be changed.

	for(int i=0; i<7; i+=2){
		int idx = FindNode(head, i);
		if(idx>0)
			printf("%d is at position %d.\n", i, idx);
		else
			printf("%d is not in the list.\n", i);
	}
	DeleteNode(&head, 0);
	DisplayList(head);

	DeleteNode(&head,4);
	DisplayList(head);

    DeleteNode(&head, 7);
    DisplayList(head);
	
    DestroyList(&head);
    //DisplayList(head);
}