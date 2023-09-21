/*9) Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:

1)      Che contenga solo lettere;
2)      Crei 2 ulteriori stringhe che contengano: la 1 le lettere di posizione pari; la 2 le lettere di posizione dispari;
Inserita una 2 stringa determinare:
1)      Quale delle 2 e piu lunga e piu corta;
2)      Quale delle 2 stringhe contiene piu vocali;
3)      Quale delle 2 stringhe contiene piu consonanti.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argv, char *argc[])
{

    char stringa[100];
    char stringa2[100];
    char letterePari[100];
    char lettereDispari[100];
    bool soloLettere = true;
    int contVoc1 = 0, contVoc2 = 0, contCons1 = 0, contCons2 = 0;
    int k = 0, p = 0;

    printf("Inserisci una stringa: ");
    scanf("%s", stringa);

    for (int i = 0; i < strlen(stringa) && soloLettere; i++)
    {
        if (stringa[i] < 96 || stringa[i] > 126)
        {
            soloLettere = false;
        }
        else
        {
            if (i % 2 == 0)
            {
                letterePari[k] = stringa[i];
                k++;
            }
            else
            {
                lettereDispari[p] = stringa[i];
                p++;
            }
        }
    }

    if (!soloLettere)
    {
        printf("Nella stringa non sono presenti solo lettere\n");
        exit(0);
    }

    printf("\nLe lettere in posizione pari sono %s\n", letterePari);
    printf("Le lettere in posizione dispari sono %s\n", lettereDispari);

    printf("Inserisci la seconda stringa: ");
    scanf("%s", stringa2);

    if (strlen(stringa) == strlen(stringa2))
    {
        printf("\nLe 2 stringhe inserite hanno la stessa lunghezza");
    }
    else if (strlen(stringa) > strlen(stringa2))
    {
        printf("\nLa stringa 1 e' più lunga");
    }
    else
    {
        printf("\nLa stringa 2 e' più lunga");
    }

    for (int f = 0; f < strlen(stringa); f++)
    {
        if (stringa[f] == 'a' || stringa[f] == 'e' || stringa[f] == 'i' || stringa[f] == 'o' || stringa[f] == 'u')
        {
            contVoc1++;
        }
        else
        {
            contCons1++;
        }
    }

    for (int f = 0; f < strlen(stringa2); f++)
    {
        if (stringa2[f] == 'a' || stringa2[f] == 'e' || stringa2[f] == 'i' || stringa2[f] == 'o' || stringa2[f] == 'u')
        {
            contVoc2++;
        }
        else
        {
            contCons2++;
        }
    }

    if (contVoc1 == contVoc2)
    {
        printf("\nLa prima e la seconda stringa hanno lo stesso numero di vocali");
    }
    else if (contVoc1 > contVoc2)
    {
        printf("\nLa prima stringa ha piu' vocali");
    }
    else
    {
        printf("\nLa seconda stringa ha piu' vocali");
    }

    if (contCons1 == contCons2)
    {
        printf("\nLa prima e la seconda stringa hanno lo stesso numero di consonanti");
    }
    else if (contCons1 > contCons2)
    {
        printf("\nLa prima stringa ha piu' consonanti");
    }
    else
    {
        printf("\nLa seconda stringa ha piu' consonanti");
    }

    return 0;
}