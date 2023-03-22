//leggi una stringa e conta la frequenza di un carattere (scanf)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char carattere[1];
    char stringa[100];
    int i, nVolte = 0;
    printf("Inserisci la stringa: ");
    scanf("%s", stringa);
    printf("\nInserisci il carattere da cercare nella stringa: ");
    scanf("%s", carattere);
    for (i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere[0])
        {
            nVolte++;
        }
    }
    if (nVolte == 0)
    {
        printf("Non è stato trovato il carattere\n");
    }
    else
    {
        printf("Il carattere è stato trovato %d volte\n", nVolte);
    }
    return 0;
}