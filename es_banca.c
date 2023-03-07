#include <stdio.h>
#include <string.h>

#define impMin 2.50 //costanti per il calcolo della media dei numeri compresi tra questi 2 valori
#define impMax 3.50
// Una banca vuole conoscere alcune informazioni sulle proprie azioni detenute in portafoglio.
// Scrivere il programma in c che dopo aver inserito da tastiera la denominazione dell’azione e il suo prezzo
// determini e visualizzi in Output:
// 1) La somma dei prezzi delle azioni;
// 2) La media dei prezzi delle azioni;
// 3) L’azione con il prezzo massimo;
// 4) L’azione con il prezzo minimo
// 5) La media dei prezzi delle azioni con un importo compreso tra 2,50 e 3,50 euro, estremi inclusi.
// L’inserimento termina con la parola “terminato”.
// Il programma deve permettere il reinserimento del prezzo se è pari a zero o inferiore.

int main(int argc, char *argv[])
{
    char nome[100], azioneMax[100], azioneMin[100]; //nomi delle azione inserite
    float prezzo, prezzoMax, prezzoMin; //prezzi
    float somma = 0, media, mediaCompresi = 0, sommaCompresi = 0; //somme e medie
    int i = 0, j = 0, p = 0; //contatori

    do
    {
        printf("Inserisci il nome dell'azione: "); //viene inserita un azione fin quando non viene scritto termina
        scanf("%s", nome);
        if (strcmp("termina", nome) != 0)
        {
            do{
            printf("Inserisci il prezzo dell'azione: ");
            scanf("%f", &prezzo); //input prezzo dell'azione con controllo dell'errore
            }while (prezzo <= 0);
            somma = somma + prezzo;
            i++;
            if (j = 0) //se è la prima volta che viene inserita un azione questa diventa sia l'azione col prezzo massimo che quella col prezzo minimo
            {
                prezzoMax = prezzo;
                strcpy(azioneMax, nome);
                prezzoMin = prezzo;
                strcpy(azioneMin, nome);
                j++;
            }
            if (prezzo > prezzoMax) 
            {
                prezzoMax = prezzo;
                strcpy(azioneMax, nome);
            }
            else //if (prezzo < prezzoMin)
            {
                prezzoMin = prezzo;
                strcpy(azioneMin, nome);
            }

            if (prezzo >= impMin && prezzo <= impMax) //calcolo media dei numeri compresi tra 2.50 e 3.50
            {
                sommaCompresi = sommaCompresi + prezzo;
                p++;
            }
        }
    } while (strcmp("termina", nome) != 0);

    if (somma != 0) //viene calcolata la media solo se la somma dei numeri è diversa da 0
    {
        media = somma / (float)i;
    }

    if (sommaCompresi != 0)
    {
        mediaCompresi = sommaCompresi / (float)p;
    }

    printf("La somma delle azione inserite fin ora è: %f\n", somma);
    printf("La media delle azione inserite fin ora è: %f\n", media); //output risultati
    printf("L'azione con il prezzo più alto inserito fin ora è: %s\n", azioneMax);
    printf("L'azione con il prezzo più basso inserito fin ora è: %s\n", azioneMin);
    printf("La media delle azione inserite con un valore compreso tra 2,50 e 3,50 euro, estremi inclusi, fin ora è: %f\n", mediaCompresi);

    return 0;
}