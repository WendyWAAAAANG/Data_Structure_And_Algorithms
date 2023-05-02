#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
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

void swap(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


/////////////////////////////////////////////////////////// heapify version
void heapify_no_recur(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    while (l < n || r < n)
    {
        // if (l > n && r > n)
        //     return;
        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }

        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(arr, i, largest);
            i = largest;
            l = 2 * largest + 1;
            r = 2 * largest + 2;
        }
        else
            return;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr, i, largest);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


void HeapSort(int *A, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_no_recur(A, n, i);
        // heapify(A, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(A, 0, i);

        // call max heapify on the reduced heap
        heapify_no_recur(A, i, 0);
        // heapify(A, i, 0);
    }
}
/////////////////////////////////////////////////////////////////////////////////
void Insert(int *A, int i, int val)
{
    int hole = i ++;
    while (hole > 0 && val > A[(hole - 1)/2])
    {
        A[hole] = A[(hole - 1)/2];
        hole = (hole - 1) / 2;
    }
    A[hole] = val;
}

void Delete(int *A, int n)
{
    swap(A, 0, n);
    int val = A[0];
    int hole  = 0;
    int l = hole * 2 + 1;
    int r = hole * 2 + 2;
    int largest = hole;
    while (l < n || r < n)
    {
        // If left child is larger than root
        if (l < n && A[l] > A[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && A[r] > A[largest])
            largest = r;

        if (hole != largest)
        {
            swap(A, hole, largest);
            
            hole = largest;
            l = 2 * largest + 1;
            r = 2 * largest + 2;
        }
        else
        {
            break;
        }
    }
}


void _HeapSort(int *A, int size)
{
    printf("_heapsort\n");
    for (int i = 0; i < size; i ++)
        Insert(A, i, A[i]);

    for (int i = size - 1; i > 0; i--)
    {
        Delete(A, i); 
    }
}

/***************************
 * Implement QuickSort
 * *************************/
int main(int argc, char const *argv[])
{
    // Don't change this
    // srand(time(NULL));
    srand(1);

    clock_t t;
    double cpu_time_used;

    int size = 20;
    int *A1 = NULL;
    generateRandom(&A1, size);
    printf("Value of A1 before HeapSort:\n");
    displayArr(A1, size);

    // TODO:
    _HeapSort(A1, size);
    printf("Value of A1 after HeapSort:\n");
    displayArr(A1, size);

    free(A1);
    A1 = NULL;

    size = 10000;
    generateRandom(&A1, size);
    printf("Value of A1 before HeapSort:\n");
    displayArr(A1, 20);

    t = clock();
    // TODO:
    _HeapSort(A1, size);
    // getchar();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Value of A1 after HeapSort:[%f]\n", time_taken);

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
Value of A1 after HeapSort: [0.000030]
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
***************************************/
