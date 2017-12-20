#include<stdio.h>
void printCombinations(int a[], int data[], int start, int end, int index, int r, int d[], int l)
{
    if(index==r)
    {
        int j;
        for(j=0;j<r;j++)       //print the combination from collosus' set
        {
            printf("%d ", data[j]);
        }
        for(j=0;j<l;j++)       //print the set minus which is always required
        {
                if(d[j]!=999) printf("%d ",d[j]);
        }
        printf("\n");
    }
    else
    {       int i;
            for(i=start;(i<=end)&&(end-i+1>=r-index);i++)
            {
                data[index]= a[i];
                printCombinations(a,data,i+1,end,index+1,r,d,l);
            }
    }

}
int main()
{
    int n,k,l;          //sizes of universal set, collosus' set and required set respectively
    scanf("%d", &n);
    int u[n];  //universal skillset
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &u[i]);
    }
    scanf("%d", &k);
    int c[k];  //collossus' skillset
    for(i=0;i<k;i++)
    {
        scanf("%d", &c[i]);
    }
    scanf("%d",&l);
    int r[l]; //required skillset
    int d[l]; //duplicate copy of r
    for(i=0;i<l;i++)
    {
        scanf("%d", &r[i]);
        d[i]=r[i];
    }
    for(i=0;i<k;i++)             //index of collosus' set
    {
        int j;                        //here we are doing d - c ie r - c
        for(j=0;j<l;j++)            //index of duplicate ie required set
        {
            if(c[i]==d[j]) {d[j]=999; break;}

        }
    }
    int data[k];
    printf("***************\n");
    for(i=0;i<l;i++)
    {
        if(d[i]!=999) printf("%d ",d[i]);
    }
    printf("\n");
    for(i=1;i<=k;i++)
    {
        printCombinations(c,data,0,k-1,0,i,d,l);
    }
    return 0;
}
