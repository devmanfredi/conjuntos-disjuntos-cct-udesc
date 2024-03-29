#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void inicializa_lista(Lista *l, int t) {
    l->cabeca = NULL;
    l->tamInfo = t;
    l->qtd = 0;
}

int lista_vazia(Lista *l) {
    return !l->qtd;
}

Elemento* aloca_ele(void *x, int t){
	Elemento *p = malloc(sizeof(Elemento));
	if (!p)
		return NULL; // falta mem�ria
	p->info = malloc(t);
	if (!p->info){
		free(p);
		return NULL; // falta mem�ria
	}
	memcpy(p->info, x, t);
	return p;
}

int insereNoInicio(Lista *l, void *info) {
    Elemento *p = aloca_ele(info, l->tamInfo);
    if (!p)
        return 0; // falta mem�ria
    p->proximo = l->cabeca;
    l->cabeca = p;
    l->qtd++;
    return 1; // sucesso
}

int removeDoInicio(Lista *l, void *info) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    Elemento *p = l->cabeca;
    memcpy(info, p->info, l->tamInfo);
    l->cabeca = p->proximo;
    l->qtd--;
    free(p->info);
    free(p);
    return 1; // sucesso
}

int insereNoFim(Lista *l, void *info) {
    Elemento *p = aloca_ele(info, l->tamInfo);
    if (!p)
        return 0; // falta mem�ria
    p->proximo = NULL;
    if (!l->cabeca) {
        return insereNoInicio(l, info);
    } else {
        Elemento *q = l->cabeca;
        while (q->proximo) {
            q = q->proximo;
        }
        q->proximo = p;
    }
    l->qtd++;
    return 1; // sucesso
}

int removeDoFim(Lista *l, void *info) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    if (l->qtd == 1)
        return removeDoInicio(l, info);
    Elemento *p = l->cabeca;
    while (p->proximo->proximo) { // pen�ltimo
        p = p->proximo;
    }
    memcpy(info, p->proximo->info, l->tamInfo);
    free(p->proximo->info);
    free(p->proximo);
    p->proximo = NULL;
    l->qtd--;
    return 1; // sucesso
}

int insereNaPos(Lista *l, void *info, int pos) {
    if (pos < 0 || pos > l->qtd)
        return ERRO_POS_INVALIDA;
    if (!pos)
        return insereNoInicio(l, info);
    Elemento *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos-1; cont++)
        p = p->proximo;
    Elemento *novo = aloca_ele(info, l->tamInfo);
    if (!novo)
        return 0; // falta mem�ria
    novo->proximo = p->proximo;
    p->proximo = novo;
    l->qtd++;
    return 1; // sucesso
}

int removeDaPos(Lista *l, void *info, int pos) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    if (!pos)
        return removeDoInicio(l, info);
    Elemento *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos-1; cont++)
        p = p->proximo;
    Elemento *x = p->proximo;
    p->proximo = x->proximo;
    memcpy(info, x->info, l->tamInfo);
    free(x->info);
    free(x);
    l->qtd--;
    return 1; // sucesso
}

int modificaNaPos(Lista *l, void *info, int pos) {
    if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    Elemento *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++)
        p = p->proximo;
    memcpy(p->info, info, l->tamInfo);
    return 1; // sucesso
}

int leNaPos(Lista *l, void *info, int pos) {
	
   if (lista_vazia(l))
        return ERROLISTA_VAZIA;
    if (pos < 0 || pos >= l->qtd)
        return ERRO_POS_INVALIDA;
    Elemento *p = l->cabeca;
    int cont;
    for (cont = 0; cont < pos; cont++)
        p = p->proximo;
    memcpy(info, p->info, l->tamInfo);
    return 1; // sucesso
}

int insereNaOrdem(Lista *l, void *info, int (*comp) (void *, void *)) {
    Elemento *p = l->cabeca;
    int cont = 0;
    while (p && comp(info, p->info) > 0) {
        p = p->proximo;
        cont++;
    }
    return insereNaPos(l, info, cont);
}

int posicaoDoElemento(Lista *l, void *info, int (*comp) (void *, void *)) {
	int cont = 0;
    Elemento *p = l->cabeca;
    while (p != NULL) {
    	if(comp(p->info, info) == 0) {
    		return cont;
		}
		cont++;
		p = p->proximo;
    	
    }
    return -1 ; 
}

void mostra_lista(Lista l, void (*mostra) (void *)) {
    if (lista_vazia(&l))
        printf("\nLista vazia!\n");
    else {
        
        Elemento *p = l.cabeca;
        int count =0;
        while (p!= NULL) {
            //printf("rep.(%d)\t ", count +1);
            mostra(p->info);
            p = p->proximo;
            count++;
        }
    }
}

void limpa_lista(Lista *l) {
    Elemento *p = l->cabeca, *q;
    while (p) {
        q = p;
        p = p->proximo;
        free(q->info);
        free(q);
    }
    l->cabeca = NULL;
    l->qtd = 0;
}

