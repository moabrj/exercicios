//Autor: Moab Rodrigues de Jesus

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota, nota1, nota2;
    
    nota =  0;
    int i;
    printf("Digite a primeira nota e pressione 'ENTER': ");
    scanf("%f", &nota);
    system("CLS");
    printf("Digite a segunda nota e pressione 'ENTER': ");    
    scanf("%f", &nota1);
    system("CLS");
    printf("Digite a terceira nota e pressione 'ENTER': ");
    scanf("%f", &nota2);
    system("CLS");
    
    float media = (nota+nota1+nota2)/3;
    
    if(media<7)
    {
               printf("Voce esta na final!\n");
               float final = (5 - (media*0.6))/0.4;
               printf("Nota necessaria para final: %.2f\n\n", final);
    }
    else
        printf("\nVoce esta aprovado com media %.2f\n", media);
               
    
    system("PAUSE");
    return 0;
    
}
