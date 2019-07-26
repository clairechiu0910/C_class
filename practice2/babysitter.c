#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int start;
    int end;
}time;

int main()
{
    int tcase;
    scanf("%d\n", &tcase);
    while(tcase--)
    {
        char string[50];
        char *ptr;
        int count = 0, buffer, end = -1, tmp = -1, ans = 0, i;
        time range[300];
        while(fgets(string, 50, stdin) != NULL)
        {
            if(string[0] == '\n')
                break;
            range[count].start = atoi(string);
            ptr = strchr(string, ' ');
            range[count].end = atoi(++ptr);
            if(range[count].start > range[count].end)
            {
                buffer = range[count].start;
                range[count].start = range[count].end;
                range[count].end = buffer;
            }
            count++;
        }
        while(end != 199)
        {
            for(i = 0; i < count; i++)
            {
                if(range[i].start <= end +1 && range[i].end > tmp)
                    tmp = range[i].end;
            }
            end = tmp;
            ans++;
        }
        printf("%d", ans);
        if(tcase)
            printf("\n");
    }
    return 0;
}
