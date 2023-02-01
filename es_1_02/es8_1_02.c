#include <stdio.h>
#include <math.h>
// Progettare un algoritmo che risolve il seguente problema. Si desidera
// calcolare la somma delle radici quadrate di N valori numerici inseriti
// dall’utente, con N inserito in input.
// L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
// con un messaggio di errore quando viene inserito un numero che non
// permette di effettuare il calcolo (nel dominio dei numeri reali).

int main()
{
    int num;
    int quantiN;

    float radice, somma = 0;

    printf("Quanti numeri vuoi inserire: ");
    scanf("%d", &quantiN);
    for (int i = 0; i < quantiN; i++)
    {

        printf("Inserisci un valore di cui sommare la radice quadrata: ");
        scanf("%d", &num);
        if (num >= 0)
        {
            radice = sqrt(num);
            somma = somma + radice;
        }
        else
        {
            printf("\nHai inserito un numero che non permette di calcolare la radice\n");
            i = quantiN;
        }
    }

    printf("\nLa somma delle radici dei numeri inseriti fin ora è %f\n", somma);
    return 0;
}