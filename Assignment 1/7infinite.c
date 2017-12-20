#include<stdio.h>
/*int gcd(int a, int b)
{
   if(a>b) return gcd(b,a);
   if((a==0)||(b==0)) return 0;
   if(a==b) return a;
   return gcd(a,b-a);

}*/
int gcd(int a, int b)
{
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
int main()
{
    int p,q;
    scanf("%d %d", &p, &q);
    int a=1,b=1;
    int dir=-1;
    int rank=1;
    while(5)
    {
        if((a==p)&&(b==q))
        {
            printf("%d\n", rank);
            break;
        }
        if(gcd(a,b)==1) rank++;
        switch(dir)
        {
            case -1: if(a==1) dir=1;
                     else a--;
                     b++;
                     break;
            case 1: if(b==1) dir=-1;
                    else b--;
                    a++;
                    break;
        }
    }
    return 0;
}
