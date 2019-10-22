#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class personal
{
 public:
personal(float procent,float incasari){
    procent_suma = procent;
    suma += procent * incasari / 100;}/*
void setCNP(char* Cod)
{
    CNP = new char[sizeof(Cod)];
    strcpy(CNP,Cod);
}
char* getCNP(){return CNP;}
void setNume(char* name)
{
    Nume = new char[sizeof(name)];
    strcpy(Nume,name);
}
char* getNume(){return Nume;}*/
int getSuma(){return suma;}
 protected:
char* CNP;
char* Nume;
char* nume_film;
float procent_suma;
float suma = 0;
};

class actor : public personal
{
 public:
actor(int estePrincipal,float procent,float incasari) : personal(procent,incasari)
{
    RolPrincipal = estePrincipal;
    if(estePrincipal!=0){
        procent_suma+=10;
        suma = procent_suma * incasari / 100;
    }
}
 private:
int RolPrincipal;
};

class regizor : public personal
{
 public:
regizor(float suma_fixa,float procent,float incasari) : personal(procent,incasari)
{
    suma += suma_fixa;
}

};

class film
{
 public:
float getSuma(){return suma;}
int get_nrActori(){return nrActori;}
int get_nrActoriPrincipali(){return nrActoriPrincipali;}
int get_nrPersonal(){return nrPersonal;}
 private:
float suma;
char* nume;
char* tip;
int durata;
int nrActori;
int nrPersonal;
int nrActoriPrincipali;
};

class persoane : public personal, public actor, public regizor{};

template <class X> class FirmaDistributie
{
 public:
void adaugaFilm(film T)
{
    Filme.push_back(T);
    nrPersoane = nrPersoane + T.get_nrActori() + T.get_nrPersonal() + 1;
    nrActori = nrActori + T.get_nrActori();
}
template <class Y> void adaugaPersoana(Y* a)
{
Pers.push_back(a);
}
 private:
vector <film> Filme;
X nrPersoane=0;
X nrActori=0;
X nrActoriPrinciali=0;
vector <persoane> Pers;
};

template <> class FirmaDistributie <unsigned>
{
 public:
void adaugaFilm(film T)
{
    Filme.push_back(T);
    nrPersoane = nrPersoane + T.get_nrActori() + T.get_nrPersonal() + 1;
    nrActori = nrActori + T.get_nrActori();
    nrActoriPrinciali = nrActoriPrinciali + T.get_nrActoriPrincipali();
}

template <class Y> void adaugaPersoana(Y* a)
{
Pers.push_back(a);
}
 private:
vector <film> Filme;
unsigned nrPersoane=0;
unsigned nrActori=0;
unsigned nrActoriPrinciali=0;
vector <persoane> Pers;
};


int main()
{
regizor A(2,5,100);
cout<<A.getSuma();
}
