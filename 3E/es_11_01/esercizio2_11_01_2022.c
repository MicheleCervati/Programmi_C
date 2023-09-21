#include <stdio.h>

/*Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:
            da 0 a 500€ sconto del 10%;
            da 501 a 1000 sconto del 20%;
            oltre i 1001 sconto 30%;
 Il programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire
 ulteriori somme di denaro.*/

void main()
{
    int i = 0; // contatore
    float somma = 0, soldi, sommaScontata = 0, sconto = 0;
    int altriN = 0;

    do
    {
        printf("Inserisci una somma di denaro: ");
        scanf("%f", &soldi);
        somma = somma + soldi;
        if (somma > 0 && somma < 500)
        {
            printf("La somma senza sconti è %f\n", somma);
            sconto = 0.1;
            printf("Lo sconto è %f percento\n", sconto*100);
            sommaScontata = somma - (somma * sconto);
            printf("La somma scontata è %f\n", sommaScontata);
        }
        else if (somma > 500 && somma < 1000)
        {
            printf("La somma senza sconti è %f\n", somma);
            sconto = 0.2;
            printf("Lo sconto è %f percento\n", sconto*100);
            sommaScontata = somma - (somma * sconto);
            printf("La somma scontata è %f\n", sommaScontata);
        }
        else if (somma > 1000)
        {
            printf("La somma senza sconti è %f\n", somma);
            sconto = 0.3;
            printf("Lo sconto è %f percento\n", sconto*100);
            sommaScontata = somma - (somma * sconto);
            printf("La somma scontata è %f\n", sommaScontata);
        }
        printf("Vuoi inserire altre somme di denaro? (premi 1 per si, 0 per no)");
        scanf("%d", &altriN);
    } while (altriN == 1);
}