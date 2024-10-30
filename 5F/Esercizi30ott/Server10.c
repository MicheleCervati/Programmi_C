/*Esercizio 10
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 2 stringhe
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il messaggio di
quale delle due stringhe è + lunga o più corta o se sono uguali.*/

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

int main()
{
    int LunghezzaArray;
    char str1[DIM], str2[DIM];
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio);
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    for (;;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);

        read(soa, &str1, sizeof(str1));
        read(soa, &str2, sizeof(str2));

        char stringaTemp[DIM];

        if (strlen(str1) > strlen(str2))
        {

            sprintf(stringaTemp, "\nè più lunga la stringa 1: %s", str1);
        }
        else if (strlen(str1) < strlen(str2))
        {
            sprintf(stringaTemp, "\nè più lunga la stringa 2: %s", str2);
        }
        else
        {
            sprintf(stringaTemp, "\nle 2 stringhe sono uguali");
        }

        printf("\n%s\n", stringaTemp);
        write(soa, &stringaTemp, sizeof(stringaTemp));
        close(soa);
    }

    return 0;
}