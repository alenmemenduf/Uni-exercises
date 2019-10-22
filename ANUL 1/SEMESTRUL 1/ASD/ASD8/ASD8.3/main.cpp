#include <iostream>
#include <string.h>
using namespace std;

struct nod{

char info;
nod* next;

}*prim,*ultim;

void push(){
if(ultim==NULL)
{
    nod *p = new nod;
    p->info='(';
    p->next=NULL;
    prim=ultim=p;
}
else
{
    nod *p = new nod;
    p->info='(';
    p->next=prim;
    prim=p;
}
}

int pop()
{
    nod *p = prim;
    if(prim==NULL)
        return -1;

    else if(prim==ultim)
        {
        prim=ultim=NULL;
        }

        else
        {
        p=p->next;
        delete(prim);
        prim=p;
        }
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
int l,i;
char x[20];
cin>>x;
l=strlen(x);

for(i=0;i<l;i++)
    if(x[i]=='(')
       push();
    else if(x[i]==')')
         if(pop()==-1)
            {
                cout<<"incorect";
                break;

            }
if(i==l)afisare();

}
