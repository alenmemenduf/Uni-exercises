#include <iostream>
#include <list>
using namespace std;

int main()
{
    int x;
    list <int>L;
    while(x!=0){

        cin>>x;
        if(x!=0)
        {
            if(x%2==0)
            L.push_back(x);

            if(x%2)
            L.push_front(x);
        }
    }
//for(int p:L)cout<<p<<" ";
for(list<int> :: iterator i = L.begin();i!=L.end();i++)
    cout<<*i<<" ";
}
