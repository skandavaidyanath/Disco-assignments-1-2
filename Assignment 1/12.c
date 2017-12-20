#include<stdio.h>
void reset(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=0;
    }
}
int terminate(int a[], int n)
{
    if(a[0]==n) return 1;
    else return 0;
}
int present(int a[],int n,int x)    //function to check if x is in an array a[]
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x) return 1;
    }
    return 0;
}
void copy(int a[], int b[], int k)
{
    int i;
    for(i=0;i<k;i++)
    {
        a[i]=0;
    }
    for(i=0;b[i]!=0;i++)
    {
        a[i]=b[i];
    }
}
int length(int a[])
{
    int i;
    for(i=0;a[i]!=0;i++);
    return i;
}
int checkPrime(int n)          //to check if a number n is prime
{
    int i;
    int c=0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0) c++;
    }
    if(c==2) return 1;
    else return 0;
}
void fillPrime(int n, int prime[])             //function to fill prime[] with prime factors of n
{
    int i;
    int j=0;
    for(i=1;i<=n/2;i++)
    {
        if((n%i==0)&&(checkPrime(i)))
           {
               prime[j]=i;
               j++;
           }
    }

}
int main()
{
    int n;               // the number
    scanf("%d", &n);
    int k=n/2;           //size of prev cur and prime
    int cur[k];
    int prev[k];
    int prime[k];
    int p;          //loop variable
    for(p=0;p<k;p++)
    {
        cur[p]=0;
        prev[p]=0;
        prime[p]=0;
    }
    fillPrime(n,prime);
    int edges = length(prime);  //initially....
    copy(prev, prime,k);    //copy prime on to prev
    int flag=0;
    int i,j;      // i is index of prev, j is index of prime
    while(5)
    {
        int x=0;   //index of cur
        for(i=0;prev[i]!=0;i++)
        {
            for(j=0;prime[j]!=0;j++)
            {
                int data = prev[i]*prime[j];
                if(n%data==0)
                {
                    if(present(cur,k,data)==0) {cur[x]=data; x++;}
                    edges++;
                }
            }
        }
        copy(prev,cur,k);
        reset(cur,k);                 //set cur back to all 0
        if(terminate(prev,n)) break;   //if the first element of the prev array is n then we are done
    }
    printf("%d",edges);
    return 0;
}
