#include<stdio.h>

int getDegree(int a[], int n)
{
    int i;
    int c=0;
    for(i = 0; i<n ;i++)
    {
        if(a[i]==1) c++;
    }
    return c;
}
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
    int degree[N];
    int visited[N];
    int i,j;
    for(i=0;i<N;i++)
    {
        degree[i] = 0;
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
    int numberOfComponents = 0;
    for(i=0;i<N;i++)
    {
        if(visited[i]==0)
        {
            dfsAdjacency((int *)graph,i,visited, N);
            numberOfComponents++;
        }
    }
    if(numberOfComponents > 1) printf("No");
    else
    {
        for(i=0;i<N;i++)
        {
            degree[i] = getDegree(graph[i], N);
        }
        int countOdd = 0;
        int countEven = 0;
        for(i=0;i<N;i++)
        {
            if(degree[i]%2 == 0) countEven++;
                else countOdd++;
        }
        if((countEven==N)||(countOdd==2)) printf("Yes");
            else printf("No");
    }
    return 0;
}
