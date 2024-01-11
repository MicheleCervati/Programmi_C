#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/*Creare un programma in C che genera una sequenza di 10.000
numeri casuali e li memorizza in un array; i numeri generati devono appartenere
all’intervallo 1-500.
Nel programma il processo padre genera due figli e la suddivisione dei compiti deve essere come segue:
-         Il padre genera i 10.000 numeri casuali.
-         Il padre salva tutti i numeri casuali in un file con il formato indice_array : valore
-         Il padre ricerca all’interno dei primi 2000 numeri dell’array un numero X inserito dall’utente a linea di comando e stampa a video la coppia indice_array : valore per tutte le coppie trovate; la stampa di ogni coppia deve essere preceduta dal pid del processo.
-         I due figli svolgono lo stesso compito del punto precedente dividendosi il lavoro a metà (4000 ricerche ciascuno).*/

const int quantiN = 10000;

void generaNumeri(int arrayNumber[])
{
    for (int i = 0; i < quantiN; i++)
    {
        arrayNumber[i] = rand() % 501;
    }
}

void scriviSuFile(int arrayNumber[], FILE *fileDoveScrivere)
{
    for (int i = 0; i < quantiN; i++)
    {

        fprintf(fileDoveScrivere, "%d : %d\n", i, arrayNumber[i]);
    }
}

int main()
{
    int numeroX;
    int IntervalloPadre = 2000;
    int IntervalloFiglio1 = 4000;
    int IntervalloFiglio2 = 4000;

    printf("Inserisci il numero X: ");
    scanf("%d", &numeroX);

    int arrayNumber[quantiN];

    FILE *fileNumeri = fopen("fileNumeri.txt", "w");

    generaNumeri(arrayNumber);

    scriviSuFile(arrayNumber, fileNumeri);

    int p = fork();

    if (p == 0) // figlio1
    {
        for (int i = IntervalloPadre; i < IntervalloPadre + IntervalloFiglio1; i++)
        {
            if (arrayNumber[i] == numeroX)
            {
                printf("\nPID:%d, %d : %d\n", getpid(), i, arrayNumber[i]);
            }
        }
    }
    else if (p > 0) // padre
    {
        int f = fork();

        if (f == 0) // figlio2
        {
            for (int i = IntervalloPadre + IntervalloFiglio1; i < IntervalloPadre + IntervalloFiglio1 + IntervalloFiglio2; i++)
            {
                if (arrayNumber[i] == numeroX)
                {
                    printf("\nPID:%d, %d : %d\n", getpid(), i, arrayNumber[i]);
                }
            }
        }
        else if (f > 0) // padre
        {
            for (int i = 0; i < IntervalloPadre; i++)
            {
                if (arrayNumber[i] == numeroX)
                {
                    printf("\nPID:%d, %d : %d\n", getpid(), i, arrayNumber[i]);
                }
            }
        }
    }

    return 0;
}