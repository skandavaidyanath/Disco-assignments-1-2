#include<stdio.h>
#include<stdlib.h>

typedef struct Edge
{
    int start;
    int end;
    int weight;
}Edge;

void sort(Edge *e[], int M)
{
    int i,j;
    for(i=0;i<M-1;i++)
    {
        for(j=0;j<M-i-1;j++)
        {
            if(e[j]->weight > e[j+1]->weight)
            {
                Edge *t = e[j];
                e[j] = e[j+1];
                e[j+1] = t;
            }
        }
    }
}

int checkCycle(int groupings[], Edge *e, int M)
{
    if(groupings[e->start]==groupings[e->end])
        {
                return 0;
        }
    return 1;
}

int findCost(Edge *e[], int groupings[],int M, int N)
{
    int cost = 1;
    int i;
    int j;
    for(i = 0; i<M; i++)
    {
        if((checkCycle(groupings, e[i], M)))
           {
               cost *= e[i]->weight;
               int temp = groupings[e[i]->end];
               for(j=0;j<N;j++)
               {
                   if(groupings[j]==temp)
                   {
                       groupings[j]=groupings[e[i]->start];
                   }
               }
           }
    }
    return cost;
}

int main()
{
    int N;
    scanf("%d", &N);
    int groupings[N];
    int i,j;
    for(i=0;i<N;i++)
    {
        groupings[i] = i;
    }
    int M;
    scanf("%d", &M);
    Edge *e[M];
    int a,b,c;
    for(i=0;i<M;i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        e[i] = (Edge *)malloc(sizeof(Edge));
        e[i]->start = a;
        e[i]-> end = b;
        e[i]-> weight = c;
    }
    sort(e, M);
    int cost;
    cost = findCost(e,groupings, M, N);
    printf("%d", cost);
    return 0;
}
