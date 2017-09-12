#include <stdio.h>

int main()
{
    unsigned int n, i, j=0, cont=0, result=0;
    unsigned int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    unsigned int aux[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    scanf("%d", &n);
    while(n != 0)
    {
        j=0;
        i=primos[j];
        result = n;
        while(result != 1)
        {
            if((result%i)==0)
            {
                result = result/i;
                cont++;
            } else {
                aux[j] = cont;
                cont = 0;
                j++;
                i = primos[j];
            }
        }
        unsigned int total =0;
        for(i=0;i<15;i++)
        {
            if(aux[i] != 0)
            {
                total = total*(aux[i]+1);
            }
        }
        if(total%2==0)
            printf("yes\n");
        else
            printf("no\n");
                        
        scanf("%d", &n);
    }
}
