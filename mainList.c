#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "src/br/com/list/list.h"

int main(){
	setlocale(LC_ALL, "portuguese");
	TP_LISTA * lista;
	lista = retornaPonteiroNulo();
	addListaElemento(&lista, 29);
	addListaElemento(&lista, 23);
	addListaElemento(&lista, 3);
	addListaElemento(&lista, 2);
	addListaElemento(&lista, 10);
	
	imprimirListaEnceadea(lista);
	
	removeListaElemento(&lista, 2);
	removeListaElemento(&lista, 10);
	removeListaElemento(&lista, 29);
	removeListaElemento(&lista, 3);
	removeListaElemento(&lista, 0);
	printf("------------------------------\n");
	imprimirListaEnceadea(lista);
	
	
	
	
	
	return 0;
}





