#include<stdio.h>
int min(int* a, int n)
{
	int result = a[0];
	int i;
	for(i =1;i<n;i++)
		result = a[i] < result ? a[i] : result;
	return result;
}
void printCombinations(int a[], int data[], int start, int end, int index, int r, int row, int *original, int size)
{
    int n=end+1;
    if(index==r)
    {
        if((n%2==0)&&(r==n/2)&&(min(a,n)==min(data,r))) return;
        int i,j;
        for(i = 0;i<size;i++)            // print all rows except the ith row
        {
			if(i == row) continue;
			for(j = 0; *(original + i*100 + j) !=-999; j++)
			{
				printf("%d ", *(original+ i*100 + j));
			}
			printf("\n");
		}
		for(i =0;i<r;i++)
			printf("%d ", data[i]);      //the data combination we just found
		printf("\n");
		for(i =0;i<n; i++)          //setMinus of a - data
        {
			int flag = 1;
			for(j=0;j<r;j++)
			{
				if(a[i]==data[j])
                {
                    flag=0;
                    break;
                }
			}
			if(flag==1)
				printf("%d ", a[i]);
		}
		printf("\n********************\n");
		return;
    }
    else
    {       int i;
            for(i=start;(i<=end)&&(end-i+1>=r-index);i++)
            {
                data[index]= a[i];
                printCombinations(a,data,i+1,end,index+1,r,row,(int*)original,size);
            }
    }

}
int length(int a[])
{
    int i;
    for(i=0;a[i]!=-999;i++);
    return i;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][100];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<100;j++)
        {
            a[i][j]=-999;
        }
    }
    int k;
    for(i=0;i<n;i++)
    {
        scanf("%d", &k);
        for(j=0;j<k;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n********************\n");
    for(i=0;i<n;i++)
    {
        int count  = length(a[i]);
        int temp[count];
        for(j = 0;j<count;j++)
			temp[j] = a[i][j];
        for(j=1;j<=count/2;j++)
        {
            int data[j];
            printCombinations(temp, data, 0, count-1, 0, j, i, (int *)a, n);

        }
    }
    return 0;
}

