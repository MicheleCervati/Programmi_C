#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
PIPE

int fd[2];
pipe(fd);

Parent                     child
fd[0] -------------------> fd[1]
fd[1] -------------------> fd[0] per far comunicare padre al figlio
*/

/*
ESERCIZIO 1

il padre scrive un messaggio e il padre lo legge

*/

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{

    int fd[2]; // creo il vettore di 2 interi (file descriptor)

    if (pipe(fd) == -1) // se pipe ritorna -1 c'è stato un errore altrimenti la pipe è stata creata correttamente
    {
        printf("è stato generato un errore nella generazione della pipe");
        exit(1);
    }

    int p = fork();

    if (p < 0)
    {
        printf("Errore nella generazione del figlio");
        exit(1);
    }

    if (p > 0) // padre
    {
        printf("\nSono il padre PID = %d", getpid());

        close(fd[0]); // padre deve chiudere l'output della pipe

        const char *messaggio = "Buona fortuna";
        if (write(fd[1], messaggio, strlen(messaggio)) == -1) // se ritorna -1 c'e' un errore
        {
            printf("\nErrore di scrittura nella pipe");
            exit(1);
        }

        close(fd[1]);
        wait(); // bisogna mettere la wait così che non si rischia di avere un figlio zombie
    }
    else // figlio
    {
        char buffer[BUFFER_SIZE];
        printf("\nSono il figlio PID = %d", getpid());

        close(fd[1]); // figlio deve chiudere l'input dei dati
        int n = read(fd[0], buffer, BUFFER_SIZE);
        if (n == -1)
        {
            printf("Errore di lettura dalla pipe");
            exit(1);
        }
        else
        {
            buffer[n] = '\0';
            printf("\nmessaggio ricevuto: %s\n", buffer);
            close(fd[0]);
        }
    }

    return 0;
}