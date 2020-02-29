#include <iostream>

using namespace std;

struct nod{
int info;
struct nod *next;
};


void inserare(nod* &prim,nod* &ultim,int val)
{
    nod *p = new nod;
    nod *x = new nod;
    int OK=0;
    if(prim!=NULL)
    {

        if(val <= (prim->info))
        {
            p->info=val;
            p->next=prim;
            prim=p;
        }

        else if(val >= (ultim->info))
        {
            p->info=val;
            ultim->next=p;
            p->next=NULL;
            ultim=p;
        }
        else
        {   p=prim;
            while(p->next!=NULL && !OK)
            {
                if(p->info<=val && p->next->info>val)
                {
                    x->info=val;
                    x->next=p->next;
                    p->next=x;
                    OK=1;
                }
                p=p->next;
            }
        }
    }
    else
    {
        prim->info=val;
        cout<<prim->info;
        ultim=prim;
    }
}



void afisare(nod* &prim)
{
    nod *p = new nod;
    p=prim;
    while(p->next!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

int main()
{
    nod *prim = new nod;
    nod *ultim = new nod;
    prim->next=NULL;
    ultim->next=NULL;
inserare(prim,ultim,4);
inserare(prim,ultim,2);
inserare(prim,ultim,5);
inserare(prim,ultim,4);
inserare(prim,ultim,4);
inserare(prim,ultim,1);
afisare(prim);
}
