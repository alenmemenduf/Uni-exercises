#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod* next;
};

void alf(nod* &prim,nod* &ultim,int val)
{
    nod *p = new nod;
    if(ultim!=NULL){
        p->info=val;
        ultim->next=p;
        p->next=NULL;
        ultim=p;
    }
    else {
    p->info=val;
    p->next=NULL;
    ultim=p;
    prim=p;
    }
}

void af(nod* prim){
    nod* p;
    p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Sortare(nod* &prim1,nod* &prim2)
{
    nod *p1 = prim1;
    nod *p2 = prim2;
    nod *aux;

    if(p1->info > p2->info)
    {
        prim1=p2;
        while(p1->next!=NULL && p2->next!=NULL)
        {
            if(p1->info <= p2->info)
            {
                aux=p1->next;
                p1->next=p2;
                p1=aux;
            }
            else
            {
                aux=p2->next;
                p2->next=p1;
                p2=aux;
            }
        }
    }
}

int main()
{
    nod *prim1 = new nod;
    nod *prim2 = new nod;
    nod *ultim1 = new nod;
    nod *ultim2 = new nod;
    prim1 = prim2 = ultim1 = ultim2 = NULL;

    alf(prim1,ultim1,4);
    alf(prim1,ultim1,6);
    alf(prim1,ultim1,8);
    af(prim1);
    alf(prim2,ultim2,1);
    alf(prim2,ultim2,2);
    alf(prim2,ultim2,5);
    alf(prim2,ultim2,9);
    alf(prim2,ultim2,9);
    af(prim2);

    Sortare(prim1,prim2);
    af(prim1);
}
