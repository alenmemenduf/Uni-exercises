#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,v[10],k,i,j,ok=0,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    scanf("%d",&k);
    i=1;j=n;
    m=(i+j+1)/2;
    while(ok==0&&i<j){
        if(k<v[m])
            j=m;
        else if(k>v[m])i=m;
        else ok=1;
        m=(i+j+1)/2;
    }
    if(ok)printf("%d",m);
        else printf("-1");
}
