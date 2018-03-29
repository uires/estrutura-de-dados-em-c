#include <stdio.h>
#include "src/br/com/fila/fila.h"

int main(){
	TP_FILA primeiraFila;
	inicializaFila(&primeiraFila);
	enQueue(&primeiraFila, 10);
	enQueue(&primeiraFila, 5);
	enQueue(&primeiraFila, 6);
	enQueue(&primeiraFila, 1);
	imprimirFila(primeiraFila);
	
	return 0;
}
