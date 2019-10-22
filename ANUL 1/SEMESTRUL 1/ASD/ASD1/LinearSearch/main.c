#include <stdio.h>
#include <stdlib.h>

int main()
{   //citiri
    int n,v[10],i,k,ok=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    scanf("%d",&k);


   //cautare
    for(i=0;i<n;i++){
        if(v[i]==k)
        {
            ok=1;
            printf("%d",i+1);
        }
    }
    if(ok==0)printf("-1");
}
