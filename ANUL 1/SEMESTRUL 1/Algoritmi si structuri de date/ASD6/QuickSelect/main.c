#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

int partition(int v[], int l, int r)
{
    int x = v[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (v[j] <= x) {
            swap(&v[i], &v[j]);
            i++;
        }
    }
    swap(&v[i], &v[r]);
    return i;
}
int kelement(int v[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
        {

        int index = partition(v, l, r);
        if (index - l == k - 1)
            return v[index];
        if (index - l > k - 1)
            return kelement(v, l, index - 1, k);
        return kelement(v, index + 1, r,  k - index + l - 1);
    }

}


int main()
{
    int v[20], i, n, k;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
    scanf("%d", &k);
    printf("%d", kelement(v, 0, n - 1, k));
    return 0;
}





