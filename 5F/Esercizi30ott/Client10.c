/*Esercizio 10
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 2 stringhe
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il messaggio di
quale delle due stringhe è + lunga o più corta o se sono uguali.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int main(int argc, char **argv)
{

    struct sockaddr_in servizio;
    int socketfd;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    char str1[DIM], str2[DIM];
    printf("\nInserisci stringa1: ");
    scanf("%s", str1);
    printf("\nInserisci stringa2: ");
    scanf("%s", str2);

    write(socketfd, &str1, sizeof(str1));
    write(socketfd, &str2, sizeof(str2));

    char strTemp[DIM];
    read(socketfd, &strTemp, sizeof(strTemp));

    printf("\n%s\n", strTemp);
    // chiudo il client
    close(socketfd);
    return 0;
}