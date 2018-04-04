/*
*	@uthor U�res
*	date 2018-03-29
*	Estrutura de dados FILA (FIFO- First In First Out)
*/



#define MAX 10
#define MAXCHAR 200

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
			
			if(contadorTotal == 0){
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

/*
Considere a opera��o de organiza��o de um trem onde os vag�es transportam tr�s tipos de cargas A, B e C.
O objetivo do programa de controle a ser projetado � montar um comboio com os vag�es organizados por tipo
de carga, agrupando aqueles do mesmo tipo, utilizando para isso um desvio da linha f�rrea como mostrado na 
figura seguir. Ap�s a atua��o do sistema, partindo da situa��o inicial (a), o trem ter� os vag�es organizados
como a situa��o final (c). Uma das situa��es intermedi�rias durante o processo � mostrada na figura (b). 
*/

typedef struct{
	char fila[MAXCHAR];
	int fim;
	int ini;
}TP_FILA_CHAR;

int deQuereChar(TP_FILA_CHAR * pointerFilaCircularChar, char * valorRemovido){
	if(isEmptyChar(pointerFilaCircularChar) == 1){
		return 0;
	}else{
		pointerFilaCircularChar->ini = proximoChar(pointerFilaCircularChar->ini);
		*valorRemovido = pointerFilaCircularChar->fila[pointerFilaCircularChar->ini];
		return 1;
	}
}

int enQuereChar(TP_FILA_CHAR * pointerFilaCircularChar, char value){
	if(isFullChar(pointerFilaCircularChar) == 1){
		return 0;
	}else{
		pointerFilaCircularChar->fim = proximoChar(pointerFilaCircularChar->fim);
		pointerFilaCircularChar->fila[pointerFilaCircularChar->fim] = value;
		return 1;
	}
}

int isEmptyChar(TP_FILA_CHAR * pointerFilaCircularChar){
	if(pointerFilaCircularChar->fim == pointerFilaCircularChar->ini){
		return 1;
	}else{
		return 0;
	}
}
int isFullChar(TP_FILA_CHAR * pointerFilaCircularChar){
	if(proximoChar(pointerFilaCircularChar->fim) == pointerFilaCircularChar->ini){
		return 1;
	}else{
		return 0;
	}
}

void incializaFilaChar(TP_FILA_CHAR * pointerFilaCircularChar){
	pointerFilaCircularChar->fim = MAXCHAR - 1;
	pointerFilaCircularChar->ini = MAXCHAR - 1;
	
}

int proximoChar(int posicao){
	if(posicao == MAXCHAR - 1){
		return 0;
	}else{
		return posicao + 1;
	}
}

/*
	@uthor 2018-04-04 13:08
	
*/

int vargaoTremOrdemCarga(TP_FILA_CHAR * pointerFilaCircularChar){
	TP_FILA_CHAR filaAuxiliarA;
	TP_FILA_CHAR filaAuxiliarB;
	TP_FILA_CHAR filaAuxiliarC;
	incializaFilaChar(&filaAuxiliarA);
	incializaFilaChar(&filaAuxiliarB);
	incializaFilaChar(&filaAuxiliarC);
	
	char valorRemovido;
	if(isEmptyChar(pointerFilaCircularChar) == 1){
		return 0;
	}else{
		while(!isEmptyChar(pointerFilaCircularChar)){
			deQuereChar(pointerFilaCircularChar, &valorRemovido);
			if(valorRemovido == 'A' || valorRemovido == 'a'){
				if(isFullChar(&filaAuxiliarA) == 1 ){
					continue;
				}else{
					enQuereChar(&filaAuxiliarA, valorRemovido);
				}
			}
			if(valorRemovido == 'B' || valorRemovido == 'b'){
				if(isFullChar(&filaAuxiliarB) == 1 ){
					continue;
				}else{
					enQuereChar(&filaAuxiliarB, valorRemovido);
				}
			}
			if(valorRemovido == 'C' || valorRemovido == 'c'){
				if(isFullChar(&filaAuxiliarC) == 1 ){
					continue;
				}else{
					enQuereChar(&filaAuxiliarC, valorRemovido);
				}
			}
		}
		while(!isEmptyChar(&filaAuxiliarA) && !isEmptyChar(&filaAuxiliarB) && !isEmptyChar(&filaAuxiliarC)){
			while(!isEmptyChar(&filaAuxiliarA)){
				deQuereChar(&filaAuxiliarA, &valorRemovido);
				enQuereChar(pointerFilaCircularChar, valorRemovido);
			}
			while(!isEmptyChar(&filaAuxiliarB)){
				deQuereChar(&filaAuxiliarB, &valorRemovido);
				enQuereChar(pointerFilaCircularChar, valorRemovido);
			}
			while(!isEmptyChar(&filaAuxiliarC)){
				deQuereChar(&filaAuxiliarC, &valorRemovido);
				enQuereChar(pointerFilaCircularChar, valorRemovido);
			}
		}
	}
	return 1;
}
int imprimiFilaChar(TP_FILA_CHAR copiaFilaChar){
	char valorRetiraChar;
	if(isEmptyChar(&copiaFilaChar) == 1){
		return 0;
	}else{
		while(!isEmptyChar(&copiaFilaChar)){
			deQuereChar(&copiaFilaChar, &valorRetiraChar);
			printf("char = %c\n", valorRetiraChar);
		}
		return 1;
	}
}
















