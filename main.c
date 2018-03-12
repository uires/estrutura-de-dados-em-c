#include <stdio.h>
#include <string.h>
//#include "src/br/com/pilha/pilha.h"
#include <locale.h>
#include "src/br/com/pilha/pilhaMethodInsert.h"



int main(){
	setlocale(LC_ALL, "portuguese");
	/*
	tp_item e;
	TP_PILHA_DOIS pilha;
	pilhaStart(&pilha);
	int valorTopoPilha = retornaTopoPilha(&pilha);
	
	printf("[ %d ]", valorTopoPilha);
	printf("topo: %d\n", pilha.topo);
	push(&pilha, 10);
	printf("topo: %d\n", pilha.topo);
	push(&pilha, 20);
	printf("topo: %d\n", pilha.topo);
	push(&pilha, 30);
	// Imprime o valor da pilha 
	printf("O o valor do topo...: %d", pilha.item[pilha.topo]);
	
	pop(&pilha, &e);
	*/
	
	
	TP_PILHA pilha;
	inicializaPilha(&pilha);
	push(&pilha, 10);
	push(&pilha, 1);
	push(&pilha, 21);
	listaPilha(pilha);
	pop(&pilha);
	listaPilha(pilha);
	push(&pilha, 12323);
	listaPilha(pilha);
	push(&pilha, 221);
	push(&pilha, 72);
	push(&pilha, 12);
	push(&pilha, 52);
	push(&pilha, 982);
	push(&pilha, 2);
	push(&pilha, 3);
	listaPilha(pilha);
	desempilhaTotal(&pilha);
	listaPilha(pilha);
	printf("%d", pilha.topo);

	return 0;
}




