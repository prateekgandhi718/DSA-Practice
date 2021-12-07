/*
Two for loops!

O(n^2)
Stable
Not recursive
Not adaptable by default

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

void bubbleSort (int * arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) //for passes
    {
        for (int j = 0; j < size - 1 - i; j++) //for pair wise comparison
        {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive (int * arr, int size) {
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size - 1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < size -1 -i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted) {
            return;
        }
    }
    
}


int main()
{
    int A[] = {1,2,53,12,3,45,63,14};
    int n = 8;

    printArray(A, n);
    bubbleSortAdaptive(A, n);
    printArray(A, n);
    return 0;
}
