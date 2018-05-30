/*
*	@author: u'ires deivide
*	@desc: struct para representa��o de um n� contendo
*			o ponteiro para o pr�ximo n� da lista;
*	@param ( )
*	@date: 05/30/2018
*/
typedef struct TP_NO{
	int informacaoDaLista;
	struct TP_NO * proximoElementoDaLista;
}TP_LISTA;
/*
*	@desc: retorna um ponteiro null do tipo TP_LISTA
*	@param ( )
*	@return null
*/
TP_LISTA * retornaPonteiroNulo(){
	return NULL;
}
/*
*	@desc: retorna um novo n� atrav�s de uma alo��o din�mica
*	@param ( )
*	@return ponteiro do tipo TP_LISTA
*/
TP_LISTA * alocacaoDeNovoNo(){
	TP_LISTA * novoNoLista;
	novoNoLista = ((TP_LISTA *) malloc(sizeof(TP_LISTA)));
	return novoNoLista;
}
/*
*	@desc: verifca se o ponteiro � nulo
*	@param ponteiro de TP_LISTA
*	@return 1 (verdadeiro) ou 0 (falso)
*/
int isEmptyLista(TP_LISTA * ponteiroLista){
	if(ponteiroLista == NULL){
		return 1;
	}else{
		return 0;
	}
}
/*
*	@desc: adiciona um novo n� na lista
*	@param ponteiroListaOrigem, int
*	return 1 (inserido) ou 0 (n�o inserido)
*/
int addListaElemento(TP_LISTA  **listaMainPonteiro, int valorASerInseridoNaLista){
	TP_LISTA * ponteiroAuxiliar, * novoNoLista;
	novoNoLista = alocacaoDeNovoNo();
	if(novoNoLista == NULL){
		printf("N�o foi poss�vel alocar mem�ria!\n");
		return 0;
	}else{
		novoNoLista->informacaoDaLista = valorASerInseridoNaLista;
		novoNoLista->proximoElementoDaLista = retornaPonteiroNulo();
		if(*listaMainPonteiro == NULL){
			*listaMainPonteiro = novoNoLista;
			return 1;
		}else{
			ponteiroAuxiliar = *listaMainPonteiro;
			while(ponteiroAuxiliar != NULL){
				ponteiroAuxiliar = ponteiroAuxiliar->proximoElementoDaLista;
			}
			ponteiroAuxiliar->proximoElementoDaLista = novoNoLista;
		}
		return 1;
	}
}





















