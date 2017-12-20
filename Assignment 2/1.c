#include<stdio.h>

int isSafe(int v, int* graph, int path[], int pos, int V)
{
    int i;
    if (*(graph + path[pos-1]*V +  v ) == 0)
        return 0;
    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}
int hamCycleUtil(int *graph, int path[], int pos, int V)
{
    if (pos == V)
    {
        if ( *(graph + path[pos-1]*V + path[0])  == 1 )
            return 1;
        else
            return 0;
    }
    int v;
    for (v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos, V))
        {
            path[pos] = v;
            if (hamCycleUtil (graph, path, pos+1, V) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void printSolution(int path[], int V)
{
    int i;
    for (i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d ", path[0]);
    printf("\n");
}

int main()
{
    int N, M;
    int a,b;
    int i,j;
    scanf("%d", &N);
    int graph[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            graph[i][j]=0;
    }
    scanf("%d", &M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int path[N];
    for (i=0;i<N;i++)
        path[i] = -1;
    path[0] = 0;
    hamCycleUtil((int *)graph, path, 1, N);
    printSolution(path, N);
    return 0;
}
