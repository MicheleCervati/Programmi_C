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

int main(int argc, char *argv[])
{

    Studente *st1 = malloc(sizeof(Studente));

    int fd = open(argv[0], O_RDONLY);

    read(fd, st1, sizeof(Studente));

    printf("\nnome: %s, cognome: %s, eta: %d", st1->nome, st1->cognome, st1->eta);

    printf("\nProcesso 2 terminato");

    return 0;
}