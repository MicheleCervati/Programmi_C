#include <stdio.h>
#include <math.h>

/*Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Il programma prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo. */
int main(int argc, char *argv[])
{
    float num1, num2;
    float rapporto, radiceRapporto;

    do
    {

        printf("\nInserisci il primo numero \n");
        scanf("%f", &num1);
        printf("Inserisci il secondo numero \n");
        scanf("%f", &num2);
        if (num1 > num2)
        {
            rapporto = num1 / num2;
        }
        else
        {
            rapporto = num2 / num1;
        }
        if (rapporto >= 0)
        {
            radiceRapporto = sqrt(rapporto);
            printf("La radice del rapporto tra i 2 numeri è %f\n", radiceRapporto);
        }
    } while (rapporto > 0);

    printf("Il risultato della radice tra i 2 numeri non è nel campo dei numeri reali \n");
    return 0;
}