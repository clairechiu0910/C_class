#include <stdio.h>

typedef struct
{
    int width;
    int height;
}dimention;

int cmp(const void *a, const void *b)
{
    if(((dimention*)b)->width != ((dimention*)a)->width)
        return (((dimention*)b)->width - ((dimention*)a)->width);  //big to small
    else
        return (((dimention*)b)->height - ((dimention*)a)->height);

}

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int ntype, now, height = 0, i;
        scanf("%d", &ntype);
        dimention tile[ntype * 2];
        for(i = 0; i < ntype*2; i+=2)
        {
            scanf("%d%d", &tile[i].height, &tile[i].width);
            tile[i+1].height = tile[i].width;
            tile[i+1].width = tile[i].height;
        }
        qsort(tile, ntype*2, sizeof(dimention), cmp);
        now = tile[0].width;
        height += tile[0].height;
        for(i = 1; i < ntype*2; i++)
        {
            if(tile[i].width < now)
            {
                now = tile [i].width;
                height += tile[i].height;
            }
        }
        printf("%d", height);
        if(tcase)
            printf("\n");
    }
    return 0;
}

