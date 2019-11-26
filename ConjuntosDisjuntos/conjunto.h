#include "lista.h"
#define ERRO_CONJUNTO -3
#define ERRO_VALOR_NAO_ENCONTRADO -4


typedef struct {
	Lista multi;
	int tamInfo;
}Conjuntos;

void inicializa_conjuntos(Conjuntos *p, int t);
int conjuntoVazio(Conjuntos c);
int cria_conjuntos(Conjuntos *p, void *representante, int(*compara)(void*, void*));
void desaloca_conjuntos(Conjuntos *c);
int uniao(Conjuntos *c, void *rep1, void *rep2, int(*compara)(void*, void*)); 
void mostra_conjuntos(Conjuntos c, void (*mostra)(void *));
void concatena (Lista *l1, Lista *l2);
int busca(Conjuntos *c, void *rep1, int(*compara)(void*, void*));
void removeRep(Conjuntos *c, void *rep1, int(*compara)(void*, void*));
