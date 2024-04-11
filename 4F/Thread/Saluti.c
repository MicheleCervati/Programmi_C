#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void*stampaGiorno(void *par)
{
    printf("Buongiorno\n");
}
void*stampaSera(void *par)
{
    printf("buonasera\n");
}
void* stampaNotte(void *par)
{
    printf("buonanotte\n");
}

int main()
{
    pthread_t threadGiorno, threadSera, threadNotte;

    pthread_create(&threadGiorno, NULL, &stampaGiorno, NULL);
    pthread_create(&threadSera, NULL, &stampaSera, NULL);
    pthread_create(&threadNotte, NULL, &stampaNotte, NULL);

    pthread_join(threadGiorno, NULL);
    pthread_join(threadSera, NULL);
    pthread_join(threadNotte, NULL);

    printf("ciao\n");

    //NON POSSO PARALLELIZZARE I THREAD SE VOGLIO BUONGIORNO, BUONASERA E BUONANOTTE IN ORDINE. 

    return 0;
}