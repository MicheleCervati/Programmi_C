/*Scrivere un programma in C che dopo aver inserito
 una stringa crei 2 ulteriori stringhe contenenti, la prima i caratteri speciali e la seconda lettere ordinate in ordine alfabetico.*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{

    char str1[100];
    char caratteriSpeciali[100];
    char caratteriNormali[100];
    int k=0, l=0;

    printf("Inserisci una stringa: ");
    scanf("%s", str1);

    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] < 'a' || str1[i] > 'z')
        {
            caratteriSpeciali[k] = str1[i];
            k++;

        }
        else
        {
            caratteriNormali[l] = str1[i];
            l++;
        }
    }

    printf("\nLa stringa di caratteri speciali e' %s\n", caratteriSpeciali);
    printf("La stringa di caratteri normali e' %s\n\n", caratteriNormali);

    return 0;
}