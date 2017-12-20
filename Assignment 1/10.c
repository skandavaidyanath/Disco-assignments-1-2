#include<stdio.h>
int main()
{
    int n;
    int counter=0; //for non-zeros and non-ones and non minus ones
    scanf("%d",&n);
    int i;
    int a;
    int counter_one=0;
    int counter_minus_one=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if((a!=0)&&(a!=1)&&(a!=-1)) counter++;
        if(a==1) counter_one++;
        if(a==-1) counter_minus_one++;
    }
    if(counter>1) printf("No\n");
    else if((counter_minus_one>0)&&(counter>0)) printf("No\n");
    else if((counter_minus_one>1)&&(counter_one==0)) printf("No\n");
    else printf("Yes\n");
    return 0;
}
