#include <stdio.h>
#include <string.h>


void soloNum(char str1[], char str2[]){
    int p=0;
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] == '0' || str1[i] == '1' || str1[i] == '2' || str1[i] == '3' || str1[i] == '4' || str1[i] == '5' || str1[i] == '6' || str1[i] == '7' || str1[i] == '8' || str1[i] == '9'){
            str2[p] = str1[i];
            p++;
        }
    }
}

int main(int argc, char *argv)
{

    char str1[100];
    char str2[100];

    printf("Inserisci stringa1: ");
    scanf("%s", str1);

    soloNum(str1, str2);

    printf("La stringa 1 e': %s", str1);
    printf("La stringa 2 e': %s", str2);

    return 0;
}