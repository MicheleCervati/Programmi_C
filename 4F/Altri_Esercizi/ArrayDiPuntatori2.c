#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    float media;
} student_t;

void Stampa(student_t *ArrayPuntatori[], int quantiS)
{

    for (int i = 0; i < quantiS; i++)
    {
        printf("Studente %d: %s %s media %f\n", i, ArrayPuntatori[i]->nome, ArrayPuntatori[i]->cognome, ArrayPuntatori[i]->media);
    }
}

void Inserisci(student_t *ArrayPuntatori[], int quantiS)
{

    for (int i = 0; i < quantiS; i++)
    {
        printf("Inserisci nome studente %d: ", i + 1);
        scanf("%s", ArrayPuntatori[i]->nome);

        printf("Inserisci cognome studente %d: ", i + 1);
        scanf("%s", ArrayPuntatori[i]->cognome);

        printf("Inserisci media studente %d: ", i + 1);
        scanf("%f", &ArrayPuntatori[i]->media);
    }
}

void Libera(student_t *ArrayPuntatori[], int quantiS){

    for (int i = 0; i < quantiS; i++)
    {
        free(ArrayPuntatori[i]);
    }
}

int main(int argc, char *argv[])
{
    int QuantiS = 3;
    student_t *arrayPuntatori[QuantiS];

    for (int k = 0; k < QuantiS; k++)
    {
        arrayPuntatori[k] = malloc(sizeof(student_t));
    }

    Inserisci(arrayPuntatori, QuantiS);

    Stampa(arrayPuntatori, QuantiS);

    Libera(arrayPuntatori, QuantiS);


    return 0;
}
