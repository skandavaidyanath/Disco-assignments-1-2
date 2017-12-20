#include<stdio.h>
int checkTrue(int a[],int n,int trues[])
{
    int i;
    int flag=1;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            if(trues[i]==1) continue;
            else
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==2) return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[m][n];
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=0;
    }
    for(i=0;i<m;i++)
    {
        int k;
        scanf("%d", &k);
        int l;
        int d;
        for(l=0;l<k;l++)
        {
            scanf("%d",&d);
            a[i][d]=1;
        }
        scanf("%d", &d);
        a[i][d]=2;
    }
    int trues[n];
    int o;
    for(i=0;i<n;i++)
        trues[i]=0;
    scanf("%d",&o);
    for(i=0;i<o;i++)
    {
        scanf("%d", &j);
        trues[j]=1;
    }
    int marked;
    while(5)
    {
        marked=0;
        for(i=0;i<m;i++)
        {
            int x = checkTrue(a[i],n,trues);
            if(x==-1) continue;
            else
            {
                if(trues[x]==0)
                {
                    trues[x]=1;
                    marked=1;
                }
            }
        }
        if(marked==0) break;
    }
    printf("-----------------\n");
    for(i=0;i<n;i++)
    {
        if(trues[i]==1) printf("%d ",i);
    }
    return 0;
}
