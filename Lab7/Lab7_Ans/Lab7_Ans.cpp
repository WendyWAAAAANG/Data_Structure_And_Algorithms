#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE 1000

void generateRandom(int **arr, int size)
{
    if (*arr == NULL)
        *arr = (int *)malloc(sizeof(int) * size);
    int *ptr = *arr;
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % RANDOM_RANGE;
    }
}

void displayArr(int *arr, int size)
{
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

//////////////////////////////// TODO QuickSort
void QuickSort(int *A, int left, int right)
{
    // TODO:
}

/***************************
 * Implement QuickSort
 * *************************/
int main(int argc, char const *argv[])
{
    // Don't change this
    // srand(time(NULL));
    srand(1);

    int size = 20;
    int *A1 = NULL;
    generateRandom(&A1, size);
    printf("Value of A1 before QuickSort:\n");
    displayArr(A1, size);

    // TODO:
    QuickSort(A1, 0, size - 1);
    printf("Value of A1 after QuickSort:\n");
    displayArr(A1, size);

    free(A1);
    A1 = NULL;

    size = 10000;
    generateRandom(&A1, size);
    printf("Value of A1 before QuickSort:\n");
    displayArr(A1, 20);

    // TODO:
    QuickSort(A1, 0, size - 1);
    printf("Value of A1 after QuickSort:\n");
    displayArr(A1, 20);

    return 0;
}

/*************************************** sample output
Value of A1 before QuickSort:
807 249 73 658 930 272 544 878 923 709 440 165 492 42 987 503 327 729 840 612 
Value of A1 after QuickSort:
42 73 165 249 272 327 440 492 503 544 612 658 709 729 807 840 878 923 930 987 
Value of A1 before QuickSort:
303 169 709 157 560 933 99 278 816 335 97 826 512 267 810 633 979 149 579 821 
Value of A1 after QuickSort:
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
***************************************/