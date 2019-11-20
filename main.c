#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "conjunto.h"


void mostra_float(void *x);
int compara_float(void *x, void *y);

int main() {
   Conjuntos c;
   int numero = 0;
   
   int lin, col, i, j, x;
    printf("Digite o numero de linhas e o numero de colunas: ");
    scanf("%d %d", &lin, &col);
    Lista m, sub;
   
   inicializa_conjuntos(&c, sizeof(float));
  // float x = 2;
   //cria_conjuntos(&c, &x, compara_float);
   
   while(numero != -1){
   		printf("Digite o numero: \n");
   		scanf("%d", &numero);
   		cria_conjuntos(&c, &x, compara_float);
   }
   
    printf("Dados da matriz:\n");
    /
   //mostra_conjuntos(&c, mostra_float);
   //desaloca_conj(&c);
}

void mostra_float(void *x) {
    printf("%f\n", *(float*) x);
}

int compara_float(void *x, void *y) {
    float *a = x, *b = y;
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}

