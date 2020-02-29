#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream f("date.in");
class text
{
private:
    int frecventa;
    int lungime;
    int index;
public:
    text(int frecventa,int lungime,int index) : lungime(lungime),frecventa(frecventa),index(index){};
    int Get_lungime()
    {
        return lungime;
    }
    int Get_frecventa()
    {
        return frecventa;
    }
    int Get_index()
    {
        return index;
    }

};

bool comparatie_frecventa(text a, text b)
{
    return a.Get_frecventa() > b.Get_frecventa();
}

bool comparatie_lungime(text a, text b)
{
    if(a.Get_frecventa() == b.Get_frecventa())
        return a.Get_lungime() < b.Get_lungime();
    else return 0;
}
///Sortam mai intai dupa frecventa descrescator si in caz de egalitate la frecventa, sortam crescator dupa lungime
void Sortare(vector<text> &banda)
{
    sort(banda.begin(),banda.end(),comparatie_frecventa);
    sort(banda.begin(),banda.end(),comparatie_lungime);
}

int main()
{
    int n,frecventa,lungime;
    vector<text> banda;
    f>>n;

    for(int i=0;i<n;i++)
    {
        f>>frecventa>>lungime;
        text *p = new text(frecventa,lungime,i);
        banda.push_back(*p);
    }

    Sortare(banda);

    //Afisare
    for(vector<text>::iterator i=banda.begin();i<banda.end();i++)
    {
        cout<<"p"<<(*i).Get_index()<<": "<<(*i).Get_frecventa()<<" "<<(*i).Get_lungime()<<endl;
    }
}
