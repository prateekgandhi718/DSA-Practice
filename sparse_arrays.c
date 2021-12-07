#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char ch_arr[1000][20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch_arr + i);
    }
    //stored all the strings

    //now let's store all the queries
    int m;
    scanf("%d", &m);
    char ch_qarr[1000][20];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", ch_qarr + i);
    }
    //stored all the queries as well.

    //now we have to check if the number of times a query exists in the ch_arr and print the count

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(*(ch_qarr+i), *(ch_arr+j)) == 0)
            {
                count++;
            }
            else{
                continue;
            }
            
        }
        
        printf("%d", count);
    }
     
    

    // for (int i = 0; i < 3; i++)
    // {

    //     printf("%s", ch_arr + i);
    // }


    return 0;
}
