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

  

    // apro la fifo in sola scrittura

    fd = open("myfifo1", O_RDONLY); // fd = 1 poichè ho aperto al fifo in scrittura
    printf("Ho aperto la FIFO");



    int x;

    if(read(fd, &x, sizeof(x)) != -1){
        printf("\nciao\n: %d", x);
    }

    

    close(fd);

    return 0;
}
