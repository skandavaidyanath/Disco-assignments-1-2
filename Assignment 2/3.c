#include<stdio.h>

void copy(float a[], float b[], int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        b[i]=a[i];
    }
}
int degree(int a, int *graph, int N)
{
    int i;
    int deg=0;
    for(i=0;i<N;i++)
    {
        if(*(graph+a*N+i)==1) deg++;
    }
    return deg;
}
int edge(int *graph, int a, int b, int N)
{
    if(*(graph+a*N+b)==1) return 1;
        else return 0;
}
float probabilityJtoI(int a, int b, int *graph, int N)
{
    float result;
    if(degree(a, graph, N)==0)
    {
        result = (float)1/N;
    }
        else if((degree(a, graph, N)!=0)&&(!edge(graph,a,b,N)))
        {
            result = 0;
        }
            else if((degree(a,graph, N)!=0)&&(edge(graph,a,b,N)))
            {
                result = (float)1/degree(a,graph,N);
            }
    return result;
}
float findProbability(float prevprobability[], int i, int *graph, int N)
{
    int j;
    float result = 0;
    for(j=0;j<N;j++)
    {
        result += prevprobability[j]*probabilityJtoI(j, i, graph, N);
    }
    return result;
}
int main()
{
    int N;
    scanf("%d", &N);
    int graph[N][N];
    int i,j;
    float prevprobability[N];
    for(i=0;i<N;i++)
    {
        prevprobability[i]=0;
        for(j=0;j<N;j++)
        {
            graph[i][j]=0;
        }
    }
    prevprobability[0]=1;
    int M;
    scanf("%d", &M);
    int a,b;
    for(i=0;i<M;i++)
    {
        scanf("%d %d", &a, &b);
        graph[a][b]=1;
    }
    float currentprobability[N];
    for(j=1;j<=1000;j++)
    {
        for(i=0;i<N;i++)
        {
            currentprobability[i] = findProbability(prevprobability, i, (int *)graph, N);
        }
        copy(currentprobability, prevprobability, N);
    }
    for(i=0;i<N;i++)
    {
        printf("%f\n", currentprobability[i]);
    }
    return 0;
}
