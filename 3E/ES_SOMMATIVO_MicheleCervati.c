#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*Dato un array di dimensione massima pari a SHRT_MAX,
inserire in input un numero arbitrario di interi positivi.
L'inserimento termina quando viene inserito il valore -1.

Si mostri quindi un menu cosi strutturato:
    premere 1 per mostrare il contenuto dell'array
    premere 2 per inserire un elemento in coda
    premere 3 per modificare un elemento, se presente
    premere 4 per eliminare un elemento, se presente
    premere 5 per ricercare un elemento
    premere 6 per inserire un elemento in una certa posizione
    premere 7 per mostrare il contenuto dell'array all'inverso
    premere 8 per mostrare il valore massimo dell'array
    premere 0 per terminare

dopo ogni operazione il menu deve essere nuovamente mostrato.

osservazione:
SHRT_MAX è dichiarata in limits.h

Vincolo:
è obbligatorio strutturare il programma in funzioni

*/

void InserisciPosizione(int *numeri, int *k){
    int posizione;
    int posizioneTemp;
    do{
    printf("In che posizione vuoi inserire il nuovo numero (0-%d): \n", *k);
    scanf("%d", &posizione);
    }while(posizione < 0 || posizione > *k);

    posizioneTemp = posizione;

    for(int i = posizione; i < (*k)+1; i++){
        numeri[i] = numeri[posizione+1];
        
    }
    
    printf("Che numero vuoi inserire: ");
    int numNuovo;
    scanf("%d", &numNuovo);

    numeri[posizioneTemp] = numNuovo;
    (*k)++;

}

void Ricerca(int *numeri, int *k)
{

    int ricercato;
    int p = 0;

    printf("Che numero vuoi ricercare: ");
    scanf("%d", &ricercato);

    for (int i = 0; i < *k && p != 1; i++)
    {
        if (numeri[i] == ricercato)
        {
            p++;
            printf("elemento trovato alla posizione %d\n", i);
        }
    }
}

void Elimina(int *numeri, int *k)
{
    int posizione;
    int i = 1;
    do
    {
        printf("Che elemento vuoi eliminare (inserisci la posizione dell'elemento): ");
        scanf("%d", &posizione);
    } while (posizione > *k || posizione < 1);

    while (posizione + i < *k)
    {
        numeri[posizione - 1] = numeri[posizione + i - 1];
        i++;
    }
    numeri[*k] = 0;
    (*k)--;
}

void ModificaElemento(int *numeri, int *k)
{
    int posizione;
    int num;

    do
    {
        printf("Che elemento vuoi modificare (inserisci la posizione dell'elemento): ");
        scanf("%d", &posizione);
    } while (posizione > *k || posizione < 1);

    printf("\nCon che numero vorresti sostituirlo: ");
    scanf("%d", &num);

    numeri[posizione - 1] = num;
}

void InserisciInCoda(int *numeri, int *k)
{
    int num;
    printf("Che numero vuoi inserire in coda: ");
    scanf("%d", &num);

    numeri[(*k) + 1] = num;
    (*k)++;
}

void MostraContenuto(int *numeri, int *k)
{
    for (int p = 0; p < *k; p++)
    {
        printf("Il %d ", p);
        printf("elemento dell'array e': %d \n", numeri[p]);
    }
}

void InserisciArray(int *numeri, int *k)
{
    int i = 1;
    int num;

    do
    {
        printf("Inserisci il %d numero: ", i);
        scanf("%d", &num);
        if (num != -1)
        {
            numeri[*k] = num;
            (*k)++;
        }
        i++;
    } while (num != -1);
}

void MostraMenu(int *scelta)
{
    printf("\npremere 1 per mostrare il contenuto dell array");
    printf("\npremere 2 per inserire un elemento in coda");
    printf("\npremere 3 per modificare un elemento, se presente");
    printf("\npremere 4 per eliminare un elemento, se presente");
    printf("\npremere 5 per ricercare un elemento");
    printf("\npremere 6 per inserire un elemento in una certa posizione");
    printf("\npremere 7 per mostrare il contenuto dell'array all'inverso");
    printf("\npremere 8 per mostrare il valore massimo dell'array");
    printf("\npremere 0 per terminare");

    int numScelto;

    do
    {
        printf("\nInserisci la tua scelta: ");
        scanf("%d", &numScelto);
    } while (numScelto < -1 || numScelto > 8);

    *scelta = numScelto;
}

int main(int argc, char *argv)
{

    int numeri[SHRT_MAX];
    int k = 0;
    int i = 0;
    int scelta;
    int altro = 1;
    InserisciArray(numeri, &k);

    do
    {
        MostraMenu(&scelta);

        switch (scelta)
        {
        case 1:
            MostraContenuto(numeri, &k);
            break;
        case 2:
            InserisciInCoda(numeri, &k);
            break;
        case 3:
            ModificaElemento(numeri, &k);
            break;
        case 4:
            Elimina(numeri, &k);
            break;
        case 5:
            Ricerca(numeri, &k);
            break;
        case 6:
            InserisciPosizione(numeri, &k);
            break;
            // case 7:
            //     Inverso();
            //     break;
            // case 8:
            //     Massimo();
            //     break;
            // case 0:
            //     Termina();
            //     break;

        default:
            printf("Input non valido");
            break;
        }

    } while (1 > 0);

    return 0;
}