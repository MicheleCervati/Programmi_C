#include <stdio.h>

/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/

int main(int argc, char *argv[])
{

    int num1, num2;
    int prodotto;
    int sommaProdotti = 0;

    do
    {
        printf("Inserisci il primo numero: ");
        scanf("%d", &num1);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &num2);

        prodotto = num1 * num2;
        sommaProdotti = sommaProdotti + prodotto;

        printf("Il prodotto dei 2 numeri è %d\n", prodotto);

    } while (num1 != 0 && num2 != 0);

    printf("La somma di tutti i prodotti calcolati fino ad adesso è %d\n\n", sommaProdotti);

    return 0;
}