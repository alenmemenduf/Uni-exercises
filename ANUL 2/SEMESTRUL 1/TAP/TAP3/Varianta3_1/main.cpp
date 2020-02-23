#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");

int cautare_varf(int v[],int n)
{
    if(n==1)
        return v[n];

    int m = n/2;
    if(v[m-1]<v[m] && v[m]<v[m+1])
        cautare_varf(v+(n/2), n/2);
    else if(v[m-1]>v[m] && v[m]>v[m+1])
        cautare_varf(v,n/2);
    else return v[m];

}

int main()
{
    int n;
    f>>n;
    int v[n];

    for(int i=0;i<n;i++)
        f>>v[i];
    cout<<cautare_varf(v,n);
}
