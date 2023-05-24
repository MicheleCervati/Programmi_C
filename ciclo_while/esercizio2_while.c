//calcolare la somma e la media dei numeri pari dopo che l'utente decide quanti numeri inserire
#include <stdio.h>

void main()
{
    int n, i = 1, j = 0, num;
    float somma = 0, media;

    printf("Quanti numeri vuoi inserire?        ");
    scanf("%d", &n);
    do
    {
        printf("inserisci il  %d numero: ", i);
        scanf("%d", &num);
        if(num % 2 == 0){
        somma = somma + num;
        j++;}
        n--;
        i++;
    } while (n > 0);

    media = somma / j;
    printf("La somma è %2f", somma);
    printf("La media è %2f", media);
}
