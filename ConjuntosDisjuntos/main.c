#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#include <conio.h>

int compara(void *x, void *y);
void mostra(void *x);


int main() {
	
	Conjuntos c;
	inicializa_conjuntos(&c,sizeof(float));
	float x, y, z=0, w=4, t=5;
	int ind;
	void *aux;
	do{			
		system("cls");
	    system("color 0a");
    	printf("\n\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
		printf("\n\t\t\t\xBA        C O N J U N T O S       \xBA");
		printf("\n\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\tEscolha uma das opcoes abaixo:\n\n");
		printf("\n\t\t\t(1)Inserir um conjunto na Lista; \n");
		printf("\n\t\t\t(2)Ver lista; \n");
		printf("\n\t\t\t(3)Buscar indice de um conjunto na lista;\n");
		printf("\n\t\t\t(4)Unir conjunto; \n");
		printf("\n\t\t\t(5)Remover Conjunto; \n");
		printf("\n\t\t\t(6)Zera lista de conjuntos; \n");
		printf("\n\t\t\t(7)Sair; \n");
		printf("\n");
		printf("\n");
		printf("\n");
		
		scanf("%d",&ind);
		
		switch (ind){
		
			case 1:
				printf("Digite o valor do representante do conjunto:\n");
				scanf("%f",&x);
				cria_conjuntos(&c,&x,compara);
				break;
				
			case 2:
				mostra_conjuntos(c , mostra);
				printf("\n\n ");
				system("pause");
				break;
				
			case 3:
				printf("\ndigite o representante do conjunto:");
				scanf("%f",&x);
				printf("\nO valor buscado esta no conjunto de indice %d\n\n",busca(&c,&x,compara));
				system("pause");
				break;
			
			case 4:
				if (conjuntoVazio(c)<2){
					printf("A lista nao possui representates sulficientes para realizar esta operacao\n\n ");
					system("pause");
					break;
				}
				printf("escolha o primeiro representante: ");
				scanf("%f",&x);
				if (busca(&c,&x,compara)==-4){
					printf("valor nao encontrado recomece!!!");
					system("pause");
					break;
				}
				printf("escolha o segundo representante: ");
				scanf("%f",&y);
				if (busca(&c,&y,compara)==-4){
					printf("valor nao encontrado recomece!!!");
					system("pause");
					break;
				}
				
				if (busca(&c,&y,compara)==busca(&c,&x,compara)){
					printf("\n\n Os conjuntos ja foram unidos!!");
					system("pause");
					break;
				}
				uniao(&c,&x,&y,compara);
				break;
			
			case 5:	
				if (conjuntoVazio(c)<1){
					printf("A lista nao possui representates suficientes para realizar esta operacao\n\n ");
					system("pause");
					break;
				}
				printf("escolha um representante do conjuto a ser removido: ");
				scanf("%f",&x);
				if (busca(&c,&x,compara)==-4){
					printf("valor nao encontrado recomece!!!");
					system("pause");
					break;
				}
				ind=busca(&c,&x,compara);
				removeDaPos(&c.multi,&aux,ind);
				
				break;
				
			case 6:
				desaloca_conjuntos(&c);
				break;	
			case 7:
				printf("\nobrigado volte sempre\n");
				break;			
			
			default:
				printf("\nEscolha uma opcao valida!!\n\n ");
				system("pause"); 
		}
		
	}while (ind!=7);

}

void mostra(void *x) {
    printf("%.2f ;", *(float*) x);
} 

int compara(void *x, void *y) {
    float *a = x, *b = y;
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}
