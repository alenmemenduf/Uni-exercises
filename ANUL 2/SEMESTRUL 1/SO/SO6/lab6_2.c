#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct matrice
{
 int n,m;
 int element[10][10];
}A,B;


int* inmultire(void* v)
{
 int* result=(int*)malloc(sizeof(int));
	result[0] = 0;
 int *vector =(int*)v;
 for(int i=0;i<A.m;i++)
   result[0]+= (A.element[vector[0]][i] * B.element[i][vector[1]]);
 return result;
}

int main()
{

	FILE* f = fopen("matrici.txt","r");

	fscanf(f,"%d%d",&A.n,&A.m);
	for(int i=0;i<A.n;i++)
	 for(int j=0;j<A.m;j++)
	  fscanf(f,"%d",&A.element[i][j]);

	fscanf(f,"%d%d",&B.n,&B.m);
	for(int i=0;i<B.n;i++)
	 for(int j=0;j<B.m;j++)
	  fscanf(f,"%d",&B.element[i][j]);
if(A.m == B.n)
{

	pthread_t thr;
	struct	matrice C;
	C.n = A.n;
	C.m = B.m;

    int v[2];
	
    for(int i=0;i<C.n;i++)
    for(int j=0;j<C.m;j++)
    {
        int** result;
        v[0] = i;
        v[1] = j;	 
        pthread_create(&thr,NULL,(void*)inmultire,v);
        pthread_join(thr,(void**)result);
	C.element[i][j] = **result;
}

    for(int i=0;i<C.n;i++)
    {
    for(int j=0;j<C.m;j++)
	printf("%d ",C.element[i][j]);
    printf("\n");
    }
	fclose(f);
}
else
{
printf("coloanele primei matrice != liniile celei de a doua");
return -1;

}
}
