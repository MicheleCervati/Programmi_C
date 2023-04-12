/*Scrivere un programma in C che dopo aver inserito 2 stringhe visualizzi a video le lettere comuni ad entrambe.*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv)
{

    char stringa1[100];
    char stringa2[100];

    printf("Inserisci la prima stringa: ");
    scanf("%s", stringa1);
    printf("Inserisci la seconda stringa: ");
    scanf("%s", stringa2);

    int lettere[26] = {0};
    
    int letterePresenti1[26] = {0};
    int letterePresenti2[26] = {0};

    

    for (int i = 0; i < strlen(stringa1); i++)
    {
        lettere[stringa1[i] - 'a']++;
        letterePresenti1[stringa1[i] - 'a'] = 1;
    }

    for (int i = 0; i < strlen(stringa2); i++)
    {
        lettere[stringa2[i] - 'a']++;
        letterePresenti2[stringa2[i] - 'a'] = 1;
    }   

    char carattere;

    for (int i = 0; i < 26; i++)
    {
        if (lettere[i] > 1 && letterePresenti1[i] == 1 && letterePresenti2[i] == 1)
        {
            carattere = i + 'a';
            printf("\nLe 2 stringhe hanno la lettera %c ", carattere);
            printf("in comune %d volte", lettere[i]/2);
        }
    }


    printf("\n");
    return 0;
}