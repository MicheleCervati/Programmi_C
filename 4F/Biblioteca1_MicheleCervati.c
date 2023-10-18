/*Creare una biblioteca (3 libri) dove ogni libro ha un titolo, un autore e un prezzo; queste tre caratteristiche sono introdotte dall'utente.
Realizzare:
-1 un metodo per inserire i valori scelti dall'utente;

-2 un metodo per stampare il contenuto della bilblioteca(titolo, autore, prezzo);

-3 un metodo per applicare uno sconto al prezzo dei libri (il metodo riceve lo sconto in ingresso, per esempio 10% e sconta tutti
i libri del 10%. Questo sconto è inserito dall'utente).

Nel main chiamare i metodi1,2.3 e ancora 1 per vedere se lo sconto è stato applicato correttamente.
NELL'IMPLEMENTAZIONE E' OBBLIGATORIO L'UTILIZZO DEI PUNTATORI*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLIBRI 3

typedef struct
{
    char titolo[30];
    char autore[30];
    float prezzo;
} Biblioteca;

float InserisciSconto(){
    float sconto;
    printf("\nDi quanto deve essere lo sconto: ");
    scanf("%f", &sconto);
    return sconto;
}

int ApplicaSconto(Biblioteca *bibl[], float sconto){
    for(int i = 0; i < MAXLIBRI; i++){
        bibl[i]->prezzo = bibl[i]->prezzo - (bibl[i]->prezzo * sconto / 100);
    }
    return 1;
}

int InserisciValori(Biblioteca *bibl[])
{

    for (int i = 0; i < MAXLIBRI; i++)
    {
        printf("\nInserisci titolo libro %d: ", i+1);
        scanf("%s", bibl[i]->titolo);
        printf("\nInserisci autore libro %d: ", i+1);
        scanf("%s", bibl[i]->autore);
        printf("\nInserisci prezzo libro %d: ", i+1);
        scanf("%f", &bibl[i]->prezzo);
    }

    return 1;
}

int StampaValori(Biblioteca *bibl[])
{
    for (int i = 0; i < MAXLIBRI; i++)
    {
        printf("\ntitolo libro %d: %s", i+1, bibl[i]->titolo);
        printf("\nautore libro %d: %s", i+1, bibl[i]->autore);
        printf("\nprezzo libro %d: %f", i+1, bibl[i]->prezzo);
    }

    return 1;
}


int main(int argc, char *argv[])
{

    Biblioteca *bibl[MAXLIBRI];

    for (int k = 0; k < MAXLIBRI; k++)
    {
        bibl[k] = malloc(sizeof(Biblioteca));
    }

    InserisciValori(bibl);
    StampaValori(bibl);
    ApplicaSconto(bibl, InserisciSconto());
    StampaValori(bibl);

    printf("\n\n");


    // if (InserisciValori(bibl) == 1)
    // {
    //     printf("\nInserimento andato a buon fine\n");
    // }

    // if (StampaValori(bibl) == 1)
    // {
    //     printf("\nStampa andata a buon fine\n");
    // }

    // if(ApplicaSconto(bibl, InserisciSconto()) == 1){
    //     printf("\nSconto applicato correttamente");
    // }

    // StampaValori(bibl);
}

