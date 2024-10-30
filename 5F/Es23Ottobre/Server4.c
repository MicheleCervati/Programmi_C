/*Esercizio 4
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere,e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int ContaOccorrenze(char stringa[], char carattere) {
    int counter = 0;
    int lunghezza = strlen(stringa);

    for (int i = 0; i < lunghezza; i++) {
        if (stringa[i] == carattere) {
            counter++;
        }
    }

    return counter; 
}

int main()
{
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], newstr[DIM] = "ricevuta";
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    char carattere;

    for (;;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, strlen(str));

        printf("\nStringa ricevuta: %s\n", str);

        read(soa, &carattere, sizeof(char));

        printf("\ncarattere da ricercare: %c\n", carattere);

        int nOccorrenze = ContaOccorrenze(str, carattere);


        printf("\nIl numero di occorrenze: %d", nOccorrenze);

        write(soa, &nOccorrenze, sizeof(int));
        close(soa);
    }

    return 0;
}