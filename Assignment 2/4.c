#include<stdio.h>

int counter=0;
int isSafe(int a[], int *graph, int N)
{
    int i;
    int flag=1;
    for(i=0;i<N;i++)
    {
        if((i!=N-1)&&(*(graph+a[i]*N+a[i+1])==1)) continue;
            else if((i==N-1)&&(*(graph+a[i]*N+a[0])==1)) continue;
                else flag=0;
    }
    return flag;
}
void heapPermutation(int a[], int size, int n, int *graph)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1)
    {
         if(a[0]==0)
         {
            counter += isSafe(a, graph, n);
            return;
         }
         return;
    }
    int i;
    for (i=0; i<size; i++)
    {
        heapPermutation(a,size-1,n, graph);

        // if size is odd, swap first and last
        // element
        if (size%2==1)
        {
            int t= a[0];
            a[0] = a[size-1];
            a[size-1] = t;
        }
        // If size is even, swap ith and last
        // element
        else
        {
            int t = a[i];
            a[i] = a[size-1];
            a[size-1] = t;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int graph[N][N];
    int i,j;
    int permutations[N];
    for(i=0;i<N;i++)
    {
        permutations[i]=i;
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
    }
    heapPermutation(permutations, N, N, (int *)graph);
    printf("%d", counter);
    return 0;
}
