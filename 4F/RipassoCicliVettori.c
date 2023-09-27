/*
Scrivi il codice sorgente di un programma che
_ chiede all&#39;utente di fornire in ingresso due numeri interi, limite1 e limite2, compresi tra 30 e 50
_ visualizza i valori di limite1 e limite2 solo qualora rispettino la consegna
_ chiede all&#39;utente di fornire in ingresso cinque numeri interi che verranno salvati in un vettore n[ ]
_ visualizzare il contenuto del vettore
_ se nel vettore sono presenti numeri compresi tra limite1 e limite2, allora visualizzarne l’indice e la
posizione in cui si trovano all’interno del vettore stesso
_ calcola la somma dei soli numeri, tra i cinque interi inseriti nel vettore, che sono compresi tra limite1 e
limite2
_ visualizza il valore della variabile somma

Vincoli:
_ rispettare i nomi delle variabili
_ inserire messaggi chiari per l&#39;utente
_ commentare adeguatamente il codice

VARIANTE:
 i valori limite1 e limite2 non sono più compresi tra 30 e 50 ma tra due numeri inseriti dall'utente dalla linea di comando.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int limite1 = 0;
    int limite2 = 0;
    int quantiN = 5;
    int n[quantiN];
    int somma = 0;
    int k=0;
  

    if (argc != 3)
    {
        printf("Non sono stati inseriti i parametri corretti\n");
        exit(0);
    }

    limite1 = atoi(argv[1]);
    limite2 = atoi(argv[2]);
    printf("Il limite minimo è %d\n", limite1);
    printf("Il limite massimo è %d\n", limite2);

    // Inserimento numeri nel vettore
    printf("Inserisci 5 numeri compresi tra i 2 limiti\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d", &n[i]);
    }

    // visualizzo contenuto vettore n
    printf("contenuto vettore: \n");
    for (int i = 0; i < quantiN; i++)
    {
        printf("Elemento %d di n: %d\n", i, n[i]);
    }

    // visualizzo contenuto vettore n con solo i contenuti compresi tra i limiti
    printf("Contenuto vettore compreso nei limiti: \n");
    for (int i = 0; i < quantiN; i++)
    {
        if (n[i] > limite1 && n[i] < limite2)
        {
            printf("Elemento %d di n: %d\n", i, n[i]);
            somma = somma + n[i]; //calcolo della somma
        }
    }


    printf("\nLa somma dei numeri compresi tra limite1 e limite2 vale %d\n", somma);

}