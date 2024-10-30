/*Esercizio 11
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input un
vettore di numeri e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al
Client il conteggio dei numeri pari e dei numeri dispari contenuti nel vettore.*/

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

int main(int argc,char** argv)
{
       
    struct sockaddr_in servizio;
    int socketfd;
    int quantiN;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d",&quantiN);
    write(socketfd,&quantiN,sizeof(int));

    int arr[quantiN];

    for(int i = 0; i < quantiN; i++){
        printf("\nInserisci il %d numero: ", i+1);
        scanf("%d", &arr[i]);
    }

    write(socketfd,arr,sizeof(int)*quantiN);    

    int counterPari, counterDispari;

    read(socketfd,&counterPari,sizeof(int));    
    read(socketfd,&counterDispari,sizeof(int));    

    printf("\pari: %d, dispari: %d", counterPari, counterDispari);

    close(socketfd);
    return 0;
}