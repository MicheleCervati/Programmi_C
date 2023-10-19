#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char vettNomi[20];
    char c;

    FILE * nomi; //puntatore ad oggetto file

    nomi = fopen("nomi.txt", "r");

    if(nomi==NULL){
        printf("Il file non si è aperto correttamente");
        exit(1);
    }


    do{
        c = getc(nomi);
        putchar(c);
    }while (c != EOF);

    


    for(int i = 0; i < 4; i++){
        printf("Inserisci il nome %d", i+1);
        scanf("%s", vettNomi[i]);

        fputs(vettNomi, nomi);
        fputc("\n", nomi);
    }

    fclose(nomi);

    return 0;
}