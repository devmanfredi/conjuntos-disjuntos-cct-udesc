#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "conjunto.h"

void inicializa_conjuntos(Conjuntos *p, int t){
	inicializa_lista(&p->multi, sizeof(Lista));
	p->tamInfo = t;
}

int conjuntoVazio(Conjuntos c){
	return c.multi.qtd;	
}
int cria_conjuntos(Conjuntos *c, void *representante, int(*compara)(void*, void*)){
	int i;
	Lista sub;
		for(i = 0 ; i < c->multi.qtd;i++){
		leNaPos(&c->multi,&sub,i);
		if(posicaoDoElemento(&sub, representante, compara)!=-1){
			printf("\nEste valor ja pertence a um conjunto, tente outro !!!\n\n");
			system ("pause");
			return	ERRO_CONJUNTO;		
		}
	}
	inicializa_lista(&sub, c->tamInfo);
	insereNoInicio(&sub, representante);
	insereNoFim(&c->multi, &sub);
	return 1;
}
int busca(Conjuntos *c, void *rep1, int(*compara)(void*, void*)){
	int i=0, j=-1, a=-1;
	
	Lista sub;
	
	do{ 
		leNaPos(&c->multi,&sub,i);
		a=(posicaoDoElemento(&sub, rep1, compara));
		i++;
		j++;
		if (a!=-1){
			break;
		}
	}while(i<c->multi.qtd);
	
	if (a==-1){
		return ERRO_VALOR_NAO_ENCONTRADO;
	}else {
		return j;
	}
}

int uniao(Conjuntos *c, void *rep1, void *rep2, int(*compara)(void*, void*)){

	int i=0,j=0, a=-1,b=-1, d , e=-1; 
	
	Lista sub;
	Elemento * q = c->multi.cabeca;
	Lista  *r1;
	Lista  *r2;
	
	do{ 
		leNaPos(&c->multi,&sub,i);
		a=(posicaoDoElemento(&sub, rep1, compara));
		i ++;
	}while(a==-1);
	
	for (d=0;d<i-1;d++){
		q=q->proximo;
	}
	 r1 = q->info;
	
	
	q = c->multi.cabeca;
	
	do{ 
		leNaPos(&c->multi,&sub,j);
		j ++;
		e++;
		b=(posicaoDoElemento(&sub, rep2, compara));
	}while(b==-1);
	
	for (d=0;d<j-1;d++){
		q=q->proximo;
	}
	 r2 = q->info;
	concatena(r1,r2);
	removeDaPos(&c->multi,&sub,e);
	
	return 1; //sucesso	
}



void mostra_conjuntos(Conjuntos c , void (*mostra)(void *)){
	
	if(lista_vazia(&c.multi)){
		printf("\nvazio\n");
		return ;
	}
	int i;
	Lista sub;
	for ( i = 0 ; i<c.multi.qtd;i++){
		leNaPos(&c.multi,&sub,i);
		printf("\nconjunto [%d] = { ",i);
		mostra_lista(sub, mostra);
		printf("}");
	}
}  

void desaloca_conjuntos(Conjuntos *c){
	int i;
	Lista sub;
	for(i = 0 ; i < c->multi.qtd;i++){
		leNaPos(&c->multi,&sub,i);
		limpa_lista(&sub);
	}
    limpa_lista(&c->multi);
}

void removeRep(Conjuntos *c, void *rep1, int(*compara)(void*, void*)){
	int i=0, j=-1, a=-1;
	void * inf;
	Lista sub1;
	Elemento *q = c->multi.cabeca;
	do{ 
		leNaPos(&c->multi,&sub1,i);
		a=(posicaoDoElemento(&sub1, rep1, compara));
		i++;
		j++;
	}while(a==-1);
	for (i=0;i<j;i++){
		q=q->proximo;
	}	
	
	removeDaPos(q->info,inf,a);

}

void concatena (Lista *l1, Lista *l2){	

	Elemento* p = l1->cabeca;
	int i;
	for( i=0; i< l1->qtd;i++){
		if (p->proximo==NULL){
			p->proximo = l2->cabeca;
			l2->cabeca = NULL;
			l1->qtd=l1->qtd+l2->qtd;
			l2->qtd =0;
		}else {
			p=p->proximo;
		}
 	}
	
	l1->qtd++;
}

