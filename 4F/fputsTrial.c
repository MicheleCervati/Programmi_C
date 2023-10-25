

#include <stdio.h> //inclusione libreria
#include <stdlib.h> //inclusione libreria


#define MAX_STR 20 //definisco una costante MAX_STR al valore 20
#define qtaNomi 4 //definisco una costante qtaNomi al valore 4

int i; // definisco una variabile globale i di tipo intero 
int main() //definisco la funzione main di tipo intero
{
	FILE *fileDestinazione; //definisco una variabile di tipo puntatore a FILE
	char vett[MAX_STR]; //definisco un vettire di caratteri di dimensione MAX_STR
	
	fileDestinazione=fopen("nomi.txt", "w");  //apro il file nomi.txt in scrittura e lo inserisco nella variabile fileDestinazione
	if(fileDestinazione==NULL)   //se il file non esiste
	{
		printf("Impossibile aprire il file"); //stampo una stringa
		exit (1); //termino il programma
	}
	else //altrimenti
	{
		for(i=0; i<qtaNomi; i++) //ripeto per qtaNomi volte 
		{
			printf("Inserisci il %d^ nome   >>   ", i+1); //stampo una stringa
			scanf("%s", vett);        //inserimeto di una stringa nel vettore di caratteri vett
			
			fputs(vett, fileDestinazione);  //scrivo nel file fileDestinazione la stringa contenuto in vett tramite la funzione fputs
			
			fputc('\n', fileDestinazione); //dopo aver scritto la stringa scrivo alla sua fine \n (carattere per andare a capo)
			
		}	 
    }
    fclose(fileDestinazione);//chiudo il file fileDestinazione
    
    fileDestinazione=fopen("nomi.txt", "r");   //apro il file nomi.txt in lettura e lo assegno alla variabile fileDestinazioine di tipo puntatore a FILE
	while( fgets(vett, MAX_STR, fileDestinazione) ) //scrivo il contenuto del file nel vettore vett (ripeto fin quando questo non e' uguale a null, quindi fine file)
		printf("%s", vett); //stampo il vettore
    
    if(fclose(fileDestinazione)==0) //chiudo il file e controllo se la chiusura è andata a buon fine
		printf("\n\nChiusura del file avvenuta con successo"); //stampo stringa
	else printf("\n\nChiusura del file fallita"); //stampo stringa
	
	return 0;//fine funzione main
}


//IL PROGRAMMA E' COMPOSTO DA 2 PARTI, LA PRIMA IN CUI INSERISCO DEI NOMI ALL'INTERNO DI UN FILE E UNA SECONDA IN CUI STAMPO QUESTO NOMI IN CONSOLE
//COSI DA VERIFICARE CHE TUTTO SIA AVVENUTO CORRETTAMENTE E POI CHIUDO IL FILE