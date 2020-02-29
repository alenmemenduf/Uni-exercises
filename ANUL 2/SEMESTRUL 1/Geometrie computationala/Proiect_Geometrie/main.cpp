
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

struct Node
{
    double x;
    double y;
    bool convex;
    bool principal;
    Node(double a = 0, double b = 0): x(a), y(b), convex(true), principal(true) {};

};

struct Edge
{
    Node A;
    Node B;
};

bool peSegment(Node A, Node B, Node C)
{
    if (B.x <= max(A.x, C.x) && B.x >= min(A.x, C.x) &&
            B.y <= max(A.y, C.y) && B.y >= min(A.y, C.y))
        return true;
    return false;
}

int orientare(Node A, Node B, Node C)
{
    int rez = (B.y - A.y) * (C.x - B.x) -
              (B.x - A.x) * (C.y - B.y);
    if (rez == 0)
        return 0;
    else if (rez > 0)
        return 1; // clockwise
    else
        return 2; // counter-clockwise
}

int intersectie(Edge d1, Edge d2)
{
    double a1, b1, c1;
    double a2, b2, c2;

    // primul edge scris cu ecuatia dreptei a1x + b1x = c1
    a1 = d1.B.y - d1.A.y;
    b1 = d1.A.x - d1.B.x;
    c1 = a1 * (d1.A.x) + b1 * (d1.A.y);

    // al doilea edge scris cu ecuatia dreptei a2x + b2x = c2
    a2 = d2.B.y - d2.A.y;
    b2 = d2.A.x - d2.B.x;
    c2 = a2 * (d2.A.x) + b2 * (d2.A.y);

    double delta = a1 * b2 - a2 * b1; // |a1 b1| delta e determinant
    // |a2 b2|
    if (delta == 0)
    {
        //cazul in care matricea extinsa are rang 1 =====> segmentele pe aceeasi dreapta
        double detMatExtinsa[3];
        detMatExtinsa[0] = a1 * b2 - a2 * b1;
        detMatExtinsa[1] = a1 * (-c2) - a2 * (-c1);
        detMatExtinsa[2] = b1 * (-c2) - b2 * (-c1);

        if (!detMatExtinsa[0] &&
                !detMatExtinsa[1] &&
                !detMatExtinsa[2])
        {
            //cazurile in care intersectia reprezinta un segment (punctele sunt coliniare)
            if (peSegment(d1.A, d2.A, d1.B) && peSegment(d2.A, d1.B, d2.B))
                return 1;
            else if (peSegment(d1.A, d2.B, d1.B) && peSegment(d2.B, d1.B, d2.A))
                return 1;
            else if (peSegment(d1.B, d2.A, d1.A) && peSegment(d2.A, d1.A, d2.B))
                return 1;
            else if (peSegment(d1.B, d2.B, d1.A) && peSegment(d2.B, d1.A, d2.A))
                return 1;
            else if (peSegment(d1.A, d2.A, d1.B) && peSegment(d1.A, d2.B, d1.B))
                return 1;
            else if (peSegment(d2.A, d1.A, d2.B) && peSegment(d2.A, d1.B, d2.B))
                return 1;
            else
                return 0;
        }
        // cazul cand segmentele sunt paralele
        else
            return 0;
    }
    else
    {
        //cand au orientari diferite
        double x = (b2 * c1 - b1 * c2) / delta;
        double y = (a1 * c2 - a2 * c1) / delta;
        Node crossPoint(x, y);
        if (peSegment(d1.A, crossPoint, d1.B) && peSegment(d2.A, crossPoint, d2.B))
            return 1; //cand cele doua drepte se intersecteaza intr-un singur punct
        return 0;
    }
}

float sign (Node A, Node B, Node C)
{
    return (A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y);
}

bool PointInTriangle (Node pt, Node V1, Node V2, Node V3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;
    d1 = sign(pt, V1, V2);
    d2 = sign(pt, V2, V3);
    d3 = sign(pt, V3, V1);

    has_neg = (d1 < 0) && (d2 < 0) && (d3 < 0);
    has_pos = (d1 > 0) && (d2 > 0) && (d3 > 0);

    return (has_neg || has_pos);
}
int main()
{
    int i, j, n;
    double x, y;
    f >> n;
    Node* noduri = new Node[n];
    Edge* muchii = new Edge[n];

    for (i = 0; i < n; i++)
    {
        f >> x >> y;
        noduri[i].x = x;
        noduri[i].y = y;
    }
    //formam edge-urile
    for (i = 0; i < n - 1; i++)
    {
        muchii[i].A = noduri[i];
        muchii[i].B = noduri[i + 1];
    }
    muchii[n - 1].A = noduri[n - 1];
    muchii[n - 1].B = noduri[0];

// CONVEX SAU CONCAV
    for (i = 0; i < n; i++)
    {
        if (orientare(noduri[i], noduri[(i+1)%(n)], noduri[(i+2)%(n)]) == 1)
            noduri[(i+1)%n].convex = false;
    }
    for (i = 0; i < n; i++)
    {
        if (noduri[i].convex == true)
            cout << "Nodul " << i << " este convex" << endl;
        else
            cout << "Nodul " << i << " este concav" << endl;
    }

    // PRINCIPAL SAU NU
    int suma;
    Edge _muchie;

    // CAZ PENTRU NODUL 0
    suma = 0;
    _muchie.A = noduri[n-1];
    _muchie.B = noduri[1];
    for (j = 0; j < n; j++)
        suma += intersectie(_muchie, muchii[j]);
    if (suma > 4)
        noduri[0].principal = false;

    // CAZ PENTRU NODUL N-1
    suma = 0;
    _muchie.A = noduri[n-2];
    _muchie.B = noduri[0];
    for (j = 0; j < n; j++)
        suma += intersectie(_muchie, muchii[j]);
    if (suma > 4)
        noduri[n-1].principal = false;

    // RESTUL
    for (i = 1; i < n-1; i++)
    {
        suma = 0;
        _muchie.A = noduri[i-1];
        _muchie.B = noduri[i+1];
        for (j = 0; j < n; j++)
            suma += intersectie(_muchie, muchii[j]);
        if (suma > 4)
            noduri[i].principal = false;
    }

    for (i = 0; i < n-1; i++)
        for (j = 0; j < n; j++)
        {
            if (j!= i && j!= i+1 && j!= i+2)
            {
                if (PointInTriangle(noduri[j], noduri[i], noduri[(i+1)%n],noduri[(i+2)%n])==true)
                    noduri[(i+1)%n].principal = false;
            }
        }
    for (i = 0; i < n; i++)
        if (noduri[i].principal == true)
            cout << "Nodul " << i << " este principal" << endl;
        else
            cout << "Nodul " << i << " nu este principal" << endl;


    delete noduri;
    delete muchii;
    return 0;
};
