#define MAX 10

typedef int tp_item;

typedef struct{
	tp_item item[MAX];
	int topo;
}TP_PILHA;

void inicializaPilha(TP_PILHA * pointerPilha){
	printf("Inicializado Pilha!\n");
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
		printf("Is full!\n");
		return 0;
	}else{
		printf("Inserido o valor...: %d, no topo ...: %d \n", value, pointerPilha->topo + 2 );
		pointerPilha->topo++;
		pointerPilha->item[pointerPilha->topo] = value;
	}
}
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
int pop(TP_PILHA * pointerPilha){
	if(isEmpty(pointerPilha) == 1){
		printf("Is empty\n!");
		return 0;
	}else{
		pointerPilha->topo--;
		printf("Remove item...: %d\n", pointerPilha->topo);
		return 1;
	}
}

int desempilhaTotal(TP_PILHA * pointerPilha){
	if(isEmpty(pointerPilha) == 1){
		return 0;
	}else{
		for( ;pointerPilha->topo > -1 ; ){
			pop(pointerPilha);
			printf("%d \n",pointerPilha->topo);
			pointerPilha->topo--;
		}
		printf("ESC, 1-1\n");		
		return 1;
	}
}



