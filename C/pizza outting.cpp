#include <stdio.h>

int main()
{
    long int m, N;
    while(1)
    {
         scanf("%ld", &N);
         if(N < 0){ break; }
         else if(N == 0){ 
              printf("\n0");
         }
         else{
              m = (((1+N)*N)/2)+1;
              printf("\n%ld", m);
         }
    }
}
