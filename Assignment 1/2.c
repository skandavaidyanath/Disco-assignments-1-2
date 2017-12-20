#include<stdio.h>

int count(int n, int k)
{
    if((n<k)||(k<1)) return 0;
        else if ((n==k)||(k==1)) return 1;
            else
            {
                return count(n-1,k-1)+ count(n-k,k);
            }
}
int main()
{
    int e,m;            // e is total energy and m is min energy per clone
    scanf("%d %d", &e, &m);
    int max_clones= e/m;
    int i=1;
    int counter=0;
    for(;i<=max_clones;i++)
    {
        int available = e - ((m-1)*i);
        counter += count(available, i);
    }
    printf("%d", counter);
    return 0;
}
