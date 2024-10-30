/*Esercizio 11
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input un
vettore di numeri e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al
Client il conteggio dei numeri pari e dei numeri dispari contenuti nel vettore.*/



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

        read(soa, &LunghezzaArray, sizeof(int));

        int arr[LunghezzaArray];
        read(soa, arr, sizeof(arr));

        int counterP = 0, counterD = 0;
        for (int i = 0; i < LunghezzaArray; i++)
        {
            if (arr[i] % 2 == 0)
            {
                counterP++;
            }
            else
            {
                counterD++;
            }
        }


        printf("pari: %d, dispari: %d", counterP, counterD);
        write(soa, &counterP, sizeof(int));
        write(soa, &counterD, sizeof(int));

        close(soa);
    }

    return 0;
}