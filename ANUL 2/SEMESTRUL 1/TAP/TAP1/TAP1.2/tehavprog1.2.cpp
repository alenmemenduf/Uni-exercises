#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <list>
using namespace std;

ifstream f("date.in");
map<pair<int,int>,int> Hash;
map<pair<int,int>,int>::iterator j;
list<vector<int> > Paralelipipede;
list<vector<int> >::iterator k;

void sortare (int &x, int &y, int &z)
{
    int minim = min(min(x, y), z);
    int maxim = max(max(x, y), z);
    int suma = x + y + z;
    y = suma - minim - maxim;
    x = minim;
    z = maxim;
}
int main()
{
    int n;
    f>>n;
    int L,l,h;
    double r=0;


    for(int i=0;i<n;i++)
    {
        f>>L>>l>>h;
        Paralelipipede.push_back({L,l,h});
    }
    // facem lista cu fiecare triplet
    for(k=Paralelipipede.begin(); k!=Paralelipipede.end(); k++)
    {
        /*sortam in ordine crescatoare tripletul
        ca sa luam ca si cheie perechea ultimelor 2*/
        sortare((*k)[0],(*k)[1],(*k)[2]);
        if((*k)[0]/2.0 > r)
            r = (*k)[0]/2.0;
        pair<int,int> cheie; cheie.first = (*k)[1]; cheie.second = (*k)[2];
        if(Hash.find(cheie)!=Hash.end()) // daca gasim deja cheia respectiva in map-ul "Hash"
        {
            j = Hash.find(cheie);
            double suma = ((*k)[0]+j->second)/2.0;
            r = max(r,suma);
            if(j->second < (*k)[0]) j->second = (*k)[0];
        }
        else
        {
            Hash.insert({cheie,(*k)[0]});
        }
    }
    cout<<r;

}
