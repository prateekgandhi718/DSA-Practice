#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char str[1000];
    scanf("%[^\n]s", str);
    for (int i = 0; i<strlen(str); i++) {
        if (str[i]>=65 && str[i]<= 90) {
            str[i] = str[i] + 32;
        }
    }
    printf("%s", str);
    
    // int countArr[26];
    // for (int i =0; i<26; i++) {
    //     countArr[i] = 0;
    // }
    
    
    return 0;
}