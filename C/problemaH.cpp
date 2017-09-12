/*
Autor: Moab Rodrigues de Jesus
Data: 19/09/2015

Descri��o do problema: Uma cidade hist�rica possui postes (de energia)
centen�rios e os mesmo n�o podem ser derrubados. A cidade deseja construir
uma pra�a, e deseja que a pra�a conte com pelo mesmo dois postes em cada
esquina. Nesta cidade os postes que sobraram estao dispostos em linhas e colunas
como um num plano cartesiano e n�o existe dois poste ocupando a mesma linha
ou coluna.
O programa recebe como entrada o n�mero de postes N, logo ap�s recebe a posi��o
x, y de cada poste (posicao em numero inteiros). O programa retorna a quantidade
de posi�oes possiveis para constru��o da pra�a, sabendo que dentro da pra�a
n�o pode haver postes.
*/

//----------------- Bibliotecas -----------------------------------------

#include <stdio.h>
#include <algorithm>
#include <vector>


//---------------- Declaracao de funcoes e complementos -----------------

using namespace std;

struct ponto { //implementa ponto (par ordenado)
    int x;
    int y;
};

bool compara(struct ponto a, struct ponto b);
bool verificaPonto(struct ponto p[], int posA, int posB, int posC);

// ----------------- Inicio do programa ---------------------------------

int main()
{
    int N, m;
    //vector<ponto> xy;
    scanf("%d", &N);
    ponto xy[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d", &m);
        xy[i].x = m;
        scanf("%d", &m);
        xy[i].y = m;
    }

    //ordenar vetor de pares ordenados
    sort(&xy[0], &xy[N], compara);

    int cont = 0;
    int i = 0, j = 0, k = 0;
    bool lock = true;

    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            for(k=i+1;k<N;k++)
            {

            	if(k==j)
            	{
            		k++;
            		if(k >= N)
            			continue;
            	}

            	if(!verificaPonto(xy, i, j, k))
                    lock = false; //esta dentro da area

            }
            if(lock)
            	cont++;
            lock = true;
        }
    }

    printf("%d\n", cont);
    system("PAUSE");
    return 0;
}

//---------------- Funcoes e estruturas --------------------------------

//verifica se o ponto c esta dentro da area forma pelos pontos a e b
bool verificaPonto(struct ponto p[], int posA, int posB, int posC)
{
	if((p[posC].x > p[posA].x && p[posC].x < p[posB].x) &&
	((p[posC].y > p[posA].y && p[posC].y < p[posB].y) || (p[posC].y < p[posA].y && p[posC].y > p[posB].y)))
			return false; //esta dentro da area formada por a e b
	return true;
}

//auxilia comparacao do metodo sort
bool compara(struct ponto a, struct ponto b)
{
	return (b.x > a.x);
}
