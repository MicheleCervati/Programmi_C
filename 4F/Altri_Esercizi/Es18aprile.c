#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int vecotor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void *Ricerca(void *args)
{
    int temp = (int)args;
    for (int i = 5 * (temp - 1); i < 10 / temp; i++)
    {
        if (vecotor[i] == 8)
        {
            if (i < 5)
            {
                printf("Posizione nella prima meta");
            }
            else
            {
                printf("Posizione nella prima meta");
            }
        }
    }
}

int main()
{
    pthread_t primaMeta, secondaMeta;
    int a = 1;
    pthread_create(&primaMeta, NULL, &Ricerca, &a);
    a = 2;
    pthread_create(&secondaMeta, NULL, &Ricerca,&a);

    pthread_join(primaMeta, NULL);
    pthread_join(secondaMeta, NULL);
    return 0;
}