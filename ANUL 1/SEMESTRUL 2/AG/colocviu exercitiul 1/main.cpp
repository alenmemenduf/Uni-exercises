#include <iostream>
#include <fstream>
#include <list>
#include <utility>
using namespace std;

class Graph
{
private:
 int V,E;
 list<pair<int,int>> *adj;
 void DFSutil(int st,bool visited[],int tata[],int &ok)
 {
    visited[st] = true;
    cout<<st<<" ";

    list<pair<int,int>>::iterator i;
    for(i = adj[st].begin(); i!=adj[st].end(); i++)
    {


        if(!visited[i->first])
        {
            tata[i->first] = st;
            DFSutil(i->first,visited,tata,ok);
        }
        else if(tata[st]!= i->first)
            ok = 0;
    }
 }
public:
 Graph(int V,int E)
 {
 this->V = V;
 this->E = E;
 adj = new list<pair<int,int>>[V+1];
 }
void addEdge(int a,int b,int weight)
 {
 adj[a].push_back({b,weight});
 adj[b].push_back({a,weight});
 }
void DFS(int st)
{
    int ok = 1;
    bool visited[V];
    int tata[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    tata[st] = -1;
    DFSutil(st,visited,tata,ok);

    cout<<endl;
    if(ok) cout<<"DA";
    else cout<<"NU";
}
};

int main()
{
    ifstream f("graf.in");
    int n,m,k,a,b,c;
    f>> n >> m >> k;

    Graph graph(n,m);

    for(int i=0;i<m;i++)
    {
        f>>a>>b>>c;
        graph.addEdge(a,b,c);
    }
    graph.DFS(1);

f.close();
}
