#include <iostream>

using namespace std;

struct nod{
int info;
nod* adr;
};

void alf(nod* &prim,nod* &ultim,int val)
{
    nod *p = new nod;
    if(ultim!=NULL){
        p->info=val;
        ultim->adr=p;
        p->adr=NULL;
        ultim=p;
    }
    else {
    p->info=val;
    p->adr=NULL;
    ultim=p;
    prim=p;
    }
}

void af(nod* &prim)
{
    nod *p = prim;
    while(p!=NULL)
    {
    cout<< p->info <<" ";
    p=p->adr;
    }
}

void inversare(nod* &prim,nod* &ultim)
{
    nod *prev = prim;
    nod *current = prev->adr;
    nod *next = current->adr;

    prev->adr=NULL;
    while(next->adr!=NULL)
    {
    current->adr=prev;
    prev=current;
    current=next;
    next=next->adr;
    }
    prim=next;
    next->adr=current;
    current->adr=prev;
}

int main()
{
    nod *prim = new nod;
    nod *ultim = new nod;
    prim = ultim = NULL;

    alf(prim,ultim,4);
    alf(prim,ultim,1);
    alf(prim,ultim,3);
    alf(prim,ultim,7);
    alf(prim,ultim,9);
    alf(prim,ultim,5);
    alf(prim,ultim,10);
    inversare(prim,ultim);
    af(prim);
}
