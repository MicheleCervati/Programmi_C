/*Esercizio 3
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il messaggio se
è palindroma oppure non lo è.*/

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

int ControllaPalindromo(char stringa[])
{
    int lunghezza = strlen(stringa);
    int inizio = 0;
    int fine = strlen(stringa) - 1;

    while (inizio < fine)
    {
        if (stringa[inizio] != stringa[fine])
        {
            return -1; // Non è palindroma 0;
        }
        inizio++;
        fine--;
    }

    return 1; // È palindroma
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

    for (;;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, sizeof(str));

        printf("Stringa ricevuta: %s\n", str);

        int temp = ControllaPalindromo(str);

        if (temp == 1)
        {

            printf("La stringa è palindroma");


        }
        else
        {
            printf("La stringa non è palindroma");

        }
        write(soa, &temp, sizeof(int));
        close(soa);
    }

    return 0;
}