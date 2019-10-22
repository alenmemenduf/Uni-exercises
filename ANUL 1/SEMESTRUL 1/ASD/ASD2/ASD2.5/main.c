#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int p(int t,int v[]){
    int s=0,i;
    for(i=0;i<=n;i++){
        s=s+v[i]*pow(t,i);
        }
return s;
}


int main()
{
int t;
scanf("%d",&n);
int i,v[n+1];
for(i=n;i>=0;i--)
    scanf("%d",&v[i]);
scanf("%d",&t);

printf("%d",p(t,v));
}


