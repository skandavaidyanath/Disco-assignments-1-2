#include<stdio.h>
int search(int a[], int x,  int n)
{
    int i, flag=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==x) flag=1;
    }
    return flag;
}
int pos(int a[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==x) return i;
}
void insertAfter(int a[], int n, int x, int data)
{
    int i;
    for(i=n-2;i>x ;i--)
    {
        if(a[i]>data) a[i+1]=a[i];
        else break;
    }
    a[i+1]= data;
}
void insertBefore(int a[], int n, int x, int data)
{
    int i;
    for(i=n-1;i>x;i--)
    {
        a[i]=a[i-1];
    }
    i--;
    for(;i>=0;i--)
    {
        if(a[i]>data) a[i+1]=a[i];
        else break;
    }
    a[i+1]=data;
}
void insertRightAfter(int a[], int n, int x, int data)
{
    int k=n-1;
    int y = pos(a,n,x);
    for(;k>y;k--)
    {
        a[k]=a[k-1];
    }
    a[k+1]=data;

}
void insertRightBefore(int a[], int n, int x, int data)
{
    int k=n-1;;
    int y=pos(a,n,x);
    for(;k>y;k--)
    {
        a[k]=a[k-1];
    }
    a[y]=data;
}
void whenBothAreThere(int a[], int n, int x, int y)
{
     int x1= pos(a,n,x);
     int x2= pos(a,n,y);
     if(x1>x2)
     {
        int i;
        for(i=x2;i<x1;i++)
        {
            a[i]=a[i+1];
        }
        a[i]=y;
     }
   //check this function
}
void fill(int a[], int b[], int c[], int n, int k)
{
    int i=0;
    int j=0;
    int flag1=-1, flag2=-1;
    for(;i<k;i++)
    {
        flag1 = search(c, a[i], n);
        flag2 = search(c, b[i], n);
        if((flag1==-1)&&(flag2==-1))
        {
            c[j]= a[i];
            j++;
            c[j]= b[i];
            j++;
        }
        else if((flag1==1)&&(flag2==-1))
        {
            if(b[i]>a[i])
            {
                int x = pos(c,n,a[i]);
                insertAfter(c,n,x,b[i]);

            }
            else
            {
                insertRightAfter(c,n,a[i],b[i]);
            }

        }
        else if((flag1==-1)&&(flag2==1))
        {
            if(a[i]<b[i])
            {
                int x = pos(c,n,b[i]);
                insertBefore(c,n,x,b[i]);
            }
            else
            {
                insertRightBefore(c,n,b[i],a[i]);
            }
        }
        else
        {
            whenBothAreThere(c,n,a[i],b[i]);
        }
    }

}
int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int i;
    int c[n];
    for(i=0;i<n;i++)
        c[i]=999;
    int a[k], b[k];
    for(i=0;i<k;i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    fill(a,b,c,n,k);
    for(i=0;i<n;i++)
        printf("%d ", c[i]);
    return 0;
}
