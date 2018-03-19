#define MAX 10

typedef int tp_item;

typedef struct{
	tp_item item[MAX];
	int topo;
}TP_PILHA;

void inicializaPilha(TP_PILHA * pointerPilha){
	//printf("Inicializado Pilha!\n");
	pointerPilha->topo = -1;
}
int isEmpty(TP_PILHA * pointerPilha){
	if(pointerPilha->topo == -1 ){
		return 1;
	}else{
		return 0;
	}
}
int isFull(TP_PILHA * pointerPilha){
	if(pointerPilha->topo == MAX - 1){
		return 1;
	}else{
		return 0;
	}
}
int alturaPilha(TP_PILHA pointerPilha){
	return pointerPilha.topo + 1;
}
int push(TP_PILHA * pointerPilha, int value){
	if(isFull(pointerPilha) == 1){
		//printf("Is full!\n");
		return 0;
	}else{
		//printf("Inserido o valor...: %d, no topo ...: %d \n", value, pointerPilha->topo + 2 );
		pointerPilha->topo++;
		pointerPilha->item[pointerPilha->topo] = value;
	}
}
/* Esse é a forma errado de imprimir um pilha, pois não se adequa a lógica de desempilhar um pilha
void listaPilha(TP_PILHA pointerPilha){
	if(pointerPilha.topo == -1){
		printf("Is empty!\n");
	}else{
		for( ;pointerPilha.topo > -1 ; ){
			printf("[ %d ] = %d\n",pointerPilha.topo + 1, pointerPilha.item[pointerPilha.topo]);
			pointerPilha.topo--;
		}	
	}	
}
*/
int pop(TP_PILHA * pointerPilha, tp_item * e){
	if(isEmpty(pointerPilha) == 1){
		//printf("Is empty\n!");
		return 0;
	}else{
		*e = pointerPilha->item[pointerPilha->topo];
		pointerPilha->topo--;
		//printf("Remove item...: %d\n", pointerPilha->topo);
		
		return 1;
	}
}
/*
int desempilhaTotal(TP_PILHA * pointerPilha){
	if(isEmpty(pointerPilha) == 1){
		return 0;
	}else{
		for( ;pointerPilha->topo > -1 ; ){
			pop(pointerPilha, &e);
			printf("%d \n",pointerPilha->topo);
			pointerPilha->topo--;
		}
		printf("ESC, 1-1\n");		
		return 1;
	}
}*/ 
/*
	@uthor uíres
	date 2018-03-15
	
	Essa função recebe uma pilha para retirar todos os elements imparés da pilha,
	usando o comportamento de pop e push;
*/

void retiraImpares(TP_PILHA * pointerPilha){
	TP_PILHA pilhaAuxiliar;
	inicializaPilha(&pilhaAuxiliar);
	tp_item e;
	
	while(!isEmpty(pointerPilha)){
		pop(pointerPilha, &e);
		if(e % 2 == 0){
			push(&pilhaAuxiliar, e);
		}else{
			continue;
		}
	}
	while(!isEmpty(&pilhaAuxiliar)){
		pop(&pilhaAuxiliar, &e);
		push(pointerPilha, e);
	}
	
}

/*
	@author u'ires
	date 2018-03-15
	
	Essa função tem a função de imprimir uma pilha utilizando o comportamento correto de desimpilhar
	, seguindo a seguinte assinatura int imprimir(TP_PILHA PILHA);
*/
int imprimirPilha(TP_PILHA pilha){
	if(isEmpty(&pilha) == 1){
		return 0;
	}else{
		tp_item e;
		while(!isEmpty(&pilha)){
			pop(&pilha, &e);
			printf("[ %d ]...-> %d\n", alturaPilha(pilha), e);
		}
		return 1;
	}
	
}
/* 
	@uthor uíres
	date 2018-03-15
	
	Essa função compara duas pilhas e retorna 1 caso sejam iguais e 0 se não forem iguais
*/

int comparaPilha(TP_PILHA pointerPilhaUm, TP_PILHA pointerPilhaDois){
	tp_item x, y;
	if(alturaPilha(pointerPilhaUm) != alturaPilha(pointerPilhaDois)){
		return 0;
	}else{
		while(!isEmpty(&pointerPilhaUm) && !isEmpty(&pointerPilhaDois)){
			pop(&pointerPilhaUm, &x);
			pop(&pointerPilhaDois, &y);
			if(x != y){
				return 0;
			}else{
				continue;
			}
		}
		return 1;		
	}
}

void concatenaPilha(TP_PILHA * pointerPilhaUm, TP_PILHA * pointerPilhaDois){
	if(isEmpty(pointerPilhaUm) || isEmpty(pointerPilhaDois)){
		printf("Pilhas vázias!\n");
	}else{
		TP_PILHA aux;
		inicializaPilha(&aux);
		int e;
		
		while(!isEmpty(pointerPilhaDois)){
			pop(pointerPilhaDois, &e);
			push(&aux, e);
		}
		while(!isEmpty(&aux)){
			pop(&aux, &e);
			push(pointerPilhaUm, e);
		}	
	}
}


