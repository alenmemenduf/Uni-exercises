#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sorted=0,v[10],i,n,aux;

    scanf("%d",&n);

        for(i=0;i<n;i++)
        {
        scanf("%d",v+i);
        }
    while(!sorted){
        sorted=1;
        for(i=0;i<n;i++){
            if(v[i]>v[i+1])
            {
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
            sorted=0;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",*(v+i));
    }
}
