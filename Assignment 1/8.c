#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    int check[n];  //to check how many friends get Momo again if they start with Momo
    int loop[n];    //to check if we're in a loop and stop accordingly
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        check[i]=0;
    }
    for(i=0;i<n;i++)      //starting with each of the friends
    {
        int j=i;
        int k=0;
        for(;k<n;k++)
            loop[k]=0;
        loop[i]=1;           //this array is to check how many times a friend gets Momo in a cycle
                            //since we start with friend i, i has already got Momo once
        while(5)
        {
            j = (j + a[j])%n;
            loop[j]++;
            if(j==i) {check[i]=1; break;}
            if(loop[j]>1) break;
        }
    }
    int c=0;
    for(i=0;i<n;i++)
    {
        if(check[i]>0) c++;
    }
    printf("%d", c);
    return 0;
}
