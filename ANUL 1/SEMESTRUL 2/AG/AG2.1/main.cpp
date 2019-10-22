#include <iostream>
#include <fstream>
#include <list>
#include <utility>

using namespace std;

int m,n;
int status[100],dt[100],tata[100],low[100],crit[100];

list<int>L[100];
//list<pair<int,int>>MC;
ifstream fin("graf.in");
int times;


int dfs(int x)
{
int nrc = 0;
times++;
status[x]=1;
dt[x] = low[x] = times;

    for(int y:L[x])
    {
        if(status[y]==0)
        {
            tata[y]=x;
            nrc++;
            dfs(y);
            low[x] = min(low[x],low[y]);

            if(dt[x] <= low[y])crit[x] = 1;
            if(dt[x]<low[y]) cout<<'\n'<<x<<"-"<<y<<" criticala"<<endl;
        }

        if(status[y]==1)
            if(y!=tata[x]) // x-y muchie de intoarcere
        {
            low[x] = min(low[x],dt[y]);
        }


    }
status[x] = 2; return nrc;

}

int main()
{
    int i,j,x,y,st;
    fin >> n >> m;


    for(i=0;i<m;i++)
    {
        fin >> x >> y;
        L[x].push_back(y);
        L[y].push_back(x);
    }

    cin>>st;
    if(dfs(st)>1)crit[st]=1;
        else crit[st] = 0;
    for(i=1;i<=n;i++)
    {
        if(crit[i]==1)cout<<i<<" ";
    }

/*
    cout<<'\n';
    for(i=1;i<=n;i++)
    {
        for(int p:L[i])
            cout<<p<<" ";
        cout<<endl;

    }
cout<<"\n--------------------\n";
    for(i=1;i<=n;i++)
    {
        cout<<dt[i]<<" ";
    }
    cout<<'\n';

    for(i=1;i<=n;i++)
    {
        cout<<low[i]<<" ";
    }
    cout<<'\n';*/
}
