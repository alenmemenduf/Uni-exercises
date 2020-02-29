#include <iostream>
using namespace std;
/*
Se dau 4 puncte in R^2, distincte 2 cate 2 sa se determine intersectia dintre
segmentul format din primele 2 si segmentul format din urmatoarele 2.

*/

struct Punct{
    float x;
    float y;
	Punct(float a, float b) { x = a; y = b; };
};

int max(float a, float b) {
	return (a > b) ? a : b;
}
int min(float a, float b) {
	return (a < b) ? a : b;
}

void afisare(Punct a)
{
	cout << "punctul: (" << a.x << ","
		 << a.y << ")" << endl;
}

bool peSegment(Punct A, Punct B, Punct C)
{
	if (B.x <= max(A.x, C.x) && B.x >= min(A.x, C.x) &&
		B.y <= max(A.y, C.y) && B.y >= min(A.y, C.y))
		return true;

	return false;
}

Punct intersectie(Punct A, Punct B, Punct C, Punct D) {
	//segmentul AB scris ca a1x + b1y = c1
	float a1, b1, c1;
	float a2, b2, c2;

	a1 = B.y - A.y;
	b1 = A.x - B.x;
	c1 = a1 * (A.x) + b1 * (A.y);

	//segmentul CD scris ca a2x + b2y = c2
	a2 = D.y - C.y;
	b2 = C.x - D.x;
	c2 = a2 * (C.x) + b2 * (C.y);

	float delta = a1 * b2 - a2 * b1; // |a1 b1| delta e determinant
									 // |a2 b2|

	if (delta == 0) {

		//cazul in care matricea extinsa are rang 1 =====> segmentele pe aceeasi dreapta
		float detMatExtinsa[3];
		detMatExtinsa[0] = a1 * b2 - a2 * b1;
		detMatExtinsa[1] = a1 * (-c2) - a2 * (-c1);
		detMatExtinsa[2] = b1 * (-c2) - b2 * (-c1);

		if (!detMatExtinsa[0] ||
			!detMatExtinsa[1] ||
			!detMatExtinsa[2]){

			cout << "segmentele se afla pe aceeasi dreapta"<<endl;

			if (peSegment(A, C, B) && peSegment(C, B, D))
			{
				cout << "intersectia pe intervalul: [(" << C.x << "," << C.y << "),(" << B.x << "," << B.y << ")" << endl;
			}
			else if (peSegment(A, D, B) && peSegment(D, B, C))
			{
				cout << "intersectia pe intervalul: [(" << D.x << "," << D.y << "),(" << B.x << "," << B.y << ")" << endl;
			}
			else if (peSegment(B, C, A) && peSegment(C, A, D))
			{
				cout << "intersectia pe intervalul: [(" << C.x << "," << C.y << "),(" << A.x << "," << A.y << ")" << endl;
			}
			else if (peSegment(B, D, A) && peSegment(D, A, C))
			{
				cout << "intersectia pe intervalul: [(" << D.x << "," << D.y << "),(" << A.x << "," << A.y << ")" << endl;
			}
			else if (peSegment(A, C, B) && peSegment(A, D, B))
			{
				cout << "intersectia pe intervalul: [(" << C.x << "," << C.y << "),(" << D.x << "," << D.y << ")" << endl;
			}
			else if (peSegment(C, A, D) && peSegment(C, B, D))
			{
				cout << "intersectia pe intervalul: [(" << A.x << "," << A.y << "),(" << B.x << "," << B.y << ")" << endl;
			}
			else cout << "nu se intersecteaza" << endl;
		}

		// cazul cand segmentele sunt paralele
		else {
			cout << "segmentele sunt PARALELE" << endl;
		}

		Punct A(FLT_MAX, FLT_MAX);
		return A;
	}
	else {
		//cand au orientari diferite => nu sunt pe aceeasi dreapta sau paralele
		float x = (b2 * c1 - b1 * c2) / delta;
		float y = (a1 * c2 - a2 * c1) / delta;
		Punct crossPoint(x, y);
		if (peSegment(A, crossPoint, B) && peSegment(C, crossPoint, D))
			afisare(crossPoint);
		else cout << "segmentele nu au aceeasi orientare, dar NU se intersecteaza"<<endl;
	}
}

int main()
{
	Punct A(0, 0);
	Punct B(1, 1);
	Punct C(3, 3);
	Punct D(2, 2);
	Punct crossPoint = intersectie(A, B, C, D);


}
