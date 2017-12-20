#include<stdio.h>
int reflexive(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
            if(*(a+i*n+i)==0) return 0;
    }
    return 1;
}
int antiSymmetric(int *a, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((*(a+i*n+j)==1)&&(*(a+j*n+i)==1)) return 0;
        }
    }
    return 1;
}
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
int transitive(int *a, int n)
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
            if(check[j]!= *(a+i*n+j)) return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    int k;
    scanf("%d",&k);
    int i;
    int x,y;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
            a[x][y]=0;
    }
    for(i=0;i<k;i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y]=1;
    }
    int refCheck = reflexive((int *)a, n);
    int antiSymmCheck = antiSymmetric((int *)a, n);
    int transCheck = transitive((int *)a, n);
    //printf("%d %d %d",refCheck,antiSymmCheck,transCheck);
    if((refCheck==1)&&(antiSymmCheck==1)&&(transCheck==1)) printf("YES\n");
        else printf("NO\n");
    return 0;
}

