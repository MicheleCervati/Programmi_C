#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*s
Scrivi il codice
sorgente di un programma in cui il processo padre genera tre processi figli:
Qui, Quo, Qua.


Ciascun processo
dovrà visualizzare sullo schermo, rispettivamente:


_ “Sono il padre A,
il mio PID = … “


_Sono il figlio QUI,
il mio PID = … “


_Sono il figlio QUO,
il mio PID = … “


_Sono il figlio QUA,
il mio PID = … “


Manda in esecuzione
più volte e osserva il comportamento del programma in esecuzione.*/

int p;
int k;
int j;

int main()
{

    p = fork(); // padre genera un processo figlio

    if (p != 0)
    { // padre (la p sarà maggiore di 0)

        printf("\nSono il padre. p = %d, PID = %d, mio padre ha PID = %d", p, getpid(), getppid()); // p è il numero ritornato dalla fork
        k = fork();
        if (k == 0)
        {

            printf("\nSono Qui, k = %d, PID = %d, mio padre ha PID = %d", k, getpid(), getppid());
        }
        else
        {
            // PADRE
            j = fork();
            if (j == 0)
            {
                printf("\nSono Qua, j = %d, PID = %d, mio padre ha PID = %d", j, getpid(), getppid());
            }
        }
    }
    else
    { // figlio (la p è uguale a 0)

        printf("\nSono Sono Quo p = %d, PID = %d, mio padre ha PID = %d\n", p, getpid(), getppid());
    }

    return 0;
}