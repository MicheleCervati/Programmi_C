// Scrivere un programma in C che dopo aver inserito una stringa ed un carattere  da linea comando , elimini il carattere inserito
// dalla stringa stessa (se esistente).

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char carattere;
    char stringa[100];
    char copiaStringa[100];
    int i, nVolte = 0;
    printf("Inserisci la stringa: ");
    scanf("%s", stringa);
    strcpy(copiaStringa, stringa);
    printf("\nInserisci il carattere da cercare nella stringa: ");
    scanf(" %c", &carattere);
    for (i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {

            stringa[i] = ' ';
        }
    }

    if (strcmp(stringa, copiaStringa))
    {
        printf("%s", stringa);
    }
    else
    {
        printf("Il carattere da eliminare non era gia presente nella stringa");
    }

    return 0;
}