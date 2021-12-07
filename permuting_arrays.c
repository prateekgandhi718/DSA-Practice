#include <stdio.h>
#include <stdbool.h>

int main()
{
    int q;
    int n;
    int k;
    scanf("%d", &q);
    scanf("%d", &n);
    scanf("%d", &k);

    while (q--)
    {
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr1[i]);
        }

        int arr2[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr2[i]);
        }
        bool flag;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr1[i] + arr2[j] >= k)
                {
                    flag = true;
                    arr2[j] = 0;
                    break;
                }
                else
                {
                    flag = false;
                    continue;
                }
            }
            // printf("%d", flag);
        }
        if (flag == true)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }

    return 0;
}
