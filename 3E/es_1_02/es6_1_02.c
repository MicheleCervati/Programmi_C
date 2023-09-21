#include <stdio.h>
void main()
{
    int a, b, numero, somma, i=0;
    double media;

    do
    {
        printf("inserire il valore di a:\n");
        scanf("%f", &a);
        printf("inserire il valore di b:\n");
        scanf("%f", &b);
    } while (b < a);
    do
    {
        printf("inserisci un numero\n");
        scanf("%d", &numero);

        if (numero >= a && numero <= b)
        {
            somma = somma + numero;
            i++;
        }

    } while (numero >= a && numero <= b);
    media = (double)somma / (double)i;

    printf("\nla media è: %f\n", media);
}