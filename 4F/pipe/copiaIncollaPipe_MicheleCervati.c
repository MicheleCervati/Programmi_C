
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //serve per la fork()
#include <sys/wait.h> //serve per la wait()
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{

    int p;

    p = fork();

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
        close(fd[0]);

        FILE *FilePartenza = fopen("memoryProcess.txt", "r");
        char stringBuffer[BUFFER_SIZE];
        do
        {
            fread(stringBuffer, BUFFER_SIZE, BUFFER_SIZE, FilePartenza);
            write(fd[1], stringBuffer, BUFFER_SIZE);
        } while (strlen(stringBuffer) < BUFFER_SIZE);

        close(fd[1]);
        wait(NULL);
    }
    else // figlio
    {
        close(fd[1]);
        char stringBuffer[BUFFER_SIZE];
        FILE *FileDestinazione = fopen("FileDestinazione.txt", "w");
        
        
            read(fd[1], stringBuffer, BUFFER_SIZE);
        printf("%s", stringBuffer);
            read(fd[1], stringBuffer, BUFFER_SIZE);
        printf("\n\naaaaaaaaaaaa%s", stringBuffer);
        

        close(fd[0]);
    }

    return 0;
}