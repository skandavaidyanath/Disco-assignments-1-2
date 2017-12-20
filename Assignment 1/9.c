#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==1) continue;  //only if the first array is undividable, Galactus wins
        else {flag=1; break;}     //the total number of breaks is always 2^(n-1)-1 where n is the level of the tree we draw
    }                              //the above number is always odd. Hence it is always Uatu who makes the last move
    if(flag==0) printf("Galactus");     // therefore unless the first array is undividable, Galactus can't win
    else printf("Uatu");
   return 0;
}
