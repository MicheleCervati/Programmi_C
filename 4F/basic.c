#include <stdio.h> //inclusione libreria
#include <stdlib.h> //inclusione libreria




int main() //dichiarazione funzione main
{
	
	FILE *fileOrigine; //dichiarazione della variabile fileOrigine di tipo puntatore a FILE

	fileOrigine=fopen("nomeFile.txt", "r"); //apertura nomeFile.txt in modalità lettura

	if(fileOrigine==NULL)  //se il file non esiste
	{
		printf("Impossibile aprire il file"); //print di un errore
		exit (1); //termina il programma
	}
	else //se esiste il file
	{
		 printf("File aperto"); //print di file aperto
    }

    fclose(fileOrigine); //chiudo il file
	
    if(fclose(fileOrigine)==0) //se chiusura andata bene
		printf("\nChiusura del file avvenuta con successo"); //print di chiusura avvenuta correttamente
	else printf("\nChiusura del file fallita"); //print messaggiodi errore

	return 0; //ritorno un intero per chiudere il main
}

//QUESTO PROGRAMMA VERIFICASE SI RIESCE APRIRE A CHIUDERE UN FILE E STAMPA A SCHERMO IL RISULTATO
