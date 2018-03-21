#include <stdio.h>
#include <string.h>
//#include "src/br/com/pilha/pilha.h"
#include <locale.h>
#include "src/br/com/pilha/pilhaMethodInsert.h"




int main(){
	setlocale(LC_ALL, "portuguese");
	/* primeiro exercício
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
	
	/* segundo exercício
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
	*/
	
	
	/*	Terceiro Exerc'icio
	TP_PILHA pilha;
	inicializaPilha(&pilha);
	
	push(&pilha, 1);
	push(&pilha, 2);
	push(&pilha, 3);
	push(&pilha, 4);
	push(&pilha, 5);
	push(&pilha, 6);
	
	imprimirPilha(pilha);
	
	
	retiraImpares(&pilha);
	
	printf("\n");
	imprimirPilha(pilha);
	*/
	
	/* Terceiro exercício
	TP_PILHA pilhaUm;
	inicializaPilha(&pilhaUm);
	
	TP_PILHA pilhaDois;
	inicializaPilha(&pilhaDois);
	
	push(&pilhaUm, 1);
	push(&pilhaUm, 2);
	push(&pilhaUm, 3);
	push(&pilhaUm, 4);
	
	push(&pilhaDois, 1);
	push(&pilhaDois, 2);
	push(&pilhaDois, 3);
	push(&pilhaDois, 3);
	
	imprimirPilha(pilhaUm);
	printf("------------------\n");
	imprimirPilha(pilhaDois);
	printf("------------------\n");
	//printf("%d", comparaPilha(pilhaUm, pilhaDois));
	
	
	concatenaPilha(&pilhaUm, &pilhaDois);
	imprimirPilha(pilhaUm);
	*/
	
	
	
	
	
	
	
	
	return 0;
}




