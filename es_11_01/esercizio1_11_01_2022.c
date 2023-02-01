#include <stdio.h>

//1) Dopo aver letto N numeri reali calcolare la somma e la media dei numeri pari maggiori di 5 visualizzando a video i risultati .

void main()
{
    int i = 0; // contatore
    float somma = 0, media;
    int num, altriN=0;

    do
    {
        
        printf("Inserisci un numero da sommare");
        scanf("%d", &num);
        printf("Vuoi inserire altri numeri? (premi 1 per si, 0 per no)");
        scanf("%d", &altriN);
        if (num % 2 == 0 && num > 5)
        {
            somma = somma + num;
            i++;
        }
    } while (altriN == 1);

        media = somma / i;

        printf("La somma è %f\n", somma);
        printf("La media è %f\n", media);
}