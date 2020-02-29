#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i,j;
    scanf("%d",&n);
    int v[n];
    for(i=0;i<n;i++){
        scanf("%d",v+i);
    }
    scanf("%d",&k);

    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    i=0;
    printf("\n");
    while(i<n){
        if(v[i]==k){
            for(j=i;j<n;j++)
                v[j]=v[j+1];
            n--;
        }
        i++;
    }

    for(i=0;i<n;i++)
        printf("%d ",v[i]);
}
