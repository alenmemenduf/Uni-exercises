#include <stdio.h>
#include <stdlib.h>

void interclasare(int arr[],int st,int m,int dr)
{
    int i,j,k;
    int n1 = m-st+1;
    int n2 = dr-m;

    int Stanga[n1],Dreapta[n2];

    for(i=0;i<n1;i++)
        Stanga[i] = arr[st+i];
    for(j=0;j<n2;j++)
        Dreapta[j] = arr[m+1+j];

    i=0;j=0;k=st;

    while(i<n1 && j<n2)
    {
        if(Stanga[i]<=Dreapta[j])
        {
            arr[k]=Stanga[i];
            i++;
        }
        else
        {
            arr[k]=Dreapta[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=Stanga[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=Dreapta[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[],int st,int dr)
{
    if(st<dr)
    {
        int m=(st+dr)/2;
        mergeSort(arr,st,m);
        mergeSort(arr,m+1,dr);
        interclasare(arr,st,m,dr);
    }
}

void Afisare(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    Afisare(arr,n);

}
