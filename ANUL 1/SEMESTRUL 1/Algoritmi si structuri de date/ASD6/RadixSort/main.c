#include <stdio.h>
#include <stdlib.h>

int getMax(int v[], int n)
{
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

void countSort(int v[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (v[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (v[i]/exp)%10 ] - 1] = v[i];
        count[ (v[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        v[i] = output[i];
}

void radixsort(int v[], int n)
{
    int m = getMax(v, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(v, n, exp);
}

int main()
{
    int v[20], n , i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }
    radixsort(v, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
}
