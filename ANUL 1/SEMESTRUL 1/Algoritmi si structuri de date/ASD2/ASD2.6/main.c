#include <stdio.h>
#include <stdlib.h>

int n,m;
int main()
{
scanf("%d%d",&n,&m);
int i,x;
if(n>m)x=n;
    else x=m;

int a[x+1],b[x+1];
for(i=x;i>=0;i--)
{
    a[i]=b[i]=0;
}
//
for(i=n;i>=0;i--){
    scanf("%d",&a[i]);
}
for(i=m;i>=0;i--){
    scanf("%d",&b[i]);
}

int c[x+1];
for(i=x;i>=0;i--){
    c[i]=b[i]+a[i];
    printf("%d ",c[i]);
}
}
