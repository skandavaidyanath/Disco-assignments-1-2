#include<stdio.h>
#include<math.h>
int count(int a[])
{
    int i;
    int c_one=0;
    int c_zero=0;
    for(i=0;(a[i]!=5);i++)
    {
        if(a[i]==0) c_zero++;
        if(a[i]==1) c_one++;
    }
    if(c_one==c_zero) return 1;
        else return 0;

}
int main()
{
    int a[20]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
    int n;
    scanf("%d", &n);
    int i;
    for(i=0;(i<20)&&(n>0);i++)
    {
        int c= n%2;
        a[i]=c;
        n/=2;
    }
    int b[20]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
    int j=0;
    for(i=19;i>=0;i--)
    {
        if(a[i]!=5) {b[j]=a[i]; j++;}

    }
    if(count(b)==1) printf("Yes\n");
        else printf("No\n");
    return 0;
}
