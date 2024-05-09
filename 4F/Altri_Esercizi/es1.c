/**/


#include <stdio.h>
#include <string.h>


int main(int argv, char* argc){
    printf("Gli argomenti inseriti da linea di comadno sono i seguenti: ");
    printf("\n");
    for(int i=0; i < argv; i++){
        printf("elemento %d: %s\n", i, argc[i]);
    }

    return 0;
}