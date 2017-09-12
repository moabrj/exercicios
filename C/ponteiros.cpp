//ponteiros

#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
    int *a;
};

int main(void)
{
    int *ponteiro;
    int b = 10;
    int c = 100;
    
    struct numero num;
    struct numero *pont;
    
    num.a = &b; //ponteiro da estrutura recebe o endereço de b
    pont = &num; //ponteiro recebe o endereço da struct
    ponteiro = &c;
    
    printf("Endereco de b: %d", &b);
    printf("\nEndereco armazenado em a (b): %d", num.a);
    printf("\nConteudo armazenado no endereco apontado por a: %d", *num.a);//10
    printf("\nEndereco armazenado em a (b): %d", pont->a);
    printf("\nConteudo armazenado no endereco apontado por a: %d", (*(*pont).a));//10
    printf("\nEndereco de c: %d", ponteiro);
    printf("\nConteudo de c: %d\n\n", *ponteiro); //100
    
    
    system("pause");
}
