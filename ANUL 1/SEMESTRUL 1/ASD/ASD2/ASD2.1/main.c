#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,min,max;
    scanf("%d", &n);
    int v[n];

    scanf("%d",v);
    min=max=v[0];

    for(i=1;i<n;i++){
            scanf("%d",v+i);
        if(v[i]>max)max=v[i];
        else if(v[i]<min)min=v[i];
    }
    printf("minimul e %d , maximul e %d",min,max);

}
