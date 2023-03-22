/*
    Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
    visualizzare in ordine crescente i numeri interi compresi
    nell'intervallo chiuso [N1,N2].
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore negli argomenti.\n");
        exit(0);
    }
    int n1 = atoi(argv[1]), n2 = atoi(argv[2]);
    if (n1 < 0 || n2 < 0)
    {
        printf("Entrami i numeri devono essere positivi.\n");
        exit(0);
    }
    if (n2 <= n1)
    {
        printf("Il terzo argomento deve essere maggiore del secondo.\n");
        exit(0);
    }
    printf("I numeri compresi tra %d e %d sono: ", n1, n2);
    for (int i = n1; i <= n2; i++)
    {
        printf("\n%d", i);
    }
    printf("\n");
    return 0;
}