// scrivi un programma in c che dopo aver chiesto all'utente quanti numeri inserire calcolare la somma e la media dei numeri maggiori di 5 e poi manda
// a video i risultati

#include <stdio.h>

void main()
{
    int n, i = 1, j = 0;
    float somma = 0, num, media;

    printf("Quanti numeri vuoi inserire?        ");
    scanf("%d", &n);
    do
    {
        printf("inserisci il  %d numero: ", i);
        scanf("%f", &num);
        if (num > 5)
        {
            somma = somma + num;
            j++;
        }
        n--;
        i++;
    } while (n > 0);

    media = somma / j;
    printf("La somma è %2f", somma);
    printf("La media è %2f", media);
}