/*Esercizio Struct
Definisci la struttura dati per la creazione di un punto con le sue coordinate, x, y, z, offrendo all’utente la
possibilità di vederne visualizzati i valori: crea un’apposita funzione stampa_punto().
Scrivi il codice sorgente di una funzione, punto_modificato(), per la creazione di un ulteriore punto le cui
coordinate abbiano un valore incrementato di una unità rispetto al precedente punto e visualizzale.
Avvalersi dell’uso delle funzioni e del passaggio di parametri per valore.*/

#include <stdio.h>

typedef struct
{
    int x;
    int y;
    int z;
} Posizione;

void stampa_punto(Posizione punto)
{
    printf("\nX: %d\n", punto.x);
    printf("Y: %d\n", punto.y);
    printf("Z: %d\n", punto.z);
}

Posizione punto_modificato(Posizione punto)
{
    Posizione punto2;
    punto2.x = punto.x + 1;
    punto2.y = punto.y + 1;
    punto2.z = punto.z + 1;
    //stampa_punto(punto2);

    return punto2;
}

int main(int argc, char *argv[])
{
    Posizione pos1;
    pos1.x = 5;
    pos1.y = 8;
    pos1.z = 15;
    stampa_punto(pos1);

    Posizione punto2 = punto_modificato(pos1);
    stampa_punto(punto2);
 

    return 0;
}