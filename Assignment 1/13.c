#include<stdio.h>
void cities(int *a , int check[],int i, int n)
{
    int j, flag=0;
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
void transitive(int *a, int n)
{
    int i;
    int check[n];
    for(i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
            check[j]=0;
        cities(a,check,i,n);
        for(j=0;j<n;j++)
            *(a+i*n+j) = check[j];
    }
}
int reflexive(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
            if(*(a+i*n+i)==0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d ",&n);
    int i,j;
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=0;
    }
    int x,y;
    int k;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y]=1;
    }
    transitive((int *)a,n);
    x = reflexive((int *)a, n);
    if(x==1) printf("Reflexive\n");
        else printf("Not Reflexive\n");
    return 0;
}
