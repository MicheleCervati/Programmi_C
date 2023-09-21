// Scrivere un programma che dopo aver letto una stringa conti quante consonanti e vocali contiene

// DA SISTEMARE

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0, cons = 0, voc = 0, lung = 0;
    char str[20];

    char vocali[5] = {'a', 'e', 'i', 'o', 'u'};

    printf("inserisci una stringa: ");
    scanf("%s", str);

    while (str[i] != '\0')
    {
        // lung++;
        i++;
    }

    lung = i;

    for (int j = 0; j < lung; j++)
    {
        if (str[j] == vocali[0] || str[j] == vocali[1] || str[j] == vocali[2] || str[j] == vocali[3] || str[j] == vocali[4] )
        {
            voc++;
        }
        else if ((str[j] != vocali[0] || str[j] != vocali[1] || str[j] != vocali[2] || str[j] != vocali[3] || str[j] != vocali[4]) && (str[i]>97 && str[i] <122))
        {
            cons++;
        }
    }

    printf("Sono state individuate %d vocali\n", voc);
    printf("Sono state individuate %d consonanti\n\n", cons);

    return 0;
}