// Leggi una stringa e un carattere e, se il carattere è presente nella stringa, conta quante volte quel carattere è contenuto nella stringa.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int frequenza = 0;
    int i = 0;

    if (argc != 3)
    {
        printf("argomenti non validi.");
        exit(0);
    }

    if (strlen(argv[1]) > 20)
    {
        printf("argomenti non validi.");
        exit(0);
    }

    if (strlen(argv[2]) > 1)
    {
        printf("argomenti non validi.");
        exit(0);
    }

    char stringa[20];
    strcpy(stringa, argv[1]);
    char carattere[1];
    strcpy(carattere, argv[2]);


    // printf("\nInserisci la stringa: ");
    // fgets(stringa, sizeof(stringa), stdin);
    // printf("Inserisci il carattere: ");
    // scanf("%c", &carattere);

    while (stringa[i] != '\0')
    {
        if (carattere[0] == stringa[i])
        {
            frequenza++;
        }
        i++;
    }

    if (frequenza > 0)
    {
        printf("\nLa frequenza e' %d\n\n", frequenza);
    }
    else
    {
        printf("\nNon è stato trovato il carattere richiesto\n");
    }
}