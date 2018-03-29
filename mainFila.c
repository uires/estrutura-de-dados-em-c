#include <stdio.h>
#include "src/br/com/fila/fila.h"

int main(){
	TP_FILA primeiraFila;
	int e;
	inicializaFila(&primeiraFila);
	//posicioesFilaIniFim(primeiraFila);
	enQueue(&primeiraFila, 10);
	enQueue(&primeiraFila, 100);
	enQueue(&primeiraFila, 30);
	enQueue(&primeiraFila, 1);
	enQueue(&primeiraFila, 5);
	imprimirFila(primeiraFila);
	
		

	return 0;
}
