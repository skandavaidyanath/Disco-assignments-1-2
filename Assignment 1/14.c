#include<stdio.h>
int factorial(int n)
{
    int p=1;
    int i=1;
    for(;i<=n;i++)
        p *=i;
    return p;
}
int choose(int n, int r)
{
    int k = factorial(n)/(factorial(n-r)*factorial(r));
    return k;

}
int main()
{
    int n;
    scanf("%d", &n);
    int number_of_edges=0;
    int i;
    for(i=0;i<=n;i++)
    {
        number_of_edges += choose(n,i)*i;
    }
    printf("%d",number_of_edges);
}
