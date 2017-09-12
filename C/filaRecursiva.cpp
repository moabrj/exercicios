#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    No* proximo;
    int idade;
};

No* aloca()
{
    return ((No*) malloc(sizeof(No)));
}

void push(No **raiz, int idade)
{
    No *aux;
    if((*raiz)->proximo == NULL)
    {
        aux = aloca();
        (*raiz)->proximo = aux;
        aux->proximo = NULL;
        aux->idade = idade;
        //printf("%d\n", aux);
    } else
    {
        push(&(*raiz)->proximo, idade);
    }
    return;
}

No* pop(No **raiz)
{
    if(raiz != NULL)
    {
        No *aux = (*raiz);
        (*raiz) = (*raiz)->proximo;
        aux->proximo = NULL;
        return aux;
    }
    return NULL;
}

int main()
{
    No *raiz = NULL;
    //inicializa fila
    raiz = aloca();
    raiz->idade = 100;
    raiz->proximo = NULL;
    
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        push(&raiz, i);
    }
    
    
    for(i = 0; i< 11; i++)
    {
        No *aux = pop(&raiz);
        printf("%d\n", aux->idade);
        free(aux);
    }
    
    system("pause");
    return 0; 
    
}
