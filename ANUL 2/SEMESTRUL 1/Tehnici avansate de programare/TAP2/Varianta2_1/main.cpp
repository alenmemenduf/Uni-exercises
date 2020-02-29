// Se citesc n si p
// Se citesc n perechi de lungimi de laturi si culorile lor
//
// Rezulta: cate perechi au fost folosite, suma laturilor si laturile in ordinea datelor de intrare
// astfel incat un cub este pus peste altul doar daca are o latura mai mica si culoarea diferita de el

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
ifstream f("date.in");

///////////////////////
//
// Clasa cub ne va ajuta sa retinem valoarea lungimii, a culorii, dar si a indexului initial ( pentru afisare ) //
//
//////////////////////
class cub
{
private:
    int lungime;
    int culoare;
    int indexInitial;
public:
    cub(int lung,int cul,int index) : lungime(lung),culoare(cul),indexInitial(index){};
    int Get_lungime()
    {
        return lungime;
    }
    int Get_culoare()
    {
        return culoare;
    }
    int Get_indexInitial()
    {
        return indexInitial;
    }
};
///////////////////////////
//
// sortam descrescator, dupa lungime, vectorul //
//
///////////////////////////
bool compare(cub a, cub b)
{
    return (a.Get_lungime() > b.Get_lungime());
}

void Sortare(vector<cub> &cuburi)
{
sort(cuburi.begin(),cuburi.end(),compare);
}

/*      adaugam intr-un nou vector numit turn,
        doar acele cuburi care sunt de o culoare diferita de cubul precedent    */

vector<cub> Turn(vector<cub> &cuburi)
{
    vector<cub> turn;
    for(vector<cub>::iterator j = cuburi.begin();j<cuburi.end();j++)
    {
        if(j==cuburi.begin())
            turn.push_back(*j);
        else
        {
            if((*(j-1)).Get_culoare() != (*j).Get_culoare())
                turn.push_back(*j);
        }
    }
    return turn;
}

int main()
{
    int n, p;
    f>>n>>p;
    int i;
    int sumaLungimilor=0;
    vector<cub> cuburi; // retinem cuburile intr-un vector
    for(int i=0;i<n;i++)
    {
        int a,b;
        f>>a>>b;
        cub *c = new cub(a,b,i+1);
        cuburi.push_back(*c);
    }

    Sortare(cuburi); // Sortarea descrescatoare dupa lungime

    vector<cub> turn = Turn(cuburi);
    for(vector<cub>::iterator j = turn.begin();j<turn.end();j++)
    {
        sumaLungimilor+=(*j).Get_lungime(); // lungimea turnului
    }

    cout<<turn.size()<<" "<<sumaLungimilor<<endl; // afisarea numarului de cuburi, precum si lungimii turnului

    for(vector<cub>::iterator j = turn.begin();j<turn.end();j++)
    {
        cout<<(*j).Get_indexInitial()<<" "; // afisarea indexilor cuburilor din turn
    }



}
///// Corectitudine /////
/*
    Demonstram ca algoritmul greedy construieste o solutie optima cu ajutorul inductiei,
    dupa ce vectorul de cuburi a fost sortat in functie de latura, descrescator.

    P(0) si P(1) evidente.
    Fie n>=2, presupunem P(n-1) adevarat, demonstram P(n):

    Fie S o multime cu n cuburi

    1. Exista o solutie optima care contine primul cub adaugat
    si avem O = {o1,o2,..,on} solutie optima sortata descrescator dupa latura
    Daca acest prim cub apartine solutiei O atunci afirmatia de mai sus este adevarata.
    Presupunem ca acest prim cub "1" nu apartine lui O

    Daca culoarea lui 1 este aceeasi cu culoarea lui o1 din solutia O atunci,
    deoarece 1 are cea mai mare latura, putem obtine un turn O' = O - {o1} + {1} cu inaltime mai mare decat O, dar O solutie optima, contradictie.

    Daca culoarea lui 1 NU este aceeasi cu culoarea lui o1 din solutia O atunci
    Putem insera {1} sub turnul deja existent, formand un turn O' = O + {1} care are inaltime mai mare decat O, dar O solutie optima, contradictie.

    2. Fie r primul cub avand culoare diferita de cubul 1 si S' = {r,r+1,...,n}
    multimea cuburilor care pot apartine turnului cu baza 1
    Conform ipotezei inductiei:
    La pasul P(i) avem S' cu solutia greedy optima G' = G - {1} si rezulta ca  la pasul P(i+1) avem G = G' + {1}
    solutie optima pentru S, altfel, conform primului punct, ar exista un turn O ce il contine pe 1 si e mai inalt decat G
    ceea ce inseamna ca si O - {1} e mai inalt decat G', dar G' este optim, contradictie.

*/
