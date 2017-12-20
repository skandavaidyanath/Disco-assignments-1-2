#include<stdio.h>

void dfsAdjacency(int *graph, int v, int visited[], int N)
{
    int i;
    visited[v]=1;
    for(i=0;i<N;i++)
    {
       if((!visited[i])&&*(graph+v*N+i)==1)
       {
            dfsAdjacency(graph,i,visited, N);
       }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int graph[N][N];
    int visited[N];
    int i,j;
    for(i=0;i<N;i++)
    {
        visited[i] = 0;
        for(j=0;j<N;j++)
        {
            graph[i][j]=0;
        }
    }
    int M;
    int a,b;
    scanf("%d", &M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int u, v;
    scanf("%d %d", &u, &v);
    dfsAdjacency((int*)graph, u, visited, N);
    if(visited[v]==1) printf("Yes");
        else printf("No");
    return 0;
}
