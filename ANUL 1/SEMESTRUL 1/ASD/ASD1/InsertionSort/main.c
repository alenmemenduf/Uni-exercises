#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,v[10],i,j,aux;

    scanf("%d",&n);
        for(i=0;i<n;i++)
        {
        scanf("%d",v+i);
        }
    for(i=0;i<n;i++){
        aux=v[i];
        j=i-1;

        while(j>=0&&v[j]>aux){
        v[j+1]=v[j];
        j--;
        }
        v[j+1]=aux;
    }
    for(i=0;i<n;i++)
        printf("%d ",v[i]);
}
