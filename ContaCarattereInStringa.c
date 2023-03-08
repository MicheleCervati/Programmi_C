// Leggi una stringa e un carattere e, se il carattere è presente nella stringa, conta quante volte quel carattere è contenuto nella stringa.

#include <stdio.h>
#include <string.h>

int main(int argv, char *argc[])
{
    char stringa[20];
    char carattere;
    int frequenza = 0;
    int i = 0;

    printf("\nInserisci la stringa: ");
    fgets(stringa, sizeof(stringa), stdin);
    printf("Inserisci il carattere: ");
    scanf("%c", &carattere);

    while (stringa[i] != '\0')
    {
        if (carattere == stringa[i])
        {
            frequenza++;
        }
        i++;
    }

    if (frequenza > 0)
    {
        printf("\nLa frequenza e' %d\n\n", frequenza);
    }else{
        printf("\nNon è stato trovato il carattere richiesto\n");
    }
}