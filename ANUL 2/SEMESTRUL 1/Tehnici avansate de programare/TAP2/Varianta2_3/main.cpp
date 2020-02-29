#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream f("date.in");

// salvam intr-o clasa profitul, termenul limita si indexul
class activitate
{
private:
    int profit;
    int termen;
    int index;
public:
    activitate(int profit,int termen,int index):profit(profit),termen(termen),index(index){};

    int Get_profit()
    {
        return profit;
    }
    int Get_termen()
    {
        return termen;
    }
    int Get_index()
    {
        return index;
    }
};

bool comparatie_profit(activitate a, activitate b)
{
    return a.Get_profit() > b.Get_profit();
}
///////////////////////////////////////////////////////////
//// SORTAM DESCRESCATOR DUPA PROFIT
///////////////////////////////////////////////////////////
void Sortare(vector<activitate> &Activitati)
{
    sort(Activitati.begin(),Activitati.end(),comparatie_profit);
}

int main()
{
    int profit;
    int termen;
    int n;
    int suma_profit=0;
    vector<activitate> Activitati; // vectorul de Activitati retine tripletele {profit,termen,index}
    f>>n;

    int optim[n]; // un vector in care retinem indexul termenului cu cel mai mare profit la momentul respectiv
    bool ocupat[n]; // un vector in care retinem care pozitii din optim sunt ocupate

    for(int i=0; i<n; i++)
        ocupat[i] = false; // vectorul este gol la inceput


///// Citire

    for(int i=0;i<n;i++)
    {
        f>>profit>>termen;
        activitate *p = new activitate(profit,termen,i);
        Activitati.push_back(*p);
    }

/////


    Sortare(Activitati);

/* Debug
    for(int i=0;i<n;i++)
    {
        cout<<Activitati[i].Get_profit()<<" "<<Activitati[i].Get_termen()<<endl;
    }
    cout<<endl;

*/

    for(int i=0; i<n; i++)
    {
        for(int j=min(n,Activitati[i].Get_termen())-1; j>=0; j--)   //in vectorul optim verificam dinspre minimul dintre n si deadline-ul activitatii curente
        {                                                           //catre stanga pana gasim un loc liber, cand gaseste un loc liber, ii stocheaza index-ul acolo
            if(ocupat[j] == false)                                  //si trece la urmatoarea activitate pana le verifica pe toate
            {
                optim[j] = i;
                ocupat[j] = true;
                suma_profit += Activitati[i].Get_profit();
                break;
            }
        }
    }

//// Afisare

    cout<<suma_profit<<endl;
    for(int i=0;i<n;i++)
    {
        if(ocupat[i])
            cout<<Activitati[optim[i]].Get_index()+1<<" ";
    }

////
}

///// Corectitudine //////
/*
    O sa demonstram corectitudinea algoritmului inductiv, cand vectorul este deja sortat descrescator dupa profit:

    Fie P(i) propozitia care afirma ca solutia Greedy S(i) poate fi extinsa,la pasul i,
    la o solutie optima S(opt) prin adaugarea elementelor de la i+1 la n.

    -Pentru i=0, avem P(0) adevrat pentru ca vectorul este gol
     in ambele solutii si solutia poate fi extinsa

    -Presupunem ca P(i) adevarat, demonstram P(i):

     Avem 2 cazuri
     {

        - C1:
            /Activitatea i+1 nu poate fi adaugata la solutia Greedy/ deci S(i+1) = S(i),
            solutia ramane neschimbata la pasul i+1 si cum S(opt) extinde S(i), extinde si pe S(i+1)
        - C2:
            /Activitatea i+1 este programata la un timp numit t0/,
            deci S(i+1)[t0] din solutia Greedy este i+1 si t0 este
            ultimul loc liber gasit care este mai mic decat termenul lui i+1

            Pentru cazul 2 avem 2 subcazuri:
                {
                    - C2.1:
                        /Activitatea apare in solutia optima dar la un timp t1
                        mai devreme decat t0/

                        Astfel t1<=t0 si S(opt)[t1] = i+1 = S(i+1)[t0]
                        Daca t1 = t0 atunci S(opt) extinde S(i+1)
                        Altfel, daca t1 < t0, avem S(opt)[t0] = j care e diferit de i+1
                        si formam un S'(opt) care este echivalent cu S(opt) dar cu valorile de pe t1 si t0 interschimbate

                        S'(opt) este solutie optima, deoarece din moment ce j != 0,
                        doar am mutat j intr-un loc mai vechi si am adus i+1 pe ultima pozitie
                        Astfel S'(opt) extinde S(i+1)

                    - C2.2:
                        /Activitatea i+1 nu apartine lui S(opt)/

                        Formam S'(opt) care e identic cu S(opt), doar ca la pozitia t0 definim S'(opt) = i+1
                        S(opt)[t0] = j si e diferit de i+1 dar S(opt) extinde S(i) de unde j apartine intervalului [i+1..n] ordonate descrescator
                        Deci S'(opt) extinde S(i+1) si profitul lui j <= profitul lui i+1, deci S'(opt) are profit mai mare decat S(opt) si cum S(opt)
                        era optim, S'(opt) optim
                }
     }
*/
/// Complexitatea algoritmului de mai sus este O(n^2) deoarece, desi sortarea este O(n logn),
/// algoritmul parcurge printr-un for n elemente de maxim n ori si reda algoritmului complexitatea O(n^2)
/// acest algoritm poate fi construit si in O(n logn)
