#define MAX 10
#include <stdio.h>
// Definição de uma tipagem de dado prorpio, do tipo primitivo integer
typedef int tp_item;

typedef struct{
	// foi criado um vetor de tipografia tp_item (integer) definido com tamanho máximo na define;
	tp_item item [MAX];
	// criando um variável do tipo inteiro para classificar a posição  da pilha
	int topo;
}TP_PILHA_DOIS;
int retornaTopoPilha(TP_PILHA_DOIS * pilhaPointer){
	return pilhaPointer->topo;
}
void pilhaStart(TP_PILHA_DOIS  * pilhaPointer){
	pilhaPointer->topo = -1;
	
}
int pilhaCheia(TP_PILHA_DOIS * pilhaPointer){
	if(pilhaPointer->topo == MAX - 1){
		return 1;
	}else{
		return 0;	
	}
}

int pilhaVazia(TP_PILHA_DOIS * pilhaPointer){
	if(pilhaPointer->topo == -1){
		return 1;
	}else{
		return 0;
	}
}
int push(TP_PILHA_DOIS * pilhaPointer, tp_item value){
	if(pilhaCheia(pilhaPointer)){
		// return false 0 == false;
		return 0;		
	}else{

		pilhaPointer->topo++;
		pilhaPointer->item[pilhaPointer->topo] = value;
		return 1;		
		
	}
}

int pop(TP_PILHA_DOIS * pilhaPointer, tp_item * e){
	if(pilhaVazia(pilhaPointer) == 1){
		return 0;
	}else{
		*e = pilhaPointer->item[pilhaPointer->topo];
		pilhaPointer->topo--;
		return 1;
	}
}


