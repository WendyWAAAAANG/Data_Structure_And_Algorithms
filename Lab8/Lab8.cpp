#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RANDOM_RANGE 1000
#define SIZE 100000

void generateRandom(int **arr, int size){
    if (*arr == NULL)
        *arr = (int *)malloc(sizeof(int) * size);
    int *ptr = *arr;
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % RANDOM_RANGE;
    }
}

void displayArr(int *arr, int size){
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

bool IsEmpty(int *A){
    //no need anymore!!
    if(A == NULL){
        //which means the array is empty.
        return false;
    }
    //else, there has element in the heap.
    return true;
}

bool IsFull(int *A){
    //no need anymore!!
    //???
    //we can use _msize.
    //in this heap sort, index will never exceed.
    return false;
}

// int FindMinIndex(int val1, int val2, int ind1, int ind2){
//     if(val1 < val2){
//         return ind1;
//     }
//     return ind2;
// }

int FindMaxIndex(int val1, int val2, int ind1, int ind2){
    if(val1 > val2){
        return ind1;
    }
    return ind2;
}

bool Insert(int *A, int size, int x){
    // if(IsFull(A)){
    //     //to check whether the heap can continue to insert.
    //     return false;
    // }
    //otherwise, we will percolate up the heap.
    //increase the index of array.
    int hole = size++;
    //then add the node at the correct pos.
    while(hole > 0 && x > A[(hole-1)/2]){
        //as long as the hole is valid and x is not the root.
        //continue to scan the heap.
        A[hole] = A[(hole-1)/2];
        hole = (hole-1)/2;
    }
    //then assign the value of x into the current pos.
    A[hole] = x;
    return true;
}

int Delete_Max(int *A, int size){
    // if(IsEmpty(A)){
    //     //which mean we cannot delete element anymore.
    //     return 0;
    // }
     if(size == 0){
        return 0;
    }
    //declare some parameters.
    int max = A[0];
    int hole = 0;
    int x = A[--size];
    //then we can continue percolateing down.
    while((2*hole+1) < size){
        //which means the node has at least one child.
        //initialize the index to traverse the path.
        int sid = -1;
        //find the index of smaller child.
        if((2*hole+2) >= size){
            //which means the node only has one children.
            sid = 2 * hole + 1;
        }
        else{
            //otherwise, the node has two children.
            //find the smaller child' index.
            //sid = FindMinIndex(A[2*hole+1], A[2*hole+2], 2*hole+1, 2*hole+2);
            sid = A[2*hole+1] > A[2*hole+2] ? (2*hole+1) : (2*hole+2);
        }
        //then do the assignment.
        if(x >= A[sid]){
            break;
        }
        A[hole] = A[sid];
        hole = sid;
    }
    //finally find the correct pos for x.
    A[hole] = x;
    return max;
}

//////////////////////// TODO:
void HeapSort(int *A, int n){
    for(int i = 0; i < n; i++){
        //here we used to construct the heap.
        Insert(A, i, A[i]);
    }
    for(int i = n; i > 0; i--){
        //used to sort the array.
        A[i] = Delete_Max(A, i+1);
    }
    return;
}

/***************************
 * Implement QuickSort
 * *************************/
int main(int argc, char const *argv[]){
    // Don't change this
    // srand(time(NULL));
    srand(1);

    int size = 20;
    int *A1 = NULL;
    generateRandom(&A1, size);
    printf("Value of A1 before HeapSort:\n");
    displayArr(A1, size);

    // TODO:
    HeapSort(A1, size-1);
    printf("Value of A1 after HeapSort:\n");
    displayArr(A1, size);

    free(A1);
    A1 = NULL;

    size = 10000;
    generateRandom(&A1, size);
    printf("Value of A1 before HeapSort:\n");
    displayArr(A1, 20);

    // TODO:
    HeapSort(A1, size-1);
    printf("Value of A1 after HeapSort:\n");
    displayArr(A1, 20);

    return 0;
}

/*************************************** sample output
Value of A1 before HeapSort:
807 249 73 658 930 272 544 878 923 709 440 165 492 42 987 503 327 729 840 612 
Value of A1 after HeapSort:
42 73 165 249 272 327 440 492 503 544 612 658 709 729 807 840 878 923 930 987 
Value of A1 before HeapSort:
303 169 709 157 560 933 99 278 816 335 97 826 512 267 810 633 979 149 579 821 
Value of A1 after HeapSort:
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
***************************************/