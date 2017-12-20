#include<stdio.h>
int serious(int a[], int n)
{
    int i,j;
    int counter=0;
    int cardinality = n%2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]<=a[i]) continue;
            else
            {
                if(a[j]%a[i]==0) counter++;
            }
        }
    }
    if((counter%2)==cardinality) return 1;
    else return 0;
}
void printCombinations(int a[], int data[], int start, int end, int index, int r)
{
    if(index==r)
    {
        if(serious(data,r))
        {
            int j;
            for(j=0;j<r;j++)
                printf("%d ", data[j]);
            printf("\n");
        }
    }
    else
    {       int i;
            for(i=start;(i<=end)&&(end-i+1>=r-index);i++)
            {
                data[index]= a[i];
                printCombinations(a,data,i+1,end,index+1,r);
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
        scanf("%d",&a[i]);
    }
    int data[n];
    for(i=2;i<=n;i++)
    {
        printCombinations(a,data,0,n-1,0,i);
    }
    return 0;
}
