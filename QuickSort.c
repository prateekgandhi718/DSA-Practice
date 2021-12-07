/*
Pivot!

O(n^2);
Not stable
No extra space required.



*/

#include <stdio.h>

void printArray (int * arr, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}

int partition (int * arr, int low, int high) {
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i<j) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);
    //finally swap arr[low] with arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}


void quickSort(int * arr, int low, int high) {
    int partitionIndex;
    if (low < high) {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex);
        quickSort(arr, partitionIndex+1, high);
    }
}

int main()
{
    int A[] = {2,42,31,41,23,512,4};
    int n = 7;

    printArray(A, n);

    quickSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}
