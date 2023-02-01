#include <stdio.h>
void main()
{
    int a = 0, b = 0, c = 0, diff = 0, diffpari = 0, diffdispari = 0, nodiff = 0;
    do
    {
        printf("inserire il valore di a:\n");
        scanf("%d", &a);
        printf("inserire il valore di b:\n");
        scanf("%d", &b);
        printf("inserire il valore di c:\n");
        scanf("%d", &c);
        diff = (a - b);
        if (diff == 0)
            nodiff++;
        if (diff % 2 == 0)
            diffpari++;
        else
            diffdispari++;
    } while (a + b < c);
    printf("la differenza tra a e b  è stata nulla %d volte", &nodiff);
    printf("la differenza tra a e b  è stata dispari %d volte", &diffdispari);
    printf("la differenza tra a e b  è stata pari %d volte", &diffpari);
}
