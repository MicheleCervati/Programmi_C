/*Creare un processo P1 che:
 - crea un processo P2
 - passa a P2 dei dati relativi ad uno studente (nome,cognome,età)
 - P2 stampa i dati ricevuti
SUGGERIMENTI
- per passare i dati utilizzare una struct
- per creare P2 combinare fork con execl....*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct
{
    char nome[30];
    char cognome[30];
    int eta;
} Studente;

int main()
{
    Studente *st1 = malloc(sizeof(Studente));

    strcpy(st1->nome, "marco");
    strcpy(st1->cognome, "rossi");
    st1->eta = 15;

    int fd = open("FIFO", O_WRONLY);

    int p = fork();

    if (p == 0) // figlio
    {
        execl("./p2", "FIFO", NULL);
    }
    else
    {
        write(fd,st1,sizeof(Studente));
        printf("\nProcesso 1 terminato");
    }

    return 0;
}