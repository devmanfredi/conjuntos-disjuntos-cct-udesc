#include "lista.h"


typedef struct {
	Lista multi;
	int tamInfo;
}Conjuntos;

void inicializa_conjuntos(Conjuntos *p, int t);
int cria_conjuntos(Conjuntos *p, void *representante, int(*compara)(void*, void*));

//int uniao(Conjuntos *p, void *rep1, void *rep2, int(*compara)(void*, void*));  
//void mostra_conjuntos(Conjuntos *p, void (*mostra)(void *));

