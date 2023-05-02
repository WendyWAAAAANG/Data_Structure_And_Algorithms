// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

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

// void Median3(int *A, int left, int right){
//     //store three value of array.
//     //should be: l < c < r.
//     int l_val = A[left];
//     int r_val = A[right];
//     int c_val = A[(left + right) / 2];
//     //then compare value of these three num.
//     if(l_val < c_val){
//         if(c_val < r_val){
//             //l < c < r,
//             //all element in correct position.
//             //do nothing.
//         }
//         else{
//             //l < c; r < c,
//             if(l_val < r_val){
//                 //l < r < c,
//                 //which means we need swap c_val and r_val.
//                 int temp = A[(left + right) / 2];
//                 A[(left + right) / 2] = A[right];
//                 A[right] = temp;
//             }
//             else{
//                 //r < l < c,
//                 //swap two of them.
//                 int t1 = A[(left + right) / 2];
//                 A[(left + right) / 2] = A[left];
//                 A[left] = t1;

//                 //r < c < l,
//                 //swap two of them.
//                 int t2 = A[right];
//                 A[right] = A[left];
//                 A[left] = t2;
//             }
//         }
//     }
//     if(l_val > c_val){
//         if(l_val > r_val){
//             //c < r < l,
//             //swap two of them.
//             int t1 = A[(left + right) / 2];
//             A[(left + right) / 2] = A[right];
//             A[right] = t1;

//             //r < c < l,
//             //swap two of them.
//             int t2 = A[right];
//             A[right] = A[left];
//             A[left] = t2;
//         }
//         else{
//             //c < l < r,
//             int t1 = A[(left + right) / 2];
//             A[(left + right) / 2] = A[left];
//             A[left] = t1;
//         }
//     }
//     //after 3 num sorted,
//     //swap pivot(c_val) with last second element.
//     int temp = A[(left + right) / 2];
//     A[(left + right) / 2] = A[right - 1];
//     A[right - 1] = temp;
//     return;
// }

// int Partition(int *A, int left, int right){
//     Median3(A, left, right);
//     //Median3 repositions the left, center and the right elements.
//     //set two pointers from left and right of the array.
//     int i = left + 1;
//     int j = right - 2;
//     //set the pivot which put by Median3.
//     int pivot = A[right - 1];
//     //then do the interration to move the elements.
//     while(1){
//         while(A[i] < pivot){
//             //which means it is on the correct position,
//             //just increase i to check next one.
//             i++;
//         }
//         while(A[j] > pivot){
//             //which means it is on the correct position,
//             //just decrease j to check next one.
//             j--;
//         }
//         if(i >= j){
//             //which means two pointers got acrossed.
//             //so that all elements has been partited.
//             break;
//         }
//         else{
//             //which means we should swap element to correct pos.
//             int t1 = A[i];
//             A[i] = A[j];
//             A[j] = t1;
//             //change the pointer.
//             i++;
//             j--;
//         }
//     }
//     //after do the partition of all elements,
//     //swap and put pivot in correct pos.
//     int t2 = A[right - 1];
//     A[right - 1] = A[i];
//     A[i] = t2;
//     //then return the position of pivot.
//     return i;
// }

// // // See slide 19, chapter 7
// // void QuickSort(int *A, int left, int right) {
// //   if(right - left <= 10) {
// //     InsertionSort(A, left, right);
// //     return;
// //   }

// //   int q = Partition(A, left, right);
// //   QuickSort(A, left, q - 1);
// //   QuickSort(A, q + 1, right);
// // }

// void QuickSort(int *A, int left, int right){
//     // TODO:
//     if(right - left <= 10){
//         //which means we will use insertion sort.
//         InsertionSort(A, (right+1));
//         return;
//     }
//     //to partition the array to do further sort.
//     //use q to represent the position of the pivot.
//     int q = Partition(A, left, right);
//     //doing the resurison.
//     //sort left subarray.
//     QuickSort(A, left, q-1);
//     //sort right subarray.
//     QuickSort(A, q+1, right);
//     return;
// }


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