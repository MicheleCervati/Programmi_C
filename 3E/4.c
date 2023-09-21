/*
    Dato N un numero intero positivo, generare e visualizzare in ordine
    crescente i numeri pari minori o uguali a N.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore negli argomenti.\n");
        exit(0);
    }
    int n = atoi(argv[1]), i = 0;
    if (n < 0)
    {
        printf("Il numero deve essere positivo.\n");
        exit(0);
    }
    printf("I numeri pari minori o uguali a %d sono: ", n);
    do
    {
        printf("\n%d", i);
        i += 2;
    } while (i <= n);
    printf("\n");
    return 0;
}