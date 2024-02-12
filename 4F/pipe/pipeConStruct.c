/*Creare un programma C dove il padre passa due variabili di tipo libro (STRUCT: titolo,autore e prezzo) al processo figlio che stampa
i dati così ricevuti.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //serve per la fork()
#include <sys/wait.h> //serve per la wait()
#include <string.h>

#define MAX_LUNGHEZZA_TITOLO 50
#define MAX_LUNGHEZZA_AUTORE 50

typedef struct
{
    char titolo[MAX_LUNGHEZZA_TITOLO];
    char autore[MAX_LUNGHEZZA_AUTORE];
    float prezzo;
} Libro;

int main()
{
    int p;

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
        close(fd[0]);
        Libro libro1;

        strcpy(libro1.titolo, "libro TPSIT");
        strcpy(libro1.autore, "Gianni");
        libro1.prezzo = 15;

        Libro libro2;
        strcpy(libro2.titolo, "libro Italiano");
        strcpy(libro2.autore, "Pino");
        libro2.prezzo = 15;

        write(fd[1], &libro1, sizeof(libro1));
        write(fd[1], &libro2, sizeof(libro2));
        close(fd[1]);
    }
    else if (p == 0) // figlio
    {
        close(fd[1]);
        Libro LibroBuffer;

        read(fd[0], &LibroBuffer, sizeof(LibroBuffer));
        printf("\n\nLibro1 titolo: %s, autore: %s, prezzo: %f", LibroBuffer.titolo, LibroBuffer.autore, LibroBuffer.prezzo);
        read(fd[0], &LibroBuffer, sizeof(LibroBuffer));
        printf("\n\nLibro1 titolo: %s, autore: %s, prezzo: %f\n", LibroBuffer.titolo, LibroBuffer.autore, LibroBuffer.prezzo);

        close(fd[0]);
    }
    return 0;
}