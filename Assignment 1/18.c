#include<stdio.h>
void printCombinations(int a[], int data[], int start, int end, int index, int r)
{
    if(index==r)
    {
        int j;
        for(j=0;j<r;j++)
            printf("%d ", data[j]);
        printf("\n");
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
    int i=0;
    for(;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    int r;
    scanf("%d", &r);
    int data[r];
    printCombinations(a,data,0,n-1,0,r);
    return 0;
}
