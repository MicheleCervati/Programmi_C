//leggi una stringa e conta le doppie (scanf)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[100];
    char fineStringa = '\n';
    int doppie = 0;
    printf("Inserisci la stringa: ");
    scanf("%s", stringa);


    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == stringa[i + 1] && stringa[i] != fineStringa)
        {
            doppie++;
            fineStringa = stringa[i];
        }
    }
    if (doppie != 0)
    {
        printf("Nella stringa %s ci sono %d doppie\n", stringa, doppie);
    }
    else
    {
        printf("Nella stringa non sono state trovate doppie");
    }
    return 0;
}