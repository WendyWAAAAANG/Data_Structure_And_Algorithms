#include "list.h"
#include <stdio.h>
#include <stdlib.h>

bool IsEmpty(Node *head){
	Node *p;
	p = head->next;
	if(p == NULL){
		return true;
	}
	return false;
}

Node *InsertNode(Node **phead, int index, double x){
	// initializing the node to be inserted
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = x;

	Node *tmp = *phead;
	if (index >= 0)
	{
		if (index == 0)
		{
			// insert at the beginning position
			*phead = node;
		}
		else
		{
			Node *pre = NULL;
			// use loop to find specific position to insert the node
			for (int i = 0; i < index; i++, pre = tmp, tmp = tmp->next) ;
			pre->next = node;
		}

		node->next = tmp;
	}
	else
	{
		return NULL;
	}
	return *phead;
}

int FindNode(Node *head, double x){
	for (int pos = 1; head; pos++, head = head->next)
	{
		if (head->data == x)
		{
			return pos;
		}
	}
	return 0;
}

void DisplayList(Node *head){
	if (head == NULL){
		printf("NULL\n");
		return;
	}
	for (; head; head = head->next){
		if (head->next)
		{
			printf("%g->", head->data);
		}
		else
		{
			printf("%g\n", head->data);
		}
	}
}

void DestroyList(Node *head){
	Node *temp;
	Node *currNode = head;
	if (head == NULL){
		return;
	}
	int i = 1;
	for (i = 1; currNode->next != NULL; i++){
		temp = currNode->next;
		free(currNode);
		currNode = temp;
	}
}

int DeleteNodes(Node **phead, double x){
	// remove all the elements from a linked list that have value x.
    // return the number of occurrences.
    // firsly we check whether the list is empty.
    if(*phead == NULL){
        // which means the list is empty.
        return 0;
    }
    // declare a counter to record occurrences of x.
    int counter = 0;
    // declare pointers for traverse.
    Node *currNode = *phead;
    Node *foreNode = NULL;
    while(currNode != NULL){
        // then we continue to scan the node.
        // check value of currNode.
        if(currNode -> data == x && currNode == *phead){
            // increase the counter.
            counter++;
            *phead = currNode -> next;
            // which means the head of list should be changed.
            free(currNode);
            currNode = *phead;
            foreNode = NULL;
        }
        else if(currNode -> data == x){
            // increase counter.
            counter++;
            // which means the node should be removed.
            foreNode -> next = currNode -> next;
            free(currNode);
            foreNode = foreNode -> next;
            if(foreNode == NULL){
                // currNode = foreNode -> next;
                break;
            }
            else{
                currNode = foreNode -> next;
            }
        }
        // otherwise, move to next point.
        else{
            foreNode = currNode;
            currNode = currNode -> next;
        }
    }
    // which means all node that data = x are removed.
    return counter;
}

void RemoveDuplicates(Node **phead){
// 	// remove duplicates from sorted list.
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
//     Node *tempNode = NULL;
//     // use while statement to traverse the list.
//     while(currNode != NULL){
//         // continously traverse the whole list.
//         if(currNode -> data == foreNode -> data){
//             // which means there are duplicate nodes,
//             // we fix the foreNode to check whether duplicate still exist.
//             // while(currNode -> data == foreNode -> data){
//             //     // save the next node and free current node.
//             //     tempNode = currNode;
//             //     currNode = currNode -> next;
//             //     free(tempNode);
//             // }
//             // // otherwise, we can save the next foreNode.
//             // foreNode -> next = currNode;

//             //which means we have encounter a duplicate node.
//             //firstly, store the first node of duplicate.
//             //in the meanwhile,
//             //we need to check whether the duplicate is start from head.
//             if(foreNode == *phead){
//                 //which means duplicate start from head.
//                 //free memory the head node.
//                 free(*phead);
//                 //set currNode as new head node.
//                 *phead = currNode;
//                 foreNode = *phead;
//             }
//             else{
//                 tempNode = foreNode;
//                 //we should do the delete operation.
//                 foreNode -> next = currNode -> next;
//                 free(currNode);
//                 currNode = foreNode -> next;
//                 //free the first duplicate node.
//                 free(tempNode);
//             }

//             //firstly, check whether duplicate starts from head.
//             if(foreNode == *phead){
//                 //which means need to delete head.
//                 //update the pointers.
//                 tempNode = *phead;
//                 *phead = tempNode -> next;

//                 foreNode = currNode;
//                 currNode = currNode -> next;
//                 //use loop to intervatively delete duplicate.
//                 while(currNode -> data == tempNode -> data){
//                 }
//             }
//         }
//         // // otherwise, continusely scan the next node.
//         // foreNode = currNode;
//         // currNode = currNode -> next;

//         else{
//             //update all pointers.
//             tempNode = foreNode;
//             foreNode = currNode;
//             currNode = currNode -> next;
//         }
//     }
//     // end loop, we can simply return.
//     return;


    //firstly to check whther list is empty.
    if(*phead == NULL){
        //list is empty, just return NULL.
        return;
    }
    //otherwise, we scan the list.
    Node *currNode = (*phead);
    Node *foreNode = NULL;
    Node *nextNode = (*phead) -> next;
    while(nextNode != NULL){
        //we continue scan the data in the list.
        if(currNode -> data == nextNode -> data && currNode != *phead){
            //if the duplicate node does not at head.
            //which means we need to remove currNode and nextNode,
            //if necessary, may be need to remove the coming node.
            if(nextNode -> next == NULL){
                free(currNode);
                free(nextNode);
                foreNode -> next = NULL;
                return;
            }
            else if(nextNode -> data != nextNode -> next -> data){
                //then we will delete two nodes.
                foreNode -> next = nextNode -> next;
                free(currNode);
                free(nextNode);
                currNode = foreNode -> next;
                nextNode = currNode -> next;
            }
            else{
                //we only delete current node, use loop to delete next.
                foreNode -> next = currNode -> next;
                free(currNode);
                currNode = nextNode;
                if(currNode != NULL){
                    nextNode = currNode -> next;
                }
                else{
                    break;
                }
            }
            
        }
        else if(currNode -> data == nextNode -> data && currNode == *phead){
            //which means the node should be removed and it at head.
            if(nextNode -> next == NULL){
                //which means we have scan all lists.
                //just delete two points.
                free(currNode);
                free(nextNode);
                *phead = NULL;
                return;
            }
            else if(nextNode -> data != nextNode -> next -> data){
                //which means the two node should be deleted at the same time.
                *phead = nextNode -> next;
                free(currNode);
                free(nextNode);
                //update pointers.
                foreNode = NULL;
                currNode = *phead;
                if(currNode != NULL){
                    nextNode = currNode -> next;
                }
                else{
                    break;
                }
                //nextNode = currNode -> next;
            }
            else{
                //we only delete current node.
                *phead = nextNode;
                free(currNode);
                //update pointers.
                foreNode = NULL;
                currNode = *phead;
                if(currNode != NULL){
                    nextNode = currNode -> next;
                }
                else{
                    break;
                }
            }
        }
        else{
            //otherwise, move all pointers forward.
            //which means the val is single.
            foreNode = currNode;
            currNode = nextNode;
            nextNode = nextNode -> next;
        }
    }
    return;
}

void ReverseList(Node **phead){
	// reverse the linked list.
    // firstly check whether the list is empty.
    if(*phead == NULL){
        // which means the list is empty.
        return;
    }
    // otherwise, we can use iteration to reverse the list.
    Node *currNode = *phead;
    Node *foreNode = NULL;
    while(currNode != NULL){
        // declare a temp node to store the node after currNode.
        Node *temp = currNode -> next;
        // change the node currNode points to.
        currNode -> next = foreNode;
        // update the node.
        foreNode = currNode;
        currNode = temp;
    }
    // update the head node.
    *phead = foreNode;
    return;
}
