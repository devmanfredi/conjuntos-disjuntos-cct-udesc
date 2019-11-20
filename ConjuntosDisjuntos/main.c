#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compara(void *x, void *y);
void mostra(void *x);

int main(int argc, char *argv[]) {
	
	Conjuntos c;
	inicializa_conjuntos(&c,sizeof(float));
	float x = 9;
	int i;
	cria_conjuntos(&c,&x,compara);
	
	/*
	
	void var =  c.multi.cabeca[0].info;
	peesoal, assim estou conseguindo acessar a posiçao do elemento da multilista
	c->multi->cabeca[0] : 
	{
    	info = 0xb81730, 
    	proximo = 0x0
	}
	*/
	
	if(x != 2){
		printf("passei");
	}
	
	
	
	return 0;
}

void mostra(void *x) {
    printf("%f\n", *(float*) x);
}

int compara(void *x, void *y) {
    float *a = x, *b = y;
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}
