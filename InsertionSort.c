/*
O(n^2)
Stable
Adaptive!


Remember by we insert a key therefore we use key here.
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

void insertionSort (int * arr, int size) {
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j] > key) {
            //we be slidin'
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int A[] = {1,4,23,5,43,23,4};
    int n = 7;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
    return 0;
}
