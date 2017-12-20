#include<stdio.h>
void print(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void sortFirst(int a[], int b[], int n)
{
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
    }
}
void sortSecond(int *a, int b[], int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(*(a+b[i]*n+b[i+1])==*(a+b[i+1]*n+b[i]))
        {
            if(b[i]>b[i+1])
            {
                int t= b[i];
                b[i]=b[i+1];
                b[i+1]=t;
            }
        }
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
int length(int a[], int n)
{
    int i;
    int c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=0) c++;
    }
    return c;
}
int main()
{
    int n;
    scanf("%d ", &n);
    int a[n][n];
    int k;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=0;
    }
    scanf("%d", &k);
    for(i=0;i<k;i++)
    {
        int x,y;
        scanf("%d %d",&x, &y);
        a[x][y]=1;
    }
    transitive((int *)a, n);
    int answer[n];
    int lengths[n];
    for(i=0;i<n;i++)
    {
        lengths[i]=length(a[i],n);
        answer[i]=i;
    }
    print(lengths,n);
    sortFirst(lengths, answer, n);
    sortSecond((int *)a, answer, n);
    print(answer,n);
    return 0;
}
