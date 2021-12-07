/*
O(n^2)

Not stable.

Not recursive

Not adaptive by default

But we don't make any redundant swaps here.


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

void selectionSort (int * arr, int size) {
    int indexOfMin, temp;
    for (int i = 0; i < size-1; i++)
    {
        indexOfMin = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[indexOfMin]) {
                indexOfMin = j;
            }
        }
        //swap arr[i] with arr[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
    
}

int main()
{   
    int A[] = {12,34,25,4,3,2,3,4,124,12,41,24};
    int n = 12;

    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
    
    return 0;
}
