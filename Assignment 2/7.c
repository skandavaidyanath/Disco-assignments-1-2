#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct Edge
{
    int start;
    int end;
    int weight;
}Edge;

void printGroups(int groupings[], int N)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0;j<N; j++)
        {
            if(groupings[j] == i)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
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

void generateGroups(Edge *e[], int groupings[], int M, int N, int K)
{
    int numberOfGroups = N;
    int i,j;
    for(i = 0; numberOfGroups > K ; i++)
    {
        if((checkCycle(groupings, e[i], M)))
           {
               int temp = groupings[e[i]->end];
               for(j=0;j<N;j++)
               {
                   if(groupings[j]==temp)
                   {
                       groupings[j]=groupings[e[i]->start];
                   }
               }
               numberOfGroups--;
           }
    }
}

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

int distance(int a[], int b[])
{
    return pow((a[0]-b[0]),2) + pow((a[1]-b[1]),2);
}

int main()
{
    int N;
    scanf("%d", &N);
    int groupings[N];
    Edge *e[ N*(N-1)/2 ];
    int coordinates[N][2];
    int i,j;
    int a,b;
    for(i=0;i<N;i++)
    {
        groupings[i] = i;
        scanf("%d %d", &a, &b);
        coordinates[i][0] = a;
        coordinates[i][1] = b;
    }
    int K;
    scanf("%d", &K);
    int l = 0;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            e[l] = (Edge *)malloc(sizeof(Edge));
            e[l]->start = i;
            e[l]->end = j;
            e[l]->weight = distance(coordinates[i], coordinates[j]);
            l++;
        }
    }
    sort(e, N*(N-1)/2);
    generateGroups(e, groupings, N*(N-1)/2, N, K);
    printGroups(groupings, N);
    return 0;
}
