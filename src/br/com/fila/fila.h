/*
*	@uthor U�res
*	date 2018-03-29
*	Estrutura de dados FILA (FIFO- First In First Out)
*/

#include <stdio.h>

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
Incializa as duas vari�veis de controle FIM(fim da fila) e INI
(inicio da fila) com MAX - 1;
*/
void inicializaFila(TP_FILA * pointerFila){
	pointerFila->ini = MAX - 1;
	pointerFila->fim = MAX - 1;
}
/*
Verifica se fim e ini s�o iguais, caso seja retorne 1
significa que a fila est� v�zia, 



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
	/*
	Uma l�gica para uma fila circular, caso a constante MAX - 1
	seja iguais a (9) ou seja final do espa�o f�sico do vetor, 
	ir� retornar (0), ou seja a primeira alo��o desse vetor,
	assim tornando a fila (array) circular;
	*/
	if(posicao == MAX - 1){
		return 0;
	}else{
		return posicao + 1;
	}
}

/*

Essa fun��o utiliza-se da fun��o proximo, caso fim + 1, 
seja igual a ini significa que a fila est� cheia, pois
com o m�todo de fila circular, h� a necessidade de sacrificar
um �ndice do vetor, pois se n�o a array ir� acessar uma
aloca��o (manti�a da mem�ria) acima do alocado para  a mesma,
dessa forma com o m�todo de sacrificar um �ndice n�o h� esse 
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
Insere um valor na fila, caso ela n�o retorn 1 em isFull()
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
* Retira um elemento da fila
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
		while(!isEmpty(&copiaFila)){
			deQueue(&copiaFila, &valorRemovido);
			printf("FIFO Value= %d \n", valorRemovido);
		}
		return 1;
	}
}


void retornaFimIni(TP_FILA * pointerFilaCircular){
	printf("FIM = %d\n INI = %d", pointerFilaCircular->fim, pointerFilaCircular->ini);
}
/*
Dada uma fila circular alocada sobre um vetor DADOS[6], fa�a um algoritmo que leia 15 n�meros inteiros e proceda, para cada um deles, como segue:
se o n�mero for par, insira-o na fila; se estiver cheia, retire um elemento da fila e insira o n�mero lido
se o n�mero lido for �mpar, retire um n�mero da fila; se estiver vazia, mostre uma mensagem
Ao final, esvazie a fila imprimindo os elementos.

*/

void filaControl(TP_FILA * pointerFilaCircular){
	int valorLido, contador = 0;
	TP_ITEM x;
	while(contador < 15){
		printf("Digite um valor inteiro: \n");
		scanf("%d", &valorLido);
		if(valorLido % 2 == 0){
			if(isFull(pointerFilaCircular) == 1){
				printf("Entrou no isFull() == 1\n");
				deQueue(pointerFilaCircular, &x);
				enQueue(pointerFilaCircular, valorLido);
				retornaFimIni(pointerFilaCircular);
				printf("\n");
			}else{
				printf("Entrou no else quando eh par!\n");
				enQueue(pointerFilaCircular, valorLido);
				retornaFimIni(pointerFilaCircular);
				printf("\n");
			}
		}else{
			if(isEmpty(pointerFilaCircular) == 1){
				printf("A fila est� v�zia!\n");
				
			}else{
				printf("Retirou um elemento impa!\n");
				deQueue(pointerFilaCircular, &x);
				retornaFimIni(pointerFilaCircular);
				printf("\n");
			}
		}
		contador++;
	}
	while(!isEmpty(pointerFilaCircular)){
		deQueue(pointerFilaCircular, &x);
		printf("Valor removido= %d\n", x);
	}
}
/*
Construa um programa que forne�a o maior, o menor e a m�dia aritm�tica dos elementos de uma fila circular,
considerando implementa��o de filas em vetor.
*/


int filaCircularMediaElementos(TP_FILA pointerFilaCircular){
	TP_ITEM valorRetiradaFila;
	int menorValor, maiorValor;
	int contadorTotal = 0;
	int valorMedia = 0;
	float resultadoFinalMedia;
	if(isEmpty(&pointerFilaCircular) == 1){
		return 0;
	}else{
		while(!isEmpty(&pointerFilaCircular)){
			deQueue(&pointerFilaCircular, &valorRetiradaFila);
			
			if(contadorTotal == 1){
				menorValor = valorRetiradaFila;
				maiorValor = valorRetiradaFila;
			}else{
				if(valorRetiradaFila < menorValor){
					menorValor = valorRetiradaFila;
				}
				if(valorRetiradaFila > maiorValor){
					maiorValor = valorRetiradaFila;
				}
			}
			valorMedia += valorRetiradaFila;
			contadorTotal++;
		}
		printf("O menor valor �: %d\n", menorValor);
		printf("O maior valor �: %d\n", maiorValor);
		resultadoFinalMedia = (float) valorMedia / contadorTotal;
		printf("A m�dia aritm�tica dos elementos �: %.2f\n", resultadoFinalMedia);
		
	}
	
}



















