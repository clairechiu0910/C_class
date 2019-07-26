#include <stdio.h>
#include <string.h>

int main()
{
    int nextline = 0;
    char s[1500];
    while(fgets(s, 1500, stdin) != NULL)
    {
        if(nextline++ != 0)
            printf("\n");

        int time = 0, first, last, len = strlen(s) - 1, i, j, k;
        for(i = 0; i < len; i++)
        {
            if(s[i] <= '9' && s[i] >= '0')
            {
                time = time * 10 + s[i] - '0';
            }
            else
            {
                if(s[i - 1] <= '9' && s[i - 1] >= '0')
                {
                    first = i;
                }
                if((s[i + 1] <= '9' && s[i + 1] >= '0') || s[i + 1] == '\n')
                {
                    last = i;
                    for(j = 0; j < time; j++)
                        for(k = first; k <= last; k++)
                            printf("%c", s[k]);
                    time = 0;
                }
            }
        }
    }
}
