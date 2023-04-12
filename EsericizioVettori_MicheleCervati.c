/*Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
determini:
1) il massimo ed il minimo dei numeri pari inseriti;
2) il massimo ed il minimo dei numeri dispari inseriti;
3) le posizioni di inserimento dei numeri precedentemente determinati.*/

#include <stdio.h>
#include <limits.h>


int main(int argc, char *argv[])
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
        printf("Inserisci il %d numero: ", j+1);
        scanf("%d", &numeri[j]);
    }

    maxP = -INT_MAX; // massimo pari
    minP = INT_MAX;

    maxD = -INT_MAX;
    minD = INT_MAX;
    pmaxP = -1; // posizione massimo pari
    pminP = -1;
    pmaxD = -1;
    pminD = -1;

    for (int k = 0; k < N ; k++)
    {
        numero = numeri[k];

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
            
            if (numero < minD)
            {
                minD = numero;
                pminD = k;
            }
        }
    }

    printf("\nIl numero pari maggiore inserito e': %d\n", maxP);
    printf("Il numero dispari maggiore inserito e': %d\n", maxD);
    printf("Il numero pari maggiore si trova alla posizione: %d\n", pmaxP);
    printf("Il numero dispari maggiore si trova alla posizione e': %d\n", pmaxD);

    printf("Il numero pari minore inserito e': %d\n", minP);
    printf("Il numero dispari minore inserito e': %d\n", minD);
    printf("Il numero pari minore si trova alla posizione e': %d\n", pminP);
    printf("Il numero dispari minore si trova alla posizione e': %d\n", pminD);

    return 0;
}