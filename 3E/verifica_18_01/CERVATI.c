#include <stdio.h>

/*Scrivere un programma in c che permetta di inserire dei numeri interi in input da tastiera. L’inserimento
termina quando la somma dei numeri inseriti supera il valore pari a 20.
Visualizzare a video:
1) La somma e la media effettiva dei numeri inseriti;
2) quanti numeri maggiori di 7 sono stati inseriti;
3) la media dei numeri pari e di quelli dispari (tra quelli inseriti);*/

void main()
{
    int num; //numero inserito dall'utente
    int somma = 0; //somma di tutti i numeri inseriti dall'utente
    float mediaTot; //media di tutti i numeri inseriti dall'utente
    int i = 0; //contatore per determianre quanti numeri sono stati inseriti dall'utente
    int j = 0; //contatore per determinare quanti numeri > 7 sono stati inseriti
    int pari = 0, dispari = 0; //contatori di quanti numeri pari e dispari sono stati inseriti
    int sommaPari = 0, sommaDispari = 0; //somma di tutti i numeri pari e dispari inseriti dall'utente
    float mediaPari = 0, mediaDispari = 0; //media di tutti i numeri pari e dispari inseriti dall'utente

    do
    {
        i++;
        printf("Inserisci un numero: "); //input numero
        scanf("%d", &num);
        somma = somma + num;
        if (num > 7) //se il numero è maggiore di 7 incrementa il contatore
        {
            j++;
        }

        if (num % 2 == 0) //per verificare se il numero è pari oppure dispari
        {
            pari++;
            sommaPari = sommaPari + num;
        }
        else
        {
            dispari++;
            sommaDispari = sommaDispari + num;
        }
    } while (somma < 21); //il ciclo si ripete fin quando la somma non supera 20

    mediaTot = somma / i; //calcolo media
    if (sommaPari != 0) //controllo per verificare se la somma dei numeri pari e dispari è diversa da 0 perchè altrimenti non si può calcolare la media
    {
        mediaPari = sommaPari / pari;
    }
    if (sommaDispari != 0)
    {
        mediaDispari = sommaDispari / dispari;
    }
    printf("\nLa somma di tutti i numeri inseriti è %d\n", somma); //output dati
    printf("La media dei numeri inseriti è %f\n", mediaTot);
    printf("Sono stati inseriti %d numeri maggiori di 7\n", j);
    printf("La media dei numeri pari inseriti è %f\n", mediaPari);
    printf("La media dei numeri dispari inseriti è %f\n", mediaDispari);
}