#include <stdio.h>

int main()
{
    int ncase, nextline = 0;
    while(1)
    {
        scanf("%d", &ncase);
        if(ncase == 0)
            break;
        if(nextline++ != 0)
            printf("\n");
        int element, choice = 0, no = 0, tmpch, tmpno, i;
        for(i = 0; i < ncase; i++)
        {
            scanf("%d", &element);
            tmpch = no + element;
            tmpno = (choice > no)? choice : no;
            no = tmpno;
            choice = tmpch;
        }
        printf("%d", (choice > no)? choice : no);
    }
}
