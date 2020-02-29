#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}



void heap(int v[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && v[l] > v[largest])
		largest = l;
	if (r < n && v[r] > v[largest])
		largest = r;

	if (largest != i)
	{
		swap(&v[i], &v[largest]);
        heap(v, n, largest);
	}
}

void heapSort(int v[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(v, n, i);

	for (int i=n-1; i>=0; i--)
	{
		swap(&v[0], &v[i]);
		heap(v, i, 0);
	}
}



int main()
{
	int v[20], i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }

	heapSort(v, n);

	for(i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
}
