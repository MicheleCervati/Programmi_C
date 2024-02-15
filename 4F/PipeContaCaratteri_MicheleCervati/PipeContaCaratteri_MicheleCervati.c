
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //serve per la fork()
#include <sys/wait.h> //serve per la wait()
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{

    int p;
    int n;
    int fd[2]; // creo il vettore di 2 interi (file descriptor)

    if (pipe(fd) == -1) // se pipe ritorna -1 c'è stato un errore altrimenti la pipe è stata creata correttamente
    {
        printf("è stato generato un errore nella generazione della pipe");
        exit(1);
    }

    p = fork();

    if (p < 0)
    {
        printf("\nErrore nella generazione del figlio");
        exit(1);
    }

    if (p > 0) // padre
    {
        printf("\nSono il processo padre, il mio PID: %d", getpid());
        int fd2[2];
        if (pipe(fd2) == -1) // se pipe ritorna -1 c'è stato un errore altrimenti la pipe è stata creata correttamente
        {
            printf("è stato generato un errore nella generazione della pipe");
            exit(1);
        }

        close(fd[0]);
        close(fd2[0]);

        int p2;
        p2 = fork();
        if (p2 < 0)
        {
            printf("Errore");
            exit(1);
        }
        if (p2 > 0) // padre
        {
            FILE *FilePartenza = fopen("memoryProcess.txt", "rb");
            char stringBuffer[BUFFER_SIZE];
            while ((n = fread(stringBuffer, 1, sizeof(stringBuffer), FilePartenza)) > 0)
            {
                write(fd[1], stringBuffer, n);
                write(fd2[1], stringBuffer, n);
            }

            fclose(FilePartenza);
            close(fd[1]);
            close(fd2[1]);
            printf("Programma padre terminato");
        }
        else
        { // figlio 2
            
            close(fd2[1]);
            char carattereDaRicercare[1] = "o";
            char charBuffer[1];
            int contatoreCarattere = 0;
            while ((n = read(fd2[0], charBuffer, sizeof(charBuffer))) > 0)
            {
                if (strcmp(carattereDaRicercare, charBuffer))
                {
                    contatoreCarattere++;
                }
            }

            printf("\n\nSONO STATI CONTATI %d CARATTERI\n\n", contatoreCarattere);
        }
    }
    else // figlio
    {
       wait(NULL);
        close(fd[1]);
        char stringBuffer[BUFFER_SIZE];
        FILE *FileDestinazione = fopen("FileDestinazione.txt", "wb");

        while ((n = read(fd[0], stringBuffer, sizeof(stringBuffer))) > 0)
        {
            fwrite(stringBuffer, 1, n, FileDestinazione);
        }
        fclose(FileDestinazione);
        close(fd[0]);
        printf("Programma figlio terminato");
        exit(1);
    }

    return 0;
}