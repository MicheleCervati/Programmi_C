

#include <stdio.h>//inclusione libreria
#include <stdlib.h> //inclusione libreria
int main() //dichiarazione funzione main
{
	FILE *fileOrigine; //dichiarazione della variabile fileOrigine di tipo puntatore a FILE
	char c; //dichiarazione variabile c di tipo char 
	fileOrigine=fopen("nomi.txt", "r");  //apro il file nomi.ext in lettura e assegno il contenuto alla varbaile file origine
	if(fileOrigine==NULL)  //se il file non esiste
	{
		printf("Impossibile aprire il file"); //print di un errore
		exit (1); //termino il porgramma
	}
	else //altrimenti
	{
		c=fgetc(fileOrigine); //assegno a c il primo carattere di fileOrigine
		while (c!=EOF) //fin quando c non è uguale al carattere di fine file EOF
		{
			putchar(c); //stampo il carattere c
			c=fgetc(fileOrigine);		//assegno a c il carrattere successivo a quello assegnato prima di dileOrigine
	    }
	
	if(fclose(fileOrigine)==0)  //se la chiusura è andata bene
		printf("\n\nChiusura del file avvenuta con successo"); //print stringa
	else printf("\n\nChiusura del file fallita");// altrimenti stampo un altra stringa
    }
    return 0;//ritorno 0 per terminare il programma
}


//QUESTO PROGRAMMA STAMPA IL CONTENUTO DI UN FILE (nomi.txt)
