
#include <stdio.h>

/*

Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.

*/

int main(int argc, char *argv[])
{
    int num1, num2;
    float rapporto;
    do
    {
        printf("Inserisci una coppia di numeri\n");
        printf("Inserisci primo numero: ");
        scanf("%d", &num1);
        printf("Inserisci secondo numero: ");
        scanf("%d", &num2);

        if (num1 > num2)
        {
            rapporto = (float)num2 / num1;
        }
        else
        {
            rapporto = (float)num1 / num2;
        }

        printf("Il rapporto tra il minore e il maggiore dei 2 numeri inseriti è %f\n",  rapporto);
    } while (num1 != 0 && num2 != 0);

    return 0;
}