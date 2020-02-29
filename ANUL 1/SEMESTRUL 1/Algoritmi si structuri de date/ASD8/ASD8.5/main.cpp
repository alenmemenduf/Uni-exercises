#include <iostream>
#include <fstream>
using namespace std;

int A[10][10];

struct nod{

int x,y;
nod* next;

}*prim,*ultim;

void push(int i,int j){
if(ultim==NULL)
{
    nod *p = new nod;
    p->x=i;
    p->y=j;
    p->next=NULL;
    prim=ultim=p;
}

else
{
    nod *p = new nod;
    p->x=i;
    p->y=j;
    p->next=NULL;
    ultim->next=p;
    ultim=p;
}

}

int pop(int *i,int *j)
{
    nod *p = prim;
    if(prim==NULL)
        return -1;

    else if(prim==ultim)
        {
        *i=prim->x;
        *j=prim->y;
        prim=ultim=NULL;
        }

        else
        {
        *i=prim->x;
        *j=prim->y;
        p=p->next;
        delete(prim);
        prim=p;
        }
}

void adiacent(int i,int j)
{
    if(A[i-1][j]==1)push(i-1,j);
    if(A[i][j-1]==1)push(i,j-1);
    if(A[i][j+1]==1)push(i,j+1);
    if(A[i+1][j]==1)push(i+1,j);

}

void colorare(int k)
{
    int i,j;
    while(pop(&i,&j)!=-1)
    {
        adiacent(i,j);
        A[i][j]=k;
    }

}

int main()
{
    ifstream f("matrice.in");
    int i,j,m,k=2;
    f>>m;

    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        f >> A[i][j];

    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            {
                if(A[i][j]==1)
                {
                    push(i,j);
                    colorare(k);
                    k++;
                }
            }



    for(i=1;i<=m;i++)
        {
        for(j=1;j<=m;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
        }

f.close();
}

