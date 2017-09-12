#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int p, int q, int r, int v[])
{
     int i, j, k, *aux;
     i=p;
     j=q;
     k=0;
     aux = (int*) malloc((r-p)*sizeof(int));
     if(!aux){ exit(1); }
     while(i < q && j<r)
     {
             if(v[i] <= v[j])
             {
                     aux[k]= v[i];
                     i++;
             }
             else
             {
                 aux[k] = v[j];
                 j++;
             }
             k++;
     }
     
     while(i<q)
     {
               aux[k] = v[i];
               i++;
               k++;
     }
     while(j<r)
     {
               aux[k] = v[j];
               j++;
               k++;
     }
     
     for(i=p; i<r; i++)
     {
              v[i] = aux[i-p];
     }
     
     free(aux);
}

void mergeSort(int p, int r, int v[])
{
     int q;
     if(p < r-1)
     {
          q = (p+r)/2;
          mergeSort(p,q,v);
          mergeSort(q,r,v);
          intercala(p,q,r,v);
     }
}

int main()
{
    
    int v[500000], y;
    for(y=0;y<500000;y++)
    {
         v[y]=rand();
    }
    clock_t start_time;
    start_time = clock();
    mergeSort(0, 500000, v);
    double time_in_seconds = (clock() - start_time) / (double)CLOCKS_PER_SEC;
    
    printf("\n\nVetor ordenado em %f segundos\n", time_in_seconds);
    
    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
