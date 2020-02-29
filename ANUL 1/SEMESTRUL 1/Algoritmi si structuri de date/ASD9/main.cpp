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

void afisare(nod* &tree,int level)
{
    if(tree==NULL)
     return;
    cout<<" nivel"<<level<<": ";
    cout<<tree->nr;
    afisare(tree->st,level+1);
    afisare(tree->dr,level+1);
}

void RSD(nod* &tree)
{
    if(tree==NULL)
        return;
    cout<<tree->nr;
    RSD(tree->st);
    RSD(tree->dr);
}


void SRD(nod* &tree)
{
    if(tree==NULL)
        return;
    SRD(tree->st);
    cout<<tree->nr;
    SRD(tree->dr);
}

void SDR(nod* &tree)
{
    if(tree==NULL)
        return;
    SDR(tree->st);
    SDR(tree->dr);
    cout<<tree->nr;
}


nod* cautare(nod* &tree,int val)
{
if(tree==NULL || val==tree->nr)
    return tree;
else if(val<tree->nr)
    cautare(tree->st,val);
else cautare(tree->dr,val);
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

void Stergere(nod* &tree,int val)
{
    struct nod *aux,*y,*x = cautare(tree,val);
    if(x->st==NULL && x->dr==NULL)
    {
        if(x->p->st == x)
        {
            x->p->st = NULL;
            delete x;

        }
        else {
            x->p->dr = NULL;
            delete x;
        }
    }

    else if(x->st==NULL)
    {
        if(x->p->st==x)
        {
            aux = x->p;
            x->p->st = x->dr;
            x->dr->p =aux;
            delete x;
        }
        else{
            aux = x->p;
            x->p->dr = x->dr;
            x->dr->p =aux;
            delete x;
        }
    }



    else if(x->dr==NULL)
    {
        if(x->p->st==x)
        {
            aux = x->p;
            x->p->st = x->st;
            x->st->p =aux;
            delete x;
        }
        else{
            aux = x->p;
            x->p->dr = x->st;
            x->st->p =aux;
            delete x;
        }
    }



    else{

        y = minim(x->dr);

        if(y==x->dr)
        {

                Transplant(tree,x,y);
                y->st=x->st;
                y->st->p=y;
                delete x;
        }


            else
            {

                Transplant(tree,y,y->dr);
                y->dr=x->dr;
                y->dr->p =y;

                Transplant(tree,x,y);
                y->st=x->st;
                y->st->p=y;
                delete x;


            }

        }

}






int main()
{
struct nod* tree = NULL;
Inserare(tree,2);
Inserare(tree,4);
Inserare(tree,1);
Inserare(tree,2);
Inserare(tree,3);
Inserare(tree,7);

RSD(tree);
cout<<endl;
SRD(tree);
cout<<endl;
SDR(tree);
cout<<endl;


delete(tree);

}
