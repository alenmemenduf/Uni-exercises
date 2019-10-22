#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,t,k;
    scanf("%d",&n);
    int v[n];

    for(i=0;i<n;i++)
        scanf("%d",v+i);


    for(i=0;i<n;i++)
         printf("%d ",v[i]);
    printf("\n");


    scanf("%d",&t);
    int w[n+t];

    scanf("%d",&k);
    //
    for(i=0;i<k;i++)
        w[i]=v[i];

    for(i=k;i<k+t;i++)
        scanf("%d",&w[i]);

    for(i=k+t;i<n+t;i++)
        w[i]=v[i-t];

    //
    printf("\n");
    for(i=0;i<n+t;i++)
        printf("%d ",w[i]);
}
