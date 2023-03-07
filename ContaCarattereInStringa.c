// Leggi una stringa e un carattere e, se il carattere è presente nella stringa, conta quante volte quel carattere è contenuto nella stringa.

#include <stdio.h>
#include <string.h>

int main(int argv, char *argc[])
{
    char stringa[100];
    int lunghezzaStringa;
    char carattere;
    int nVolte = 0;

    printf("Inserisci la stringa: ");
    scanf("%s", stringa);
    printf("inserisci il carattere da contare: ");
    scanf("%s", carattere);

    lunghezzaStringa = strlen(stringa);

    for (int i = 0; i < lunghezzaStringa; i++)
    {
        if (stringa[i] == carattere)
        {
            nVolte++;
        }
    }


    printf("\nViene ripetuto %d volte\n", nVolte);
   // printf("\nIl carattere %c viene ripetuto %d nella stringa %s", &carattere, &nVolte, stringa);
}