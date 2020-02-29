#include <stdio.h>
#include <stdlib.h>

    int freq[32000];
int countNumber(int number,int vect[],int length){
    int count = 0;

    for(int i = 0; i < length;i++){
        if(vect[i]==number)count++;
    }
    return count;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int vect[n];
   for(i=0;i<n;i++){
    scanf("%d",&vect[i]);
    }
    for(i=0;i<n;i++){
        freq[i] = countNumber(vect[i],vect,n);
    }

    for(i=0;i<n;i++)
        if(freq[vect[i]]==1)
        printf("%d",vect[i]);
}
