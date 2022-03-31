#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7
void main()
{
    srand((int)time(NULL));
    int i, j;
    int mt[N][M], *Pmt;
    Pmt = &mt[0][0];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(Pmt + (i * M + j)) = 1 + rand() % 100;
            printf("%d", *(Pmt + (i * M + j)));
        }
        printf("\n");
    }
}