//leggi una stringa e conta le doppie (argc-argv)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore negli argomenti\n");
        return 0;
    }
    char fineStringa = '\n';
    int doppie = 0;
    

    for (int i = 0; i < strlen(argv[1]) - 1; i++)
    {
        if (argv[1][i] == argv[1][i + 1] && argv[1][i] != fineStringa)
        {
            doppie++;
            fineStringa = argv[1][i];
        }
    }

    
    if (doppie != 0)
    {
        printf("Nella stringa %s ci sono %d doppie\n", argv[1], doppie);
    }
    else
    {
        printf("Nella stringa non sono state trovate doppie");
    }
    return 0;
}