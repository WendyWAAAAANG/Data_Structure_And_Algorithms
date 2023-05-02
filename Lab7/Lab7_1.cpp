// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>

// #define SIZE 100000
// #define RANDOM_RANGE 1000

// void generateRandom(int **arr, int size){
//     if (*arr == NULL)
//         *arr = (int *)malloc(sizeof(int) * size);
//     int *ptr = *arr;
//     for (int i = 0; i < size; i++){
//         ptr[i] = rand() % RANDOM_RANGE;
//     }
// }

// void displayArr(int *arr, int size){
//     if (arr != NULL){
//         for (int i = 0; i < size; i++){
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//     }
// }

// // See slide 7, chapter 6 (modified to use left and right instead of n)
// void InsertionSort(int *A, int left, int right) {
//   for(int p = left + 1; p <= right; p++) {
//     int key = A[p];
//     int i = p - 1;
//     while(i >= 0 && A[i] > key) {
//       A[i + 1] = A[i];
//       i--;
//     }
//     A[i + 1] = key;
//   }
// }

// ////////////////////////////////////////////////////////////

// // Swap the array elements at indexes i and j.
// void swap(int *A, int i, int j) {
//   int temp = A[i];
//   A[i] = A[j];
//   A[j] = temp;
// }

// // See slide 24, chapter 7
// void Median3(int *A, int left, int right) {
//   int center = (left + right) / 2;

//   // Make sure that A[left] is smaller than both A[center] and A[right]:
//   if(A[left] > A[center]) {
//     swap(A, left, center);
//   }
//   if(A[left] > A[right]) {
//     swap(A, left, right);
//   }
//   // Now make sure that A[center] is smaller than A[right]:
//   if(A[center] > A[right]) {
//     swap(A, center, right);
//   }
//   // Put the pivot at second last position:
//   swap(A, center, right - 1);
// }

// // See slide 26, chapter 7
// int Partition(int *A, int left, int right) {
//   Median3(A, left, right);
  
//   int i = left + 1;
//   int j = right - 2;
//   int pivot = A[right - 1];

//   while(true) {
//     while(A[i] < pivot) {
//       i++;
//     }
//     while(A[j] > pivot) {
//       j--;
//     }
//     if(i < j) {
//       swap(A, i, j);
//       i++;
//       j--;
//     } else {
//       break; // end of while loop
//     }
//   }
//   swap(A, i, right - 1);
//   return i; // index of pivot after last swap
// }

// // See slide 19, chapter 7
// void QuickSort(int *A, int left, int right) {
//   if(right - left <= 10) {
//     InsertionSort(A, left, right);
//     return;
//   }

//   int q = Partition(A, left, right);
//   QuickSort(A, left, q - 1);
//   QuickSort(A, q + 1, right);
// }

// ////////////////////////////////////////////////////////////

// // int main(void) {
// //   int A1[SIZE], A2[SIZE];

// //   // Initialize pseudo-random number genrator:
// //   srand(time(NULL));
// //   // And fill in the arrays:
// //   for(int i = 0; i < SIZE; i++) {
// //     A2[i] = A1[i] = rand();
// //   }

// //   // This was not asked:
// //   clock_t start = clock();
// //   InsertionSort(A1, 0, SIZE - 1);
// //   clock_t end = clock();
// //   printf("Insertion Sort: %f ms\n", 1000.0 * (double)(end - start) / CLOCKS_PER_SEC);

// //   start = clock();
// //   QuickSort(A2, 0, SIZE - 1);
// //   end = clock();
// //   printf("Quick Sort: %f ms\n", 1000.0 * (double)(end - start) / CLOCKS_PER_SEC);

// //   return 0;
// // }


// /***************************
//  * Implement QuickSort
//  * *************************/
// int main(int argc, char const *argv[]){
    
//     // Don't change this
//     srand(1);

//     int size = 10;
//     int *A1 = NULL;
//     generateRandom(&A1, size);
//     printf("Value of A1 before QuickSort:\n");
//     displayArr(A1, size);

//     // TODO:
//     QuickSort(A1, 0, size - 1);
//     printf("Value of A1 after QuickSort:\n");
//     displayArr(A1, size);
//     return 0;
// }
// /*************************************** sample output
// Value of A1 before QuickSort:
// 807 249 73 658 930 272 544 878 923 709 
// Value of A1 after QuickSort:
// 73 249 272 544 658 709 807 878 923 930
// ***************************************/
