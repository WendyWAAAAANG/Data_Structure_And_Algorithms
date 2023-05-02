#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//functions declaration.
void InsertionSort(int *A, int n);
void MergeSort(int *A, int left, int right);
void Merge(int *A, int left, int middle, int right);
void RandArray(int *RandNum, int num);

//functions implementation.
int main(){
    //declare n as size of the input array.
    //firstly we assgined 10.
    int n = 10;
    //declare an array called A1, A2 to store random value.
    int* A1 = (int*)malloc(sizeof(int)*n);
    int* A2 = (int*)malloc(sizeof(int)*n);
    RandArray(A1, n);
    for(int i = 0; i < n; i++){
        A2[i] = A1[i];
    }

    //print the array A1 that before sorted.
    printf("Value of A1 that before sorted:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", A1[i]);
    }
    printf("\n");
    //print the array A2 that before sorted.
    printf("Value of A2 that before sorted:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", A2[i]);
    }
    printf("\n");

    //do the sorting.
    InsertionSort(A1, n);
    MergeSort(A2, 0, (n-1));

    //print the array A1 that after sorted.
    printf("Value of A1 that after sorted:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", A1[i]);
    }
    printf("\n");
    //print the array A2 that after sorted.
    printf("Value of A2 that after sorted:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", A2[i]);
    }
    printf("\n");
    // //free the memory of two arrays.
    // free(A1);
    // free(A2);

    //change the value of n, assige as 10^5.
    n = 100000;
    //randomly assigned value of array.
    //declare an array called A1, A2 to store random value.
    A1 = (int*)malloc(sizeof(int)*n);
    A2 = (int*)malloc(sizeof(int)*n);
    RandArray(A1, n);
    for(int i = 0; i < n; i++){
        A2[i] = A1[i];
    }
    //print elapsed time.
    clock_t start = clock();
    InsertionSort(A1, n);
    clock_t end = clock();
    printf("Elapsed time of insertion sort: %f ms.\n", 1000 * (double(end - start) / CLOCKS_PER_SEC));

    start = clock();
    MergeSort(A2, 0, (n-1));
    end = clock();
    printf("Elapsed time of merge sort: %f ms.\n", 1000 * (double(end - start) / CLOCKS_PER_SEC));

    // //free the memory of two arrays.
    // free(A1);
    // free(A2);
    return 0;
}

void InsertionSort(int *A, int n){
    //declare a key to store the current elements.
    int key = 0;
    //declare an index to store the insertion index.
    int i = 0;
    //do the for loop to insert elements.
    for(int p = 1; p < n; p++){
        key = A[p];
        i = p - 1;
        while(i >= 0 && A[i] > key){
            //if the condition satisfied,
            //we should move the A[i] afterwards one position.
            A[i+1] = A[i];
            i--;
        }
        //otherwise, put the element on the current position.
        A[i+1] = key;
    }
    return;
}

void MergeSort(int *A, int left, int right){
    if(left >= right){
        //which means that we have reached the base case.
        //just return without doing any operation.
        return;
    }
    //otherwise, do the recursion to futher divide the array.
    //use floor function to get the value of middle position.
    int middle = floor((left+right) / 2);
    //then do the recursion.
    MergeSort(A, left, middle);
    MergeSort(A, middle+1, right);
    Merge(A, left, middle, right);
    return;
}

void Merge(int *A, int left, int middle, int right){
    //declare pointers.
    //i1 to store the front of the array.
    int i1 = left;
    //i2 to store the middle of the array.
    int i2 = middle+1;
    //i as index of new array.
    int i = 0;
    //declare an array called B,
    //to store the array which already sorted.
    int B[right - left + 1];
    while(i1 <= middle && i2 <= right){
        if(A[i1] < A[i2]){
            //then we will put value at i1 into B,
            //then move the index forword.
            B[i++] = A[i1++];
        }
        else{
            //otherwise, we will put value at i2 into B,
            //then move the index forword.
            B[i++] = A[i2++];
        }
    }
    while(i1 <= middle){
        //if i1 still not reach the middle,
        //use looping to put value in B.
        B[i++] = A[i1++];
    }
    while(i2 <= right){
        //if i1 still not reach the last index,
        //use looping to put value in B.
        B[i++] = A[i2++];
    }
    //copy the value of B to A.
    for(int k = 0; k < (right-left+1); k++){
        A[left + k] = B[k];
    }
    return;
}

void RandArray(int *RandNum, int num){
    int i, m, temp;
    for(i = 0; i < num; i++){
        RandNum[i] = i;
    }
    //gengerate random number seed.
    srand((unsigned)time(NULL)); 
    for(i = num; i > 1; i--){
        m = rand()%i;
        temp = RandNum[i-1];
        RandNum[i-1] = RandNum[m];
        RandNum[m] = temp;
    }
    // srand((unsigned)time(NULL));
    // for(int i = 0; i < num; i++){
    //     RandNum[i] = rand();
    // }
    return;
}

