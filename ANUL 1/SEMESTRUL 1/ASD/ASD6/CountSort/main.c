#include <stdio.h>
#include <stdlib.h>

void CountSort(int arr[],int n,int max)
{
    int count[10]={0};
    int i,j;
    for(i=0;i<n;i++)
    {
        count[arr[i]]=count[arr[i]]+1;
    }
    for(i=0;i<=max;i++)
    {
        for(j=1;j<=count[i];j++)
        {
            printf("%d ",i);
        }
    }
}

int main()
{
    int arr[10];
    int n,i,max=0;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    CountSort(arr,n,max);
    return 0;
}
