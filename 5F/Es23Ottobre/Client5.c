/*Esercizio 3
Esercizio 5
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa,
e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client la stringa
ordinata alfabeticamente (eliminando i caratteri speciali).*/

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
#define MAXGRANDEZZA 100

int main(int argc, char **argv)
{

    struct sockaddr_in servizio;
    int socketfd;
    char str1[DIM], str2[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci la stringa: ");
    fgets(str1, DIM, stdin);
    str1[strcspn(str1, "\n")] = 0;

    write(socketfd, str1, strlen(str1) + 1);

    char temp[MAXGRANDEZZA];
    read(socketfd, temp, MAXGRANDEZZA);

    printf("Stringa ordinata: %s\n", temp);

    close(socketfd);
    return 0;
}