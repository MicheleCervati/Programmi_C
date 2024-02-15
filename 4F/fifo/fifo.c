#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int fd; // filedescriptor
    // int x = 90;

    if (mkfifo("myfifo1", 0777) == -1) // 0777 perchè do tutti i permessi
    {
        if (errno != EEXIST)
        {
            printf("Errore nella creazione della fifo");
            return 1;
        } 
    }

    // apro la fifo in sola scrittura

    fd = open("myfifo1", O_WRONLY); // fd = 1 poichè ho aperto al fifo in scrittura
    printf("Ho aperto la FIFO");

    int x = 90;

    if (write(fd, &x, sizeof(x)) == -1)
    {
        printf("Errore in scrittura nella FIFO");
        return 2;
    }
    printf("Ho scritto nella FIFO");

    close(fd);

    return 0;
}
