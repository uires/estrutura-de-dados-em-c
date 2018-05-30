/*
*	@author: u'ires deivide
*	@desc: struct para representação de um nó contendo
*			o ponteiro para o próximo nó da lista;
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
*	@desc: retorna um novo nó através de uma aloção dinâmica
*	@param ( )
*	@return ponteiro do tipo TP_LISTA
*/
TP_LISTA * alocacaoDeNovoNo(){
	TP_LISTA * novoNoLista;
	novoNoLista = ((TP_LISTA *) malloc(sizeof(TP_LISTA)));
	return novoNoLista;
}
/*
*	@desc: verifca se o ponteiro é nulo
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
*	@desc: adiciona um novo nó na lista
*	@param ponteiroListaOrigem, int
*	return 1 (inserido) ou 0 (näo inserido)
*/
int addListaElemento(TP_LISTA  **listaMainPonteiro, int valorASerInseridoNaLista){
	TP_LISTA * ponteiroAuxiliar, * novoNoLista;
	novoNoLista = alocacaoDeNovoNo();
	if(novoNoLista == NULL){
		printf("Não foi possível alocar memória!\n");
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





















