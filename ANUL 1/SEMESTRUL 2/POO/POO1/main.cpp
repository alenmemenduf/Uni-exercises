#include <iostream>

using namespace std;

struct nod{
int info;
nod *next;

};
////////////////CLASA LISTA INLANTUITA //////////////
class lista{
protected:
 nod *head,*tail;
public:
 lista()
 {
     head = NULL;
     tail = NULL;
 }
 void crearenod(int x)
    {
      nod *aux=new nod;
      aux->info=x;
      aux->next=NULL;
      if(head==NULL)
      {
        head=aux;
        tail=aux;
        aux=NULL;
      }
      else
      {
        tail->next=aux;
        tail=aux;
      }
    }

};
//////////////// CLASA MULTIME /////////////
class multime:public lista{
private:
 nod *a,*b,*temp;
public:
 void transformare()
    {
        a = head;
        while(a->next!=NULL)
        {
            b = a;
            while(b->next!=NULL)
            {
                if(a->info == b->next->info)
                {
                    temp = b->next->next;
                    delete b->next;
                    b->next = temp;
                }
                else b = b->next;
            }
            if(a->next!=NULL)
            a = a->next;
        }


    }
 nod* GetHead(){return head;};
 friend ostream& operator<<(ostream& out,multime &o);
 friend istream& operator>>(istream& in,multime &o);
 multime operator+(multime& b);
 multime operator*(multime& b);
 multime operator-(multime& b);
};

multime multime::operator+(multime& b) // reunirea multimilor
 {
    multime a;
    nod *x;

    x = this->head;

    while(x!=NULL)
    {
        a.crearenod(x->info);
        x = x->next;
    }
    x = b.head;
    while(x!=NULL)
    {
        a.crearenod(x->info);
        x = x->next;
    }

    a.transformare();
    return a;
 }

 multime multime::operator*(multime& b) //intersectia multimilor
 {
    multime a;
    nod *x,*y;

    x = this->head;
    while(x!=NULL)
    {
        y = b.head;
        while(y!=NULL)
        {
            if(x->info == y->info)
                a.crearenod(x->info);
            y = y->next;
        }
        x = x->next;
    }
    return a;
 }

 multime multime::operator-(multime& b) // diferenta multimilor
 {
    multime a;
    nod *x,*y;
    int ok;

    x = this->head;
    while(x!=NULL)
    {
        ok = 1;
        y = b.head;
        while(y!=NULL)
        {
            if(x->info == y->info)
                ok = 0;
            y = y->next;
        }
        if(ok==1)
            a.crearenod(x->info);
        x = x->next;
    }
    return a;
 }

ostream& operator<<(ostream& out,multime &o) // afisare multimi
{
    o.a = o.head;
    while(o.a!=NULL)
    {
        out<<o.a->info<<" ";
        o.a = o.a->next;
    }
    out<<endl;
    return out;
}

istream& operator>>(istream& in,multime &o) // citire multimi
{
    int i,x,n;

    cout<<"nr elemente:";
    in >> n;
    for(i=0;i<n;i++)
    {
        in >> x;
        o.crearenod(x);
    }
    o.transformare();
    return in;
}
/////////////////// CLASA PERECHE /////////////
class pereche{
private:
 int first;
 int second;
 pereche *next;

public:
/* void SetNext(pereche *next){this->next = next;};
 void SetSecond(int x){second = x;};
 void SetFirst(int x){first = x;};*/
 void crearepereche(int x,int y){first = x;second = y;};
 int getFirst(){return this->first;};
 int getSecond(){return this->second;};
 pereche *getNext(){return next;};
 friend class multime_perechi;
 friend ostream& operator<<(ostream& out,pereche &o);
 friend istream& operator>>(istream& in,pereche &o);
};
///////////////// CLASA PERECHE DE MULTIMI ///////////

class multime_perechi:public multime{
private:
    pereche *head,*tail;
    pereche *a,*b,*temp;
public:
    multime_perechi()
    {
        head = NULL;
        tail = NULL;
    }
    void crearenod(int x,int y)
    {
      pereche *aux = new pereche;
      aux->first=x;
      aux->second=y;
      aux->next=NULL;

      if(head==NULL)
      {
        head=aux;
        tail=aux;
        aux=NULL;
      }

      else
      {
        tail->next=aux;
        tail = aux;

      }
      //cout<<head->first<<head->second;
    }
    void transformare()
    {
        a = head;
        while(a->next!=NULL)
        {
            b = a;
            while(b->next!=NULL)
            {
                if(a->first == b->next->first && a->second == b->next->second)
                {
                    temp = b->next->next;
                    delete b->next;
                    b->next = temp;
                }
                else b = b->next;
            }
            if(a->next!=NULL)
            a = a->next;
        }
    }

 friend ostream& operator<<(ostream& out,multime_perechi &o);
 friend istream& operator>>(istream& in,multime_perechi &o);
};

ostream& operator<<(ostream& out,multime_perechi &o) // afisare multimi
{
    o.a = o.head;
    while(o.a!=NULL)
    {

        out<<o.a->getFirst() <<" "<< o.a->getSecond()<<endl;
        o.a = o.a->getNext();
    }
    out<<endl;
    return out;
}
istream& operator>>(istream& in,multime_perechi &o)
{
    int n,x,y;
    cout<<"nr perechi:";
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>x>>y;
        o.crearenod(x,y);
    }
    o.transformare();
    return in;
}

ostream& operator<<(ostream& out,pereche &o)
{
    out<<endl<< o.first << " " << o.second;
    return out;
}
 istream& operator>>(istream& in,pereche &o)
 {
    in>> o.first >> o.second;
    return in;
 }


multime_perechi produs_cartezian(multime a,multime b)
{
    multime_perechi A;
    nod *x,*y;
    x=a.GetHead();
    while(x!=NULL)
    {
    y=b.GetHead();
        while(y!=NULL)
            {
                A.crearenod(x->info,y->info);
                y=y->next;
            }
        x = x->next;
        }
    return A;
}




int main()
{
multime_perechi C;
multime A,B;
cin>>A>>B;
C = produs_cartezian(A,B);

cout<<C;
}
