#include<stdio.h>
int main()
{
    int p,q;
    scanf("%d %d", &p, &q);
    int a[100][100];
    int x,y;
    for(x=0;x<100;x++)
        for(y=0;y<100;y++)
            a[x][y]=0;
    int n;
    a[0][0]=1;
    int c=2;
    int i,j;
    for(n=1;n<100;n++)
    {
        int k;
        for(k=1;k<=n+1;k++)
        {
            if(n%2==0)
            {
                if(k==1)
                {
                    i=0;
                    j=n;
                }
                if((i==0)||(j==0))
                {
                    a[i][j]=c;
                    c++;
                }
                if(i<99) i++;
                if(j>0) j--;
            }
            else
            {
                if(k==1)
                {
                    i=n;
                    j=0;
                }
                a[i][j]=c;
                c++;
                if(i>0) i--;
                if(j<99) j++;
            }
        }
    }
    /*for(x=0;x<100;x++)
    {
        for(y=0;y<100;y++)
            printf("%d ", a[x][y]);
        printf("\n");
    }*/
    printf("%d", a[q-1][p-1]);
    return 0;

}
