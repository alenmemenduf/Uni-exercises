#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int aux=*a;
    *a=*b;
    *b=aux;
}




int Partitie(int v[],int prim,int ultim)
{
    int pivot=v[ultim];
    int i = prim-1;
    for(int j=prim;j<=ultim-1;j++)
    {
        if(v[j] <= pivot)
        {
        i++;
        swap(&v[i],&v[j]);

        }
    }
    swap(&v[i+1],&v[ultim]);
    return (i+1);
}

int Partitie_random(int v[],int prim,int ultim)
{
    srand(time(NULL));
    int m = prim+rand()%(ultim-prim);


    swap(&v[m],&v[ultim]);
    return Partitie(v,prim,ultim);

}


void QuickSort(int v[],int prim,int ultim)
{
    if(prim<ultim){

    int m = Partitie_random(v,prim,ultim);

    QuickSort(v,prim,m-1);
    QuickSort(v,m+1,ultim);
}
}
int main()
{
    int i,n,v[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }


QuickSort(v,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
}
