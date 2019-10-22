#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

struct Stare {
    string eticheta;
    vector<pair<char, int>> listaTranzitii;
};

struct ElTabelMultimi {
    int *pVector;
};

struct ElTabelAFD {
    char eticheta;
    int *multime;
};

struct Automat {
    Stare *stari = NULL;
    int nrStari = 0;
    int nrStariFinale = 0;
    int *stariFinale = NULL;
    int nrLitere = 0;
    char *litere = NULL;
};

void citire(Automat &automat) {
    ifstream f("date2.in");
    int indexStareInceput, indexStareSfarsit, nrTranzitii;
    char literaTranzitie;

    f >> automat.nrStari >> nrTranzitii >> automat.nrStariFinale;
    automat.stariFinale = new int[automat.nrStariFinale + 1];
    for (int i = 0; i < automat.nrStariFinale; i++) f >> automat.stariFinale[i];

    f >> automat.nrLitere;
    automat.litere = new char[automat.nrLitere];
    for (int i = 0; i < automat.nrLitere; i++) f >> automat.litere[i];


    automat.stari = new Stare[automat.nrStari];

    for(int i = 0; i < automat.nrStari; i++) {
        automat.stari[i].listaTranzitii.push_back(make_pair('~', i));
    }

    for (int i = 0; i < nrTranzitii; i++) {
        f >> indexStareInceput >> literaTranzitie >> indexStareSfarsit;

        automat.stari[indexStareInceput].listaTranzitii.push_back(make_pair(literaTranzitie, indexStareSfarsit));
        automat.stari[indexStareInceput].eticheta = to_string(indexStareInceput);
    }
}

void afisare(Automat automat) {
    for (int i = 0; i < automat.nrStari; i++) {
        cout << "(" << i << ")" << ":";
        for (int j = 0; j < automat.stari[i].listaTranzitii.size(); j++) {
            cout << "(" << automat.stari[i].listaTranzitii.at(j).first << ", " << automat.stari[i].listaTranzitii.at(j).second << ") ";
        }
        cout << endl;
    }
    cout << "Stari finale: ";
    for (int i = 0; i < automat.nrStariFinale; i++) {
        cout << "(" <<automat.stariFinale[i] << ")" <<' ';
    }
}

void reuniuneMultimi(int *a, int *b, int *&rezultat, int marime) {
    for (int i = 0; i < marime; i++) {
        if (a[i] == 1 || b[i] == 1) {
            rezultat[i] = 1;
        }
    }
}

int comparareMultimi(int *a, int *b, int marime) {
    for (int i = 0; i < marime; i++) {
        if(a[i] != b[i])
            return -1;
    }
    return 1;
}

bool inchidereLambdaRecursie(int indexStare, int nrStari, Stare *stari, int *&inchidereLambda) {
    for (int i = 0; i < stari[indexStare].listaTranzitii.size(); i++) {
        if(stari[indexStare].listaTranzitii[i].first == '~' && stari[indexStare].listaTranzitii[i].second != indexStare) {
            inchidereLambda[stari[indexStare].listaTranzitii[i].second] = 1;
            if(inchidereLambdaRecursie(stari[indexStare].listaTranzitii[i].second, nrStari, stari, inchidereLambda)) {
                return true;
            }
        }
    }
}

void inchidereLambda(int indexStare, int nrStari, Stare *stari, int *&inchidereLambda) {
    inchidereLambdaRecursie(indexStare, nrStari, stari, inchidereLambda);
    inchidereLambda[indexStare] = 1;
}

void inchidereLitera(int indexStare, Stare *stari, int *&inchidereLitera, char litera) {
    for(int i = 0; i < stari[indexStare].listaTranzitii.size(); i++) {
        if(stari[indexStare].listaTranzitii[i].first == litera) {
            inchidereLitera[stari[indexStare].listaTranzitii[i].second] = 1;
        }
    }
}

int *inchidereLambdaLiteraLambda(int indexStare, int nrStari, Stare *stari, char litera) {

    int *inchidereLam = new int[nrStari]();
    int *inchidereLit = new int[nrStari]();
    int *inchidere = new int[nrStari]();

    inchidereLambda(indexStare, nrStari, stari, inchidereLam);

    for(int i = 0; i < nrStari; i++) {
        if(inchidereLam[i] == 1) {
            inchidereLitera(i, stari, inchidereLit, litera);
        }
    }

    for(int i = 0; i < nrStari; i++) {
        if(inchidereLit[i] == 1) {
            inchidereLambda(i, nrStari, stari, inchidere);
        }
    }

    return inchidere;

}

void AfnLambdaInAfd(Automat AFN, Automat &AFD) {
    /// tabelul pentru AFN ///
    ElTabelMultimi tabel[AFN.nrStari][AFN.nrLitere];
    for (int i = 0; i < AFN.nrStari; i++) {
        for (int j = 0; j < AFN.nrLitere; j++) {
            tabel[i][j].pVector = inchidereLambdaLiteraLambda(i, AFN.nrStari, AFN.stari, AFN.litere[j]);
        }
    }


    /// tabel AFD ///
    ElTabelAFD tabelAFD[50][10];
    ElTabelAFD elementInitial;
    list<ElTabelAFD> elementeNoi;
    int indexLinie = 0;
    AFD.stariFinale = new int[AFN.nrStari]();
    char et = '0';

    elementInitial.eticheta = et++;
    elementInitial.multime = new int[AFN.nrStari];
    inchidereLambda(0, AFN.nrStari, AFN.stari, elementInitial.multime);
    elementeNoi.push_back(elementInitial);

    while(!elementeNoi.empty()) {
        ElTabelAFD elementNou = elementeNoi.front();
        tabelAFD[indexLinie][0] = elementNou;
        elementeNoi.pop_front();

        for(int i = 0; i < AFN.nrLitere; i++) {
            // Initializam un nou element pentru litera i din tabel
            ElTabelAFD elementPentruLitera;
            elementPentruLitera.multime = new int[AFN.nrStari]();

            for(int j = 0; j < AFN.nrStari; j++) {
                if(elementNou.multime[j] == 1) {
                    reuniuneMultimi(elementPentruLitera.multime, tabel[j][i].pVector, elementPentruLitera.multime, AFN.nrStari);
                }
            }

            int existent = 0;
            for(int j = 0; j < indexLinie + 1; j++) {
                if(comparareMultimi(tabelAFD[j][0].multime, elementPentruLitera.multime, AFN.nrStari) == 1) {
                    elementPentruLitera.eticheta = tabelAFD[j][0].eticheta;
                    existent = 1;
                }
            }

            for(ElTabelAFD x : elementeNoi) {
                if(comparareMultimi(x.multime, elementPentruLitera.multime, AFN.nrStari) == 1) {
                    elementPentruLitera.eticheta = x.eticheta;
                    existent = 1;
                }
            }

            if(existent == 0) {
                elementPentruLitera.eticheta = et++;
                elementeNoi.push_back(elementPentruLitera);
            }

            tabelAFD[indexLinie][i+1] = elementPentruLitera;

        }

        indexLinie++;

    }

    /// Cream AFD-ul
    AFD.nrLitere = AFN.nrLitere;
    AFD.litere = AFN.litere;
    AFD.nrStari = indexLinie;
    AFD.stari = new Stare[AFD.nrStari];
    AFD.nrStariFinale = 0;

    int tempStariFinale[AFN.nrStari] = {0};

    /// Setam numele Starilor
    for(int i = 0; i < AFD.nrStari; i++) {
        AFD.stari[i].eticheta = tabelAFD[i][0].eticheta;
    }

    /// Setam tranzitiile
    for(int i = 0; i < AFD.nrStari; i++) {
        for(int j = 1; j <= AFD.nrLitere; j++) {
            AFD.stari[i].listaTranzitii.push_back(make_pair(AFD.litere[j-1], tabelAFD[i][j].eticheta - '0'));
        }
    }
        int elementMultime;
    /// Setam starile finale ale AFD-ului
    for(int i = 0; i < indexLinie; i++) {
        for(int j  = 0; j < AFN.nrStari; j++) {
            if(tabelAFD[i][0].multime[j] == 1) {
                elementMultime = j;
            }
            else elementMultime = -1;
            for(int k = 0; k < AFN.nrStariFinale; k++) {
                if(AFN.stariFinale[k] == elementMultime) {
                    tempStariFinale[i] = 1;
                }
            }
        }
    }

    int index = 0;
    for(int i = 0; i < AFD.nrStari; i++) {
        if(tempStariFinale[i] == 1) {
            AFD.nrStariFinale++;

        }
    }
    for(int i = 0; i < AFD.nrStari; i++) {
        if(tempStariFinale[i] == 1) {
            AFD.stariFinale[index++] = i;

        }
    }
}

int main() {
    Automat AFD, AFN;
    citire(AFN);
    AfnLambdaInAfd(AFN, AFD);
    afisare(AFD);
}
