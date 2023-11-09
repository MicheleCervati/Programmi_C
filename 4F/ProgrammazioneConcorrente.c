#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int p; // VARIABILE INTERA CHE PERMETTE DI GESTIRE IL PADRE E IL FIGLIO,
       // p nel padre = PID figlio
       // p nel figlio = 0

int main()
{ // diventa un processo quando entra nel main

    p = fork(); // padre genera un processo figlio

    if (p != 0)
    { // padre (la p sarà maggiore di 0)

        printf("\nSono il padre. p = %d, PID = %d, mio padre ha PID = %d", p, getpid(), getppid()); // p è il numero ritornato dalla fork
    }
    else
    { // figlio (la p è uguale a 0)

        printf("\nSono il figlio. p = %d, PID = %d, mio padre ha PID = %d\n", p, getpid(), getppid());
    }

    return 0;
}