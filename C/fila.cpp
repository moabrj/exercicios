#include <stdio.h>
#include <stdlib.h>

typedef struct Info
{
    int idade;
};

typedef struct No
{
    No *proximo;
    Info info;
};

typedef struct Fila
{
    No *primeiro;
    No *ultimo;
    int quantidade;
};

Fila* push(Fila *root, int idade);
No* pop(Fila *root);

int main()
{
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    
    //Inicializa a fila
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->quantidade = 0;
    
    int i = 0;
    for(i = 0; i< 100; i++)
    {
        fila = push(fila, i);
    }
    
    
    for(i = 0; i< 100; i++)
    {
        No *aux = pop(fila);
        printf("%d\n", aux->info.idade);
    }
    
    system("pause");
    return 0;   
}

Fila* push(Fila *fila, int idade)
{
    if(fila->primeiro == NULL) //fila está vazia
    {
        No *aux = (No*) malloc(sizeof(No));
        aux->info.idade = idade;
        aux->proximo = NULL;
        fila->primeiro = aux;
        fila->ultimo = aux;
        printf("%d", aux);
        printf("       %d\n", aux->proximo);
        return fila;
    } else
    {
        No *aux = (No*) malloc(sizeof(No));
        aux->info.idade = idade;
        aux->proximo = NULL;
        No *ultimo = fila->ultimo;
        ultimo->proximo = aux;
        fila->ultimo = aux;
        printf("%d", aux);
        printf("       %d\n", aux->proximo);
        return fila;
    }
}

//retorna o endereco do novo root
No* pop(Fila *root)
{
    No *aux;
    if(root->primeiro != NULL)
    {
        aux = root->primeiro;
        root->primeiro = aux->proximo;
        //free(root);
    } else
        aux = NULL;
    return aux;
}
