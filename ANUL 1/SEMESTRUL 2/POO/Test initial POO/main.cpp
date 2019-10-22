#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

struct forma
{
float suma_suprafete;
float volum;
struct forma *next;
};


void functie0()
{
    unsigned long long int a,b;
    cin >> a >> b;

    cout << a+b << endl;
}

int perfect(unsigned long long x)
{
    unsigned long long s=0;

    for(unsigned long long i=2;i<=x/2;i++)
        if(x%i==0)
            s+=i;
    if(x==s)return 1;
    return 0;
}

void functie1()
{
    unsigned long long a,b,s=0;
    for(unsigned long long i=a; i<=b; i++)
    {
        if(perfect(i)==1)
            s+=i;
    }

    cout << s;
}



void functie2()
{
    float h,r,latura_mica,latura_mare,latura,cateta_mica,cateta_mare,ipotenuza;
    float frisca=0,gem=0;
    char s[10];
    cin>>s;

    struct forma *x = NULL;
    struct forma *prim;

    while(strcmp(s,"stop")!=0)
    {
        struct forma *p = new forma;
        p->next = NULL;
        if(strcmp(s,"add")==0)
        {
            cin>>s;

            if(strcmp(s,"cerc")==0)
            {
                cin>>r;
                cin>>h;
                p->suma_suprafete = 2 * 3.14 * r * (r + h);
                p->volum = 3.14 * r * r * h;
                cout<<"gem: "<<2*p->volum<<" grame. frisca:"<<p->suma_suprafete<<" grame\n";
            }

            if(strcmp(s,"dreptunghi")==0)
            {

                cin>>latura_mica;
                cin>>latura_mare;
                cin>>h;
                p->suma_suprafete = 2* (latura_mare*latura_mica + latura_mare*h + latura_mica*h);
                p->volum = latura_mare * latura_mica * h;
                cout<<"gem: "<<2*p->volum<<" grame. frisca:"<<p->suma_suprafete<<" grame\n";
            }

            if(strcmp(s,"patrat")==0)
            {
                cin>>latura;
                cin>>h;
                p->suma_suprafete = 6*latura*latura;
                p->volum = latura*latura*latura;
                cout<<"gem: "<<2*p->volum<<" grame. frisca:"<<p->suma_suprafete<<" grame\n";
            }

            if(strcmp(s,"triunghi")==0)
            {
                cin>>cateta_mare;
                cin>>cateta_mica;
                cin>>h;
                ipotenuza = sqrt(pow(cateta_mare,2)+pow(cateta_mica,2));
                p->suma_suprafete = h*(cateta_mare+cateta_mica+ipotenuza) + cateta_mare*cateta_mica;
                p->volum =cateta_mare*cateta_mica*h/2;
                cout<<"gem: "<<2*p->volum<<" grame. frisca:"<<p->suma_suprafete<<" grame\n";
            }
        if(x==NULL)
        {
            x=p;
            prim = x;
        }
        else if(x!=NULL)
            {
                x->next = p;
                x = x->next;
            }
        }
/*
        if(strcmp(s,"remove")==0)
        {
            (s[7]-'1')
        }
*/
        cin >> s;

    if(strcmp(s,"total")==0)
    {

    x=prim;
    while(x!=NULL)
        {
        gem+=2*x->volum;
        frisca+=x->suma_suprafete;
        x=x->next;
    }
    cout<<endl<<"gem total: "<<gem<<" frisca total: "<<frisca<<endl;
        }
    }
delete(x);
}

int main()
{
functie2();
}
