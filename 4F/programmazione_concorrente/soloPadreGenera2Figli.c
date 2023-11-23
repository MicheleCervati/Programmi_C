#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/*soloPadreGenera2Figli.c


Scrivi il codice
sorgente di un programma in cui solo il processo padre genera due processi
figli.


Il padre visualizza
il proprio PID e il PID dei suoi due figli.


Ciascun figlio
visualizza il Proprio PID e il PID del padre.


Manda in esecuzione
più volte e osserva il comportamento del programma in esecuzione.
*/
int p;
int k;

int main(){

    
    p = fork(); // padre genera un processo figlio

    if (p != 0)
    { // padre (la p sarà maggiore di 0)

        printf("\nSono il padre del processo1. p = %d, PID = %d, mio padre ha PID = %d", p, getpid(), getppid()); // p è il numero ritornato dalla fork
        k = fork();
        if(k == 0){
            printf("S\nono il figlio numero 2, k = %d, PID = %d, mio padre ha PID = %d", k, getpid(), getppid());
        }
    }
    else
    { // figlio (la p è uguale a 0)

        printf("\nSono il figlio1. p = %d, PID = %d, mio padre ha PID = %d\n", p, getpid(), getppid());
    }


    return 0;
}