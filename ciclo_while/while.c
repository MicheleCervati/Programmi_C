// Scrivere un programma in c che dopo aver richiesto all'utente quanti numeri inserire ne calcola la somma e la visualizzi a video

#include <stdio.h>

void main()
{
    int n, i = 1;
    float somma = 0, num, media;

    printf("Quanti numeri vuoi inserire?        ");
    scanf("%d", &n);
    do
    {
        printf("inserisci il  %d numero: ", i);
        scanf("%f", &num);
        somma = somma + num;
        n--;
        i++;
    } while (n > 0);

    media = somma / (i - 1);
    printf("La somma è %2f", somma);
    printf("La media è %2f", media);
}