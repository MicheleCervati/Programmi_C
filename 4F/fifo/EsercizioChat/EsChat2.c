#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


#define DIM_BUFFER 2048

int main()
{

    char buffer[DIM_BUFFER];

    int p = fork();

    if (p < 0)
    {
        printf("Errore nella fork");
        exit(1);
    }


    if (p > 0) // padre che legge
    {
        int fdFIFO = open("ChatFIFO", O_RDONLY);
        char temp[DIM_BUFFER];

        do
        {
            if (read(fdFIFO, buffer, sizeof(buffer)) != -1)
            {
                if (strcmp(buffer, temp) != 0)
                {
                    printf("\nChat2: %s", buffer);
                    strcpy(buffer, temp);
                }
            }
        } while (strcmp(buffer, "HALT") != 0);
    }
    else if (p == 0)
    {
        char buffer[DIM_BUFFER];
        int fdFIFO = open("ChatFIFO1", O_WRONLY);
        char temp[DIM_BUFFER];
        do
        {
            scanf("%s", buffer);
            strcat(buffer, "$");

            while (buffer[strlen(buffer) - 1] != '$')
            {
                write(fdFIFO, buffer, sizeof(char));
            }


        } while (strcmp(buffer, "HALT") != 0);
    }
}
