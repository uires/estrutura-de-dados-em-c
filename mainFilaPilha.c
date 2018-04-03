#include "src/br/com/pilha/pilha.h"
#include "src/br/com/fila/fila.h"
#include <stdio.h>
#include <string.h>


int main(){
	TP_PILHA_DOIS pilhaUm;
	TP_FILA filaUm, filaDois;
	inicializaFila(&filaUm);
	inicializaFila(&filaDois);
	pilhaStart(&pilhaUm);
	int num, x, r;

	scanf("%d", &num);
	while(num != 99)	{
		push(&pilhaUm, num);
		scanf("%d", &num);
	}	
	
	while(!pilhaVazia(&pilhaUm)){
		pop(&pilhaUm, &x);
		r = x % 3;
		if(r != 0 ){
			x = x * 2;
			enQueue(&filaUm, x );
		}else{
			x = x * 3;
			enQueue(&filaDois, x);
		}
	}
	imprimirFila(filaUm);
	printf("-----------------------\n");
	
	imprimirFila(filaDois);
	
	
	
	return 0;
}

