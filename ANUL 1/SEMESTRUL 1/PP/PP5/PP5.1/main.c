#include <stdio.h>
#include <stdlib.h>

int x[4001];
int main()
{
 int i,n,m,k,nrcomune=0;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++){
    scanf("%d",&k);
    if(k>=0&&k<=2000)x[k]=1;
    else if(k>=-2000&&k<0)x[k+2000]=1;
 }
 for(i=1;i<=m;i++){
    scanf("%d",&k);
    if(k>=0&&k<=2000)
        if(x[k]==1)nrcomune++;
    else if(k>=-2000&&k<0)
        if(x[k+2000]==1)nrcomune++;
 }
 printf("%d",nrcomune);
}
