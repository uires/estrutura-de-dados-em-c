#include <stdio.h>
#include <string.h>
#include "src/br/com/pilha/notacaoPolonesaPilha.h"


int main(){
	char string [10] = "81-2*1+";
	TP_PILHA_CHAR pilha;
	
	notacaoPolonesa(&pilha, string);
	
	
	return 0;
}


