// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <unistd.h>
// #define RANDOM_RANGE 1000

// //functions declaration.
// void InsertionSort(int *A, int n);
// void MergeSort(int *A, int left, int right);
// void Merge(int *A, int left, int middle, int right);

// // for measure time
// #include <sys/time.h>
// static inline uint64_t time_get(void)
// {
//     struct timeval tv;

//     gettimeofday(&tv, 0);
//     return (uint64_t)(tv.tv_sec * 1000000000ULL + tv.tv_usec * 1000);
// }

// void generateRandom(int **arr, int size)
// {
//     if (*arr == NULL)
//         *arr = (int *)malloc(sizeof(int) * size);
//     int *ptr = *arr;
//     for (int i = 0; i < size; i++)
//     {
//         ptr[i] = rand() % RANDOM_RANGE;
//     }
// }

// void displayArr(int *arr, int size)
// {
//     if (arr != NULL)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//     }
// }


// int main(int argc, char const *argv[])
// {
//     // Don't change this
//     srand(1);

//     int size = 10;
//     int *A1 = NULL;
//     generateRandom(&A1, size);
//     displayArr(A1, size);
//     int *A2 = (int *)malloc(sizeof(int) * size);
//     memcpy(A2, A1, sizeof(int) * size);
//     displayArr(A2, size);

//     printf("Value of A1 that after InsertionSort:\n");
//     // TODO:
//     InsertionSort(A1, size);
//     displayArr(A1, size);

//     printf("Value of A2 that after MergeSort:\n");
//     // TODO:
//     MergeSort(A2, 0, size - 1);
//     displayArr(A2, size);

//     // prevent memory leak!
//     free(A1);
//     free(A2);
//     A1 = NULL;
//     A2 = NULL;

//     // for larger array
//     size = 100000;
//     generateRandom(&A1, size);
//     A2 = (int *)malloc(sizeof(int) * size);
//     memcpy(A2, A1, sizeof(int) * size);

//     // For InsertionSort
//     uint64_t begin = time_get();
//     // TODO:
//     InsertionSort(A1, size);
//     //sleep(1);
//     uint64_t end = time_get();
//     printf("InsertionSort Lasting: %12.3fms\n", (double)(end - begin) / 1000.0f / 1000.0f);

//     // For MergeSort
//     begin = time_get();
//     // TODO:
//     MergeSort(A2, 0, size - 1);
//     end = time_get();
//     printf("MergeSort Lasting: %12.3fms\n", (double)(end - begin) / 1000.0f / 1000.0f);
//     return 0;
// }

// void InsertionSort(int *A, int n){
//     //declare a key to store the current elements.
//     int key = 0;
//     //declare an index to store the insertion index.
//     int i = 0;
//     //do the for loop to insert elements.
//     for(int p = 1; p < n; p++){
//         key = A[p];
//         i = p - 1;
//         while(i >= 0 && A[i] > key){
//             //if the condition satisfied,
//             //we should move the A[i] afterwards one position.
//             A[i+1] = A[i];
//             i--;
//         }
//         //otherwise, put the element on the current position.
//         A[i+1] = key;
//     }
//     return;
// }

// void MergeSort(int *A, int left, int right){
//     if(left >= right){
//         //which means that we have reached the base case.
//         //just return without doing any operation.
//         return;
//     }
//     //otherwise, do the recursion to futher divide the array.
//     //use floor function to get the value of middle position.
//     int middle = floor((left+right) / 2);
//     //then do the recursion.
//     MergeSort(A, left, middle);
//     MergeSort(A, middle+1, right);
//     Merge(A, left, middle, right);
//     return;
// }

// void Merge(int *A, int left, int middle, int right){
//     //declare pointers.
//     //i1 to store the front of the array.
//     int i1 = left;
//     //i2 to store the middle of the array.
//     int i2 = middle+1;
//     //i as index of new array.
//     int i = 0;
//     //declare an array called B,
//     //to store the array which already sorted.
//     int B[right - left + 1];
//     while(i1 <= middle && i2 <= right){
//         if(A[i1] < A[i2]){
//             //then we will put value at i1 into B,
//             //then move the index forword.
//             B[i++] = A[i1++];
//         }
//         else{
//             //otherwise, we will put value at i2 into B,
//             //then move the index forword.
//             B[i++] = A[i2++];
//         }
//     }
//     while(i1 <= middle){
//         //if i1 still not reach the middle,
//         //use looping to put value in B.
//         B[i++] = A[i1++];
//     }
//     while(i2 <= right){
//         //if i1 still not reach the last index,
//         //use looping to put value in B.
//         B[i++] = A[i2++];
//     }
//     //copy the value of B to A.
//     for(int k = 0; k < (right-left+1); k++){
//         A[left + k] = B[k];
//     }
//     return;
// }
// /************************************************************************ sample output
// 807 249 73 658 930 272 544 878 923 709 
// 807 249 73 658 930 272 544 878 923 709 
// Value of A1 that after InsertionSort:
// 73 249 272 544 658 709 807 878 923 930 
// Value of A2 that after MergeSort:
// 73 249 272 544 658 709 807 878 923 930 
// InsertionSort Lasting:    13748.408ms
// MergeSort Lasting:       28.463ms
// ************************************************************************/

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <unistd.h>
// #define RANDOM_RANGE 1000

// //functions declaration.
// void InsertionSort(int *A, int n);
// void MergeSort(int *A, int left, int right);
// void Merge(int *A, int left, int middle, int right);

// // for measure time
// #include <sys/time.h>
// static inline uint64_t time_get(void)
// {
//     struct timeval tv;

//     gettimeofday(&tv, 0);
//     return (uint64_t)(tv.tv_sec * 1000000000ULL + tv.tv_usec * 1000);
// }

// void generateRandom(int **arr, int size)
// {
//     if (*arr == NULL)
//         *arr = (int *)malloc(sizeof(int) * size);
//     int *ptr = *arr;
//     for (int i = 0; i < size; i++)
//     {
//         ptr[i] = rand() % RANDOM_RANGE;
//     }
// }

// void displayArr(int *arr, int size)
// {
//     if (arr != NULL)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//     }
// }


// int main(int argc, char const *argv[])
// {
//     // Don't change this
//     srand(1);

//     int size = 10;
//     int *A1 = NULL;
//     generateRandom(&A1, size);
//     displayArr(A1, size);
//     int *A2 = (int *)malloc(sizeof(int) * size);
//     memcpy(A2, A1, sizeof(int) * size);
//     displayArr(A2, size);

//     printf("Value of A1 that after InsertionSort:\n");
//     // TODO:
//     InsertionSort(A1, size);
//     displayArr(A1, size);

//     printf("Value of A2 that after MergeSort:\n");
//     // TODO:
//     MergeSort(A2, 0, size - 1);
//     displayArr(A2, size);

//     // prevent memory leak!
//     free(A1);
//     free(A2);
//     A1 = NULL;
//     A2 = NULL;

//     // for larger array
//     size = 100000;
//     generateRandom(&A1, size);
//     A2 = (int *)malloc(sizeof(int) * size);
//     memcpy(A2, A1, sizeof(int) * size);

//     // For InsertionSort
//     uint64_t begin = time_get();
//     // TODO:
//     InsertionSort(A1, size);
//     //sleep(1);
//     uint64_t end = time_get();
//     printf("InsertionSort Lasting: %12.3fms\n", (double)(end - begin) / 1000.0f / 1000.0f);

//     // For MergeSort
//     begin = time_get();
//     // TODO:
//     MergeSort(A2, 0, size - 1);
//     end = time_get();
//     printf("MergeSort Lasting: %12.3fms\n", (double)(end - begin) / 1000.0f / 1000.0f);
//     return 0;
// }

// void InsertionSort(int *A, int n){
//     //declare a key to store the current elements.
//     int key = 0;
//     //declare an index to store the insertion index.
//     int i = 0;
//     //do the for loop to insert elements.
//     for(int p = 1; p < n; p++){
//         key = A[p];
//         i = p - 1;
//         while(i >= 0 && A[i] > key){
//             //if the condition satisfied,
//             //we should move the A[i] afterwards one position.
//             A[i+1] = A[i];
//             i--;
//         }
//         //otherwise, put the element on the current position.
//         A[i+1] = key;
//     }
//     return;
// }

// void MergeSort(int *A, int left, int right){
//     if(left >= right){
//         //which means that we have reached the base case.
//         //just return without doing any operation.
//         return;
//     }
//     //otherwise, do the recursion to futher divide the array.
//     //use floor function to get the value of middle position.
//     int middle = floor((left+right) / 2);
//     //then do the recursion.
//     MergeSort(A, left, middle);
//     MergeSort(A, middle+1, right);
//     Merge(A, left, middle, right);
//     return;
// }

// void Merge(int *A, int left, int middle, int right){
//     //declare pointers.
//     //i1 to store the front of the array.
//     int i1 = left;
//     //i2 to store the middle of the array.
//     int i2 = middle+1;
//     //i as index of new array.
//     int i = 0;
//     //declare an array called B,
//     //to store the array which already sorted.
//     int B[right - left + 1];
//     while(i1 <= middle && i2 <= right){
//         if(A[i1] < A[i2]){
//             //then we will put value at i1 into B,
//             //then move the index forword.
//             B[i++] = A[i1++];
//         }
//         else{
//             //otherwise, we will put value at i2 into B,
//             //then move the index forword.
//             B[i++] = A[i2++];
//         }
//     }
//     while(i1 <= middle){
//         //if i1 still not reach the middle,
//         //use looping to put value in B.
//         B[i++] = A[i1++];
//     }
//     while(i2 <= right){
//         //if i1 still not reach the last index,
//         //use looping to put value in B.
//         B[i++] = A[i2++];
//     }
//     //copy the value of B to A.
//     for(int k = 0; k < (right-left+1); k++){
//         A[left + k] = B[k];
//     }
//     return;
// }
// /************************************************************************ sample output
// 807 249 73 658 930 272 544 878 923 709 
// 807 249 73 658 930 272 544 878 923 709 
// Value of A1 that after InsertionSort:
// 73 249 272 544 658 709 807 878 923 930 
// Value of A2 that after MergeSort:
// 73 249 272 544 658 709 807 878 923 930 
// InsertionSort Lasting:    13748.408ms
// MergeSort Lasting:       28.463ms
// ************************************************************************/