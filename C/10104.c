#include <stdio.h>
long int a, b, d, x, y, prev_x, prev_y, temp;
/*
long int mdc(long int maior, long int menor)
{
	long int resto = maior % menor;
	if(resto == 0)
		return menor;
	return mdc(menor, resto);
}
*/

void mdc(long int maior, long int menor)
{
	long int resto = maior % menor;
	
	long int q = maior/menor; //quociente
	//printf("%ld %ld %ld %ld\n", maior, menor, resto, q);
	
	if(resto == 0){
        d = menor;
        return;
    }
	
    long int next_x = prev_x - q * x;
    prev_x = x;
    x = next_x;     

    long int next_y = prev_y - q * y;
    prev_y = y;
    y = next_y;  
    
    mdc(menor, resto);
	//printf("%ld %ld %ld %ld\n", maior, menor, resto, q);
}


int main()
{
    long int aux;
    //long int a, b, x, y, d;
	while(scanf("%ld %ld", &a, &b) != EOF)
	{
        x = 0; y = 1; prev_x = 1; prev_y = 0;
        if(a == 0){
            x = 0;
            y = 1;
            d = b;
        } else {
            //calcular mdc
            mdc(a,b);
            /*
            if(a != b)
            {
            //calcula menor x e y
                while(1)
                {
                    if(((-a*x)+d)%b == 0)
                    {
                        y = ((-a*x)+d)/b;
                        aux = x;
                        break;
                    } else if(((a*x)+d)%b == 0) {
                        y = ((a*x)+d)/b;
                        aux = -x;
                        break;
                    } else {
                        x++;
                    }
                }
            }
            else{ aux=0; y=1;}
            */
        }
		
		printf("%ld %ld %ld\n", x, y, d);
	}
	return 0;
}
