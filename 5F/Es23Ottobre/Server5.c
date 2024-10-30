#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313
#define MAXSTRINGA 100

// Funzione per ordinare la stringa e rimuovere i caratteri speciali
char *RitornaOrdinata(char stringa[]) {
    static char stringa[MAXSTRINGA]; // Usare statico per mantenere l'array
    int j = 0;

    for (int i = 0; i < j - 1; i++) {
        for (int k = i + 1; k < j; k++) {
            if (stringa[i] > stringa[k]) {
                char temp = stringa[i];
                stringa[i] = stringa[k];
                stringa[k] = temp;
            }
        }
    }

    return stringa;  
}

int main() {
    struct sockaddr_in servizio, addr_remoto; 
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    for (;;) {
        printf("\nServer in ascolto...");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, sizeof(str));

        printf("Stringa ricevuta: %s\n", str);

        char *risultato = RitornaOrdinata(str);
        write(soa, risultato, strlen(risultato) + 1); // Invia solo la stringa ordinata
        close(soa);
    }

    return 0;
}
