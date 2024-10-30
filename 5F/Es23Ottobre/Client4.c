/*Esercizio 4
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere,e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.*/



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
    char str1[DIM],str2[DIM];
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    printf("\nInserisci la stringa\n");
    scanf("%s",str1);
    write(socketfd,str1,sizeof(str1));
    char carattere;
    printf("\nInserisci il carattere\n");
    scanf(" %c", &carattere);
    write(socketfd,&carattere,sizeof(char));

    int temp;
    read(socketfd,&temp,sizeof(int));    


    printf("\nIl numero di occorrenze nella stringa %s e' %d", str1, temp);


    //chiudo il client
    close(socketfd);
    return 0;
}