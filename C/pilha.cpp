/*
Autor: Moab Rodrigues de Jesus
Data: 29/12/2015, Terça-feira, Hora: 21:37
*/

#include <stdio.h>
#include <stdlib.h>

//-------------- Structs e funcoes -------------------
typedef struct Info {
    unsigned short int idade;
};

typedef struct No {
    No *proximo;
    Info info;
};

No* push(No *topo, int i);
No* pop(No *topo);

int main()
{
    No *topo = NULL;
    
    int i = 0;
    
    for(i = 0; i< 100; i++)
    {
        topo = push(topo, i);
    }
    
    for(i = 0; i< 100; i++)
    {
        No *novo = topo;
        topo = pop(topo);
        if(novo != NULL)
        {
            printf("%d\n", novo->info.idade);
        }
    }
    
    
    system("pause");
    
    return 0;
}

//recebe o endereco do ponteiro
No* push(No *topo, int i)
{
    if(topo == NULL)
    {
        //aloca espaco para um no
        topo = (No*) malloc(sizeof(No));
        topo->proximo = NULL;
        //topo->info = (Info) malloc(sizeof(Info));
        topo->info.idade = i;
        return topo;
    } else {
        No *novo = (No*) malloc(sizeof(No));
        novo->proximo = topo; //recebe o endereco do antigo topo
        //novo->info = (Info) malloc(sizeof(Info));
        novo->info.idade = i;
        return novo;
    }
}

//o pop remove o topo atual da pilha
No* pop(No *topo)
{
    if(topo == NULL)
    {
        return topo;
    } else {
        //No *aux = topo;
        //topo = (topo->proximo); //o endereco do topo e atualizado
        return topo->proximo;//retorna o endereco do topo
    }
}
