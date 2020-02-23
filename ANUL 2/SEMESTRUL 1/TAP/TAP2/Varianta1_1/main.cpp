#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comparatie(pair<int,int> &a,
                pair<int,int> &b)
{
    if(a.first == b.first)
        return a.second > b.second;
    else return 0;
}
ifstream f("date.in");
int main()
{
    /*
    vector <pair<int,int>> v,s;
    citim n,a,b;
    while(f>>a>>b){
        if(y<a||x>b) continue;
        v.push_back({x,y});
    }
    sortam v dupa primul element crescator;
    si la egalitate descrescator dupa al doilea element

    if(v[0].first>a){cout<<"nu exista sol"; return 0;}
    s.push_back(v[0]);

    for(i=1;i<n;i++)
    {
        if(s.size() == 1)
        {
            if(v[i].first<=a && v[i].second>=s[0].second) s[0]=v[i];
            else if(v[i].first<=s[0].second && v[i].second>s[0].second) s.push_back(v[i]);
        }
        else
        {
            if(v[i].first <= s[s.size()-1].second && v[i].second > s[s.size()-1].second) s.push_back(v[i]);
        }
    }

    */
    vector < pair<int,int> > v,s;
    int a,b,x,y,n;
    f>>a>>b;
    f>>n;
    while(f>>x>>y)
    {
    if(y<a||x>b) continue;
    v.push_back({x,y});
    }

    sort(v.begin(),v.end());

    cout<<endl;

    sort(v.begin(),v.end(),comparatie);

    for(vector< pair<int,int> >::iterator i=v.begin();i<v.end();i++)
        cout<<i->first<<" "<<i->second<<endl;
    //sortare


}
