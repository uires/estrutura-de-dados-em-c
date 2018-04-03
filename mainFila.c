#include <stdio.h>
#include "src/br/com/fila/fila.h"
#include <locale.h>

int main(){
	setlocale(LC_ALL, "portuguese");
/*	TP_FILA primeiraFila;
	int e;
	inicializaFila(&primeiraFila);
	//posicioesFilaIniFim(primeiraFila);
	enQueue(&primeiraFila, 10);
	enQueue(&primeiraFila, 100);
	enQueue(&primeiraFila, 30);
	enQueue(&primeiraFila, 1);
	enQueue(&primeiraFila, 5);
	imprimirFila(primeiraFila);
	filaControl(&primeiraFila);
	
	if(imprimirFila(primeiraFila) == 0){
		printf("A fila está vázia!");
	}else{
		imprimirFila(primeiraFila);
	}
		
*/
	
	TP_FILA fila;
	inicializaFila(&fila);
	enQueue(&fila, 10);
	enQueue(&fila, 5);
	enQueue(&fila, 3);
	enQueue(&fila, 2);
	enQueue(&fila, 9);
	enQueue(&fila, 55);
	enQueue(&fila, 2);
	
	filaCircularMediaElementos(fila);
	


	return 0;
}
