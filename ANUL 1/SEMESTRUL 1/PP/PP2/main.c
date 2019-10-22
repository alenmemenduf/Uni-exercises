#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{


/////PRIMA PROBLEMA/////



    /*
    int x,p=1;
    long y=0;
    scanf("%d",&x);
    while(x){
    y=y+(x%2)*p;
    p*=10;
    x/=2;
    }
    printf("%d",y);
    */

    /*
    int x,p=1;
    long y=0;
    scanf("%d",&x);
    while(x)
    {
      y=y+(x & 1)*p;
      p=(p<<3)+(p<<1);
    x=x>>1;
    }
    printf("%d",y);

    */



/////A DOUA PROBLEMA/////

/*
    int n,x;
    scanf("%d%d",&x,&n);

    printf("\n%d\n",((x>>n)&1));
    printf("\n%d\n",(x|(1<<n)));
    printf("\n%d\n",(x&(~(1<<n))));
    printf("\n%d\n",(x^(1>>n)));

  */

////A TREIA PROBLEMA////
/*
    int m=0,k=1,x,y,n,p;
    scanf("%d%d%d%d",&x,&y,&n,&p);
    while(n){
    m=m+k;
    k*=10;
    n--
    }
    y=y&m;
    x=x&(~(m<<p-n));
    printf("%d",x);
 */

////A partra problema////
/*
long long n2;
int u4,x,i,k=0,v[100];
scanf("%llu",&n2);
while(n2){
i=0;x=0;
u4=n2%10000;
    while(u4&&i<4){
    x=x+u4%10*pow(2,i);
    i++;
    u4/=10;
    }
v[k]=x;
k++;
n2/=10000;
}
for(i=k-1;i>=0;i--)
if(v[i]>9)
    printf("%c ",v[i]+55);
else printf("%d",v[i]);
*/

////A CINCEA PROBLEMA////
/*
int n,i=0,v[100],aux,suma;
while(scanf("%d",&v[i])&&v[i]!=0)
    i++;
n=i;
i=0;
while(i<n-1){
aux=v[i];
suma=0;
    while(aux){
    suma+=aux%10;
    aux/=10;
    }
if(v[i]%suma==v[i+1])
    printf("%d %d\n",v[i],v[i+1]);
i++;
}
*/

////A SASEA PROBLEMA////

int p,i,j,k;
scanf("%d",&p);
for(i=1;i<=p-2;i++)
    for(j=i;j<=p-2;j++)
        if(p-i-j>0)printf("%d %d %d\n",i,j,p-i-j);


}
