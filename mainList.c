#include <stdio.h>
#include <stdlib.h>
#include "src/br/com/list/list.h"


int main(){
	TP_LIST * lista;
	lista = inicializaPonteiroLista();
	adicionarNovoNoLista(&lista, 10);
	adicionarNovoNoLista(&lista, 3);
	adicionarNovoNoLista(&lista, 1);
	adicionarNovoNoLista(&lista, 11105);
	adicionarNovoNoLista(&lista, 200);
	imprimirListaEncadeada(lista);
	
	
	
	
	
	return 0;
}





