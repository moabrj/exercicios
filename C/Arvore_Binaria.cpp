//Arvore binaria
//Autor: Moab Rodrigues de Jesus

//----------- Informacoes Gerais ---------------------


//----------- Inicio do codigo -----------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct no
{
        int numero;
        struct no *e_prox; //proximo filho a esquerda
        struct no *d_prox; //proximo filho a direita
}node;

node* aloca()
{
      //puts("Memoria alocada!");
      return (node*)malloc(sizeof(no));
}

//Metodo de insercao na arvore
node* inserir(int num, node *raiz)
{
     node *aux = raiz;
     if(aux == NULL)
     {
            node *novo = aloca();
            novo->numero = num;
            novo->d_prox = NULL;
            novo->e_prox = NULL;
            aux = novo;
            return aux;
     }
     else
     {
         if(num >= aux->numero)
         {
             aux->d_prox = inserir(num, aux->d_prox);
         }
         else
         {
             aux->e_prox = inserir(num, aux->e_prox);
         }
     }
     return raiz;
}

void imprimir(node* raiz)
{
     node *aux = raiz;
     if(aux == NULL)
            return;
     printf("%d\n", aux->numero);
     imprimir(aux->d_prox);
     imprimir(aux->e_prox);
}

int main()
{
    
    //preenche vetor para testar
    int i,v[100];
    /*
    srand(time(NULL)); 
    for (i=0; i<=98; i++) 
    {
        v[i]= rand ();
    }
    */
    
    //inicio do programa
    node *raiz = NULL;
    /*
    for (i=0; i<=98; i++)
    {
        raiz = inserir(v[i], raiz);
    }
    */
    raiz = inserir(10, raiz);
    raiz = inserir(12, raiz);
    raiz = inserir(11, raiz);
    raiz = inserir(13, raiz);
    raiz = inserir(8, raiz);
    raiz = inserir(9, raiz);
    raiz = inserir(7, raiz);
    imprimir(raiz);
    system("PAUSE");
    return 0;
}
     
                  
