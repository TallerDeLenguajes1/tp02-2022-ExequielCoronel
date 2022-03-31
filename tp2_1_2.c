#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void main()
{
    srand((int)time(NULL));
    int i;
    int vt[N], *Pvt;
    Pvt = &vt[0];

    for (i = 0; i < N; i++)
    {
        *Pvt = 1 + rand() % 100;
        printf("%d", *Pvt);
        Pvt++;
    }
}