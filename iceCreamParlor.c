#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        int k;
        int n;
        scanf("%d", &k);
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        bool flag = false;

        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (arr[i] + arr[j] == k)
                {
                    flag = true;
                    printf("%d", i+1);
                    printf(" ");
                    printf("%d", j+1);
                    break;
                }
            }

            if (flag == true)
            {
                break;
            }
            else{
                continue;
            }
        }
        
        
    }
    
    return 0;
}
