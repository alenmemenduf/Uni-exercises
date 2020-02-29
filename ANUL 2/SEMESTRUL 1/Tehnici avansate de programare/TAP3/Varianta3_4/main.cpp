#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
using namespace std;

ifstream f("date.in");



class punct{
private:
    int x,y;
public:
    punct(){};
    punct(int a,int b){x = a; y = b;};
    int Get_x(){return x;};
    int Get_y(){return y;};
    void Set_x(const int a){x = a;};
    void Set_y(const int a){y = a;};
};


void Citire(int &n, punct Puncte[])
{
    int x,y;
    for(int i=0;i<n;i++)
    {
        f>>x>>y;
        Puncte[i].Set_x(x);
        Puncte[i].Set_y(y);
    }
}


void Afisare(const int n, punct Puncte[])
{
    for(int i=0;i<n;i++)
    {
        cout<<Puncte[i].Get_x()<<" "<<Puncte[i].Get_y()<<endl;
    }
    cout<<endl;
}

bool ComparDupaX(punct a, punct b)
{
    return a.Get_x() < b.Get_x();
}
bool ComparDupaY(punct a, punct b)
{
    return a.Get_y() < b.Get_y();
}

float Distanta(punct a, punct b)
{
    int x = a.Get_x()-b.Get_x();
    int y = a.Get_y()-b.Get_y();

return sqrt(x*x + y*y);
}

float min(float x, float y)
{
    return (x<y)?x:y;
}

float Aproape_de_linie(punct Linie[],int marime,float d)
{
    float minim = d;
    sort(&Linie[0],&Linie[marime-1],ComparDupaY);

    for(int i=0;i<marime;i++)
        for(int j=i+1;j < marime && (Linie[j].Get_y() - Linie[i].Get_y()) < d;j++)
            if(Distanta(Linie[j],Linie[i]) < minim)
                minim = Distanta(Linie[j],Linie[i]);

    return minim;
}
float Recursivitate(punct Puncte[], int n)
{
    if(n<=3)
    {
        float minim = FLT_MAX;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(Distanta(Puncte[i],Puncte[j]) < minim)
                    minim = Distanta(Puncte[i],Puncte[j]);
        return minim;
    }

    int mijloc = n/2;
    punct punctulMijlociu = Puncte[mijloc];

    float stanga = Recursivitate(Puncte,mijloc);
    float dreapta = Recursivitate(Puncte+mijloc,n-mijloc);

    float d = min(stanga,dreapta);

    punct Linie[n];
    int j = 0;
    for(int i = 0; i < n;i++)
        if(abs(Puncte[i].Get_x()-punctulMijlociu.Get_x())<d)
        {
            Linie[j] = Puncte[i];
            j++;
        }
    return min(d,Aproape_de_linie(Linie,j,d));
}

int main()
{
    int n;
    punct *Puncte;
    f>>n;
    Puncte = new punct[n];

    Citire(n,Puncte);
    sort(&Puncte[0],&Puncte[n],ComparDupaX);

    //Afisare(n,Puncte);

    cout<<Recursivitate(Puncte,n);
}
