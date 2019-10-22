#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main()
{
    int n,i,j;
    char x,y;
    ifstream fin("date.in");
    vector <int>V;queue<char>T,NT;
    list<pair<char,char>>E;
    fin>>n;V.resize(n);
    int S=0;

    for(i=0;i<n;i++)
    {
        fin>>V[i];S+=V[i];
        if(V[i]<1){cout<<"NU";return 0;}
        else if(V[i]==1)T.push('A'+i);
        else NT.push('A'+i);
    }
    if(S!=2*(n-1)){cout<<"NU";return 0;}

    while(!NT.empty())
    {
        x = NT.front();
        y=T.front();
        T.pop();
        V[x-'A']--;
        if(V[x-'A']==1)
        {
            NT.pop();T.push(x);
        }
        E.push_back({x,y});

    }
    x = T.front();T.pop();y=T.front();E.push_back({x,y});

    for(auto p:E)
        cout<<p.first-'A'+1<<" "<<p.second-'A'+1<<'\n';
}
