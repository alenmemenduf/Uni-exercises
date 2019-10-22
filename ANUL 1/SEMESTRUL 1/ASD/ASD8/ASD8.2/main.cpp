#include <iostream>

using namespace std;

struct nod{

int info;
nod* next;

}*prim,*ultim;

void push(int x){
if(ultim==NULL)
{
    nod *p = new nod;
    p->info=x;
    p->next=NULL;
    prim=ultim=p;
}

else
{
    nod *p = new nod;
    p->info=x;
    p->next=NULL;
    ultim->next=p;
    ultim=p;
}

}

int pop()
{
    int x;
    nod *p = prim;
    if(prim==NULL)
        return -1;

    else if(prim==ultim)
        {
        x=prim->info;
        prim=ultim=NULL;
        return x;
        }

        else
        {
        x=prim->info;
        p=p->next;
        delete(prim);
        prim=p;
        return x;
        }
}
int peek()
{
    if(prim!=NULL)
        return prim->info;
    return -1;
}

int empty()
{
    if(ultim==NULL)
        return 1;
    else return 0;
}

int search(int x)
{
    int k=1;
    nod *p=prim;
    while(p!=NULL)
    {
        if(p->info==x)
            return k;
        k++;
        p=p->next;
    }
    return -1;
}


void afisare()
{
nod *p = prim;
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
prim = ultim;

afisare();
push(1);
push(2);
push(3);
afisare();
cout<<search(2)<<endl;
cout<<search(4)<<endl;
cout<<empty()<<endl;
cout<<pop()<<endl;
afisare();
cout<<peek()<<endl;
afisare();
pop();
pop();
afisare();
cout<<pop()<<endl;
cout<<empty()<<endl;
}
