#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod* next;
}*prim,*ultim;


void af(nod* prim){
    nod* p;
    p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<endl;
        p=p->next;
    }
}

void ali(nod* &prim,nod* &ultim,int val)
{
    nod *p = new nod;
    if(prim!=NULL){
        p->info=val;
        p->next=prim;
        prim=p;
    }
    else {
    p->info=val;
    p->next=NULL;
    prim=p;
    ultim=p;
    }
}

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

int cv(nod* &prim,int val){

int poz=0;
nod *p = new nod;
p=prim;
while(p->next!=NULL){
    poz++;
    if(p->info==val)return poz;
    p=p->next;
}
if(p==NULL)return -1;

}

int cp(nod* &prim,int poz){

int val=1;
nod *p;
p=prim;
while(p->next!=NULL&&val!=poz)
{
    val++;
    p=p->next;
}
if(p!=NULL)return p->info;
else return -1;

}

void iv(nod* &prim,nod* &ultim,int val,int elem)
{
int i;
nod *p; p=prim;
nod *x = new nod;
x->info=elem;
if(val!=-1){
for(i=1;i<=cv(prim,val)-1;i++)
    p=p->next;
x->next=p->next;
p->next=x;
if(ultim->next!=NULL)
    ultim=ultim->next;
}
}

void ip(nod* &prim,nod* &ultim,int poz,int elem)
{
int i;
nod *p; p=prim;
nod *x = new nod;
x->info=elem;
for(i=1;i<=poz-1;i++)
    p=p->next;
x->next=p->next;
p->next=x;
if(ultim->next!=NULL)
    ultim=ultim->next;

}




int main()
{
prim=ultim=NULL;
alf(prim,ultim,2);
alf(prim,ultim,4);
alf(prim,ultim,5);
alf(prim,ultim,1);
iv(prim,ultim,5,2);
af(prim);
}
