#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Esercizio n°1


conta.c


Scrivi il codice
sorgente di un programma che permette al processo padre di generare un processo
figlio.


Sia il processo padre
e sia il processo figlio visualizzano ciascuno il proprio PID e il PID del
proprio parente.


Padre conta da 0 a
19.


Figlio conta da 0 a
9.


Manda in esecuzione
più volte e osserva il comportamento del programma in esecuzione.*/

int main()
{

    int p;
    int contaPadre = 0, contaFiglio = 0;

    p = fork();

    if (p < 0)
    {
        printf("Errore non è stato possibile generare figli");
        exit(1);
    }

    if (p != 0)
    {
        printf("\nsono il padre e il mio PID è %d, mio figlio ha PID %d\n", getpid(), p);
        while (contaPadre <= 40)
        {
            printf("conta padre: %d\n", contaPadre);
            contaPadre++;
        }
    }
    else
    {

        printf("\nsono il figlio e il mio PID è %d, mio padre ha PID=%d\n", getpid(), getppid());
        while (contaFiglio <= 20)
        {
            printf("conta figlio: %d\n", contaFiglio);
            contaFiglio++;
            //exit(1);
        }

    }
        printf("Ciao sono il processo %d", getpid());

    return 0;
}