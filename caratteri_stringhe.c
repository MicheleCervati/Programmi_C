#include <stdio.h>

// int main(){
//     char carattere;
//     printf("inserisci il carattere \n");
//     //scanf("%c", &carattere);
//     carattere = getchar();
//     printf("hai inserito il seguente carattere: %c\n", carattere);
//     putchar(carattere);

//     printf("Il codice ASCII del carattere inserito è %d", carattere);
//     return 0;
// }


int main(){
    char stringa[30];
    int i=0;
    //[G][I][A][N][N][I][\0][][][][][][][][][][][][][][][][][][][][][]
    printf("Inserisci una stringa: ");
    scanf("%s", stringa);
    printf("Hai inserito la stringa: %s", stringa);
    while (stringa[i] != '\0')
    {
        i++;
    }
    printf("\n\n\nLa stringa è lunga %d\n\n\n", i);
}