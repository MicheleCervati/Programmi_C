/*Es 1
Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
alterni (o scambi ) a due a due le posizioni del vettore. Esempio:
vettore inserito: 1,2,3,4  vettore alternato: 2,1,4,3.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{

    int i = 0;
    int numeri[100];
    char altriN; // = 'n';
    int swap;

    do
    {
        printf("Inserisci il %d numero: ", i + 1);
        scanf("%d", &numeri[i]);
        printf("Vuoi inserire altri numeri? (y/n) \n");
        // https://stackoverflow.com/a/13543113
        scanf(" %c", &altriN);
        i++;
    } while (altriN == 'y');

    for (int j = 0; j < i - 1; j++)
    {
        if (j % 2 == 0)
        {
            
            swap = numeri[j];
            numeri[j] = numeri[j + 1];
            numeri[j + 1] = swap;
        }
    }

    for (int p = 0; p < i; p++)
    {
        printf("%d\n", numeri[p]);
    }

    return 0;
}