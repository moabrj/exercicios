#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
       int idade;
       no *next;
};

no* aloca()
{
    return (no*)malloc(sizeof(no));
}

void inserir(int idade, no *raiz)
{
     no *aux = raiz;
     no *novo;
     novo = aloca();
     novo->idade = idade;
     if(aux->next == NULL)
     {
            novo->next = NULL;
            aux->next = novo;
     }
     else
     {
            while((aux->next) != NULL)
            {
                     aux = aux->next;
            }
            aux->next = novo;
            novo->next = NULL;
     }         
}

void imprimir(no *raiz)
{
     no *aux = raiz;
     while(aux->next != NULL)
     {
                     aux = aux->next;
                     printf("%d\n", aux->idade);
     }
}

void remove(int i, no*raiz)
{
     no *aux = raiz;
     no *aux2 = aux;
     while(aux->next != NULL && aux->idade != i)
     {
                     aux2 = aux;
                     aux = aux->next;
     }
     if(aux->idade == i)
     {
           aux2->next = aux->next;
           free(aux);
     }
     else
     {
          printf("\nERRO - O elemento escolhido nao esta na lista!\n");
     }
}
                     

int main()
{
    no *raiz = aloca();
    raiz->next = NULL;
    
    int i =0;
    while(i<30)
    {
                 inserir(i,raiz);
                 i++;
    }
    printf("\nLista com 30 elementos:\n");
    imprimir(raiz);
    remove(10, raiz);
    remove(0, raiz);
    remove(29, raiz);
    printf("\nLista com sem os elementos 0, 10 e 29:\n");
    imprimir(raiz);
    remove(69, raiz); //nao está na lista
    system("PAUSE");
    return 0;
}
