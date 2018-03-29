/*
*	@uthor Uíres
*	date 2018-03-29
*	Estrutura de dados FILA (FIFO- First In First Out)
*/



#define MAX 10

typedef int TP_ITEM;
typedef struct{
	TP_ITEM fila[MAX];
	int ini;
	int fim;
}TP_FILA;

void posicioesFilaIniFim(TP_FILA fila){
	printf("Inicio = %d\nFim = %d\n", fila.ini, fila.fim);
}

/*
*	
*
*
*/
void inicializaFila(TP_FILA * pointerFila){
	pointerFila->ini = MAX - 1;
	pointerFila->fim = MAX - 1;
}
/*
*	
*
*
*/
int isEmpty(TP_FILA * pointerFila){
	if(pointerFila->ini == pointerFila->fim){
		return 1;
	}else{
		return 0;
	}
}
/*
*	
*
*
*/
int proximo(int posicao){
	if(posicao == MAX - 1){
		return 0;
	}else{
		return posicao + 1;
	}
}
/*
*	
*
*
*/
int isFull(TP_FILA * pointerFila){
	if(proximo(pointerFila->fim) == pointerFila->ini){
		return 1;
	}else{
		return 0;
	}
}
/*
*	
*
*
*/
int enQueue(TP_FILA * pointerFila, int value){
	if(isFull(pointerFila) == 1){
		return 0;
	}else{
		pointerFila->fim = proximo(pointerFila->fim);
		pointerFila->fila[pointerFila->fim] = value;
		return 1;
	}
}
/*
*	
*
*
*/
int deQueue(TP_FILA * pointerFila, TP_ITEM * removeValue){
	if(isEmpty(pointerFila) == 1){
		return 0;
	}else{
		pointerFila->ini = proximo(pointerFila->ini);
		*removeValue = pointerFila->fila[pointerFila->ini];
		return 1;
	}
}

int imprimirFila(TP_FILA copiaFila){
	TP_ITEM valorRemovido;
	if(isEmpty(&copiaFila) == 1){
		return 0;
	}else{
		printf("else\n");
		while(!isEmpty(&copiaFila)){
			deQueue(&copiaFila, &valorRemovido);
			printf("FIFO Value= %d \n", valorRemovido);
		}
		return 1;
	}
}
