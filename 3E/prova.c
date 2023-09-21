
#include <stdio.h>

void main()
{
    printf("\npremere 1 per mostrare il contenuto dell array");
    printf("\npremere 2 per inserire un elemento in coda");
    printf("\npremere 3 per modificare un elemento, se presente");
    printf("\npremere 4 per eliminare un elemento, se presente");
    printf("\npremere 5 per ricercare un elemento");
    printf("\npremere 6 per inserire un elemento in una certa posizione");
    printf("\npremere 7 per mostrare il contenuto dell'array all'inverso");
    printf("\npremere 1 per mostrare il contenuto dell array");
    printf("\npremere 0 per terminare");

    int numScelto;

    do(
        printf("\nInserisci la tua scelta: ");
        scanf("%d", &numScelto);
    )while(numScelto < -1 || numScelto > 8);

  
}