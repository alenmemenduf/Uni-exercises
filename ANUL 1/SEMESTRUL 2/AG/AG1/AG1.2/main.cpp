#include <iostream>
#include <fstream>
#include <list>
#include <utility>
#include <queue>
using namespace std;

int M[10][10];
list<int> X[10];
bool check[50];
int pred[50];
int d[50];
ifstream fin("graf.in");

int MatriceAdiacenta( list<pair<int,int> > E)
{

    for(pair<int,int>p:E)
        M[p.first][p.second] = M[p.second][p.first] = 1;

}
int AfisareMatrice()
{
    int i,j;
    for(i=1;i<10;i++)
        int y;
    {
        int y;
        for(j=1;j<10;j++)
        cout<<M[i][j]<<" ";
        cout<<endl;
    }
}


int ListaAdiacenta(list<pair<int,int> > E)
{
    for(pair<int,int>p:E)
        X[p.first].push_back(p.second),X[p.second].push_back(p.first);
}
////
int AfisareLista()
{
    int y;
    for(int i=1;i<10;i++)
    {
        cout<<i<<": ";
        for(int p : X[i])
            cout<< p <<" ";
        cout<<endl;
    }
}
////

void BFS(int x,list <int > L[10])
{
    while(fin>>x)check[x] = true;
    int st; cin>> st;
    queue <int> Q; Q.push(st);
    pred[st]=-1; d[st] = 0;
    while(!Q.empty())
        {
            x=Q.front();Q.pop();
            if(check[x])break;
        for(int y:L[x]) if(!pred[y])
        {
            pred[y] = x; d[y] = d[x]+1;
            Q.push(y);
        }
    cout<<"cel mai apropiat punct de control este "<<x<<" ";
    cout<<" distanta "<<d[x]<<endl;
        }
}


int main()
{
    int n,m,x,y,i;
    list< pair<int,int> > E;

    fin>>n>>m;
    for(i=0;i<m;i++)
    {
        fin>>x>>y;E.push_back({x,y});
    }
    cout<<"Lista de muchii:\n";

    for(pair<int,int>p:E)
        cout<<p.first<<" "<<p.second<<"\n";
    ListaAdiacenta(E);
    BFS(x,X);

}
