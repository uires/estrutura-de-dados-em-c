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

Essa função utiliza-se da função proximo, caso fim + 1, 
seja igual a ini significa que a fila está cheia, pois
com o método de fila circular, há a necessidade de sacrificar
um índice do vetor, pois se não a array irá acessar uma
alocação (mantiça da memória) acima do alocado para  a mesma,
dessa forma com o método de sacrificar um índice não há esse 
problema. 

*/
int isFull(TP_FILA * pointerFila){
	if(proximo(pointerFila->fim) == pointerFila->ini){
		return 1;
	}else{
		return 0;
	}
}
/*
Insere um valor na fila, caso ela não retorn 1 em isFull()
*/
int deQueue(TP_FILA * pointerFila, int value){
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
* Retira um elemento da fila
*
*/
int enQueue(TP_FILA * pointerFila, TP_ITEM * removeValue){
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
		while(!isEmpty(&copiaFila)){
			deQueue(&copiaFila, &valorRemovido);
			printf("FIFO Value= %d \n", valorRemovido);
		}
		return 1;
	}
}








void filaControl(TP_FILA * pointerFilaCircular){
	int valorLido, contador = 0;
	TP_ITEM x;
	while(contador < 15){
		printf("Digite um valor inteiro: \n");
		scanf("%d", &valorLido);
		if(valorLido % 2 == 0){
			if(isFull(pointerFilaCircular) == 1){
				printf("Entrou no isFull() == 1\n");
				enQueue(pointerFilaCircular, &x);
				deQueue(pointerFilaCircular, valorLido);
				retornaFimIni(pointerFilaCircular);
				printf("\n");
			}else{
				printf("Entrou no else quando eh par!\n");
				deQueue(pointerFilaCircular, valorLido);
				retornaFimIni(pointerFilaCircular);
				printf("\n");
			}
		}else{
			if(isEmpty(pointerFilaCircular) == 1){
				printf("A fila está vázia!\n");
				
			}else{
				printf("Retirou um elemento impa!\n");
				enQueue(pointerFilaCircular, &x);
				retornaFimIni(pointerFilaCircular);
				printf("\n");
			}
		}
		contador++;
	}
	while(!isEmpty(pointerFilaCircular)){
		enQueue(pointerFilaCircular, &x);
		printf("Valor removido= %d\n", x);
	}
}
