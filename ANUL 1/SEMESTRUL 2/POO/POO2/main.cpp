#include <iostream>

using namespace std;

//////////////        MATRICE          /////////////

class Matrice
{
private:
int n;
int **x;
public:
    Matrice(int **a);
    Matrice(const Matrice &x);
    ~Matrice();
    Matrice operator=(const Matrice &y);
    friend istream& operator>>(istream& in,Matrice &o);
    friend ostream& operator<<(ostream& out,Matrice &o);
};
Matrice::Matrice(int **a)
{
cout<<"cate noduri sunt?\n";
cin>>n;
a = new int*[n];

for(int i=0;i<n;i++)
    a[i] = new int[n];

x=a;

}
Matrice::~Matrice()
{
for(int i=0;i<n;i++) delete x[i];
delete x;
}
Matrice::Matrice(const Matrice &y)
{
n = y.n;

x = new int*[n];
for(int i=0;i<n;i++)
    x[i] = new int[n];

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        x[i][j] = y.x[i][j];
    }

}

Matrice Matrice::operator=(const Matrice &y)
{
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        x[i][j] = y.x[i][j];
    }

}

ostream& operator<<(ostream& out,Matrice &o) // afisare multimi
{
   int i,j;
   for(i=0;i<o.n;i++)
   {for(j=0;j<o.n;j++)
        out<<o.x[i][j]<< " ";
    out<<"\n";
   }
   return out;
}

istream& operator>>(istream& in,Matrice &o) // citire multimi
{
    int i,j;
    for(i=0;i<o.n;i++)
     for(j=0;j<o.n;j++)
        in>>o.x[i][j];
    return in;
}

////////////////      VECTOR       ////////////////////

class Vector
{
private:
    int *x;
    int n;
public:
    int Get_n(){return n;};
    int* Get_x(){return x;};
    Vector();
    Vector(int *v,int dim);
    ~Vector();
    Vector(const Vector &y);
    Vector operator=(const Vector &y);
    friend ostream& operator<<(ostream& out,Vector &o);
    friend istream& operator>>(istream& in,Vector &o);

};

Vector::Vector()
{cout<<"vector\n";
cin>>n;
x = new int[n];
}
Vector::Vector(int *v,int dim)
{
    n = dim;
    x = v;

    x = new int[n];
}
Vector::~Vector()
{
    delete x;
}

Vector::Vector(const Vector &y)
{
    n = y.n;
    x = new int[n];
    for(int i=0;i<n;i++)
        x[i] = y.x[i];
}
Vector Vector::operator=(const Vector &y)
{
    n = y.n;
    for(int i=0;i<n;i++)
        x[i] = y.x[i];
}
ostream& operator<<(ostream& out,Vector &o)
{
    for(int i=0;i<o.n;i++)
        out<<o.x[i]<<" ";
    return out;
}
istream& operator>>(istream& in,Vector &o)
{
    for(int i=0;i<o.n;i++)
        in>>o.x[i];
    return in;
}

struct nod
{

};

class Lista
{
private:
Vector *x;
int n;
public:
    Lista(Vector *l);
    ~Lista();
    Lista(const Lista &y);
    Lista operator=(const Lista &y);
    friend ostream& operator<<(ostream& out,Lista &o);
    friend istream& operator>>(istream& in,Lista &o);
};

Lista::Lista(Vector *l)
{
cout<<"lista:\n";
 x = l;
cin>>n;
}
Lista::~Lista()
{
delete x;
}
Lista::Lista(const Lista &y)
{
n = y.n;
x = new Vector[n];
for(int i=0;i<n;i++)
    x[i] = y.x[i];
}
Lista Lista::operator=(const Lista &y)
{
n = y.n;
for(int i=0;i<n;i++)
    x[i] = y.x[i];
}
ostream& operator<<(ostream& out,Lista &o)
{
for(int i=0;i<o.n;i++)
{
    cout<<o.x[i];
    cout<<endl;
}
return out;
}
istream& operator>>(istream& in,Lista &o)
{
    for(int i=0;i<o.n;i++)
    {
        in>>o.x[i];
    }
return in;
}

class Graf
{
protected:
    int n;
public:
    Graf(int nr_noduri){n = nr_noduri;}
    ~Graf();
    virtual void pure()=0;
};
/*
class Graf_Neorientat:public Graf
{
public:
    Graf_Neorientat(Lista L): Graf(n)
    {

    }
    ~Graf_Neorientat(): ~Graf()
    {

    }

};

class Graf_Orientat:public Graf
{
private:

public:
    Graf_Orientat(Matrice A):Graf(n)
    {

    }
    ~Graf_Orientat():~Graf();
};
*/

int main()
{/*
    int *a;
    Vector l[3];
    Lista A(l);
    cin>> A;
    cout<<endl<<A;*/
}
