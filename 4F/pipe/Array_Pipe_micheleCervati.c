/*Creare un programma in C che rispetta i seguenti requisiti:
- genera un processo figlio
- padre e figlio si identificano
- il figlio chiede all'utente di inserire cinque numeri e li memorizza in un array
- il figlio, tramite una pipe, inoltra l'array al padre
- il padre stampa i numeri ricevuti dopo averli moltiplicati per un numero inserito dall'utente e chiesto dal padre stesso.*/

/*
int fd[2];
pipe(fd);

Parent                     child
fd[0] -------------------> fd[1]
fd[1] -------------------> fd[0] per far comunicare padre al figlio*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //serve per la fork()
#include <sys/wait.h> //serve per la wait()

#define QuantiN 5
#define BUFFER_SIZE 1024

int main()
{

    int p;

    p = fork();
    int arr[QuantiN];

    int fd[2]; // creo il vettore di 2 interi (file descriptor)

    if (pipe(fd) == -1) // se pipe ritorna -1 c'è stato un errore altrimenti la pipe è stata creata correttamente
    {
        printf("è stato generato un errore nella generazione della pipe");
        exit(1);
    }

    if (p < 0)
    {
        printf("\nErrore nella generazione del figlio");
        exit(1);
    }
    else if (p > 0) // padre
    {
        printf("\nSono il processo padre, il mio PID: %d", getpid());

        int moltiplicatore;

        close(fd[1]); // padre deve chiudere l'input dei dati
        int n;
        for (int i = 0; i < QuantiN; i++)
        {
            n = read(fd[0], &arr[i], 4);
            if (n == -1)
            {
                printf("Errore di lettura dalla pipe");
                exit(1);
            }
        }
wait(NULL);
        printf("\nQual' e' il fattore di moltiplicazione? ");
        scanf("%d", &moltiplicatore);

        for (int i = 0; i < QuantiN; i++)
        {
            printf("\nnumero %d: %d\n", i + 1, arr[i]*2);
        }

        close(fd[0]);
    }
    else // figlio
    {
        printf("\nSono il processo figlio, il mio PID: %d", getpid());
        for (int i = 0; i < QuantiN; i++)
        {
            printf("\nInserisci il %d numero: ", i + 1);
            scanf("%d", &arr[i]);
        }

        close(fd[0]);

        for (int i = 0; i < QuantiN; i++)
        {
            if (write(fd[1], &arr[i], 4) == -1) // se ritorna -1 c'e' un errore
            {
                printf("\nErrore di scrittura nella pipe");
                exit(1);
            }
        }

        close(fd[1]);
    }

    return 0;
}