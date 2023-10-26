#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 4

int main(int argc, char *argv[])
{
    FILE *origine;
    FILE *destinazione;

    int n;
    unsigned char buffer[BUFFER_DIM];

    if (argc != 3)
    { // NOMEFILE NOMEORIGINE NOMEDESTINAZIONE
        printf("Inseririe correttamente i parametri d'ingresso\n");
        exit(1);
    }

    // APERTUA FILE IN LETTURA
    origine = fopen(argv[1], "r");
    if (origine == NULL)
    {
        printf("Errore apertura file origine\n");
        exit(1);
    }

    n = fread(buffer, 1, BUFFER_DIM, origine); // va nel file e legge 1024 byte 1 a 1 (secondo parametro) e lo insrisce nel buffer. IN N RESTITUISCE QUANTI CARATTERI HA COPIATO NEL BUFFER

    for(int i=0; i < BUFFER_DIM; i++){
        printf("%c", buffer[i]);
    }

    fclose(origine);
}
