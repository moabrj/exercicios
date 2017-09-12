#include <stdio.h>
#include <stdlib.h>

int particiona(int v[],int p, int r)
{
    int c = v[p], i=p+1, j=r-1, aux;
    while(i<=j)
    {
               while(i<r && v[i]<=c)
                         i++;
               while(c<v[j])
                         j--;
               if(i>=j)
                      break;
               aux = v[i];
               v[i]=v[j];
               v[j]=aux;
               i++;
               j--;
    }
    aux = v[p];
    v[p] = v[j];
    v[j] = aux;
    return j;                        
}

void quickSort(int v[],int p,int r)
{
     int j;
     if(p<r-1)
     {
              //puts("\nEntrou\n");
              j=particiona(v,p,r);
              quickSort(v,p,j);
              quickSort(v,j+1,r);
     }
}

int main()
{
    int v[100];
    int l;
    
    for(l=0;l<100;l++)
        v[l]=rand();
    
    quickSort(v,0,100);
    
    for(l=0;l<100;l++)
        printf("%d\n", v[l]);
    
    system("PAUSE");
    return 0;
}
