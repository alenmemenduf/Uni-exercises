#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct Dot
{
    int x,y;
};

Dot Primul_punct;


Dot Penultimul(stack<Dot> &stiva)
{
    Dot ultimul, penultimul;

    ultimul = stiva.top();
    stiva.pop();
    penultimul = stiva.top();
    stiva.push(ultimul);

    return penultimul;

}

void swap(Dot &a, Dot &b)
{
    Dot aux = a;
    a = b;
    b = aux;
}

int distanta(Dot a, Dot b)
{
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

int orientare(Dot a, Dot b, Dot c)
{
    int rez = (b.y-a.y) * (c.x-b.x) -
              (b.x-a.x) * (c.y-b.y);
    if(rez == 0)
        return 0;
    else if(rez>0)
        return 1;
    else
        return 2;
}

int comparatie(const void *a, const void *b)
{
    Dot *p = (Dot*)a;
    Dot *q = (Dot*)b;
    int o;
    o = orientare(Primul_punct, *p, *q);
    if(o == 0)
    {
        if(distanta(Primul_punct,*q) >= distanta(Primul_punct,*p))
            return -1;
        else
            return 1;
    }
    else
    {
        if(o==2)
            return -1;
    }
    return 1;
}


void Acoperire(Dot dot[], int n)
{
    int y_minim = dot[0].y;
    int minim = 0;

    for(int i=1; i<n; i++)
    {
        int y = dot[i].y;
        if((y<y_minim) || (y==y_minim &&
                           dot[i].x < dot[minim].x))
            y_minim = dot[i].y, minim = i;

    }


    swap(dot[0],dot[minim]);
    Primul_punct = dot[0];
    qsort(&dot[1],n-1,sizeof(dot[0]),comparatie);


    int m = 1;
    Dot dot2[n];
    dot2[0] = dot[0];

    for(int i=1; i<n; i++)
    {
        while(i<n-1 && orientare(Primul_punct, dot[i], dot[i+1])==0) // pastram doar cele mai indepartate puncte pe dreapta de la Primul_punct
            i++;

        dot2[m] = dot[i]; // formam noul vector pana la m
        m++;
    }


    stack<Dot> stiva;
    stiva.push(dot2[0]);
    stiva.push(dot2[1]);
    stiva.push(dot2[2]);
//cat timp nu face viraj dreapta -> pop
    for (int i=3; i<m; i++)
    {
        while(orientare(Penultimul(stiva),stiva.top(),dot2[i])!=2)
            stiva.pop();
        stiva.push(dot2[i]);
    }

    vector<Dot> I;
    vector<Dot> J;
//daca au ramas in stiva cel putin 3 puncte
    if(m<3)
    {
        while(!stiva.empty())
            stiva.pop();

        I.push_back(dot[0]);
        I.push_back(dot[3]);
    }
//Graham scan problema 4 puncte
    if(n==4)
    {
    //DACA E PATRULATER
        if(stiva.size()==4)
            while(!stiva.empty())
            {
                I.push_back(stiva.top());
                stiva.pop();
                J.push_back(stiva.top());
                stiva.pop();

            }

    //DACA E Triunghi cu un punct in mijloc
        else if(stiva.size()==3)
        {
            // I are tot ce e in stiva, J are ce nu e in stiva

            for(int i=0;i<3;i++)
            {
                I.push_back(stiva.top());
                stiva.pop();
            }
            for(int i=0;i<4;i++)
            {
                for(vector<Dot>::iterator it=I.begin();it<=I.end();it++)
                {
                    if((*it).x == dot[i].x && (*it).y == dot[i].y)
                        break;
                    else if(it == I.end())
                        J.push_back(dot[i]);
                }

            }
        }
        //DACA SUNT PE ACEEASI DREAPTA
        else
        {

            for(int i=0;i<4;i++)
            {
                for(vector<Dot>::iterator it=I.begin();it<=I.end();it++)
                {
                    if((*it).x == dot[i].x && (*it).y == dot[i].y)
                        break;
                    else if(it == I.end())
                        J.push_back(dot[i]);
                }

            }
        }
        cout<<"I: "<<endl;
        for(vector<Dot>::iterator i = I.begin(); i<I.end(); i++)
            cout<<(*i).x<<" "<<(*i).y<<endl;

        cout<<endl<<"J: "<<endl;
        for(vector<Dot>::iterator j = J.begin(); j<J.end(); j++)
            cout<<(*j).x<<" "<<(*j).y<<endl;


    }
    //Graham's scan general
    else
    {
        while(!stiva.empty())
        {
            cout<<stiva.top().x<<"-"<<stiva.top().y<<endl;
            stiva.pop();
        }
    }

}

int main()
{
    Dot dot[]= {{0,0},{3,0},{0,3},{1,1}};
    int n = sizeof(dot) / sizeof(dot[0]);
    Acoperire(dot,n);
}
