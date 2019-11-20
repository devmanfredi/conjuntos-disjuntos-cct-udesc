#include "conjunto.h"

void inicializa_conjuntos(Conjuntos *p, int t){
	inicializa_lista(&p->multi, sizeof(Lista));
	p->tamInfo = t;
}

int cria_conjuntos(Conjuntos *p, void *representante, int(*compara)(void*, void*)){
	Lista sub;
	inicializa_lista(&sub, p->tamInfo);
	insereNoInicio(&sub, representante);
	insereNoFim(&p->multi, &sub);
}

//int uniao(Conjuntos *p, void *rep1, void *rep2, int(*compara)(void*, void*));   implementor
void mostra_conjuntos(Conjuntos *p, void (*mostra)(void *)){
	int i, j;
	
	Lista * l;
	
	for (i = 0; i < p->multi->qtd; i++) {
        leNaPos(&p->multi, &l, i);
        mostra_lista(l, void (*mostra) (void *))
        //for (j = 0; j < p->multi->cabeca->proximo->info ; j++) {
            //leNaPos(&sub, &x, j);
            //mostra(x);
        //}
        printf("\n");
    }	
}  

void desaloca_conj(&c){
	for (i = 0; i < lin; i++) {
        leNaPos(&m, &sub, i);
        limpa_lista(&sub);
    }
    limpa_lista(&m);
}

