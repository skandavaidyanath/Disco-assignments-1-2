#include<stdio.h>
void print(int a[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(x==i) continue;
        if(a[i]==1) printf("%d ",i);
    }

}
void cities(int *a ,int check[],int i, int n)
{
    int j;
    if(check[i]==1) return;
    else
    {
        check[i]=1;
        for(j=0;j<n;j++)
        {
            if(*(a+i*n+j)==1)
            {
                cities(a,check,j,n);

            }
        }
    }
}
int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int a[n][n];
    int c=1;
    int i,j;
    int s;
    int g,h;
    for(g=0;g<n;g++)
    {
        for(h=0;h<n;h++)
            a[g][h]=0;
    }
    for(;c<=k;c++)
    {
        scanf("%d %d", &i ,&j);
        a[i][j]=1;
    }
    int check[n];
    printf("$$$$$$$$$$$$$$$$$\n");
    for(s=0;s<n;s++)
    {
        int l=0;
        for(;l<n;l++)
            check[l]=0;
        cities((int *)a,check,s,n);
        print(check,n,s);
        printf("\n");
    }
    return 0;
}

