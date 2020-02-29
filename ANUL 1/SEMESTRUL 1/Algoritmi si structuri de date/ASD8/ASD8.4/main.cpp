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
    p->next=prim;
    prim=p;
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

int empty()
{
    if(ultim==NULL)
        return 1;
    else return 0;
}

int peek()
{
    if(prim!=NULL)
        return prim->info;
    return -1;
}

void afisare()
{
nod *p = prim;
cout<<"-varf- ";
while(p!=NULL)
{
    cout<<p->info<<" ";
    p=p->next;
}
cout<<" -baza-"<<endl<<endl;
}

int main()
{
prim=ultim;
int n,i,x;
cin>>n;
for(i=0;i<n;i++)
    {
        cin>>x;
        if(peek()==x)
            pop();
        else push(x);
    }

if(empty()==1)cout<<"corect";
else cout<<"incorect";
}
