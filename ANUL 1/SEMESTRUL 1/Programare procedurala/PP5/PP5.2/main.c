#include <stdio.h>
#include <stdlib.h>

int CautareBinara(int v[],int k,int n)
{
int mid,midval,inf=0,sup=n-1;
while(inf<=sup)
{
    mid=(inf+sup)/2;
    if(k<v[mid])sup=mid;
    else if (k>v[mid])inf=mid;
    else return mid;
}



}

int main()
{
    int aux,n,x,y,i;
    scanf("%d",&n);
    int v[n];

    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    scanf("%d%d",&x,&y);

    if(y<x){
        aux=y;
        y=x;
        x=aux;
    }
    int inf,sup;
    inf=CautareBinara(v,x,n);
    sup=CautareBinara(v,y,n);
    for(i=inf;i<=sup;i++)
        printf("%d ",v[i]);

}
