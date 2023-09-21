#include <stdio.h>
#include<string.h>

int main(int argv, char *argc[]){

    int i=0, lung;
    char str1[20],str2[20];
    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);
    lung = strlen(str1);
    printf("La lunghezza della stringa è %d\n\n", lung);
    printf("Inserisci la seconda stringa:  ");
    scanf("%s", str2);


    if(strcmp(str1,str2) == 0){
        printf("le 2 stringhe sono uguali\n\n");
    }else{
        printf("le 2 stringhe sono diverse\n\n");
    }


    strcat(str1, str2);

    printf("Le 2 stringhe concatenate sono:  %s\n\n", str1);

    printf("Le 2 stringhe copiate una nell'altra sono  %s\n\n", strcpy(str1,str2));
    return 0;
}