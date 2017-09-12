#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cont = 0;

int fibonRec(int n)
{
    cont++;
    //printf("%d\n", cont);
    if(n <= 2)
         return 1;
    return (fibonRec(n-2)+fibonRec(n-1));
}

int main()
{
    int n;
    clock_t inicio, fim;
    
    scanf("%d", &n);
    system("CLS");
    
    inicio= clock(); //captura tempo
    int fibo = fibonRec(n);
    fim= clock(); //captura tempo
    
    printf("\nO Resultado da serie eh: %d\n\n", fibo);
    printf("Tempo gasto %.2f\n\n", ((fim - inicio)/CLOCKS_PER_SEC));
    system("PAUSE");
    return 0;
}
