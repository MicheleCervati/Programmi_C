#include <stdio.h>

//VERIFICA DI TPSIT LABORATORIO CERVATI MICHELE 10 MAGGIO 2023 FILA 3

void CercaCoppie(int numeri[], int N)
{

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if ((numeri[i] * 2) == numeri[k])
            {
                printf("\ncoppia trovata: ");
                printf("|%d ", numeri[i]);
                printf("%d|", numeri[k]);
            }
        }
    }
}

int InserisciN()
{
    int N;
    do
    {
        printf("Quanti numeri vuoi inserire all'interno dell'array: ");
        scanf("%d", &N);
    } while (N <= 0);

    return N;
}

void InserisciArray(int numeri[], int N)
{

    int i = 0;

    //=========Inserimento elementi all'interno dell'array numeri con controllo che siaqno positivi e diversi da 0==============
    do
    {
        printf("Inserisci il %d numero ", i + 1);
        scanf("%d", &numeri[i]);
        if (numeri[i] > 0)
        {
            i++;
        }
    } while (i < N);
}

int main(int argc, char *argv)
{

    int N = InserisciN(); // numero di elementi dell'array numeri

    int numeri[N];

    InserisciArray(numeri, N); //inserimento degli elementi all'interno dell'array

    CercaCoppie(numeri, N); //cerco le coppie di numeri nelle quali uno è il doppio dell altro

    printf("\n\n");

    return 0;
}