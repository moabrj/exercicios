#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont =0;

int fibonIt(int n)
{
    long unsigned int aux, t1, t2;
    t1=t2=1;
    while(n>2)
    {
              cont++;
              //printf("%d\n", cont);
              aux = t2;
              t2+=t1;
              t1=aux;
              n--;
    }
    return t2;
}

int main()
{
     int n;
     scanf("%d", &n);
     system("CLS");
     int fibo = fibonIt(n);
     printf("\nO Resultado da serie eh: %d\n\n", fibo);
     system("PAUSE");
     return 0;
}
