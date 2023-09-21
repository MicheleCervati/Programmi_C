/*Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
determini:
1) il massimo ed il minimo dei numeri pari inseriti;
2) il massimo ed il minimo dei numeri dispari inseriti;
3) le posizioni di inserimento dei numeri precedentemente determinati.*/

#include <stdio.h>

int main(int argc, char *argc[])
{
    int maxP, minP, maxD, minD, pmaxP, pminP, pmaxD, pminD;
    int numero;
    int i = 0;
    int N;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);

    int numeri[N];

    for (int j = 0; j < N; j++)
    {
        printf("Inserisci il %d numero: ", i);
        scanf("%d", numeri[j]);
    }

    maxP = numeri[0];
    minP = numeri[0];
    maxD = numeri[0];
    minD = numeri[0];
    pmaxP = 0;
    pminP = numeri[0];
    pmaxD = numeri[0];
    pminD = numeri[0];

    for (int k = 0; k < N - 1; k++)
    {
        numero = numeri[k]

            if (numero % 2 == 0)
        { // pari
            if (numero > maxP)
            {
                maxP = numero;
                pmaxP = k;
            }

            if (numero < minP)
            {
                minP = numero;
                pminP = k;
            }
        }
        else
        { // dispari
            if (numero > maxD)
            {
                maxD = numero;
                pmaxD = k;
            }
        }

        if (numeri[k + 1] > numero)
        {
        }
    }

    return 0;
}