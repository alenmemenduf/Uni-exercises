// Fie 4 puncte din R^2, oricare 3 necoliniare
// daca cele 4 puncte au acoperire convexa, dar nu e convex
// In caz afirmativ, sa se studieze pozitia punctului A[3] fata de
// cercul circumscris triunghiului A[0]-A[1]-A[2]
//      daca suma unghiurilor A[1] si A[3]
//              -formeaza 180 grade                     ////    A[3] apartine cercului
//              -formeaza mai mult de 180 de grade      ////    A[3] e in interiorul cercului
//              -formeaza mai putin de 180 de grade     ////    A[3] e in exteriorul cercului

#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159265359

struct punct
{
    double x, y;
}A[4];

int peSegment(punct a, punct q, punct b) //daca q apartine peSegment ab
{
    if(q.x <= max(a.x, b.x) &&
       q.x >= min(a.x, b.x) &&
       q.y <= max(a.y, b.y) &&
       q.y >= min(a.y, b.y))
        return 1;
    return 0;
}
double distanta(punct A, punct B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+
                (A.y-B.y)*(A.y-B.y));
}

double cosin(punct B, punct A, punct C) // produs vectorial
{
    punct AB, AC;
    double produs;

    AB.x = B.x - A.x;
    AB.y = B.y - A.y;

    AC.x = C.x - A.x;
    AC.y = C.y - A.y;

    produs = AB.x * AC.x + AB.y * AC.y;
    return produs / (distanta(A, B) * distanta(A, C));

}

int main()
{
    cout << "Punctele sunt: ";
    double aux1, aux2, x, y;
    for(int i=0; i<4; i++)
        cin >> A[i].x >> A[i].y;

    //Segment A0A2 - Ecuatie prima Diagonala
    double a1, b1, c1;
    aux1 = A[2].x - A[0].x;
    aux2 = A[2].y - A[0].y;
    a1 = aux2;
    b1 = -aux1;
    c1 = A[0].y * aux1 - A[0].x * aux2;

    //Segment A1A3 - Ecuatie a doua Diagonala
    double a2, b2, c2;
    aux1 = A[3].x - A[1].x;
    aux2 = A[3].y - A[1].y;
    a2 = aux2;
    b2 = -aux1;
    c2 = A[1].y * aux1 - A[1].x * aux2;

    //Verificam daca Diagonalele se Intersecteaza
    double det = a1 * b2 - b1 * a2;
    if(det != 0) //Patrulaterul este Convex = diagonalele se intersecteaza intr-un punct
    {
        aux1 = b2 * (-c1) + b1 * c2;
        x = aux1 / det;
        aux2 = a1 * (-c2) + c1 * a2;
        y = aux2 / det;

        punct cross;
        cross.x = x;
        cross.y = y;
        if(peSegment(A[0], cross, A[2]) && peSegment(A[1], cross, A[3]))
        {
            cout<<"Patrulaterul este Convex."<<endl;
            double unghi_A1, unghi_A3, unghi_format;
            unghi_A1 = acos(cosin(A[0], A[1], A[2]));
            unghi_A3 = acos(cosin(A[0], A[3], A[2]));
            unghi_format = (unghi_A1 + unghi_A3) * 180.0 / PI;
            if(unghi_format > 179.99 && unghi_format < 180.01) cout << "A3 este pe Cerc.";
            else if(unghi_format > 180) cout << "A3 este in interior.";
                else cout << "A3 este in exterior.";
        }
        else cout << "Patrulaterul nu e Convex." << endl;
    }
    else
        cout << "Patrulaterul nu e Convex." << endl;

    return 0;
}
