#include <iostream>

using namespace std;

struct nod{
int info;
nod *next;
}*prim,*ultim;

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

void ip(nod* &prim,nod* &ultim,int poz,int elem)
{
int i;
nod *p = prim;
nod *x = new nod;
x->info=elem;
for(i=1;i<=poz-1;i++)
    p=p->next;
x->next=p->next;
p->next=x;
if(ultim->next!=NULL)
    ultim=ultim->next;

}

void af(nod* &prim){
    nod* p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

void citire(int n)
{
    int i,x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        alf(prim,ultim,x);
    }
}
int main()
{
 int i=1,n,s;
 cin>>n;
 citire(n);
 nod *p = prim;
    while(p->next!=NULL)
    {
        s=p->info+p->next->info;
        ip(prim,ultim,i,s/2);
        p=p->next->next;
        i+=2;
    }
af(prim);
}
