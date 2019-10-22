#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nrCifreX=0,nrCifreY=0,nrmaxcifre;
    long long aux,x,y;
    int x1[100],y1[100];
    scanf("%lli%lli",&x,&y);
    aux=x;
    while(aux)
    {
        x1[nrCifreX]=aux%10;
        nrCifreX++;
        aux=aux/10;
    }
    aux=y;
    while(aux)
    {
        y1[nrCifreY]=aux%10;
        nrCifreY++;
        aux=aux/10;
    }


    if(nrCifreX>nrCifreY){
        nrmaxcifre=nrCifreX;
        for(int i=nrCifreY+1;i<=nrCifreX;i++)
            x1[i]=0;
    }
    else{
    nrmaxcifre=nrCifreY;
    for(int i=nrCifreX+1;i<=nrCifreY;i++)
        y1[i]=0;
    }


for(int i=0;i<=nrmaxcifre;i++){
    x1[i]=x1[i]+y1[i];
    if(x1[i]>9){
        x1[i+1]=x1[i+1]+x1[i]/10;
        x1[i]%=10;
    }
}
    for(int i=nrmaxcifre;i>=0;i--)
        printf("%d",x1[i]);
}
