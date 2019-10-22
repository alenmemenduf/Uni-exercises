#include <stdio.h>
#include <stdlib.h>
int p[10],q[10],pq[21];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    ;
    for(i=n;i>=0;i--)
        scanf("%d",&p[i]);
    for(i=m;i>=0;i--)
        scanf("%d",&q[i]);

    for(i=n;i>=0;i--)
        for(j=m;j>=0;j--)
            pq[i+j]=pq[i+j]+p[i]*q[j];
    for(i=m+n;i>=0;i--)
        printf("%d ",pq[i]);
}
