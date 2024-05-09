#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int global1 = 130;
int global2;

int main(){
    int a;

    while(1){
        printf("%d\n", getpid());
        printf("%p\n", &a);
        sleep(5);
    }

    return 0;
}