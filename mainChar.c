#include <stdio.h>
#include <string.h>
#include "src/br/com/pilha/notacaoPolonesaPilha.h"

/*
*	@uthor u�res
*	date 2018-03-18
*
*/

int main(int argc, char* argv[]){
	

	char string [10] = "81-2*1+";
	TP_PILHA_CHAR pilha;
	
	notacaoPolonesa(&pilha, string);
	
	
	return 0;
	
}                                                                                                                                                                                                                                                                                     
