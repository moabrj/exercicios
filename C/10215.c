#include <stdio.h>
#include <math.h>

int main()
{
	double L, W, x_min, x_max;
	while(scanf("%lf %lf", &L, &W) != EOF)
	{
		if(L==W)
		{
			x_min = ((4*(L+W))+sqrt(pow((4*(L+W)),2)-48*L*W))/24;
			x_max = ((4*(L+W))-sqrt(pow((4*(L+W)),2)-48*L*W))/24;	
			printf("%.3lf 0.000 %.3lf\n", x_max, x_min);	
		} else 
        {
			x_max = ((4*(L+W))-sqrt(pow((4*(L+W)),2)-48*L*W))/24;
			if(L > W)
            {
                printf("%.3lf 0.000 %.3lf\n", x_max, W/2+1e-10); //1e-10 eh uma aproximacao do epsilon de maquina
            }
			else
			{
				printf("%.3lf 0.000 %.3lf\n", x_max, L/2+1e-10); //1e-10 eh uma aproximacao do epsilon de maquina
            }
		}		
	}
	return 0;
}
