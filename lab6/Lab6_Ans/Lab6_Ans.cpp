#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define RANDOM_RANGE 1000

#if defined(_WIN32)
#include <chrono>

static inline unsigned long time_get()
{
    namespace sc = std::chrono;
    sc::system_clock::duration d = sc::system_clock::now().time_since_epoch();
    sc::seconds s = sc::duration_cast<sc::seconds>(d);
    unsigned long tv_sec = s.count();
    unsigned long tv_usec = sc::duration_cast<sc::microseconds>(d - s).count();
    return tv_sec * 1000000000ULL + tv_usec * 1000;
}

#else
// for measure time
#include <sys/time.h>
static inline unsigned long time_get(void)
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return (tv.tv_sec * 1000000000ULL + tv.tv_usec * 1000);
}
#endif

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

void InsertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int left, int middle, int right)
{
    int i1 = left, i2 = middle + 1, i = 0;
    int B[right - left + 1];
    while (i1 <= middle && i2 <= right)
    {
        B[i++] = arr[i1] < arr[i2] ? arr[i1++] : arr[i2++];
    }
    // copy remain
    if (i1 <= middle)
    {
        int gap = middle - i1 + 1;
        memcpy(B + i, arr + i1, sizeof(int) * gap);
        i += gap;
    }
    if (i2 <= right)
    {
        int gap = right - i2 + 1;
        memcpy(B + i, arr + i2, sizeof(int) * gap);
    }

    // while (i1 <= middle)
    // {
    //     B[i++] = arr[i1++];
    // }
    // while (i2 <= right)
    // {
    //     B[i++] = arr[i2++];
    // }
    // copy the value of B to A. Faster way
    memcpy(arr + left, B, sizeof(int) * (right - left + 1));

    // for (int k = 0; k < (right - left + 1); k++)
    // {
    //     arr[left + k] = B[k];
    // }
}

void MergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(int argc, char const *argv[])
{
    // Don't change this
    srand(1);

    int size = 10;
    int *A1 = NULL;
    generateRandom(&A1, size);
    displayArr(A1, size);
    int *A2 = (int *)malloc(sizeof(int) * size);
    memcpy(A2, A1, sizeof(int) * size);
    displayArr(A2, size);

    printf("Value of A1 that after InsertionSort:\n");
    // TODO:
    InsertionSort(A1, size);
    displayArr(A1, size);

    printf("Value of A2 that after MergeSort:\n");
    // TODO:
    MergeSort(A2, 0, size - 1);
    displayArr(A2, size);

    // prevent memory leak!
    free(A1);
    free(A2);
    A1 = NULL;
    A2 = NULL;

    // for larger array
    size = 100000;
    generateRandom(&A1, size);
    A2 = (int *)malloc(sizeof(int) * size);
    memcpy(A2, A1, sizeof(int) * size);

    // For InsertionSort
    uint64_t begin = time_get();
    // TODO:
    InsertionSort(A1, size);
    uint64_t end = time_get();
    printf("InsertionSort Lasting: %12.3fms\n", (double)(end - begin) / 1000.0f / 1000.0f);

    // For MergeSort
    begin = time_get();
    // TODO:
    MergeSort(A2, 0, size - 1);
    end = time_get();
    printf("MergeSort Lasting: %12.3fms\n", (double)(end - begin) / 1000.0f / 1000.0f);

    free(A1);
    free(A2);
    A1 = NULL;
    A2 = NULL;
    return 0;
}

/************************************************************************ sample output
807 249 73 658 930 272 544 878 923 709 
807 249 73 658 930 272 544 878 923 709 
Value of A1 that after InsertionSort:
73 249 272 544 658 709 807 878 923 930 
Value of A2 that after MergeSort:
73 249 272 544 658 709 807 878 923 930 
InsertionSort Lasting:    13748.408ms
MergeSort Lasting:       28.463ms
************************************************************************/