#include <stdio.h>
#include <string.h>
#include <math.h>
int change(char in[10000], int out[1005])
{
    int i,len,temp=0,num=0;
    len=strlen(in);
    for(i=0;i<len-1;i++)
    {
        if(in[i]>='0'&&in[i]<='9')
        {
            temp=temp*10+in[i]-'0';
            if(in[i+1]<'0'||in[i+1]>'9')
            {
                out[num++]=temp;
                temp=0;
            }
        }
    }
    return num;
}
int cmpx(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
int cmpy(const void *a, const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int ncase;
    scanf("%d\n",&ncase);
    while(ncase--)
    {
        char xin[10000],yin[10000];
        int xcor[1005]={0},ycor[1005]={0};
        int num,i;
        double sum=0;  //double
        fgets(xin,10000,stdin);
        fgets(yin,10000,stdin);
        num=change(xin,xcor);
        num=change(yin,ycor);
        qsort(xcor,num,sizeof(xcor[0]),cmpx);
        qsort(ycor,num,sizeof(ycor[0]),cmpy);
        for(i=0;i<num;i++)
            sum+=sqrt(xcor[i]*xcor[i]+ycor[i]*ycor[i]);
        printf("%d", (int)sum);
        if(ncase)
            printf("\n");
    }
    return 0;
}
