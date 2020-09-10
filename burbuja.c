#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    clock_t tiempo_inicio, tiempo_final;
    double segundos;
    int *vec;
    int i;
    int j;
    int aux;
    int n;
    printf("Cuantos numeros quieres: "); scanf("%d",&n);
    vec = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    /*Generando arreglo de valores aleatorios*/
    for(i=0; i<n; i++) {
       vec[i] = 1 + rand() %((n-1)+3) ;
       printf("%d ",vec[i]);
    }
    tiempo_inicio = clock();
    /*Metodo de la Burbuja*/
    for(i=0; i<n; i++){
       for(j=0; j<n-1; j++){
          if(vec[j] > vec[j+1]){
             aux = vec[j];
             vec[j] = vec[j+1];
             vec[j+1] = aux;
          }
       }
    }
    printf("\n");
    /*Imprimir de forma ascendente*/
    printf("\nLos numeros ordenas por el metodo de burbuja son:\n\n");
    for(i=0; i<n; i++){
       printf("%d ",vec[i]);
    }
    printf("\n");
    tiempo_final = clock();
    segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC * 1000;
    printf("Tiempo de ejecucion: %f ms\n", segundos);
    free(vec);
    vec = NULL;
    return 0; 
}
