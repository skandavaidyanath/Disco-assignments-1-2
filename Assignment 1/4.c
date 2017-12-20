#include<stdio.h>
int flag=0;
int position(int a[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x) break;
    }
    return i;
}
int check(int a[], int n, int array1[], int array2[], int index)
{
    int i;
    for(i=0;i<index;i++)
    {
        int flag1 = position(a,n,array1[i]);
        int flag2 = position(a,n,array2[i]);
        if(flag1>flag2) return 0;
    }
    return 1;
}
// Generating permutation using Heap Algorithm
void Permutation(int a[], int size, int n, int x[], int y[], int k)
{
    // if size becomes 1 then checks the obtained
    // permutation if it is satisfiable
    int i;
    if (size == 1)
    {
        flag += check(a,n,x,y,k);
        return;
    }

    for (i=0; i<size; i++)
    {
        Permutation(a,size-1,n,x,y,k);

        // if size is odd, swap first and last
        // element
        if (size%2==1)
        {
            int t= a[0];
            a[0] = a[size-1];
            a[size-1] = t;
        }

        // If size is even, swap ith and last
        // element
        else
        {
            int t = a[i];
            a[i] = a[size-1];
            a[size-1] = t;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=i;
    }
    int k;
    scanf("%d", &k);
    int x[k];
    int y[k];
    for(i=0;i<k;i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    Permutation(a,n,n,x,y,k);
    printf("%d ",flag);
    return 0;
}
