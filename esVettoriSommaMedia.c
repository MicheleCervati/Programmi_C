#include <stdio.h>

int main(int argc, char *argv[]){

    int n,i,v[100], somma=0;
    float media;

    do{
        printf("Quanti elementi vuoi inserire? ");
        scanf("%d", &n);
    }while (n<=0 || n > 100);

    for(int i = 0; i < n; i++){
        printf("Inserisci un numero di posizione %d: ", (i+1));
        scanf("%d", &v[i]);
        somma=somma+v[i];
    }

    media = (float) somma / n;

    printf("Il vettore inserito è il seguente: ");
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }


    printf("\nLa somma del vettore risulta: %d", somma);
    printf("\nLa media del vettore risulta: %f", media);
    

    return 0;
}