#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[10];
    int ncase;
    fgets(s,10,stdin);
    ncase=atoi(s);
    while(ncase--)
    {
        char c;
        int test[26]={0},max=1,i;
        while(scanf("%c",&c)!=EOF)
        {
            if(c=='\n')
                break;
            c=toupper(c);
            if(c>='A'&&c<='Z')
                test[c-'A']++;
        }
        for(i=0;i<26;i++)
            if(test[i]>max)
                max=test[i];
        for(i=0;i<26;i++)
            if(test[i]==max)
                printf("%c",i+'A');
        if(ncase)
            printf("\n");
    }
    return 0;
}
