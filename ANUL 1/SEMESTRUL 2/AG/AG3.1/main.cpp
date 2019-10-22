#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <list>
using namespace std;


int main()
{
ifstream fin("date.in");
int n,i,j,x;
vector <pair<int,char>>S,man; //grad,eticheta
list <pair<char,char>>E;

fin>>n; S.resize(n);man.resize(n);
for(i=0;i<n;i++)
{
    fin>>x; if(x<0||x>=n)
    {
        cout<<"NU"; return 0;
    }
    S[i]={x,'A'+i};
}

sort(S.begin(),S.end());
//for(i=0;i<n;i++) cout<<S[i].second<<' '<<S[i].first<<'\n';
while(S[n-1].first >0)
{
    int d = S[n-1].first;
    char et = S[n-1].second;
    S.pop_back();n--;
    for(i=1;i<=d;i++)
    {
        S[n-i].first--;
        E.push_back({et,S[n-i].second});
        if(S[n-i].first<0)
        {
            cout<< "NU";return 0;
        }
    }
    merge(S.begin(),S.begin()+n-d , S.begin()+n-d,S.end() , man.begin());
for(i=0;i<n;i++)S[i] = man[i];
}
for(auto p:E)
    cout<<p.first-'A'+1<<' '<<p.second-'A'+1<<'\n';
}
