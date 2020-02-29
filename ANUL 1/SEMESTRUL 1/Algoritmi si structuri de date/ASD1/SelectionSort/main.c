#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,v[10],max,jmax,aux;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",v+i);
    }
    for(i=0;i<n;i++){
        max=v[i];
        jmax=i;
        for(j=i;j<n;j++)
        {
        if(v[j]>max){
                max=v[j];
                jmax=j;
        }
        aux=v[i];
        v[i]=v[jmax];
        v[jmax]=aux;

    }
}
    for(i=0;i<n;i++){
        printf("%d ",v[i]);

    }
}
