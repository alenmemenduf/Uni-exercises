#include <limits.h>
#include <iostream>
#include <set>
#include <utility>
#include <fstream>
#include <list>
using namespace std;

int main()
{
    int n,m,p,i,t[100],d[100],st,x,y;
    ifstream fin("graf.in");
    list <pair<int,int> >L[100];
    fin>>n>>m;
    for(i=0;i<m;i++)
    {

        fin>>x>>y>>p;
        L[x].push_back({p,y});
        L[y].push_back({p,x});
    }
    for(i=0;i<n;i++)
    {
        d[i] = INT_MAX;
        t[i] = 0;
    }

    cout<<"nod de start:\n";
    cin>>st;
    d[st] = 0;
    set<pair<int,int> >Q;
    Q.insert({d[st],st});
    while(Q.size()>0)
    {
        x = Q.begin()->second;
        Q.erase(Q.begin());
        for(pair<int,int>it:L[x])
        {
            y = it.second;
            p = it.first;
            if(d[y]>d[x]+p)
            {
                Q.erase({d[y],y});
                d[y] = d[x]+p;
                t[y] = x;
                Q.insert({d[y],y});
            }
        }
    }

    for(i=0;i<n;i++)
    {
        cout<<i<<" "<<d[i] <<" "<<t[i]<<endl;
    }
}
