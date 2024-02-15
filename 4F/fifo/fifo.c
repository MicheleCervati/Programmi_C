#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){




    mkfifo("myfifo1");

    return 0;
}
