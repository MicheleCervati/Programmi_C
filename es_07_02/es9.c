// Progettare un algoritmo che risolva il seguente problema. Si richieda
// all’utente di inserire una serie di terne di dati numerici (A, B, C).
// Il programma deve terminare quando uno dei valori inseriti è minore di
// zero. Si scartino le terne nelle quali i valori non sono in ordine
// strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
// Su tutte le terne non scartate si calcoli il massimo e il minimo dei
// valori inseriti. Si stampino a video tali valori massimi e minimi prima
// di terminare il programma.

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    int max, min;
    int j = 0;
    do
    {
        printf("Inserisci una terna di numeri \n");
        printf("inserisci il primo numero A: ");
        scanf("%d", &a);
        printf("inserisci il secondo numero B: ");
        scanf("%d", &b);
        printf("inserisci il terzo numero C: ");
        scanf("%d", &c);

        if (a > b && b > c)
        {
            if (j == 0)
            {
                max = a;
                min = c;
                j++;
            }
            else
            {
                if (a > max)
                {
                    max = a;
                }
                if (c < min)
                {
                    min = c;
                }
            }
        }
    } while (a > 0 && b > 0 && c > 0);

    printf("Il valore massimo inserito è: %d\n", max);
    printf("Il valore minimo inserito è: %d\n", min);
}