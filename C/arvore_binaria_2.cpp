//arvore binaria

#include <stdio.h>
#include <stdlib.h>


typedef struct folha
{
    struct folha *e;
    struct folha *d;
    int numero;
};

folha* inserir(folha *raiz, int numero);
void imprimirOrdem(folha *raiz);
void imprimirPosOrdem(folha *raiz);

int main(void)
{
    struct folha *raiz = NULL;
    
    for(int i=1;i<5;i++)
    {
        raiz = inserir(raiz, i);
        printf("%d ", i);
    }
    printf("\n\n");
    imprimirOrdem(raiz);
    printf("\n\n");
    imprimirPosOrdem(raiz);
    system("pause");
    return 0;
}

folha* inserir(folha *raiz, int numero)
{
    folha *aux = raiz;
    if(aux == NULL)
    {
        struct folha *novo = (folha*)malloc(sizeof(folha));
        novo->numero = numero;
        novo->e = NULL;
        novo->d = NULL;
        aux = novo;
        return aux;
    } else {
        if(aux->numero >= numero)
            aux->d = inserir(aux->d, numero);
        else
            aux->e = inserir(aux->e, numero);
    }
    return raiz;
}

void imprimirOrdem(folha *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->numero);
        imprimirOrdem(raiz->d);
        imprimirOrdem(raiz->e);
        return;
    }
    return;
}


void imprimirPosOrdem(folha *raiz)
{
    if(raiz != NULL)
    {
        imprimirPosOrdem(raiz->d);
        imprimirPosOrdem(raiz->e);
        printf("%d ", raiz->numero);
        return;
    }
    return;
}

void remover(folha *raiz, int numero)
{
    folha aux = raiz;
    if(aux->numero == numero)
    {
        aux = encontraVazio(aux);
    } else if(aux->numero < numero){//vai para ramo direito
        remover(aux, numero);
    } else { //vai para ramo esquerdo
        remover(aux, numero);
    }
    
}

folha* encontraVazio(folha *raiz)
{
    
}
