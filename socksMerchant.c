#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int countArr[100];
    for (int i = 0; i<100; i++) {
        countArr[i] = 0;
    }
    
    for (int i = 0; i<n; i++) {
        countArr[arr[i]] = countArr[arr[i]] + 1;
    }
    
    for (int i = 0; i < 100; i++) {
        printf("%d", countArr[i]);
        printf(" ");
    }
    // int pairs = 0;
    // for (int i = 0; i<100; i++) {
    //     if (countArr[i] > 0) {
    //         pairs = pairs + (countArr[i]/2);
    //     }
    //     else{
    //         continue;
    //     }
    // }
    
    // printf("%d", pairs);
    return 0;
}