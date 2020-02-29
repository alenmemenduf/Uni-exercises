#include <iostream>

using namespace std;

struct nod{

int info;
nod* next;

};


void push(nod* prim[],nod* ultim[],int l,int x){
if(ultim[l]==NULL)
{
    nod *p = new nod;
    p->info=x;
    p->next=NULL;
    prim[l]=ultim[l]=p;
}

else
{
    nod *p = new nod;
    p->info=x;
    p->next=NULL;
    ultim[l]->next=p;
    ultim[l]=p;
}

}
/*
int pop()
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
*/

void afisare(nod* prim[],nod* ultim[],int l)
{
nod *p = prim[l];
cout<<"-primul- ";
while(p!=NULL)
{
    cout<<p->info<<" ";
    p=p->next;
}
cout<<" -ultimul-"<<endl<<endl;
}

int main()
{
int i,k;
cin>>k;
nod *prim[k+2],*ultim[k+2];
for(i=0;i<=k+1;i++)
    prim[i] = ultim[i] = new nod;
push(prim,ultim,0,3);
afisare(prim,ultim,0);
}
