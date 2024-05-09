#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    float media;
} student_t;

int main(int argc, char *argv[])
{
    int QuantiS = 3;
    student_t *arrayPuntatori[QuantiS];

    for (int k = 0; k < QuantiS; k++)
    {
        arrayPuntatori[k] = malloc(sizeof(student_t));
    }

    for (int i = 0; i < QuantiS; i++)
    {
        printf("Inserisci nome studente %d: ", i+1);
        scanf("%s", arrayPuntatori[i]->nome);

        printf("Inserisci cognome studente %d: ", i+1);
        scanf("%s", arrayPuntatori[i]->cognome);

        printf("Inserisci media studente %d: ", i+1);
        scanf("%f", &(arrayPuntatori[i]->media));
    }


    for(int i=0; i < QuantiS; i++){
        printf("Studente %d: %s %s media %f\n", i, arrayPuntatori[i]->nome, arrayPuntatori[i]->cognome, arrayPuntatori[i]->media);
    }

    for(int i=0; i < QuantiS; i++){
        free(arrayPuntatori[i]);
    }

    return 0;
}



