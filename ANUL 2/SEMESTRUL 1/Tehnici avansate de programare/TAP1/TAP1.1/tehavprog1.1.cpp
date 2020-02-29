#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <set>
#include <tuple>
#include <utility>

using namespace std;
int n;
ifstream f("date.in");

set< tuple<int,int,int> > s;

int* citire()
{
    f>>n;
    int *x = new int[n];
    for(int i=0;i<n;i++)
        {
            f>>x[i];

        }
    return x;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a) - (*(int*)b);
}

void sum_3(int n, int x[])
{
int i,a,b,c,inceput,sfarsit;
    for(i=0;i<n;i++)
    {
        a=x[i];
        inceput=i+1;
        sfarsit=n-1;
        while(inceput<sfarsit)
        {
        b=x[inceput];
        c=x[sfarsit];
        if(a+b+c==0)
        {
            s.insert(make_tuple(a,b,c));
            inceput++;
            sfarsit--;
        }
        else if (a+b+c>0)
            sfarsit--;

        else
            inceput++;
        }
    }
}

int main()
{
int *x = citire();
qsort(x,n,sizeof(int),compare);
sum_3(n,x);

set< tuple<int,int,int> >::iterator i;
for(i=s.begin();i!=s.end();i++)
    {
        cout<<"("<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<")"<<endl;
    }

delete(x);
}
