#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char*argv[]){
    
    typedef struct {
        char nome[20];
        char cognome[20];
        int media;
    } student_t;

    //NON VIENE PIU FATTA UNA VARIABILI DI TIO STUDENT_T CHE OCUPAVA MOLTA MEMORIA
    student_t *stud;
    stud = malloc(sizeof(student_t)); //memory allocation 


    strcpy(stud->nome, "nome");
    strcpy(stud->cognome, "cognome");
    stud->media = 8;


    printf("%s\n", stud->nome);
    printf("%s\n", stud->cognome);
    printf("%d\n", stud->media);


    return 0;
}