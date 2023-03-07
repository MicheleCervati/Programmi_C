#include <stdio.h>
int main(int argc, char *argv[])
{
    int a, b, c;          // numeri da inserire
    int min = 0, max = 0; // per calcolare massimo e minimo
    // inizio ciclo per inserire numeri
    do
    {
        printf("inscerisci il primo numero \n");
        scanf("%d", &a);
        // controllo se numero minore di 0
        if (a < 0)
        {
            // per interrompere il ciclo in case sia verificato l'if
            break;
        }
        printf("inscerisci il secondo numero \n");
        scanf("%d", &b);
        if (b < 0)
        {
            break;
        }
        printf("inscerisci il terzo numero \n");
        scanf("%d", &c);
        if (c < 0)
        {
            break;
        }
        // scarto le terne che soddisfano la condizione
        if (a < b && b < c)
        {
            printf("Questa terna non verrà considerata \n ");
        }
        else
        {
            // verifico maggiore della terna
            if (a >= c && a >= b)
            {
                max = a;
            }
            else if (b >= c && b >= a)
            {
                max = b;
            }
            else if (c >= b && c >= a)
            {
                max = c;
            }
            // verifico minore della terna
            if (a <= b && a <= c)
            {
                min = a;
            }
            else if (b <= c && b <= a)
            {
                min = b;
            }
            else if (c <= b && c <= a)
            {
                min = c;
            }
            // stampa del minore e del maggiore
            printf("il numero maggiore  della terna è %d \n", max);
            printf("il numero minore  della terna è %d \n", min);
        }

    } while (1); // ciclo infinito che termnina col break in mezzo
    printf("fine ciclo \n");
    return 0;
}