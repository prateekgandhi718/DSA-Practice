/*
BEST TIME COMPLEXITY OF O(n logn);


*/

#include <stdio.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}

void merge (int * arr, int low, int mid, int high) {
    int i, j, k, arr1[100];
    i = low;
    j = mid+1;
    k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            arr1[k] = arr[i];
            i++;
            k++;
        }
        else {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid) {
        arr1[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        arr1[k] = arr[j];
        j++;
        k++;
    }

    //put arr1 elements back in arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr1[i];
    }

}

void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int A[] = {2, 4, 2, 5, 7, 2, 34, 5, 1};
    int n = 9;

    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printArray(A, n);
    return 0;
}
