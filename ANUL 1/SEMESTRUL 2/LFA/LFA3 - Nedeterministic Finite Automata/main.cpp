#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// nr stari totale // nr stari finale //  nr litere din alfabet // nr tranzitii
// starile finale // literele din alfabet // tranzitiile = stare1,stare2 si litera

class Automat
{
private:
 int q,t,f,v,sc;     // q = nr stari totale // g = nr tranzitii // f = nr stari finale // v = nr litere din alfabet // sc = stare curenta
 int *F;
 char *V;      // *F = starile finale // *V = literele alfabetului
 struct tranzitie
 {
    int a,b;
    char c;
 } *T;       // *G toate tranzitiile
 int ok;
public:
 Automat(char *fisier);
 int Verificare(char *cuvant,int sc,int litera_din_cuvant);
};

Automat::Automat(char *fisier)
{
    int i;
    ifstream in(fisier);
    in>>q>>f>>v>>t;
    F = new int[f];
    for(i=0;i<f;i++)
        in>>F[i];
    V = new char[v];
    for(i=0;i<v;i++)
        in>>V[i];
    T = new tranzitie[t];
    for(i=0;i<t;i++)
        in>>T[i].a>>T[i].b>>T[i].c;
    sc=0;
    ok=0;
}

int Automat::Verificare(char *cuvant,int sc,int litera_din_cuvant)
{
    int i;
    if(litera_din_cuvant == strlen(cuvant))
    {
        for(i=0;i<f;i++)
            if(sc==F[i])
                {ok=1;
                return 1;}
    }
    else
    {
        for(i=0;i<t;i++)
        {
            if(ok==1) return 1;
            if(T[i].a==sc && T[i].c==cuvant[litera_din_cuvant])
                Verificare(cuvant,T[i].b,litera_din_cuvant+1);
        }

    }
    return 0;
}
int main()
{
    Automat x("alt_AFN.in");
    char *w="ac";

    if(x.Verificare(w,0,0)==1)
        cout<<"accepta";
    else cout<<"nu accepta";
}
