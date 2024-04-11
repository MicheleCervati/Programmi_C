#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* stampaSaluti(void *par)
{
    printf("%s\n", (char*)par);
    return (void*) 0;
}

int main()
{
    pthread_t threadGiorno, threadSera, threadNotte;

    char *msg1 = "Buongiorno";
    char *msg2 = "Buonasera";
    char *msg3 = "Buonanotte";

    pthread_create(&threadGiorno, NULL, &stampaSaluti, msg1);
    pthread_create(&threadSera, NULL, &stampaSaluti, msg2);
    pthread_create(&threadNotte, NULL, &stampaSaluti, msg3);

    pthread_join(threadGiorno, NULL);
    pthread_join(threadSera, NULL);
    pthread_join(threadNotte, NULL);

    printf("ciao\n");

    //NON POSSO PARALLELIZZARE I THREAD SE VOGLIO BUONGIORNO, BUONASERA E BUONANOTTE IN ORDINE. 

    return 0;
}