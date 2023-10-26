#include <stdio.h>
#include <stdlib.h>


#define BUFFER_DIM 4

int main(int argc, char * argv[]){
    FILE *origine;
    FILE *destinazione;

    int n;
    unsigned char buffer[BUFFER_DIM];

    if(argc != 3){ //NOMEFILE NOMEORIGINE NOMEDESTINAZIONE
        printf("Inseririe correttamente i parametri d'ingresso\n");
        exit(1);
    }

//APERTUA FILE IN LETTURA
    origine = fopen(argv[1], "r");
    if(origine == NULL){
        printf("Errore apertura file origine\n");
        exit(1);
    }

//APERTURA FILE IN SCCRITTURA
    destinazione = fopen(argv[2], "w");
    if(destinazione == NULL){
        printf("Errore apertura file destinazione\n");
        exit(1);
    }

    

    while (!feof(origine)) //FIN QUANDO NON TROVA END OF FILE, RITORNA TRUE QUANDO TROVA EOF
    {
        n = fread(buffer, 1, BUFFER_DIM, origine); //va nel file e legge 1024 byte 1 a 1 (secondo parametro) e lo insrisce nel buffer. IN N RESTITUISCE QUANTI CARATTERI HA COPIATO NEL BUFFER
    
        if(n>0){ //quando il file finirà fread ritornerà 0 quindi qua controllo solo quando non ha ancora finito di copiare nel buffer
            fwrite(buffer, 1, n, destinazione); //copia i dati del buffer nel file destinazione
        }
    }

    fclose(origine);
    fclose(destinazione);
    
}