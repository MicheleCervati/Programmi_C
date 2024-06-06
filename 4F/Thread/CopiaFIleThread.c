/*
-copiare il contenuto di un file di testo in un secondo file (i nomi dei file sono inseriti dall'utente quando avvia il programma);
-le operazioni di lettura e scrittura sono svolte da due thread separati.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define GrandezzaNomeFile 50
#define DIM_BUFFER 2048

char buffer[DIM_BUFFER];
int finito = 0;


         
void *Scrittura(void *arg)
{
  //  datiPerFile *temp = (datiPerFile *)arg;
    FILE *scritt = fopen(*temp->Destinazione, "w");
    while (finito != 1)
    {
        fwrite(buffer, 1, 1, scritt);
        printf("scrittura");
    }
    fclose(scritt);
    pthread_exit(NULL);
}

void *Lettura(void *arg)
{
    char *temp[GrandezzaNomeFile] = (char **)arg;
    FILE *lett = fopen(*temp->Origine, "r");

    pthread_t thread_Scritt;

    int n;
    while ((n = fread(buffer, 1, DIM_BUFFER, lett)) > 0)
    {
        printf("\nLettura");
    }
    finito = 1;
    fclose(lett);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore");
        exit(-1);
    }
    char origine[30];
    char destinazione[30];
    strcpy(origine, argv[1]);
    strcpy(destinazione, argv[2]);
    pthread_t ThreadLettura;
    pthread_t ThreadScrittura;
    pthread_create(&ThreadLettura, NULL, &Lettura, (void *)&origine);
    pthread_create(&ThreadScrittura, NULL, &Scrittura, (void *)&destinazione);
    pthread_join(&ThreadLettura, NULL);
    pthread_join(&ThreadScrittura, NULL);
    printf("\nProgramma terminato\n");
    return 1;
}