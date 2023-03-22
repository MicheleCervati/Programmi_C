/*
    Dato N un numero intero positivo, generare e visualizzare il numero successivo.
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
    int n = atoi(argv[1]);
    if (n < 0)
    {
        printf("Il numero deve essere positivo.\n");
        exit(0);
    }
    printf("Il numero successivo a %d è %d\n", n, n + 1);
    return 0;
}