#include<stdio.h>
int symmetric(int *a, int n)
{
    int i,j;
    int flag=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((*(a+i*n+j)==1)&&(*(a+j*n+i)==1))
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
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
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    int k;
    scanf("%d",&k);
    int i;
    int x,y;
    for(i=0;i<k;i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y]=1;
    }
    transitive((int *)a,n);                        //make the reflection transitive
    int check = symmetric((int *)a,n);       //if it is symmetric at any point then it is wrong
    if(check==1) printf("Possible\n");
    else printf("Not Possible\n");
    return 0;
}
