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
*	@param ( ponteiro de TP_LISTA )
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
		novoNoLista->proximoElementoDaLista = NULL;
		if(isEmptyLista(*listaMainPonteiro) == 1){
			*listaMainPonteiro = novoNoLista;
			return 1;
		}else{
			ponteiroAuxiliar = *listaMainPonteiro;
			while(ponteiroAuxiliar->proximoElementoDaLista != NULL){
				ponteiroAuxiliar = ponteiroAuxiliar->proximoElementoDaLista;
			}
			ponteiroAuxiliar->proximoElementoDaLista = novoNoLista;
		}
		return 1;
	}
}
/*
*	@desc: imprimi na tela os valores dos n�s da lista
*	@param ponteiro do tipo TP_LISTA
*	return 1 ou 0
*/

int imprimirListaEnceadea(TP_LISTA *ponteiroLista){
	if( isEmptyLista(ponteiroLista)  == 1){
		return 0;
	}else{
		TP_LISTA * ponteiroAuxiliarLista;
		ponteiroAuxiliarLista = ponteiroLista;
		while(ponteiroAuxiliarLista != NULL){
			printf("=>: %d\n", ponteiroAuxiliarLista->informacaoDaLista);
			ponteiroAuxiliarLista= ponteiroAuxiliarLista->proximoElementoDaLista;
		}
	}
	return 1;
}
/*
*	@desc: Remove um n� da lista
*	@param ponteiroListaOrigem, elemento a ser pesquisado
*	return 0(n�o removido) ou n�o zero == removido
*/

/*	De longe a mais complicada fun��o */
int removeListaElemento(TP_LISTA **listaMainPonteiro, int informacaoAserRemovida){
	if(isEmptyLista(*listaMainPonteiro) == 1){
		printf("Lista v�zia!\n");
		return 0;
	}else{
		TP_LISTA * ponteiroAuxiliar, *ponteiroAnteriorLista;
		ponteiroAnteriorLista = NULL;
		ponteiroAuxiliar = *listaMainPonteiro;
		while((ponteiroAuxiliar != NULL) && (ponteiroAuxiliar->informacaoDaLista != informacaoAserRemovida)){
			ponteiroAnteriorLista = ponteiroAuxiliar;
			ponteiroAuxiliar = ponteiroAuxiliar->proximoElementoDaLista;
		}
		/*	o valor informado n�o foi encontrado na lista */
		if(ponteiroAuxiliar == NULL){
			printf("Elemento n�o encontrado na lista!\n");
			return 0;
		}else{
			/*
			*	Nesse momento � possiblidade de dois poss�veis cen�rios,
			*	o primeiro s�ria que na busca o primeiro elemento
			*	fosse encontrado, com isso o n�o n�o entraria no while sendo assim
			*	ponteiroAnterior vai estar nulo, ent�o s� preciso tratar a atribui��o
			*	o listaMainPonteiro para o pr�ximo n� do ponteiroAuxliar->proximoElementoLista
				
			*	E o segundo caso � somente tratar o n� anterior  para que aponte
			*	para o ponteiroAuxiliar->proximoElemento e por fim limpar da mem�ria
			*	do ponteiroAuxiliar;
			*/
			if(ponteiroAnteriorLista == NULL){
				*listaMainPonteiro = ponteiroAuxiliar->proximoElementoDaLista;
			}else{
				ponteiroAnteriorLista->proximoElementoDaLista = ponteiroAuxiliar->proximoElementoDaLista;
			}
			/*
				Limpa o ponteiro e faz atribui nullo ao mesmo
			*/
			free(ponteiroAuxiliar);
			ponteiroAuxiliar = NULL;
		}
		printf("Elemento retirado com sucesso!\n");
		return 1;
	}
}
/*
*	@desc: Limpa uma lista, destruindo todos os n�s, disponiblizando assim a mem�ria para o SO
*	@param ( )
*	@return
*
*/
int destroyLista(TP_LISTA **ponteiroListaMain){
	if(isEmptyLista(*ponteiroListaMain) == 1){
		printf("Lista v�zia!\n");
		return 0;
	}else{
		TP_LISTA * pointeiroAuxiliar, *ponteiroPostumo;
		pointeiroAuxiliar = *ponteiroListaMain;
		while(pointeiroAuxiliar != NULL){
			ponteiroPostumo = pointeiroAuxiliar->proximoElementoDaLista;
			free(pointeiroAuxiliar);
			pointeiroAuxiliar = ponteiroPostumo;
		}
		*ponteiroListaMain = NULL;
		return 1;
	}
}

















