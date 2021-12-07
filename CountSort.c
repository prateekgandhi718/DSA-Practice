#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray (int * arr, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
    printf("\n");
}

int maximum (int * arr, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort (int * arr, int size) {
    int max = maximum(arr, size);
    int * countArray = (int *)malloc((max+1) * sizeof(int));
    for (int i = 0; i < max+1; i++)
    {
        countArray[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        countArray[arr[i]] = countArray[arr[i]] + 1;
    }

    //time to put back the numbers in the arr array.
    int i = 0; //for countarray
    int j = 0; //for arr
    while (i <= max) {
        if (countArray[i] > 0) {
            arr[j] = i;
            countArray[i] = countArray[i] - 1;
            j++;
        }
        else {
            i++;
        }
    }
}

int main()
{
    int A[] = {1,152,3,23,2,3,12,31,23,12};
    int n = 10;
    printArray(A,n);
    countSort(A,n);
    printArray(A,n);
    return 0;
}
