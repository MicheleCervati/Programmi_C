//leggi una stringa e conta la frequenza di un carattere (argc-argv)


#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i, nVolte = 0;

    if (argc != 3)
    {
        printf("Errore negli argomenti\n");
        return 0;
    }
    if (strlen(argv[2]) != 1)
    {
        printf("Il secondo argomento deve essere un carattere\n");
        return 0;
    }


    for (i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] == argv[2][0])
        {
            nVolte++;
        }
    }
    if (nVolte == 0)
    {
        printf("Non si è trovato il carattere scelto all'interno della stringa\n");
    }
    else
    {
        printf("Il carattere è stato trovato %d volte\n", nVolte);
    }
    return 0;
}