#include <iostream>

using namespace std;

struct nod{
int info;
nod *next;
}*ultim1,*prim1,*ultim2,*prim2;

void Lista(int x,nod* &p,nod* &prim,nod* &ultim)
{
    p->info=x%10;
    x/=10;
    p->next=NULL;
    prim = ultim = p;

    while(x)
    {
        nod *p = new nod;
        p->info=x%10;
        ultim->next = p;
        p->next = NULL;
        ultim=p;
        x/=10;
    }
}

/*
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
*/
void af(nod* &prim)
{
 nod *p = prim;
 while(p != NULL)
 {
    cout << p->info << "~";
    p = p->next;
 }
 cout<<endl;
}

int GetSize(nod* &prim)
{
    nod *p = prim;
    int k=0;
    while(p)
    {
        k++;
        p=p->next;
    }
    return k;
}

void Suma()
{
    int n,m,carry=0;
    nod *p = prim1;
    nod *q = prim2;
    n=GetSize(prim1);
    m=GetSize(prim2);
    if(n>=m)
    {
    for(int i=1;i<m;i++)
        q=q->next;
    for(int i=1;i<=n-m;i++)
    {
        nod *q2 = new nod;
        q2->info=0;
        q2->next=NULL;
        q->next=q2;
        q=q2;
    }
    ultim2=q;
    }

    else
    {
    for(int i=1;i<n;i++)
        p=p->next;
    for(int i=1;i<=m-n;i++)
    {
        nod *p2 = new nod;
        p2->info=0;
        p2->next=NULL;
        p->next=p2;
        p=p2;
    }
    ultim1=p;
    }


    p=prim1;
    q=prim2;

    while(p && q)
    {
        p->info=carry+p->info+q->info;
        carry=0;
        if(p->info>9)
        {
            carry=1;
            p->info-=10;
        }
        p=p->next;
        q=q->next;
    }

    if(carry)
    {

        nod *p = new nod;
        p->info=1;
        p->next=NULL;
        ultim1->next=p;
        ultim1=p;

    }
}
int main()
{

    nod *p = new nod;
    nod *q = new nod;
    int x,y;
    cin>>x>>y;
    Lista(x,p,prim1,ultim1);
    Lista(y,q,prim2,ultim2);
    af(prim1);
    af(prim2);
    Suma();
    af(prim1);


}
