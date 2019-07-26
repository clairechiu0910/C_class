#include <stdio.h>
#include <string.h>

int main()
{
    freopen("in.txt", "r", stdin);
    char c;
    while(scanf("%c", &c) != EOF)
    {
        if(c <= '8' && c >= '0'){
            printf("%c", c+1);
            continue;
        }
        if(c == '9')
        {
            printf("0");
            continue;
        }
        if(c <= 'z' && c >= 'a')
        {
            c = toupper(c);
            printf("%c", 'Z' - (c - 'A'));
            continue;
        }
        if(c <= 'Z' && c >= 'A')
        {
            c = tolower(c);
            printf("%c", 'z' - (c - 'a'));
            continue;
        }
        printf("%c", c);
    }
    return 0;
}
