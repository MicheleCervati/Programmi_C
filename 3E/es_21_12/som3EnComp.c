// Dopo aver letto N numeri reali calcolare la somma e la media dei numeri esterni all'intervallo tra 4 e 8 (estremi esclusi).
//cioè dei numeri minori di 4 e maggiori di 8
// Visualizzare a video i risultati

#include <stdio.h>

void main()
{
    float num, somma = 0, media;
    int n, cont = 0, cont2 = 0;
    printf("quanti numeri vuoi inserire? \n");
    scanf("%d", &n);
    while (cont < n)
    {
        printf("inserisci il %d° numero \n", cont + 1);
        scanf("%f", &num);
        cont++;
        if (num < 4 || num > 8)
        {
            somma = somma + num;
            cont2++;
        }
    }

    printf("La somma dei numeri è %.2f\n", somma);
    media = somma / cont2++;
    printf("La media invece risulta %.2f\n", media);
}