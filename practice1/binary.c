#include <stdio.h>
#include <string.h>
int main()
{
    int ncase,line=0,i,j;
    while(1)
    {
        scanf("%d",&ncase);
        if(ncase==0)
            break;
        char str[50];
        long long int mul=1,sum=0;
        for(i=0;i<ncase;i++,mul=1)  //每輸入一個就要計算一次
        {
            scanf("%s",str);
            for(j=strlen(str)-1;j>=0;j--,mul*=2)
                sum+=(str[j]-'0')*mul;
        }
        if(line++!=0)
            printf("\n");
        printf("%lld",sum);
    }
    return 0;
}
