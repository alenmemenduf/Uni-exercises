#include <iostream>

using namespace std;

struct nod{
int nr;
nod *st,*dr,*p;
};

void Inserare(nod* &tree,int val)
{
struct nod *x;
struct nod *y = NULL;
struct nod *z = new nod;

z->nr = val; //am creeat un nod cu valoarea transmisa
z->st = z->dr = z->p = NULL;
x=tree;


while(x != NULL)//parcurgem arborele cu x
{
    y=x;
    if(z->nr <= x->nr)
        x=x->st;
    else
        x=x->dr;
}

z->p = y;
if(y==NULL)
    tree = z;
else if(z->nr <= y->nr)
    y->st = z;
    else
        y->dr = z;
}


void cautarek1k2(nod* &tree,int k1,int k2)
{
if(tree==NULL)return;
if(tree->nr>k1&&tree->nr<k2){
    cout<<tree->nr<<" ";
    cautarek1k2(tree->st,k1,k2);
    cautarek1k2(tree->dr,k1,k2);
    }
else return;
}

nod* maxim(nod* &tree)
{
    while(tree->dr!=NULL)
        tree=tree->dr;
    return tree;
}

nod* minim(nod* &tree)
{
    while(tree->st!=NULL)
        tree=tree->st;
    return tree;
}

void Transplant(nod* &tree,nod* &u,nod* &v)
{
if(u->p==NULL)
    tree=v;
else if(u==u->p->st)
    u->p->st=v;
else u->p->dr=v;
if(v!=NULL)
    v->p = u->p;
}







int main()
{
struct nod* tree = NULL;
Inserare(tree,4);
Inserare(tree,1);
Inserare(tree,2);
Inserare(tree,3);
Inserare(tree,6);
Inserare(tree,7);

cautarek1k2(tree,1,7);
delete(tree);

}
